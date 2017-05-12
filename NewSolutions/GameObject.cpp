#include "GameObject.h"
#include <algorithm>

uint64_t GameObject::InstanceCount = 0;

GameObject::GameObject()
    : UUID(GameObject::InstanceCount)
{
    GameObject::InstanceCount++;
    Name = "GameObject " + std::to_string(UUID);
}

GameObject::GameObject(const std::string& Name)
    :   GameObject()
{
    this->Name = Name;
}

const std::string & GameObject::GetName() const
{
    return Name;
}

void GameObject::SetName(const std::string & NewName)
{
    Name = NewName;
}

void GameObject::AddChild(GameObject::Ptr Child)
{
    Child->SetParent(this);
    Children.push_back(Child);
}

void GameObject::RemoveChild(Ptr Child)
{
   std::remove(Children.begin(), Children.end(), Child);
}

const std::vector<GameObject::Ptr>& GameObject::GetChildren() const
{
    return Children;
}

void GameObject::AddComponent(Component::Ptr Component)
{
    Components.push_back(Component);
}

void GameObject::RemoveComponent(Component::Ptr Component)
{
    std::remove(Components.begin(), Components.end(), Component);
}

const std::vector<Component::Ptr>& GameObject::GetComponents() const
{
    return Components;
}

const GameObject::Ptr GameObject::GetParent() const
{
    return Parent;
}

void GameObject::Update(float DeltaTime)
{
    for (auto Component : GetComponents())
    {
        Component->Update(DeltaTime);
    }

    for (auto Child : GetChildren())
    {
        Child->Update(DeltaTime);
    }
}

void GameObject::SetParent(Ptr NewParent)
{
    Parent = NewParent;
}
