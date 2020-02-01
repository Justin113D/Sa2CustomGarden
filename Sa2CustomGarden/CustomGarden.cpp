#include "pch.h"
#include "SA2ModLoader.h"
#include "IniFile.hpp"
#include "LandTableInfo.cpp"

extern "C"
{
	__declspec(dllexport) void Init(const char* path, const HelperFunctions& helperFunctions)
	{
		const IniFile* settings = new IniFile(std::string(path) + "\\config.ini");
		string gardenType = settings->getString("CustomGarden", "GardenType");
		int textureCount = settings->getInt("CustomGarden", "TextureCount");
		delete settings;

		if (gardenType == "") gardenType = "Neut";
		if (textureCount == 0)
		{
			if (gardenType == "Neut")
			{
				textureCount = 12;
			}
			else if (gardenType == "Hero")
			{
				textureCount = 37;
			}
			else if (gardenType == "Dark")
			{
				textureCount = 18;
			}
		}

		NJS_TEXNAME *texName = new NJS_TEXNAME[textureCount];
		NJS_TEXLIST texList = { texName, textureCount };

		
		LandTable* newTable = (new LandTableInfo(std::string(path) + "\\LandTable.sa2blvl"))->getlandtable();

		LPCSTR tableName = ("objLandTable" + gardenType).c_str();
		HMODULE hmodule = GetModuleHandle(__TEXT("Data_DLL_orig"));
		LandTable* oldland = (LandTable*)GetProcAddress(hmodule, tableName);
		newTable->TextureList = &texList;// oldland->TextureList;
		newTable->TextureName = oldland->TextureName;
		*oldland = *newTable;
		//oldland->TextureList = &texList;

		
	}

	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer };
}