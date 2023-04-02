#pragma once

#include <thread>
#include <chrono>
#include <utility>
#include <string>
#include <format>
#include <iostream>

#include "types.hpp"
#include "progressbar.hpp"
#include "console.hpp"
#include "logging.hpp"
#include "datetime.hpp"

class Timer
{
 public:
	explicit Timer(usize seconds = 0, usize seconds_max = 25*60);
	[[nodiscard]] std::pair<usize,usize> time_passed() const;
	[[nodiscard]] std::string time_passed_string() const;
 private:
	enum class Status {
		stopped,
		running,
	};

	Status m_status;
	usize m_seconds;
	usize m_seconds_max;

	ProgressBar m_progress_bar;

	void start();
	void tick();
	void finish();
};