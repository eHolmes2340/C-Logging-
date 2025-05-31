#pragma once


#include "Common.h"

//To use Log class use must define a Macro called Debug or uncomment this one. 

class Log
{
public:
    enum LogLevel : unsigned char
    {
        LogLevelError = 0,
        LogLevelWarning = 1,
        LogLevelInfo = 2,
        LogLevelDebug=3
    };

private:
    static LogLevel m_LogLevel;
    static std::string fileName;
    static std::mutex m_Mutex;
    static std::ofstream m_LogFile;
    static bool m_wantLogFile;

    static void WriteMessageToFile(const std::string& message);
    static void SetConsoleTextColor(WORD attributes);

public:
    static std::string GetTimeStamp();
    static std::string SetFileName(const std::string& setFileNameVar);
    static void SetLogLevel(LogLevel level);

    static void Error(const char* message);
    static void Warning(const char* message);
    static void Info(const char* message);
    static void Debug(const char* message); 
    



    static void WantsLogFile(bool ans);
};



//Macros 
#define LOG_INFO(message)   \
    Log::SetLogLevel(Log::LogLevelInfo); \
    Log::Info(message)

#define LOG_WARNING(message) \
    Log::SetLogLevel(Log::LogLevelWarning); \
    Log::Warning(message)

#define LOG_ERROR(message)  \
    Log::SetLogLevel(Log::LogLevelError); \
    Log::Error(message)


#define LOG_DEBUG(message)  \
    Log::SetLogLevel(Log::LogLevelDebug); \
    Log::Debug(message)



