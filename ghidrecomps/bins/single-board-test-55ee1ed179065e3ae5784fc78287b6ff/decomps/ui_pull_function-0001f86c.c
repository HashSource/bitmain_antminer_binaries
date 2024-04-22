
undefined4 ui_pull_function(void)

{
  int iVar1;
  byte bVar2;
  bool bVar3;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  code *local_18;
  undefined4 *local_14;
  code **local_10;
  int local_c;
  
  while (ui_pull_thread != 0) {
    iVar1 = pthread_mutex_lock((pthread_mutex_t *)&ui_api_mutex);
    if (iVar1 == 0) {
      local_10 = (code **)new_iterator_c_map(ui_flicker_map);
      local_c = (**local_10)(local_10);
      while (local_c != 0) {
        local_14 = (undefined4 *)(*local_10[2])(local_c);
        local_18 = local_10[5];
        if (local_14[1] == 0) {
          gpio_write(*(undefined4 *)**(undefined4 **)(local_18 + 0x10),local_14[2] & 0xff);
          iVar1 = local_14[2];
          bVar3 = iVar1 == 1;
          if (bVar3) {
            iVar1 = 0;
          }
          bVar2 = (byte)iVar1;
          if (!bVar3) {
            bVar2 = 1;
          }
          local_14[2] = (uint)bVar2;
          local_14[1] = *local_14;
        }
        local_14[1] = local_14[1] - default_flicker_interval;
        local_14[1] = local_14[1];
        local_24 = *local_14;
        local_20 = local_14[1];
        local_1c = local_14[2];
        (*local_10[1])(local_10,&local_24,0xc);
        free(local_14);
        local_c = (**local_10)(local_10);
      }
      delete_iterator_c_map(local_10);
      pthread_mutex_unlock((pthread_mutex_t *)&ui_api_mutex);
    }
    usleep(default_flicker_interval * 1000);
  }
  return 0;
}

