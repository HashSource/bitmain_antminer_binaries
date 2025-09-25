
int asn1_enc_restore(int *len,uchar **out,ASN1_VALUE **pval,ASN1_ITEM *it)

{
  ASN1_VALUE *pAVar1;
  ASN1_VALUE *pAVar2;
  ASN1_VALUE *pAVar3;
  ASN1_VALUE *pAVar4;
  
  if (pval == (ASN1_VALUE **)0x0) {
    return 0;
  }
  pAVar4 = *pval;
  pAVar1 = pAVar4;
  if (((pAVar4 != (ASN1_VALUE *)0x0) &&
      (pAVar2 = (ASN1_VALUE *)it->funcs, pAVar1 = pAVar2, pAVar2 != (ASN1_VALUE *)0x0)) &&
     (pAVar1 = (ASN1_VALUE *)(*(uint *)(pAVar2 + 4) & 2), pAVar1 != (ASN1_VALUE *)0x0)) {
    pAVar3 = pAVar4 + *(int *)(pAVar2 + 0x14);
    if (pAVar3 == (ASN1_VALUE *)0x0) {
      pAVar1 = (ASN1_VALUE *)0x0;
    }
    else {
      if (*(int *)(pAVar3 + 8) != 0) {
        return 0;
      }
      if (out != (uchar **)0x0) {
        memcpy(*out,*(void **)(pAVar4 + *(int *)(pAVar2 + 0x14)),*(size_t *)(pAVar3 + 4));
        *out = *out + *(int *)(pAVar3 + 4);
      }
      if (len == (int *)0x0) {
        pAVar1 = (ASN1_VALUE *)0x1;
      }
      else {
        pAVar1 = (ASN1_VALUE *)0x1;
        *len = *(int *)(pAVar3 + 4);
      }
    }
  }
  return (int)pAVar1;
}

