#include "../include/Post.hpp"

Post::Post(
    int ID,
    const std::string& text,
    const std::string& author
): id(ID) , text(text) , author(author){}

int Post::getID() const {return this->id;}
std::string Post::getAuthor() const {return this->author;}
std::string Post::getText() const {return this->text;}
int Post::getCommentCount() const {return this->comments.size();}


void Post::addComment(const Comment& comment){comments.push_back(comment);} 

bool Post::addLike(const std::string& username) {

    if (likedUsers.find(username) != likedUsers.end())
        return false;

    likedUsers.insert(username);
    return true;
}

int Post::getLikes() const {
    return likedUsers.size();
}

const std::unordered_set<std::string>& Post::getLikedUsers() const {
    return likedUsers;
}

