#include <iostream>

using namespace std;

class Monitor;
class Keyboard;

class PartVisitor {
	
	public:
		virtual void visit(Keyboard *keyboard) = 0;
		virtual void visit(Monitor *monitor) = 0;
};

class Part {
	
	public:
		virtual void accept(PartVisitor *pv) = 0;

};

class Keyboard : public Part {
	
	public:
		void accept(PartVisitor *pv) {
			pv->visit(this);
		}

};


class Monitor : public Part {
	
	public:
		void accept(PartVisitor *pv) {
			pv->visit(this);
		}

};


class PartVisitImpl : public PartVisitor {

	public:
		void visit(Keyboard *keybord) {
			cout << "Keyboard" << endl;
		}

		void visit(Monitor *monitor) {
			cout << "Monitor" << endl;
		}
};

int main() {
	
	Part *parts[] = {new Keyboard(), new Monitor()};

	PartVisitImpl visitor;

	parts[0]->accept(&visitor);
	parts[1]->accept(&visitor);	
	
}
