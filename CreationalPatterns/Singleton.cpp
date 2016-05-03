#include <iostream>


class Single {
	
	private:
		static Single *single;
	public:
		static Single *getInstance() {
			if (!single) {
				single = new Single();
			}
			return single;
		}

};

Single *Single::single = NULL;

int main() {

	Single a;

	std::cout << a.getInstance() << std::endl;
	std::cout << a.getInstance() << std::endl;

}


