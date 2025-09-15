
void * completion_thread(void *arg)

{
  void *arg_local;
  cg_completion *cgc;
  
  pthread_setcanceltype(1,(int *)0x0);
  (**(code **)((int)arg + 0x10))(*(undefined4 *)((int)arg + 0x14));
  _cgsem_post((cgsem_t *)arg,"util.c","completion_thread",0xe99);
  return (void *)0x0;
}

