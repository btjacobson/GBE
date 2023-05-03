#ifndef CARTRIDGE_H
#define CARTRIDGE_H

#include "Common.h"


static const char* ROMTYPES[] =
{
    "ROM ONLY",
    "MBC1",
    "MBC1+RAM",
    "MBC1+RAM+BATTERY",
    "0x04 ???",
    "MBC2",
    "MBC2+BATTERY",
    "0x07 ???",
    "ROM+RAM 1",
    "ROM+RAM+BATTERY 1",
    "0x0A ???",
    "MMM01",
    "MMM01+RAM",
    "MMM01+RAM+BATTERY",
    "0x0E ???",
    "MBC3+TIMER+BATTERY",
    "MBC3+TIMER+RAM+BATTERY 2",
    "MBC3",
    "MBC3+RAM 2",
    "MBC3+RAM+BATTERY 2",
    "0x14 ???",
    "0x15 ???",
    "0x16 ???",
    "0x17 ???",
    "0x18 ???",
    "MBC5",
    "MBC5+RAM",
    "MBC5+RAM+BATTERY",
    "MBC5+RUMBLE",
    "MBC5+RUMBLE+RAM",
    "MBC5+RUMBLE+RAM+BATTERY",
    "0x1F ???",
    "MBC6",
    "0x21 ???",
    "MBC7+SENSOR+RUMBLE+RAM+BATTERY",
};

static const char* LICENSEECODE[0xA5] =
{
    "None",
    "Nintendo R&D1",
    "Capcom",
    "Electronic Arts",
    "Hudson Soft",
    "b-ai",
    "kss",
    "pow",
    "PCM Complete",
    "san-x",
    "Kemco Japan",
    "seta",
    "Viacom",
    "Nintendo",
    "Bandai",
    "Ocean/Acclaim",
    "Konami",
    "Hector",
    "Taito",
    "Hudson",
    "Banpresto",
    "Ubi Soft",
    "Atlus",
    "Malibu",
    "angel",
    "Bullet-Proof",
    "irem",
    "Absolute",
    "Acclaim",
    "Activision",
    "American sammy",
    "Konami",
    "Hi tech entertainment",
    "LJN",
    "Matchbox",
    "Mattel",
    "Milton Bradley",
    "Titus",
    "Virgin",
    "LucasArts",
    "Ocean",
    "Electronic Arts",
    "Infogrames",
    "Interplay",
    "Broderbund",
    "sculptured",
    "sci",
    "THQ",
    "Accolade",
    "misawa",
    "lozc",
    "Tokuma Shoten Intermedia",
    "Tsukuda Original",
    "Chunsoft",
    "Video system",
    "Ocean/Acclaim",
    "Varie",
    "Yonezawa/s’pal",
    "Kaneko",
    "Pack in soft",
    "Konami (Yu-Gi-Oh!)"
};

struct ROMHeader
{
	u8 entry[4];
	u8 logo[0x30];

	char title[16];
	u16 newLicenseeCode;
	u8 sgbFlag;
	u8 type;
	u8 romSize;
	u8 ramSize;
	u8 destCode;
	u8 licenseeCode;
	u8 version;
	u8 checksum;
	u16 globalChecksum;
};


class Cartridge
{
public:
    Cartridge();

    const char* CartridgeLicenseeName();
    const char* CartridgeTypeName();

	bool LoadCartridge(char* cartridge);	
    u8 Read(u16 address);

    void Write(u16 address, u8 value);

private:
	char filename[1024];
	u32 romSize;
	u8* romData;
	ROMHeader* header;
};

#endif
