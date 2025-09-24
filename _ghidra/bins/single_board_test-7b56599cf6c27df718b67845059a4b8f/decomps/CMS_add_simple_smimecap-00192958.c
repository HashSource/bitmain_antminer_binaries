
int CMS_add_simple_smimecap(stack_st_X509_ALGOR **algs,int algnid,int keysize)

{
  ASN1_INTEGER *a;
  int iVar1;
  ASN1_STRING *alg;
  ASN1_OBJECT *aobj;
  stack_st_X509_ALGOR *psVar2;
  
  if (keysize < 1) {
    alg = (ASN1_STRING *)X509_ALGOR_new();
    a = alg;
    if (alg == (ASN1_STRING *)0x0) goto LAB_001929ac;
    a = (ASN1_INTEGER *)0x0;
    aobj = OBJ_nid2obj(algnid);
    iVar1 = -1;
  }
  else {
    a = ASN1_INTEGER_new();
    if (((a == (ASN1_INTEGER *)0x0) || (iVar1 = ASN1_INTEGER_set(a,keysize), iVar1 == 0)) ||
       (alg = (ASN1_STRING *)X509_ALGOR_new(), alg == (ASN1_STRING *)0x0)) {
LAB_001929ac:
      ASN1_INTEGER_free(a);
      return 0;
    }
    aobj = OBJ_nid2obj(algnid);
    iVar1 = 2;
  }
  X509_ALGOR_set0((X509_ALGOR *)alg,aobj,iVar1,a);
  psVar2 = *algs;
  if (psVar2 == (stack_st_X509_ALGOR *)0x0) {
    psVar2 = (stack_st_X509_ALGOR *)OPENSSL_sk_new_null();
    *algs = psVar2;
    if (psVar2 == (stack_st_X509_ALGOR *)0x0) goto LAB_00192998;
  }
  iVar1 = OPENSSL_sk_push(psVar2,alg);
  if (iVar1 != 0) {
    return 1;
  }
LAB_00192998:
  X509_ALGOR_free((X509_ALGOR *)alg);
  return 0;
}

