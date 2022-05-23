/**************************************
*  Natives Header File
***************************************/

#ifndef _natives_h

#define _natives_h

#include <string>
#include <amx/amx2.h>
#include "../../src/common/common.hpp"

namespace Natives {
	cell test_native(AMX* amx, cell* params);

	cell SetLogLevel(AMX* amx, cell* params);
}

#endif