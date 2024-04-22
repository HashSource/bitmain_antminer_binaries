
void midd_recv_comm(int param_1)

{
  pthread_t __th;
  undefined auStack_410 [1024];
  uint local_10;
  int local_c;
  
  local_c = param_1;
  memset(auStack_410,0,0x400);
  __th = pthread_self();
  pthread_detach(__th);
  do {
    usleep(3000);
    local_10 = uart_receive(*(uint *)(g_chain + (uint)*(byte *)(local_c + 4) * 0x28) & 0xff,
                            auStack_410,1);
    rt_ringbuffer_put(bm_comm_rb,auStack_410,local_10 & 0xffff);
  } while( true );
}

