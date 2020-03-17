#include "sapi.h"

#define BOCINA_GPIO T_COL1

int main(void)
{
  uint8_t i;

  /* Inicializar la placa */
  boardConfig();

  gpioConfig(BOCINA_GPIO, GPIO_ENABLE);
  gpioConfig(BOCINA_GPIO, GPIO_OUTPUT);
  gpioWrite(BOCINA_GPIO, OFF);

  for(i = 0; i < 5; i++)
  {
    gpioWrite(BOCINA_GPIO, ON);
    delay(100);
    gpioWrite(BOCINA_GPIO, OFF);
    delay(100);
  }

  for(;;);
  return 0;
}
