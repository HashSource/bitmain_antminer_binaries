
undefined4 gpio_reg_callback(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  
  local_14 = param_1;
  if (param_2 == 0) {
    printf("%s:%d","gpio_reg_callback",0x78);
    puts("bad param");
    uVar2 = 0xffffffff;
  }
  else {
    iVar1 = pthread_mutex_lock((pthread_mutex_t *)gpio_ctrl_map);
    if (iVar1 == 0) {
      iVar1 = exists_c_map(gpio_ctrl_map._24_4_,&local_14);
      if (iVar1 == 0) {
        printf("%s:%d","gpio_reg_callback",0x81);
        printf("add %d to callback map\n",local_14);
        local_c = 0xffffffff;
        local_10 = param_2;
        insert_c_map(gpio_ctrl_map._24_4_,&local_14,4,&local_10,8);
      }
      else {
        printf("%s:%d","gpio_reg_callback",0x85);
        printf("port %d already exist in callback map \n",local_14);
      }
      pthread_mutex_unlock((pthread_mutex_t *)gpio_ctrl_map);
      uVar2 = 0;
    }
    else {
      printf("%s:%d","gpio_reg_callback",0x7c);
      puts("fail to lock gpio ctrl mutex");
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

