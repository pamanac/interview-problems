#include <iostream>
#include <vector>
using namespace std;

template <typename T>
struct Node {
	T data;
	Node* next;
	Node(T data = NULL, Node* next = nullptr) {
		this->data = data;
		this->next = next;
	}
	void setNext(Node<T>* next) {
		this->next = next;
	}
	T getVal() {
		return this->data;
	}
};

template <typename T>
class LinkedList {

	Node<T>* root;
	Node<T>* tail;

public:
	LinkedList(){
		this->root = new Node<T>();
		this->tail = root;
	}

	void add(T datum) {
		Node<T>* node = new Node<T>(datum);
		this->tail->setNext(node);
		this->tail = this->tail->next;
	}

	void appendNode(Node<T>* node) {
		this->tail->next = node;
		this->tail = this->tail->next;
	}

	Node<T>* getNode(T datum) {
		Node<T>* runner = this->root;
		while (runner != nullptr) {
			if (runner->getVal() == datum)
				return runner;
			runner = runner->next;
		}
	}

	T findIntersect(LinkedList& other) {
		Node<T>* runner = this->root;
		Node<T>* checker = other.root;
		T intersect = NULL;
		while (runner != nullptr && checker != nullptr) {
			if (runner == checker) {
				intersect = runner->getVal();
				return intersect;
			}
			if (runner == this->tail) {
				runner = this->root;
				checker = checker->next;
			}
			else {
				runner = runner->next;
			}

		}
		return NULL;
	}
	
	T circular() {
		Node<T>* ptr = this->root;
		vector<Node<T>*> seen;
		while (ptr != nullptr) {
			for (auto itr = seen.begin(); itr < seen.end(); itr++)
				if (ptr == *itr)
					return ptr->getVal();
			seen.push_back(ptr);
			ptr = ptr->next;
		}
	}

	/*
	~LinkedList() {
		Node<T>* ptr = this->root;
		while (ptr != nullptr) {
			Node<T>* deleteMe = ptr;
			ptr = ptr->next;
			delete deleteMe;
		}
	}
	*/
};


int main(int argc, char* argv[]) {
	LinkedList<double> A;
	LinkedList<double> B;
	double elements[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
	for (double elem : elements) {
		A.add(elem);
		B.add(elem);
	}
	B.appendNode(A.getNode(3.0));
	A.appendNode(A.getNode(4.0));

	cout << "Intersect (expected 3.0) : " << A.findIntersect(B) << endl;
	cout << "Circular (exprected 4.0) : " << A.circular() << endl;
}