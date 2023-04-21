#include <valarray>
#include "Triangle.h"


using namespace std;
namespace Geometry {

    double Triangle::area() {
        double p = (side1_ + side2_ + side3_) / 2.0;
        double _area = sqrt(p * (p - side1_) * (p - side2_) * (p - side3_));
        return _area;
    }

    pair<double,double> Triangle::coordinates() {
        return make_pair(x_, y_);
    }

    string Triangle::name() {
        return this->_name;
    }
    unique_ptr<Triangle>
    Triangle::create(double x, double y, double side1, double side2, double side3) {
        return make_unique<Triangle>(x, y, side1, side2, side3);
    }

    Triangle::Triangle(double x, double y, double side1, double side2, double side3) {
        x_ = x;
        y_ = y;
        side1_ = side1;
        side2_ = side2;
        side3_ = side3;
    }

    double Triangle::perimeter() {
        return side1_ + side2_ + side3_;
    }

    pair<double, double> Triangle::centroid() {
        double area_ = area() * 2/3;
        double q_1 = area_ / side1_;
        double q_2 = area_ / side2_;
        double q_3 = area_ / side3_;

        return pair<double, double>();
    }

}