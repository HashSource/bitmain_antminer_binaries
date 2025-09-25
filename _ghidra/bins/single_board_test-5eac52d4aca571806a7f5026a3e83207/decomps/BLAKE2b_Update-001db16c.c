
undefined4 BLAKE2b_Update(int param_1,void *param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  void *__src;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0xe0);
  iVar3 = param_1 + 0x60;
  uVar2 = 0x80 - iVar1;
  __src = param_2;
  if (uVar2 < param_3) {
    if (iVar1 == 0) {
      uVar2 = param_3;
      if (param_3 < 0x81) {
        iVar1 = 0;
        goto LAB_001db1a8;
      }
    }
    else {
      param_3 = param_3 - uVar2;
      __src = (void *)((int)param_2 + uVar2);
      memcpy((void *)(iVar1 + iVar3),param_2,uVar2);
      blake2b_compress(param_1,iVar3,0x80);
      *(undefined4 *)(param_1 + 0xe0) = 0;
      uVar2 = param_3;
      param_2 = __src;
      if (param_3 < 0x81) {
        iVar1 = 0;
        goto LAB_001db1a8;
      }
    }
    param_3 = uVar2 & 0x7f;
    if (param_3 == 0) {
      param_3 = 0x80;
    }
    __src = (void *)((int)param_2 + (uVar2 - param_3));
    blake2b_compress(param_1,param_2,uVar2 - param_3,param_3,param_4);
    iVar1 = *(int *)(param_1 + 0xe0);
  }
LAB_001db1a8:
  memcpy((void *)(iVar1 + iVar3),__src,param_3);
  *(uint *)(param_1 + 0xe0) = param_3 + *(int *)(param_1 + 0xe0);
  return 1;
}

