#include "SortContainer.h"

class Student
{
public:
	int rate = 0;
	int indexNumber = 0;
	
	friend std::ostream &operator<<(std::ostream &os, const Student & student) {
		if(pass(student))
			os << "Pass the test: ";
		else
			os << "Not pass the test: ";
		os << student.indexNumber << "\n";
		return os;
	}
	
	friend std::istream &operator>>(std::istream &is, Student &student) {
		
		is >> student.indexNumber;
		is >> student.rate;
		return is;
	}
	
	static bool pass(const Student & student)
	{
		return student.rate>2;
	}
};

class Point
{
public:
	int x, y;
	
	friend std::ostream &operator<<(std::ostream &os, const Point & point) {
		if(isPivot(point))
			os << "Point lying in the 2 or 4 quadrant: ";
		else if(condition(point))
			os << "Point lying in the 1 or 3 quadrant: ";
		else
			os << "Point lying on the axis: ";
		os << "(" << point.x << ", " << point.y << ")\n";
		return os;
	}
	
	friend std::istream &operator>>(std::istream &is, Point &point) {
		
		is >> point.x;
		is >> point.y;
		return is;
	}
	
	static bool isPivot(const Point & point)
	{
		return point.x<0 && point.y > 0 || point.x > 0 && point.y<0;
	}
	
	static bool condition(const Point & point)
	{
		return point.x > 0 && point.y > 0 || point.x < 0 && point.y < 0;
	}
};

void runFirst() {
	SortContainer<Student> data;
	size_t size{0};
	int searchNumber{0};
	
	std::cout << "Type students amount: ";
	
	std::cin >> size;
	
	data.reserve(size);
	std::cout << "Type index and rate from test:\n";
	
	std::cin >> data;
	
	data.partition(0, data.getSize()-1, Student::pass);
	
	std::cout<<" "<<data << "\n";
}

void runSecond() {
	SortContainer<Point> data;
	size_t size{0};
	
	std::cout << "Type points amount: ";
	
	std::cin >> size;
	
	data.reserve(size);
	std::cout << "Type points coordinate:\n";
	
	std::cin >> data;
	
	std::cout << "Algorithm time complexity O(n):\n";
	
	data.threeWayPartition(Point::condition, Point::isPivot);
	
	std::cout<<" "<<data;
}


int main() {
	std::cout << "First task:\n\n";
	runFirst();
	
	std::cout << "Second task:\n\n";
	runSecond();
	return 0;
}