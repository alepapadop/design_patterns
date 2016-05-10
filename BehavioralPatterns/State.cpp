#include <iostream>


using namespace std;

class State;

class Context {
	private:
		State *state;
	public:
		Context() {
			state = NULL;
		}
		void setState(State *st) {
			state = st;
		}
		State *getState() {
			return state;
		}
};

class State {

	public:
		virtual void doAction(Context *context) = 0;
		
};

class StartState : public State {

	public:
		void doAction(Context *context) {
			cout << "Start State" << endl;
			context->setState(this);
		}

		void toString() {
			cout << "Start State" << endl;
		}
		
};

class StopState : public State {

	public:
		void doAction(Context *context) {
			cout << "Stop State" << endl;
			context->setState(this);
		}

		void toString() {
			cout << "Stop State" << endl;
		}
};

int main() {

	Context *context = new Context();
	
	StartState *startState = new StartState();
	startState->doAction(context);

	startState->toString();

	StopState *stopState = new StopState();
	stopState->doAction(context);

	stopState->toString();

}
