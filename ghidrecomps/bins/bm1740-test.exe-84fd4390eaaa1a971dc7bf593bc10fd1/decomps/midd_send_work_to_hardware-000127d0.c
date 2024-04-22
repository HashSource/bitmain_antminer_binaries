
undefined4 midd_send_work_to_hardware(undefined param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = bm1740_pack_work_pkg(param_2,param_3);
  if (iVar1 < 1) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = uart_send(param_1,param_2,iVar1);
  }
  return uVar2;
}

