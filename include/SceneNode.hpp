#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <assert.h>

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
    typedef std::unique_ptr<SceneNode> Ptr;

public:
    SceneNode();

public:
    void attachChild(Ptr child);
    auto detachChild(const SceneNode &node) -> Ptr;

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    std::vector<Ptr> mChildren;
    SceneNode *mParent;
};