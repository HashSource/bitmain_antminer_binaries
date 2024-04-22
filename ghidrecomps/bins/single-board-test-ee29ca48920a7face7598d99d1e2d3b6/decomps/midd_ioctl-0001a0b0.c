
int midd_ioctl(undefined param_1,undefined4 param_2,undefined4 param_3)

{
  undefined auStack_138 [300];
  int local_c;
  
  memset(auStack_138,0,300);
  local_c = pack_ioctl_pkg(auStack_138,300,param_2,param_3);
  if (-1 < local_c) {
    local_c = uart_send(param_1,auStack_138,local_c);
  }
  return local_c;
}

