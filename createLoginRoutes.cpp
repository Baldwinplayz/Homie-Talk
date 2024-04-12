#include "crow.h"

void createLoginRoutes(crow::SimpleApp &app) {
    CROW_ROUTE(app, "/login")([](){
        auto loginPage = crow::mustache::load_text("login.html");
        return loginPage;
    });
}