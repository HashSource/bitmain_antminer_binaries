
/* WARNING: Unknown calling convention */

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
  logstr[0] = s_bitmain_core_reInit_open_core_ov_00053148[0];
  logstr[1] = s_bitmain_core_reInit_open_core_ov_00053148[1];
  logstr[2] = s_bitmain_core_reInit_open_core_ov_00053148[2];
  logstr[3] = s_bitmain_core_reInit_open_core_ov_00053148[3];
  logstr[4] = s_bitmain_core_reInit_open_core_ov_00053148[4];
  logstr[5] = s_bitmain_core_reInit_open_core_ov_00053148[5];
  logstr[6] = s_bitmain_core_reInit_open_core_ov_00053148[6];
  logstr[7] = s_bitmain_core_reInit_open_core_ov_00053148[7];
  logstr[8] = s_bitmain_core_reInit_open_core_ov_00053148[8];
  logstr[9] = s_bitmain_core_reInit_open_core_ov_00053148[9];
  logstr[10] = s_bitmain_core_reInit_open_core_ov_00053148[10];
  logstr[11] = s_bitmain_core_reInit_open_core_ov_00053148[11];
  logstr[12] = s_bitmain_core_reInit_open_core_ov_00053148[12];
  logstr[13] = s_bitmain_core_reInit_open_core_ov_00053148[13];
  logstr[14] = s_bitmain_core_reInit_open_core_ov_00053148[14];
  logstr[15] = s_bitmain_core_reInit_open_core_ov_00053148[15];
  logstr[16] = s_bitmain_core_reInit_open_core_ov_00053148[16];
  logstr[17] = s_bitmain_core_reInit_open_core_ov_00053148[17];
  logstr[18] = s_bitmain_core_reInit_open_core_ov_00053148[18];
  logstr[19] = s_bitmain_core_reInit_open_core_ov_00053148[19];
  logstr[20] = s_bitmain_core_reInit_open_core_ov_00053148[20];
  logstr[21] = s_bitmain_core_reInit_open_core_ov_00053148[21];
  logstr[22] = s_bitmain_core_reInit_open_core_ov_00053148[22];
  logstr[23] = s_bitmain_core_reInit_open_core_ov_00053148[23];
  logstr[24] = s_bitmain_core_reInit_open_core_ov_00053148[24];
  logstr[25] = s_bitmain_core_reInit_open_core_ov_00053148[25];
  logstr[26] = s_bitmain_core_reInit_open_core_ov_00053148[26];
  logstr[27] = s_bitmain_core_reInit_open_core_ov_00053148[27];
  logstr[28] = s_bitmain_core_reInit_open_core_ov_00053148[28];
  logstr[29] = s_bitmain_core_reInit_open_core_ov_00053148[29];
  logstr[30] = s_bitmain_core_reInit_open_core_ov_00053148[30];
  logstr[31] = s_bitmain_core_reInit_open_core_ov_00053148[31];
  logstr[32] = s_bitmain_core_reInit_open_core_ov_00053148[32];
  logstr[33] = s_bitmain_core_reInit_open_core_ov_00053148[33];
  logstr[34] = s_bitmain_core_reInit_open_core_ov_00053148[34];
  logstr[35] = s_bitmain_core_reInit_open_core_ov_00053148[35];
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

