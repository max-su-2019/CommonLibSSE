#include "RE/T/TESObjectARMO.h"
#include "RE/T/TESObjectARMA.h"

namespace RE
{
	float TESObjectARMO::GetArmorRating()
	{
		return static_cast<float>(armorRating) / static_cast<float>(100.0);
	}

	TESObjectARMA* TESObjectARMO::GetArmorAddonInSlot(BipedObjectSlot a_slot)
	{
		for (auto& addon : armorAddons) {
			if (addon && addon->GetSlotMask().all(a_slot))
				return addon;
		}

		return nullptr;
	}

	void TESObjectARMO::InitWornArmor(Actor* a_actor, BSTSmartPointer<BipedAnim>* a_biped)
	{
		using func_t = decltype(&TESObjectARMO::InitWornArmor);
		static REL::Relocation<func_t> func{ REL::ID(24232) };
		return func(this, a_actor, a_biped);
	}
}
