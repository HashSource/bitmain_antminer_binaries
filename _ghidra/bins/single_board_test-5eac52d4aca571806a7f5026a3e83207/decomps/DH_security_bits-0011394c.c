
void DH_security_bits(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_r2;
  
  if (*(BIGNUM **)(param_1 + 0x24) == (BIGNUM *)0x0) {
    iVar1 = *(int *)(param_1 + 0x10);
    if (iVar1 == 0) {
      iVar1 = -1;
    }
  }
  else {
    iVar1 = BN_num_bits(*(BIGNUM **)(param_1 + 0x24));
  }
  iVar2 = BN_num_bits(*(BIGNUM **)(param_1 + 8));
  BN_security_bits(iVar2,iVar1,extraout_r2,param_4);
  return;
}

