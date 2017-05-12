#pragma once
#include <vector>
#include <string>
#include <stdint.h>

#include "Macros.h"
#include "Component.h"

class GameObject
{
public:
    using Ptr = GameObject*;

    GameObject();
    GameObject(const std::string& Name);
    virtual ~GameObject() = default;

    const std::string& GetName() const;
    void SetName(const std::string& NewName);

    void AddChild(Ptr Child);
    void RemoveChild(Ptr Child);
    const std::vector<Ptr>& GetChildren() const;

    void AddComponent(Component::Ptr Component);
    void RemoveComponent(Component::Ptr Component);
    const std::vector<Component::Ptr>& GetComponents() const;

    const Ptr GetParent() const;

    virtual void Update(float DeltaTime);

#ifdef ENGINE_DEBUG
    void PrintChildsWithComponents(uint64_t IndentLevel = 0)
    {
        for (uint64_t i = 0; i < IndentLevel; ++i)
            std::cout << "    ";
            std::cout << Name << std::endl;

            for (auto Component : Components)
            {
                for (uint64_t i = 0; i < IndentLevel; ++i)
                std::cout << "    ";
                std::cout << "  " << Component->GetName() << std::endl;
            }

        for (auto Child : Children)
        {
            Child->PrintChildsWithComponents(IndentLevel + 1);
        }
    }
#endif

protected:
    void SetParent(Ptr NewParent);

private:
    std::string                 Name;
    static uint64_t             InstanceCount;
    uint64_t                    UUID;
    Ptr                         Parent;
    std::vector<Ptr>            Children;
    std::vector<Component::Ptr> Components;
};