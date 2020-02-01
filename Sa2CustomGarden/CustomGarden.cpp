#include "pch.h"
#include "SA2ModLoader.h"
#include "IniFile.hpp"
#include "LandTableInfo.cpp"

NJS_TEXNAME* texName;
NJS_TEXLIST texList;

extern "C"
{
	__declspec(dllexport) void Init(const char* path, const HelperFunctions& helperFunctions)
	{
		const IniFile* settings = new IniFile(std::string(path) + "\\config.ini");
		// GardenType is either
		// 1. "Neut"
		// 2. "Hero"
		// 3. "Dark"
		string gardenType = settings->getString("CustomGarden", "GardenType");
		// Texture count is per default 0
		Uint32 textureCount = settings->getInt("CustomGarden", "TextureCount");
		delete settings;

		// Default is "Neut", which means that it will be blank when not set
		if (gardenType == "") gardenType = "Neut";

		//if texture count is 0, set the texture count of the default texture file
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

		texName = new NJS_TEXNAME[textureCount];
		texList = { texName, textureCount };

		LandTable* newTable = (new LandTableInfo(std::string(path) + "\\LandTable.sa2blvl"))->getlandtable();

		LPCSTR tableName = ("objLandTable" + gardenType).c_str();
		HMODULE hmodule = GetModuleHandle(__TEXT("Data_DLL_orig"));
		LandTable* oldland = (LandTable*)GetProcAddress(hmodule, tableName);
		newTable->TextureList = &texList;// oldland->TextureList;
		newTable->TextureName = oldland->TextureName;
		*oldland = *newTable;

		
	}

	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer };
}