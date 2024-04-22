
undefined4 blake2b_update(int param_1,void *param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint __n;
  bool bVar2;
  uint local_20;
  uint uStack_1c;
  void *local_18;
  
  local_20 = param_3;
  uStack_1c = param_4;
  local_18 = param_2;
  while ((local_20 | uStack_1c) != 0) {
    iVar1 = *(int *)(param_1 + 0x160);
    __n = 0x100 - iVar1;
    bVar2 = uStack_1c == 0;
    if (uStack_1c == 0) {
      bVar2 = local_20 <= __n;
    }
    if (bVar2) {
      memcpy((void *)(param_1 + iVar1 + 0x60),local_18,local_20);
      *(uint *)(param_1 + 0x160) = *(int *)(param_1 + 0x160) + local_20;
      local_18 = (void *)((int)local_18 + local_20);
      local_20 = 0;
      uStack_1c = 0;
    }
    else {
      memcpy((void *)(param_1 + iVar1 + 0x60),local_18,__n);
      *(uint *)(param_1 + 0x160) = *(int *)(param_1 + 0x160) + __n;
      blake2b_increment_counter(param_1);
      blake2b_compress(param_1,param_1 + 0x60);
      memcpy((void *)(param_1 + 0x60),(void *)(param_1 + 0xe0),0x80);
      *(int *)(param_1 + 0x160) = *(int *)(param_1 + 0x160) + -0x80;
      local_18 = (void *)((int)local_18 + __n);
      bVar2 = local_20 < __n;
      local_20 = local_20 - __n;
      uStack_1c = uStack_1c - bVar2;
    }
  }
  return 0;
}

