#include <algorithm>
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

    pair<double, double> Container::centroid() {
        double x = 0, y = 0, total_mass = 0;
        for(const auto& figure: figures_){
            double mass = figure->mass();
            pair<double,double> cur_coord = figure->coordinates();
            x += mass * cur_coord.first;
            y += mass* cur_coord.second;
            total_mass+=mass;
        }

        return make_pair(x/total_mass,y/total_mass);
    }

    double Container::TotalMemSize() {
        double total_size = 0;
        for(const auto& figure: figures_){
            total_size+=figure->size();
        }
        return total_size;
    }



    vector<unique_ptr<Figure>> Container::getSortedFiguresByMass() const {
        vector<unique_ptr<Figure>> temp_figures;
        temp_figures.reserve(figures_.size());
        for (auto& figure : figures_) {
            temp_figures.push_back(std::make_unique<Figure>(*figure));
        }
        std::sort(temp_figures.begin(), temp_figures.end(), Figure::compareFiguresByMass);
        return temp_figures;
    }


}
