#pragma once
#include <vector>
using namespace std;
class Shape;

void purge(vector<Shape*> v) {
	for (vector<Shape*>::iterator it = v.begin(); it != v.end(); it++) {
		delete (*it);
	}
	v.clear();
}
