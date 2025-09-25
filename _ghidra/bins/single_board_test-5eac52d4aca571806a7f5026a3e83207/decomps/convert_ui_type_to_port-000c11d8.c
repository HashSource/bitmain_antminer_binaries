
/* WARNING: Unknown calling convention */

uint32_t convert_ui_type_to_port(ui_type_e type)

{
  int32_t iVar1;
  uint32_t uVar2;
  
  if (type == GREEN_LED) {
    iVar1 = hal_led_green_addr();
    if (-1 < iVar1) {
      uVar2 = hal_led_green_addr();
      return uVar2;
    }
  }
  else if (type < (GREEN_LED|RED_LED)) {
    if (type == RED_LED) {
      uVar2 = convert_ui_type_to_port(RED_LED);
      return uVar2;
    }
  }
  else if (type == RESET_KEY) {
    iVar1 = hal_key_reset_addr();
    if (-1 < iVar1) {
      uVar2 = hal_key_reset_addr();
      return uVar2;
    }
  }
  else if ((type == IP_REPORT_KEY) && (iVar1 = hal_key_ipreport_addr(), -1 < iVar1)) {
    uVar2 = hal_key_ipreport_addr();
    return uVar2;
  }
  return 0;
}

