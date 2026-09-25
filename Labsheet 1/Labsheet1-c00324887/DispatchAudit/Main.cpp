#include "Dispatch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

int main()
{
	Dispatch::printHeading();

	std::ifstream in("batches.txt");
	if (!in)
	{
		std::cerr << "Failed to open batches.txt\n";
		return 1;
	}

	int batchCount = 0;
	int totalStock = 0;
	int lowBatchCount = 0;

	for (;;)
	{
		in >> std::ws;
		if (in.eof())
		{
			break;
		}

		int value = 0;
		if (!(in >> value))
		{
			std::cerr << "Invalid data in batches.txt\n";
			return 1;
		}

		if (value < 0 || value > 40)
		{
			std::cerr << "Value out of range in batches.txt\n";
			return 1;
		}

		++batchCount;
		if (batchCount > 12)
		{
			std::cerr << "Too many entries in batches.txt\n";
			return 1;
		}

		totalStock += value;
		if (value < 10)
		{
			++lowBatchCount;
		}
	}

	if (batchCount == 0)
	{
		std::cerr << "No entries in batches.txt\n";
		return 1;
	}

	std::string depotName;
	std::cout << "Enter depot name: ";
	// Read the depot name. An empty name is allowed; if reading fails, stop with an error.
	if (!std::getline(std::cin, depotName))
	{
		std::cerr << "Failed to read depot name\n";
		return 1;
	}
	// Keep the name exactly as entered, even if it is empty.

	// Now ask for the requested units. We accept an integer at the start of the response and ignore
	// any extra characters on the same line. If there's no leading integer or the number is out
	// of range, ask again. If input ends before we get a valid number, exit with an error.
	int requested = 0;
	for (;;)
	{
		std::cout << "Enter requested units: ";

		if (!(std::cin >> requested))
		{
			// No leading number was found. If input ended, report the error; otherwise prepare to try again.
			if (std::cin.eof())
			{
				std::cerr << "Input ended before a valid requested-units value was provided\n";
				return 1;
			}
			// Clear the error and skip the rest of this line, then prompt again.
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Invalid integer response; please try again.\n";
			continue;
		}

		// We got a number; ignore any remaining characters on the same line.
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		// Check the number is between 0 and 60.
		if (requested < 0 || requested > 60)
		{
			std::cerr << "Requested units out of range (0-60); please try again.\n";
			// If input ended after this bad number, stop with an error.
			if (std::cin.eof())
			{
				return 1;
			}
			continue;
		}

		// Valid number obtained; proceed.
		break;
	}

	int availableStock = totalStock;
	int dispatchCount = 0;

	int* selectedQuantity = &availableStock;

	int dispatched = (requested < availableStock) ? requested : availableStock;

	if (selectedQuantity != nullptr)
	{
		*selectedQuantity -= dispatched;
	}

	selectedQuantity = &dispatchCount;
	if (dispatched > 0 && selectedQuantity != nullptr)
	{
		++(*selectedQuantity);
	}

	selectedQuantity = nullptr;

	std::cout << "Depot: " << depotName << '\n';
	std::cout << "Batches: " << batchCount << '\n';
	std::cout << "Low batches: " << lowBatchCount << '\n';
	std::cout << "Original stock: " << totalStock << '\n';
	std::cout << "Requested units: " << requested << '\n';
	std::cout << "Dispatched units: " << dispatched << '\n';
	std::cout << "Remaining stock: " << availableStock << '\n';
	std::cout << "Dispatch count: " << dispatchCount << '\n';

	if (selectedQuantity == nullptr)
	{
		std::cout << "No quantity selected." << '\n';
	}

	return 0;
}
