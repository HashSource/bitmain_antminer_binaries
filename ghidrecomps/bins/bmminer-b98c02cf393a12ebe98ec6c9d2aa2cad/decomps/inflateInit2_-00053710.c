
int inflateInit2_(int param_1,undefined4 param_2,char *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
  if (((param_3 != (char *)0x0) && (*param_3 == '1')) && (param_4 == 0x38)) {
    if (param_1 == 0) {
      iVar2 = -2;
    }
    else {
      pcVar3 = *(code **)(param_1 + 0x20);
      *(undefined4 *)(param_1 + 0x18) = 0;
      if (pcVar3 == (code *)0x0) {
        pcVar3 = (code *)0x55b7d;
        *(undefined4 *)(param_1 + 0x28) = 0;
        *(undefined4 *)(param_1 + 0x20) = 0x55b7d;
        iVar2 = *(int *)(param_1 + 0x24);
      }
      else {
        iVar2 = *(int *)(param_1 + 0x24);
      }
      if (iVar2 == 0) {
        *(undefined4 *)(param_1 + 0x24) = 0x55b85;
      }
      iVar1 = (*pcVar3)(*(undefined4 *)(param_1 + 0x28),1,0x1bcc,pcVar3,0x38);
      if (iVar1 == 0) {
        iVar2 = -4;
      }
      else {
        *(int *)(param_1 + 0x1c) = iVar1;
        *(undefined4 *)(iVar1 + 0x34) = 0;
        iVar2 = inflateReset2(param_1,param_2);
        if (iVar2 != 0) {
          (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0x28),iVar1);
          *(undefined4 *)(param_1 + 0x1c) = 0;
          return iVar2;
        }
      }
    }
    return iVar2;
  }
  return -6;
}

