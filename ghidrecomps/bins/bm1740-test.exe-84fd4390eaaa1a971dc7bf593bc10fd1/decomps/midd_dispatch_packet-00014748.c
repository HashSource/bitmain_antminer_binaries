
void midd_dispatch_packet(int param_1)

{
  pthread_t __th;
  size_t local_1034;
  int local_1030;
  undefined auStack_102c [1024];
  undefined auStack_c2c [1024];
  undefined auStack_82c [2048];
  size_t local_2c;
  int local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  size_t local_18;
  undefined *local_14;
  
  memset(auStack_82c,0,0x800);
  memset(auStack_c2c,0,0x400);
  local_14 = auStack_c2c;
  memset(auStack_102c,0,0x400);
  local_20 = (uint)*(byte *)(param_1 + 4);
  local_24 = 0;
  local_1030 = 0;
  local_18 = 1;
  local_1034 = 1;
  local_28 = 0;
  local_1c = param_1;
  __th = pthread_self();
  pthread_detach(__th);
  do {
    while( true ) {
      while( true ) {
        do {
          usleep(10000);
          local_2c = midd_recv_comm_from_rb(auStack_82c,local_18);
        } while (local_2c != local_18);
        local_28 = bm1740_parse_respond_len(auStack_82c,local_18,&local_1034);
        if (local_28 != 0) break;
        local_18 = 1;
        local_14 = auStack_c2c;
      }
      if (local_28 != 1) break;
      memcpy(local_14,auStack_82c,local_18);
      local_14 = local_14 + local_18;
      local_18 = local_1034;
    }
    memcpy(local_14,auStack_82c,local_18);
    local_14 = local_14 + local_18;
    local_24 = bm1740_parse_respond_pkg
                         (auStack_c2c,(int)local_14 - (int)auStack_c2c,&local_1030,auStack_102c,
                          0x400);
    if (0 < (int)local_24) {
      auStack_102c[local_24] = *(undefined *)(local_1c + 4);
      local_24 = local_24 + 1;
      if (local_1030 == 0) {
        rt_ringbuffer_put(bm_nonce_rb,auStack_102c,local_24 & 0xffff);
      }
      else if (local_1030 == 2) {
        rt_ringbuffer_put(bm_reg_rb,auStack_102c,local_24 & 0xffff);
      }
      else {
        printf("unknow receive type %d\n",local_1030);
      }
    }
    local_14 = auStack_c2c;
    local_18 = 1;
  } while( true );
}

