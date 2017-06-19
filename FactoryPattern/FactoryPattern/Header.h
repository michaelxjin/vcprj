#pragma once
#include <string>
#include <map>
#include <vector>
#include <exception>
#include <iostream>
using namespace std;

// demo Polymorphic Factories
class Shape {
public:
	virtual void draw() = 0;
	virtual void erase() = 0;
	virtual ~Shape() {}
};

class ShapeFactory {
	virtual Shape * create() = 0;

	static map<string, ShapeFactory*> factories;

public:
	virtual ~ShapeFactory() {}
	friend class ShapeFactoryInit;
	class BadShapeCreation : public exception {
		string reason;
	public:
		BadShapeCreation(string type) {
			reason = "Can not create type " + type;
		}
		const char* what() const { return reason.c_str(); }
	};

	static Shape* ceateShape(string id)	throw (BadShapeCreation)
	{
		if (factories.find(id) != factories.end()) {
			return factories[id]->create();
		}
		else
			throw BadShapeCreation(id);
	}
};
map<string, ShapeFactory*> ShapeFactory::factories;

class Circle : public Shape {
	Circle() { cout << __FUNCTION__ " ctr called\n";  } // private ctr
public:
	void draw() { cout << __FUNCTION__ " draw a Circle\n";  }
	void erase() { cout << __FUNCTION__ " erase a Circle\n"; }
	class Factory : public ShapeFactory {
	public:
			Shape * create() { return new Circle; } // can it access priv outside member??
	};
};
class Square : public Shape {
	Square() { cout << __FUNCTION__ " ctr called\n"; } // private ctr
public:
	void draw() { cout << __FUNCTION__ "  draw a Square\n"; }
	void erase() { cout << __FUNCTION__ " erase a Square\n"; }
	class Factory : public ShapeFactory {
	public:
			Shape * create() { return new Square; } // can it access priv outside member??
	};
};

// singleton to init factory
class ShapeFactoryInit {
	static ShapeFactoryInit si;
//public:
	ShapeFactoryInit() {
		ShapeFactory::factories["Circle"] = new Circle::Factory;
		ShapeFactory::factories["Square"] = new Square::Factory;
	}
};
ShapeFactoryInit ShapeFactoryInit::si;





