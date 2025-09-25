
undefined4 DSA_security_bits(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((*(BIGNUM **)(param_1 + 8) != (BIGNUM *)0x0) && (*(int *)(param_1 + 0xc) != 0)) {
    iVar1 = BN_num_bits(*(BIGNUM **)(param_1 + 8));
    iVar2 = BN_num_bits(*(BIGNUM **)(param_1 + 0xc));
    uVar3 = BN_security_bits(iVar1,iVar2);
    return uVar3;
  }
  return 0xffffffff;
}

