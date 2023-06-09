#ifndef CPP_LAB4_FIGURECONTAINER_H
#define CPP_LAB4_FIGURECONTAINER_H
#include <vector>
#include <memory>
#include "../Geometry/Figure.h"

using namespace std;
namespace Service{
    class Container{
    private:
        std::vector<std::unique_ptr<Figure>> figures_; // некоторые произвольные фигуры которые будем хранить
    public:
        Container();
        static Container* create();
        void addFigure(std::unique_ptr<Figure> figure);
        vector<std::unique_ptr<Figure>> & getFigures();
        double TotalArea();
        double TotalPerimeter();
        double TotalMemSize();
        pair<double, double> centroid();
        vector<unique_ptr<Figure>> getSortedFiguresByMass() const;
    };
}

#endif
