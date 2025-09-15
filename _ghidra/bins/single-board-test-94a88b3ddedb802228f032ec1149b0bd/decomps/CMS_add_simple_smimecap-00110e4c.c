
int CMS_add_simple_smimecap(stack_st_X509_ALGOR **algs,int algnid,int keysize)

{
  ASN1_INTEGER *a;
  int iVar1;
  X509_ALGOR *alg;
  ASN1_OBJECT *aobj;
  _STACK *st;
  
  if (keysize < 1) {
    alg = X509_ALGOR_new();
    if (alg == (X509_ALGOR *)0x0) {
      return 0;
    }
    a = (ASN1_INTEGER *)0x0;
    aobj = OBJ_nid2obj(algnid);
    iVar1 = -1;
  }
  else {
    a = ASN1_INTEGER_new();
    if (a == (ASN1_INTEGER *)0x0) {
      return 0;
    }
    iVar1 = ASN1_INTEGER_set(a,keysize);
    if (iVar1 == 0) {
      return 0;
    }
    alg = X509_ALGOR_new();
    if (alg == (X509_ALGOR *)0x0) {
      ASN1_INTEGER_free(a);
      return 0;
    }
    aobj = OBJ_nid2obj(algnid);
    iVar1 = 2;
  }
  X509_ALGOR_set0(alg,aobj,iVar1,a);
  st = &(*algs)->stack;
  if (st == (_STACK *)0x0) {
    st = sk_new_null();
    *algs = (stack_st_X509_ALGOR *)st;
    if (st == (_STACK *)0x0) goto LAB_00110e8c;
  }
  iVar1 = sk_push(st,alg);
  if (iVar1 != 0) {
    return 1;
  }
LAB_00110e8c:
  X509_ALGOR_free(alg);
  return 0;
}

