//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 6/7/22
//  File type: C++ source file
//  Description: Given a node in a connected graph, return a deep copy of that graph.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


typedef std::vector<std::vector<int>> AdjList;


class Node {
public:
   int val;
   vector<Node*> neighbors;

   Node() {
      val = 0;
      neighbors = vector<Node*>();
   }

   Node(int _val) {
      val = _val;
      neighbors = vector<Node*>();
   }

   Node(int _val, vector<Node*> _neighbors) {
      val = _val;
      neighbors = _neighbors;
   }
};



// we do a dfs exploration of the original connected graph.
// For each node we explore, for each of its neighbors, allocate it if it hasnt been explored yet.
// Make the connection between both nodes, and then call dfs again on that neighbor.


Node* dfs_clone(Node *node, std::unordered_map<int, Node*> &new_graph){
   if (!node) return nullptr;
   if (new_graph.count(node->val)) return new_graph[node->val];
   Node *copy = new Node(node->val);
   new_graph[node->val] = copy;
   for (Node *nbr : node->neighbors){
      copy->neighbors.push_back(dfs_clone(nbr, new_graph));
   }
   return copy;
}



Node* cloneGraph(Node* node){
   std::unordered_map<int, Node*> new_graph;
   return dfs_clone(node, new_graph);
}




void assert_matching_deep_copy(Node* og, Node* copy){
   std::unordered_set<Node*> visited = {nullptr};
   std::vector<Node*> og_nodes, copy_nodes;

   std::function<void(Node*, std::vector<Node*>&)> dfs;
   dfs = [&](Node* node, std::vector<Node*> &nodes) -> void {
      if (visited.count(node)) return;
      nodes.push_back(node);
      visited.insert(node);
      for (Node *nbr : node->neighbors){
         dfs(nbr, nodes);
      }
   };

   dfs(og, og_nodes);
   dfs(copy, copy_nodes);

   assert(og_nodes.size() == copy_nodes.size());

   for (int i = 0; i < og_nodes.size(); ++i){
      assert(og_nodes[i] != copy_nodes[i]);
      assert(og_nodes[i]->val == copy_nodes[i]->val);
   }
}




Node* createGraph(AdjList graph){
   // figure out the size of our graph (values of nodes are the nodes index)
   // so the max value is the size of our graph.
   int size = 1;
   for (auto &pair : graph){
      size = std::max(size, pair[0]);
      size = std::max(size, pair[1]);
   }

   // instantiate all nodes
   std::vector<Node*> all_nodes(size);
   for (int i = 0; i < size; ++i){
      all_nodes[i] = new Node(i+1);
   }


   // connect them
   for (auto &pair : graph){
      all_nodes[pair[0]-1]->neighbors.push_back(all_nodes[pair[1]-1]);
      all_nodes[pair[1]-1]->neighbors.push_back(all_nodes[pair[0]-1]);
   }

   return all_nodes[0];
}



int main(){
   AdjList graph = {{1,3},{1,4},{2,3},{2,4}};
   Node *og = createGraph(graph);

   Node *copy = cloneGraph(og);

   assert_matching_deep_copy(og, copy);

   dlog("Ran successfully.");
   return 0;
}



