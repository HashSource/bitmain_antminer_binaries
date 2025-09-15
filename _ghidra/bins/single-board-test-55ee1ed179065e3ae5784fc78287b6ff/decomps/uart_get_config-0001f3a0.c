
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 uart_get_config(int param_1,int param_2,undefined4 *param_3,int param_4)

{
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 0xfffffffb;
  if ((param_3 == (undefined4 *)0x0) || (param_4 != 0)) {
    local_c = 0xfffffffd;
  }
  else {
    pthread_mutex_lock((pthread_mutex_t *)(&uart_send_mutex + param_1 * 0x18));
    if (param_2 == 0) {
      if (platform_is_t9 == 0) {
        local_14 = 0;
        local_c = fpga_read(v9_fpga_map._56_4_,&local_14);
        *param_3 = local_14;
      }
      else {
        local_10 = 0;
        local_c = fpga_read(DAT_00035588,&local_10);
        *param_3 = local_10;
      }
      _shift = 4;
      printf("%s:%d","uart_get_config",0x2fc);
      printf("uart_get_config return %d\n",*param_3);
    }
    else {
      printf("%s:%d","uart_get_config",0x2ff);
      printf("unknown set config type = %d\n",param_2);
    }
    pthread_mutex_unlock((pthread_mutex_t *)(&uart_send_mutex + param_1 * 0x18));
  }
  return local_c;
}

