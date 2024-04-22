
/* WARNING: Unknown calling convention */

void * completion_thread(void *arg)

{
  cg_completion *cgc;
  
  pthread_setcanceltype(1,(int *)0x0);
  (**(code **)((int)arg + 0x10))(*(undefined4 *)((int)arg + 0x14));
  _cgsem_post((cgsem_t *)arg,"util.c",DAT_000124f8,0xd8a);
  return (void *)0x0;
}

