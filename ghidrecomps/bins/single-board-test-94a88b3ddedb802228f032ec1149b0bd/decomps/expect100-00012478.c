
int expect100(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = 0;
  *(undefined *)(param_1 + 0x867c) = 0;
  if (((*(int *)(param_1 + 0x8678) != 10) && (iVar2 = *(int *)(param_2 + 0x13c), iVar2 != 10)) &&
     ((uVar4 = *(uint *)(param_1 + 0x27c), uVar4 != 1 || (10 < iVar2)))) {
    if ((int)uVar4 < 2) {
      iVar3 = 1 - uVar4;
      if (1 < uVar4) {
        iVar3 = 0;
      }
      if (iVar3 == 0) {
        return 0;
      }
    }
    if (iVar2 == 0x14) {
      iVar3 = 0;
    }
    else {
      iVar2 = Curl_checkheaders(param_2,DAT_000124f0,param_3,iVar2,param_4);
      if (iVar2 == 0) {
        iVar3 = Curl_add_bufferf(param_3,DAT_000124f8);
        if (iVar3 == 0) {
          *(undefined *)(param_1 + 0x867c) = 1;
        }
      }
      else {
        iVar3 = 0;
        uVar1 = Curl_compareheader(iVar2,DAT_000124f0,DAT_000124f4);
        *(undefined *)(param_1 + 0x867c) = uVar1;
      }
    }
  }
  return iVar3;
}

