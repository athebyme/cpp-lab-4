#ifndef PATTERN_APP_H
#define PATTERN_APP_H
#include "Service/DisplayServiceInterface.h"
#include "Service/FigureContainer.h"

class App {
private:
    Service::Container* figure_container;
    Service::DisplayServiceInterface* displayService;
public:
    explicit App(
            Service::DisplayServiceInterface* displayService,
            Service::Container* figure_container
    );
    int start(int argc, char* argv[]);
    static App* create(Service::DisplayServiceInterface* displayService, Service::Container* figure_container);
};

#endif
