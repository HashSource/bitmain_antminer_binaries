
void gpio_key_callback(undefined4 param_1,char param_2)

{
  int iVar1;
  int local_c;
  
  iVar1 = convert_port_to_ui_type(param_1);
  if (iVar1 == 0x102) {
    printf("%s:%d","gpio_key_callback",0x6e);
    printf("gpio port %d is not a supported key\n",param_1);
  }
  else {
    for (local_c = 0; local_c < 5; local_c = local_c + 1) {
      if (*(int *)(ui_callback + local_c * 4) != 0) {
        (**(code **)(ui_callback + local_c * 4))(iVar1,param_2 != '\0');
      }
    }
  }
  return;
}

