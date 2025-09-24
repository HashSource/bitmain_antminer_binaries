
uint32_t convert_ui_type_to_port(ui_type_e type)

{
  int32_t iVar1;
  uint32_t uVar2;
  
  iVar1 = hal_led_red_addr();
  if (-1 < iVar1) {
    uVar2 = hal_led_red_addr();
    return uVar2;
  }
  return 0;
}

