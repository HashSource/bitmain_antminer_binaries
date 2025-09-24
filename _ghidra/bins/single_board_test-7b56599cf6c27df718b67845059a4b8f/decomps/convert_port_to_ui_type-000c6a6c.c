
/* WARNING: Unknown calling convention */

uint32_t convert_port_to_ui_type(uint32_t port)

{
  uint32_t uVar1;
  char tmp42 [2048];
  
  uVar1 = hal_key_reset_addr();
  if (uVar1 == port) {
    uVar1 = 0x100;
  }
  else {
    uVar1 = hal_key_ipreport_addr();
    if (port == uVar1) {
      uVar1 = 0x101;
    }
    else {
      snprintf(tmp42,0x800,"unmaped port = %d\n",port);
      _applog(0,tmp42,false);
      uVar1 = 0x103;
    }
  }
  return uVar1;
}

