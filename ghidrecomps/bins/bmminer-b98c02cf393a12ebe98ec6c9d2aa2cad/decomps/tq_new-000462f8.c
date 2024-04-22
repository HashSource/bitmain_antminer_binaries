
int tq_new(void)

{
  int iVar1;
  
  iVar1 = _cgcalloc(1,0x58,"util.c",DAT_00046334,0x435);
  *(int *)iVar1 = iVar1;
  *(int *)(iVar1 + 4) = iVar1;
  pthread_mutex_init((pthread_mutex_t *)(iVar1 + 0xc),(pthread_mutexattr_t *)0x0);
  pthread_cond_init((pthread_cond_t *)(iVar1 + 0x28),(pthread_condattr_t *)0x0);
  return iVar1;
}

