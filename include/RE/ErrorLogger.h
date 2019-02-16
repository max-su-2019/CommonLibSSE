#pragma once

#include "RE/BSTEvent.h"  // BSTEventSource
#include "RE/BSTHashMap.h"  // BSTHashMap
#include "RE/LogEvent.h"  // LogEvent


namespace RE
{
	namespace BSScript
	{
		class ErrorLogger : public BSTEventSource<LogEvent>
		{
		public:
			virtual ~ErrorLogger();										// 00

			// add
			virtual const char*	FormatLog(const char* a_logEvent) = 0;	// 01
			virtual void		Unk_02(void);							// 02 - { return; }


			// members
			UInt64							unk60;	// 60
			BSTHashMap<UnkKey, UnkValue>	unk68;	// 68
		};
		STATIC_ASSERT(sizeof(ErrorLogger) == 0x98);
	}
}