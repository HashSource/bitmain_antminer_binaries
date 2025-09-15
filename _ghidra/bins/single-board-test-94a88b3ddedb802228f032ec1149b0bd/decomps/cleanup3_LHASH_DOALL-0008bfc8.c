
void cleanup3_LHASH_DOALL(void *param_1)

{
  ASN1_OBJECT *a;
  int iVar1;
  
  a = *(ASN1_OBJECT **)((int)param_1 + 4);
  iVar1 = a->nid + -1;
  a->nid = iVar1;
  if (iVar1 == 0) {
    ASN1_OBJECT_free(a);
  }
  CRYPTO_free(param_1);
  return;
}

