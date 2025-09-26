
X509_EXTENSION * OCSP_accept_responses_new(char **oids)

{
  void *ext_struc;
  char *s;
  int n;
  X509_EXTENSION *pXVar1;
  ASN1_OBJECT *pAVar2;
  char **ppcVar3;
  
  ext_struc = (void *)OPENSSL_sk_new_null();
  if (ext_struc == (void *)0x0) {
    pXVar1 = (X509_EXTENSION *)0x0;
  }
  else {
    if ((oids != (char **)0x0) && (s = *oids, s != (char *)0x0)) {
      ppcVar3 = oids + 1;
      do {
        n = OBJ_txt2nid(s);
        if ((n != 0) && (pAVar2 = OBJ_nid2obj(n), pAVar2 != (ASN1_OBJECT *)0x0)) {
          OPENSSL_sk_push(ext_struc,pAVar2);
        }
        if (ppcVar3 == (char **)0x0) break;
        s = *ppcVar3;
        ppcVar3 = ppcVar3 + 1;
      } while (s != (char *)0x0);
    }
    pXVar1 = X509V3_EXT_i2d(0x170,0,ext_struc);
  }
  OPENSSL_sk_pop_free(ext_struc,0x18981d);
  return pXVar1;
}

