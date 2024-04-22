
void start_send_work_and_get_result(int param_1)

{
  FILE *pFVar1;
  uint uVar2;
  undefined4 uVar3;
  int local_10;
  int local_c;
  
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: start_send_work_and_get_result enter\n","board_frq_tuning.c",0x1e0);
    }
    fclose(pFVar1);
  }
  *(undefined4 *)(chain_DataCount + param_1 * 4) = 0x390;
  *(undefined4 *)(chain_ValidNonce + param_1 * 4) = 0x12b40;
  *(undefined4 *)(chain_PassCount + param_1 * 4) = 0x390;
  reset_work_data();
  if (gBegin_get_nonce != '\x01') {
    puts("clement2 set_nonce_fifo_interrupt");
    uVar2 = get_nonce_fifo_interrupt();
    set_nonce_fifo_interrupt(uVar2 | 0x10000);
    gBegin_get_nonce = '\x01';
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: start send works on chain[%d]\n","board_frq_tuning.c",500,param_1);
    }
    fclose(pFVar1);
  }
  StartSendFlag[param_1] = 1;
  send_func_all();
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: wait recv nonce on chain[%d]\n","board_frq_tuning.c",0x1f9,param_1);
    }
    fclose(pFVar1);
  }
  local_10 = 0;
  local_c = 0;
  while ((local_c < 0x14 &&
         (*(int *)(valid_nonce_num + param_1 * 4) < *(int *)(chain_ValidNonce + param_1 * 4)))) {
    if (*(int *)(valid_nonce_num + param_1 * 4) == local_10) {
      local_c = local_c + 1;
    }
    else {
      local_c = 0;
      local_10 = *(int *)(valid_nonce_num + param_1 * 4);
    }
    usleep(100000);
  }
  gBegin_get_nonce = 0;
  start_receive = 0;
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: get nonces on chain[%d]\n","board_frq_tuning.c",0x20c,param_1);
    }
    fclose(pFVar1);
  }
  get_result(param_1,*(undefined4 *)(chain_PassCount + param_1 * 4),
             *(undefined4 *)(chain_ValidNonce + param_1 * 4));
  SaveAsicCoreEnabledFlagByResultToTempRecord(param_1);
  uVar3 = get_crc_count();
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: After TEST CRC error counter=%d\n","board_frq_tuning.c",0x212,uVar3);
    }
    fclose(pFVar1);
  }
  return;
}

