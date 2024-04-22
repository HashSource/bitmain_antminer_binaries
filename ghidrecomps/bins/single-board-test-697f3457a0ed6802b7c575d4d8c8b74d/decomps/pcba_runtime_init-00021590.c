
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void pcba_runtime_init(runtime_base_t *runtime)

{
  int iVar1;
  int iVar2;
  runtime_base_t *runtime_local;
  char tmp42 [1024];
  int bt8d;
  int chainid;
  
  iVar2 = runtime->chain_id;
  runtime->chain_status[iVar2].design_asic_num = app_conf->asic_num;
  reg_list_init();
  work_list_init((runtime->nonce_verify_info).work_len);
  iVar1 = uart_init(runtime->chain_status[iVar2].comport,0x1c200);
  runtime->chain_status[iVar2].fd = iVar1;
  sleep(1);
  if (runtime->baudrate != 0x1c200) {
    iVar1 = baud2bt8d(runtime->baudrate);
    if (iVar1 < 1) {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        tmp42[0] = s_Don_t_support_current_baudrate__s_000367e0[0];
        tmp42[1] = s_Don_t_support_current_baudrate__s_000367e0[1];
        tmp42[2] = s_Don_t_support_current_baudrate__s_000367e0[2];
        tmp42[3] = s_Don_t_support_current_baudrate__s_000367e0[3];
        tmp42[4] = s_Don_t_support_current_baudrate__s_000367e0[4];
        tmp42[5] = s_Don_t_support_current_baudrate__s_000367e0[5];
        tmp42[6] = s_Don_t_support_current_baudrate__s_000367e0[6];
        tmp42[7] = s_Don_t_support_current_baudrate__s_000367e0[7];
        tmp42[8] = s_Don_t_support_current_baudrate__s_000367e0[8];
        tmp42[9] = s_Don_t_support_current_baudrate__s_000367e0[9];
        tmp42[10] = s_Don_t_support_current_baudrate__s_000367e0[10];
        tmp42[11] = s_Don_t_support_current_baudrate__s_000367e0[11];
        tmp42[12] = s_Don_t_support_current_baudrate__s_000367e0[12];
        tmp42[13] = s_Don_t_support_current_baudrate__s_000367e0[13];
        tmp42[14] = s_Don_t_support_current_baudrate__s_000367e0[14];
        tmp42[15] = s_Don_t_support_current_baudrate__s_000367e0[15];
        tmp42[16] = s_Don_t_support_current_baudrate__s_000367e0[16];
        tmp42[17] = s_Don_t_support_current_baudrate__s_000367e0[17];
        tmp42[18] = s_Don_t_support_current_baudrate__s_000367e0[18];
        tmp42[19] = s_Don_t_support_current_baudrate__s_000367e0[19];
        tmp42[20] = s_Don_t_support_current_baudrate__s_000367e0[20];
        tmp42[21] = s_Don_t_support_current_baudrate__s_000367e0[21];
        tmp42[22] = s_Don_t_support_current_baudrate__s_000367e0[22];
        tmp42[23] = s_Don_t_support_current_baudrate__s_000367e0[23];
        tmp42[24] = s_Don_t_support_current_baudrate__s_000367e0[24];
        tmp42[25] = s_Don_t_support_current_baudrate__s_000367e0[25];
        tmp42[26] = s_Don_t_support_current_baudrate__s_000367e0[26];
        tmp42[27] = s_Don_t_support_current_baudrate__s_000367e0[27];
        tmp42[28] = s_Don_t_support_current_baudrate__s_000367e0[28];
        tmp42[29] = s_Don_t_support_current_baudrate__s_000367e0[29];
        tmp42[30] = s_Don_t_support_current_baudrate__s_000367e0[30];
        tmp42[31] = s_Don_t_support_current_baudrate__s_000367e0[31];
        tmp42[32] = s_Don_t_support_current_baudrate__s_000367e0[32];
        tmp42[33] = s_Don_t_support_current_baudrate__s_000367e0[33];
        tmp42[34] = s_Don_t_support_current_baudrate__s_000367e0[34];
        tmp42[35] = s_Don_t_support_current_baudrate__s_000367e0[35];
        tmp42[36] = s_Don_t_support_current_baudrate__s_000367e0[36];
        tmp42[37] = s_Don_t_support_current_baudrate__s_000367e0[37];
        tmp42[38] = s_Don_t_support_current_baudrate__s_000367e0[38];
        tmp42[39] = s_Don_t_support_current_baudrate__s_000367e0[39];
        tmp42[40] = s_Don_t_support_current_baudrate__s_000367e0[40];
        tmp42[41] = s_Don_t_support_current_baudrate__s_000367e0[41];
        tmp42[42] = s_Don_t_support_current_baudrate__s_000367e0[42];
        tmp42[43] = s_Don_t_support_current_baudrate__s_000367e0[43];
        tmp42._44_2_ = (undefined2)ram0x0003680c;
        tmp42[46] = (char)((uint)ram0x0003680c >> 0x10);
        _applog(2,tmp42,false);
      }
    }
    else {
      (*runtime->set_baud)(runtime->chain_status[iVar2].fd,runtime->baudrate);
      usleep(200000);
      set_fpga_baud((uchar)iVar1);
      sleep(1);
    }
  }
  pthread_create(&runtime->chain_status[iVar2].p_dispatch,(pthread_attr_t *)0x0,
                 handle_asic_response + 1,runtime);
  sleep(1);
  pthread_create(&runtime->p_scanhash,(pthread_attr_t *)0x0,check_nonce_loop + 1,runtime);
  runtime->start_recv = 1;
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"%s Done!\n","pcba_runtime_init");
    _applog(2,tmp42,false);
  }
  return;
}

