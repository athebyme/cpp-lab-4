#include "FigureContainer.h"
#include "ConsoleDisplayService.h"
namespace Service{
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

    std::vector<std::unique_ptr<Figure>>& Container::getFigures() {
        return figures_;
    }

    double Container::TotalPerimeter() {
        double p = 0;
        for (const auto &figure: figures_){
            p+=figure->perimeter();
        }
        return p;
    }

}
