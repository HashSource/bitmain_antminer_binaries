
undefined4 RSA_security_bits(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  
  iVar1 = BN_num_bits(*(BIGNUM **)(param_1 + 0x10));
  uVar2 = extraout_r2;
  if ((*(int *)(param_1 + 4) == 1) &&
     ((iVar3 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 0x30)), iVar3 < 1 ||
      (iVar4 = rsa_multip_cap(iVar1), uVar2 = extraout_r2_00, iVar4 <= iVar3 + 1)))) {
    return 0;
  }
  uVar2 = BN_security_bits(iVar1,0xffffffff,uVar2,param_4);
  return uVar2;
}

