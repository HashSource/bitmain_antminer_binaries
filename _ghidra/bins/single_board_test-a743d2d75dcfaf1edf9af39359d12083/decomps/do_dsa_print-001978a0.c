
int do_dsa_print(BIO *param_1,int param_2,int param_3,int param_4)

{
  BIGNUM *a;
  int iVar1;
  uchar *buf;
  int iVar2;
  BIGNUM *a_00;
  BIGNUM *pBVar3;
  char *pcVar4;
  
  if (param_4 == 2) {
    a_00 = *(BIGNUM **)(param_2 + 0x1c);
    pBVar3 = *(BIGNUM **)(param_2 + 0x18);
    pcVar4 = "Private-Key";
  }
  else if (param_4 < 1) {
    a_00 = (BIGNUM *)0x0;
    pcVar4 = "DSA-Parameters";
    pBVar3 = a_00;
  }
  else {
    a_00 = (BIGNUM *)0x0;
    pBVar3 = *(BIGNUM **)(param_2 + 0x18);
    if (param_4 == 1) {
      pcVar4 = "Public-Key";
    }
    else {
      pcVar4 = "DSA-Parameters";
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
  if (pBVar3 != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(pBVar3);
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    if (a < (BIGNUM *)(iVar2 >> 3)) {
      a = (BIGNUM *)(iVar2 >> 3);
    }
  }
  buf = (uchar *)CRYPTO_malloc((int)((int)&a->dmax + 2),"dsa_ameth.c",0x1bd);
  if (buf == (uchar *)0x0) {
    ERR_put_error(10,0x68,0x41,"dsa_ameth.c",0x1bf);
    return 0;
  }
  if (a_00 == (BIGNUM *)0x0) {
LAB_00197996:
    iVar2 = ASN1_bn_print(param_1,"priv:",a_00,buf,param_3);
    if ((((iVar2 != 0) && (iVar2 = ASN1_bn_print(param_1,"pub: ",pBVar3,buf,param_3), iVar2 != 0))
        && (iVar2 = ASN1_bn_print(param_1,"P:   ",*(BIGNUM **)(param_2 + 0xc),buf,param_3),
           iVar2 != 0)) &&
       (iVar2 = ASN1_bn_print(param_1,"Q:   ",*(BIGNUM **)(param_2 + 0x10),buf,param_3), iVar2 != 0)
       ) {
      iVar2 = ASN1_bn_print(param_1,"G:   ",*(BIGNUM **)(param_2 + 0x14),buf,param_3);
      if (iVar2 != 0) {
        iVar2 = 1;
      }
      goto LAB_00197968;
    }
  }
  else {
    iVar2 = BIO_indent(param_1,param_3,0x80);
    if (iVar2 != 0) {
      iVar2 = BN_num_bits(*(BIGNUM **)(param_2 + 0xc));
      iVar2 = BIO_printf(param_1,"%s: (%d bit)\n",pcVar4,iVar2);
      if (0 < iVar2) goto LAB_00197996;
    }
  }
  iVar2 = 0;
LAB_00197968:
  CRYPTO_free(buf);
  return iVar2;
}

