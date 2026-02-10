#include "../include/Network.hpp"
#include "../include/CommandLineInterface.hpp"

int main(){
    Network network;
    CommandLineInterface cli(network);
    cli.run();
    return 0;
}