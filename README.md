# LogLib

Log lib is a lightweight C++ logging library that supports console output with colored messages and optional log-to-file support. 

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
To use logging lib you can build this project in release mode and use the static lib that is created.

Include Header file 
```cpp
#include "Log.h" 
```


```cpp


Log::WantsLogFile(true);
Log::SetFileName("GameLog.log");
Log::SetLogLevel(Log::LogLevelInfo);
Log::Info("App started");
Log::Warning("Low memory");
Log::Error("Failed to load file");
Log::Debug("Debug Message);


```

