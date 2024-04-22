
int inflateInit_(int param_1,char *param_2,int param_3,undefined4 param_4)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  
  if (((param_2 != (char *)0x0) && (*param_2 == '1')) && (param_3 == 0x38)) {
    if (param_1 == 0) {
      iVar3 = -2;
    }
    else {
      pcVar4 = *(code **)(param_1 + 0x20);
      *(undefined4 *)(param_1 + 0x18) = 0;
      pcVar1 = DAT_00053820;
      if (pcVar4 == (code *)0x0) {
        *(undefined4 *)(param_1 + 0x28) = 0;
        *(code **)(param_1 + 0x20) = pcVar1;
        iVar3 = *(int *)(param_1 + 0x24);
        pcVar4 = pcVar1;
      }
      else {
        iVar3 = *(int *)(param_1 + 0x24);
      }
      if (iVar3 == 0) {
        *(undefined4 *)(param_1 + 0x24) = DAT_00053824;
      }
      iVar2 = (*pcVar4)(*(undefined4 *)(param_1 + 0x28),1,0x1bcc,pcVar4,param_4);
      if (iVar2 == 0) {
        iVar3 = -4;
      }
      else {
        *(int *)(param_1 + 0x1c) = iVar2;
        *(undefined4 *)(iVar2 + 0x34) = 0;
        iVar3 = inflateReset2(param_1,0xf);
        if (iVar3 != 0) {
          (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),iVar2);
          *(undefined4 *)(param_1 + 0x1c) = 0;
          return iVar3;
        }
      }
    }
    return iVar3;
  }
  return -6;
}

