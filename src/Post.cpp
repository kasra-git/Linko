#include "../include/Post.hpp"

Post::Post(
    int ID,
    const std::string& text,
    const std::string& author
): id(ID) , text(text) , author(author) , likes(0){}

int Post::getID() const {return this->id;}
std::string Post::getAuthor() const {return this->author;}
std::string Post::getText() const {return this->text;}
int Post::getLikes() const {return this->likes;}
int Post::getCommentCount() const {return this->comments.size();}

void Post::like() {this->likes++;}
void Post::addComment(const Comment& comment){comments.push_back(comment);}