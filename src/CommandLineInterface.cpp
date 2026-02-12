#include "../include/CommandLineInterface.hpp"
#include "../include/Feed.hpp"
#include <exception>
#include <iostream>
#include <sstream>
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
    std::string line;
    menu();
    while(true){
        try{
            std::cout << '>';
            std::getline(std::cin,line);

            if(line.empty()) {continue;}

            std::stringstream ss(line);
            std::string cmd;
            ss >> cmd;

            // Register user
            if(cmd == "register"){
                std::string u,p,d,b;
                ss >> u >> p >> d >> b;
                if(u.empty() || p.empty()){
                    std::cout << "Error: invalid input" << std::endl;
                    continue;
                }
                std::getline(ss >> std::ws,d);
                b = "";
                if(!auth.registerUser(u,p,d,b)){
                    std::cout << "Error: username already exists" << std::endl;
                }else{
                    std::cout << "User " << '\'' << u << '\'' << "registered successfuly" << std::endl; 
                }
            // Login User
            }else if(cmd == "login"){
                std::string u,p;
                ss >> u >> p;
                if(u.empty() || p.empty()){
                    std::cout << "Error: invalid input" << std::endl;
                    continue;
                }
                currentUser = auth.login(u,p);
                if(!currentUser){
                    std::cout << "Error: invalid username or password" << std::endl;
                }else{
                    std::cout << "Login successfuly" << std::endl;
                    std::cout << "Welcome" << '\'' << u << '\'' << std::endl;
                }
            
            // Logout
            }else if(cmd == "logout"){
                if(!currentUser){
                    std::cout << "Error: no user logged in" << std::endl;
                    continue;
                }

                currentUser = nullptr;
                std::cout << "Logged out successfully" << std::endl;

            // Post
            }else if(cmd == "post"){
                if(!currentUser){
                    std::cout << "Error: you must login first" << std::endl;
                    continue;
                }

                std::string text;
                std::getline(ss >> std::ws , text);

                if(text.empty()){
                    std::cout << "Error: post can not be empty" << std::endl;
                    continue;
                }

                Post& post = network.createPost(currentUser->getUsername(),text);

                std::cout << "Post created successfuly" << std::endl;
                std::cout << "Post ID: " << post.getID() << std::endl;
            // Follow
            }else if(cmd == "follow"){
                if(!currentUser){
                    std::cout << "Error: login required" << std::endl;
                    continue;
                }

                std::string target;
                ss >> target;

                if(target.empty()){
                    std::cout << "Error: invalid username" << std::endl;
                    continue;
                }

                if(target == currentUser->getUsername()){
                    std::cout << "Error: you cannot follow yourself" << std::endl;
                    continue;
                }

                User* targetUser = network.getUser(target);

                if(!targetUser){
                    std::cout << "Error: user does not exist" << std::endl;
                    continue;
                }

                currentUser->follow(target);
                std::cout << "You are now following " << '\'' << target << '\'' << std::endl;
                
            // Feed    
            }else if(cmd == "feed"){
                if(!currentUser){
                    std::cout << "Error: Login required" << std::endl;
                    continue;
                }
                Feed::show(network);
            
            // Like
            }else if(cmd == "like"){
                if(!currentUser){
                    std::cout << "Error: login required" << std::endl;
                    continue;
                }

                int id;
                ss >> id;

                if(ss.fail()){
                    std::cout << "Error: Invalid post ID" << std::endl;
                    continue;
                }

                Post* post = network.findPostById(id);

                if(!post){
                    std::cout << "Error: post not found" << std::endl;
                    continue;
                }

                post->like();
                std::cout << "Post " << '\'' << id << '\'' << "liked successfully" << std::endl;
            // Comment
            }else if(cmd == "command"){
                if(!currentUser){
                    std::cout << "Error: login required" << std::endl;
                    continue;
                }

                int id;
                ss >> id;

                if(ss.fail()){
                    std::cout << "Error: Invalid post ID" << std::endl;
                    continue;
                }

                std::string text;
                std::getline(ss >> std::ws,text);

                if(text.empty()){
                    std::cout << "Error: comment cannot be empty" << std::endl;
                    continue;
                }

                Post* post = network.findPostById(id);

                if(!post){
                    std::cout << "Error: post not found" << std::endl;
                    continue;
                }

                post->addComment(Comment(currentUser->getUsername(),text));
                std::cout << "Comment added successfully" << std::endl;
            
            // Save
            }else if(cmd == "save"){
                network.saveUser();
                network.savePost();
                std::cout << "Data saved successfully" << std::endl;
                break;

            // Exit
            }else if(cmd == "exit"){
                network.saveUser();
                network.savePost();
                std::cout << "Goodbye! See you soon on Linko" << std::endl;
                break;
            }else{
                std::cout << "Error: Unknown command" << std::endl;
            }
        }catch (const std::exception& e){
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}