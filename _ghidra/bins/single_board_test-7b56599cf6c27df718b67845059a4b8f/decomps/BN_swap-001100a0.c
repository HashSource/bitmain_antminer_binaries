
void BN_swap(BIGNUM *a,BIGNUM *b)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  ulong *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  uVar1 = b->flags;
  uVar3 = a->flags;
  iVar6 = b->top;
  puVar5 = a->d;
  a->d = b->d;
  iVar4 = b->dmax;
  iVar8 = a->top;
  iVar2 = a->neg;
  a->top = iVar6;
  iVar6 = b->neg;
  iVar7 = a->dmax;
  a->dmax = iVar4;
  a->neg = iVar6;
  b->d = puVar5;
  b->top = iVar8;
  b->dmax = iVar7;
  b->neg = iVar2;
  a->flags = uVar3 & 1 | uVar1 & 0xe;
  b->flags = uVar3 & 0xe | uVar1 & 1;
  return;
}

