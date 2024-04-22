
undefined4 gpio_thread_function(void)

{
  int iVar1;
  code *local_2c;
  uint local_28;
  byte local_21;
  undefined4 local_20;
  code **local_1c;
  code *local_18;
  code **local_14;
  int local_10;
  int local_c;
  
  local_10 = 0;
  do {
    if (gpio_thread == 0) {
      return 0;
    }
    iVar1 = pthread_mutex_lock((pthread_mutex_t *)gpio_ctrl_map);
    if (iVar1 == 0) {
      local_14 = (code **)new_iterator_c_map(gpio_ctrl_map._24_4_);
      local_c = (**local_14)(local_14);
      while (local_c != 0) {
        local_18 = local_14[5];
        local_1c = (code **)(*local_14[2])(local_c);
        local_20 = *(undefined4 *)**(undefined4 **)(local_18 + 0x10);
        local_21 = 0;
        local_10 = gpio_read(local_20,&local_21);
        if (local_10 != 0) {
          printf("%s:%d","gpio_thread_function",0x32);
          printf("failed to read gpio port %d\n",local_20);
          free(local_1c);
          break;
        }
        if (local_1c[1] != (code *)(uint)local_21) {
          printf("%s:%d","gpio_thread_function",0x37);
          printf("gpio port %d, last val = %d, new val = %d\n",
                 *(undefined4 *)**(undefined4 **)(local_18 + 0x10),local_1c[1],(uint)local_21);
          (**local_1c)(local_20,local_21);
          local_2c = *local_1c;
          local_28 = (uint)local_21;
          (*local_14[1])(local_14,&local_2c,8);
        }
        free(local_1c);
        local_c = (**local_14)(local_14);
      }
      delete_iterator_c_map(local_14);
      pthread_mutex_unlock((pthread_mutex_t *)gpio_ctrl_map);
    }
    usleep(default_pull_interval * 1000);
  } while( true );
}

