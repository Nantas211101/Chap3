#pragma once
#include <SFML/Graphics.hpp>
#include "../include/ResourceHolder.hpp"
#include "../include/SceneNode.hpp"
#include "../include/Aircraft.hpp"
#include <array>

class World : private sf::NonCopyable
{
public:
    explicit World(sf::RenderWindow &window);
    void update(sf::Time dt);
    void draw();

private:
    void loadTextures();
    void buildScene();

private:
    enum Layer
    {
        Background,
        Air,
        LayerCound
    };

private:
    sf::RenderWindow &mWindow;
    sf::View mWorldView;
    TextureHolder mTextures;
    SceneNode mSceneGraph;
    std::array<SceneNode*, LayerCount> mSceneLayers;

    sf::FloatRect mWorldBounds;
    sf::Vector2f mSpawnPosition;
    float mScrollSpeed;
    Aircraft* mPlayerAircraft;
};