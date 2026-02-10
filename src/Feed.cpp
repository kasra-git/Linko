#include "../include/Feed.hpp"
#include <iostream>

void Feed::show(Network& network){
    for (auto& post : network.getPosts()){
        std::cout << "[" << post.getID() <<
        "]: " << post.getAuthor() <<
        std::endl << post.getText() <<
        std::endl << "Likes: " <<
        post.getLikes() << std::endl <<
        "Comments: " << post.getCommentCount() << std::endl;
    }
}