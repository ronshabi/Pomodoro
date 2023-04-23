#include <iostream>
#include <cstdlib>
#include <csignal>

#include "timer.hpp"
#include "logging.hpp"

void print_usage()
{
    std::cout << "C++ Pomodoro utility, 2023(c) Ron Shabi.\n";
    std::cout << "usage: ./pomodoro [duration] [start-offset] --csv\n";
    std::cout << "By default, logs are saved in ~/.pomodoro\n";
}

int main(int argc, const char** const argv)
{
    usize duration{25*60};
    usize start{0};

    if (argc==1) {

    }
    else if (argc==2) {
        if (std::strcmp(argv[1], "csv")==0) {
            logging::convert_log_to_csv(logging::get_homedir() + "/.pomodoro/log-"+datetime::date()+".txt");
            std::exit(0);
        }

        duration = std::stoi(argv[1])*60;
    }
    else if (argc==3) {
        duration = std::stoi(argv[1])*60;
        start = std::stoi(argv[2])*60;
    }
    else {
        print_usage();
        std::exit(0);
    }

    Timer t{start, duration};

    return 0;
}
