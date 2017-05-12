#pragma once
#include "Component.h"
class Transform : public Component
{
public:
    Transform();
    Transform(const std::string& Name);
    virtual ~Transform();

    virtual void Update(float DeltaTime) override;
};

