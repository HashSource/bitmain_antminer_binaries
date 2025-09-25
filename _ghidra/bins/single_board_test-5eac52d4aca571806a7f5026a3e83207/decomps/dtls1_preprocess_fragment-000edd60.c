
undefined4 dtls1_preprocess_fragment(int param_1,byte *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(param_2 + 4);
  if ((uint)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0xc)) <= uVar4) {
    uVar2 = 0x454c;
    if (0x454c < *(uint *)(param_1 + 0x4fc)) {
      uVar2 = *(uint *)(param_1 + 0x4fc);
    }
    if (uVar4 <= uVar2) {
      if (*(int *)(*(int *)(param_1 + 0x80) + 0x158) == 0) {
        iVar1 = BUF_MEM_grow_clean(*(BUF_MEM **)(param_1 + 0x6c),uVar4 + 0xc);
        if (iVar1 != 0) {
          iVar1 = *(int *)(param_1 + 0x7c);
          iVar3 = *(int *)(param_1 + 0x80);
          *(uint *)(iVar1 + 0x208) = uVar4;
          *(uint *)(iVar3 + 0x150) = uVar4;
          *(uint *)(iVar1 + 0x20c) = (uint)*param_2;
          *(byte *)(iVar3 + 0x14c) = *param_2;
          *(undefined2 *)(*(int *)(param_1 + 0x80) + 0x154) = *(undefined2 *)(param_2 + 8);
          return 1;
        }
        ossl_statem_fatal(param_1,0x50,0x120,7,"ssl/statem/statem_dtls.c",0x1b9);
        return 0;
      }
      if (uVar4 == *(uint *)(*(int *)(param_1 + 0x80) + 0x150)) {
        return 1;
      }
      ossl_statem_fatal(param_1,0x2f,0x120,0x98,"ssl/statem/statem_dtls.c",0x1c8);
      return 0;
    }
  }
  ossl_statem_fatal(param_1,0x2f,0x120,0x98,"ssl/statem/statem_dtls.c",0x1ae);
  return 0;
}

