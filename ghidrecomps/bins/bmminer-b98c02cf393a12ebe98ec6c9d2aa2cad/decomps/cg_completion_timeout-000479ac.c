
bool cg_completion_timeout(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *__arg;
  int iVar1;
  pthread_t local_1c [2];
  
  __arg = (void *)_cgmalloc(0x18,"util.c",DAT_00047a38,0xe60);
  _cgsem_init(__arg,"util.c",DAT_00047a38,0xe61);
  *(undefined4 *)((int)__arg + 0x10) = param_1;
  *(undefined4 *)((int)__arg + 0x14) = param_2;
  pthread_create(local_1c,(pthread_attr_t *)0x0,completion_thread + 1,__arg);
  iVar1 = _cgsem_mswait(__arg,param_3,"util.c",DAT_00047a38,0xe67);
  if (iVar1 != 0) {
    pthread_cancel(local_1c[0]);
    return iVar1 == 0;
  }
  pthread_join(local_1c[0],(void **)0x0);
  free(__arg);
  return true;
}

