
bool EVP_PKEY_up_ref(int param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_1 + 8);
  do {
    ExclusiveAccess(piVar3);
    iVar2 = *piVar3;
    bVar1 = (bool)hasExclusiveAccess(piVar3);
  } while (!bVar1);
  *piVar3 = iVar2 + 1;
  return 0 < iVar2;
}

