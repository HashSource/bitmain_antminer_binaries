
X509_EXTENSION * OCSP_url_svcloc_new(X509_NAME *issuer,char **urls)

{
  OCSP_SERVICELOC *a;
  X509_NAME *pXVar1;
  stack_st_ACCESS_DESCRIPTION *psVar2;
  int iVar3;
  ACCESS_DESCRIPTION *a_00;
  ASN1_OBJECT *pAVar4;
  char *pcVar5;
  GENERAL_NAME *pGVar6;
  ASN1_OBJECT *str;
  char **ppcVar7;
  
  a = OCSP_SERVICELOC_new();
  if (a != (OCSP_SERVICELOC *)0x0) {
    X509_NAME_free(a->issuer);
    pXVar1 = X509_NAME_dup(issuer);
    a->issuer = pXVar1;
    if (pXVar1 != (X509_NAME *)0x0) {
      if ((urls != (char **)0x0) && (*urls != (char *)0x0)) {
        psVar2 = (stack_st_ACCESS_DESCRIPTION *)OPENSSL_sk_new_null();
        a->locator = psVar2;
        if (psVar2 == (stack_st_ACCESS_DESCRIPTION *)0x0) goto LAB_0013ffe0;
        pcVar5 = *urls;
        while (pcVar5 != (char *)0x0) {
          a_00 = ACCESS_DESCRIPTION_new();
          if (a_00 == (ACCESS_DESCRIPTION *)0x0) goto LAB_0013ffe0;
          str = OBJ_nid2obj(0xb2);
          a_00->method = str;
          pAVar4 = str;
          if ((str == (ASN1_OBJECT *)0x0) ||
             (str = (ASN1_OBJECT *)ASN1_IA5STRING_new(), pAVar4 = str, str == (ASN1_OBJECT *)0x0))
          goto LAB_0013ffe6;
          ppcVar7 = urls + 1;
          iVar3 = ASN1_STRING_set((ASN1_STRING *)str,*urls,-1);
          if (iVar3 == 0) {
            pAVar4 = (ASN1_OBJECT *)0x0;
            goto LAB_0013ffe6;
          }
          pGVar6 = a_00->location;
          (pGVar6->d).rfc822Name = (ASN1_IA5STRING *)str;
          pGVar6->type = 6;
          str = (ASN1_OBJECT *)OPENSSL_sk_push(a->locator,a_00);
          pAVar4 = str;
          if (str == (ASN1_OBJECT *)0x0) goto LAB_0013ffe6;
          if (ppcVar7 == (char **)0x0) break;
          urls = ppcVar7;
          pcVar5 = *ppcVar7;
        }
      }
      a_00 = (ACCESS_DESCRIPTION *)0x0;
      str = (ASN1_OBJECT *)0x0;
      pAVar4 = (ASN1_OBJECT *)X509V3_EXT_i2d(0x173,0,a);
      goto LAB_0013ffe6;
    }
  }
LAB_0013ffe0:
  a_00 = (ACCESS_DESCRIPTION *)0x0;
  str = (ASN1_OBJECT *)0x0;
  pAVar4 = (ASN1_OBJECT *)0x0;
LAB_0013ffe6:
  ASN1_IA5STRING_free((ASN1_STRING *)str);
  ACCESS_DESCRIPTION_free(a_00);
  OCSP_SERVICELOC_free(a);
  return (X509_EXTENSION *)pAVar4;
}

