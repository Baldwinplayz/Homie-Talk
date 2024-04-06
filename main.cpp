#include <iostream>
#include <crow.h>
#include <fstream>

/*
This is the execution command.
cd "/workspaces/Homie-Talk/" && g++ main.cpp -I"/workspaces/Homie-Talk/include" -pthread -std=c++17 -o main && sudo "/workspaces/Homie-Talk/"main
*/

/*
The following code open the login file in html and moves it into a string that will get sent to the user.
*/
std::ifstream loginFile("/workspaces/Homie-Talk/login.html");

std::string loginPage( (std::istreambuf_iterator<char>(loginFile) ),
                       (std::istreambuf_iterator<char>()    ) );

int main() {
  crow::SimpleApp app;
  
  CROW_ROUTE(app, "/login")([](){
    return loginPage;
  });

    app.port(80).multithreaded().run();
}