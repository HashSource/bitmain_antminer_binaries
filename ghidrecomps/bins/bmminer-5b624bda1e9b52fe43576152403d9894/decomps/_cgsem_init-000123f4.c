
/* WARNING: Unknown calling convention */

void _cgsem_init(cgsem_t *cgsem,char *file,char *func,int line)

{
  int iVar1;
  int ret;
  int *piVar2;
  char tmp42 [2048];
  
  iVar1 = sem_init((sem_t *)cgsem,0,0);
  if (iVar1 != 0) {
    piVar2 = __errno_location();
    snprintf(tmp42,0x800,DAT_00012440,iVar1,*piVar2,file,func,line);
    _applog(3,tmp42,true);
    _quit(1);
  }
  return;
}

