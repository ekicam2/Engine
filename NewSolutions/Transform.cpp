#include "Transform.h"

#include <iostream>

Transform::Transform()
    :   Component()
{
}


Transform::Transform(const std::string & Name)
    :   Component(Name)
{
}

Transform::~Transform()
{
}

void Transform::Update(float DeltaTime)
{
    std::cout << "Transform Component " << GetName() << std::endl;
}
