#pragma once

#include "GameObject.h"

class RootObject : public GameObject
{
public:
    RootObject() = delete;
    RootObject(const std::string& Name);
    virtual ~RootObject();

    virtual void Update(float DeltaTime) override;
};

