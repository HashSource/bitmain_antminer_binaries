
undefined4 read_reg_item(char *param_1)

{
  int local_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  pthread_mutex_lock((pthread_mutex_t *)reg_scan_mutex);
  local_10 = 0;
  do {
    if (99 < local_10) {
LAB_0001839c:
      pthread_mutex_unlock((pthread_mutex_t *)reg_scan_mutex);
      return local_c;
    }
    if (((((&reg_scan_items)[local_10 * 0xc] == *param_1) &&
         ((&DAT_00031299)[local_10 * 0xc] == param_1[1])) &&
        ((&DAT_0003129a)[local_10 * 0xc] == param_1[2])) &&
       (-1 < *(int *)(&DAT_000312a0 + local_10 * 0xc))) {
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(&DAT_0003129c + local_10 * 0xc);
      *(undefined4 *)(&DAT_000312a0 + local_10 * 0xc) = 0xffffffff;
      local_c = 1;
      goto LAB_0001839c;
    }
    local_10 = local_10 + 1;
  } while( true );
}

