
void bitmain_core_reInit(void)

{
  uint uVar1;
  FILE *__stream;
  
  doTestPatten = 1;
  pthread_mutex_lock((pthread_mutex_t *)reinit_mutex);
  startCheckNetworkJob = 0;
  uVar1 = get_dhash_acc_control();
  set_dhash_acc_control(uVar1 & 0xffffffbf);
  sleep(3);
  uVar1 = get_dhash_acc_control();
  set_dhash_acc_control(uVar1 & 0xffffffbf);
  sleep(2);
  open_core(1);
  if (3 < log_level) {
    __stream = fopen(log_file,(char *)&DAT_0005e760);
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: bitmain_core_reInit open_core over\n","driver-btm-c5.c",0x3ef0,
              DAT_0003c870);
    }
    fclose(__stream);
  }
  set_nonce2_and_job_id_store_address(PHY_MEM_NONCE2_JOBID_ADDRESS);
  set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
  set_asic_ticket_mask(ticket_mask);
  set_hcnt(0);
  set_sno(0);
  cgsleep_ms(10);
  uVar1 = get_nonce_fifo_interrupt();
  set_nonce_fifo_interrupt(uVar1 | 0x10000);
  doTestPatten = 0;
  pthread_mutex_unlock(DAT_0003c864);
  if (last_job_buffer[0] != '\x17') {
    re_send_last_job_part_15();
  }
  cgtime(DAT_0003c868);
  cgtime(DAT_0003c86c);
  startCheckNetworkJob = 1;
  return;
}

