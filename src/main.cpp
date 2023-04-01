#include <iostream>
#include "../include/Game.h"

int main()
{
    try{
        Game game;
        game.run();
    }
    catch (std::exception& e){
        std::cout << "\n EXCEPTION: " << e.what() << std::endl;
    }
    return 0;
}