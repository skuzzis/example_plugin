#if defined _example_plugin_inc
	#endinput
#endif

#define _example_plugin_inc

#define LOG_NONE                    0x00000000
#define LOG_ERROR                   0x00000500
#define LOG_WARNING                 0x08000000
#define LOG_DEBUG                   0x00000001

native test_native();
native SetLogLevel(loglevel = LOG_ERROR | LOG_WARNING);