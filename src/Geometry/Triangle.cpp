#include <valarray>
#include "Triangle.h"


using namespace std;
namespace Geometry {

    double Triangle::area() {
        double p = (this->side1_ + this->side2_ + this->side3_) / 2;
        return sqrt(p * (p - this->side1_) * (p - this->side2_) * (p - this->side3_));
    }

    pair<double,double> Triangle::coordinates() {
        return make_pair(x_, y_);
    }

    string Triangle::name() {
        return this->_name;
    }
    unique_ptr<Triangle>
    Triangle::create(double x, double y, double side1, double side2, double side3, double mass) {
        return make_unique<Triangle>(x, y, side1, side2, side3, mass);
    }


    Triangle::Triangle(double x, double y, double side1, double side2, double side3, double mass) {
        this->x_ = x;
        this->y_ = y;
        this->side1_ = side1;
        this->side2_ = side2;
        this->side3_ = side3;
        this->_mass = mass;
    }

    double Triangle::perimeter() {
        return this->side1_ + this->side2_ + this->side3_;
    }

    pair<double, double> Triangle::centroid() {
        return pair<double, double>(this->x_, this->y_);
    }

    double Triangle::mass() {
        return this->_mass;
    }

    double Triangle::size() {
        return sizeof(Triangle);
    }

    unique_ptr<Service::Figure> Triangle::getSelf() {
        return make_unique<Triangle>(*this);
    }

}