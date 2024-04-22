
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int pattern_test(runtime_base_t *runtime,int freq,int *nonce)

{
  int iVar1;
  int iVar2;
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
  
  iVar2 = runtime->chain_id;
  match_num = 0;
  fpg = (FILE *)0x0;
  fpr = (FILE *)0x0;
  remove("./pattern_result.txt");
  (*runtime->set_pt_ctrl)(runtime->chain_status[iVar2].fd,0,0);
  usleep(100000);
  (*runtime->set_ticket_mask)(runtime->chain_status[iVar2].fd,5);
  usleep(100000);
  (*runtime->set_core_timeout)(runtime->chain_status[iVar2].fd,45000);
  usleep(100000);
  (*runtime->set_txn_data)(runtime->chain_status[iVar2].fd,0);
  usleep(100000);
  (*runtime->set_frequency)(runtime->chain_status[iVar2].fd,freq);
  usleep(100000);
  (*runtime->set_pt_ctrl)(runtime->chain_status[iVar2].fd,0x7ff,1);
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
    (*runtime->read_register)(runtime->chain_status[iVar2].fd,1,'\0','`');
    iVar1 = read_reg_item(&item,500);
    if (iVar1 < 1) {
      if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
        tmp42[0] = s_REG_PT_RESULT_read_timeout_000344a0[0];
        tmp42[1] = s_REG_PT_RESULT_read_timeout_000344a0[1];
        tmp42[2] = s_REG_PT_RESULT_read_timeout_000344a0[2];
        tmp42[3] = s_REG_PT_RESULT_read_timeout_000344a0[3];
        tmp42[4] = s_REG_PT_RESULT_read_timeout_000344a0[4];
        tmp42[5] = s_REG_PT_RESULT_read_timeout_000344a0[5];
        tmp42[6] = s_REG_PT_RESULT_read_timeout_000344a0[6];
        tmp42[7] = s_REG_PT_RESULT_read_timeout_000344a0[7];
        tmp42[8] = s_REG_PT_RESULT_read_timeout_000344a0[8];
        tmp42[9] = s_REG_PT_RESULT_read_timeout_000344a0[9];
        tmp42[10] = s_REG_PT_RESULT_read_timeout_000344a0[10];
        tmp42[11] = s_REG_PT_RESULT_read_timeout_000344a0[11];
        tmp42[12] = s_REG_PT_RESULT_read_timeout_000344a0[12];
        tmp42[13] = s_REG_PT_RESULT_read_timeout_000344a0[13];
        tmp42[14] = s_REG_PT_RESULT_read_timeout_000344a0[14];
        tmp42[15] = s_REG_PT_RESULT_read_timeout_000344a0[15];
        tmp42[16] = s_REG_PT_RESULT_read_timeout_000344a0[16];
        tmp42[17] = s_REG_PT_RESULT_read_timeout_000344a0[17];
        tmp42[18] = s_REG_PT_RESULT_read_timeout_000344a0[18];
        tmp42[19] = s_REG_PT_RESULT_read_timeout_000344a0[19];
        tmp42[20] = s_REG_PT_RESULT_read_timeout_000344a0[20];
        tmp42[21] = s_REG_PT_RESULT_read_timeout_000344a0[21];
        tmp42[22] = s_REG_PT_RESULT_read_timeout_000344a0[22];
        tmp42[23] = s_REG_PT_RESULT_read_timeout_000344a0[23];
        tmp42[24] = s_REG_PT_RESULT_read_timeout_000344a0[24];
        tmp42[25] = s_REG_PT_RESULT_read_timeout_000344a0[25];
        tmp42[26] = s_REG_PT_RESULT_read_timeout_000344a0[26];
        tmp42[27] = s_REG_PT_RESULT_read_timeout_000344a0[27];
        _applog(0,tmp42,false);
      }
    }
    else {
      pt_result_reg.core_timeout.core_timeout._2_2_ = (undefined2)(item.reg_data >> 0x10);
      if ((pt_result_reg.core_timeout.core_timeout._2_2_ & 0xfff) == 0x800) {
        if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
          tmp42[0] = s_pattern_test_finished_00034454[0];
          tmp42[1] = s_pattern_test_finished_00034454[1];
          tmp42[2] = s_pattern_test_finished_00034454[2];
          tmp42[3] = s_pattern_test_finished_00034454[3];
          tmp42[4] = s_pattern_test_finished_00034454[4];
          tmp42[5] = s_pattern_test_finished_00034454[5];
          tmp42[6] = s_pattern_test_finished_00034454[6];
          tmp42[7] = s_pattern_test_finished_00034454[7];
          tmp42[8] = s_pattern_test_finished_00034454[8];
          tmp42[9] = s_pattern_test_finished_00034454[9];
          tmp42[10] = s_pattern_test_finished_00034454[10];
          tmp42[11] = s_pattern_test_finished_00034454[11];
          tmp42[12] = s_pattern_test_finished_00034454[12];
          tmp42[13] = s_pattern_test_finished_00034454[13];
          tmp42[14] = s_pattern_test_finished_00034454[14];
          tmp42[15] = s_pattern_test_finished_00034454[15];
          tmp42[16] = s_pattern_test_finished_00034454[16];
          tmp42[17] = s_pattern_test_finished_00034454[17];
          tmp42[18] = s_pattern_test_finished_00034454[18];
          tmp42[19] = s_pattern_test_finished_00034454[19];
          tmp42._20_3_ = (undefined3)ram0x00034468;
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
  if (read_timeout_counter < 0xf) {
    if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
      tmp42[0] = s_pattern_test_finished__read_out_n_000344d4[0];
      tmp42[1] = s_pattern_test_finished__read_out_n_000344d4[1];
      tmp42[2] = s_pattern_test_finished__read_out_n_000344d4[2];
      tmp42[3] = s_pattern_test_finished__read_out_n_000344d4[3];
      tmp42[4] = s_pattern_test_finished__read_out_n_000344d4[4];
      tmp42[5] = s_pattern_test_finished__read_out_n_000344d4[5];
      tmp42[6] = s_pattern_test_finished__read_out_n_000344d4[6];
      tmp42[7] = s_pattern_test_finished__read_out_n_000344d4[7];
      tmp42[8] = s_pattern_test_finished__read_out_n_000344d4[8];
      tmp42[9] = s_pattern_test_finished__read_out_n_000344d4[9];
      tmp42[10] = s_pattern_test_finished__read_out_n_000344d4[10];
      tmp42[11] = s_pattern_test_finished__read_out_n_000344d4[11];
      tmp42[12] = s_pattern_test_finished__read_out_n_000344d4[12];
      tmp42[13] = s_pattern_test_finished__read_out_n_000344d4[13];
      tmp42[14] = s_pattern_test_finished__read_out_n_000344d4[14];
      tmp42[15] = s_pattern_test_finished__read_out_n_000344d4[15];
      tmp42[16] = s_pattern_test_finished__read_out_n_000344d4[16];
      tmp42[17] = s_pattern_test_finished__read_out_n_000344d4[17];
      tmp42[18] = s_pattern_test_finished__read_out_n_000344d4[18];
      tmp42[19] = s_pattern_test_finished__read_out_n_000344d4[19];
      tmp42[20] = s_pattern_test_finished__read_out_n_000344d4[20];
      tmp42[21] = s_pattern_test_finished__read_out_n_000344d4[21];
      tmp42[22] = s_pattern_test_finished__read_out_n_000344d4[22];
      tmp42[23] = s_pattern_test_finished__read_out_n_000344d4[23];
      tmp42[24] = s_pattern_test_finished__read_out_n_000344d4[24];
      tmp42[25] = s_pattern_test_finished__read_out_n_000344d4[25];
      tmp42[26] = s_pattern_test_finished__read_out_n_000344d4[26];
      tmp42[27] = s_pattern_test_finished__read_out_n_000344d4[27];
      tmp42[28] = s_pattern_test_finished__read_out_n_000344d4[28];
      tmp42[29] = s_pattern_test_finished__read_out_n_000344d4[29];
      tmp42[30] = s_pattern_test_finished__read_out_n_000344d4[30];
      tmp42[31] = s_pattern_test_finished__read_out_n_000344d4[31];
      tmp42[32] = s_pattern_test_finished__read_out_n_000344d4[32];
      tmp42[33] = s_pattern_test_finished__read_out_n_000344d4[33];
      tmp42[34] = s_pattern_test_finished__read_out_n_000344d4[34];
      tmp42[35] = s_pattern_test_finished__read_out_n_000344d4[35];
      tmp42._36_3_ = (undefined3)ram0x000344f8;
      _applog(0,tmp42,false);
    }
    for (i = 0; i < 0x10; i = i + 1) {
      (*runtime->set_pt_result)(runtime->chain_status[iVar2].fd,i,1);
      usleep(200000);
    }
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      tmp42[0] = s_Compare_golden_nonce_and_current_000344fc[0];
      tmp42[1] = s_Compare_golden_nonce_and_current_000344fc[1];
      tmp42[2] = s_Compare_golden_nonce_and_current_000344fc[2];
      tmp42[3] = s_Compare_golden_nonce_and_current_000344fc[3];
      tmp42[4] = s_Compare_golden_nonce_and_current_000344fc[4];
      tmp42[5] = s_Compare_golden_nonce_and_current_000344fc[5];
      tmp42[6] = s_Compare_golden_nonce_and_current_000344fc[6];
      tmp42[7] = s_Compare_golden_nonce_and_current_000344fc[7];
      tmp42[8] = s_Compare_golden_nonce_and_current_000344fc[8];
      tmp42[9] = s_Compare_golden_nonce_and_current_000344fc[9];
      tmp42[10] = s_Compare_golden_nonce_and_current_000344fc[10];
      tmp42[11] = s_Compare_golden_nonce_and_current_000344fc[11];
      tmp42[12] = s_Compare_golden_nonce_and_current_000344fc[12];
      tmp42[13] = s_Compare_golden_nonce_and_current_000344fc[13];
      tmp42[14] = s_Compare_golden_nonce_and_current_000344fc[14];
      tmp42[15] = s_Compare_golden_nonce_and_current_000344fc[15];
      tmp42[16] = s_Compare_golden_nonce_and_current_000344fc[16];
      tmp42[17] = s_Compare_golden_nonce_and_current_000344fc[17];
      tmp42[18] = s_Compare_golden_nonce_and_current_000344fc[18];
      tmp42[19] = s_Compare_golden_nonce_and_current_000344fc[19];
      tmp42[20] = s_Compare_golden_nonce_and_current_000344fc[20];
      tmp42[21] = s_Compare_golden_nonce_and_current_000344fc[21];
      tmp42[22] = s_Compare_golden_nonce_and_current_000344fc[22];
      tmp42[23] = s_Compare_golden_nonce_and_current_000344fc[23];
      tmp42[24] = s_Compare_golden_nonce_and_current_000344fc[24];
      tmp42[25] = s_Compare_golden_nonce_and_current_000344fc[25];
      tmp42[26] = s_Compare_golden_nonce_and_current_000344fc[26];
      tmp42[27] = s_Compare_golden_nonce_and_current_000344fc[27];
      tmp42[28] = s_Compare_golden_nonce_and_current_000344fc[28];
      tmp42[29] = s_Compare_golden_nonce_and_current_000344fc[29];
      tmp42[30] = s_Compare_golden_nonce_and_current_000344fc[30];
      tmp42[31] = s_Compare_golden_nonce_and_current_000344fc[31];
      tmp42[32] = s_Compare_golden_nonce_and_current_000344fc[32];
      tmp42[33] = s_Compare_golden_nonce_and_current_000344fc[33];
      tmp42[34] = s_Compare_golden_nonce_and_current_000344fc[34];
      tmp42[35] = s_Compare_golden_nonce_and_current_000344fc[35];
      tmp42[36] = s_Compare_golden_nonce_and_current_000344fc[36];
      tmp42[37] = s_Compare_golden_nonce_and_current_000344fc[37];
      tmp42[38] = s_Compare_golden_nonce_and_current_000344fc[38];
      tmp42[39] = s_Compare_golden_nonce_and_current_000344fc[39];
      _applog(2,tmp42,false);
    }
    fpr = (FILE *)fopen("./pattern_result.txt","r");
    if (fpr == (FILE *)0x0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
        tmp42[0] = s_open_failed_pattern_result_txt_00034528[0];
        tmp42[1] = s_open_failed_pattern_result_txt_00034528[1];
        tmp42[2] = s_open_failed_pattern_result_txt_00034528[2];
        tmp42[3] = s_open_failed_pattern_result_txt_00034528[3];
        tmp42[4] = s_open_failed_pattern_result_txt_00034528[4];
        tmp42[5] = s_open_failed_pattern_result_txt_00034528[5];
        tmp42[6] = s_open_failed_pattern_result_txt_00034528[6];
        tmp42[7] = s_open_failed_pattern_result_txt_00034528[7];
        tmp42[8] = s_open_failed_pattern_result_txt_00034528[8];
        tmp42[9] = s_open_failed_pattern_result_txt_00034528[9];
        tmp42[10] = s_open_failed_pattern_result_txt_00034528[10];
        tmp42[11] = s_open_failed_pattern_result_txt_00034528[11];
        tmp42[12] = s_open_failed_pattern_result_txt_00034528[12];
        tmp42[13] = s_open_failed_pattern_result_txt_00034528[13];
        tmp42[14] = s_open_failed_pattern_result_txt_00034528[14];
        tmp42[15] = s_open_failed_pattern_result_txt_00034528[15];
        tmp42[16] = s_open_failed_pattern_result_txt_00034528[16];
        tmp42[17] = s_open_failed_pattern_result_txt_00034528[17];
        tmp42[18] = s_open_failed_pattern_result_txt_00034528[18];
        tmp42[19] = s_open_failed_pattern_result_txt_00034528[19];
        tmp42[20] = s_open_failed_pattern_result_txt_00034528[20];
        tmp42[21] = s_open_failed_pattern_result_txt_00034528[21];
        tmp42[22] = s_open_failed_pattern_result_txt_00034528[22];
        tmp42[23] = s_open_failed_pattern_result_txt_00034528[23];
        tmp42[24] = s_open_failed_pattern_result_txt_00034528[24];
        tmp42[25] = s_open_failed_pattern_result_txt_00034528[25];
        tmp42[26] = s_open_failed_pattern_result_txt_00034528[26];
        tmp42[27] = s_open_failed_pattern_result_txt_00034528[27];
        tmp42[28] = s_open_failed_pattern_result_txt_00034528[28];
        tmp42[29] = s_open_failed_pattern_result_txt_00034528[29];
        tmp42[30] = s_open_failed_pattern_result_txt_00034528[30];
        tmp42[31] = s_open_failed_pattern_result_txt_00034528[31];
        _applog(0,tmp42,false);
      }
    }
    else {
      fpg = (FILE *)fopen("./pattern_golden.txt","r");
      if (fpg == (FILE *)0x0) {
        if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
          tmp42[0] = s_open_failed_pattern_golden_txt_00034560[0];
          tmp42[1] = s_open_failed_pattern_golden_txt_00034560[1];
          tmp42[2] = s_open_failed_pattern_golden_txt_00034560[2];
          tmp42[3] = s_open_failed_pattern_golden_txt_00034560[3];
          tmp42[4] = s_open_failed_pattern_golden_txt_00034560[4];
          tmp42[5] = s_open_failed_pattern_golden_txt_00034560[5];
          tmp42[6] = s_open_failed_pattern_golden_txt_00034560[6];
          tmp42[7] = s_open_failed_pattern_golden_txt_00034560[7];
          tmp42[8] = s_open_failed_pattern_golden_txt_00034560[8];
          tmp42[9] = s_open_failed_pattern_golden_txt_00034560[9];
          tmp42[10] = s_open_failed_pattern_golden_txt_00034560[10];
          tmp42[11] = s_open_failed_pattern_golden_txt_00034560[11];
          tmp42[12] = s_open_failed_pattern_golden_txt_00034560[12];
          tmp42[13] = s_open_failed_pattern_golden_txt_00034560[13];
          tmp42[14] = s_open_failed_pattern_golden_txt_00034560[14];
          tmp42[15] = s_open_failed_pattern_golden_txt_00034560[15];
          tmp42[16] = s_open_failed_pattern_golden_txt_00034560[16];
          tmp42[17] = s_open_failed_pattern_golden_txt_00034560[17];
          tmp42[18] = s_open_failed_pattern_golden_txt_00034560[18];
          tmp42[19] = s_open_failed_pattern_golden_txt_00034560[19];
          tmp42[20] = s_open_failed_pattern_golden_txt_00034560[20];
          tmp42[21] = s_open_failed_pattern_golden_txt_00034560[21];
          tmp42[22] = s_open_failed_pattern_golden_txt_00034560[22];
          tmp42[23] = s_open_failed_pattern_golden_txt_00034560[23];
          tmp42[24] = s_open_failed_pattern_golden_txt_00034560[24];
          tmp42[25] = s_open_failed_pattern_golden_txt_00034560[25];
          tmp42[26] = s_open_failed_pattern_golden_txt_00034560[26];
          tmp42[27] = s_open_failed_pattern_golden_txt_00034560[27];
          tmp42[28] = s_open_failed_pattern_golden_txt_00034560[28];
          tmp42[29] = s_open_failed_pattern_golden_txt_00034560[29];
          tmp42[30] = s_open_failed_pattern_golden_txt_00034560[30];
          tmp42[31] = s_open_failed_pattern_golden_txt_00034560[31];
          _applog(0,tmp42,false);
        }
      }
      else {
LAB_000141b0:
        iVar2 = feof((FILE *)fpr);
        if (iVar2 == 0) {
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
          result[11] = '\0';
          result[12] = '\0';
          result[13] = '\0';
          result[14] = '\0';
          result[15] = '\0';
          result[16] = '\0';
          result[17] = '\0';
          result[18] = '\0';
          result[19] = '\0';
          fgets(result,0x400,(FILE *)fpr);
          fseek((FILE *)fpg,0,0);
          do {
            iVar2 = feof((FILE *)fpg);
            if (iVar2 != 0) goto LAB_000141b0;
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
            golden[11] = '\0';
            golden[12] = '\0';
            golden[13] = '\0';
            golden[14] = '\0';
            golden[15] = '\0';
            golden[16] = '\0';
            golden[17] = '\0';
            golden[18] = '\0';
            golden[19] = '\0';
            fgets(golden,0x400,(FILE *)fpg);
            iVar2 = strncmp(golden,result,0x10);
          } while ((iVar2 != 0) || (golden[0] == '\0'));
          match_num = match_num + 1;
          goto LAB_000141b0;
        }
      }
    }
  }
  else if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    tmp42[0] = s_patten_test_timeout_000344bc[0];
    tmp42[1] = s_patten_test_timeout_000344bc[1];
    tmp42[2] = s_patten_test_timeout_000344bc[2];
    tmp42[3] = s_patten_test_timeout_000344bc[3];
    tmp42[4] = s_patten_test_timeout_000344bc[4];
    tmp42[5] = s_patten_test_timeout_000344bc[5];
    tmp42[6] = s_patten_test_timeout_000344bc[6];
    tmp42[7] = s_patten_test_timeout_000344bc[7];
    tmp42[8] = s_patten_test_timeout_000344bc[8];
    tmp42[9] = s_patten_test_timeout_000344bc[9];
    tmp42[10] = s_patten_test_timeout_000344bc[10];
    tmp42[11] = s_patten_test_timeout_000344bc[11];
    tmp42[12] = s_patten_test_timeout_000344bc[12];
    tmp42[13] = s_patten_test_timeout_000344bc[13];
    tmp42[14] = s_patten_test_timeout_000344bc[14];
    tmp42[15] = s_patten_test_timeout_000344bc[15];
    tmp42[16] = s_patten_test_timeout_000344bc[16];
    tmp42[17] = s_patten_test_timeout_000344bc[17];
    tmp42[18] = s_patten_test_timeout_000344bc[18];
    tmp42[19] = s_patten_test_timeout_000344bc[19];
    tmp42[20] = (char)ram0x000344d0;
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

