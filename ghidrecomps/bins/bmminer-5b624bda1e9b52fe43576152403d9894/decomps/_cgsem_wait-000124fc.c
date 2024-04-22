
/* WARNING: Unknown calling convention */

void _cgsem_wait(cgsem_t *cgsem,char *file,char *func,int line)

{
  int iVar1;
  int *piVar2;
  char tmp42 [2048];
  
  do {
    iVar1 = sem_wait((sem_t *)cgsem);
    if (iVar1 == 0) {
      return;
    }
    piVar2 = __errno_location();
  } while (*piVar2 == 4);
  snprintf(tmp42,0x800,DAT_0001254c,*piVar2,cgsem,file,func,line);
  _applog(3,tmp42,true);
  _quit(1);
  return;
}

