
/* WARNING: Unknown calling convention */

void * mcast_thread(void *userdata)

{
  thr_info *mythr;
  
  mythr = (thr_info *)pthread_self();
  pthread_detach((pthread_t)mythr);
  pthread_setcanceltype(1,(int *)0x0);
  RenameThread("APIMcast");
  mcast();
  *(undefined4 *)((int)userdata + 0xc) = 0;
  return (void *)0x0;
}

