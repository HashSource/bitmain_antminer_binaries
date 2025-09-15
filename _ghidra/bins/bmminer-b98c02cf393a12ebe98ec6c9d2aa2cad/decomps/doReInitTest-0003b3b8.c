
void doReInitTest(void)

{
  uint uVar1;
  undefined1 *__dest;
  undefined1 *puVar2;
  undefined1 *__src;
  int *piVar3;
  
  startCheckNetworkJob = 0;
  doTestPatten = 1;
  pthread_mutex_lock((pthread_mutex_t *)reinit_mutex);
  uVar1 = get_dhash_acc_control();
  set_dhash_acc_control(uVar1 & 0xffffffbf);
  __src = show_last_freq;
  sleep(3);
  uVar1 = get_dhash_acc_control();
  set_dhash_acc_control(uVar1 & 0xffffffbf);
  sleep(2);
  piVar3 = (int *)(dev + 4);
  __dest = chain_pic_buf;
  do {
    while (piVar3 = piVar3 + 1, *piVar3 == 1) {
      puVar2 = __dest + 0x80;
      memcpy(__dest,__src,0x80);
      __src = __src + 0x100;
      __dest = puVar2;
      if (puVar2 == nonce_mutex) goto LAB_0003b442;
    }
    __dest = __dest + 0x80;
    __src = __src + 0x100;
  } while (__dest != nonce_mutex);
LAB_0003b442:
  set_nonce2_and_job_id_store_address(PHY_MEM_NONCE2_JOBID_ADDRESS);
  set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
  doTestPatten = 0;
  bitmain_reinit_test();
  doTestPatten = 1;
  set_nonce2_and_job_id_store_address(PHY_MEM_NONCE2_JOBID_ADDRESS);
  set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
  set_asic_ticket_mask(ticket_mask);
  cgsleep_ms(10);
  uVar1 = get_nonce_fifo_interrupt();
  set_nonce_fifo_interrupt(uVar1 | 0x10000);
  clear_nonce_fifo();
  if (opt_multi_version == 0) {
    set_time_out_control(*(uint *)(dev + 0x48) & 0x1ffff | 0x80000000);
  }
  else {
    set_time_out_control(*(int *)(dev + 0x48) * opt_multi_version & 0x1ffffU | 0x80000000);
  }
  doTestPatten = 0;
  pthread_mutex_unlock((pthread_mutex_t *)reinit_mutex);
  if (last_job_buffer[0] != '\x17') {
    re_send_last_job_part_15();
  }
  cgtime(&tv_send_job);
  cgtime(&tv_send);
  startCheckNetworkJob = 1;
  return;
}

