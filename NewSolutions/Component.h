#pragma once

#include <string>

class Component
{
public:
    using Ptr = Component*;

    Component();
    Component(const std::string& name);
    virtual ~Component() = default;

    void SetName(const std::string& NewName);
    const std::string& GetName() const;

    uint64_t GetUUID() const;

    virtual void Update(float DeltaTime) = 0;

private:
    std::string                 Name;
    static uint64_t             InstanceCount;
    uint64_t                    UUID;
};