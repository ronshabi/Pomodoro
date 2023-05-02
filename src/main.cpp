#include <iostream>
#include <cstdlib>
#include <csignal>
#include <vector>
#include <cctype>

#include "timer.hpp"
#include "logging.hpp"

void print_usage()
{
    std::cout << "C++ Pomodoro utility, 2023(c) Ron Shabi.\n";
    std::cout << "usage: pomodoro [duration] [start-offset] --csv\n";
    std::cout << "By default, logs are saved in ~/.pomodoro\n";
    std::exit(0);
}

int main(int argc, const char** const argv)
{
    int duration{25*60};
    int start{0};

    // Convert argv to string vector 
    std::vector<std::string> arguments{};
    for (int i = 1; i < argc; i++) {
        arguments.push_back(argv[i]);
    }

    // Argument parsing
    if (arguments.size() == 1) {
        int session_duration = std::atoi(arguments.at(0).c_str());

        // not a number
        if (session_duration <= 0) {
            // single argument checking is done here
            if (arguments.at(0) == "csv") {
                logging::convert_log_to_csv(logging::get_homedir() + "/.pomodoro/log-"+datetime::date()+".txt");
                std::exit(0);
            } else {
                print_usage();
            }
        }

        // valid number
        duration = session_duration * 60;
        
    } else if (arguments.size() == 2) {
        int session_duration =  std::atoi(arguments.at(0).c_str());
        int starting_offset =  std::atoi(arguments.at(1).c_str());

        // Invalid duration arguments
        if (session_duration <= 0 || starting_offset <= 0) {
            print_usage();
        }

        // Valid duration arguments
        duration = session_duration * 60;
        start = session_duration * 60;
    } else {
        print_usage();
    }

    Timer t{start, duration};

    return 0;
}
