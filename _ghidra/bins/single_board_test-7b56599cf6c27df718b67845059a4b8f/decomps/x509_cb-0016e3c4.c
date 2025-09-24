
int x509_cb(int param_1,undefined4 *param_2)

{
  int iVar1;
  void *obj;
  
  obj = (void *)*param_2;
  if (param_1 == 3) {
    CRYPTO_free_ex_data(3,obj,(CRYPTO_EX_DATA *)((int)obj + 0x74));
    X509_CERT_AUX_free(*(X509_CERT_AUX **)((int)obj + 0xc4));
    ASN1_OCTET_STRING_free(*(ASN1_STRING **)((int)obj + 0x90));
    AUTHORITY_KEYID_free(*(AUTHORITY_KEYID **)((int)obj + 0x94));
    CRL_DIST_POINTS_free(*(CRL_DIST_POINTS **)((int)obj + 0x9c));
    policy_cache_free(*(undefined4 *)((int)obj + 0x98));
    GENERAL_NAMES_free(*(GENERAL_NAMES **)((int)obj + 0xa0));
    NAME_CONSTRAINTS_free(*(NAME_CONSTRAINTS **)((int)obj + 0xa4));
    OPENSSL_sk_pop_free(*(undefined4 *)((int)obj + 0xa8),0x16f869);
    ASIdentifiers_free(*(ASIdentifiers **)((int)obj + 0xac));
    return 1;
  }
  if (param_1 == 4) {
    CRYPTO_free_ex_data(3,obj,(CRYPTO_EX_DATA *)((int)obj + 0x74));
    X509_CERT_AUX_free(*(X509_CERT_AUX **)((int)obj + 0xc4));
    ASN1_OCTET_STRING_free(*(ASN1_STRING **)((int)obj + 0x90));
    AUTHORITY_KEYID_free(*(AUTHORITY_KEYID **)((int)obj + 0x94));
    CRL_DIST_POINTS_free(*(CRL_DIST_POINTS **)((int)obj + 0x9c));
    policy_cache_free(*(undefined4 *)((int)obj + 0x98));
    GENERAL_NAMES_free(*(GENERAL_NAMES **)((int)obj + 0xa0));
    NAME_CONSTRAINTS_free(*(NAME_CONSTRAINTS **)((int)obj + 0xa4));
    OPENSSL_sk_pop_free(*(undefined4 *)((int)obj + 0xa8),0x16f869);
    ASIdentifiers_free(*(ASIdentifiers **)((int)obj + 0xac));
  }
  else if (param_1 != 1) {
    return 1;
  }
  *(undefined4 *)((int)obj + 0xcc) = 0;
  *(undefined4 *)((int)obj + 0x84) = 0;
  *(undefined4 *)((int)obj + 0x88) = 0;
  *(undefined4 *)((int)obj + 0x8c) = 0;
  *(undefined4 *)((int)obj + 0x80) = 0;
  *(undefined4 *)((int)obj + 0x90) = 0;
  *(undefined4 *)((int)obj + 0x94) = 0;
  *(undefined4 *)((int)obj + 0x98) = 0;
  *(undefined4 *)((int)obj + 0xa0) = 0;
  *(undefined4 *)((int)obj + 0xa4) = 0;
  *(undefined4 *)((int)obj + 0xa8) = 0;
  *(undefined4 *)((int)obj + 0xac) = 0;
  *(undefined4 *)((int)obj + 0xc4) = 0;
  *(undefined4 *)((int)obj + 0x9c) = 0;
  *(undefined4 *)((int)obj + 0x78) = 0xffffffff;
  *(undefined4 *)((int)obj + 0x7c) = 0xffffffff;
  iVar1 = CRYPTO_new_ex_data(3,obj,(CRYPTO_EX_DATA *)((int)obj + 0x74));
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

