
int midd_ioctl(undefined param_1,undefined4 param_2,undefined4 param_3)

{
  undefined auStack_10c [256];
  int local_c;
  
  memset(auStack_10c,0,0x100);
  local_c = bm1740_pack_ioctl_pkg(auStack_10c,0x100,param_2,param_3);
  if (-1 < local_c) {
    local_c = uart_send(param_1,auStack_10c,local_c);
  }
  return local_c;
}

