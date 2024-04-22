
void _cgsem_init(sem_t *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  char acStack_818 [2052];
  
  iVar1 = sem_init(param_1,0,0);
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    snprintf(acStack_818,0x800,"Failed to sem_init ret=%d errno=%d in %s %s():%d",iVar1,*piVar2,
             param_2,param_3,param_4);
    _applog(3,acStack_818,1);
    _quit(1);
  }
  return;
}

