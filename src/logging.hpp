#pragma once

#include <iostream>
#include <fstream>
#include "types.hpp"

namespace logging
{
	void log_to_text(const std::string& file_name, const std::string& contents);
}