#include <iostream>
#include "TrainingBot.h"

int main() {
	std::cout << "Training bot lab\n\n";

	TrainingBot bot{};
	std::cout << "Starting health: " << bot.getHealth() << '\n';

	return 0;
}
