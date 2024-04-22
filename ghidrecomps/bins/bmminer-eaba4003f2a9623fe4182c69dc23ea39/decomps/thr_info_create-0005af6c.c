
int thr_info_create(thr_info *thr,pthread_attr_t *attr,_func_void_ptr_void_ptr *start,void *arg)

{
  int iVar1;
  void *arg_local;
  _func_void_ptr_void_ptr *start_local;
  pthread_attr_t *attr_local;
  thr_info *thr_local;
  
  _cgsem_init(&thr->sem,"util.c","thr_info_create",0x4a7);
  iVar1 = pthread_create(&thr->pth,(pthread_attr_t *)attr,(__start_routine *)start,arg);
  return iVar1;
}

