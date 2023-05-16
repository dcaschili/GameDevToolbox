#pragma once

#define GDTUI_SHORT_LOG(LogCategory, VerbosityLevel, Format, ...) UE_LOG(LogCategory, VerbosityLevel, TEXT("%s: %s"), *FString(__FILE__), *FString::Printf(Format, ##__VA_ARGS__ ))

#define GDTUI_LOG(LogCategory, VerbosityLevel, Format, ...) UE_LOG(LogCategory, VerbosityLevel, TEXT("%s %s (%d): %s"), *FString(__FILE__), *FString(__FUNCTION__), __LINE__, *FString::Printf(Format, ##__VA_ARGS__ ) )
