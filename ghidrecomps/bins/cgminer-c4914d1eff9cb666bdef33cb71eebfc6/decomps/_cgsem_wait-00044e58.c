
void _cgsem_wait(cgsem_t *cgsem,char *file,char *func,int line)

{
  _Bool _Var1;
  int iVar2;
  int *piVar3;
  int line_local;
  char *func_local;
  char *file_local;
  cgsem_t *cgsem_local;
  char tmp42 [2048];
  
  do {
    iVar2 = sem_wait((sem_t *)cgsem);
    if (iVar2 == 0) {
      return;
    }
    _Var1 = interrupted();
  } while (_Var1);
  piVar3 = __errno_location();
  snprintf(tmp42,0x800,"Failed to sem_wait errno=%d cgsem=0x%p in %s %s():%d",*piVar3,cgsem,file,
           func,line);
  _applog(3,tmp42,true);
  _quit(1);
  return;
}

