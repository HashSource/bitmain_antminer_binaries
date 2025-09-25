
/* WARNING: Unknown calling convention */

int start_recv_thread(void)

{
  int iVar1;
  char time_stamp [48];
  char tmp1 [256];
  int ret;
  
  g_rt.recv_nonce = 1;
  cancle_pause_recv_nonce();
  iVar1 = pthread_create(&g_recv_handle,(pthread_attr_t *)0x0,(__start_routine *)0x4ea01,&g_rt);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : create recv thread failed\n","start_recv_thread");
    builtin_strncpy(tmp1,"create recv thread faile",0x18);
    tmp1[0x18] = 'd';
    tmp1[0x19] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  return iVar1;
}

