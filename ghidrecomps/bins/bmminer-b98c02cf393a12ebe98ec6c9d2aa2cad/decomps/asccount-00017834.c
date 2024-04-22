
void asccount(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_14;
  
  local_14 = 0;
  message(param_1,0x68,0,0,param_4);
  if (param_4 != 0) {
    iVar1 = io_add(param_1,",\"ASCS\":[");
    uVar2 = api_add_data_full(0,"Count",6,&local_14,0);
    print_data(param_1,uVar2,1,0);
    if (iVar1 != 0) {
      *(undefined *)(param_1 + 0xd) = 1;
    }
    return;
  }
  io_add(param_1,"ASCS,");
  uVar2 = api_add_data_full(0,"Count",6,&local_14,0);
  print_data(param_1,uVar2,0,0);
  return;
}

