
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int scanfreq_init(int max_freq)

{
  all_parameters *paVar1;
  uint uVar2;
  int iVar3;
  float fVar4;
  int max_freq_local;
  char tmp42 [2048];
  float freq_step;
  float final_freq;
  float init_freq;
  int hardware_version;
  int open_core_temp;
  int pre_heat_temp;
  _Bool pre_heat_finished;
  _Bool need_pre_heat;
  int i;
  int chain;
  
  if (((use_syslog) || (opt_log_output)) || (4 < opt_log_level)) {
    tmp42._0_4_ = s_scanfreq_init_000781a4._0_4_;
    tmp42._4_4_ = s_scanfreq_init_000781a4._4_4_;
    tmp42._8_4_ = s_scanfreq_init_000781a4._8_4_;
    tmp42._12_2_ = (undefined2)ram0x000781b0;
    tmp42[14] = (char)((uint)ram0x000781b0 >> 0x10);
    _applog(5,tmp42,false);
  }
  set_QN_write_data_command(0x8080800f);
  sleep(2);
  set_Hardware_version(0x40000000);
  read_fpga_id(FPGA_ID_str);
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"miner ID : %s\n",FPGA_ID_str);
    _applog(5,tmp42,false);
  }
  uVar2 = get_hardware_version();
  pcb_version = (int)uVar2 >> 0x10 & 0x7fff;
  fpga_version = uVar2 & 0xff;
  fpga_major_version = uVar2 >> 8 & 0xff;
  sprintf(g_miner_version,"%d.%d.%d.%d",(fpga_major_version - 0xc5U) * 0x100 + fpga_version,
          pcb_version,1,3);
  set_nonce2_and_job_id_store_address(PHY_MEM_NONCE2_JOBID_ADDRESS);
  set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
  set_PWM('d');
  puts("rst harshboard down...");
  sleep(1);
  reset_down_hash_board();
  puts("===Init PIC===");
  scanfreq_init_pic();
  pic_heart_beat = (thr_info *)calloc(1,0x40);
  iVar3 = thr_info_create(pic_heart_beat,(pthread_attr_t *)0x0,pic_heart_beat_func + 1,
                          pic_heart_beat);
  if (iVar3 == 0) {
    pthread_detach(pic_heart_beat->pth);
    set_reset_allhashboard(1);
    sleep(3);
    puts("===Power on===");
    scanfreq_set_voltage_75j(g_opencore_vol);
    sleep(1);
    puts("rst harshboard up...");
    reset_up_hash_board();
    sleep(1);
    puts("==reset 2nd==");
    sleep(1);
    reset_hash_board();
    usleep(500000);
    if (opt_multi_version != 0) {
      uVar2 = get_dhash_acc_control();
      set_dhash_acc_control(uVar2 & 0xffff70df | 0x8100);
    }
    cgsleep_ms(10);
    dev->corenum = 0xd0;
    scanfreq_check_asic_num();
    puts("===Scan Chip Done===!");
    sleep(2);
    software_set_address(2);
    cgsleep_ms(10);
    set_baud('\x01',1);
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      snprintf(tmp42,0x800,"set baud=%d\n",1);
      _applog(5,tmp42,false);
    }
    cgsleep_ms(10);
    for (i = 0; i < 0x10; i = i + 1) {
      if ((dev->chain_exist[i] == 1) && (dev->chain_asic_num[i] == 'l')) {
        calibration_sensor_offset(0x98,i);
        cgsleep_ms(10);
      }
    }
    read_temp_id = (thr_info *)calloc(1,0x40);
    iVar3 = thr_info_create(read_temp_id,(pthread_attr_t *)0x0,scanfreq_read_temp_func + 1,
                            read_temp_id);
    if (iVar3 == 0) {
      pthread_detach(read_temp_id->pth);
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"\n\nset initial frequency %.2fM\n",tmp42,0x4059000000000000);
        _applog(5,tmp42,false);
      }
      set_freq_yf(100.0);
      cgsleep_ms(10);
      sleep(1);
      paVar1 = dev;
      iVar3 = calculate_core_number((uint)dev->corenum);
      iVar3 = __aeabi_idiv(0x1000000,iVar3);
      iVar3 = __aeabi_idiv((uint)dev->addrInterval * iVar3,max_freq);
      paVar1->timeout = (iVar3 * 0x5f) / 100;
      if (0x1ffff < dev->timeout) {
        dev->timeout = 0x1ffff;
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"dev->timeout = %d\n",dev->timeout);
        _applog(5,tmp42,false);
      }
      set_time_out_control(0x8000c350);
      sleep(1);
      set_clock_delay_control();
      sleep(1);
      puts("===Pre Open Core===");
      for (chain = 0; chain < 0x10; chain = chain + 1) {
        if ((dev->chain_exist[chain] != 0) && (scanfreq_info.scan_finished[chain] == false)) {
          open_core_BM1393_pre_open_yf('\x05',chain);
          printf("Chain[%d] Pre open core,ready!\n",chain);
        }
      }
      sleep(2);
      puts("===Open Core There===");
      for (chain = 0; chain < 0x10; chain = chain + 1) {
        if ((dev->chain_exist[chain] != 0) && (scanfreq_info.scan_finished[chain] == false)) {
          open_core_BM1393_S11_single_board((uchar)chain);
          printf("Chain[%d] Open core,ready!\n",chain);
        }
      }
      sleep(2);
      puts("===increase the freq slowly===");
      puts("All Chains are in Same Freq");
      increase_freq_slowly(100.0,275.0,25.0);
      puts("===Open Core Again===");
      for (chain = 0; chain < 0x10; chain = chain + 1) {
        if ((dev->chain_exist[chain] != 0) && (scanfreq_info.scan_finished[chain] == false)) {
          open_core_BM1393_S11_single_board((uchar)chain);
        }
      }
      decrease_voltage_75j('\0',g_opencore_vol,g_target_vol,10);
      for (chain = 0; paVar1 = dev, chain < 0x10; chain = chain + 1) {
        if ((dev->chain_exist[chain] != 0) && (scanfreq_info.scan_finished[chain] == false)) {
          iVar3 = calculate_core_number((uint)dev->corenum);
          iVar3 = __aeabi_idiv(0x1000000,iVar3);
          fVar4 = (((float)(longlong)(int)((uint)dev->addrInterval * iVar3) / 275.0) * DAT_00047f6c)
                  / DAT_00047f70;
          paVar1->timeout = (uint)(0.0 < fVar4) * (int)fVar4;
        }
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"\n\nfinal timeout=%d\n",dev->timeout);
        _applog(5,tmp42,false);
      }
      if (opt_multi_version == 0) {
        set_time_out_control(dev->timeout & 0x1ffff | 0x80000000);
      }
      else {
        set_time_out_control(opt_multi_version * dev->timeout & 0x1ffff | 0x80000000);
      }
      iVar3 = 0;
    }
    else {
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"%s: fail to create thread for read temp\n","scanfreq_init");
        _applog(5,tmp42,false);
      }
      iVar3 = -7;
    }
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      snprintf(tmp42,0x800,"%s: create thread for get nonce and register from FPGA failed\n",
               "scanfreq_init");
      _applog(5,tmp42,false);
    }
    iVar3 = -5;
  }
  return iVar3;
}

