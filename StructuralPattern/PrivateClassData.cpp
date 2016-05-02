class CircleData {
	private: 
		double radius;
	public:
	CircleData(double rad) {
		radius = rad;
	}
	double getRadius() {
		return radius;
	}
};

class Circle {
	private: 
		CircleData *circleData;
	
	public:
		Circle(double rad) {
			circleData = new CircleData(rad);
		}
		double Circumference() {
			return 2 * 3.14 * circleData->getRadius();
		}
};
	

int main() {

	Circle circ(3);
	
	circ.Circumference();

}
