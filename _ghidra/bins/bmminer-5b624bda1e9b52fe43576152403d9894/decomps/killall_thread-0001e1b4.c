
/* WARNING: Unknown calling convention */

void * killall_thread(void *arg)

{
  pthread_t __th;
  
  __th = pthread_self();
  pthread_detach(__th);
  pthread_setcanceltype(1,(int *)0x0);
  sleep(7);
                    /* WARNING: Subroutine does not return */
  exit(1);
}

