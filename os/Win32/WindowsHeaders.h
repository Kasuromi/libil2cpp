#pragma once

#if IL2CPP_PLATFORM_WIN32

#define WIN32_LEAN_AND_MEAN 1
#include <Windows.h>

#if IL2CPP_TARGET_WINRT
#include <roapi.h>
#endif

#endif
