
undefined4 bm1740_app_init(void)

{
  int iVar1;
  undefined4 uVar2;
  int local_10;
  int local_c;
  
  inited = 1;
  init_fpga();
  check_chain();
  for (local_10 = 0; local_10 < 1; local_10 = local_10 + 1) {
    if ((&gChain_exist)[local_10] == '\0') {
      printf("chain %d can\'t find\n");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
  }
  reset_hash_board();
  bm1740_soc_init();
  rb_nonce = malloc(0x24540);
  rb_reg = malloc(900);
  rb_comm = malloc(0x5000);
  if (((rb_nonce == (void *)0x0) || (rb_reg == (void *)0x0)) || (rb_comm == (void *)0x0)) {
    printf("%s malloc failed\n","bm1740_app_init");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  memset(rb_nonce,0,0x24540);
  memset(rb_reg,0,900);
  memset(rb_comm,0,0x5000);
  rt_ringbuffer_init(bm_nonce_rb,rb_nonce,0x4540,0);
  rt_ringbuffer_init(bm_reg_rb,rb_reg,900,0);
  rt_ringbuffer_init(bm_comm_rb,rb_comm,0x5000,0);
  reg_scan_init();
  iVar1 = pthread_create(&p_get_nonce_back,(pthread_attr_t *)0x0,bm1740_get_nonce + 1,(void *)0x0);
  if (iVar1 == 0) {
    iVar1 = pthread_create(&p_get_reg_back,(pthread_attr_t *)0x0,bm1740_get_reg + 1,(void *)0x0);
    if (iVar1 == 0) {
      for (local_c = 0; local_c < 1; local_c = local_c + 1) {
        *(uint *)(g_chain + local_c * 0x28) = (uint)(byte)(&gChain_fd)[local_c];
        g_chain[local_c * 0x28 + 4] = (char)local_c;
        iVar1 = pthread_create((pthread_t *)(g_chain + local_c * 0x28 + 0x18),(pthread_attr_t *)0x0,
                               midd_dispatch_packet + 1,g_chain + local_c * 0x28);
        if (iVar1 != 0) {
          puts("create p_dispatch failed");
          return 0xffffffff;
        }
        iVar1 = pthread_create((pthread_t *)(g_chain + local_c * 0x28 + 0x1c),(pthread_attr_t *)0x0,
                               midd_recv_comm + 1,g_chain + local_c * 0x28);
        if (iVar1 != 0) {
          puts("create p_read_comm failed");
          return 0xffffffff;
        }
      }
      uVar2 = 0;
    }
    else {
      puts("create get_reg_back thread failed");
      uVar2 = 0xffffffff;
    }
  }
  else {
    puts("create get_nonce_back thread failed");
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

