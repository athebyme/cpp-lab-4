#include "App.h"
#include "Service/ExceptionService.h"
#include "Service/FigureContainer.h"
#include "Geometry/Ellipse.h"
#include "Geometry/Triangle.h"

using namespace std;
int App::start(int argc, char* argv[]) {
    try {
        auto triangle = Geometry::Triangle::create(0,0,5, 5 ,5, 10);
        auto triangle2 = Geometry::Triangle::create(1,4,6,4,1,11);
        auto ellipse = Geometry::Ellipse::create(argc, argv);
        this->figure_container->addFigure(std::move(ellipse));
        this->figure_container->addFigure(std::move(triangle));
        this->figure_container->addFigure(std::move(triangle2));

        for(const auto &figure: figure_container->getFigures()){
            this->displayService->displayInformation("%s with x: %.2f y: %.2f mass: %.2f mem_loc: %.2f\n",
                                                     figure->name().c_str(),
                                                     figure->coordinates(),
                                                     figure->mass(),
                                                     figure->size());
        }

        this->displayService->displayInformation("total memsize: %.2f\n",  figure_container->TotalMemSize());
        this->displayService->displayInformation("total container area: %.2f\n",this->figure_container->TotalArea());
        this->displayService->displayInformation("total container perimeter: %.2f\n",this->figure_container->TotalPerimeter());

    }catch (std::exception const &e) {
        this->displayService->displayError(e);
        return -1;
    }
    return 0;
}

App::App(
        Service::DisplayServiceInterface* displayService,
        Service::Container* figure_containter
) {
    this->displayService = displayService;
    this->figure_container = figure_containter;
}

App *App::create(Service::DisplayServiceInterface* displayService, Service::Container* figure_container) {
    return new App(displayService, figure_container);
}