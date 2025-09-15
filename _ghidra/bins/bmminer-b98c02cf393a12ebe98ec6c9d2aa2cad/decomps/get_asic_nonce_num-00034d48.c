
int get_asic_nonce_num(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (0 < param_3) {
    iVar1 = 0;
    iVar3 = nonce_times % 0x3c + -1;
    param_3 = iVar3 - param_3;
    do {
      iVar2 = iVar3;
      if (iVar3 < 0) {
        iVar2 = iVar3 + 0x3c;
      }
      iVar3 = iVar3 + -1;
      iVar1 = iVar1 + *(int *)(nonce_num + (iVar2 + param_1 * 0x1e00 + param_2 * 0x3c) * 8);
    } while (iVar3 != param_3);
    return iVar1;
  }
  return 0;
}

