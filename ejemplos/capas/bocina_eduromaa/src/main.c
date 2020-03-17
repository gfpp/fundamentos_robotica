/*==================[inclusiones]=============================================*/
#include "sapi.h"
#include "bocina.h"

/*==================[definiciones]===========================================*/

/*==================[implementaciones]=======================================*/
int main(void)
{
  uint8_t i;

  /* Inicializa EduCIAA */
  boardConfig();

  /* Inicializa Bocina */
  iniBocina();

  for(i = 0; i < 5; i++)
  {
    prenderBocina();
    delay(100);
    apagarBocina();
    delay(100);
  }

  for(;;);
  return 0;
}

