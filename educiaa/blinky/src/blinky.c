#include "sapi.h"

int main(void)
{
  /* ------------- INICIALIZACIONES ------------- */

  /* Inicializar la placa */
  boardConfig();

  /* ------------- REPETIR POR SIEMPRE ------------- */
  while(1) 
  {
    /* Prendo el led azul */
    gpioWrite( LEDB, ON );
    delay(500);

    /* Apago el led azul */
    gpioWrite( LEDB, OFF );
    delay(500);
  }

  return 0 ;
}
