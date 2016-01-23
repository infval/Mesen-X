#include "stdafx.h"
#include "MessageManager.h"
#include "MapperFactory.h"
#include "ROMLoader.h"
#include "AXROM.h"
#include "Bandai74161_7432.h"
#include "BnRom.h"
#include "BF909x.h"
#include "BF9096.h"
#include "CNROM.h"
#include "CpRom.h"
#include "ColorDreams.h"
#include "GxRom.h"
#include "IremG101.h"
#include "IremLrog017.h"
#include "IremTamS1.h"
#include "JalecoJf16.h"
#include "JalecoJf17_19.h"
#include "JalecoJfxx.h"
#include "JalecoSs88006.h"
#include "Mapper57.h"
#include "Mapper58.h"
#include "Mapper61.h"
#include "Mapper62.h"
#include "Mapper107.h"
#include "Mapper200.h"
#include "Mapper201.h"
#include "Mapper202.h"
#include "Mapper203.h"
#include "Mapper231.h"
#include "Mapper240.h"
#include "Mapper242.h"
#include "Mapper246.h"
#include "MMC1.h"
#include "MMC2.h"
#include "MMC3.h"
#include "MMC3_12.h"
#include "MMC3_37.h"
#include "MMC3_44.h"
#include "MMC3_47.h"
#include "MMC3_49.h"
#include "MMC3_52.h"
#include "MMC3_115.h"
#include "MMC3_189.h"
#include "MMC3_205.h"
#include "MMC3_ChrRam.h"
#include "MMC4.h"
#include "MMC5.h"
#include "Namco108.h"
#include "Namco108_76.h"
#include "Namco108_88.h"
#include "Namco108_95.h"
#include "Namco108_154.h"
#include "Nanjing.h"
#include "Nina01.h"
#include "Nina03_06.h"
#include "NROM.h"
#include "NtdecTc112.h"
#include "Sachen_145.h"
#include "Sachen_147.h"
#include "Sachen_148.h"
#include "Sachen_149.h"
#include "Sunsoft3.h"
#include "Sunsoft89.h"
#include "Sunsoft93.h"
#include "Sunsoft184.h"
#include "TaitoTc0190.h"
#include "TaitoX1005.h"
#include "UnlPci556.h"
#include "UNROM.h"
#include "UnRom_94.h"
#include "UnRom_180.h"
#include "VRC1.h"
#include "VRC2_4.h"
#include "VRC3.h"

BaseMapper* MapperFactory::GetMapperFromID(ROMLoader &romLoader)
{
#ifdef _DEBUG
	MessageManager::DisplayMessage("Game Info", "Mapper: " + std::to_string(romLoader.GetMapperID()));
#endif

	switch(romLoader.GetMapperID()) {
		case 0: return new NROM();
		case 1: return new MMC1();
		case 2: return new UNROM();
		case 3: return new CNROM(false);
		case 4: return new MMC3();
		case 5: return new MMC5();
		case 7: return new AXROM();
		case 9: return new MMC2();
		case 10: return new MMC4();
		case 11: return new ColorDreams();
		case 12: return new MMC3_12();
		case 13: return new CpRom();
		case 16: break; //18 games
		case 18: return new JalecoSs88006();
		case 19: break; //16 games
		case 21: return new VRC2_4(VRCVariant::VRC4a);  //Conflicts: VRC4c
		case 22: return new VRC2_4(VRCVariant::VRC2a);
		case 23: return new VRC2_4(VRCVariant::VRC2b);  //Conflicts: VRC4e
		case 25: return new VRC2_4(VRCVariant::VRC4b);  //Conflicts: VRC2c, VRC4d
		case 27: return new VRC2_4(VRCVariant::VRC4_27);  //Untested
		case 32: return new IremG101();
		case 33: return new TaitoTc0190();
		case 34: return (romLoader.GetChrSize() > 0) ? (BaseMapper*)new Nina01() : (BaseMapper*)new BnRom(); //BnROM uses CHR RAM (so no CHR rom in the .NES file)
		case 37: return new MMC3_37();
		case 38: return new UnlPci556();
		case 44: return new MMC3_44();
		case 47: return new MMC3_47();
		case 49: return new MMC3_49();
		case 52: return new MMC3_52();
		case 57: return new Mapper57();
		case 58: return new Mapper58();
		case 61: return new Mapper61();
		case 62: return new Mapper62();
		case 66: return new GxRom();
		case 67: return new SunSoft3();
		case 70: return new Bandai74161_7432(false);
		case 71: return new BF909x();
		case 72: return new JalecoJf17_19(false);
		case 73: return new VRC3();
		case 74: return new MMC3_ChrRam(0x08, 0x09, 2);
		case 75: return new VRC1();
		case 76: return new Namco108_76();
		case 77: return new IremLrog017();
		case 78: return new JalecoJf16(romLoader.GetSubMapper() == 3);
		case 79: return new Nina03_06(false);
		case 80: return new TaitoX1005();
		case 87: return new JalecoJfxx(false);
		case 88: return new Namco108_88();
		case 89: return new Sunsoft89();
		case 92: return new JalecoJf17_19(true);
		case 93: return new Sunsoft93();
		case 94: return new UnRom_94();
		case 95: return new Namco108_95();
		case 97: return new IremTamS1();
		case 101: return new JalecoJfxx(true);
		case 107: return new Mapper107();
		case 113: return new Nina03_06(true);
		case 115: return new MMC3_115();
		case 119: return new MMC3_ChrRam(0x40, 0x7F, 8);
		case 145: return new Sachen_145();
		case 146: return new Nina03_06(false);
		case 147: return new Sachen_147();
		case 148: return new Sachen_148();
		case 149: return new Sachen_149();
		case 152: return new Bandai74161_7432(true);
		case 154: return new Namco108_154();
		case 163: return new Nanjing();
		case 180: return new UnRom_180();
		case 184: return new Sunsoft184();
		case 185: return new CNROM(true);
		case 189: return new MMC3_189();
		case 191: return new MMC3_ChrRam(0x80, 0xFF, 2);
		case 192: return new MMC3_ChrRam(0x08, 0x0B, 4);
		case 193: return new NtdecTc112();
		case 194: return new MMC3_ChrRam(0x00, 0x01, 2);
		case 195: return new MMC3_ChrRam(0x00, 0x03, 4);
		case 200: return new Mapper200();
		case 201: return new Mapper201();
		case 202: return new Mapper202();
		case 203: return new Mapper203();
		case 205: return new MMC3_205();
		case 206: return new Namco108();
		case 231: return new Mapper231();
		case 232: return new BF9096();
		case 240: return new Mapper240();
		case 242: return new Mapper242();
		case 246: return new Mapper246();
	}

	MessageManager::DisplayMessage("Error", "Unsupported mapper, cannot load game.");
	return nullptr;
}

shared_ptr<BaseMapper> MapperFactory::InitializeFromFile(string romFilename, stringstream *filestream, string ipsFilename)
{
	ROMLoader loader;

	if(loader.LoadFile(romFilename, filestream, ipsFilename)) {
		shared_ptr<BaseMapper> mapper(GetMapperFromID(loader));

		if(mapper) {
			mapper->Initialize(loader);
			return mapper;
		}
	}
	return nullptr;
}

