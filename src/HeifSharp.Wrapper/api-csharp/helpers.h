#pragma once

#define DLL_EXPORTS
#ifdef DLL_EXPORTS
   #define DLL_API __declspec(dllexport)
#else
   #define DLL_API __declspec(dllimport)
#endif