#include <iostream>


class Rectangle
{
	public:
		virtual void draw() = 0;
};

class LegacyRectangle
{
	public:
		LegacyRectangle(int x1, int y1, int x2, int y2) {
			_x1 = x1;
			_y1 = y1;
			_x2 = x2;
			_y2 = y2;
			std::cout << "LegacyRectangle: create. (" << _x1 << "," << _y1 << ") => (" << _x2 << "," << _y1 << ")" << std::endl; 
		}

		void oldDraw() {
			std::cout << "LegacyRectangle: oldDraw. (" << _x1 << "," << _y1 << ") => (" << _x2 << "," << _y1 << ")" << std::endl; 
		}
	private:
		int _x1;
		int _y1;
		int _x2;
		int _y2;
};

class RectangleAdapter : public Rectangle, private LegacyRectangle
{
	public:
		RectangleAdapter(int x, int y, int w, int h) : LegacyRectangle(x, y, x + w, y + h) {
			std::cout << "RextangleAdapter: create. (" << x << "," << y << "), width = " << w << ", height = " << h <<std::endl;

		}
		virtual void draw() 
		{
			std::cout << "RectangleAdapter: draw." << std::endl;
			oldDraw();
		}

};


int main()
{
	Rectangle *r = new RectangleAdapter(12, 20 ,60 ,40);
	r->draw();
}


