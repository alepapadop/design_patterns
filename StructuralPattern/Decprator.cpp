#include <iostream>

using namespace std;

class Widget
{
	public:
		virtual void draw() = 0;
};

class TextField : public Widget
{
	int width, height;
	
	public:
		TextField(int w, int h) {
			width = w;
			height = h;
		}

		void draw() {
			cout << "TextField: " << width << ", " << height << endl;
		}
};

class Decorator : public Widget
{

	Widget *w;

	public:
		Decorator(Widget *w)
		{
			this->w = w;
		}

		void draw()
		{
			w->draw();
		}
};

class BorderDecorator : public Decorator
{
	public:

	BorderDecorator(Widget *w) : Decorator(w) {}

	void draw()
	{
		Decorator::draw();
		cout << " BorderDecorator" << endl;
	}
};

class ScrollDecorator : public Decorator
{
	public:
		ScrollDecorator(Widget *w): Decorator(w){}

	void draw()
	{
		Decorator::draw();
		cout << " ScrollDecorator" << endl;
	}
};

int main()
{
	Widget *awidget = new BorderDecorator(new BorderDecorator(new ScrollDecorator(new TextField(80, 24))));
	awidget->draw();
}


