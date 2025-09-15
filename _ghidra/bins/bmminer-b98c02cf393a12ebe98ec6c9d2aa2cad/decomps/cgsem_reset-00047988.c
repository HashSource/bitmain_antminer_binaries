
void cgsem_reset(sem_t *param_1)

{
  int iVar1;
  int *piVar2;
  
  do {
    while( true ) {
      iVar1 = sem_trywait(param_1);
      if (iVar1 < 0) break;
      if (iVar1 != 0) {
        return;
      }
    }
    piVar2 = __errno_location();
  } while (*piVar2 == 4);
  return;
}

