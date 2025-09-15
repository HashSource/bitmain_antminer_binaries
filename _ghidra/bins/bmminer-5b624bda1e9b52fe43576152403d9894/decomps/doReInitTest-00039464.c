
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void doReInitTest(void)

{
  uint *puVar1;
  uint uVar2;
  uchar (*__dest) [128];
  uchar (*__src) [256];
  int iVar3;
  all_parameters *paVar4;
  
  iVar3 = 0;
  startCheckNetworkJob = false;
  doTestPatten = true;
  pthread_mutex_lock((pthread_mutex_t *)&reinit_mutex);
  uVar2 = get_dhash_acc_control();
  set_dhash_acc_control(uVar2 & 0xffffffbf);
  sleep(3);
  uVar2 = get_dhash_acc_control();
  set_dhash_acc_control(uVar2 & 0xffffffbf);
  sleep(2);
  paVar4 = dev;
  do {
    while (puVar1 = paVar4->chain_exist, paVar4 = (all_parameters *)&paVar4->pwm_value, *puVar1 == 1
          ) {
      __dest = chain_pic_buf + iVar3;
      __src = show_last_freq + iVar3;
      iVar3 = iVar3 + 1;
      memcpy(__dest,__src,0x80);
      if (iVar3 == 0x10) goto LAB_000394da;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 0x10);
LAB_000394da:
  set_nonce2_and_job_id_store_address(PHY_MEM_NONCE2_JOBID_ADDRESS);
  set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
  doTestPatten = false;
  bitmain_reinit_test();
  doTestPatten = true;
  set_nonce2_and_job_id_store_address(PHY_MEM_NONCE2_JOBID_ADDRESS);
  set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
  set_asic_ticket_mask(0x3f);
  cgsleep_ms(10);
  uVar2 = get_nonce_fifo_interrupt();
  set_nonce_fifo_interrupt(uVar2 | 0x10000);
  clear_nonce_fifo();
  if (opt_multi_version == 0) {
    set_time_out_control(dev->timeout & 0x1ffff | 0x80000000);
  }
  else {
    set_time_out_control(dev->timeout * opt_multi_version & 0x1ffff | 0x80000000);
  }
  doTestPatten = false;
  pthread_mutex_unlock((pthread_mutex_t *)&reinit_mutex);
  re_send_last_job();
  cgtime(&tv_send_job);
  cgtime(&tv_send);
  startCheckNetworkJob = true;
  return;
}

