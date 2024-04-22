
undefined4 add_reg_item(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int local_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  pthread_mutex_lock((pthread_mutex_t *)reg_scan_mutex);
  local_18 = 0;
  do {
    if (99 < local_18) {
LAB_000182a4:
      pthread_mutex_unlock((pthread_mutex_t *)reg_scan_mutex);
      return local_14;
    }
    if (*(int *)(&DAT_000312a0 + local_18 * 0xc) < 1) {
      local_18 = local_18 * 0xc;
      *(uint *)(&reg_scan_items + local_18) = param_1;
      *(undefined4 *)(&DAT_0003129c + local_18) = param_2;
      *(undefined4 *)(&DAT_000312a0 + local_18) = param_3;
      printf("ADD: chainid=%02x chipaddr=%02x regaddr=%02x regdata=%08x age=%d\n",param_1 & 0xff,
             param_1 >> 8 & 0xff,param_1 >> 0x10 & 0xff,param_2,param_3);
      local_14 = 1;
      goto LAB_000182a4;
    }
    local_18 = local_18 + 1;
  } while( true );
}

