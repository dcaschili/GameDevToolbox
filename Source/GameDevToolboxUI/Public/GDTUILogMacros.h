#pragma once

#define GDTUI_SHORT_LOG(LogCategory, VerbosityLevel, Format, ...) UE_LOG(LogCategory, VerbosityLevel, TEXT("%s: %s"), *FString(__FILE__), Format, ##__VA_ARGS__ )

#define GDTUI_LOG(LogCategory, VerbosityLevel, Format, ...) UE_LOG(LogCategory, VerbosityLevel, TEXT("%s %s (%d): %s"), *FString(__FILE__), *FString(__FUNCTION__), *FString::FromInt(__LINE__), Format, ##__VA_ARGS__ )