
void notify(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (total_devices == 0) {
    message(param_1,10,0,0);
    return;
  }
  message(param_1,0x3c,0,0,param_4);
  if (param_4 == 0) {
    if (total_devices < 1) {
      return;
    }
    iVar2 = 0;
  }
  else {
    iVar2 = io_add(param_1,",\"NOTIFY\":[");
    if (total_devices < 1) goto LAB_00019c2e;
  }
  iVar3 = 0;
  do {
    uVar1 = get_devices(iVar3);
    iVar4 = iVar3 + 1;
    notifystatus(param_1,iVar3,uVar1,param_4,param_5);
    iVar3 = iVar4;
  } while (iVar4 < total_devices);
LAB_00019c2e:
  if (iVar2 != 0) {
    *(undefined *)(param_1 + 0xd) = 1;
  }
  return;
}

