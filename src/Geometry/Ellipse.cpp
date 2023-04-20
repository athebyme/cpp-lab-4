#include <cmath>
#include "Ellipse.h"
#include "../Service/ExceptionService.h"
using namespace std;
namespace Geometry {
    unique_ptr<Ellipse> Ellipse::create(int argc, char *argv[]) {
        if(argc < 4){
            throw CustomExceptions::NotEnoughArgumentsException();
        }
        return make_unique<Ellipse>(atof(argv[1]),
                                         atof(argv[2]),
                                         atof(argv[3]),
                                         atof(argv[4]));
    }

    Ellipse::Ellipse(double x, double y, double a, double b) {
        this->x = x;
        this->y = y;
        this->a = a;
        this->b = b;
    }

    double Ellipse::area() {
        return this->b * this->a * M_PI;
    }

    double Ellipse::coordinates() {
        return (this->x, this->y);
    }
}