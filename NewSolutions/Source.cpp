#include <iostream>
#include "RootObject.h"
#include "StaticObject.h"
#include "Transform.h"



int main()
{
    auto root = new RootObject("root");

    auto objA = new StaticObject("ObjA");
    auto objB = new StaticObject("ObjB");

    root->AddChild(objA);
    root->AddChild(objB);

    objB->AddComponent(new Transform("obj_B_Component"));
    objB->AddChild(new StaticObject("Domek_B"));
    auto samochod = new StaticObject("Samochod");
    samochod->AddComponent(new Transform("samochod_Component"));
    root->AddChild(samochod);

#ifdef ENGINE_DEBUG
    root->PrintChildsWithComponents();
#endif

    for (;;)
    {
        std::cout << "----------------\n";
        root->Update(0.04f);
        std::cout << "----------------\n";
    }
    return 0;
}