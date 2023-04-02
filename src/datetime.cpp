#include "datetime.hpp"

namespace datetime
{
	auto get_current_time()
	{
		auto now = std::chrono::system_clock::now();
		auto now_as_time_t = std::chrono::system_clock::to_time_t(now);
		auto now_as_tm = std::localtime(&now_as_time_t);

		return now_as_tm;
	}

	std::string date()
	{
		char buffer[13];
		std::memset(buffer, 0, sizeof(buffer));
		std::strftime(buffer, 12, "%d-%m-%Y", get_current_time());

		return { buffer };
	}

	std::string time_hh_mm() {
		char buffer[7];
		std::memset(buffer, 0, sizeof(buffer));
		std::strftime(buffer, 12, "%H:%M", get_current_time());

		return { buffer };
	}

}