
/* WARNING: Unknown calling convention */

void * submit_work_thread(void *userdata)

{
  pthread_t __th;
  
  __th = pthread_self();
  pthread_detach(__th);
  return (void *)0x0;
}

