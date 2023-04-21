#ifndef CPP_LAB4_FIGURE_H
#define CPP_LAB4_FIGURE_H

#include <string>

using namespace std;
namespace Service{
    class Figure{
    public:
        virtual double area() = 0;
        virtual double perimeter() = 0;
        virtual pair<double, double> centroid () = 0;
        virtual pair<double,double> coordinates() = 0;
        virtual string name() = 0;
    };
}

#endif