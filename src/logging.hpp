#pragma once

#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>

#include <fstream>
#include <iostream>

#include "datetime.hpp"

namespace logging {
std::string get_homedir();

void log_to_text(const std::string& file_name, const std::string& contents);

void convert_log_to_csv(const std::string& file_name);
} // namespace logging