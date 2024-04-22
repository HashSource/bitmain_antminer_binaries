
undefined4 ui_init(void)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  
  if (ui_inited == 0) {
    iVar1 = gpio_init();
    if (iVar1 == 0) {
      uVar2 = convert_ui_type_to_port(1);
      gpio_export(uVar2);
      uVar2 = convert_ui_type_to_port(2);
      gpio_export(uVar2);
      uVar2 = convert_ui_type_to_port(0x100);
      gpio_export(uVar2);
      uVar2 = convert_ui_type_to_port(0x101);
      gpio_export(uVar2);
      uVar2 = convert_ui_type_to_port(0x100);
      gpio_reg_callback(uVar2,0x1fa51);
      uVar2 = convert_ui_type_to_port(0x101);
      gpio_reg_callback(uVar2,0x1fa51);
      pthread_mutex_init((pthread_mutex_t *)&ui_api_mutex,(pthread_mutexattr_t *)0x0);
      for (local_c = 0; local_c < 5; local_c = local_c + 1) {
        *(undefined4 *)(ui_callback + local_c * 4) = 0;
      }
      ui_flicker_map = new_c_map(0x1f991,0,0);
      ui_pull_thread = 1;
      pthread_create(&ui_thread,(pthread_attr_t *)0x0,ui_pull_function + 1,(void *)0x0);
      ui_inited = 1;
      uVar2 = 0;
    }
    else {
      printf("%s:%d","ui_init",0x7c);
      puts("gpio init failed");
      uVar2 = 0xffffffff;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

