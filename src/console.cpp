#include "console.hpp"

namespace console
{
	void set_title(const std::string& s)
	{
		std::cout << "\033]0;" << s << '\007';
	}
} // namespace console