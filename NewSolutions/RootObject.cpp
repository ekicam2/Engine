#include "RootObject.h"



RootObject::RootObject(const std::string& Name)
    : GameObject(Name)
{
    SetParent(this);
}


RootObject::~RootObject()
{
}

void RootObject::Update(float DeltaTime)
{
    GameObject::Update(DeltaTime);
}
