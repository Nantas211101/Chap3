#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceHolder.hpp"
#include "SceneNode.hpp"
#include "Aircraft.hpp"
#include "SpriteNode.hpp"
#include <array>
const char* Eagle = "";
const char* Raptor = "";
const char* Desert = "";

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
        LayerCount
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