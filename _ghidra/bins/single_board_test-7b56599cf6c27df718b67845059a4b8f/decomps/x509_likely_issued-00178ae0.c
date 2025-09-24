
int x509_likely_issued(X509 *param_1,X509 *param_2)

{
  X509_NAME *a;
  X509_NAME *b;
  int iVar1;
  EVP_PKEY *pkey;
  int iVar2;
  int local_18;
  int local_14;
  
  a = X509_get_subject_name(param_1);
  b = X509_get_issuer_name(param_2);
  iVar1 = X509_NAME_cmp(a,b);
  iVar2 = 0x1d;
  if (iVar1 == 0) {
    x509v3_cache_extensions(param_1);
    if ((param_1[1].references << 0x18 < 0) ||
       (x509v3_cache_extensions(param_2), param_2[1].references << 0x18 < 0)) {
      return 1;
    }
    if (((AUTHORITY_KEYID *)param_2[1].ex_pcpathlen == (AUTHORITY_KEYID *)0x0) ||
       (iVar2 = X509_check_akid(param_1,(AUTHORITY_KEYID *)param_2[1].ex_pcpathlen), iVar2 == 0)) {
      pkey = (EVP_PKEY *)X509_get0_pubkey(param_1);
      if (pkey == (EVP_PKEY *)0x0) {
        iVar2 = 0x4d;
      }
      else {
        iVar2 = EVP_PKEY_base_id(pkey);
        iVar2 = OBJ_find_sigid_algs(iVar2,(int *)0x0,&local_18);
        if (iVar2 == 0) {
          local_18 = EVP_PKEY_base_id(pkey);
        }
        iVar2 = OBJ_obj2nid((ASN1_OBJECT *)param_2->name);
        iVar2 = OBJ_find_sigid_algs(iVar2,(int *)0x0,&local_14);
        if (iVar2 == 0) {
          iVar2 = 0x4e;
        }
        else {
          iVar1 = EVP_PKEY_type(local_14);
          iVar2 = 0;
          if (iVar1 != local_18) {
            iVar2 = 0x4c;
          }
        }
      }
    }
  }
  return iVar2;
}

