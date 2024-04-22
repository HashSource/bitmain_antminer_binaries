
int trynextip(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = param_1 + (param_3 + 0x56) * 4;
  iVar4 = *(int *)(iVar1 + 4);
  *(undefined4 *)(iVar1 + 4) = 0xffffffff;
  if (param_2 == 0) {
    iVar1 = *(int *)(param_1 + (param_3 + 0x14) * 4);
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x50);
      if (iVar1 == 0) goto LAB_00039786;
      iVar2 = *(int *)(iVar1 + 0x1c);
      if (*(int *)(iVar1 + 4) == 2) {
        iVar3 = 10;
      }
      else {
        iVar3 = 2;
      }
    }
    else {
      iVar3 = *(int *)(iVar1 + 4);
      iVar2 = *(int *)(iVar1 + 0x1c);
    }
    if (iVar2 != 0) {
      do {
        if (*(int *)(param_1 + ((param_3 ^ 1) + 0x14) * 4) == 0) {
          iVar1 = 0;
        }
        else {
          while (iVar1 = *(int *)(iVar2 + 4), iVar1 != iVar3) {
            iVar2 = *(int *)(iVar2 + 0x1c);
            if (iVar2 == 0) goto LAB_00039786;
          }
        }
        iVar1 = singleipconnect(param_1,iVar2,param_1 + (param_3 + 0x56) * 4 + 4,iVar1,param_4);
        if (iVar1 != 7) {
          *(int *)(param_1 + (param_3 + 0x14) * 4) = iVar2;
          goto LAB_00039788;
        }
        iVar2 = *(int *)(iVar2 + 0x1c);
      } while (iVar2 != 0);
    }
  }
LAB_00039786:
  iVar1 = 7;
LAB_00039788:
  if (iVar4 != -1) {
    Curl_closesocket(param_1,iVar4);
  }
  return iVar1;
}

