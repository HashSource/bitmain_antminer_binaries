
uint uart_send(byte param_1,void *param_2,uint param_3)

{
  int iVar1;
  byte abStack_23c [512];
  uint local_3c;
  uint local_38;
  undefined4 local_34;
  uint local_30;
  undefined4 local_2c;
  uint local_28;
  uint local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  int local_10;
  int local_c;
  
  local_2c = 0;
  local_c = 0;
  local_30 = 0;
  local_10 = 0;
  local_34 = 0;
  memset(abStack_23c,0,0x200);
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  local_20 = 0;
  local_3c = 0;
  local_24 = 0;
  local_38 = param_3;
  pthread_mutex_lock((pthread_mutex_t *)(&uart_send_mutex + (uint)param_1 * 0x18));
  for (local_28 = 0; local_28 < param_3; local_28 = local_28 + 1) {
    printf("%02x",(uint)*(byte *)((int)param_2 + local_28));
  }
  putchar(10);
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
    local_3c = iVar1 >> (local_24 & 0xff) & 0xff;
    if (param_3 <= local_3c) {
      local_c = 0;
      while( true ) {
        iVar1 = read_axi_fpga(local_1c);
        if (-1 < iVar1) {
          memcpy(abStack_23c,param_2,param_3);
          local_30 = local_38 >> 2;
          for (local_10 = 0; local_10 < (int)local_30; local_10 = local_10 + 1) {
            local_14 = (uint)abStack_23c[local_10 * 4 + 3] |
                       (uint)abStack_23c[local_10 * 4] << 0x18 |
                       (uint)abStack_23c[local_10 * 4 + 1] << 0x10 |
                       (uint)abStack_23c[local_10 * 4 + 2] << 8;
            write_axi_fpga(local_20,local_14);
          }
          local_30 = local_38 & 3;
          if (local_30 != 0) {
            if (local_30 == 2) {
              local_14 = (uint)abStack_23c[local_10 * 4 + 1] << 0x10 |
                         (uint)abStack_23c[local_10 * 4] << 0x18;
            }
            else if (local_30 == 3) {
              local_14 = (uint)abStack_23c[local_10 * 4 + 2] << 8 |
                         (uint)abStack_23c[local_10 * 4] << 0x18 |
                         (uint)abStack_23c[local_10 * 4 + 1] << 0x10;
            }
            else if (local_30 == 1) {
              local_14 = (uint)abStack_23c[local_10 * 4] << 0x18;
            }
            else {
              printf("%s: the uart%d send left data is 4*N length, error!!!\n","uart_send",
                     (uint)param_1);
            }
            write_axi_fpga(local_20,local_14);
          }
          write_axi_fpga(local_1c,local_38 | 0x80000000);
          pthread_mutex_unlock((pthread_mutex_t *)(&uart_send_mutex + (uint)param_1 * 0x18));
          return local_38;
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

