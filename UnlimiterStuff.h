int CarArraySize, CarCount, i;
bool AllNewCarsInitiallyUnlocked, AllNewCarsCanBeDrivenByAI, SortCarsByID, DisappearingWheelsFix, ExpandMemoryPools, AddOnOpponentsPartsFix, WorldCrashFixes;

#include "PresetCarSlot.h"

#define CarTypeInfoArray 0x734588

bool IsRacer(BYTE CarTypeID)
{
	if (CarTypeID >= CarCount) return 0;
	return *(BYTE*)((*(DWORD*)CarTypeInfoArray) + CarTypeID * 0xC90 + 0xC54) == 0;
}

unsigned int GetCarTypeNameHash(BYTE CarTypeID)
{
	if (CarTypeID >= CarCount) return 0;
	return *(DWORD*)((*(DWORD*)CarTypeInfoArray) + CarTypeID * 0xC90 + 0xD0);
}

void __declspec(naked) DoUnlimiterStuffCodeCave()
{
	// Get count
	_asm mov dword ptr ds : [CarTypeInfoArray] , edi;
	_asm sub edi, 0x0C;
	_asm mov edi, [edi];
	_asm mov CarArraySize, edi;
	_asm mov edi, dword ptr ds : [CarTypeInfoArray] ;
	_asm pushad;

	CarArraySize -= 8;
	CarCount = CarArraySize / 0xC90;
	if (CarCount > 127)
	{
		CarCount = 127;
		CarArraySize = CarCount * 0xC90;
	}
	// Do required stuff
	
	// Car Type Unlimiter
	injector::WriteMemory<int>(0x4397C4, CarArraySize, true); // sub_4394F0
	injector::WriteMemory<int>(0x4397E4, CarArraySize, true); // sub_4394F0
	injector::WriteMemory<int>(0x43B048, CarArraySize, true); // sub_43AF80
	injector::WriteMemory<int>(0x43B068, CarArraySize, true); // sub_43AF80
	injector::WriteMemory<int>(0x4AC519, CarArraySize, true); // FEPlayerCarDB::DefaultCustomizableCars
	injector::WriteMemory<int>(0x4C32C0, CarArraySize, true); // sub_4C3240
	injector::WriteMemory<int>(0x4C43B5, CarArraySize, true); // sub_4C42D0

	injector::WriteMemory<BYTE>(0x405421, CarCount, true); // sub_4053F0
	injector::WriteMemory<int>(0x439C7A, CarCount, true); // sub_439AA0
	injector::WriteMemory<BYTE>(0x4ABFF3, CarCount, true); // FEPlayerCarDB::FindCustomizableCarByType
	injector::WriteMemory<BYTE>(0x4AC5E1, CarCount, true); // FECarConfig::BuildRide
	injector::WriteMemory<BYTE>(0x4ACCFF, CarCount, true); // FECarConfig::GetCarType
	injector::WriteMemory<BYTE>(0x4B3944, CarCount, true); // sub_4B3940
	injector::WriteMemory<BYTE>(0x4BC1CD, CarCount, true); // QRCarSelectScreen::BuildSelectableCarList
	injector::WriteMemory<BYTE>(0x4BC3FD, CarCount, true); // QRCarSelectScreen::BuildSelectableCarList
	injector::WriteMemory<BYTE>(0x4BC51D, CarCount, true); // QRCarSelectScreen::BuildSelectableCarList
	injector::WriteMemory<BYTE>(0x4C673D, CarCount, true); // MainMenuCarCustomize::BuildSelectableCarList
	injector::WriteMemory<BYTE>(0x4C790A, CarCount, true); // UndergroundSamanthaGiveth::UndergroundSamanthaGiveth
	injector::WriteMemory<BYTE>(0x4C7AB7, CarCount, true); // UndergroundSamanthaGiveth::UndergroundSamanthaGiveth
	injector::WriteMemory<int>(0x4C78FE, CarCount, true); // UndergroundSamanthaGiveth::UndergroundSamanthaGiveth
	injector::WriteMemory<int>(0x4C7A57, CarCount, true); // UndergroundSamanthaGiveth::UndergroundSamanthaGiveth
	injector::WriteMemory<int>(0x4C7AAA, CarCount, true); // UndergroundSamanthaGiveth::UndergroundSamanthaGiveth
	injector::WriteMemory<BYTE>(0x4E0E0D, CarCount, true); // sub_4E0D90
	injector::WriteMemory<BYTE>(0x4E104D, CarCount, true); // sub_4E0D90
	injector::WriteMemory<BYTE>(0x4E1145, CarCount, true); // sub_4E0D90
	injector::WriteMemory<BYTE>(0x4E4908, CarCount, true); // sub_4E4840
	injector::WriteMemory<BYTE>(0x4E49EF, CarCount, true); // sub_4E4840
	injector::WriteMemory<BYTE>(0x504640, CarCount, true); // sub_504630
	injector::WriteMemory<BYTE>(0x50467E, CarCount, true); // sub_504630
	injector::WriteMemory<BYTE>(0x50736F, CarCount, true); // sub_507340
	injector::WriteMemory<BYTE>(0x507479, CarCount, true); // sub_507340
	injector::WriteMemory<BYTE>(0x50D372, CarCount, true); // sub_50D360
	injector::WriteMemory<BYTE>(0x510E84, CarCount, true); // GarageDecalsSlot::GarageDecalsSlot
	injector::WriteMemory<BYTE>(0x510EEC, CarCount, true); // GarageDecalsSlot::GarageDecalsSlot
	injector::WriteMemory<BYTE>(0x511F4E, CarCount, true); // sub_511F00
	injector::WriteMemory<BYTE>(0x57C8F3, CarCount, true); // LoaderCarInfo
	injector::WriteMemory<BYTE>(0x57CED4, CarCount, true); // sub_57CED0
	injector::WriteMemory<BYTE>(0x57CF8D, CarCount, true); // GetCarTypeInfo
	injector::WriteMemory<BYTE>(0x57CFA3, CarCount, true); // sub_57CFA0
	injector::WriteMemory<BYTE>(0x57CFF0, CarCount, true); // sub_57CFA0
	injector::WriteMemory<BYTE>(0x57D4BE, CarCount, true); // RideInfo::SetStockParts
	injector::WriteMemory<BYTE>(0x57D52A, CarCount, true); // RideInfo::SetStockParts
	injector::WriteMemory<BYTE>(0x57D59A, CarCount, true); // RideInfo::SetStockParts
	injector::WriteMemory<BYTE>(0x57D60A, CarCount, true); // RideInfo::SetStockParts
	injector::WriteMemory<BYTE>(0x57D67A, CarCount, true); // RideInfo::SetStockParts
	injector::WriteMemory<BYTE>(0x57D6EA, CarCount, true); // RideInfo::SetStockParts
	injector::WriteMemory<BYTE>(0x57D747, CarCount, true); // RideInfo::SetStockParts
	injector::WriteMemory<BYTE>(0x57EDAD, CarCount, true); // RideInfo::UpdatePartsEnabled
	injector::WriteMemory<BYTE>(0x57EE17, CarCount, true); // RideInfo::UpdatePartsEnabled
	injector::WriteMemory<BYTE>(0x57EE85, CarCount, true); // RideInfo::UpdatePartsEnabled
	injector::WriteMemory<BYTE>(0x57EEF4, CarCount, true); // RideInfo::UpdatePartsEnabled
	injector::WriteMemory<BYTE>(0x5A3D00, CarCount, true); // sub_5A3C00

	// Add new cars to the hashes table
	for (i = 0; i < CarCount; i++)
	{
		if (IsRacer(i) && HashesCount < 127)
		{
			hashes[HashesCount++] = GetCarTypeNameHash(i);
		}
	}

	// Relocate the hashes table
	injector::WriteMemory(0x4AC564, hashes, true); // sub_4AC550
	injector::WriteMemory(0x4AC6D1, hashes, true); // FECarConfig::BuildRide
	injector::WriteMemory(0x4AC7B3, hashes, true); // PresetCarSlot::FillWithRide
	injector::WriteMemory(0x4AC849, hashes, true); // sub_4AC820

	// Write its element count
	injector::WriteMemory<BYTE>(0x4AC56D, HashesCount, true); // sub_4AC550
	injector::WriteMemory<BYTE>(0x4AC7BC, HashesCount, true); // PresetCarSlot::FillWithRide

	// Continue
	_asm popad;
	_asm push 0x57C8CE;
	_asm retn;
}

