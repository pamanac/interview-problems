/**

BiNode: Consider a simple data structure called BiNode, which has pointers to two other nodes.
public class BiNode {
}
 public BiNode nodel, node2;
public int data;
The data structure BiNode could be used to represent both a binary tree (where nodel is the left
node and node2 is the right node) or a doubly linked list (where nodel is the previous node and
node2 is the next node). Implement a method to convert a binary search tree (implemented with
BiNode) into a doubly linked list. The values should be kept in order and the operation should be
performed in place (that is, on the original data structure).
*/
#include <iostream>
#include <ostream>

class Binode {
	Binode *node1, *node2;
	Binode* parent;
	int data;

public:
	Binode(int datum) : data(datum) { node1 = node2 = parent = nullptr;  }
	void setOne(Binode* node) {
		node1 = node;
	}

	Binode* getOne() {
		return this->node1;
	}

	void setTwo(Binode* node) {
		node2 = node;
	}
	Binode* getTwo() {
		return this->node2;
	}
	void set(Binode* one, Binode* two) {
		this->setOne(one);
		this->setTwo(two);
	}
	int getData() {
		return data;
	}

	int add(Binode* node, int height = 1) {
		if (node->getData() == this->data) //No duplicates
			return height;
		if (node1 == nullptr) {
			node1 = node;
			node->parent = this;
		}
		else if (node2 == nullptr) {
			node2 = node;
			node2->parent = this;
		}
		else {
			return node1->add(node, height+1);
		}
		return height;
	}

	void append(Binode* node) {
		this->node2 = node;
		node->node1 = this;
	}

	void print(std::ostream& out) {
		out << this->data;
	}

	void printTree(std::ostream& out) {
		this->print(out);
		out << " : ";
		if (node1) {
			node1->print(out);
			out << " , ";
		}
		if (node2)
			node2->print(out);
		out << std::endl;
		if (node1)
			node1->printTree(out);
		if (node2)
			node2->printTree(out);

	}

	Binode* getParent() {
		return this->parent;
	}

	
};


class Tree {
private:
	Binode* root;
	int height;

public:
	Tree() {
		this->root = nullptr;
		this->height = 0;
	}

	void add(Binode* node) {
		if (root == nullptr) {
			root = node;
			this->height = 1;
		}
		else {
			int height = root->add(node);
			if (height > this->height)
				this->height = height;
		}
	}

	void print(std::ostream& out) {
		if (root)
			root->printTree(out);
	}

	Binode* getRoot() {
		return this->root;
	}

	int getHeight() {
		return this->height;
	}


};

class DoubleLinkedList {
private:
	Binode* head, * tail;
	int length;

public:
	DoubleLinkedList() {
		this->head = this->tail = nullptr;
		this->length = 0;
	}

	void add(Binode* node) {
		if (head == nullptr) {
			head = node;
			tail = head;
		}
		else {
			tail->append(node);
			tail = node;
		}
	}

	void print(std::ostream& out) {
		Binode* runner = head;
		out << " [ ";
		while (runner != nullptr) {
			runner->print(out);
			if(runner->getTwo() != nullptr)
				out << " , ";
			runner = runner->getTwo();
		}
		out << " ] ";
		out << std::endl;
	}
};

void convertToList(Tree* tree) {
	Binode* runner = tree->getRoot();
	int currentHeight = 0;
	while (currentHeight != tree->getHeight()) {
		runner = runner->getOne();
		currentHeight++;
	}
	
	Binode* tracker = runner;
	int bubbleUp = 0;
	while (bubbleUp < currentHeight) {
		tracker = tracker->getParent();
		bubbleUp++;
	}
		
	int bubbleDown = 1;
	while (bubbleDown < currentHeight) {
		tracker = tracker->getTwo();
		bubbleDown++;
	}

	runner->setOne(tracker);
	if (runner == runner->getParent()->getOne())
		runner->setTwo(runner->getParent()->getTwo());
	else {
		//must define getLeftMost() and getRightMost() for Tree
		//here, unless you are the rightmost, you need to bubble up
		//and go down the other branch of the tree. runner->setTwo is 
		//the leftmost node of the other branch

}


int main(int argc, char* argv[]) {
	Tree t;
	DoubleLinkedList l;
	int vals[]{ 10, 5, 7, 1, 11, 13, 9 };
	for (int val : vals) {
		t.add(new Binode(val));
		l.add(new Binode(val));
	}

	t.print(std::cout);

	l.print(std::cout);

	convertToList(&t);
	t.print(std::cout);
}