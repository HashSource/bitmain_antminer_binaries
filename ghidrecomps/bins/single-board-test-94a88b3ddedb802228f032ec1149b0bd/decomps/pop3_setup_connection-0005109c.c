
undefined4
pop3_setup_connection(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  iVar4 = *param_1;
  iVar1 = (**DAT_00051100)(0xc,1,param_3,*DAT_00051100,param_4);
  *(int *)(iVar4 + 0x14c) = iVar1;
  if (iVar1 == 0) {
    return 0x1b;
  }
  *(undefined *)(param_1 + 0x7b) = 0;
  iVar1 = DAT_00051104;
  if ((*(char *)(param_1 + 0x7c) != '\0') && (*(char *)(iVar4 + 0x2fa) == '\0')) {
    iVar4 = param_1[0x86];
    bVar5 = iVar4 == DAT_00051104 + 0x88;
    if (!bVar5) {
      iVar4 = DAT_00051104 + 0x44;
    }
    iVar3 = iVar4;
    if (bVar5) {
      param_1[0x86] = DAT_00051104;
      iVar3 = iVar1;
    }
    if (!bVar5) {
      param_1[0x86] = iVar4;
    }
    uVar2 = (**(code **)(iVar3 + 4))(param_1);
    return uVar2;
  }
  *(int *)(iVar4 + 0x868c) = *(int *)(iVar4 + 0x868c) + 1;
  return 0;
}

