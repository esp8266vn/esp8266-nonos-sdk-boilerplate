
#include "osapi.h"
#include "user_interface.h"

void ICACHE_FLASH_ATTR print_info()
{
  uart_div_modify(0, UART_CLK_FREQ / 115200);
  os_printf("\r\n\r\n[INFO] BOOTUP...\r\n");
  os_printf("[INFO] SDK: %s\r\n", system_get_sdk_version());
  os_printf("[INFO] Chip ID: %08X\r\n", system_get_chip_id());
  os_printf("[INFO] Memory info:\r\n");
  system_print_meminfo();

  os_printf("[INFO] -------------------------------------------\n");
  os_printf("[INFO] Build time: %s\n", BUID_TIME);
  os_printf("[INFO] -------------------------------------------\n");

}


void ICACHE_FLASH_ATTR app_init()
{


  print_info();


  wifi_set_opmode_current(STATION_MODE);

}

void ICACHE_FLASH_ATTR user_init(void)
{
  system_init_done_cb(app_init);

}
