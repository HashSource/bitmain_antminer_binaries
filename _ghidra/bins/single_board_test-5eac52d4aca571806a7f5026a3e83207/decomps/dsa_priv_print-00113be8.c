
undefined4 dsa_priv_print(BIO *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  BIGNUM *num;
  BIGNUM *num_00;
  
  iVar2 = *(int *)(param_2 + 0x18);
  num = *(BIGNUM **)(iVar2 + 0x18);
  num_00 = *(BIGNUM **)(iVar2 + 0x14);
  if (num != (BIGNUM *)0x0) {
    iVar1 = BIO_indent(param_1,param_3,0x80);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = BN_num_bits(*(BIGNUM **)(iVar2 + 8));
    iVar1 = BIO_printf(param_1,"%s: (%d bit)\n","Private-Key",iVar1);
    if (iVar1 < 1) {
      return 0;
    }
  }
  iVar1 = ASN1_bn_print(param_1,"priv:",num,(uchar *)0x0,param_3);
  if ((((iVar1 != 0) &&
       (iVar1 = ASN1_bn_print(param_1,"pub: ",num_00,(uchar *)0x0,param_3), iVar1 != 0)) &&
      (iVar1 = ASN1_bn_print(param_1,"P:   ",*(BIGNUM **)(iVar2 + 8),(uchar *)0x0,param_3),
      iVar1 != 0)) &&
     (iVar1 = ASN1_bn_print(param_1,"Q:   ",*(BIGNUM **)(iVar2 + 0xc),(uchar *)0x0,param_3),
     iVar1 != 0)) {
    iVar2 = ASN1_bn_print(param_1,"G:   ",*(BIGNUM **)(iVar2 + 0x10),(uchar *)0x0,param_3);
    if (iVar2 != 0) {
      return 1;
    }
    return 0;
  }
  return 0;
}

