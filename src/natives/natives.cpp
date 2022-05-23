/**************************************
*  Natives Source Code File
***************************************/

#include "natives.hpp"
#include "../utilities/utilities.hpp"

cell Natives::test_native(AMX* amx, cell* params) 
{
	logprintf("Test Native");
	return 1;
}

cell Natives::SetLogLevel(AMX* amx, cell* params) 
{
	Utilities::prepareLogging(Utilities::GetInteger(amx, params, 1));
	return 1;
}