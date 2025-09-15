
undefined4 uart_set_config(int param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  undefined4 local_c;
  
  local_c = 0xfffffffb;
  if (param_3 == (undefined4 *)0x0) {
    local_c = 0xfffffffd;
  }
  else {
    pthread_mutex_lock((pthread_mutex_t *)(&uart_send_mutex + param_1 * 0x18));
    if (param_2 == 0) {
      if (platform_is_t9 == 0) {
        local_c = fpga_write(v9_fpga_map._56_4_,*param_3);
      }
      else {
        local_c = fpga_write(DAT_00035588,*param_3);
      }
    }
    else {
      printf("%s:%d","uart_set_config",0x2e0,param_2,param_4);
      printf("unknown set config type = %d\n",param_2);
    }
    pthread_mutex_unlock((pthread_mutex_t *)(&uart_send_mutex + param_1 * 0x18));
  }
  return local_c;
}

