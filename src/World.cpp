#include "../include/World.hpp"

World::World(sf::RenderWindow &window) : 
mWindow(window), 
mWorldView(window.getDefaultView()), 
mWorldBounds(
    0.f,                                                    // left X position
    0.f,                                                    // top Y position
    mWorldView.getSize().x,                                 // width
    2000.f),                                                // height
mSpawnPosition(
    mWorldView.getSize().x / 2.f,                           // X position
    mWorldBounds.height - mWorldView.getSize().y / 2.f),  // Y position
mPlayerAircraft(nullptr){
    loadTextures();
    buildScene();

    mWorldView.setCenter(mSpawnPosition);
}

void World::loadTextures(){
    mTextures.load(Textures::Eagle, Eagle);
    mTextures.load(Textures::Raptor, Raptor);
    mTextures.load(Textures::Desert, Desert);
}