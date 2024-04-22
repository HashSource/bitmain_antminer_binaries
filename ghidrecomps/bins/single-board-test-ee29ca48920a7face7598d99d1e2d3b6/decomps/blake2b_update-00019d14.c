
undefined4 blake2b_update(int param_1,void *param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint __n;
  bool bVar2;
  uint local_28;
  uint uStack_24;
  void *local_20;
  
  local_28 = param_3;
  uStack_24 = param_4;
  local_20 = param_2;
  while ((local_28 | uStack_24) != 0) {
    iVar1 = *(int *)(param_1 + 0x160);
    __n = 0x100 - iVar1;
    bVar2 = uStack_24 == 0;
    if (uStack_24 == 0) {
      bVar2 = local_28 <= __n;
    }
    if (bVar2) {
      memcpy((void *)(iVar1 + param_1 + 0x60),local_20,local_28);
      *(uint *)(param_1 + 0x160) = *(int *)(param_1 + 0x160) + local_28;
      local_20 = (void *)(local_28 + (int)local_20);
      local_28 = 0;
      uStack_24 = 0;
    }
    else {
      memcpy((void *)(iVar1 + param_1 + 0x60),local_20,__n);
      *(uint *)(param_1 + 0x160) = *(int *)(param_1 + 0x160) + __n;
      blake2b_increment_counter(param_1);
      blake2b_compress(param_1,param_1 + 0x60);
      memcpy((void *)(param_1 + 0x60),(void *)(param_1 + 0xe0),0x80);
      *(int *)(param_1 + 0x160) = *(int *)(param_1 + 0x160) + -0x80;
      local_20 = (void *)(__n + (int)local_20);
      bVar2 = local_28 < __n;
      local_28 = local_28 - __n;
      uStack_24 = uStack_24 - bVar2;
    }
  }
  return 0;
}

