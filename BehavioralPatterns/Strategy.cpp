#include <iostream>

using namespace std;

class Strategy {

	public:
		virtual int doAction(int n1, int n2) = 0;
};

class ActionAdd : public Strategy {
	
	public:
		int doAction(int n1, int n2) {
			return n1 + n2;
		}
};

class ActionSub : public Strategy {
	
	public:
		int doAction(int n1, int n2) {
			return n1 - n2;	
		}
};

class ActionMulti : public Strategy {
	
	public:
		int doAction(int n1, int n2) {
			return n1 * n2;
		}
};

class Context {
	private:
		Strategy *strategy;

	public:
		Context(Strategy *str) {
			strategy = str;
		}
		
		int execStrategy(int n1, int n2) {
			return strategy->doAction(n1, n2);
		}
};

int main() {
	
	Context *ctx = new Context(new ActionAdd());
	cout << ctx->execStrategy(2, 5) << endl;

	ctx = new Context(new ActionSub());
	cout << ctx->execStrategy(2, 5) << endl;

	ctx = new Context(new ActionMulti());
	cout << ctx->execStrategy(2, 5) << endl;
}
