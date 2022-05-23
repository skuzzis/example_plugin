/**************************************
*  Utilities Header File
***************************************/

#ifndef _utilities_h

#define _utilities_h

#include <string>
#include <amx/amx2.h>
#include "../../src/common/common.hpp"

#define LOG_NONE                    0x00000000
#define LOG_ERROR                   0x00000500
#define LOG_WARNING                 0x08000000
#define LOG_DEBUG                   0x00000001

namespace Utilities {

	std::string GetString(AMX* amx, cell* params, int offset);
	int GetInteger(AMX* amx, cell* params, int offset);
	float GetFloat(AMX* amx, cell* params, int offset);

	int GenerateDirectories(const char* location);
	void prepareLogging(int log_level);

	void WriteDebugLog(char* text);
	void WriteWarningLog(char* text);
	void WriteErrorLog(char* text);

	int RandomNumber(int max);
}

#endif