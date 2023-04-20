#include "src/App.h"
#include "src/Service/ConsoleDisplayService.h"
#include "src/Service/FigureContainer.h"

int main(int argc, char* argv[]) {
    return App::create(
            new Service::ConsoleDisplayService(),
            (new Service::Container)->create()
    )->start(argc, argv);
}