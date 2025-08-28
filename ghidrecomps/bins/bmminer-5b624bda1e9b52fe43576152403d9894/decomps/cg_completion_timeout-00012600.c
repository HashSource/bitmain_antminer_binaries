
/* WARNING: Unknown calling convention */

_Bool cg_completion_timeout(void *fn,void *fnarg,int timeout)

{
  cgsem_t *cgsem;
  int iVar1;
  pthread_t pthread;
  
  cgsem = (cgsem_t *)_cgmalloc(0x18,"util.c","cg_completion_timeout",0xd95);
  _cgsem_init(cgsem,"util.c","cg_completion_timeout",0xd96);
  *(void **)((int)cgsem + 0x14) = fnarg;
  cgsem[1].__align = (long)fn;
  pthread_create(&pthread,(pthread_attr_t *)0x0,(__start_routine *)0x124cd,cgsem);
  iVar1 = _cgsem_mswait(cgsem,timeout,"util.c","cg_completion_timeout",0xd9c);
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

