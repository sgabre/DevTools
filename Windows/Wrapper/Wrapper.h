#ifndef _WRAPPER_H_
#define _WRAPPER_H_

#ifdef _WIN32
#ifdef WRAPPER_EXPORTS
#define WRAPPER_API __declspec(dllexport)
#else
#define WRAPPER_API __declspec(dllimport)
#endif
#else
#define WRAPPER_API
#endif

WRAPPER_API void Function();

#endif // _WRAPPER_H_
