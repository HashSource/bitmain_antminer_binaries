
int EC_KEY_print(BIO *bp,EC_KEY *key,int off)

{
  BIGNUM *pBVar1;
  EC_GROUP *x;
  EC_POINT *pEVar2;
  point_conversion_form_t pVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  char *pcVar7;
  int iVar8;
  undefined4 local_28;
  void *local_24 [2];
  
  pBVar1 = EC_KEY_get0_private_key(key);
  local_28 = 0;
  local_24[0] = (void *)0x0;
  if ((key == (EC_KEY *)0x0) || (x = EC_KEY_get0_group(key), x == (EC_GROUP *)0x0)) {
    ERR_put_error(0x10,0xdd,0x43,"crypto/ec/ec_ameth.c",0x170);
    return 0;
  }
  pEVar2 = EC_KEY_get0_public_key(key);
  if (pEVar2 == (EC_POINT *)0x0) {
    iVar4 = 0;
    iVar8 = 0;
    if (pBVar1 == (BIGNUM *)0x0) goto LAB_00116c64;
LAB_00116cbc:
    pBVar1 = EC_KEY_get0_private_key(key);
    if (pBVar1 == (BIGNUM *)0x0) {
      pBVar1 = (BIGNUM *)0x0;
    }
    else {
      pBVar1 = (BIGNUM *)EC_KEY_priv2buf(key,&local_28);
      if (pBVar1 == (BIGNUM *)0x0) goto LAB_00116cb2;
    }
    pcVar7 = "Private-Key";
    iVar8 = BIO_indent(bp,off,0x80);
    if (iVar8 == 0) goto LAB_00116c76;
LAB_00116ce6:
    uVar6 = EC_GROUP_order_bits(x);
    iVar8 = BIO_printf(bp,"%s: (%d bit)\n",pcVar7,uVar6);
    if (((0 < iVar8) &&
        ((pBVar1 == (BIGNUM *)0x0 ||
         ((iVar8 = BIO_printf(bp,"%*spriv:\n",off,""), 0 < iVar8 &&
          (iVar8 = ASN1_buf_print(bp,local_28,pBVar1,off + 4), iVar8 != 0)))))) &&
       ((iVar4 == 0 ||
        ((iVar8 = BIO_printf(bp,"%*spub:\n",off,""), 0 < iVar8 &&
         (iVar4 = ASN1_buf_print(bp,local_24[0],iVar4,off + 4), iVar4 != 0)))))) {
      iVar8 = 1;
      iVar4 = ECPKParameters_print(bp,x,off);
      if (iVar4 != 0) goto LAB_00116c8c;
    }
  }
  else {
    pVar3 = EC_KEY_get_conv_form(key);
    iVar4 = EC_KEY_key2buf(key,pVar3,local_24,0);
    if (iVar4 == 0) {
LAB_00116cb2:
      pBVar1 = (BIGNUM *)0x0;
    }
    else {
      iVar8 = iVar4;
      if (pBVar1 != (BIGNUM *)0x0) goto LAB_00116cbc;
LAB_00116c64:
      pcVar7 = "Public-Key";
      iVar5 = BIO_indent(bp,off,0x80);
      iVar4 = iVar8;
      if (iVar5 != 0) goto LAB_00116ce6;
    }
  }
LAB_00116c76:
  iVar8 = 0;
  ERR_put_error(0x10,0xdd,0x10,"crypto/ec/ec_ameth.c",0x1a0);
LAB_00116c8c:
  CRYPTO_clear_free(local_28,pBVar1,"crypto/ec/ec_ameth.c",0x1a1);
  CRYPTO_free(local_24[0]);
  return iVar8;
}

