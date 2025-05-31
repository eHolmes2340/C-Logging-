#include "../include/Log.h"


void main()
{
	//Optional: 

	//True: want a log file 
	//False: don't want a log file. If function not called then default to false. 
	//Log::WantsLogFile(true);


	//If no name is entered then log file name defaults to "AppLog.log"
	Log::SetFileName("GameLog.log");


	//Key Functions 
	// How to call the log level function to write logs using the Log class. 

	Log::SetLogLevel(Log::LogLevelInfo);
	Log::Info("Info message here in green");


	Log::SetLogLevel(Log::LogLevelWarning);
	Log::Warning("Warning message here in yellow");


	Log::SetLogLevel(Log::LogLevelError);
	Log::Error("Info message here in red");

	Log::SetLogLevel(Log::LogLevelDebug); 
	Log::Debug("Debug message here"); 


	std::cout << "\n";



	std::cout << "Using Macros" << std::endl; 

	//Using the Macros
	LOG_INFO("This is a info message using the macro");
	LOG_WARNING("This is a warning message using the macro");
	LOG_ERROR("This is a error message using the macro");
	LOG_DEBUG("This is a debug message using the macro");




}