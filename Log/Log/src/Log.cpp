
//File          : Log.cpp
//Programmer    : Erik Holmes
//Last Edited   : 2025-05-29
//Description   : This file contains all the class methods used by the Log Class found in the Log.h file


#include "../include/Log.h"

//Class defined
Log::LogLevel Log::m_LogLevel = Log::LogLevelInfo;
std::mutex Log::m_Mutex;
bool Log::m_wantLogFile = false;
std::string Log::fileName = "AppLog.log"; //Change Log file name here 
std::ofstream Log::m_LogFile;

/// <summary>
/// This class method will get a time stamp for our log message
/// </summary>
/// <returns> Time stamp </returns>
std::string Log::GetTimeStamp()
{
    const int sizeofTimeStampString = 26;

    static char buffer[sizeofTimeStampString];
    time_t now = time(nullptr);
    ctime_s(buffer, sizeof(buffer), &now);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline
    return std::string(buffer);
}

/// <summary>
/// This method will set the log level for our log message. 
/// </summary>
/// <param name="level"></param>
void Log::SetLogLevel(LogLevel level)
{
    m_LogLevel = level;
}

/// <summary>
/// This method will set the colour text for our log message. 
/// </summary>
/// <param name="attributes"></param>
void Log::SetConsoleTextColor(WORD attributes)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, attributes);
}

/// <summary>
/// This method will take in a message and write a error message to the console or a log file. 
/// </summary>
/// <param name="message"></param>
void Log::Error(const char* message)
{
    if (m_LogLevel >= LogLevelError)
    {
        std::lock_guard<std::mutex> lock(m_Mutex);
        SetConsoleTextColor(FOREGROUND_RED);
        std::string fullMessage = "[ERROR] " + GetTimeStamp() + ": " + message;
        std::cout << fullMessage << std::endl;
        if (m_wantLogFile) WriteMessageToFile(fullMessage);
        SetConsoleTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
}

/// <summary>
/// This method will take in a message and write a warning message to the console or a log file. 
/// </summary>
/// <param name="message"></param>
void Log::Warning(const char* message)
{
    if (m_LogLevel >= LogLevelWarning)
    {
        std::lock_guard<std::mutex> lock(m_Mutex);
        SetConsoleTextColor(FOREGROUND_RED | FOREGROUND_GREEN); // Yellow
        std::string fullMessage = "[WARNING] " + GetTimeStamp() + ": " + message;
        std::cout << fullMessage << std::endl;
        if (m_wantLogFile) WriteMessageToFile(fullMessage);
        SetConsoleTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
}

/// <summary>
/// This method will take in a message and write a info message to the console or a log file. 
/// </summary>
/// <param name="message"></param>
void Log::Info(const char* message)
{
    if (m_LogLevel >= LogLevelInfo)
    {
        std::lock_guard<std::mutex> lock(m_Mutex);
        SetConsoleTextColor(FOREGROUND_GREEN); // Green
        std::string fullMessage = "[INFO] " + GetTimeStamp() + ": " + message;
        std::cout << fullMessage << std::endl;
        if (m_wantLogFile) WriteMessageToFile(fullMessage);
        SetConsoleTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
}



/// <summary>
/// This method will take in a message and write a debug message to the console or log file 
/// </summary>
/// <param name="message"></param>
void Log::Debug(const char* message)
{
    std::lock_guard<std::mutex>lock(m_Mutex); 
    SetConsoleTextColor(FOREGROUND_BLUE);
    std::string fullMessage = "[DEBUG] " + GetTimeStamp() + ": " + message; 
    std::cout << fullMessage << std::endl;
    if (m_wantLogFile) WriteMessageToFile(fullMessage);
    SetConsoleTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}




/// <summary>
/// This method is tell class it wants a log file to be made called App.log. Found at the top of this source file. 
/// </summary>
/// <param name="ans"></param>
void Log::WantsLogFile(bool ans)
{
    std::lock_guard<std::mutex> lock(m_Mutex);
    m_wantLogFile = ans;

    if (ans)
    {
        m_LogFile.open(fileName, std::ios::app);
        if (!m_LogFile)
        {
            std::cerr << "[LOG ERROR] Failed to open log file: " << fileName << std::endl;
            m_wantLogFile = false;
        }
    }
    else
    {
        if (m_LogFile.is_open())
            m_LogFile.close();
    }
}

/// <summary>
///  This method will set the file name. 
/// </summary>
/// <param name="setFileNameVar"></param>
/// <returns>file name</returns>
std::string Log::SetFileName(const std::string& setFileNameVar)
{
    std::lock_guard<std::mutex> lock(m_Mutex);
    fileName = setFileNameVar;
    return fileName;
}

/// <summary>
/// This method will write a message to the App.log file. 
/// </summary>
/// <param name="message"></param>
void Log::WriteMessageToFile(const std::string& message)
{
    if (m_LogFile.is_open())
    {
        m_LogFile << message << std::endl;
    }
}
