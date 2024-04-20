#include <iostream>
#include <crow.h>
#include <fstream>
#include "createLoginRoutes.hpp"

#define ASIO_STANDALONE

/*
This is the execution command.
cd "./" && g++ main.cpp createLoginRoutes.cpp -I"./include" -pthread -std=c++17 -o main && sudo "./"main  
*/

int main() {
	crow::SimpleApp app;

	CROW_ROUTE(app, "/")([](){
		return "Hello World";
	});

	createLoginRoutes(app);

	app.bindaddr("0.0.0.0")
	.port(3000)
	.multithreaded()
	.run();
}
