
void BN_swap(BIGNUM *a,BIGNUM *b)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  ulong *puVar7;
  
  uVar1 = a->flags;
  uVar2 = b->flags;
  puVar7 = a->d;
  iVar6 = a->top;
  a->d = b->d;
  iVar5 = a->dmax;
  iVar4 = a->neg;
  a->top = b->top;
  iVar3 = b->dmax;
  a->flags = uVar2 & 2 | uVar1 & 1;
  b->d = puVar7;
  a->dmax = iVar3;
  b->top = iVar6;
  b->dmax = iVar5;
  a->neg = b->neg;
  b->flags = uVar2 & 1 | uVar1 & 2;
  b->neg = iVar4;
  return;
}

