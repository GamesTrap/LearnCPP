#pragma once

class This
{
public:
	int get() const;

	This& add(int v);

	This& assign(const This& t);

private:
	int m_value = 0;
};