#include <iostream>
#include <cmath>
using namespace std;
//class Point
class Point {
	private:
		int x, y;

	public:
		Point(int xx, int yy);
		Point(Point &p);
		~Point();
		int getX() {
			return x;
		}
		int getY() {
			return y;
		}
};

Point::Point(int xx, int yy) {
	x = xx;
	y = yy;
}

Point::Point(Point &p) {
	x = p.x;
	y = p.y;
	cout << "calling copy constructor of Point...\n";
}

Point::~Point(){
}

class Line {
	private:
		/* data */
		Point p1;
		Point p2;
		double len;

	public:
		Line(Point xp1, Point xp2);
		Line(Line &l);
		~Line();
		double getLen() {
			return len;
		};

};

Line::Line(Point xp1, Point xp2) : p1(xp1), p2(xp2) {
	cout << "calling construction of Line...\n";
	int xLen = p1.getX() - p2.getX();
	int yLen = p1.getY() - p2.getY();
	len = sqrt(xLen * xLen + yLen * yLen);
}

//copy constructor
Line::Line(Line &l) : p1(l.p1), p2(l.p2) {
	len = l.len;
	cout << "calling copy constructor of Line...\n"<<endl;
}

Line::~Line() {
}

int main() {
	Point oPoint1(1, 2);
	Point oPoint2(3, 5);
	Line oLine(oPoint1, oPoint2);
	Line oLine2(oLine);
	cout << "the length of the line is:\n";
	cout << oLine.getLen();

	cout << "the lenght of the line2 is:\n" ;
	cout << oLine2.getLen()<<endl;
	return 0;
}
