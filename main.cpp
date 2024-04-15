#include <iostream>
#include <crow.h>
#include <fstream>
#include "createLoginRoutes.hpp"

/*
This is the execution command.
cd "/workspaces/Homie-Talk/" && g++ main.cpp createLoginRoutes.cpp -I"/workspaces/Homie-Talk/include" -pthread -std=c++17 -o main && sudo "/workspaces/Homie-Talk/"main
*/

int main() {
	crow::SimpleApp app;

	CROW_ROUTE(app, "/")([](){
		return "Hello World";
	});

	createLoginRoutes(app);

	app.port(3000).multithreaded().run();
}
