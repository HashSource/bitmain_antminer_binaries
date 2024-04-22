
void gost_cnt_next(int param_1,uint *param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  uint local_28;
  uint local_24;
  
  if (*(int *)(param_1 + 8) == 0) {
    iVar2 = *(int *)(param_1 + 4);
  }
  else {
    iVar2 = *(int *)(param_1 + 4);
    if (iVar2 == 0x400) {
      cryptopro_key_meshing(param_1 + 0xc);
      iVar2 = *(int *)(param_1 + 4);
    }
  }
  if (iVar2 == 0) {
    gostcrypt(param_1 + 0xc,param_2,&local_28);
  }
  else {
    local_28 = *param_2;
    local_24 = param_2[1];
  }
  uVar1 = (local_24 >> 0x10 & 0xff) << 0x10 | (local_24 >> 8 & 0xff) << 8 | local_24 & 0xff |
          local_24 & 0xff000000;
  local_24 = uVar1 + 0x1010104;
  local_28 = ((local_28 >> 0x10 & 0xff) << 0x10 | (local_28 >> 8 & 0xff) << 8 | local_28 & 0xff |
             local_28 & 0xff000000) + 0x1010101;
  if (local_24 < uVar1) {
    local_24 = uVar1 + 0x1010105;
  }
  *param_2 = local_28;
  param_2[1] = local_24;
  gostcrypt(param_1 + 0xc,&local_28,param_3,&stack0xffffffe0);
  *(uint *)(param_1 + 4) = (*(uint *)(param_1 + 4) & 0x3ff) + 8;
  return;
}

