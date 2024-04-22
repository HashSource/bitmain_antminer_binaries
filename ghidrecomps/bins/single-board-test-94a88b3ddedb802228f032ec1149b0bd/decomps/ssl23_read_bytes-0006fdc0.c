
uint ssl23_read_bytes(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *(uint *)(param_1 + 0x50);
  uVar1 = param_2;
  if (uVar2 < param_2) {
    iVar3 = *(int *)(param_1 + 0x4c);
    while( true ) {
      *(undefined4 *)(param_1 + 0x18) = 3;
      uVar1 = BIO_read(*(BIO **)(param_1 + 0xc),(void *)(iVar3 + uVar2),param_2 - uVar2);
      if ((int)uVar1 < 1) break;
      *(undefined4 *)(param_1 + 0x18) = 1;
      uVar2 = uVar1 + *(int *)(param_1 + 0x50);
      *(uint *)(param_1 + 0x50) = uVar2;
      if (param_2 <= uVar2) {
        return uVar2;
      }
    }
  }
  return uVar1;
}

