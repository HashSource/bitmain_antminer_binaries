
undefined4 dcr_uart_send(char param_1,void *param_2,size_t param_3)

{
  undefined4 uVar1;
  undefined local_20c;
  undefined local_20b;
  undefined auStack_20a [510];
  undefined4 local_c;
  
  local_c = 0;
  if (param_1 == -1) {
    printf("%s: invalid chain id\n","dcr_uart_send");
    uVar1 = 0xffffffff;
  }
  else {
    memset(&local_20c,0,0x200);
    local_20c = 0x55;
    local_20b = 0xaa;
    memcpy(auStack_20a,param_2,param_3);
    uVar1 = uart_send(param_1,&local_20c,param_3 + 2);
  }
  return uVar1;
}

