#include "../include/Network.hpp"
#include <cstddef>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
Network::Network():nextPostID(1){}

bool Network::addUser(const User& new_user){
    if (users.count(new_user.getUsername()))
        return false;
    users[new_user.getUsername()] = new_user;
    return true;
}

User* Network::getUser(const std::string& user_name){
    if (!users.count(user_name)) 
        return nullptr;
    return &users[user_name];
}

Post& Network::createPost(const std::string& author,const std::string& text){
    posts.emplace_back(nextPostID++ , author,text);
    return posts.back();
}

std::vector<Post>& Network::getPosts() {
    return posts;
}

void Network::saveUser(){
    std::ofstream file("../data/users.txt");
    if(!file){
        std::cerr << "file not found" << std::endl;
        return;
    }

    for(auto& [username,user] : users){
        file << user.getUsername() << '|' << user.getPassword() << '|' << user.getDisplayName() << '|' << user.getBio() << "\n";
    }

    file.close();
}

void Network::loadUser(){
    std::ifstream file("../data/users.txt");
    if(!file){
        return;
    }
    std::string line;
    while(std::getline(file,line)){
        std::stringstream ss(line);
        std::string u , p ,d ,b;

        std::getline(ss,u,'|');
        std::getline(ss,p,'|');
        std::getline(ss,d,'|');
        std::getline(ss,b,'|');
        users[u] = User(u,p,d,b);
    }
    file.close();
}


void Network::savePost(){
    std::ofstream file("../data/posts.txt");

    if(!file){
        std::cerr << "file not found" << std::endl;
    }

    for(auto& post : posts){
        file << post.getID() << '|' << post.getAuthor() << '|' << post.getLikes() << '|' << post.getText() << "\n";
    }

    file.close();
}


void Network::loadPost(){
    std::ifstream file("../data/posts.txt");
    if(!file){
        return;
    }

    std::string line;
    while (std::getline(file,line)){
        std::stringstream ss(line);
        std::string id , author , likes,text;

        std::getline(ss,id,'|');
        std::getline(ss,author,'|');
        std::getline(ss,likes,'|');
        std::getline(ss,text,'|');

        Post p(std::stoi(id),author,text);
        for(size_t i = 0; i<std::stoi(likes);i++){
            p.like();
            posts.push_back(p);
        }
    }

    file.close();
}

Post* Network::findPostById(int id) {

    for (auto& post : posts) {
        if (post.getID() == id) {
            return &post;
        }
    }

    return nullptr;
}