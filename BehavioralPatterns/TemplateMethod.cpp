#include <iostream>

using namespace std;

class Game {
	
	public:
		virtual void initialize() {}
		virtual void startPlay() {}
		virtual void endPlay() {}
	
		void play() {

			initialize();

			startPlay();

			endPlay();
		}
};

class Cricket : public Game {

	public:
		void initialize() {
			cout << "Cricket init " << endl;
		}
		
		void startPlay() {
			cout << "Cricket start" << endl;
		}

		void endPlay() {
			cout << "Cricket end" << endl;
		}

};

class Football : public Game {

	public:

		void initialize() {
			cout << "Football init " << endl;
		}
		
		void startPlay() {
			cout << "Football start" << endl;
		}

		void endPlay() {
			cout << "Football end" << endl;
		}

};

int main() {


	Game *game = new Cricket();
	game->play();

	game = new Football();
	game->play();

}
