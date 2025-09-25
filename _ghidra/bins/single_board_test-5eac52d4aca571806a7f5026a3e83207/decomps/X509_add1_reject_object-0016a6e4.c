
int X509_add1_reject_object(X509 *x,ASN1_OBJECT *obj)

{
  ASN1_OBJECT *a;
  stack_st_ASN1_OBJECT *psVar1;
  int iVar2;
  X509_CERT_AUX *pXVar3;
  
  a = OBJ_dup(obj);
  if (a == (ASN1_OBJECT *)0x0) {
    return 0;
  }
  if (x == (X509 *)0x0) {
LAB_0016a712:
    ASN1_OBJECT_free(a);
    return 0;
  }
  pXVar3 = (X509_CERT_AUX *)x[1].rfc3779_asid;
  if (pXVar3 == (X509_CERT_AUX *)0x0) {
    pXVar3 = X509_CERT_AUX_new();
    x[1].rfc3779_asid = (ASIdentifiers_st *)pXVar3;
    if (pXVar3 == (X509_CERT_AUX *)0x0) goto LAB_0016a712;
  }
  psVar1 = pXVar3->reject;
  if (psVar1 == (stack_st_ASN1_OBJECT *)0x0) {
    psVar1 = (stack_st_ASN1_OBJECT *)OPENSSL_sk_new_null();
    pXVar3->reject = psVar1;
    if (psVar1 == (stack_st_ASN1_OBJECT *)0x0) goto LAB_0016a712;
  }
  iVar2 = OPENSSL_sk_push(psVar1,a);
  return iVar2;
}

