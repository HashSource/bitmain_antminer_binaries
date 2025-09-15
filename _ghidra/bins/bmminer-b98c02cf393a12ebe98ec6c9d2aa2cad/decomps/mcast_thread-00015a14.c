
void mcast_thread(int param_1)

{
  pthread_t __th;
  
  __th = pthread_self();
  pthread_detach(__th);
  pthread_setcanceltype(1,(int *)0x0);
  RenameThread("APIMcast");
  mcast();
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}

