/*
7. Build Order: You are given a list of projects and a list of dependencies (which is a list of pairs of
projects, where the second project is dependent on the first project). Ail of a project's dependencies
must be built before the project is. Find a build order that will allow the projects to be built. If there
is no valid build order, return an error.
Input:
p r o j e c t s : a, b, c, d, e, f
dependencies: (a, d), ( f , b ) , (b, d ) , ( f , a ) , (d, c)
Output: F, e, a, b, d, c
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Project {
private:
	char id;
	vector<char> dependencies;
	int dependenciesCounter;

public:
	Project(char id) {
		this->id = id;
		this->dependenciesCounter = 0;
	}

	void addDependency(char depID) {
		this->dependencies.push_back(depID);
		this->dependenciesCounter++;
	}

	char getID() {
		return this->id;
	}

	bool isReady() {
		return this->dependenciesCounter == 0;
	}

	void removeDependency(char depID) {
		for (auto iterator = dependencies.begin(); iterator < dependencies.end(); iterator++)
			if ((*iterator) == depID)
				dependenciesCounter--;
	}

	void print() {
		cout << " ID: " << this->getID() << " | -> | ";
		for (auto iterator = dependencies.begin(); iterator < dependencies.end(); iterator++)
			cout << *iterator << " , ";
		cout << endl;
	}

	static vector<char> buildOrder(vector<Project*> projects) {
		vector<char> returnVector;
		int counter = 0;
		int breakout = projects.size() * 100;
		while (returnVector.size() != projects.size() && counter < breakout) {
			for (Project* p : projects)
				if (p->isReady()) {
					bool found = false;
					for (auto it = returnVector.begin(); it < returnVector.end(); it++)
						if (*it == p->getID())
							found = true;
					if(!found)
						returnVector.push_back(p->getID());
				}

			for (char ID : returnVector) {
				for (Project* p : projects) {
					p->removeDependency(ID);
				}
			}

			counter++;
		}
		return returnVector;
	}

};


int main(int argc, char* argv) {
	string symbs = "abcdef";

	struct dependency {
		char neededBefore;
		char dependant;
	};
	dependency deps[] = { {'a', 'd'}, { 'f','b' }, { 'b','d' }, { 'f','a' }, { 'd','c' } };

	vector<Project*> buildProjects;
	
	for (char letter : symbs) {
		Project* myProject = new Project(letter);
		for (dependency dep : deps) {
			if (dep.dependant == letter)
				myProject->addDependency(dep.neededBefore);
		}
		buildProjects.push_back(myProject);
	}
	for (Project* p: buildProjects) {
		p->print();
	}
	vector<char> solution = Project::buildOrder(buildProjects);
	for (char i : solution) {
		cout << i << " ";
	}
	cout << endl;


	


}