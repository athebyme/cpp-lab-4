#include <cmath>
#include "Ellipse.h"
#include "../Service/ExceptionService.h"
using namespace std;
namespace Geometry {
    unique_ptr<Ellipse>
            Ellipse::create(int argc, char *argv[]) {
        if(argc < 6){
            throw CustomExceptions::NotEnoughArgumentsException();
        }
        return make_unique<Ellipse>(atof(argv[1]),
                                         atof(argv[2]),
                                         atof(argv[3]),
                                         atof(argv[4]),
                                         atof(argv[5]));
    }

    double Ellipse::area() {
        return this->b * this->a * M_PI;
    }

    pair<double,double> Ellipse::coordinates() {
        return make_pair(this->x, this->y);
    }

    string Ellipse::name() {
        return this->_name;
    }

    double Ellipse::perimeter() {
        return 4 * (M_PI * a * b + pow((a-b),2))/(a+b);
    }

    pair<double, double> Ellipse::centroid() {
        return make_pair(x, y);
    }

    double Ellipse::mass() {
        return _mass;
    }

    Ellipse::Ellipse(double x, double y, double a, double b, double mass) {
        this->a = a;
        this->b = b;
        this->x = x;
        this->y = y;
        this->_mass = mass;
    }

    double Ellipse::size() {
        return sizeof(Ellipse);
    }
    unique_ptr<Service::Figure> Ellipse::getSelf() {
        return make_unique<Ellipse>(*this);
    }
}