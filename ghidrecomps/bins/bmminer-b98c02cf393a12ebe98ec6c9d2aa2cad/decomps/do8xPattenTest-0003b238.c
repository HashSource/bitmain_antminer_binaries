
void do8xPattenTest(void)

{
  uint uVar1;
  void *pvVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int *piVar6;
  
  doTestPatten = 1;
  startCheckNetworkJob = 0;
  pthread_mutex_lock((pthread_mutex_t *)reinit_mutex);
  uVar1 = get_dhash_acc_control();
  set_dhash_acc_control(uVar1 & 0xffffffbf);
  sleep(3);
  uVar1 = get_dhash_acc_control();
  set_dhash_acc_control(uVar1 & 0xffffffbf);
  sleep(2);
  puVar3 = chain_pic_buf;
  piVar6 = (int *)(dev + 4);
  puVar4 = chip_last_freq;
  do {
    while (piVar6 = piVar6 + 1, *piVar6 == 1) {
      pvVar2 = memcpy(puVar3,puVar4,0x80);
      puVar3 = (undefined1 *)((int)pvVar2 + 0x80);
      puVar4 = puVar4 + 0x100;
      if (puVar3 == nonce_mutex) goto LAB_0003b2c6;
    }
    puVar3 = puVar3 + 0x80;
    puVar4 = puVar4 + 0x100;
  } while (puVar3 != nonce_mutex);
LAB_0003b2c6:
  puVar3 = show_last_freq;
  set_asic_ticket_mask(0);
  clement_doTestBoardOnce(1);
  piVar6 = (int *)(dev + 4);
  puVar4 = chain_pic_buf;
  do {
    while (piVar6 = piVar6 + 1, *piVar6 == 1) {
      puVar5 = puVar4 + 0x80;
      memcpy(puVar4,puVar3,0x80);
      puVar3 = puVar3 + 0x100;
      puVar4 = puVar5;
      if (puVar5 == nonce_mutex) goto LAB_0003b302;
    }
    puVar4 = puVar4 + 0x80;
    puVar3 = puVar3 + 0x100;
  } while (puVar4 != nonce_mutex);
LAB_0003b302:
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

