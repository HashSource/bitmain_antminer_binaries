
X509_EXTENSION * OCSP_crlID_new(char *url,long *n,char *tim)

{
  OCSP_CRLID *a;
  ASN1_IA5STRING *str;
  int iVar1;
  ASN1_INTEGER *a_00;
  ASN1_GENERALIZEDTIME *s;
  X509_EXTENSION *pXVar2;
  
  a = OCSP_CRLID_new();
  if (a != (OCSP_CRLID *)0x0) {
    if (url != (char *)0x0) {
      str = ASN1_IA5STRING_new();
      a->crlUrl = str;
      if ((str == (ASN1_IA5STRING *)0x0) || (iVar1 = ASN1_STRING_set(str,url,-1), iVar1 == 0))
      goto LAB_0014dcde;
    }
    if (n != (long *)0x0) {
      a_00 = ASN1_INTEGER_new();
      a->crlNum = a_00;
      if ((a_00 == (ASN1_INTEGER *)0x0) || (iVar1 = ASN1_INTEGER_set(a_00,*n), iVar1 == 0))
      goto LAB_0014dcde;
    }
    if (tim != (char *)0x0) {
      s = ASN1_GENERALIZEDTIME_new();
      a->crlTime = s;
      if ((s == (ASN1_GENERALIZEDTIME *)0x0) ||
         (iVar1 = ASN1_GENERALIZEDTIME_set_string(s,tim), iVar1 == 0)) goto LAB_0014dcde;
    }
    pXVar2 = X509V3_EXT_i2d(0x16f,0,a);
    OCSP_CRLID_free(a);
    return pXVar2;
  }
LAB_0014dcde:
  OCSP_CRLID_free(a);
  return (X509_EXTENSION *)0x0;
}

