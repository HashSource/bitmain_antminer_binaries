
/* WARNING: Unknown calling convention */

int start_recv_thread(void)

{
  int iVar1;
  char tmp42 [256];
  int ret;
  
  g_rt.recv_nonce = 1;
  cancle_pause_recv_nonce();
  iVar1 = pthread_create(&g_recv_handle,(pthread_attr_t *)0x0,(__start_routine *)0x8fec1,&g_rt);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    builtin_strncpy(tmp42,"create recv thread faile",0x18);
    tmp42[0x18] = 'd';
    tmp42[0x19] = '\0';
    puts(tmp42);
  }
  return iVar1;
}

