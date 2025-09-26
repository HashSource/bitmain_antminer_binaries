
undefined4 eckey_priv_print(BIO *param_1,int param_2,int param_3)

{
  EC_GROUP *x;
  EC_POINT *pEVar1;
  point_conversion_form_t pVar2;
  int iVar3;
  BIGNUM *pBVar4;
  int iVar5;
  EC_KEY *key;
  undefined4 uVar6;
  int iVar7;
  undefined4 local_28;
  void *local_24 [2];
  
  key = *(EC_KEY **)(param_2 + 0x18);
  local_28 = 0;
  local_24[0] = (void *)0x0;
  if ((key == (EC_KEY *)0x0) || (x = EC_KEY_get0_group(key), x == (EC_GROUP *)0x0)) {
    ERR_put_error(0x10,0xdd,0x43,"crypto/ec/ec_ameth.c",0x170);
    return 0;
  }
  pEVar1 = EC_KEY_get0_public_key(key);
  if (pEVar1 == (EC_POINT *)0x0) {
    iVar3 = 0;
LAB_00124944:
    pBVar4 = EC_KEY_get0_private_key(key);
    if (pBVar4 == (BIGNUM *)0x0) {
      iVar5 = BIO_indent(param_1,param_3,0x80);
      iVar7 = 0;
    }
    else {
      iVar7 = EC_KEY_priv2buf(key,&local_28);
      if (iVar7 == 0) goto LAB_00124904;
      iVar5 = BIO_indent(param_1,param_3,0x80);
    }
    if (iVar5 != 0) {
      uVar6 = EC_GROUP_order_bits(x);
      iVar5 = BIO_printf(param_1,"%s: (%d bit)\n","Private-Key",uVar6);
      if (((0 < iVar5) &&
          ((iVar7 == 0 ||
           ((iVar5 = BIO_printf(param_1,"%*spriv:\n",param_3,""), 0 < iVar5 &&
            (iVar5 = ASN1_buf_print(param_1,local_28,iVar7,param_3 + 4), iVar5 != 0)))))) &&
         ((iVar3 == 0 ||
          ((iVar5 = BIO_printf(param_1,"%*spub:\n",param_3,""), 0 < iVar5 &&
           (iVar3 = ASN1_buf_print(param_1,local_24[0],iVar3,param_3 + 4), iVar3 != 0)))))) {
        uVar6 = 1;
        iVar3 = ECPKParameters_print(param_1,x,param_3);
        if (iVar3 != 0) goto LAB_0012491c;
      }
    }
  }
  else {
    pVar2 = EC_KEY_get_conv_form(key);
    iVar3 = EC_KEY_key2buf(key,pVar2,local_24,0);
    if (iVar3 != 0) goto LAB_00124944;
LAB_00124904:
    iVar7 = 0;
  }
  uVar6 = 0;
  ERR_put_error(0x10,0xdd,0x10,"crypto/ec/ec_ameth.c",0x1a0);
LAB_0012491c:
  CRYPTO_clear_free(local_28,iVar7,"crypto/ec/ec_ameth.c",0x1a1);
  CRYPTO_free(local_24[0]);
  return uVar6;
}

