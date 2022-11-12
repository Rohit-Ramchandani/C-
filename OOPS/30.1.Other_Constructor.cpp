#include<iostream>
using namespace std;

class Point
{
    int x,y;

    public:
    Point(int a, int b)
    {
        x = a;
        y = b;
    }

    void display()
    {
        cout << "The point is represented by ("<< x << "," << y <<")";
    }
};

int main()
{
    Point p(21,41);
    p.display();
}