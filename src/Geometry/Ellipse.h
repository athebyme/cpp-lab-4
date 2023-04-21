#ifndef CPP_LAB4_ELLIPSE_H
#define CPP_LAB4_ELLIPSE_H

#include <vector>
#include <string>
#include "../Service/FigureContainer.h"

namespace Geometry {
    class Ellipse : public Service::Figure{
    public:
        double area() override;
        pair<double,double> coordinates () override;
        double perimeter() override;
        std::string name() override;
        pair<double, double> centroid () override;
        double mass() override;
        double size() override;
        unique_ptr<Figure> getSelf() override;
        explicit Ellipse(double x, double y, double a, double b, double mass);
        static std::unique_ptr<Ellipse> create(int argc, char **argv);
    private:
        std::string _name = "Ellipse";
        double x, y;
        double a, b;
        double _mass;


    };

}

#endif
