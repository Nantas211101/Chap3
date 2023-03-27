#include "../include/SceneNode.hpp"

SceneNode::SceneNode() : mParent(nullptr)
{
}

void SceneNode::attachChild(Ptr child){
    child->mParent = this;
    mChildren.push_back(std::move(child));
}

auto SceneNode::detachChild(const SceneNode& node) -> Ptr{
    
}