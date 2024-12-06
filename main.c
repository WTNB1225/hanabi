#include "hanabi.h"

int main(void)
{
    Hanabi hanabi;
    Hanabi hanabi2;
    Hanabi hanabi3;
    while (1)
    {
      constructor(&hanabi, "0*+");
      constructor(&hanabi2, "+-*");
      constructor(&hanabi3, "Q0o");
      launch(&hanabi, 1);
      launch(&hanabi2, 0);
      launch(&hanabi2, 0);
      launch(&hanabi2, 0);
      launch(&hanabi2, 0);
      launch(&hanabi2, 0);
      launch(&hanabi3, 0);
      launch(&hanabi3, 0);
      launch(&hanabi3, 0);
      launch(&hanabi3, 0);
      launch(&hanabi3, 0);
      launch(&hanabi3, 0);

    }

    return 0;
}
