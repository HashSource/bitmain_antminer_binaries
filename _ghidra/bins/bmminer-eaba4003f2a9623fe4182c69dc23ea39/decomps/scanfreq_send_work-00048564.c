
void * scanfreq_send_work(void *arg)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  SCAN_FREQ_WORK *pSVar5;
  SCAN_FREQ_WORK *__src;
  void *arg_local;
  char tmp42 [2048];
  uint buf_vil [13];
  vil_work_1387 work_vil_1387;
  SCAN_FREQ_WORK *work;
  SCAN_FREQ_WORK *works;
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
  
  iVar2 = scanfreq_info.CoreNum;
  iVar1 = scanfreq_info.AsicNum;
  work_id = 0;
  buf_vil[0] = 0;
  buf_vil[1] = 0;
  buf_vil[2] = 0;
  buf_vil[3] = 0;
  buf_vil[4] = 0;
  buf_vil[5] = 0;
  buf_vil[6] = 0;
  buf_vil[7] = 0;
  buf_vil[8] = 0;
  buf_vil[9] = 0;
  buf_vil[10] = 0;
  buf_vil[0xb] = 0;
  buf_vil[0xc] = 0;
  if (((use_syslog) || (opt_log_output)) || (4 < opt_log_level)) {
    builtin_strncpy(tmp42,"start send work\n",0x10);
    tmp42._16_4_ = tmp42._16_4_ & 0xffffff00;
    _applog(5,tmp42,false);
  }
  gBegin_get_nonce = true;
  uVar3 = get_nonce_fifo_interrupt();
  set_nonce_fifo_interrupt(uVar3 | 0x10000);
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if ((dev->chain_exist[chain] != 0) && (scanfreq_info.scan_finished[chain] == false)) {
      for (which_asic = 0; which_asic < iVar1; which_asic = which_asic + 1) {
        pSVar5 = scanfreq_info.works[which_asic];
        for (which_core = 0; which_core < iVar2; which_core = which_core + 1) {
          for (which_pattern = 0; iVar4 = __aeabi_idiv(scanfreq_info.AsicWorkCount,iVar2),
              which_pattern < iVar4; which_pattern = which_pattern + 1) {
            while (uVar3 = get_buffer_space(), (uVar3 & 1 << (chain & 0xffU)) == 0) {
              usleep(5000);
            }
            memset(buf_vil,0,0xd);
            iVar4 = __aeabi_idiv(scanfreq_info.AsicWorkCount,iVar2);
            __src = pSVar5 + which_core * iVar4 + which_pattern;
            memset(&work_vil_1387,0,0x34);
            work_vil_1387.work_type = '\x01';
            work_vil_1387.chain_id = (byte)chain | 0x80;
            work_vil_1387.reserved1[0] = '\0';
            work_vil_1387.reserved1[1] = '\0';
            work_id = work_id + 1;
            if (0x7f < work_id) {
              work_id = 0;
            }
            work_vil_1387.work_count = which_pattern << 7 | work_id & 0x7f;
            memcpy(scanfreq_info.send_work + work_id,__src,0x74);
            for (i = 0; i < 0xc; i = i + 1) {
              work_vil_1387.data[i] = __src->data[i];
            }
            for (i = 0; i < 0x20; i = i + 1) {
              work_vil_1387.midstate[i] = __src->midstate[i];
            }
            buf_vil[0] = (uint)work_vil_1387.reserved1[1] |
                         (uint)work_vil_1387.work_type << 0x18 |
                         (uint)work_vil_1387.chain_id << 0x10 |
                         (uint)work_vil_1387.reserved1[0] << 8;
            buf_vil[1] = work_vil_1387.work_count;
            for (j = 2; (uint)j < 5; j = j + 1) {
              buf_vil[j] = (uint)work_vil_1387.reserved1[j * 4 + 1] |
                           (uint)work_vil_1387.reserved1[j * 4 + -2] << 0x18 |
                           (uint)work_vil_1387.reserved1[j * 4 + -1] << 0x10 |
                           (uint)work_vil_1387.reserved1[j * 4] << 8;
            }
            for (j = 5; (uint)j < 0xd; j = j + 1) {
              buf_vil[j] = (uint)work_vil_1387.reserved1[j * 4 + 1] |
                           (uint)work_vil_1387.reserved1[j * 4 + -2] << 0x18 |
                           (uint)work_vil_1387.reserved1[j * 4 + -1] << 0x10 |
                           (uint)work_vil_1387.reserved1[j * 4] << 8;
            }
            set_TW_write_command_vil(buf_vil);
            scanfreq_info.send_work_num[chain] = scanfreq_info.send_work_num[chain] + 1;
          }
        }
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"Chain[%d] send %d works\n",chain,scanfreq_info.send_work_num[chain]);
        _applog(5,tmp42,false);
      }
    }
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    builtin_strncpy(tmp42,"wait for receiving nonce",0x18);
    tmp42[0x18] = '\n';
    tmp42[0x19] = '\0';
    _applog(5,tmp42,false);
  }
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if ((dev->chain_exist[chain] != 0) && (scanfreq_info.scan_finished[chain] == false)) {
      last_recv_num = 0;
      wait_count = 0;
      while ((wait_count < 3 &&
             (scanfreq_info.valid_nonce_num[chain] < scanfreq_info.RequiredChainNonce))) {
        if (scanfreq_info.valid_nonce_num[chain] == last_recv_num) {
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
  return &gBegin_get_nonce;
}

