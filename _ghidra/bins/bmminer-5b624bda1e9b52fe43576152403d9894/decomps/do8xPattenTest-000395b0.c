
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void do8xPattenTest(void)

{
  uint *puVar1;
  uint uVar2;
  uchar (*pauVar3) [128];
  uchar (*pauVar4) [256];
  int iVar5;
  all_parameters *paVar6;
  
  iVar5 = 0;
  startCheckNetworkJob = false;
  doTestPatten = true;
  pthread_mutex_lock((pthread_mutex_t *)&reinit_mutex);
  uVar2 = get_dhash_acc_control();
  set_dhash_acc_control(uVar2 & 0xffffffbf);
  sleep(3);
  uVar2 = get_dhash_acc_control();
  set_dhash_acc_control(uVar2 & 0xffffffbf);
  sleep(2);
  paVar6 = dev;
  do {
    while (puVar1 = paVar6->chain_exist, paVar6 = (all_parameters *)&paVar6->pwm_value, *puVar1 == 1
          ) {
      pauVar3 = chain_pic_buf + iVar5;
      pauVar4 = chip_last_freq + iVar5;
      iVar5 = iVar5 + 1;
      memcpy(pauVar3,pauVar4,0x80);
      if (iVar5 == 0x10) goto LAB_00039624;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 != 0x10);
LAB_00039624:
  set_asic_ticket_mask(0);
  clement_doTestBoardOnce(true);
  iVar5 = 0;
  paVar6 = dev;
  do {
    while (puVar1 = paVar6->chain_exist, paVar6 = (all_parameters *)&paVar6->pwm_value, *puVar1 == 1
          ) {
      pauVar3 = chain_pic_buf + iVar5;
      pauVar4 = show_last_freq + iVar5;
      iVar5 = iVar5 + 1;
      memcpy(pauVar3,pauVar4,0x80);
      if (iVar5 == 0x10) goto LAB_00039660;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 != 0x10);
LAB_00039660:
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

