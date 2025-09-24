
void asn1_enc_init(ASN1_VALUE **pval,ASN1_ITEM *it)

{
  ASN1_VALUE *pAVar1;
  void *pvVar2;
  ASN1_VALUE *pAVar3;
  
  if ((((pval != (ASN1_VALUE **)0x0) && (pAVar3 = *pval, pAVar3 != (ASN1_VALUE *)0x0)) &&
      (pvVar2 = it->funcs, pvVar2 != (void *)0x0)) && (*(int *)((int)pvVar2 + 4) << 0x1e < 0)) {
    pAVar1 = pAVar3 + *(int *)((int)pvVar2 + 0x14);
    if (pAVar1 != (ASN1_VALUE *)0x0) {
      *(undefined4 *)(pAVar3 + *(int *)((int)pvVar2 + 0x14)) = 0;
      *(undefined4 *)(pAVar1 + 8) = 1;
      *(undefined4 *)(pAVar1 + 4) = 0;
    }
  }
  return;
}

