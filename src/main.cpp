#include "../include/Network.hpp"
#include "../include/CommandLineInterface.hpp"

int main(){
    Network network;
    network.loadUser();
    network.loadPost();
    CommandLineInterface cli(network);
    cli.run();
    network.saveUser();
    network.savePost();
    return 0;
}