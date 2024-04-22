
undefined4 gpio_unreg_callback(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_c;
  
  local_c = param_1;
  if (param_2 == 0) {
    printf("%s:%d","gpio_unreg_callback",0x94);
    puts("bad param");
    uVar2 = 0xffffffff;
  }
  else {
    iVar1 = pthread_mutex_lock((pthread_mutex_t *)gpio_ctrl_map);
    if (iVar1 == 0) {
      iVar1 = exists_c_map(gpio_ctrl_map._24_4_,&local_c);
      if (iVar1 == 1) {
        printf("%s:%d","gpio_unreg_callback",0x9d);
        printf("remove %d from callback list\n",local_c);
        remove_c_map(gpio_ctrl_map._24_4_,&local_c);
      }
      else {
        printf("%s:%d","gpio_unreg_callback",0xa0);
        puts("callback function not registered before");
      }
      pthread_mutex_unlock((pthread_mutex_t *)gpio_ctrl_map);
      uVar2 = 0;
    }
    else {
      printf("%s:%d","gpio_unreg_callback",0x98);
      puts("fail to lock gpio ctrl mutex");
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

