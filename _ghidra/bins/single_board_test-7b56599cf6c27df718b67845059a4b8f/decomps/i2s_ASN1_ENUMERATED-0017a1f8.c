
char * i2s_ASN1_ENUMERATED(X509V3_EXT_METHOD *meth,ASN1_ENUMERATED *aint)

{
  BIGNUM *a;
  int iVar1;
  char *pcVar2;
  
  if (aint == (ASN1_ENUMERATED *)0x0) {
    return (char *)0x0;
  }
  a = ASN1_ENUMERATED_to_BN(aint,(BIGNUM *)0x0);
  if (a != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(a);
    if (iVar1 < 0x80) {
      pcVar2 = BN_bn2dec(a);
    }
    else {
      pcVar2 = (char *)bignum_to_string_part_0();
    }
    if (pcVar2 != (char *)0x0) {
      BN_free(a);
      return pcVar2;
    }
  }
  ERR_put_error(0x22,0x79,0x41,"crypto/x509v3/v3_utl.c",0xb0);
  BN_free(a);
  return (char *)0x0;
}