int BogusCarPart;

void __declspec(naked) CrashWorkaroundCodeCave()
{
	_asm
	{
		mov ecx, dword ptr ds:[ecx+0x490]
		test ecx, ecx
		jz workaround

		usualthing:
			mov dword ptr ds: [BogusCarPart], ecx
			jmp caveexit

		workaround:
			mov ecx, dword ptr ds : [BogusCarPart]

		caveexit:
			push 0x56A36D
			retn
	}
}

void Init()
{
	CIniReader Settings("NFSUUnlimiterSettings.ini");

	// Main
	//AllNewCarsInitiallyUnlocked = Settings.ReadInteger("Main", "AllNewCarsInitiallyUnlocked", 0) == 1;
	//AllNewCarsCanBeDrivenByAI = Settings.ReadInteger("Main", "AllNewCarsCanBeDrivenByAI", 0) == 1;
	SortCarsByID = Settings.ReadInteger("Main", "SortCarsByID", 0) == 1;
	// Fixes
	DisappearingWheelsFix = Settings.ReadInteger("Fixes", "DisappearingWheelsFix", 1) == 1;
	//AddOnOpponentsPartsFix = Settings.ReadInteger("Fixes", "AddOnOpponentsPartsFix", 1) == 1;
	// Misc
	//ExpandMemoryPools = Settings.ReadInteger("Misc", "ExpandMemoryPools", 0) == 1;

	// Count Cars Automatically
	injector::MakeJMP(0x57C8C8, DoUnlimiterStuffCodeCave, true);

	// Crash Workaround
	injector::MakeJMP(0x56A367, CrashWorkaroundCodeCave, true);

	// Fix Invisible Wheels
	if (DisappearingWheelsFix)
	{
		injector::WriteMemory<unsigned char>(0x5696E4, 0x01, true);
	}

	// Sort the cars by their ID instead of special flags
	if (SortCarsByID)
	{
		injector::WriteMemory<unsigned char>(0x4C2BC0, 0xC3, true);
	}

}