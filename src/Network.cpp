#include "../include/Network.hpp"
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
        file << user.getUsername() << '|' << user.getPassword() << '|' << user.getDisplayName() << '\n' << user.getBio() << "\n";
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

    if(!file.is_open()){
        std::cerr << "Error: file posts.txt not found" << std::endl;
        return;
    }

    for(const auto& post : posts){
        file << post.getID() << "|" << post.getAuthor() << "|" << post.getText() << "|";
        
        const auto& likedUsers = post.getLikedUsers();
        bool first = true;

        for(const auto& user : likedUsers){
            if(!first){
                file << ',';
            }
            file << user;
            first = false;
        }
        file << '\n';
    }
    file.close();
}


void Network::loadPost(){
    std::ifstream file("../data/posts.txt");
    if(!file.is_open()){
        std::cerr << "Error: posts.txt not found" <<std::endl;
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

        if(id.empty() || author.empty()){
            std::cout << "Error: invalid inputs" << std::endl;
            return;
        }

        int ID = std::stoi(id);

        Post p(ID,author,text);

        std::stringstream likeStream(likes);
        std::string username;

        while (std::getline(likeStream,username,',')) {
            if(!username.empty()){
                p.addLike(username);
            }
        }
        posts.push_back(p);

        if(ID >= nextPostID){
            nextPostID = ID + 1;
        }
        file.close();
    }
}

Post* Network::findPostById(int id) {

    for (auto& post : posts) {
        if (post.getID() == id) {
            return &post;
        }
    }

    return nullptr;
}

void Network::feed(Network& network){
    for (auto& post : network.getPosts()){
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "[" << post.getID() <<
        "]: " << post.getAuthor() <<
        std::endl << post.getText() <<
        std::endl << "Likes: " <<
        post.getLikes() << '|' << " Comments: " <<
        post.getCommentCount() << std::endl;
        std::cout << "------------------------------------------" << std::endl;
    }
}