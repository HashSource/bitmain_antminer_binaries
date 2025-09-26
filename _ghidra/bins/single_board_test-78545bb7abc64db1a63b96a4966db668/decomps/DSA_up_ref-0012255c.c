
int DSA_up_ref(DSA *r)

{
  bool bVar1;
  BIGNUM *pBVar2;
  BIGNUM **ppBVar3;
  
  ppBVar3 = &r->r;
  do {
    ExclusiveAccess(ppBVar3);
    pBVar2 = *ppBVar3;
    bVar1 = (bool)hasExclusiveAccess(ppBVar3);
  } while (!bVar1);
  *ppBVar3 = (BIGNUM *)((int)&pBVar2->d + 1);
  return (uint)(0 < (int)pBVar2);
}

