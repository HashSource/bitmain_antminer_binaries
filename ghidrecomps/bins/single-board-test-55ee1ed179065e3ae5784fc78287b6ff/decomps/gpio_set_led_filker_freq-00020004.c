
undefined4 gpio_set_led_filker_freq(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = convert_ui_type_to_port(param_1);
  if (iVar1 == 0) {
    printf("%s:%d","gpio_set_led_filker_freq",0x106);
    puts("unsuported led port");
    uVar2 = 0xffffffff;
  }
  else if (param_2 == default_flicker_interval) {
    printf("%s:%d","gpio_set_led_filker_freq",0x10a);
    puts("interval is same with default");
    uVar2 = 0;
  }
  else {
    update_filcker_freq(iVar1,param_2,ui_flicker_map);
    uVar2 = 0;
  }
  return uVar2;
}

