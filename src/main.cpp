/**************************************
*  Main Source Code File
***************************************/

#include <amx/amx.h>
#include <plugincommon.h>

#include "common/common.hpp"
#include "natives/natives.hpp"

logprintf_t logprintf;

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports() 
{
	return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void** ppData) 
{
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
	logprintf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];
	return true;

}

extern "C" const AMX_NATIVE_INFO natives_listing[] = {
	{ "test_native", Natives::test_native },
	{ "SetLogLevel", Natives::SetLogLevel },
	{ NULL, NULL }
};

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX* amx) 
{
	return amx_Register(amx, natives_listing, (int)arraysize(natives_listing));
}

PLUGIN_EXPORT int PLUGIN_CALL Unload()
{
	return 1;
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX* amx)
{
	return 1;
}