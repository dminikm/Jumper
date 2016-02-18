#include "Headers/Main.h"
#include "Headers/Game.h"

int main(int argc, char* argv[])
{
    CGame* mainGame = new CGame();
    mainGame->Init("Jumper", 0x1FFF0000, 0x1FFF0000, 480, 360);
    mainGame->Run();
    return 0;
}
