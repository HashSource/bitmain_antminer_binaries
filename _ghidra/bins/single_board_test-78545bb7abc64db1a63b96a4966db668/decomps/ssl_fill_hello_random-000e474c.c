
int ssl_fill_hello_random(int param_1,int param_2,uchar *param_3,uint param_4,int param_5)

{
  time_t tVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_4 < 4) {
    return 0;
  }
  if (param_2 == 0) {
    iVar2 = *(int *)(param_1 + 0x4f0) << 0x1a;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x4f0) << 0x19;
  }
  if (iVar2 < 0) {
    tVar1 = time((time_t *)0x0);
    param_3[3] = (uchar)tVar1;
    *param_3 = (uchar)((uint)tVar1 >> 0x18);
    param_3[1] = (uchar)((uint)tVar1 >> 0x10);
    param_3[2] = (uchar)((uint)tVar1 >> 8);
    iVar2 = RAND_bytes(param_3 + 4,param_4 - 4);
  }
  else {
    iVar2 = RAND_bytes(param_3,param_4);
  }
  if (0 < iVar2) {
    if (param_4 < 9) {
      return 0;
    }
    iVar3 = 0x6ac;
    if (param_5 != 1) {
      if (param_5 != 2) {
        return iVar2;
      }
      iVar3 = 0x4fc;
    }
    uVar4 = (*(undefined4 **)((int)&_GLOBAL_OFFSET_TABLE_ + iVar3))[1];
    *(undefined4 *)(param_3 + (param_4 - 8)) =
         **(undefined4 **)((int)&_GLOBAL_OFFSET_TABLE_ + iVar3);
    *(undefined4 *)(param_3 + (param_4 - 4)) = uVar4;
    return iVar2;
  }
  return iVar2;
}

