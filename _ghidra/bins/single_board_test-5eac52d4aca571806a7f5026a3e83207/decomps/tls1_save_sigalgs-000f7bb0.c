
undefined4 tls1_save_sigalgs(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (-1 < *(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1e) {
    return 1;
  }
  if (*(int *)(param_1 + 0x404) != 0) {
    iVar2 = *(int *)(param_1 + 0x7c);
    if (param_3 == 0) {
      uVar1 = tls1_save_u16(param_2,iVar2 + 0x268,iVar2 + 0x270);
      return uVar1;
    }
    uVar1 = tls1_save_u16(param_2,iVar2 + 0x26c,iVar2 + 0x274);
    return uVar1;
  }
  return 0;
}

