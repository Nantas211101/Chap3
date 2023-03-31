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

void World::buildScene(){
    for(std::size_t i = 0; i < LayerCount; ++i){
        SceneNode::Ptr layer(new SceneNode());
        mSceneLayers[i] = layer.get();

        mSceneGraph.attachChild(std::move(layer)); // attach the layer into the graph
    }

    // Get the Textures::Desert take the bounded and set it to repeated
    sf::Texture& texture = mTextures.get(Textures::Desert);
    sf::IntRect textureRect(mWorldBounds);
    texture.setRepeated(true);
    
    // Link the texture to the spritenode
    std::unique_ptr<SpriteNode> backgroundSprite(
        new SpriteNode(texture, textureRect));
    backgroundSprite->setPosition(
        mWorldBounds.left,
        mWorldBounds.top);          // set the position (to fullfill the view)
                                    // because the backgroundsprite did not set the origin so its origin is the top left
    mSceneLayers[Background]
        ->attachChild(std::move(backgroundSprite)); // attach the child for the background
}