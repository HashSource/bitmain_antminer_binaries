
void asn1_enc_init(ASN1_VALUE **pval,ASN1_ITEM *it)

{
  int *piVar1;
  ASN1_VALUE *pAVar2;
  void *pvVar3;
  ASN1_VALUE *pAVar4;
  undefined4 unaff_r4;
  bool bVar5;
  
  if ((((pval != (ASN1_VALUE **)0x0) && (pAVar4 = *pval, pAVar4 != (ASN1_VALUE *)0x0)) &&
      (pvVar3 = it->funcs, pvVar3 != (void *)0x0)) && (*(int *)((int)pvVar3 + 4) << 0x1e < 0)) {
    piVar1 = (int *)((int)pvVar3 + 0x14);
    pAVar2 = pAVar4 + *piVar1;
    bVar5 = pAVar2 != (ASN1_VALUE *)0x0;
    if (bVar5) {
      pvVar3 = (void *)0x0;
      unaff_r4 = 1;
    }
    if (bVar5) {
      *(void **)(pAVar4 + *piVar1) = pvVar3;
    }
    if (bVar5) {
      *(void **)(pAVar2 + 4) = pvVar3;
    }
    if (bVar5) {
      *(undefined4 *)(pAVar2 + 8) = unaff_r4;
    }
  }
  return;
}

