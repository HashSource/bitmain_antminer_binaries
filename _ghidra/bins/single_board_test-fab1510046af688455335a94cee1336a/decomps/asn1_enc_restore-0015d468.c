
int asn1_enc_restore(int *len,uchar **out,ASN1_VALUE **pval,ASN1_ITEM *it)

{
  void *pvVar1;
  ASN1_VALUE *pAVar2;
  ASN1_VALUE *pAVar3;
  
  if ((((pval != (ASN1_VALUE **)0x0) && (pAVar2 = *pval, pAVar2 != (ASN1_VALUE *)0x0)) &&
      (pvVar1 = it->funcs, pvVar1 != (void *)0x0)) && ((*(uint *)((int)pvVar1 + 4) & 2) != 0)) {
    pAVar3 = pAVar2 + *(int *)((int)pvVar1 + 0x14);
    if ((pAVar3 != (ASN1_VALUE *)0x0) && (*(int *)(pAVar3 + 8) == 0)) {
      if (out != (uchar **)0x0) {
        memcpy(*out,*(void **)(pAVar2 + *(int *)((int)pvVar1 + 0x14)),*(size_t *)(pAVar3 + 4));
        *out = *out + *(int *)(pAVar3 + 4);
      }
      if (len != (int *)0x0) {
        *len = *(int *)(pAVar3 + 4);
        return 1;
      }
      return 1;
    }
  }
  return 0;
}

