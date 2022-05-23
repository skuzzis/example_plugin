/**************************************
*  Utilities Source Code File
***************************************/

#include <cstdarg>
#include <time.h>
#include <fstream>
#include <random>

#include "utilities.hpp"

int log_level = LOG_NONE;

std::string Utilities::GetString(AMX* amx, cell* params, int index) 
{
	return amx_GetCppString(amx, params[index]);
}

int Utilities::GetInteger(AMX* amx, cell* params, int offset) 
{
	if (offset == 1)
		return static_cast<int>(params[1]);

	cell* memory_addr = nullptr;
	
	amx_GetAddr(amx, params[offset], &memory_addr);
	int value = static_cast<int>(static_cast<cell>(*memory_addr));
	delete[] memory_addr;

	return value;
}

float Utilities::GetFloat(AMX* amx, cell* params, int offset) 
{
	cell* memory_addr = nullptr;

	amx_GetAddr(amx, params[offset], &memory_addr);
	float value = round(amx_ctof(*memory_addr) * 100) / 100;
	delete[] memory_addr;

	return value;
}

int Utilities::GenerateDirectories(const char* location)
{
	wchar_t* wc = new wchar_t[strlen(location) + 1];
	mbstowcs(wc, location, strlen(location) + 1);
	return _wmkdir(wc);
}

void Utilities::prepareLogging(int log_lvl) 
{
	char folder_path[64];
	if ((log_lvl & LOG_ERROR) == LOG_ERROR)
	{
		snprintf(folder_path, sizeof folder_path, "./logs/%s/error", PLUGIN_NAME);
		Utilities::GenerateDirectories(folder_path);
		log_level |= LOG_ERROR;
	}
	if ((log_lvl & LOG_WARNING) == LOG_WARNING)
	{
		snprintf(folder_path, sizeof folder_path, "./logs/%s/warning", PLUGIN_NAME);
		Utilities::GenerateDirectories(folder_path);
		log_level |= LOG_WARNING;
	}
	if ((log_lvl & LOG_DEBUG) == LOG_DEBUG)
	{
		snprintf(folder_path, sizeof folder_path, "./logs/%s/debug", PLUGIN_NAME);
		Utilities::GenerateDirectories(folder_path);
		log_level |= LOG_DEBUG;
	}
}

void Utilities::WriteDebugLog(char* text) 
{
	if ((log_level & LOG_DEBUG) == LOG_DEBUG)
	{
		time_t now = time(0);
		tm* ltm = localtime(&now);

		char logFileName[100];
		snprintf(logFileName, sizeof(logFileName), "./logs/%s/debug/%02d-%02d-%d.log", PLUGIN_NAME, ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900);
		std::ofstream DebugFile(logFileName, std::ios_base::app);
		char logDate[100];
		snprintf(logDate, sizeof(logDate), "[%02d/%02d/%d %02d:%02d:%02d]", ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900, ltm->tm_hour, ltm->tm_min, ltm->tm_sec);

		DebugFile << logDate << " " << std::string(text) << "\n";
		DebugFile.close();
	}
}

void Utilities::WriteWarningLog(char* text)
{
	if ((log_level & LOG_WARNING) == LOG_WARNING)
	{
		time_t now = time(0);
		tm* ltm = localtime(&now);

		char logFileName[100];
		snprintf(logFileName, sizeof(logFileName), "./logs/%s/warning/%02d-%02d-%d.log", PLUGIN_NAME, ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900);
		std::ofstream WarningFile(logFileName, std::ios_base::app);
		char logDate[100];
		snprintf(logDate, sizeof(logDate), "[%02d/%02d/%d %02d:%02d:%02d]", ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900, ltm->tm_hour, ltm->tm_min, ltm->tm_sec);

		WarningFile << logDate << " " << std::string(text) << "\n";
		WarningFile.close();
	}
}

void Utilities::WriteErrorLog(char* text)
{
	if ((log_level & LOG_ERROR) == LOG_ERROR)
	{
		time_t now = time(0);
		tm* ltm = localtime(&now);

		char logFileName[100];
		snprintf(logFileName, sizeof(logFileName), "./logs/%s/error/%02d-%02d-%d.log", PLUGIN_NAME, ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900);
		std::ofstream ErrorFile(logFileName, std::ios_base::app);
		char logDate[100];
		snprintf(logDate, sizeof(logDate), "[%02d/%02d/%d %02d:%02d:%02d]", ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900, ltm->tm_hour, ltm->tm_min, ltm->tm_sec);

		ErrorFile << logDate << " " << std::string(text) << "\n";
		ErrorFile.close();
	}
}

int Utilities::RandomNumber(int max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> ran(0, max);
	return ran(gen);
}