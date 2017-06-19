#if 0
#include "Header.h"
#else
#include "Header2.h"
#endif

#include "purge.h"

char *shapeList[] = { "Circle", "Square", "Square", "Circle", ""};

int main() {
	vector<Shape*> shapes;
	try {
		for (char **cp = shapeList; **cp; cp++) {
			shapes.push_back(ShapeFactory::ceateShape(*cp));
		}
		} catch (ShapeFactory::BadShapeCreation e) {
			cout << e.what() << endl;
			return 1;
		}
		for (size_t i = 0; i < shapes.size(); i++) {
			shapes[i]->draw();
			shapes[i]->erase();
		}
		purge(shapes);
		return 0;
}

