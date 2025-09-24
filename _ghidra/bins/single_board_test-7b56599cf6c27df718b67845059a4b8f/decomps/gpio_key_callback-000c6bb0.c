
/* WARNING: Unknown calling convention */

void gpio_key_callback(uint32_t port,uint8_t val)

{
  ui_type_e uVar1;
  uint8_t val_00;
  uint8_t uVar2;
  _func_void_ui_type_e_bitmain_key_status_e **pp_Var3;
  _func_void_ui_type_e_bitmain_key_status_e **pp_Var4;
  
  uVar1 = convert_port_to_ui_type(port);
  if (uVar1 == UI_RESERVED) {
    gpio_key_callback(port,val_00);
    return;
  }
  pp_Var3 = ui_callback;
  do {
    pp_Var4 = pp_Var3 + 1;
    uVar2 = val;
    if (val != '\0') {
      uVar2 = '\x01';
    }
    if (*pp_Var3 != (_func_void_ui_type_e_bitmain_key_status_e *)0x0) {
      (**pp_Var3)(uVar1,(bitmain_key_status_e)uVar2);
    }
    pp_Var3 = pp_Var4;
  } while (pp_Var4 != (_func_void_ui_type_e_bitmain_key_status_e **)&ui_thread);
  return;
}

