#include <iostream>
#include "crow_all.h"

int main() {
  crow::SimpleApp app;
  CROW_ROUTE(app, "/")([](){
    return "Home Page";
  })
    app.port(80).multithreaded().run();
}