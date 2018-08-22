#pragma once

class NumberedObject
{
public:
	NumberedObject();
	NumberedObject(const NumberedObject&);
	~NumberedObject();

	unsigned long serialNumber() const;

	static int amount();

	static bool testMode;

private:
	static int m_amo; //int instead of unsigned
	static unsigned long m_maxNumber;
	const unsigned long m_serialNo;
};