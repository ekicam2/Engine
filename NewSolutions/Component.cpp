#include "Component.h"

uint64_t Component::InstanceCount = 0;

Component::Component()
    : UUID(Component::InstanceCount)
{
    Component::InstanceCount++;
    Name = "Component " + std::to_string(UUID);
}

Component::Component(const std::string& Name)
    : Component()
{
    this->Name = Name;
}

void Component::SetName(const std::string & NewName)
{
    Name = NewName;
}

const std::string & Component::GetName() const
{
    return Name;
}

uint64_t Component::GetUUID() const
{
    return UUID;
}

