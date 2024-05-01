#include <iostream>
#include <crow.h>
#include <fstream>
#include "createRoutes/createLoginRoutes.hpp"
#include "createRoutes/createStaticFilesRoutes.hpp"

/*
This is the execution command.
cd "./" && g++ main.cpp createRoutes/createLoginRoutes.cpp createRoutes/createStaticFilesRoutes.cpp -I"./include" -pthread -std=c++17 -o main && sudo "./"main  
*/

int main() {
	crow::SimpleApp app;

	CROW_ROUTE(app, "/")([](){
		auto homePage = crow::mustache::load_text("homepage.html");
        return homePage;
	});

	createLoginRoutes(app);

	createStaticFilesRoutes(app);

	app.bindaddr("0.0.0.0")
	.port(8080)
	.multithreaded()
	.run();
}
