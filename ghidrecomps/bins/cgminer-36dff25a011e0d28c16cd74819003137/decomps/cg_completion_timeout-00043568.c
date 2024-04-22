
_Bool cg_completion_timeout(void *fn,void *fnarg,int timeout)

{
  int iVar1;
  bool bVar2;
  int timeout_local;
  void *fnarg_local;
  void *fn_local;
  pthread_t pthread;
  cg_completion *cgc;
  _Bool ret;
  
  ret = false;
  cgc = (cg_completion *)_cgmalloc(0x18,"util.c","cg_completion_timeout",0xea3);
  _cgsem_init((cgsem_t *)cgc,"util.c","cg_completion_timeout",0xea4);
  cgc->fn = (_func_void_void_ptr *)fn;
  cgc->fnarg = fnarg;
  pthread_create(&pthread,(pthread_attr_t *)0x0,completion_thread,cgc);
  iVar1 = _cgsem_mswait(&cgc->cgsem,timeout,"util.c","cg_completion_timeout",0xeaa);
  bVar2 = iVar1 != 0;
  if (bVar2) {
    iVar1 = 1;
  }
  ret = SUB41(iVar1,0);
  if (!bVar2) {
    ret = false;
  }
  if (ret == true) {
    pthread_cancel(pthread);
  }
  else {
    pthread_join(pthread,(void **)0x0);
    free(cgc);
  }
  return ret == false;
}

