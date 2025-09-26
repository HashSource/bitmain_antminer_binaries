
int dsa_param_print(BIO *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 0x18);
  iVar1 = ASN1_bn_print(param_1,"priv:",(BIGNUM *)0x0,(uchar *)0x0,param_3);
  if ((((iVar1 == 0) ||
       (iVar1 = ASN1_bn_print(param_1,"pub: ",(BIGNUM *)0x0,(uchar *)0x0,param_3), iVar1 == 0)) ||
      (iVar1 = ASN1_bn_print(param_1,"P:   ",*(BIGNUM **)(iVar2 + 8),(uchar *)0x0,param_3),
      iVar1 == 0)) ||
     (iVar1 = ASN1_bn_print(param_1,"Q:   ",*(BIGNUM **)(iVar2 + 0xc),(uchar *)0x0,param_3),
     iVar1 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = ASN1_bn_print(param_1,"G:   ",*(BIGNUM **)(iVar2 + 0x10),(uchar *)0x0,param_3);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
  return iVar1;
}

