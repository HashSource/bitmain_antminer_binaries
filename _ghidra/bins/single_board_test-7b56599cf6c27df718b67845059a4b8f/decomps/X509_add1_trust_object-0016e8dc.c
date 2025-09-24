
int X509_add1_trust_object(X509 *x,ASN1_OBJECT *obj)

{
  ASN1_OBJECT *a;
  ASIdentifierChoice *pAVar1;
  int iVar2;
  X509_CERT_AUX *pXVar3;
  
  if (obj == (ASN1_OBJECT *)0x0) {
    a = (ASN1_OBJECT *)0x0;
  }
  else {
    a = OBJ_dup(obj);
    if (a == (ASN1_OBJECT *)0x0) {
      return 0;
    }
  }
  if (x != (X509 *)0x0) {
    pXVar3 = (X509_CERT_AUX *)x[1].rfc3779_asid;
    if (pXVar3 == (X509_CERT_AUX *)0x0) {
      pXVar3 = X509_CERT_AUX_new();
      x[1].rfc3779_asid = (ASIdentifiers_st *)pXVar3;
      if (pXVar3 == (X509_CERT_AUX *)0x0) goto LAB_0016e902;
    }
    pAVar1 = (ASIdentifierChoice *)pXVar3->trust;
    if (pAVar1 == (ASIdentifierChoice *)0x0) {
      pAVar1 = (ASIdentifierChoice *)OPENSSL_sk_new_null();
      pXVar3->trust = (stack_st_ASN1_OBJECT *)pAVar1;
      if (pAVar1 == (ASIdentifierChoice *)0x0) goto LAB_0016e902;
    }
    if ((a == (ASN1_OBJECT *)0x0) || (iVar2 = OPENSSL_sk_push(pAVar1,a), iVar2 != 0)) {
      return 1;
    }
  }
LAB_0016e902:
  ASN1_OBJECT_free(a);
  return 0;
}

