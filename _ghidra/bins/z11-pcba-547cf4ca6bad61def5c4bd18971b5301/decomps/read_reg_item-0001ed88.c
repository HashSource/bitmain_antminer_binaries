
undefined4 read_reg_item(char *param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  int extraout_r1;
  int local_18;
  int local_14;
  
  iVar2 = __aeabi_idiv(param_2,0x32);
  __aeabi_idivmod(param_2,0x32);
  local_14 = extraout_r1 + iVar2;
  do {
    usleep(50000);
    pthread_mutex_lock((pthread_mutex_t *)reg_scan_mutex);
    for (local_18 = 0; local_18 < 100; local_18 = local_18 + 1) {
      if (((((&reg_scan_items)[local_18 * 0xc] == *param_1) &&
           ((&DAT_00047969)[local_18 * 0xc] == param_1[1])) &&
          ((&DAT_0004796a)[local_18 * 0xc] == param_1[2])) &&
         (-1 < *(int *)(&DAT_00047970 + local_18 * 0xc))) {
        *(undefined4 *)(param_1 + 4) = *(undefined4 *)(&DAT_0004796c + local_18 * 0xc);
        *(undefined4 *)(&DAT_00047970 + local_18 * 0xc) = 0xffffffff;
        pthread_mutex_unlock((pthread_mutex_t *)reg_scan_mutex);
        return 1;
      }
    }
    pthread_mutex_unlock((pthread_mutex_t *)reg_scan_mutex);
    bVar1 = local_14 < 1;
    local_14 = local_14 + -1;
    if (bVar1) {
      return 0xffffffff;
    }
  } while( true );
}

