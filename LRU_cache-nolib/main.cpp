//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 1/6/2021
//  File type: C++ source file
//  Description: Manual implementation of an LRU Cache using a doubly linked list and a
//  hash map (rather than simply using an ordered map).
//  	Complexity of get and put: constant
//////////////////////////////////////////////////////


#include <iostream>
#include "../debug.h"
#include <unordered_map>

//using namespace std;


struct DListNode {
	int key, val;
	DListNode *pre = nullptr, *post = nullptr;

	DListNode(int _key, int _val) : key(_key), val(_val) {}
};



class DLinkList {
	unsigned int length = 0;
	DListNode *head, *tail;

public:
	DLinkList(){
		// add dummy nodes for cleaner implementation
		head = new DListNode(0,0);
		tail = new DListNode(0,0);
		head->post = tail;
		tail->pre = head;
	}

	void add(DListNode* node){
		// insert at head
		node->post = head->post;
		node->pre = head;
		head->post->pre = node;
		head->post = node;
		length++;
	}


	void bringToFront(DListNode* node){
		//disconnect node
		node->pre->post = node->post;
		node->post->pre = node->pre;
		length--;
		//add it back to front
		this->add(node);
	}

	int evict(){
		tail->pre->pre->post = tail;
		DListNode* new_last = tail->pre->pre;
		int key = tail->pre->key;
		delete tail->pre;
		tail->pre = new_last;
		length--;
		return key;
	}

	unsigned int getLength() const {
		return length;
	}

	void print() const {
		if (length == 0){
			std::cout << "EMPTY" << std::endl;
		}
		DListNode* curr = head->post;
		while (curr != tail){
			std::cout << curr->key << "," << curr->val << " - ";
			curr = curr->post;
		}
		std::cout << "\n";
	}
};




class LRUCache {
	std::unordered_map<int, DListNode*> umap;
	unsigned int cap;
	DLinkList list;


public:
	LRUCache(unsigned int _capacity) : cap(_capacity){
	}

	void put(int key, int val){
		auto mapping = umap.find(key);

		if (mapping != umap.end()){
			mapping->second->val = val; // update value
			list.bringToFront(mapping->second);

		} else {
			if (list.getLength() >= cap){ // evict LRU
				umap.erase(umap.find(list.evict()));
			}
			DListNode* node = new DListNode(key, val);
			list.add(node);
			umap[key] = node;
		}
		
	}

	int get(int key){
		auto mapping = umap.find(key);
		if (mapping != umap.end()){
			list.bringToFront(mapping->second);
			return mapping->second->val;
		}
		return -1;
		
	}

	void print() const {
		std::cout << "{";
		for (auto& x : umap){
			std::cout << x.first << ":" << x.second->val << ", ";
		}
		std::cout << "}" << std::endl;
		list.print();
		std::cout << "\n";
	}
};




int main(){
	LRUCache c(2);
	c.put(1,1);
	c.print();

	c.put(2,2);
	c.print();

	log(c.get(1));

	c.put(3,3);
	c.print();

	log(c.get(2));

	c.put(4,4);
	c.print();

	log(c.get(1));
	log(c.get(3));
	log(c.get(4));

	return 0;
}



