#include <iostream>
#include <crow.h>
#include <fstream>
#include "createLoginRoutes.hpp"

/*
This is the execution command.
cd "./" && g++ main.cpp createLoginRoutes.cpp -I"./include" -pthread -std=c++17 -o main && sudo "./"main  
*/

int main() {
	crow::SimpleApp app;

	CROW_ROUTE(app, "/")([](){
		auto homePage = crow::mustache::load_text("index.html");
        return homePage;
	});

	createLoginRoutes(app);

	app.bindaddr("0.0.0.0")
	.port(80)
	.multithreaded()
	.run();
}
