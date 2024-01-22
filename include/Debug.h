#ifndef DEBUG_LOG_H
#define DEBUG_LOG_H

#include <iostream>

#ifdef DEBUG
#define DEBUG_LOG(msg) std::cout << msg << std::endl
#else
#define DEBUG_LOG(msg)
#endif

#endif