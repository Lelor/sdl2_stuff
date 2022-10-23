#pragma once
#include <iostream>


enum LogLevel
{ DEBUG=0, INFO=1, WARN=2, ERROR=3 };


class Log
{
private:
	LogLevel m_logLevel;
public:
	Log(LogLevel level)
		:m_logLevel(level)
	{};

	void setLevel(LogLevel level)
	{
		m_logLevel = level;
	}

	template<typename T>
	void Debug(T& log) const
	{
		if (m_logLevel >= LogLevel::DEBUG)
			std::cout << "[DEBUG] - " << log << std::endl;
	}

	template<typename T>
	void Info(T& log) const
	{
		if (m_logLevel >= LogLevel::INFO)
			std::cout << "[INFO] - " << log << std::endl;
	}

	template<typename T>
	void Warn(T& log) const
	{
		if (m_logLevel >= LogLevel::WARN)
			std::cout << "[WARN] - " << log << std::endl;
	}

	template<typename T>
	void Error(T& log) const
	{
		if (m_logLevel == LogLevel::ERROR)
			std::cout << "[ERROR] - " << log << std::endl;
	}
};

extern Log logger;
