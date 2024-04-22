
int RSA_memory_lock(RSA *r)

{
  BIGNUM *pBVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  BIGNUM *pBVar5;
  ulong *puVar6;
  int iVar7;
  
  if (r->d == (BIGNUM *)0x0) {
    iVar2 = 1;
  }
  else {
    pBVar1 = (BIGNUM *)
             CRYPTO_malloc_locked
                       ((r->dmq1->top + r->d->top + r->p->top + r->q->top + r->dmp1->top +
                         r->iqmp->top + 0x20) * 4,DAT_000a3f94,0x13a);
    if (pBVar1 == (BIGNUM *)0x0) {
      ERR_put_error(4,0x82,0x41,DAT_000a3f94,0x13b);
      iVar2 = 0;
    }
    else {
      puVar6 = (ulong *)((int)&pBVar1[1].dmax + 3);
      pBVar5 = r->d;
      r->d = pBVar1;
      iVar2 = pBVar5->top;
      iVar3 = pBVar5->dmax;
      iVar4 = pBVar5->neg;
      pBVar1->d = pBVar5->d;
      pBVar1->top = iVar2;
      pBVar1->neg = iVar4;
      pBVar1->dmax = iVar3;
      iVar2 = pBVar5->top;
      pBVar1->d = puVar6;
      pBVar1->flags = 2;
      memcpy(puVar6,pBVar5->d,iVar2 << 2);
      puVar6 = puVar6 + pBVar5->top;
      BN_clear_free(pBVar5);
      pBVar5 = r->p;
      r->p = pBVar1 + 1;
      iVar2 = pBVar5->top;
      iVar3 = pBVar5->dmax;
      iVar4 = pBVar5->neg;
      pBVar1[1].d = pBVar5->d;
      pBVar1[1].top = iVar2;
      pBVar1[1].neg = iVar4;
      pBVar1[1].dmax = iVar3;
      iVar2 = pBVar5->top;
      pBVar1[1].d = puVar6;
      pBVar1[1].flags = 2;
      memcpy(puVar6,pBVar5->d,iVar2 << 2);
      puVar6 = puVar6 + pBVar5->top;
      BN_clear_free(pBVar5);
      pBVar5 = r->q;
      r->q = pBVar1 + 2;
      iVar4 = pBVar5->top;
      iVar2 = pBVar5->dmax;
      iVar3 = pBVar5->neg;
      pBVar1[2].d = pBVar5->d;
      pBVar1[2].top = iVar4;
      pBVar1[2].dmax = iVar2;
      pBVar1[2].neg = iVar3;
      iVar2 = pBVar5->top;
      pBVar1[2].d = puVar6;
      pBVar1[2].flags = 2;
      memcpy(puVar6,pBVar5->d,iVar2 << 2);
      puVar6 = puVar6 + pBVar5->top;
      BN_clear_free(pBVar5);
      pBVar5 = r->dmp1;
      r->dmp1 = pBVar1 + 3;
      iVar4 = pBVar5->top;
      iVar2 = pBVar5->dmax;
      iVar3 = pBVar5->neg;
      pBVar1[3].d = pBVar5->d;
      pBVar1[3].top = iVar4;
      pBVar1[3].dmax = iVar2;
      pBVar1[3].neg = iVar3;
      iVar2 = pBVar5->top;
      pBVar1[3].d = puVar6;
      pBVar1[3].flags = 2;
      memcpy(puVar6,pBVar5->d,iVar2 << 2);
      puVar6 = puVar6 + pBVar5->top;
      BN_clear_free(pBVar5);
      pBVar5 = r->dmq1;
      r->dmq1 = pBVar1 + 4;
      iVar4 = pBVar5->top;
      iVar2 = pBVar5->dmax;
      iVar3 = pBVar5->neg;
      pBVar1[4].d = pBVar5->d;
      pBVar1[4].top = iVar4;
      pBVar1[4].dmax = iVar2;
      pBVar1[4].neg = iVar3;
      iVar2 = pBVar5->top;
      pBVar1[4].d = puVar6;
      pBVar1[4].flags = 2;
      memcpy(puVar6,pBVar5->d,iVar2 << 2);
      iVar4 = pBVar5->top;
      BN_clear_free(pBVar5);
      pBVar5 = r->iqmp;
      r->iqmp = pBVar1 + 5;
      iVar7 = pBVar5->top;
      iVar2 = pBVar5->dmax;
      iVar3 = pBVar5->neg;
      pBVar1[5].d = pBVar5->d;
      pBVar1[5].top = iVar7;
      pBVar1[5].dmax = iVar2;
      pBVar1[5].neg = iVar3;
      iVar2 = pBVar5->top;
      pBVar1[5].d = puVar6 + iVar4;
      pBVar1[5].flags = 2;
      memcpy(puVar6 + iVar4,pBVar5->d,iVar2 << 2);
      BN_clear_free(pBVar5);
      iVar2 = 1;
      r->bignum_data = (char *)pBVar1;
      r->flags = r->flags & 0xfffffff9;
    }
  }
  return iVar2;
}

