
/* WARNING: Unknown calling convention */

void * api_thread(void *userdata)

{
  thr_info *mythr;
  
  mythr = (thr_info *)pthread_self();
  pthread_detach((pthread_t)mythr);
  pthread_setcanceltype(1,(int *)0x0);
  RenameThread("API");
  set_lowprio();
  api(api_thr_id);
  *(undefined4 *)((int)userdata + 0xc) = 0;
  return (void *)0x0;
}

