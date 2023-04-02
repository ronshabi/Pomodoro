#include "logging.hpp"

namespace logging
{
	void log_to_text(const std::string& file_name, const std::string& contents) {
		std::ofstream log_file{file_name, std::ios::app};
		log_file << contents << '\n';
	}
}