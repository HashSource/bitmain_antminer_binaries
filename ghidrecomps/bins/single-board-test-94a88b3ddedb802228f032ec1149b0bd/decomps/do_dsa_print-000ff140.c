
int do_dsa_print(BIO *param_1,int param_2,int param_3,int param_4)

{
  BIGNUM *a;
  int iVar1;
  uchar *buf;
  int iVar2;
  BIGNUM *a_00;
  BIGNUM *a_01;
  undefined4 uVar3;
  
  if (param_4 == 2) {
    a_00 = *(BIGNUM **)(param_2 + 0x1c);
    a_01 = *(BIGNUM **)(param_2 + 0x18);
    uVar3 = DAT_000ff2e4;
  }
  else if (param_4 < 1) {
    a_00 = (BIGNUM *)0x0;
    a_01 = a_00;
    uVar3 = DAT_000ff2c4;
  }
  else {
    a_00 = (BIGNUM *)0x0;
    a_01 = *(BIGNUM **)(param_2 + 0x18);
    uVar3 = DAT_000ff2c0;
    if (param_4 != 1) {
      uVar3 = DAT_000ff2c4;
    }
  }
  a = *(BIGNUM **)(param_2 + 0xc);
  if (a != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(a);
    iVar2 = iVar1 + 0xe;
    if (-1 < iVar1 + 7) {
      iVar2 = iVar1 + 7;
    }
    a = (BIGNUM *)(iVar2 >> 3);
  }
  if (*(BIGNUM **)(param_2 + 0x10) != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(*(BIGNUM **)(param_2 + 0x10));
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    if (a < (BIGNUM *)(iVar2 >> 3)) {
      a = (BIGNUM *)(iVar2 >> 3);
    }
  }
  if (*(BIGNUM **)(param_2 + 0x14) != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(*(BIGNUM **)(param_2 + 0x14));
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    if (a < (BIGNUM *)(iVar2 >> 3)) {
      a = (BIGNUM *)(iVar2 >> 3);
    }
  }
  if (a_00 != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(a_00);
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    if (a < (BIGNUM *)(iVar2 >> 3)) {
      a = (BIGNUM *)(iVar2 >> 3);
    }
  }
  if (a_01 != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(a_01);
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    if (a < (BIGNUM *)(iVar2 >> 3)) {
      a = (BIGNUM *)(iVar2 >> 3);
    }
  }
  buf = (uchar *)CRYPTO_malloc((int)((int)&a->dmax + 2),DAT_000ff2c8,0x1bd);
  if (buf == (uchar *)0x0) {
    ERR_put_error(10,0x68,0x41,DAT_000ff2c8,0x1bf);
    return 0;
  }
  if (a_00 == (BIGNUM *)0x0) {
LAB_000ff236:
    iVar2 = ASN1_bn_print(param_1,DAT_000ff2d0,a_00,buf,param_3);
    if ((((iVar2 != 0) && (iVar2 = ASN1_bn_print(param_1,DAT_000ff2d4,a_01,buf,param_3), iVar2 != 0)
         ) && (iVar2 = ASN1_bn_print(param_1,DAT_000ff2d8,*(BIGNUM **)(param_2 + 0xc),buf,param_3),
              iVar2 != 0)) &&
       (iVar2 = ASN1_bn_print(param_1,DAT_000ff2dc,*(BIGNUM **)(param_2 + 0x10),buf,param_3),
       iVar2 != 0)) {
      iVar2 = ASN1_bn_print(param_1,DAT_000ff2e0,*(BIGNUM **)(param_2 + 0x14),buf,param_3);
      if (iVar2 != 0) {
        iVar2 = 1;
      }
      goto LAB_000ff208;
    }
  }
  else {
    iVar2 = BIO_indent(param_1,param_3,0x80);
    if (iVar2 != 0) {
      iVar2 = BN_num_bits(*(BIGNUM **)(param_2 + 0xc));
      iVar2 = BIO_printf(param_1,DAT_000ff2cc,uVar3,iVar2);
      if (0 < iVar2) goto LAB_000ff236;
    }
  }
  iVar2 = 0;
LAB_000ff208:
  CRYPTO_free(buf);
  return iVar2;
}

