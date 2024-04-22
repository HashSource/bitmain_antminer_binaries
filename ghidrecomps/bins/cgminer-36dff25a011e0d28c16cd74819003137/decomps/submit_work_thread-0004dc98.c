
void * submit_work_thread(void *userdata)

{
  pthread_t __th;
  void *userdata_local;
  
  __th = pthread_self();
  pthread_detach(__th);
  return (void *)0x0;
}

