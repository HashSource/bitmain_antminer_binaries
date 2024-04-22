
void _cgsem_wait(sem_t *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  char acStack_818 [2052];
  
  do {
    iVar1 = sem_wait(param_1);
    if (iVar1 == 0) {
      return;
    }
    piVar2 = __errno_location();
  } while (*piVar2 == 4);
  snprintf(acStack_818,0x800,"Failed to sem_wait errno=%d cgsem=0x%p in %s %s():%d",*piVar2,param_1,
           param_2,param_3,param_4);
  _applog(3,acStack_818,1);
  _quit(1);
  return;
}

