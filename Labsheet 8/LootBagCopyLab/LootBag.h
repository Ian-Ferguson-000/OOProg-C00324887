#pragma once

class LootBag
{
public:
    static constexpr int MAX_SLOTS{5};
    explicit LootBag(int t_slotCount = 0);
    ~LootBag();

    LootBag(LootBag const& t_other);
    LootBag& operator=(LootBag const& t_other);

    int slotCount() const;
    int slotValue(int t_index) const;
    bool setSlot(int t_index, int t_value);
    int const* data() const;

private:
    int m_slotCount;
    int* m_slots;
};
