
/* WARNING: Unknown calling convention */

void * mcast_thread(void *userdata)

{
  pthread_t __th;
  
  __th = pthread_self();
  pthread_detach(__th);
  pthread_setcanceltype(1,(int *)0x0);
  RenameThread("APIMcast");
  mcast();
  *(undefined4 *)((int)userdata + 0xc) = 0;
  return (void *)0x0;
}

