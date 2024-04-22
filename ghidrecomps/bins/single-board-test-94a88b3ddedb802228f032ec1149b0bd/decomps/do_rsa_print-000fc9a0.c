
int do_rsa_print(BIO *param_1,int param_2,int param_3,int param_4)

{
  char *number;
  char *number_00;
  BIGNUM *pBVar1;
  int iVar2;
  uchar *buf;
  int iVar3;
  
  pBVar1 = *(BIGNUM **)(param_2 + 0x10);
  if (pBVar1 != (BIGNUM *)0x0) {
    iVar2 = BN_num_bits(pBVar1);
    iVar3 = iVar2 + 0xe;
    if (-1 < iVar2 + 7) {
      iVar3 = iVar2 + 7;
    }
    pBVar1 = (BIGNUM *)(iVar3 >> 3);
  }
  if (*(BIGNUM **)(param_2 + 0x14) != (BIGNUM *)0x0) {
    iVar2 = BN_num_bits(*(BIGNUM **)(param_2 + 0x14));
    iVar3 = iVar2 + 7;
    if (iVar2 + 7 < 0) {
      iVar3 = iVar2 + 0xe;
    }
    if (pBVar1 < (BIGNUM *)(iVar3 >> 3)) {
      pBVar1 = (BIGNUM *)(iVar3 >> 3);
    }
  }
  if (param_4 != 0) {
    if (*(BIGNUM **)(param_2 + 0x18) != (BIGNUM *)0x0) {
      iVar2 = BN_num_bits(*(BIGNUM **)(param_2 + 0x18));
      iVar3 = iVar2 + 7;
      if (iVar2 + 7 < 0) {
        iVar3 = iVar2 + 0xe;
      }
      if (pBVar1 < (BIGNUM *)(iVar3 >> 3)) {
        pBVar1 = (BIGNUM *)(iVar3 >> 3);
      }
    }
    if (*(BIGNUM **)(param_2 + 0x1c) != (BIGNUM *)0x0) {
      iVar2 = BN_num_bits(*(BIGNUM **)(param_2 + 0x1c));
      iVar3 = iVar2 + 7;
      if (iVar2 + 7 < 0) {
        iVar3 = iVar2 + 0xe;
      }
      if (pBVar1 < (BIGNUM *)(iVar3 >> 3)) {
        pBVar1 = (BIGNUM *)(iVar3 >> 3);
      }
    }
    if (*(BIGNUM **)(param_2 + 0x20) != (BIGNUM *)0x0) {
      iVar2 = BN_num_bits(*(BIGNUM **)(param_2 + 0x20));
      iVar3 = iVar2 + 7;
      if (iVar2 + 7 < 0) {
        iVar3 = iVar2 + 0xe;
      }
      if (pBVar1 < (BIGNUM *)(iVar3 >> 3)) {
        pBVar1 = (BIGNUM *)(iVar3 >> 3);
      }
    }
    if (*(BIGNUM **)(param_2 + 0x24) != (BIGNUM *)0x0) {
      iVar2 = BN_num_bits(*(BIGNUM **)(param_2 + 0x24));
      iVar3 = iVar2 + 7;
      if (iVar2 + 7 < 0) {
        iVar3 = iVar2 + 0xe;
      }
      if (pBVar1 < (BIGNUM *)(iVar3 >> 3)) {
        pBVar1 = (BIGNUM *)(iVar3 >> 3);
      }
    }
    if (*(BIGNUM **)(param_2 + 0x28) != (BIGNUM *)0x0) {
      iVar2 = BN_num_bits(*(BIGNUM **)(param_2 + 0x28));
      iVar3 = iVar2 + 7;
      if (iVar2 + 7 < 0) {
        iVar3 = iVar2 + 0xe;
      }
      if (pBVar1 < (BIGNUM *)(iVar3 >> 3)) {
        pBVar1 = (BIGNUM *)(iVar3 >> 3);
      }
    }
    if (*(BIGNUM **)(param_2 + 0x2c) != (BIGNUM *)0x0) {
      iVar2 = BN_num_bits(*(BIGNUM **)(param_2 + 0x2c));
      iVar3 = iVar2 + 7;
      if (iVar2 + 7 < 0) {
        iVar3 = iVar2 + 0xe;
      }
      if (pBVar1 < (BIGNUM *)(iVar3 >> 3)) {
        pBVar1 = (BIGNUM *)(iVar3 >> 3);
      }
    }
  }
  buf = (uchar *)CRYPTO_malloc((int)((int)&pBVar1->dmax + 2),DAT_000fcbbc,0xcc);
  if (buf == (uchar *)0x0) {
    ERR_put_error(4,0x92,0x41,DAT_000fcbbc,0xce);
    return 0;
  }
  pBVar1 = *(BIGNUM **)(param_2 + 0x10);
  if (pBVar1 != (BIGNUM *)0x0) {
    pBVar1 = (BIGNUM *)BN_num_bits(pBVar1);
  }
  iVar3 = BIO_indent(param_1,param_3,0x80);
  if (iVar3 != 0) {
    if ((param_4 == 0) || (*(int *)(param_2 + 0x18) == 0)) {
      iVar3 = BIO_printf(param_1,DAT_000fcbcc,pBVar1);
      number = DAT_000fcbd0;
      number_00 = DAT_000fcbd4;
    }
    else {
      iVar3 = BIO_printf(param_1,DAT_000fcbc0,pBVar1);
      number = DAT_000fcbc4;
      number_00 = DAT_000fcbc8;
    }
    if (((0 < iVar3) &&
        (iVar3 = ASN1_bn_print(param_1,number_00,*(BIGNUM **)(param_2 + 0x10),buf,param_3),
        iVar3 != 0)) &&
       (iVar3 = ASN1_bn_print(param_1,number,*(BIGNUM **)(param_2 + 0x14),buf,param_3), iVar3 != 0))
    {
      if (param_4 == 0) {
        iVar3 = 1;
        goto LAB_000fca12;
      }
      iVar3 = ASN1_bn_print(param_1,DAT_000fcbd8,*(BIGNUM **)(param_2 + 0x18),buf,param_3);
      if (((iVar3 != 0) &&
          (iVar3 = ASN1_bn_print(param_1,DAT_000fcbdc,*(BIGNUM **)(param_2 + 0x1c),buf,param_3),
          iVar3 != 0)) &&
         ((iVar3 = ASN1_bn_print(param_1,DAT_000fcbe0,*(BIGNUM **)(param_2 + 0x20),buf,param_3),
          iVar3 != 0 &&
          ((iVar3 = ASN1_bn_print(param_1,DAT_000fcbe4,*(BIGNUM **)(param_2 + 0x24),buf,param_3),
           iVar3 != 0 &&
           (iVar3 = ASN1_bn_print(param_1,DAT_000fcbe8,*(BIGNUM **)(param_2 + 0x28),buf,param_3),
           iVar3 != 0)))))) {
        iVar3 = ASN1_bn_print(param_1,DAT_000fcbec,*(BIGNUM **)(param_2 + 0x2c),buf,param_3);
        if (iVar3 != 0) {
          iVar3 = 1;
        }
        goto LAB_000fca12;
      }
    }
  }
  iVar3 = 0;
LAB_000fca12:
  CRYPTO_free(buf);
  return iVar3;
}

