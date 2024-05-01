#include "crow.h"

void createStaticFilesRoutes(crow::SimpleApp &app) {
    CROW_ROUTE(app, "/staticFiles/images/Homie-Talk.png")([](const crow::request&, crow::response& res){
        res.set_static_file_info("staticFiles/images/Homie-Talk.png");
        res.end();
    });
}