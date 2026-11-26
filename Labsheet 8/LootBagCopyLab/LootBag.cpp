#include "LootBag.h"
#include <cassert>
#include <algorithm>

LootBag::LootBag(int t_slotCount)
    : m_slotCount{(t_slotCount >= 0 && t_slotCount <= MAX_SLOTS) ? t_slotCount : 0}
    , m_slots{m_slotCount > 0 ? new int[m_slotCount] : nullptr}
{
    for (int i = 0; i < m_slotCount; ++i)
    {
        m_slots[i] = (i + 1) * 10;
    }
}

LootBag::~LootBag()
{
    delete[] m_slots;
}

// copy constructor - new bag gets its own array
LootBag::LootBag(LootBag const& t_other)
    : m_slotCount{t_other.m_slotCount}
    , m_slots{t_other.m_slotCount > 0 ? new int[t_other.m_slotCount] : nullptr}
{
    if (m_slots != nullptr)
    {
        std::copy_n(t_other.m_slots, m_slotCount, m_slots);
    }
}

// copy assignment - check, prepare, copy, commit
LootBag& LootBag::operator=(LootBag const& t_other)
{
    if (this == &t_other)
    {
        return *this;
    }

    int* replacement{t_other.m_slotCount > 0 ? new int[t_other.m_slotCount] : nullptr};

    if (replacement != nullptr)
    {
        std::copy_n(t_other.m_slots, t_other.m_slotCount, replacement);
    }

    delete[] m_slots;
    m_slots = replacement;
    m_slotCount = t_other.m_slotCount;

    return *this;
}

int LootBag::slotCount() const
{
    return m_slotCount;
}

int LootBag::slotValue(int t_index) const
{
    assert(t_index >= 0 && t_index < m_slotCount);
    return m_slots[t_index];
}

bool LootBag::setSlot(int t_index, int t_value)
{
    if (t_index < 0 || t_index >= m_slotCount)
    {
        return false;
    }
    m_slots[t_index] = t_value;
    return true;
}

int const* LootBag::data() const
{
    return m_slots;
}
