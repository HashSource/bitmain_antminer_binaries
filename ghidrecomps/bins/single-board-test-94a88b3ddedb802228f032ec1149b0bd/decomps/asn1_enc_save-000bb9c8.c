
int asn1_enc_save(ASN1_VALUE **pval,uchar *in,int inlen,ASN1_ITEM *it)

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
      pvVar1 = CRYPTO_malloc(inlen,DAT_000bba20,0xae);
      *(void **)(pAVar2 + iVar3) = pvVar1;
      if (pvVar1 != (void *)0x0) {
        memcpy(pvVar1,in,inlen);
        *(int *)(pAVar4 + 4) = inlen;
        *(undefined4 *)(pAVar4 + 8) = 0;
        return 1;
      }
      return 0;
    }
  }
  return 1;
}

