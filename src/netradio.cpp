#include <unistd.h>
#include "playercore.h"

int main(int argc, char** argv)
{
    VLCPlayer player;

    player.play("http://46.232.185.98:8000/hitradion1");

    sleep(10);

    return 0;
}
