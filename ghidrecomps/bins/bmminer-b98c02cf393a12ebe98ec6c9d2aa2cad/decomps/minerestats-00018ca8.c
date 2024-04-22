
void minerestats(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  undefined4 uVar5;
  int local_44;
  char acStack_3c [24];
  
  message(param_1,0x46,0,0,param_4);
  if (param_4 == 0) {
    if (total_devices < 1) {
      return;
    }
    local_44 = 0;
  }
  else {
    local_44 = io_add(param_1,",\"STATS\":[");
    if (total_devices < 1) goto LAB_00018d2c;
  }
  iVar3 = 0;
  uVar5 = 0;
  do {
    iVar1 = get_devices(iVar3);
    if ((iVar1 != 0) && (iVar2 = *(int *)(iVar1 + 4), iVar2 != 0)) {
      pcVar4 = *(code **)(iVar2 + 0x1c);
      if (pcVar4 != (code *)0x0) {
        pcVar4 = (code *)(*pcVar4)();
        iVar2 = *(int *)(iVar1 + 4);
      }
      sprintf(acStack_3c,"%s%d",*(undefined4 *)(iVar2 + 8),*(undefined4 *)(iVar1 + 8));
      uVar5 = itemstats_isra_17(param_1,uVar5,acStack_3c,iVar1 + 0x124,pcVar4,param_4);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < total_devices);
LAB_00018d2c:
  if (local_44 != 0) {
    *(undefined *)(param_1 + 0xd) = 1;
  }
  return;
}

