#include "StaticObject.h"



StaticObject::StaticObject()
    : GameObject()
{
}

StaticObject::StaticObject(const std::string& Name)
    : GameObject(Name)
{

}

StaticObject::~StaticObject()
{
}

void StaticObject::Update(float DeltaTime)
{
    std::cout << "Static Object " << GetName() <<  " Update "<< std::endl;
    GameObject::Update(DeltaTime);
}
