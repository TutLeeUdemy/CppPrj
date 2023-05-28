#pragma once

#ifdef UTILITY_DLL_EXPORT
	#define UTILITY_API __declspec(dllexport)
#else 
	#define UTILITY_API __declspec(dllimport)
#endif
