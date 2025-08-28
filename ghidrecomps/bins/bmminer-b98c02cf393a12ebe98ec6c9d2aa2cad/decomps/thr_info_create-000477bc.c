
void thr_info_create(int param_1,pthread_attr_t *param_2,__start_routine *param_3,void *param_4)

{
  _cgsem_init(param_1 + 0x10,"util.c","thr_info_create",0x4a7);
  pthread_create((pthread_t *)(param_1 + 0xc),param_2,param_3,param_4);
  return;
}

