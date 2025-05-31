# LogLib

Log lib is a lightweight C++ logging library that supports console output with coloured messages and optional log-to-file support. 

## Features
- Log levels: Info, Warning, Error
- Console color output (Windows)
- Optional file output
- Thread-safe


## Log Levels
- Info 
- Warning 
- Error 
- Debug 

## Usage
```cpp


Log::WantsLogFile(true);
Log::SetFileName("GameLog.log");
Log::SetLogLevel(Log::LogLevelInfo);
Log::Info("App started");
Log::Warning("Low memory");
Log::Error("Failed to load file");
Log::Debug("Debug Message); 
