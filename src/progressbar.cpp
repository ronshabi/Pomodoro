#include "progressbar.hpp"

ProgressBar::ProgressBar(usize size) : m_percentage{ 0 }, m_size{ size }
{

}

void ProgressBar::set_size(usize size)
{
	m_size = size;
}

void ProgressBar::set_percentage(double percentage)
{
	m_percentage = percentage;
}

std::ostream& operator<<(std::ostream& stream, const ProgressBar& pb)
{
	auto draw_amount{ static_cast<usize>(pb.m_percentage * pb.m_size) };
	auto space_amount{ pb.m_size - draw_amount };
	stream << '[';
	stream << std::string(draw_amount, '=');
	stream << std::string(space_amount, ' ');
	stream << ']';

	return stream;
}

