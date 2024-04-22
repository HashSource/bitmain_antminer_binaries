
undefined4 lcd_show_result(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_c;
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&ui_api_mutex);
  if (iVar1 == 0) {
    if (lcd_ctx < 0) {
      lcd_ctx = lcd_init(lcd_path);
      lcd_clear(lcd_ctx);
    }
    if (lcd_ctx < 1) {
      printf("%s:%d","lcd_show_result",0x181);
      printf("failed to init %s\n",lcd_path);
      local_c = 0xffffffff;
    }
    else {
      local_c = lcd_write(lcd_ctx,param_1,param_2,param_3);
    }
    pthread_mutex_unlock((pthread_mutex_t *)&ui_api_mutex);
  }
  else {
    printf("%s:%d","lcd_show_result",0x177);
    puts("failed to api lock");
    local_c = 0xfffffffc;
  }
  return local_c;
}

