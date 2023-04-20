#ifndef CPP_LAB4_FIGURECONTAINER_H
#define CPP_LAB4_FIGURECONTAINER_H
#include <vector>
#include <memory>
#include "../Geometry/Figure.h"

namespace Service{
    class Container{
    private:
        std::vector<std::unique_ptr<Figure>> figures_; // некоторые произвольные фигуры которые будем хранить
    public:
        Container();
        static Container* create();
        void addFigure(std::unique_ptr<Figure> figure);
        double TotalArea();
    };

    Container *Container::create() {
        return new Container();
    }

    double Container::TotalArea(){
        double area = 0;
        for (const auto &figure: figures_){
            area+=figure->area();
        }
        return area;
    }

    void Container::addFigure(std::unique_ptr<Figure> figure) {
        figures_.push_back(std::move(figure));
    }

    Container::Container() {
        this->figures_ = std::vector<std::unique_ptr<Figure>>();
    }
}

#endif
