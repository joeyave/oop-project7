#include "src/Application.h"

int main() {
    Config config;
    config.chooseColorTheme();

    Application application(config);
    application.run();
}
