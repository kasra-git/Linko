#include "../include/CommandLineInterface.hpp"
#include "../include/Feed.hpp"
#include <iostream>
#include <string>

CommandLineInterface::CommandLineInterface(Network& n):
    network(n) , auth(n) , currentUser(nullptr){}

void CommandLineInterface::run(){
    std::string cmd;
    std::cout << "Linko Beta Version" << std::endl;

    while(true){
        std::cout << '>';
        std::cin >> cmd;

        if (cmd == "register"){
            std::string u,p,d,b;
            std::cin >> u >> p >> d;
            std::cin.ignore();
            std::getline(std::cin,b);
            if(auth.registerUser(u,p,d,b)){
                std::cout << "Registered:)" << std::endl;
            }else{
                std::cout << "Username exists" << std::endl;
            }
        }else if(cmd == "login"){
            std::string u,p;
            std::cin >> u >> p;
            currentUser = auth.login(u,p);
            if (currentUser){
                std::cout << "Login successful" << std::endl;
            }else{
                std::cout << "Login faild" << std::endl;
            }
        }else if(cmd == "post" && currentUser){
            std::string text;
            std::getline(std::cin,text);
            network.createPost(currentUser->getUsername(),text);
            std::cout << "Post created" << std::endl;
        }else if(cmd == "feed"){
            Feed::show(network);
        }else if(cmd == "exit"){
            break;
        }
    }
}