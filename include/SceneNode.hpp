#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class SceneNode
{
public:
    typedef std::unique_ptr<SceneNode> Ptr;

public:
    SceneNode();  

public:
    void attachChild(Ptr child);
    auto detachChild(const SceneNode& node) -> Ptr;

private:
    std::vector<Ptr> mChildren;
    SceneNode *mParent;
};