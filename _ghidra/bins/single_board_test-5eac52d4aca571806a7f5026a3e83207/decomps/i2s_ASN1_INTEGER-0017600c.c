
char * i2s_ASN1_INTEGER(X509V3_EXT_METHOD *meth,ASN1_INTEGER *aint)

{
  BIGNUM *a;
  int iVar1;
  char *pcVar2;
  
  if (aint == (ASN1_INTEGER *)0x0) {
    return (char *)0x0;
  }
  a = ASN1_INTEGER_to_BN(aint,(BIGNUM *)0x0);
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
  ERR_put_error(0x22,0x78,0x41,"crypto/x509v3/v3_utl.c",0xbe);
  BN_free(a);
  return (char *)0x0;
}

