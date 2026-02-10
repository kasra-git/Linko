#ifndef COMMAND_LINE_INTERFACE_HPP
#define  COMMAND_LINE_INTERFACE_HPP

#include "Network.hpp"
#include "AuthManager.hpp"

class CommandLineInterface{
    public:
        CommandLineInterface(Network& n);
        void run();
    private:
        Network& network;
        AuthManager auth;
        User* currentUser;
};

#endif