
int EC_KEY_up_ref(EC_KEY *key)

{
  bool bVar1;
  int iVar2;
  EC_KEY *pEVar3;
  
  pEVar3 = key + 0x20;
  do {
    ExclusiveAccess(pEVar3);
    iVar2 = *(int *)pEVar3;
    bVar1 = (bool)hasExclusiveAccess(pEVar3);
  } while (!bVar1);
  *(int *)pEVar3 = iVar2 + 1;
  return (uint)(0 < iVar2);
}

