#include "../include/CommandLineInterface.hpp"
#include "../include/Feed.hpp"
#include <iostream>
#include <string>

CommandLineInterface::CommandLineInterface(Network& n):
    network(n) , auth(n) , currentUser(nullptr){}

void CommandLineInterface::menu(){
    std::cout << "Welcome to Linko Social Network!" << std::endl;
    std::string commands[] = {
        "--------------------------------",
        "Available commands:",
        "register",
        "login",
        "post",
        "feed",
        "follow",
        "like",
        "comment",
        "save",
        "load",
        "logout",
        "menu",
        "exit"
    };

    for (auto& text : commands){
        std::cout << "\t" << text << std::endl;
    }
}

void CommandLineInterface::run(){
    menu();
    while(true){
        std::cout << '>';
        std::string cmd;
        std::cin >> cmd;
        if(cmd == "register"){
            std::string u,p,d,b;
            std::cin >> u >> p >> d >> b;

            if(auth.registerUser(u,p,d,b)){
                std::cout << "User " << '\'' << u << '\'' << " registered successfully!" << std::endl;
            }else{
                std::cout << "Error: Username already exists." << std::endl;
            }
        }else if(cmd == "login"){
            std::string u,p;
            std::cin >> u >> p;
            if(auth.login(u,p)){
                std::cout << "Login successful ~ " << "Welcome," << u << std::endl;  
            }
        }else if(cmd == "exit"){
            std::cout << "Goodbye! See you soon on Linko." << std::endl;
            break;
        }else if(cmd == "logout"){
            if(!currentUser){
                std::cerr << "No user loggedIn" << std::endl;
            }
            currentUser = nullptr;
            std::cout << "Logged out successfully." << std::endl;
        }else if(cmd == "post"){
            if(!currentUser){
                std::cout << "No user loggedIn" << std::endl;
            }
            std::string text;
            std::getline(std::cin,text);
            if(text.empty()){
                std::cerr << "the text should not be empty" << std::endl;
            }
            Post& currenPost = network.createPost(currentUser->getUsername(),text);

            std::cout << "Post created successfully." << std::endl << "Post ID: " << currenPost.getID() << std::endl;
        }
    }
}