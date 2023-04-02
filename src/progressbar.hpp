#pragma once

#include <iostream>
#include "types.hpp"
class ProgressBar
{
 public:
	ProgressBar(usize size = 10);
	void set_size(usize size);
	void set_percentage(double percentage);
 private:
	double m_percentage;
	usize m_size;
	friend std::ostream& operator<< (std::ostream& stream, const ProgressBar& pb);
};
