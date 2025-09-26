
/* WARNING: Unknown calling convention */

int32_t ui_init(void)

{
  ui_type_e in_r0;
  uint32_t uVar1;
  ui_type_e type;
  
  if (ui_inited == 0) {
    uVar1 = convert_ui_type_to_port(in_r0);
    type = gpio_export(uVar1);
    uVar1 = convert_ui_type_to_port(type);
    gpio_direction(uVar1,DIRECTION_OUT);
    uVar1 = convert_ui_type_to_port(GREEN_LED);
    gpio_export(uVar1);
    uVar1 = convert_ui_type_to_port(GREEN_LED);
    gpio_direction(uVar1,DIRECTION_OUT);
    uVar1 = convert_ui_type_to_port(RESET_KEY);
    gpio_export(uVar1);
    uVar1 = convert_ui_type_to_port(RESET_KEY);
    gpio_direction(uVar1,DIRECTION_IN);
    uVar1 = convert_ui_type_to_port(IP_REPORT_KEY);
    gpio_export(uVar1);
    uVar1 = convert_ui_type_to_port(IP_REPORT_KEY);
    gpio_direction(uVar1,DIRECTION_IN);
    ui_inited = 1;
  }
  return 0;
}

