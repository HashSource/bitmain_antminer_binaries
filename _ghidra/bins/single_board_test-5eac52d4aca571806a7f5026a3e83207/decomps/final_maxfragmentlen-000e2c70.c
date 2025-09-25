
int final_maxfragmentlen(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  
  if ((*(int *)(param_1 + 0x1c) == 0) || (*(int *)(param_1 + 0x8c) == 0)) {
    iVar1 = *(int *)(param_1 + 0x474);
    if (iVar1 == 0) {
      return 1;
    }
  }
  else {
    iVar1 = *(int *)(param_1 + 0x474);
    uVar2 = *(byte *)(iVar1 + 0x1ec) - 1;
    bVar3 = uVar2 == 3;
    if (uVar2 < 4) {
      bVar3 = param_3 == 0;
    }
    if (bVar3) {
      ossl_statem_fatal(param_1,0x6d,0x22d,0x6e,"ssl/statem/extensions.c",0x6ae);
      return 0;
    }
  }
  if (((byte)(*(char *)(iVar1 + 0x1ec) - 1U) < 4) &&
     (*(uint *)(param_1 + 0x50c) < (uint)(0x200 << (uint)(byte)(*(char *)(iVar1 + 0x1ec) - 1)))) {
    iVar1 = ssl3_setup_buffers(param_1);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
    return iVar1;
  }
  return 1;
}

