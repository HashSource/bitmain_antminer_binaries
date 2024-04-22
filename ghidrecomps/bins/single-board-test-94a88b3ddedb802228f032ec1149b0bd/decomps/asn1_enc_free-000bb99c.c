
void asn1_enc_free(ASN1_VALUE **pval,ASN1_ITEM *it)

{
  void *pvVar1;
  ASN1_VALUE *pAVar2;
  int iVar3;
  ASN1_VALUE *pAVar4;
  
  if ((((pval != (ASN1_VALUE **)0x0) && (pAVar2 = *pval, pAVar2 != (ASN1_VALUE *)0x0)) &&
      (pvVar1 = it->funcs, pvVar1 != (void *)0x0)) && (*(int *)((int)pvVar1 + 4) << 0x1e < 0)) {
    iVar3 = *(int *)((int)pvVar1 + 0x14);
    pAVar4 = pAVar2 + iVar3;
    if (pAVar4 != (ASN1_VALUE *)0x0) {
      if (*(void **)(pAVar2 + iVar3) != (void *)0x0) {
        CRYPTO_free(*(void **)(pAVar2 + iVar3));
      }
      *(undefined4 *)(pAVar2 + iVar3) = 0;
      *(undefined4 *)(pAVar4 + 4) = 0;
      *(undefined4 *)(pAVar4 + 8) = 1;
    }
  }
  return;
}

