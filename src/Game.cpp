#include "../include/Game.h"

//===================================================================//
// Main function

Game::Game():
    mWindow(sf::VideoMode(640, 480), "World"), 
    mTexture(),
    mPlayer(),
    mWorld(mWindow){
    if(!mTexture.loadFromFile("C:/Users/ADMIN/Pictures/Samsung Flow/IMG_20230214_230223_678.jpg")){
        // Handle loading error    
    }
    mPlayer.setTexture(mTexture);
    mPlayer.setPosition(100.f, 100.f);
}

void Game::run(){
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while(mWindow.isOpen()){
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while(timeSinceLastUpdate > TimePerFrame){
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}

void Game::processEvents(){
    sf::Event event;
    while(mWindow.pollEvent(event)){
        switch(event.type){
            // case sf::Event::KeyPressed:
            //     handlePlayerInput(event.key.code, true);
            //     break;
            // case sf::Event::KeyReleased:
            //     handlePlayerInput(event.key.code, false);
            //     break;
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }
}

void Game::update(sf::Time deltaTime){
    // sf::Vector2f movement(0.f, 0.f);
    // if(mIsMoveUp)
    //     movement.y -= PlayerSpeed;
    // if(mIsMoveDown)
    //     movement.y += PlayerSpeed;
    // if(mIsMoveLeft)
    //     movement.x -= PlayerSpeed;
    // if(mIsMoveRight)
    //     movement.x += PlayerSpeed;

    // mPlayer.move(movement * deltaTime.asSeconds());

    mWorld.update(deltaTime);
}

void Game::render(){
    mWindow.clear();
    mWorld.draw();
    
    mWindow.setView(mWindow.getDefaultView());
    mWindow.display();
}
//===================================================//





// Additional function

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed){
    if(key == sf::Keyboard::W)
        mIsMoveUp = isPressed;
    else if(key == sf::Keyboard::S)
        mIsMoveDown = isPressed;
    else if(key == sf::Keyboard::A)
        mIsMoveLeft = isPressed;
    else if(key == sf::Keyboard::D)
        mIsMoveRight = isPressed;
}
//=========================================================//