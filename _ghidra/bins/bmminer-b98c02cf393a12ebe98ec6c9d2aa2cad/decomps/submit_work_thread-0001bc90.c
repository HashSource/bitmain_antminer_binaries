
undefined4 submit_work_thread(void)

{
  pthread_t __th;
  
  __th = pthread_self();
  pthread_detach(__th);
  return 0;
}

