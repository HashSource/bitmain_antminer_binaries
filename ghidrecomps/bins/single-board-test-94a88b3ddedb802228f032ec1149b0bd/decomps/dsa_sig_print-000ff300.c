
uint dsa_sig_print(BIO *param_1,undefined4 param_2,ASN1_STRING *param_3,int param_4)

{
  DSA_SIG *a;
  BIGNUM *a_00;
  int iVar1;
  uchar *buf;
  int iVar2;
  uint uVar3;
  uchar *local_1c;
  
  if (param_3 == (ASN1_STRING *)0x0) {
    iVar2 = BIO_puts(param_1,DAT_000ff3f4);
    uVar3 = (uint)(0 < iVar2);
  }
  else {
    local_1c = param_3->data;
    a = d2i_DSA_SIG((DSA_SIG **)0x0,&local_1c,param_3->length);
    if (a == (DSA_SIG *)0x0) {
      uVar3 = X509_signature_dump(param_1,param_3,param_4);
    }
    else {
      a_00 = a->r;
      if (a_00 != (BIGNUM *)0x0) {
        iVar1 = BN_num_bits(a_00);
        iVar2 = iVar1 + 0xe;
        if (-1 < iVar1 + 7) {
          iVar2 = iVar1 + 7;
        }
        a_00 = (BIGNUM *)(iVar2 >> 3);
      }
      if (a->s != (BIGNUM *)0x0) {
        iVar1 = BN_num_bits(a->s);
        iVar2 = iVar1 + 7;
        if (iVar1 + 7 < 0) {
          iVar2 = iVar1 + 0xe;
        }
        if (a_00 < (BIGNUM *)(iVar2 >> 3)) {
          a_00 = (BIGNUM *)(iVar2 >> 3);
        }
      }
      buf = (uchar *)CRYPTO_malloc((int)((int)&a_00->dmax + 2),DAT_000ff3f0,0x223);
      if (buf == (uchar *)0x0) {
        ERR_put_error(10,0x7d,0x41,DAT_000ff3f0,0x225);
        uVar3 = 0;
      }
      else {
        iVar2 = BIO_write(param_1,DAT_000ff3f4,1);
        if ((iVar2 == 1) &&
           (iVar2 = ASN1_bn_print(param_1,DAT_000ff3f8,a->r,buf,param_4), iVar2 != 0)) {
          uVar3 = ASN1_bn_print(param_1,DAT_000ff3fc,a->s,buf,param_4);
          if (uVar3 != 0) {
            uVar3 = 1;
          }
        }
        else {
          uVar3 = 0;
        }
        CRYPTO_free(buf);
      }
      DSA_SIG_free(a);
    }
  }
  return uVar3;
}

