#include "logging.hpp"

namespace logging
{
    std::string get_homedir() {
        const char* homedir = getenv("HOME");

        if (!homedir) {
            homedir = getpwuid(getuid())->pw_dir;
        }

        return {homedir};
    }

	void log_to_text(const std::string& file_name, const std::string& contents) {
		std::ofstream log_file{file_name, std::ios::app};
        if (log_file.is_open()) {
		    log_file << contents << '\n';
        } else {
            std::cout << "Fatal error: could not write log file to " << file_name << std::endl;
        }
	}

    void convert_log_to_csv(const std::string& file_name) {
        std::ifstream log_file{file_name, std::ios::in};

        std::cout << datetime::date() << '\t';

        while (log_file) {
            std::string s;
            log_file >> s;

            std::cout << s << '\t';
        }
        std::cout << "\n";
    }
} // namespace logging