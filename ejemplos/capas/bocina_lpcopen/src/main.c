#include "chip.h"

/*==================[macros and definitions]=================================*/
#define SCU_PORT    7
#define SCU_PIN     4
#define GPIO_PORT   3
#define GPIO_PIN    12

/*==================[internal functions declaration]=========================*/
static void initHardware(void);
static void pausems(uint32_t t);

/*==================[internal data definition]===============================*/
static uint32_t pausems_count;

/*==================[internal functions definition]==========================*/
static void initHardware(void)
{
  SystemCoreClockUpdate();
  SysTick_Config(SystemCoreClock / 1000);

  /* Inicializa el módilo GPIO */
  Chip_GPIO_Init(LPC_GPIO_PORT);

  Chip_SCU_PinMux(SCU_PORT, SCU_PIN, SCU_MODE_INACT | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS, FUNC0);

  /* Establece la dirección del pin */
  Chip_GPIO_SetPinDIROutput(LPC_GPIO_PORT, GPIO_PORT, GPIO_PIN);

  /* Fija el estado inicial a LOW */
  Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, GPIO_PORT, GPIO_PIN);
}

static void pausems(uint32_t t)
{
  pausems_count = t;
  while(pausems_count != 0) 
  {
    __WFI();
  }
}

void SysTick_Handler(void)
{
  if(pausems_count > 0) pausems_count--;
}

/*=============================[ main ]======================================*/
int main(void)
{
  int i;
  initHardware();

  for(i = 0; i < 5; i++)
  {
    Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, GPIO_PORT, GPIO_PIN);
    pausems(100);
    Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, GPIO_PORT, GPIO_PIN);
    pausems(100);
  }

  for(;;);
  return 0;
}

