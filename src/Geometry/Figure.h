#ifndef CPP_LAB4_FIGURE_H
#define CPP_LAB4_FIGURE_H

#include <string>

using namespace std;
namespace Service{
    class Figure{
    public:
        virtual ~Figure() = default;
        virtual double area() = 0;
        virtual double perimeter() = 0;
        virtual pair<double, double> centroid () = 0;
        virtual pair<double,double> coordinates() = 0;
        virtual double mass() = 0;
        virtual string name() = 0;
        virtual double size() = 0;
        virtual unique_ptr<Figure> getSelf() = 0;
        static bool compareFiguresByMass(const unique_ptr<Figure>& f1, const unique_ptr<Figure>& f2);
    private:
        double x{},y{};

    };

    bool Figure::compareFiguresByMass(const unique_ptr <Figure> &f1, const unique_ptr <Figure> &f2) {
        return f1->mass() < f2->mass();
    }
}

#endif