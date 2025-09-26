
int EC_KEY_key2buf(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x10) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0xc);
      if (iVar1 != 0) {
        iVar1 = EC_POINT_point2buf(iVar1,*(int *)(param_1 + 0x10),param_2,param_3,param_4);
      }
    }
    return iVar1;
  }
  return 0;
}

