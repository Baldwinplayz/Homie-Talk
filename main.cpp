#include <iostream>
#include "include/crow.h"

int main() {
  crow::SimpleApp app;
  CROW_ROUTE(app, "/")([](){
    return "Home Page";
  })
    app.port(80).multithreaded().run();
}