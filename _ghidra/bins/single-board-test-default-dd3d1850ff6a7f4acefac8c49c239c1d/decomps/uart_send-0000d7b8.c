
uint uart_send(byte param_1,void *param_2,uint param_3)

{
  int iVar1;
  byte abStack_238 [512];
  uint local_38;
  uint local_34;
  undefined4 local_30;
  uint local_2c;
  undefined4 local_28;
  uint local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  int local_10;
  int local_c;
  
  local_28 = 0;
  local_c = 0;
  local_2c = 0;
  local_10 = 0;
  local_30 = 0;
  memset(abStack_238,0,0x200);
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  local_20 = 0;
  local_38 = 0;
  local_24 = 0;
  local_34 = param_3;
  pthread_mutex_lock((pthread_mutex_t *)(&uart_send_mutex + (uint)param_1 * 0x18));
  switch(param_1) {
  case 0:
    local_24 = 0x18;
    local_18 = 0x400;
    local_1c = 0x404;
    local_20 = 0x405;
    break;
  case 1:
    local_24 = 0x10;
    local_18 = 0x400;
    local_1c = 0x406;
    local_20 = 0x407;
    break;
  case 2:
    local_24 = 8;
    local_18 = 0x400;
    local_1c = 0x408;
    local_20 = 0x409;
    break;
  case 3:
    local_24 = 0;
    local_18 = 0x400;
    local_1c = 0x40a;
    local_20 = 0x40b;
    break;
  case 4:
    local_24 = 0x18;
    local_18 = 0x401;
    local_1c = 0x40c;
    local_20 = 0x40d;
    break;
  case 5:
    local_24 = 0x10;
    local_18 = 0x401;
    local_1c = 0x40e;
    local_20 = 0x40f;
    break;
  case 6:
    local_24 = 8;
    local_18 = 0x401;
    local_1c = 0x410;
    local_20 = 0x411;
    break;
  case 7:
    local_24 = 0;
    local_18 = 0x401;
    local_1c = 0x412;
    local_20 = 0x413;
    break;
  case 8:
    local_24 = 0x18;
    local_18 = 0x402;
    local_1c = 0x414;
    local_20 = 0x415;
    break;
  case 9:
    local_24 = 0x10;
    local_18 = 0x402;
    local_1c = 0x416;
    local_20 = 0x417;
    break;
  default:
    printf("%s: The uart%d is not supported!!!\n","uart_send");
    return 0;
  }
  local_c = 0;
  do {
    iVar1 = read_axi_fpga(local_18);
    local_38 = iVar1 >> (local_24 & 0xff) & 0xff;
    if (param_3 <= local_38) {
      local_c = 0;
      while( true ) {
        iVar1 = read_axi_fpga(local_1c);
        if (-1 < iVar1) {
          memcpy(abStack_238,param_2,param_3);
          local_2c = local_34 >> 2;
          for (local_10 = 0; local_10 < (int)local_2c; local_10 = local_10 + 1) {
            local_14 = (uint)abStack_238[local_10 * 4 + 3] |
                       (uint)abStack_238[local_10 * 4] << 0x18 |
                       (uint)abStack_238[local_10 * 4 + 1] << 0x10 |
                       (uint)abStack_238[local_10 * 4 + 2] << 8;
            write_axi_fpga(local_20,local_14);
          }
          local_2c = local_34 & 3;
          if (local_2c != 0) {
            if (local_2c == 2) {
              local_14 = (uint)abStack_238[local_10 * 4 + 1] << 0x10 |
                         (uint)abStack_238[local_10 * 4] << 0x18;
            }
            else if (local_2c == 3) {
              local_14 = (uint)abStack_238[local_10 * 4 + 2] << 8 |
                         (uint)abStack_238[local_10 * 4] << 0x18 |
                         (uint)abStack_238[local_10 * 4 + 1] << 0x10;
            }
            else if (local_2c == 1) {
              local_14 = (uint)abStack_238[local_10 * 4] << 0x18;
            }
            else {
              printf("%s: the uart%d send left data is 4*N length, error!!!\n","uart_send",
                     (uint)param_1);
            }
            write_axi_fpga(local_20,local_14);
          }
          write_axi_fpga(local_1c,local_34 | 0x80000000);
          pthread_mutex_unlock((pthread_mutex_t *)(&uart_send_mutex + (uint)param_1 * 0x18));
          return local_34;
        }
        if (0x14 < local_c) break;
        local_c = local_c + 1;
        usleep(3000);
      }
      pthread_mutex_unlock((pthread_mutex_t *)(&uart_send_mutex + (uint)param_1 * 0x18));
      printf("%s: uart%d always busy, break\n","uart_send",(uint)param_1);
      return 0;
    }
    usleep(3000);
    local_c = local_c + 1;
  } while (local_c < 0x15);
  pthread_mutex_unlock((pthread_mutex_t *)(&uart_send_mutex + (uint)param_1 * 0x18));
  printf("%s: uart%d always dose not has enough send fifo space, break\n","uart_send",(uint)param_1)
  ;
  return 0;
}

