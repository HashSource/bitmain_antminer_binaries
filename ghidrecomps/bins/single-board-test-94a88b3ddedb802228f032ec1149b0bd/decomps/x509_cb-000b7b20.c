
undefined4 x509_cb(int param_1,int **param_2)

{
  char *pcVar1;
  int *obj;
  
  obj = *param_2;
  if (param_1 == 3) {
    CRYPTO_free_ex_data(10,obj,(CRYPTO_EX_DATA *)(obj + 6));
    X509_CERT_AUX_free((X509_CERT_AUX *)obj[0x19]);
    ASN1_OCTET_STRING_free((ASN1_OCTET_STRING *)obj[0xe]);
    AUTHORITY_KEYID_free((AUTHORITY_KEYID *)obj[0xf]);
    CRL_DIST_POINTS_free((CRL_DIST_POINTS *)obj[0x11]);
    policy_cache_free(obj[0x10]);
    GENERAL_NAMES_free((GENERAL_NAMES *)obj[0x12]);
    NAME_CONSTRAINTS_free((NAME_CONSTRAINTS *)obj[0x13]);
    if ((void *)obj[5] != (void *)0x0) {
      CRYPTO_free((void *)obj[5]);
      return 1;
    }
  }
  else {
    if (param_1 == 5) {
      if ((void *)obj[5] != (void *)0x0) {
        CRYPTO_free((void *)obj[5]);
      }
      pcVar1 = X509_NAME_oneline(*(X509_NAME **)(*obj + 0x14),(char *)0x0,0);
      obj[5] = (int)pcVar1;
      return 1;
    }
    if (param_1 == 1) {
      obj[3] = 0;
      obj[5] = 0;
      obj[10] = 0;
      obj[0xe] = 0;
      obj[0xf] = 0;
      obj[0x19] = 0;
      obj[0x11] = 0;
      obj[8] = -1;
      CRYPTO_new_ex_data(10,obj,(CRYPTO_EX_DATA *)(obj + 6));
      return 1;
    }
  }
  return 1;
}

