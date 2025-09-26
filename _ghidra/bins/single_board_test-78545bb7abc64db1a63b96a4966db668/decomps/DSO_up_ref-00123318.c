
int DSO_up_ref(DSO *dso)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  
  if (dso == (DSO *)0x0) {
    ERR_put_error(0x25,0x72,0x43,"crypto/dso/dso_lib.c",0x6b);
    return 0;
  }
  piVar2 = &dso->references;
  do {
    ExclusiveAccess(piVar2);
    iVar3 = *piVar2;
    bVar1 = (bool)hasExclusiveAccess(piVar2);
  } while (!bVar1);
  *piVar2 = iVar3 + 1;
  return (uint)(0 < iVar3);
}

