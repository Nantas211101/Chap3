#include "../include/SceneNode.hpp"

SceneNode::SceneNode() : mParent(nullptr)
{
}

void SceneNode::attachChild(Ptr child)
{
    child->mParent = this;
    mChildren.push_back(std::move(child));
}

auto SceneNode::detachChild(const SceneNode &node) -> Ptr
{
    auto found = std::find_if(mChildren.begin(), mChildren.end(), [&](Ptr &p) -> bool
                              { return p.get() == &node; }); // check the element's pointer p.get() == address of the node or not
    assert(found != mChildren.end());

    auto result = std::move(*found);
    result->mParent = nullptr;
    mChildren.erase(found); // erase iterator
    return result; // return unique_ptr
}