#include<iostream>

using namespace std;


class Shape {
public:
	virtual float CalCircumferance() = 0;
	virtual float CalArea() = 0;
};

class Circle : public Shape {
public:
	Circle(float r) :radius(r) {}
	float CalCircumferance()
	{
		return 2 * 3.1415926 * radius;
	}
	float CalArea()
	{
		return 3.1415926 * radius * radius;
	}
private:
	float radius;
};

class Square : public Shape {
public:
	Square(float w) :width(w) {}
	float CalCircumferance()
	{
		return 4 * width;
	}
	float CalArea()
	{
		return width * width;
	}
private:
	float width;
};

class Rect : public Shape {
public:
	Rect(float w, float h) :width(w), height(h) {}
	float CalCircumferance()
	{
		return 2 * (width + height);
	}
	float CalArea()
	{
		return width * height;
	}
private:
	float width;
	float height;
};

void VirtualFuncTest()
{
	Shape * circle = new Circle(10);
	Shape * square = new Square(10);
	Shape * rect = new Rect(10, 20);
	cout << "circle : " << circle->CalCircumferance() << ", " << circle->CalArea() << endl;
	cout << "square : " << square->CalCircumferance() << ", " << square->CalArea() << endl;
	cout << "rect : " << rect->CalCircumferance() << ", " << rect->CalArea() << endl;
}

void base_class_test()
{
	VirtualFuncTest();
	cout << endl;
}