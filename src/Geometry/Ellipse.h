#ifndef CPP_LAB4_ELLIPSE_H
#define CPP_LAB4_ELLIPSE_H

#include <vector>
#include "../Service/FigureContainer.h"

namespace Geometry {
    class Ellipse : public Service::Figure{
    public:
        double area() override;
        double coordinates () override;
        explicit Ellipse(double x, double y, double a, double b);
        static std::unique_ptr<Ellipse> create(int argc, char **argv);
    private:
        double x, y, a, b;
    };

}

#endif
