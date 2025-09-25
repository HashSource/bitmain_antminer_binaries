
undefined4 eckey_pub_print(BIO *param_1,int param_2,int param_3)

{
  EC_GROUP *x;
  EC_POINT *pEVar1;
  point_conversion_form_t pVar2;
  int iVar3;
  int iVar4;
  EC_KEY *key;
  undefined4 uVar5;
  void *local_1c;
  
  key = *(EC_KEY **)(param_2 + 0x18);
  local_1c = (void *)0x0;
  if ((key == (EC_KEY *)0x0) || (x = EC_KEY_get0_group(key), x == (EC_GROUP *)0x0)) {
    ERR_put_error(0x10,0xdd,0x43,"crypto/ec/ec_ameth.c",0x170);
    return 0;
  }
  pEVar1 = EC_KEY_get0_public_key(key);
  if (pEVar1 == (EC_POINT *)0x0) {
    iVar3 = 0;
LAB_00116a00:
    iVar4 = BIO_indent(param_1,param_3,0x80);
    if (iVar4 != 0) {
      uVar5 = EC_GROUP_order_bits(x);
      iVar4 = BIO_printf(param_1,"%s: (%d bit)\n","Public-Key",uVar5);
      if ((0 < iVar4) &&
         ((iVar3 == 0 ||
          ((iVar4 = BIO_printf(param_1,"%*spub:\n",param_3,""), 0 < iVar4 &&
           (iVar3 = ASN1_buf_print(param_1,local_1c,iVar3,param_3 + 4), iVar3 != 0)))))) {
        uVar5 = 1;
        iVar3 = ECPKParameters_print(param_1,x,param_3);
        if (iVar3 != 0) goto LAB_001169d8;
      }
    }
  }
  else {
    pVar2 = EC_KEY_get_conv_form(key);
    iVar3 = EC_KEY_key2buf(key,pVar2,&local_1c,0);
    if (iVar3 != 0) goto LAB_00116a00;
  }
  uVar5 = 0;
  ERR_put_error(0x10,0xdd,0x10,"crypto/ec/ec_ameth.c",0x1a0);
LAB_001169d8:
  CRYPTO_clear_free(0,0,"crypto/ec/ec_ameth.c",0x1a1);
  CRYPTO_free(local_1c);
  return uVar5;
}

