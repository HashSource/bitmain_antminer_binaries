
int ECParameters_print(BIO *bp,EC_KEY *key)

{
  EC_GROUP *x;
  int iVar1;
  undefined4 uVar2;
  
  if ((key == (EC_KEY *)0x0) || (x = EC_KEY_get0_group(key), x == (EC_GROUP *)0x0)) {
    ERR_put_error(0x10,0xdd,0x43,"crypto/ec/ec_ameth.c",0x170);
    return 0;
  }
  iVar1 = BIO_indent(bp,4,0x80);
  if (iVar1 != 0) {
    uVar2 = EC_GROUP_order_bits(x);
    iVar1 = BIO_printf(bp,"%s: (%d bit)\n","ECDSA-Parameters",uVar2);
    if ((0 < iVar1) && (iVar1 = ECPKParameters_print(bp,x,4), iVar1 != 0)) {
      iVar1 = 1;
      goto LAB_00116de8;
    }
  }
  iVar1 = 0;
  ERR_put_error(0x10,0xdd,0x10,"crypto/ec/ec_ameth.c",0x1a0);
LAB_00116de8:
  CRYPTO_clear_free(0,0,"crypto/ec/ec_ameth.c",0x1a1);
  CRYPTO_free((void *)0x0);
  return iVar1;
}

