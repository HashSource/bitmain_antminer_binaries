
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int user_asic_init(runtime_base_t *runtime)

{
  int iVar1;
  int iVar2;
  runtime_base_t *runtime_local;
  char tmp42 [1024];
  int chainid;
  int check_times;
  
  iVar2 = runtime->chain_id;
  check_times = 3;
  do {
    check_asic_num(runtime);
    if (0 < runtime->chain_status[iVar2].real_asic_num) break;
    sleep(1);
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"check again check_times = %d\n",check_times);
      _applog(2,tmp42,false);
    }
    check_times = check_times + -1;
  } while (0 < check_times);
  if (check_times < 1) {
    if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
      tmp42[0] = s_check_asic_failed_000345c0[0];
      tmp42[1] = s_check_asic_failed_000345c0[1];
      tmp42[2] = s_check_asic_failed_000345c0[2];
      tmp42[3] = s_check_asic_failed_000345c0[3];
      tmp42[4] = s_check_asic_failed_000345c0[4];
      tmp42[5] = s_check_asic_failed_000345c0[5];
      tmp42[6] = s_check_asic_failed_000345c0[6];
      tmp42[7] = s_check_asic_failed_000345c0[7];
      tmp42[8] = s_check_asic_failed_000345c0[8];
      tmp42[9] = s_check_asic_failed_000345c0[9];
      tmp42[10] = s_check_asic_failed_000345c0[10];
      tmp42[11] = s_check_asic_failed_000345c0[11];
      tmp42[12] = s_check_asic_failed_000345c0[12];
      tmp42[13] = s_check_asic_failed_000345c0[13];
      tmp42[14] = s_check_asic_failed_000345c0[14];
      tmp42[15] = s_check_asic_failed_000345c0[15];
      tmp42._16_2_ = (undefined2)ram0x000345d0;
      tmp42[18] = (char)((uint)ram0x000345d0 >> 0x10);
      _applog(0,tmp42,false);
    }
    iVar2 = -1;
  }
  else {
    runtime->start_recv = 0;
    if (runtime->baudrate != 0x1c200) {
      sleep(1);
      (*runtime->set_baud)(runtime->chain_status[iVar2].fd,runtime->baudrate);
      sleep(1);
      uart_exit(runtime->chain_status[iVar2].fd);
      sleep(1);
      iVar1 = uart_init(runtime->chain_status[iVar2].comport,runtime->baudrate);
      runtime->chain_status[iVar2].fd = iVar1;
      sleep(1);
    }
    runtime->start_recv = 1;
    iVar2 = 0;
  }
  return iVar2;
}

