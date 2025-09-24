
int DH_up_ref(DH *dh)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = &dh->references;
  do {
    ExclusiveAccess(piVar3);
    iVar2 = *piVar3;
    bVar1 = (bool)hasExclusiveAccess(piVar3);
  } while (!bVar1);
  *piVar3 = iVar2 + 1;
  return (uint)(0 < iVar2);
}

