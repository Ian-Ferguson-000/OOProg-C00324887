# Lab 01 Evidence – Loot Bag Copy Console

**Project:** LootBagCopyLab (C++17, v145, /W4, Debug x64)

## 01 – Project setup
- Empty C++ project created from scratch, named LootBagCopyLab.
- Settings: v145, ISO C++17, Level 4 warnings, /EHsc, precompiled headers off.
- **Result:** builds and prints `Loot bag copy lab`.

## 02 – One owning bag
- **Prediction:** a 3-slot bag holds 10, 20, 30. After `setSlot(1, 45)` it returns true and the middle is 45.
- **Result:** Count 3, First 10, Last 30, Middle changed true, Middle 45. Matches.
- **Owning vs borrowed pointer:** `m_slots` is an owning pointer because the bag allocated it with `new[]` and must release it with `delete[]`. The pointer that `data()` returns is borrowed: the caller can read through it but must never delete it.

## 03 – Shallow copy trace (paper only, not run)
| Moment | Left | Right | Problem |
|---|---|---|---|
| Before | X, 2 slots | Y, 3 slots | Two independent owners |
| After shallow `left = right` | Y, 3 slots | Y, 3 slots | X is leaked (nothing points to it); both bags think they own Y |

- **What happens to X?** Nothing points at it any more, so it can never be freed: a memory leak.
- **What happens at destruction?** Both destructors call `delete[]` on Y, a double delete (undefined behaviour or a crash). Changing a slot in one bag would also change the other.

## 04 – Copy assignment
- Order used: self check, then prepare the new array, then copy the values, then delete the old array and commit the new pointer and count, then `return *this`.
- If `new[]` throws during preparation, the destination has not been touched yet, so it stays valid.
- **Prediction:** Source 77, Target 9, separate buffers.
- **Result:** Source 77, Target 9, Independent storage true. Matches.

## 05 – Self-assignment through an alias
- **Prediction:** `target = *alias` hits the `this == &t_other` check and returns immediately, so Target stays 9.
- **Result:** Target still 9. Matches. The check compares addresses (identity), not contents.

## 06 – Copy constructor
- `LootBag copied = source;` creates a new object, so it calls the copy constructor, not `operator=`. There is no old buffer to delete and no self-check is needed.
- **Prediction:** Source middle 20, Copy middle 5, separate buffers.
- **Result:** Source middle 20, Copy middle 5, Independent storage true. Matches.

## 07 – Chaining and by-value
- `a = b = c` groups as `a = (b = c)`. Returning `LootBag&` lets the inner result feed the outer assignment.
- **Result:** A, B and C first are all 88. All independent true.
- `previewFirst(LootBag t_bag)` copy-constructs a local bag, so changing it to 99 doesn't affect the caller's bag.
- **Result:** Preview 99, Original 7. Matches.

## 08 – Final output
- Full console output matches the published expected output, including Empty bag (Count 0, No allocation true).
- No `setSlot()` calls are placed inside `assert()`.
