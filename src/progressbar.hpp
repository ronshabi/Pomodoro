#pragma once

#include <iostream>

class ProgressBar
{
 public:
	ProgressBar(int size = 10);
	void set_size(int size);
	void set_percentage(double percentage);
 private:
	double m_percentage;
	int m_size;
	friend std::ostream& operator<< (std::ostream& stream, const ProgressBar& pb);
};
