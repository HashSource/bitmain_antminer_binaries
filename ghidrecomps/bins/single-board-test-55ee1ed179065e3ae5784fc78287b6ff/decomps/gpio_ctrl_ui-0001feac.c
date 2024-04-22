
undefined4 gpio_ctrl_ui(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  iVar1 = convert_ui_type_to_port(param_1);
  if (iVar1 == 0) {
    printf("%s:%d","gpio_ctrl_ui",0xde);
    puts("unsuported gpio port");
    local_c = 0xffffffff;
  }
  else {
    printf("%s:%d","gpio_ctrl_ui",0xe1);
    printf("ui type = %d, port = %d, status = %d\n",param_1,iVar1,param_2);
    iVar2 = pthread_mutex_lock((pthread_mutex_t *)&ui_api_mutex);
    if (iVar2 == 0) {
      if (param_2 == 1) {
        remove_port_form_gpio_map(iVar1,ui_flicker_map);
        local_c = gpio_write(iVar1,0);
      }
      else if (param_2 == 0) {
        remove_port_form_gpio_map(iVar1,ui_flicker_map);
        local_c = gpio_write(iVar1,1);
      }
      else if (param_2 == 2) {
        add_port_to_gpio_map(iVar1,default_flicker_interval,ui_flicker_map);
      }
      else {
        printf("%s:%d","gpio_ctrl_ui",0xf3);
        puts("unsuported led status");
        local_c = 0xfffffffe;
      }
      pthread_mutex_unlock((pthread_mutex_t *)&ui_api_mutex);
    }
    else {
      printf("%s:%d","gpio_ctrl_ui",0xe3);
      puts("failed to api lock");
      local_c = 0xffffffff;
    }
  }
  return local_c;
}

