
int RSA_up_ref(RSA *r)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = &r->flags;
  do {
    ExclusiveAccess(piVar3);
    iVar2 = *piVar3;
    bVar1 = (bool)hasExclusiveAccess(piVar3);
  } while (!bVar1);
  *piVar3 = iVar2 + 1;
  return (uint)(0 < iVar2);
}

