#include <iostream>
#include <cstdlib>

#include "timer.hpp"

void print_usage()
{
	std::cout << "usage: ./pomodoro [duration] [start-offset]\n";
}

int main(int argc, const char** const argv)
{
	usize duration{25*60};
	usize start{0};
	if (argc > 3)
	{
		print_usage();
		std::exit(0);
	}

	if (argc > 1) {
		duration = std::stoi(argv[1])*60;;

		if (argc > 2)
			start = std::stoi(argv[2])*60;
	}

	Timer t{ start, duration };
	return 0;
}
