#pragma once

#include "RE/B/BSTList.h"
#include "RE/F/FormTypes.h"
#include "RE/M/MemoryManager.h"

namespace RE
{
	class ExtraDataList;
	class InventoryEntryData;

	class InventoryChanges
	{
	public:
		struct ARMOR_SLOTS
		{
		public:
			enum class ArmorSlot : std::uint32_t
			{
				kHead = 30,
				kHair = 31,
				kBody = 32,
				kHands = 33,
				kForearms = 34,
				kAmulet = 35,
				kRing = 36,
				kFeet = 37,
				kCalves = 38,
				kShield = 39,
				kTail = 40,
				kLongHair = 41,
				kCirclet = 42,
				kEars = 43,
				kDecapitateHead = 50,
				kDecapitate = 51,
				kFX01 = 61
			};
		};
		using ArmorSlot = ARMOR_SLOTS::ArmorSlot;

		class IItemChangeVisitor
		{
		public:
			inline static constexpr auto RTTI = RE::RTTI_InventoryChanges__IItemChangeVisitor;

			virtual ~IItemChangeVisitor() = default;  // 00

			// add
			virtual bool Visit(RE::InventoryEntryData* a_entryData) = 0;  // 01

			virtual bool Unk_02(RE::FormType)  // 02
			{
				return true;
			}

			virtual void Unk_03(RE::InventoryEntryData* a_entryData, std::int64_t, bool& a_visited)  // 03
			{
				a_visited = true;
				Visit(a_entryData);
			}
		};
		static_assert(sizeof(IItemChangeVisitor) == 0x8);

		InventoryChanges();
		explicit InventoryChanges(TESObjectREFR* a_ref);
		~InventoryChanges();

		void           Accept(IItemChangeVisitor* a_visitor);
		void           AddEntryData(InventoryEntryData* a_entry);
		TESObjectARMO* GetArmorInSlot(ArmorSlot a_slot);
		std::uint16_t  GetNextUniqueID();
		void           InitFromContainerExtra();
		void           InitLeveledItems();
		void           InitScripts();
		void           SendContainerChangedEvent(ExtraDataList* a_itemExtraList, TESObjectREFR* a_fromRefr, TESForm* a_item, std::int32_t a_count);
		void           SetUniqueID(ExtraDataList* a_itemList, TESForm* a_oldForm, TESForm* a_newForm);

		TES_HEAP_REDEFINE_NEW();

		// members
		BSSimpleList<InventoryEntryData*>* entryList{ nullptr };  // 00
		TESObjectREFR*                     owner{ nullptr };      // 08
		float                              totalWeight{ 0.0F };   // 10
		float                              armorWeight{ 0.0F };   // 14
		bool                               changed{ false };      // 18
		std::uint8_t                       unk19{ 0 };            // 19
		std::uint8_t                       unk1A{ 0 };            // 1A
		std::uint8_t                       unk1B{ 0 };            // 1B
		std::uint32_t                      unk1C{ 0 };            // 1C

	private:
		InventoryChanges* Ctor(TESObjectREFR* a_ref);
		void              Dtor();
	};
	static_assert(sizeof(InventoryChanges) == 0x20);

}
