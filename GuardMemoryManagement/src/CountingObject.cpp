#include "CountingObject.h"

#include "Guard.h"

std::set<void*> CountingObject::m_objects;
int CountingObject::m_total = 0;

Guard g;