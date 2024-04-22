
uint uart_send(int param_1,void *param_2,uint param_3)

{
  int iVar1;
  uint local_138;
  uint local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  byte abStack_124 [256];
  uint local_24;
  uint local_20;
  undefined4 local_1c;
  uint local_18;
  int local_14;
  
  local_1c = 0;
  local_20 = 0;
  local_14 = 0;
  memset(abStack_124,0,0x100);
  local_18 = 0;
  local_128 = 0;
  local_12c = 0;
  local_130 = 0;
  local_134 = 0;
  local_138 = 0;
  local_24 = param_3;
  pthread_mutex_lock((pthread_mutex_t *)(&uart_send_mutex + param_1 * 0x18));
  iVar1 = get_send_address_info(param_1,&local_138,&local_128,&local_12c,&local_130);
  if (iVar1 == 0) {
    local_1c = 0;
    do {
      fpga_read(local_128,&local_134);
      local_134 = local_134 >> (local_138 & 0xff) & 0xff;
    } while (local_134 < param_3);
    local_1c = 0;
    do {
      fpga_read(local_12c,&local_134);
    } while ((int)local_134 < 0);
    memcpy(abStack_124,param_2,param_3);
    local_20 = local_24 >> 2;
    for (local_14 = 0; local_14 < (int)local_20; local_14 = local_14 + 1) {
      local_18 = (uint)abStack_124[local_14 * 4 + 3] |
                 (uint)abStack_124[local_14 * 4] << 0x18 |
                 (uint)abStack_124[local_14 * 4 + 1] << 0x10 |
                 (uint)abStack_124[local_14 * 4 + 2] << 8;
      fpga_write(local_130,local_18);
    }
    local_20 = local_24 & 3;
    if (local_20 != 0) {
      if (local_20 == 2) {
        local_18 = (uint)abStack_124[local_14 * 4 + 1] << 0x10 |
                   (uint)abStack_124[local_14 * 4] << 0x18;
      }
      else if (local_20 == 3) {
        local_18 = (uint)abStack_124[local_14 * 4 + 2] << 8 |
                   (uint)abStack_124[local_14 * 4] << 0x18 |
                   (uint)abStack_124[local_14 * 4 + 1] << 0x10;
      }
      else if (local_20 == 1) {
        local_18 = (uint)abStack_124[local_14 * 4] << 0x18;
      }
      else {
        printf("%s: the uart%d send left data is 4*N length, error!!!\n","uart_send",param_1);
      }
      fpga_write(local_130,local_18);
    }
    fpga_write(local_12c,local_24 | 0x80000000);
    pthread_mutex_unlock((pthread_mutex_t *)(&uart_send_mutex + param_1 * 0x18));
  }
  else {
    printf("%s:%d","uart_send",0x248);
    printf("get_send_address_info error, chain_id = %d\n",param_1);
    pthread_mutex_unlock((pthread_mutex_t *)(&uart_send_mutex + param_1 * 0x18));
    local_24 = 0;
  }
  return local_24;
}

