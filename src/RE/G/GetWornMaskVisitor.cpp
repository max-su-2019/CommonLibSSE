#include "RE/G/GetWornMaskVisitor.h"
#include "RE/I/InventoryEntryData.h"
#include "RE/T/TESBoundObject.h"

namespace RE
{
	bool GetWornMaskVisitor::Visit(InventoryEntryData* a_entryData)
	{
		using func_t = decltype(&GetWornMaskVisitor::Visit);
		static REL::Relocation<func_t> func{ REL::ID(15991) };

		TESBoundObject* object = a_entryData->object;
		auto            armor = object ? object->As<RE::TESObjectARMO>() : nullptr;

		return func(this, a_entryData);
		/*
		if (armor) {
			
			auto slot = DynamicArmorManager::GetSingleton()->GetBipedObjectSlots(actor, armor);
			slotMask |= slot;
			return 1;
			
		} else {
			return func(this, a_entryData);
		}
		*/
	}
}
