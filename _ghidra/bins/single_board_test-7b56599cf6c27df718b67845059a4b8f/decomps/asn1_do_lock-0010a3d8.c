
int asn1_do_lock(ASN1_VALUE **pval,int op,ASN1_ITEM *it)

{
  bool bVar1;
  void *pvVar2;
  ASN1_VALUE *pAVar3;
  uint uVar4;
  int iVar5;
  ASN1_VALUE *pAVar6;
  int iVar7;
  
  if (it->itype != '\x01' && it->itype != '\x06') {
    return 0;
  }
  pvVar2 = it->funcs;
  if (pvVar2 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = *(uint *)((int)pvVar2 + 4) & 1;
    if (uVar4 != 0) {
      pAVar6 = *pval;
      iVar7 = *(int *)((int)pvVar2 + 0xc);
      pAVar3 = pAVar6 + *(int *)((int)pvVar2 + 8);
      if (op == 0) {
        DataMemoryBarrier(0x1b);
        *(undefined4 *)(pAVar6 + *(int *)((int)pvVar2 + 8)) = 1;
        DataMemoryBarrier(0x1b);
        iVar5 = CRYPTO_THREAD_lock_new();
        *(int *)(pAVar6 + iVar7) = iVar5;
        if (iVar5 != 0) {
          return 1;
        }
        ERR_put_error(0xd,0xe9,0x41,"crypto/asn1/tasn_utl.c",0x4f);
        iVar7 = -1;
      }
      else if (op == 1) {
        do {
          ExclusiveAccess(pAVar3);
          iVar7 = *(int *)pAVar3;
          bVar1 = (bool)hasExclusiveAccess(pAVar3);
        } while (!bVar1);
        *(int *)pAVar3 = iVar7 + 1;
        iVar7 = iVar7 + 1;
      }
      else if (op == -1) {
        do {
          ExclusiveAccess(pAVar3);
          iVar5 = *(int *)pAVar3;
          bVar1 = (bool)hasExclusiveAccess(pAVar3);
        } while (!bVar1);
        *(int *)pAVar3 = iVar5 + -1;
        iVar5 = iVar5 + -1;
        if (iVar5 != 0) {
          return iVar5;
        }
        DataMemoryBarrier(0x1b);
        CRYPTO_THREAD_lock_free(*(undefined4 *)(pAVar6 + iVar7));
        *(undefined4 *)(pAVar6 + iVar7) = 0;
        iVar7 = 0;
      }
      else {
        iVar7 = -1;
      }
      return iVar7;
    }
  }
  return uVar4;
}

