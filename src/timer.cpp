#include "timer.hpp"

Timer::Timer(usize seconds, usize seconds_max)
	: m_seconds{ seconds },
	  m_seconds_max{ seconds_max },
	  m_status{ Status::running },
	  m_progress_bar{ 20 }
{
	start();
}

void Timer::start()
{

	while (m_seconds <= m_seconds_max && m_status == Status::running)
	{
		tick();
	}

	m_status = Status::stopped;
	finish();
}

void Timer::tick()
{
	// Get percentage
	double percentage = static_cast<double>(m_seconds) / m_seconds_max;
	m_progress_bar.set_percentage(percentage);

	// Print time
	std::cout << time_passed_string() << "\t" << m_progress_bar << '\r' << std::flush;

	// Set console title
	console::set_title(time_passed_string());


	// Sleep
	using namespace std::chrono_literals;
	std::this_thread::sleep_for(1s);

	// Increment seconds
	++m_seconds;
}

void Timer::finish()
{
	// set status
	m_status = Status::stopped;
	// log

	auto log_file_name{"log-" + datetime::date() + ".txt"};

	logging::log_to_text(log_file_name, datetime::time_hh_mm());
}

std::pair<usize, usize> Timer::time_passed() const
{
	auto seconds = m_seconds % 60;
	auto minutes = m_seconds / 60;

	return { minutes, seconds };
}

std::string Timer::time_passed_string() const
{
	char buf[7];
	auto [minutes, seconds] = time_passed();

	std::snprintf(buf, 6, "%02lu:%02lu", minutes, seconds);
	buf[6] = 0;

	return { buf };
}