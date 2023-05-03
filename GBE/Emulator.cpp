#include "Emulator.h"

#include <SDL.h>
#include <SDL_ttf.h>

#include <stdio.h>

#include "Cartridge.h"
#include "CPU.h"

Emulator* Emulator::instance = nullptr;

Emulator* Emulator::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new Emulator();
    }

    return instance;
}

int Emulator::Run(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("Usage: emulator <rom_file>\n");

        return -1;
    }

    if (!cartridge.LoadCartridge(argv[1]))
    {
        printf("Failed to load ROM file: %s\n", argv[1]);

        return -2;
    }

    printf("Cartridge loaded...\n");

    SDL_Init(SDL_INIT_VIDEO);
    printf("SDL INIT\n");
    TTF_Init();
    printf("TTF INIT\n");

    processor.Init();

    paused = false;
    running = true;
    ticks = 0;

    while (running)
    {
        if (paused)
        {
            Delay(10);

            continue;
        }

        if (!processor.Step())
        {
            printf("CPU Stopped\n");

            return -3;
        }

        ticks++;
    }

    return 0;
}

void Emulator::Delay(u32 ms)
{
    SDL_Delay(ms);
}
