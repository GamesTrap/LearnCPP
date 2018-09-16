#pragma once

#ifdef NDEBUG
	#define ASSERT(condition, exception); //Null statement
#else
	#define ASSERT(condition, exception) \
	if (!(condition)) \
	throw exception;
#endif