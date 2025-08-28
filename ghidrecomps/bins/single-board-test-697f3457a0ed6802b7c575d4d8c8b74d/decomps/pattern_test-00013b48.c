
int pattern_test(runtime_base_t *runtime,int freq,int *nonce)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *nonce_local;
  int freq_local;
  runtime_base_t *runtime_local;
  char tmp42 [1024];
  char golden [20];
  char result [20];
  bm174x_reg pt_result_reg;
  uint8_t header_bin [140];
  reg_list_item_t item;
  char *header;
  int read_timeout_limit;
  int chainid;
  int read_timeout_counter;
  FILE *fpr;
  FILE *fpg;
  int match_num;
  int i;
  
  iVar3 = runtime->chain_id;
  match_num = 0;
  fpg = (FILE *)0x0;
  fpr = (FILE *)0x0;
  remove("./pattern_result.txt");
  (*runtime->set_pt_ctrl)(runtime->chain_status[iVar3].fd,0,0);
  usleep(100000);
  (*runtime->set_ticket_mask)(runtime->chain_status[iVar3].fd,5);
  usleep(100000);
  (*runtime->set_core_timeout)(runtime->chain_status[iVar3].fd,45000);
  usleep(100000);
  (*runtime->set_txn_data)(runtime->chain_status[iVar3].fd,0);
  usleep(100000);
  (*runtime->set_frequency)(runtime->chain_status[iVar3].fd,freq);
  usleep(100000);
  (*runtime->set_pt_ctrl)(runtime->chain_status[iVar3].fd,0x7ff,1);
  usleep(100000);
  memset(header_bin,0,0x8c);
  hex2bin(header_bin,
          "010203042cb3d32b0b61304401cbe540448a4cacd7e98421a850503e2f0d102f1d3454151484151215484aa0ca1932037525e2eb9a22d3d3ff1502b320f8d9ca56377f56494b2cacf3377482ccd34188c1b25e04187ccf70af6e2244c3c96e5e2e3a6015d32fe451ad000e771eccb5c5e3d6beb470359446494d25e15f87df87c3119ebd9ca813a400000000"
          ,0x8c);
  user_send_work(runtime,header_bin,0,0);
  sleep(3);
  item.age = 3;
  item.chainid = '\0';
  item.chip_addr = '\0';
  item.reg_addr = '`';
  read_timeout_counter = 0;
  while (read_timeout_counter < 0xf) {
    (*runtime->read_register)(runtime->chain_status[iVar3].fd,1,'\0','`');
    iVar2 = read_reg_item(&item,500);
    uVar1 = tmp42._20_4_;
    if (iVar2 < 1) {
      if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
        builtin_strncpy(tmp42,"REG_PT_RESULT read timeout\n",0x1c);
        _applog(0,tmp42,false);
      }
    }
    else {
      pt_result_reg.core_timeout.core_timeout._2_2_ = (undefined2)(item.reg_data >> 0x10);
      if ((pt_result_reg.core_timeout.core_timeout._2_2_ & 0xfff) == 0x800) {
        if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
          builtin_strncpy(tmp42,"pattern test finished\n",0x17);
          tmp42[0x17] = SUB41(uVar1,3);
          _applog(2,tmp42,false);
        }
        break;
      }
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (3 < opt_log_level)))) {
        snprintf(tmp42,0x400,"REG_PT_RESULT cur num = %d < 0x800, check again\n",
                 (ushort)pt_result_reg.core_timeout.core_timeout._2_2_ & 0xfff);
        _applog(4,tmp42,false);
      }
    }
    read_timeout_counter = read_timeout_counter + 1;
    sleep(1);
  }
  uVar1 = tmp42._36_4_;
  if (read_timeout_counter < 0xf) {
    if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
      builtin_strncpy(tmp42,"pattern test finished, read out nonce\n",0x27);
      tmp42[0x27] = SUB41(uVar1,3);
      _applog(0,tmp42,false);
    }
    for (i = 0; i < 0x10; i = i + 1) {
      (*runtime->set_pt_result)(runtime->chain_status[iVar3].fd,i,1);
      usleep(200000);
    }
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      builtin_strncpy(tmp42,"Compare golden nonce and current nonce\n",0x28);
      _applog(2,tmp42,false);
    }
    fpr = (FILE *)fopen("./pattern_result.txt","r");
    if (fpr == (FILE *)0x0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
        builtin_strncpy(tmp42,"open failed pattern_result.txt\n",0x20);
        _applog(0,tmp42,false);
      }
    }
    else {
      fpg = (FILE *)fopen("./pattern_golden.txt","r");
      if (fpg == (FILE *)0x0) {
        if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
          builtin_strncpy(tmp42,"open failed pattern_golden.txt\n",0x20);
          _applog(0,tmp42,false);
        }
      }
      else {
LAB_000141b0:
        iVar3 = feof((FILE *)fpr);
        if (iVar3 == 0) {
          result[0] = '\0';
          result[1] = '\0';
          result[2] = '\0';
          result[3] = '\0';
          result[4] = '\0';
          result[5] = '\0';
          result[6] = '\0';
          result[7] = '\0';
          result[8] = '\0';
          result[9] = '\0';
          result[10] = '\0';
          result[0xb] = '\0';
          result[0xc] = '\0';
          result[0xd] = '\0';
          result[0xe] = '\0';
          result[0xf] = '\0';
          result[0x10] = '\0';
          result[0x11] = '\0';
          result[0x12] = '\0';
          result[0x13] = '\0';
          fgets(result,0x400,(FILE *)fpr);
          fseek((FILE *)fpg,0,0);
          do {
            iVar3 = feof((FILE *)fpg);
            if (iVar3 != 0) goto LAB_000141b0;
            golden[0] = '\0';
            golden[1] = '\0';
            golden[2] = '\0';
            golden[3] = '\0';
            golden[4] = '\0';
            golden[5] = '\0';
            golden[6] = '\0';
            golden[7] = '\0';
            golden[8] = '\0';
            golden[9] = '\0';
            golden[10] = '\0';
            golden[0xb] = '\0';
            golden[0xc] = '\0';
            golden[0xd] = '\0';
            golden[0xe] = '\0';
            golden[0xf] = '\0';
            golden[0x10] = '\0';
            golden[0x11] = '\0';
            golden[0x12] = '\0';
            golden[0x13] = '\0';
            fgets(golden,0x400,(FILE *)fpg);
            iVar3 = strncmp(golden,result,0x10);
          } while ((iVar3 != 0) || (golden[0] == '\0'));
          match_num = match_num + 1;
          goto LAB_000141b0;
        }
      }
    }
  }
  else if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    builtin_strncpy(tmp42,"patten test timeout\n",0x14);
    tmp42._20_4_ = tmp42._20_4_ & 0xffffff00;
    _applog(2,tmp42,false);
  }
  if (fpg != (FILE *)0x0) {
    fclose((FILE *)fpg);
  }
  if (fpr != (FILE *)0x0) {
    fclose((FILE *)fpr);
  }
  *nonce = match_num;
  return 0;
}

