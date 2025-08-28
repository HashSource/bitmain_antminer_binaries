
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void bitmain_core_reInit(void)

{
  uint uVar1;
  char logstr [256];
  
  doTestPatten = true;
  pthread_mutex_lock((pthread_mutex_t *)&reinit_mutex);
  startCheckNetworkJob = false;
  uVar1 = get_dhash_acc_control();
  set_dhash_acc_control(uVar1 & 0xffffffbf);
  sleep(3);
  uVar1 = get_dhash_acc_control();
  set_dhash_acc_control(uVar1 & 0xffffffbf);
  sleep(2);
  open_core(true);
  builtin_strncpy(logstr,"bitmain_core_reInit open_core over\n",0x24);
  writeInitLogFile(logstr);
  set_nonce2_and_job_id_store_address(PHY_MEM_NONCE2_JOBID_ADDRESS);
  set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
  set_asic_ticket_mask(0x3f);
  set_hcnt(0);
  cgsleep_ms(10);
  uVar1 = get_nonce_fifo_interrupt();
  set_nonce_fifo_interrupt(uVar1 | 0x10000);
  doTestPatten = false;
  pthread_mutex_unlock((pthread_mutex_t *)&reinit_mutex);
  re_send_last_job();
  cgtime(&tv_send_job);
  cgtime(&tv_send);
  startCheckNetworkJob = true;
  return;
}

