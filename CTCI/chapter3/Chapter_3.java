//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 3/5/22
//  File type: Java source file
//  Description: My answers to chapter 2 of Cracking the Coding Interview.
//////////////////////////////////////////////////////

import myjava.*;
import static myjava.Log.*;

import java.util.*;
import java.lang.*;


class Chapter_3 {

	/*
		Problem 1: Three in One
		Q: How would you use a single array to implement 3 stacks?

		A: I would split the array into 3rds by calculating the 3 indices that would do so.
		So for example, with a array of length 9, index 0 would be the start of the first stack,
		index 3 would be the start of the second stack, and index 6 would be the start of the
		3rd stack. I would also keep track of the end indices for each stack, which would represent
		the last used slot in the respective stacks partition of the array, so that I could know where
		to insert new elements for that stack as well as what elements to return when we call top() or
		pop() on that stack.
	*/


	/*
		Problem 2: Stack Min
		Q: How would you implement a stack that has push and pop functionality but also has a method 'min'
		that returns the minimum element in the stack in constant time for all operations?

		A: I would keep a variable 'min' that tracks the smallest element in the stack.
		This variable will initialize to INT_MAX or whatever the upper bound on our domain is.
		Every time we push an element, we will compare it to 'min' and update min accordingly.
		We will push the 'min' to the stack as well as the pushed element every time we push,
		so that at every stage we can call min() and the min of the stack will simply be the second
		to last element in the stack. This sacrifices space complexity, but this is only way we can
		improve our time complexity to constant. This could also be done with a second stack that
		pushes the min every time we push, but for simplicity we can just push both the min and the new
		value to the same stack. We also have to make sure that when we pop, we remove the last 2 elements 
		(the actual value as well as the min recorded at that stage), and we also need to update min when we
		pop too incase the value we just popped was unique and was equal to the current min at that stage.
	*/


	/*
		Problem 3: Stack of Plates
		Q: Implement a data structure called SetOfStacks that implements a stack using multiple sub-stacks, since we don't want a single stack that gets really tall.

		FOLOW-UP: Implement a method for our SetOfStacks class called popAt that takes an index and pops that specific substack.
	*/

	private static interface Poppable<T> {
		public T peek() throws Exception;
		public void push(T newValue);
		public void pop();
		public boolean isEmpty();
	}



	private static class SetOfStacks<T> implements Poppable<T> {

		// Attributes
		private LinkedList<Stack<T>> stacks; // for constant time removal of lower stacks
		private int size, capacity;


		// Methods

		public SetOfStacks(int _capacity){
			stacks = new LinkedList<Stack<T>>();
			size = 0;
			capacity = _capacity;
		}

		public T peek() throws Exception {
			if (!isEmpty()){
				return stacks.getLast().peek();
			} else {
				log("Error: Stack is empty. Can't peek.");
				throw new Exception("Ooops!");
			}
		}

		public void push(T newValue){
			if (size == 0 || stacks.getLast().size() == capacity){
				stacks.add(new Stack<T>());
			}
			stacks.getLast().push(newValue);
			size++;
		}

		public void pop(){
			if (!isEmpty()){
				Stack<T> s = stacks.getLast();
				s.pop();
				if (s.size() == 0) stacks.removeLast();
				size--;
			}
		}

		public void popAt(int index){
			// pops the sub-stack thats at the given index.
			if (index >= 0 && index < stacks.size()){
				Stack<T> s = stacks.get(index);
				s.pop();
				if (s.size() == 0) stacks.remove(index);
				size--;
			}
		}

		public int size(){
			return size;
		}

		public boolean isEmpty(){
			return size == 0;
		}

		public int stackCount(){
			return stacks.size();
		}
	}




	private static class MyQueue<T> implements Poppable<T> {
		// Attributes
		Stack<T> A, B;
		int size;


		// Methods

		public MyQueue(){
			A = new Stack<T>();
			B = new Stack<T>();
			size = 0;
		}

		public T peek() throws Exception {
			if (!isEmpty()){
				while (A.size() > 0){
					B.push(A.pop());
				}
				T front = B.peek();
				while (B.size() > 0){
					A.push(B.pop());
				}
				return front;

			} else {
				log("Error: Stack is empty. No peeking!");
				throw new Exception("Uh oh!");
			}
		}

		public void push(T newValue){
			A.push(newValue);
			size++;
		}

		public void pop(){
			if (!isEmpty()){
				while (A.size() > 0){
					B.push(A.pop());
				}
				B.pop();
				while (B.size() > 0){
					A.push(B.pop());
				}
				size--;
			}
		}


		public int size(){
			return size;
		}

		public boolean isEmpty(){
			return size == 0;
		}

	}



	public static <T extends Comparable<T>> Stack<T> sortStack(Stack<T> stk){
		Stack<T> ans = new Stack<>();
		Stack<T> temp = new Stack<>();

		while (!stk.empty()){
			while (!temp.empty() && temp.peek().compareTo(stk.peek()) > 0){
				ans.push(temp.pop());
			}
			while (!ans.empty() && ans.peek().compareTo(stk.peek()) < 0){
				temp.push(ans.pop());
			}
			ans.push(stk.pop());
		}

		return ans;
	}


