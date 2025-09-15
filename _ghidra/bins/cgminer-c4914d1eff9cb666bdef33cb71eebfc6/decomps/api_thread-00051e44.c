
void * api_thread(void *userdata)

{
  pthread_t __th;
  void *userdata_local;
  thr_info *mythr;
  
  __th = pthread_self();
  pthread_detach(__th);
  pthread_setcanceltype(1,(int *)0x0);
  RenameThread("API");
  set_lowprio();
  api(api_thr_id);
  *(undefined4 *)((int)userdata + 0xc) = 0;
  return (void *)0x0;
}

