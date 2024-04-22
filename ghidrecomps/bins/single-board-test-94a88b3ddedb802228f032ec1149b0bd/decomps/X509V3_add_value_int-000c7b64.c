
int X509V3_add_value_int(char *name,ASN1_INTEGER *aint,stack_st_CONF_VALUE **extlist)

{
  BIGNUM *a;
  char *value;
  int iVar1;
  
  if (aint == (ASN1_INTEGER *)0x0) {
    iVar1 = 1;
  }
  else {
    a = ASN1_INTEGER_to_BN(aint,(BIGNUM *)0x0);
    if ((a == (BIGNUM *)0x0) || (value = BN_bn2dec(a), value == (char *)0x0)) {
      ERR_put_error(0x22,0x78,0x41,DAT_000c7bc0,0xaa);
      iVar1 = 0;
      BN_free(a);
    }
    else {
      BN_free(a);
      iVar1 = X509V3_add_value(name,value,extlist);
      CRYPTO_free(value);
    }
  }
  return iVar1;
}

