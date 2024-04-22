
void _cgsem_post(cgsem_t *cgsem,char *file,char *func,int line)

{
  int iVar1;
  int *piVar2;
  int line_local;
  char *func_local;
  char *file_local;
  cgsem_t *cgsem_local;
  char tmp42 [2048];
  
  iVar1 = sem_post((sem_t *)cgsem);
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    snprintf(tmp42,0x800,"Failed to sem_post errno=%d cgsem=0x%p in %s %s():%d",*piVar2,cgsem,file,
             func,line);
    _applog(3,tmp42,true);
    _quit(1);
  }
  return;
}