	// Smarter but less intuitive sorting function that only allocates 1 extra stack.
	public static <T extends Comparable<T>> void sortStack2(Stack<T> stk){
		Stack<T> ans = new Stack<>();
		while (!stk.empty()){
			T temp = stk.pop();
			while (!ans.empty() && ans.peek().compareTo(temp) > 0){
				stk.push(ans.pop());
			}
			ans.push(temp);
		}

		while (!ans.empty()){
			stk.push(ans.pop());
		}
	}



	// Problem 6 Implementation

	enum Species {
		DOG,
		CAT
	}

	private static class Animal {
		// Attributes
		public Species species;
		public String name;

		// Methods

		public Animal(Species _species, String _name){
			species = _species;
			name = _name;
		}

		public String toString() {
			return name + " (" + ((species == Species.DOG) ? "Dog" : "Cat") + ")";
		}	

	}


	private static class AnimalShelter {
		// Attributes
		LinkedList<Animal> animalQueue;


		// Methods 

		public AnimalShelter(){
			animalQueue = new LinkedList<Animal>();
		}


		public void enqueue(Animal entry){
			animalQueue.add(entry);
		}

		public Animal dequeueAny() throws Exception {
			if (isEmpty()) throw new Exception("No animals!");
			return animalQueue.poll();
		}


		private Animal dequeueType(Species desiredSpecies) throws Exception {
			Stack<Animal> temp = new Stack<>();
			while (!isEmpty() && animalQueue.peek().species != desiredSpecies){
				temp.push(animalQueue.poll());
			}

			boolean hasAnimal = !isEmpty(); // represents if we have that animal type or not
			Animal selection = null;
			if (hasAnimal){
				selection = animalQueue.poll();
			}
			// add other animals back in to the queue
			while (!temp.empty()){
				animalQueue.addFirst(temp.pop());
			}
			if (hasAnimal) return selection;
			else throw new Exception("No animal of desired type here!");

		}

		public Animal dequeueDog() throws Exception {
			return dequeueType(Species.DOG);
		}

		public Animal dequeueCat() throws Exception {
			return dequeueType(Species.CAT);
		}

		public boolean isEmpty(){
			return animalQueue.size() == 0;
		}

	}


	/*
		NOTE: The above class can be improved upon by storing 2 seperate queues, one for dogs and another for cats.
		This would improve the time complexity since we wouldnt have to iteratate through a bunch of cats to get to a dog when dequeueing, for example. This would make dequeueAny slightly more complicated, but still constant time, since we would just check which animal type has the older animal and pop and return that one.
	*/





	private static void printPoppable(Poppable structure) throws Exception {
		while (!structure.isEmpty()){
			log(structure.peek());
			structure.pop();
		}
	}



	public static void main(String[] args) throws Exception {
		// Problem 3
		log("\n\n--- Problem 3 ---\n");
		SetOfStacks<Integer> mySet = new SetOfStacks<Integer>(4);

		int sz = 25;
		for (int i = 1; i < sz; ++i){
			mySet.push(i);
		}

		mySet.popAt(0);
		mySet.popAt(0);
		mySet.popAt(0);

		log("Size is : " + mySet.stackCount());

		printPoppable(mySet);


		// Problem 4
		log("\n\n--- Problem 4 ---\n");
		MyQueue<Integer> myQ = new MyQueue<Integer>();
		myQ.push(1);
		myQ.push(2);
		myQ.push(3);
		myQ.push(4);
		myQ.pop();

		printPoppable(myQ);

		// Problem 5
		log("\n\n--- Problem 5 ---\n");

		Stack<Integer> myStack = new Stack<>();
		myStack.push(1);
		myStack.push(3);
		myStack.push(2);
		myStack.push(7);
		myStack.push(7);
		myStack.push(-3);
		myStack.push(0);
		myStack.push(10);
		myStack.push(14);
		myStack.push(4);
		sortStack2(myStack); // get sorted version

		// print to see result
		while (!myStack.empty()){
			log(myStack.peek());
			myStack.pop();
		}


		// Problem 6
		log("\n\n--- Problem 6 ---\n");
		AnimalShelter shelter = new AnimalShelter();
		shelter.enqueue(new Animal(Species.CAT, "Samantha"));
		shelter.enqueue(new Animal(Species.CAT, "Rue"));
		shelter.enqueue(new Animal(Species.CAT, "Alexa"));
		shelter.enqueue(new Animal(Species.DOG, "Benji"));
		shelter.enqueue(new Animal(Species.CAT, "Lilac"));
		shelter.enqueue(new Animal(Species.CAT, "Freddy"));
		shelter.enqueue(new Animal(Species.DOG, "Eli"));
		shelter.enqueue(new Animal(Species.DOG, "Daisy"));
		shelter.enqueue(new Animal(Species.CAT, "Tookie"));

		log(shelter.dequeueDog());
		log(shelter.dequeueAny());
		log(shelter.dequeueAny());
		log(shelter.dequeueAny());
		log(shelter.dequeueAny());
		log(shelter.dequeueAny());
		log(shelter.dequeueAny());
		log(shelter.dequeueAny());
		log(shelter.dequeueAny());

	}

}


