
int ASN1_STRING_TABLE_add(int param_1,long param_2,long param_3,ulong param_4,ulong param_5)

{
  ASN1_STRING_TABLE *pAVar1;
  ASN1_STRING_TABLE *ptr;
  int iVar2;
  long lVar3;
  long lVar4;
  uint uVar5;
  ulong uVar6;
  
  if ((stable != 0) || (stable = OPENSSL_sk_new(0x18259d), stable != 0)) {
    pAVar1 = ASN1_STRING_TABLE_get(param_1);
    if ((pAVar1 != (ASN1_STRING_TABLE *)0x0) && ((int)(pAVar1->flags << 0x1f) < 0)) {
LAB_001827ae:
      if (-1 < param_2) {
        pAVar1->minsize = param_2;
      }
      if (-1 < param_3) {
        pAVar1->maxsize = param_3;
      }
      if (param_4 != 0) {
        pAVar1->mask = param_4;
      }
      if (param_5 == 0) {
        return 1;
      }
      pAVar1->flags = param_5 | 1;
      return 1;
    }
    ptr = (ASN1_STRING_TABLE *)CRYPTO_zalloc(0x14,"crypto/asn1/a_strnid.c",0x9f);
    if (ptr == (ASN1_STRING_TABLE *)0x0) {
      ERR_put_error(0xd,0x8a,0x41,"crypto/asn1/a_strnid.c",0xa0);
    }
    else {
      iVar2 = OPENSSL_sk_push(stable,ptr);
      if (iVar2 != 0) {
        if (pAVar1 == (ASN1_STRING_TABLE *)0x0) {
          ptr->nid = param_1;
          ptr->minsize = -1;
          ptr->maxsize = -1;
          ptr->flags = 1;
          pAVar1 = ptr;
        }
        else {
          uVar5 = pAVar1->flags;
          lVar4 = pAVar1->minsize;
          lVar3 = pAVar1->maxsize;
          uVar6 = pAVar1->mask;
          ptr->nid = pAVar1->nid;
          ptr->minsize = lVar4;
          ptr->flags = uVar5 | 1;
          ptr->maxsize = lVar3;
          ptr->mask = uVar6;
          pAVar1 = ptr;
        }
        goto LAB_001827ae;
      }
      CRYPTO_free(ptr);
    }
  }
  ERR_put_error(0xd,0x81,0x41,"crypto/asn1/a_strnid.c",0xbe);
  return 0;
}

