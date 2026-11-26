#include "LootBag.h"
#include <iostream>

int previewFirst(LootBag t_bag)
{
    t_bag.setSlot(0, 99);
    return t_bag.slotValue(0);
}

int main()
{
    std::cout << std::boolalpha;
    std::cout << "Loot bag copy lab\n";

    // Basic bag
    {
        LootBag bag{3};
        std::cout << "\nBasic bag\n";
        std::cout << "Count: " << bag.slotCount() << "\n";
        std::cout << "First: " << bag.slotValue(0) << "\n";
        std::cout << "Last: " << bag.slotValue(bag.slotCount() - 1) << "\n";
        bool changed{bag.setSlot(1, 45)};
        std::cout << "Middle changed: " << changed << "\n";
        std::cout << "Middle: " << bag.slotValue(1) << "\n";
    }

    // Deep assignment + self-assignment
    {
        LootBag source{3};
        source.setSlot(0, 77);
        LootBag target{1};
        target = source;
        target.setSlot(0, 9);

        std::cout << "\nDeep assignment\n";
        std::cout << "Source: " << source.slotValue(0) << "\n";
        std::cout << "Target: " << target.slotValue(0) << "\n";
        std::cout << "Independent storage: "
                  << (source.data() != nullptr && target.data() != nullptr
                      && source.data() != target.data()) << "\n";

        LootBag* alias{&target};
        target = *alias;
        std::cout << "\nSelf-assignment\n";
        std::cout << "Target still: " << target.slotValue(0) << "\n";
    }

    // Copy construction
    {
        LootBag source{2};
        LootBag copied = source;
        copied.setSlot(1, 5);

        std::cout << "\nCopy construction\n";
        std::cout << "Source middle: " << source.slotValue(1) << "\n";
        std::cout << "Copy middle: " << copied.slotValue(1) << "\n";
        std::cout << "Independent storage: "
                  << (source.data() != nullptr && copied.data() != nullptr
                      && source.data() != copied.data()) << "\n";
    }

    // Chained assignment
    {
        LootBag a{1};
        LootBag b{2};
        LootBag c{3};
        c.setSlot(0, 88);
        a = b = c;

        std::cout << "\nChained assignment\n";
        std::cout << "A first: " << a.slotValue(0) << "\n";
        std::cout << "B first: " << b.slotValue(0) << "\n";
        std::cout << "C first: " << c.slotValue(0) << "\n";
        bool allIndependent{a.data() != nullptr && b.data() != nullptr && c.data() != nullptr
                            && a.data() != b.data() && b.data() != c.data() && a.data() != c.data()};
        std::cout << "All independent: " << allIndependent << "\n";
    }

    // Empty bag
    {
        LootBag empty{};
        std::cout << "\nEmpty bag\n";
        std::cout << "Count: " << empty.slotCount() << "\n";
        std::cout << "No allocation: " << (empty.data() == nullptr) << "\n";
    }

    // By-value preview
    {
        LootBag bag{1};
        bag.setSlot(0, 7);
        int preview{previewFirst(bag)};

        std::cout << "\nBy-value preview\n";
        std::cout << "Preview: " << preview << "\n";
        std::cout << "Original: " << bag.slotValue(0) << "\n";
    }

    return 0;
}
