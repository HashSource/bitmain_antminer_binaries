
bool isChainEnough(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(dev + 4);
  do {
    piVar2 = piVar2 + 1;
    if (*piVar2 == 1) {
      iVar1 = iVar1 + 1;
    }
  } while (piVar2 != (int *)(dev + 0x44));
  return 3 < iVar1;
}

