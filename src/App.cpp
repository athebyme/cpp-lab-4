#include "App.h"
#include "Service/ExceptionService.h"
#include "Service/FigureContainer.h"
#include "Geometry/Ellipse.h"

using namespace std;
int App::start(int argc, char* argv[]) {
    try {
        auto ellipse = Geometry::Ellipse::create(argc, argv);
        this->figure_container->addFigure(std::move(ellipse));
        this->displayService->displayInformation("total container area: %.2f",this->figure_container->TotalArea());

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