#ifndef CPP_LAB4_TRIANGLE_H
#define CPP_LAB4_TRIANGLE_H

#include <string>
#include <memory>
#include "Figure.h"

using namespace std;
namespace Geometry{
    class Triangle : public Service::Figure{
    public :
        double area() override;
        pair<double,double> coordinates() override;
        string name() override;
        double perimeter() override;
        pair<double, double> centroid () override;
        double mass() override;
        double size() override;
        unique_ptr<Figure> getSelf() override;

        static unique_ptr<Triangle> create(double x, double y, double side1, double side2, double side3, double mass);
        explicit Triangle(double x, double y, double side1, double side2, double side3, double mass);
    private:
        double x_, y_;
        double side1_, side2_, side3_;
        double _mass;
        string _name = "Triangle";
    };

}

#endif
