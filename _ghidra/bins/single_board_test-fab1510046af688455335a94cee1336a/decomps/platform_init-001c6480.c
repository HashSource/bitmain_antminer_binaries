
/* WARNING: Unknown calling convention */

int32_t platform_init(void)

{
  bitmain_sys_capability_t *capa;
  int32_t iVar1;
  char tmp42 [2048];
  
  iVar1 = 0;
  if (platform_inited == 0) {
    iVar1 = fpga_init();
    if (iVar1 == 0) {
      iVar1 = gpio_init();
      if (iVar1 == 0) {
        capa = (bitmain_sys_capability_t *)memset(&capability,0,0x124);
        check_hotplug_realtime(capa);
        platform_inited = 1;
        fan_init();
        ui_init();
        uart_init();
        return 0;
      }
      iVar1 = -2;
      builtin_strncpy(tmp42,"gpio init failed",0x10);
      tmp42[0x10] = '\n';
      tmp42[0x11] = '\0';
      _applog(0,tmp42,false);
    }
    else {
      iVar1 = -1;
      builtin_strncpy(tmp42,"fpga init failed",0x10);
      tmp42[0x10] = '\n';
      tmp42[0x11] = '\0';
      _applog(0,tmp42,false);
    }
  }
  return iVar1;
}

