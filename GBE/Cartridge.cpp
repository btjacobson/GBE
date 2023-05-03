#include "Cartridge.h"

Cartridge::Cartridge()
{

}

const char* Cartridge::CartridgeLicenseeName()
{
    if (header->newLicenseeCode <= 0xA4)
    {
        return LICENSEECODE[header->licenseeCode];
    }

    return "UNKNOWN";
}

const char* Cartridge::CartridgeTypeName()
{
    if (header->type <= 0x22)
    {
        return ROMTYPES[header->type];
    }

    return "UNKNOWN";
}

bool Cartridge::LoadCartridge(char* cartridge)
{
    snprintf(filename, sizeof(filename), "%s", cartridge);

    FILE* file = fopen(cartridge, "r");

    if (!file)
    {
        printf("Failed to open: %s\n", cartridge);

        return false;
    }

    printf("Opened: %s\n", filename);

    fseek(file, 0, SEEK_END);
    romSize = ftell(file);

    rewind(file);

    romData = (u8*)malloc(romSize);
    fread(romData, romSize, 1, file);
    fclose(file);

    header = (ROMHeader*)(romData + 0x100);
    header->title[15] = 0;

    printf("Cartridge Loaded:\n");
    printf("\t Title    : %s\n", header->title);
    printf("\t Type     : %2.2X (%s)\n", header->type, CartridgeTypeName());
    printf("\t ROM Size : %d KB\n", 32 << header->romSize);
    printf("\t RAM Size : %2.2X\n", header->ramSize);
    printf("\t LIC Code : %2.2X (%s)\n", header->licenseeCode, CartridgeLicenseeName());
    printf("\t ROM Vers : %2.2X\n", header->version);

    u16 x = 0;
    for (u16 i = 0x0134; i <= 0x014C; ++i)
    {
        x = x - romData[i] - 1;
    }

    printf("\t Checksum: %2.2X (%s)\n", header->checksum, (x & 0xFF) ? "PASSED" : "FAILED");

    return true;
}

u8 Cartridge::Read(u16 address)
{
    return romData[address];
}

void Cartridge::Write(u16 address, u8 value)
{
    // TODO: Implement
    NO_IMPL;
}
