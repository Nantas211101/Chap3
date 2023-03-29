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
    return result;          // return unique_ptr
}

void SceneNode::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform(); // *= is a operator to combines the parent's absolute transform (states) with the current node's relative one (target). result will be the current node
    drawCurrent(target, states);

    // Way 1 of iteration
    for (const Ptr &child : mChildren)
    {
        child->draw(target, states);
    }

    // Way 2 of iteration
    // for (auto itr = mChildren.begin(); itr != mChildren.end(); ++itr)
    // {
    //     (*itr)->draw(target, states);
    // }
}

void SceneNode::update(sf::Time dt)
{
    updateCurrent(dt);
    updateChildren(dt);
}

void SceneNode::updateCurrent(sf::Time dt)
{
}

void SceneNode::updateChildren(sf::Time dt)
{
    for (const Ptr &child : mChildren)
        child->update(dt);
}
