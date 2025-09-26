
undefined4 eckey_param_print(BIO *param_1,int param_2,int param_3)

{
  EC_GROUP *x;
  int iVar1;
  undefined4 uVar2;
  
  if ((*(EC_KEY **)(param_2 + 0x18) == (EC_KEY *)0x0) ||
     (x = EC_KEY_get0_group(*(EC_KEY **)(param_2 + 0x18)), x == (EC_GROUP *)0x0)) {
    ERR_put_error(0x10,0xdd,0x43,"crypto/ec/ec_ameth.c",0x170);
    return 0;
  }
  iVar1 = BIO_indent(param_1,param_3,0x80);
  if (iVar1 != 0) {
    uVar2 = EC_GROUP_order_bits(x);
    iVar1 = BIO_printf(param_1,"%s: (%d bit)\n","ECDSA-Parameters",uVar2);
    if ((0 < iVar1) && (iVar1 = ECPKParameters_print(param_1,x,param_3), iVar1 != 0)) {
      uVar2 = 1;
      goto LAB_0012472c;
    }
  }
  uVar2 = 0;
  ERR_put_error(0x10,0xdd,0x10,"crypto/ec/ec_ameth.c",0x1a0);
LAB_0012472c:
  CRYPTO_clear_free(0,0,"crypto/ec/ec_ameth.c",0x1a1);
  CRYPTO_free((void *)0x0);
  return uVar2;
}

