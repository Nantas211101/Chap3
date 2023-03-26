#pragma once
#include <SFML\Graphics.hpp>

class Entity
{
public:
    void setVelocity(sf::Vector2f velocity);
    void setVelocity(float vx, float vy);
    auto getVelocity() -> sf::Vector2f const;

private:
    sf::Vector2f mVelocity;
};