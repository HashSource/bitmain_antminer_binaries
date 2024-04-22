
/* WARNING: Unknown calling convention */

_Bool cg_completion_timeout(void *fn,void *fnarg,int timeout)

{
  __start_routine *__start_routine;
  cgsem_t *cgsem;
  cg_completion *cgc;
  int iVar1;
  pthread_t pthread;
  
  cgsem = (cgsem_t *)_cgmalloc(0x18,DAT_0001266c,DAT_00012670,0xd95);
  _cgsem_init(cgsem,DAT_0001266c,DAT_00012670,0xd96);
  *(void **)((int)cgsem + 0x14) = fnarg;
  __start_routine = DAT_00012674;
  cgsem[1].__align = (long)fn;
  pthread_create(&pthread,(pthread_attr_t *)0x0,__start_routine,cgsem);
  iVar1 = _cgsem_mswait(cgsem,timeout,DAT_0001266c,DAT_00012670,0xd9c);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  if (iVar1 == 0) {
    pthread_join(pthread,(void **)0x0);
    free(cgsem);
  }
  else {
    pthread_cancel(pthread);
  }
  return (_Bool)((byte)iVar1 ^ 1);
}

