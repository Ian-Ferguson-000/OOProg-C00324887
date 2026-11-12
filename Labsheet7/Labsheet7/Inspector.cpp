#include "Inspector.h"

#include "ArenaObjects.h"

#include <typeinfo>

int readGuardHealth(ArenaObject const* t_object)
{
	Guard const* pGuard{dynamic_cast<Guard const*>(t_object)};
	if (pGuard == nullptr)
	{
		return -1;
	}

	return pGuard->health();
}

bool isExactGuard(ArenaObject const* t_object)
{
	if (t_object == nullptr)
	{
		return false;
	}

	return typeid(*t_object) == typeid(Guard);
}

int requireGuardHealth(ArenaObject const& t_object)
{
	Guard const& asGuard{dynamic_cast<Guard const&>(t_object)};
	return asGuard.health();
}

int countGuardViews(ArenaObject const* const* t_objects,
					int t_count)
{
	if (t_count < 0 || t_count > 4)
	{
		return -1;
	}

	if (t_count == 0)
	{
		return 0;
	}

	if (t_objects == nullptr)
	{
		return -1;
	}

	int matches{0};
	for (int index{0}; index < t_count; ++index)
	{
		ArenaObject const* slot{t_objects[index]};
		if (slot == nullptr)
		{
			continue;
		}

		Guard const* asGuard{dynamic_cast<Guard const*>(slot)};
		if (asGuard != nullptr)
		{
			++matches;
		}
	}

	return matches;
}

int countExactGuards(ArenaObject const* const* t_objects,
					 int t_count)
{
	if (t_count < 0 || t_count > 4)
	{
		return -1;
	}

	if (t_count == 0)
	{
		return 0;
	}

	if (t_objects == nullptr)
	{
		return -1;
	}

	int matches{0};
	for (int index{0}; index < t_count; ++index)
	{
		ArenaObject const* slot{t_objects[index]};
		if (slot == nullptr)
		{
			continue;
		}

		if (typeid(*slot) == typeid(Guard))
		{
			++matches;
		}
	}

	return matches;
}
