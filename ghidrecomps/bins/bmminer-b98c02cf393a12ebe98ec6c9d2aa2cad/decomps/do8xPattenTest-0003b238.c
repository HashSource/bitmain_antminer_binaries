
void do8xPattenTest(void)

{
  uint uVar1;
  void *pvVar2;
  void *__dest;
  void *pvVar3;
  int *piVar4;
  void *pvVar5;
  
  doTestPatten = 1;
  startCheckNetworkJob = 0;
  pthread_mutex_lock((pthread_mutex_t *)reinit_mutex);
  uVar1 = get_dhash_acc_control();
  __dest = DAT_0003b3a0;
  set_dhash_acc_control(uVar1 & 0xffffffbf);
  pvVar3 = DAT_0003b3a4;
  sleep(3);
  uVar1 = get_dhash_acc_control();
  pvVar5 = (void *)((int)__dest + 0x800);
  set_dhash_acc_control(uVar1 & 0xffffffbf);
  sleep(2);
  piVar4 = (int *)(dev + 4);
  pvVar2 = __dest;
  do {
    while (piVar4 = piVar4 + 1, *piVar4 == 1) {
      pvVar2 = memcpy(pvVar2,pvVar3,0x80);
      pvVar2 = (void *)((int)pvVar2 + 0x80);
      pvVar3 = (void *)((int)pvVar3 + 0x100);
      if (pvVar2 == pvVar5) goto LAB_0003b2c6;
    }
    pvVar2 = (void *)((int)pvVar2 + 0x80);
    pvVar3 = (void *)((int)pvVar3 + 0x100);
  } while (pvVar2 != pvVar5);
LAB_0003b2c6:
  pvVar3 = DAT_0003b3a8;
  set_asic_ticket_mask(0);
  clement_doTestBoardOnce(1);
  piVar4 = (int *)(dev + 4);
  do {
    while (piVar4 = piVar4 + 1, *piVar4 == 1) {
      pvVar2 = (void *)((int)__dest + 0x80);
      memcpy(__dest,pvVar3,0x80);
      pvVar3 = (void *)((int)pvVar3 + 0x100);
      __dest = pvVar2;
      if (pvVar2 == pvVar5) goto LAB_0003b302;
    }
    __dest = (void *)((int)__dest + 0x80);
    pvVar3 = (void *)((int)pvVar3 + 0x100);
  } while (__dest != pvVar5);
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
  pthread_mutex_unlock(DAT_0003b3ac);
  if (last_job_buffer[0] != '\x17') {
    re_send_last_job_part_15();
  }
  cgtime(DAT_0003b3b0);
  cgtime(DAT_0003b3b4);
  startCheckNetworkJob = 1;
  return;
}

