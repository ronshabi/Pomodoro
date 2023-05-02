#pragma once

#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <utility>

#include "console.hpp"
#include "datetime.hpp"
#include "logging.hpp"
#include "progressbar.hpp"

class Timer {
public:
    explicit Timer(int seconds = 0, int seconds_max = 25 * 60);
    std::pair<int, int> time_passed() const;
    std::string time_passed_string() const;
    void pause();
    void resume();
    void toggle();

private:
    enum class Status {
        stopped,
        running,
    };

    Status m_status;
    int m_seconds;
    int m_seconds_max;

    ProgressBar m_progress_bar;

    void start();
    void tick();
    void finish();
};