#pragma once

#define GDTUI_SHORT_LOG(LogCategory, VerbosityLevel, Format, ...) UE_LOG(LogCategory, VerbosityLevel, TEXT("%s: %s"), *FString(__FILE__), *FString::Printf(Format, ##__VA_ARGS__ ))

#define GDTUI_LOG(LogCategory, VerbosityLevel, Format, ...) UE_LOG(LogCategory, VerbosityLevel, TEXT("%s %s (%d): %s"), *FString(__FILE__), *FString(__FUNCTION__), __LINE__, *FString::Printf(Format, ##__VA_ARGS__ ) )

#define GDTUI_PRINT_TO_SCREEN_LOG(Format, ...) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString::Printf(Format, ##__VA_ARGS__))

#define GDTUI_PRINT_TO_SCREEN_WARN(Format, ...) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, FString::Printf(Format, ##__VA_ARGS__))

#define GDTUI_PRINT_TO_SCREEN_ERROR(Format, ...) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, FString::Printf(Format, ##__VA_ARGS__))