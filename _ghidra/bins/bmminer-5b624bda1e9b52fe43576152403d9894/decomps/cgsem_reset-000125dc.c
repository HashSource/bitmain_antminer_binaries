
/* WARNING: Unknown calling convention */

void cgsem_reset(cgsem_t *cgsem)

{
  int iVar1;
  int *piVar2;
  
  do {
    while( true ) {
      iVar1 = sem_trywait((sem_t *)cgsem);
      if (iVar1 < 0) break;
      if (iVar1 != 0) {
        return;
      }
    }
    piVar2 = __errno_location();
  } while (*piVar2 == 4);
  return;
}

