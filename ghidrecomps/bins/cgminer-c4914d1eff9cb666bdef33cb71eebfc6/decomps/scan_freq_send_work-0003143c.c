
/* WARNING: Unknown calling convention */

void scan_freq_send_work(void)

{
  int iVar1;
  int iVar2;
  FILE *pFVar3;
  uint uVar4;
  int iVar5;
  SCAN_FREQ_WORK *pSVar6;
  SCAN_FREQ_WORK *__src;
  uint buf_vil [13];
  vil_work_1387 work_vil_1387;
  SCAN_FREQ_WORK *work;
  SCAN_FREQ_WORK *works;
  int column;
  FILE *pFile_1;
  FILE *pFile_2;
  FILE *pFile;
  int AsicNum;
  int CoreNum;
  uint work_fifo_ready;
  int wait_count;
  int last_recv_num;
  uint work_id;
  int which_pattern;
  int which_core;
  int which_asic;
  int chain;
  int j;
  int i;
  
  work_id = 0;
  memset(buf_vil,0,0x34);
  iVar2 = scanfreq_info.CoreNum;
  iVar1 = scanfreq_info.AsicNum;
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: start send work\n","freq_scan.c",0x3c2,"scan_freq_send_work");
    }
    fclose(pFVar3);
  }
  gBegin_get_nonce = true;
  uVar4 = get_nonce_fifo_interrupt();
  set_nonce_fifo_interrupt(uVar4 | 0x10000);
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if ((dev->chain_exist[chain] != 0) && (scanfreq_info.test_done[chain] == false)) {
      for (which_asic = 0; which_asic < iVar1; which_asic = which_asic + 1) {
        if ((check_column_nonce == false) ||
           ((uVar4 = get_logical_column_by_chip_no(which_asic),
            uVar4 == scanfreq_info.current_column[chain] &&
            (scanfreq_info.current_column_finish[chain][uVar4] == false)))) {
          pSVar6 = scanfreq_info.works[which_asic];
          for (which_core = 0; which_core < iVar2; which_core = which_core + 1) {
            for (which_pattern = 0; iVar5 = __aeabi_idiv(scanfreq_info.AsicWorkCount,iVar2),
                which_pattern < iVar5; which_pattern = which_pattern + 1) {
              while (uVar4 = get_buffer_space(), (uVar4 & 1 << (chain & 0xffU)) == 0) {
                usleep(1000);
              }
              memset(buf_vil,0,0x34);
              iVar5 = __aeabi_idiv(scanfreq_info.AsicWorkCount,iVar2);
              __src = pSVar6 + which_pattern + which_core * iVar5;
              memset(&work_vil_1387,0,0x34);
              work_vil_1387.work_type = '\x01';
              work_vil_1387.chain_id = (byte)chain | 0x80;
              work_vil_1387.reserved1[0] = '\0';
              work_vil_1387.reserved1[1] = '\0';
              work_id = work_id + 1;
              if (0x7f < work_id) {
                work_id = 0;
              }
              work_vil_1387.work_count = work_id & 0x7f | which_pattern << 7;
              memcpy(scanfreq_info.send_work[chain] + work_id,__src,0x74);
              for (i = 0; i < 0xc; i = i + 1) {
                work_vil_1387.data[i] = __src->data[i];
              }
              for (i = 0; i < 0x20; i = i + 1) {
                work_vil_1387.midstate[i] = __src->midstate[i];
              }
              buf_vil[0] = (uint)work_vil_1387.reserved1[0] << 8 |
                           (uint)work_vil_1387.work_type << 0x18 |
                           (uint)work_vil_1387.chain_id << 0x10 | (uint)work_vil_1387.reserved1[1];
              buf_vil[1] = work_vil_1387.work_count;
              for (j = 2; (uint)j < 5; j = j + 1) {
                buf_vil[j] = (uint)work_vil_1387.reserved1[j * 4] << 8 |
                             (uint)work_vil_1387.reserved1[j * 4 + -2] << 0x18 |
                             (uint)work_vil_1387.reserved1[j * 4 + -1] << 0x10 |
                             (uint)work_vil_1387.reserved1[j * 4 + 1];
              }
              for (j = 5; (uint)j < 0xd; j = j + 1) {
                buf_vil[j] = (uint)work_vil_1387.reserved1[j * 4] << 8 |
                             (uint)work_vil_1387.reserved1[j * 4 + -2] << 0x18 |
                             (uint)work_vil_1387.reserved1[j * 4 + -1] << 0x10 |
                             (uint)work_vil_1387.reserved1[j * 4 + 1];
              }
              set_TW_write_command_vil(buf_vil);
              scanfreq_info.send_work_num[chain] = scanfreq_info.send_work_num[chain] + 1;
            }
          }
        }
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: Chain[%d] send %d works\n","freq_scan.c",0x41c,
                  "scan_freq_send_work",chain,scanfreq_info.send_work_num[chain]);
        }
        fclose(pFVar3);
      }
    }
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: wait for receiving nonce\n","freq_scan.c",0x420,
              "scan_freq_send_work");
    }
    fclose(pFVar3);
  }
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if ((dev->chain_exist[chain] != 0) && (scanfreq_info.test_done[chain] == false)) {
      last_recv_num = 0;
      wait_count = 0;
      while ((wait_count < 3 &&
             (scanfreq_info.valid_nonce_num[chain] < scanfreq_info.RequiredChainNonce))) {
        if (last_recv_num == scanfreq_info.valid_nonce_num[chain]) {
          wait_count = wait_count + 1;
        }
        else {
          wait_count = 0;
          last_recv_num = scanfreq_info.valid_nonce_num[chain];
        }
        usleep(100000);
      }
    }
  }
  gBegin_get_nonce = false;
  return;
}

