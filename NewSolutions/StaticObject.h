#pragma once

#include "GameObject.h"

class StaticObject : public GameObject
{
public:
    StaticObject();

    StaticObject(const std::string& Name);
    virtual ~StaticObject();

    virtual void Update(float DeltaTime) override;
};

