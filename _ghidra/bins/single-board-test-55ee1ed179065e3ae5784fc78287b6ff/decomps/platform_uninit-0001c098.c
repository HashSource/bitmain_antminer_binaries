
void platform_uninit(void)

{
  if (platform_inited != 0) {
    uart_uninit();
    fpga_uninit();
    fan_uninit();
    ui_uninit();
    gpio_uninit();
    platform_inited = 0;
  }
  return;
}

