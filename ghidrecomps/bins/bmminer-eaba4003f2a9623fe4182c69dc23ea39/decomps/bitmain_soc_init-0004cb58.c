
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int bitmain_soc_init(init_config config)

{
  all_parameters *paVar1;
  uint16_t uVar2;
  uint in_r0;
  uint uVar3;
  undefined4 in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  int iVar4;
  char tmp42 [2048];
  char logstr [1024];
  sysinfo si;
  int init_freq;
  int freq_step;
  int hardware_version;
  uchar voltage;
  int testCounter;
  uint data;
  uint16_t crc;
  char ret;
  int offset;
  int retry_count;
  int y;
  int x;
  int i;
  
  bitmain_scan_freq();
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    tmp42[0] = s_This_is_user_mode_for_mining_00078c54[0];
    tmp42[1] = s_This_is_user_mode_for_mining_00078c54[1];
    tmp42[2] = s_This_is_user_mode_for_mining_00078c54[2];
    tmp42[3] = s_This_is_user_mode_for_mining_00078c54[3];
    tmp42[4] = s_This_is_user_mode_for_mining_00078c54[4];
    tmp42[5] = s_This_is_user_mode_for_mining_00078c54[5];
    tmp42[6] = s_This_is_user_mode_for_mining_00078c54[6];
    tmp42[7] = s_This_is_user_mode_for_mining_00078c54[7];
    tmp42[8] = s_This_is_user_mode_for_mining_00078c54[8];
    tmp42[9] = s_This_is_user_mode_for_mining_00078c54[9];
    tmp42[10] = s_This_is_user_mode_for_mining_00078c54[10];
    tmp42[11] = s_This_is_user_mode_for_mining_00078c54[11];
    tmp42[12] = s_This_is_user_mode_for_mining_00078c54[12];
    tmp42[13] = s_This_is_user_mode_for_mining_00078c54[13];
    tmp42[14] = s_This_is_user_mode_for_mining_00078c54[14];
    tmp42[15] = s_This_is_user_mode_for_mining_00078c54[15];
    tmp42[16] = s_This_is_user_mode_for_mining_00078c54[16];
    tmp42[17] = s_This_is_user_mode_for_mining_00078c54[17];
    tmp42[18] = s_This_is_user_mode_for_mining_00078c54[18];
    tmp42[19] = s_This_is_user_mode_for_mining_00078c54[19];
    tmp42[20] = s_This_is_user_mode_for_mining_00078c54[20];
    tmp42[21] = s_This_is_user_mode_for_mining_00078c54[21];
    tmp42[22] = s_This_is_user_mode_for_mining_00078c54[22];
    tmp42[23] = s_This_is_user_mode_for_mining_00078c54[23];
    tmp42[24] = s_This_is_user_mode_for_mining_00078c54[24];
    tmp42[25] = s_This_is_user_mode_for_mining_00078c54[25];
    tmp42[26] = s_This_is_user_mode_for_mining_00078c54[26];
    tmp42[27] = s_This_is_user_mode_for_mining_00078c54[27];
    tmp42[28] = (char)(short)ram0x00078c70;
    tmp42[29] = (char)((ushort)(short)ram0x00078c70 >> 8);
    _applog(5,tmp42,false);
  }
  bitmain_axi_init();
  sysinfo((sysinfo *)&si);
  if (si.totalram < 0x3b9aca01) {
    if (si.totalram < 0x1dcd6501) {
      PHY_MEM_NONCE2_JOBID_ADDRESS = 0xf000000;
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        tmp42[0] = s_Detect_256MB_control_board_of_XI_00077b74[0];
        tmp42[1] = s_Detect_256MB_control_board_of_XI_00077b74[1];
        tmp42[2] = s_Detect_256MB_control_board_of_XI_00077b74[2];
        tmp42[3] = s_Detect_256MB_control_board_of_XI_00077b74[3];
        tmp42[4] = s_Detect_256MB_control_board_of_XI_00077b74[4];
        tmp42[5] = s_Detect_256MB_control_board_of_XI_00077b74[5];
        tmp42[6] = s_Detect_256MB_control_board_of_XI_00077b74[6];
        tmp42[7] = s_Detect_256MB_control_board_of_XI_00077b74[7];
        tmp42[8] = s_Detect_256MB_control_board_of_XI_00077b74[8];
        tmp42[9] = s_Detect_256MB_control_board_of_XI_00077b74[9];
        tmp42[10] = s_Detect_256MB_control_board_of_XI_00077b74[10];
        tmp42[11] = s_Detect_256MB_control_board_of_XI_00077b74[11];
        tmp42[12] = s_Detect_256MB_control_board_of_XI_00077b74[12];
        tmp42[13] = s_Detect_256MB_control_board_of_XI_00077b74[13];
        tmp42[14] = s_Detect_256MB_control_board_of_XI_00077b74[14];
        tmp42[15] = s_Detect_256MB_control_board_of_XI_00077b74[15];
        tmp42[16] = s_Detect_256MB_control_board_of_XI_00077b74[16];
        tmp42[17] = s_Detect_256MB_control_board_of_XI_00077b74[17];
        tmp42[18] = s_Detect_256MB_control_board_of_XI_00077b74[18];
        tmp42[19] = s_Detect_256MB_control_board_of_XI_00077b74[19];
        tmp42[20] = s_Detect_256MB_control_board_of_XI_00077b74[20];
        tmp42[21] = s_Detect_256MB_control_board_of_XI_00077b74[21];
        tmp42[22] = s_Detect_256MB_control_board_of_XI_00077b74[22];
        tmp42[23] = s_Detect_256MB_control_board_of_XI_00077b74[23];
        tmp42[24] = s_Detect_256MB_control_board_of_XI_00077b74[24];
        tmp42[25] = s_Detect_256MB_control_board_of_XI_00077b74[25];
        tmp42[26] = s_Detect_256MB_control_board_of_XI_00077b74[26];
        tmp42[27] = s_Detect_256MB_control_board_of_XI_00077b74[27];
        tmp42[28] = s_Detect_256MB_control_board_of_XI_00077b74[28];
        tmp42[29] = s_Detect_256MB_control_board_of_XI_00077b74[29];
        tmp42[30] = s_Detect_256MB_control_board_of_XI_00077b74[30];
        tmp42[31] = s_Detect_256MB_control_board_of_XI_00077b74[31];
        tmp42[32] = s_Detect_256MB_control_board_of_XI_00077b74[32];
        tmp42[33] = s_Detect_256MB_control_board_of_XI_00077b74[33];
        tmp42[34] = s_Detect_256MB_control_board_of_XI_00077b74[34];
        tmp42[35] = s_Detect_256MB_control_board_of_XI_00077b74[35];
        tmp42._36_2_ = (undefined2)ram0x00077b98;
        _applog(5,tmp42,false);
      }
    }
    else {
      PHY_MEM_NONCE2_JOBID_ADDRESS = 0x1f000000;
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        tmp42[0] = s_Detect_512MB_control_board_of_XI_00077b4c[0];
        tmp42[1] = s_Detect_512MB_control_board_of_XI_00077b4c[1];
        tmp42[2] = s_Detect_512MB_control_board_of_XI_00077b4c[2];
        tmp42[3] = s_Detect_512MB_control_board_of_XI_00077b4c[3];
        tmp42[4] = s_Detect_512MB_control_board_of_XI_00077b4c[4];
        tmp42[5] = s_Detect_512MB_control_board_of_XI_00077b4c[5];
        tmp42[6] = s_Detect_512MB_control_board_of_XI_00077b4c[6];
        tmp42[7] = s_Detect_512MB_control_board_of_XI_00077b4c[7];
        tmp42[8] = s_Detect_512MB_control_board_of_XI_00077b4c[8];
        tmp42[9] = s_Detect_512MB_control_board_of_XI_00077b4c[9];
        tmp42[10] = s_Detect_512MB_control_board_of_XI_00077b4c[10];
        tmp42[11] = s_Detect_512MB_control_board_of_XI_00077b4c[11];
        tmp42[12] = s_Detect_512MB_control_board_of_XI_00077b4c[12];
        tmp42[13] = s_Detect_512MB_control_board_of_XI_00077b4c[13];
        tmp42[14] = s_Detect_512MB_control_board_of_XI_00077b4c[14];
        tmp42[15] = s_Detect_512MB_control_board_of_XI_00077b4c[15];
        tmp42[16] = s_Detect_512MB_control_board_of_XI_00077b4c[16];
        tmp42[17] = s_Detect_512MB_control_board_of_XI_00077b4c[17];
        tmp42[18] = s_Detect_512MB_control_board_of_XI_00077b4c[18];
        tmp42[19] = s_Detect_512MB_control_board_of_XI_00077b4c[19];
        tmp42[20] = s_Detect_512MB_control_board_of_XI_00077b4c[20];
        tmp42[21] = s_Detect_512MB_control_board_of_XI_00077b4c[21];
        tmp42[22] = s_Detect_512MB_control_board_of_XI_00077b4c[22];
        tmp42[23] = s_Detect_512MB_control_board_of_XI_00077b4c[23];
        tmp42[24] = s_Detect_512MB_control_board_of_XI_00077b4c[24];
        tmp42[25] = s_Detect_512MB_control_board_of_XI_00077b4c[25];
        tmp42[26] = s_Detect_512MB_control_board_of_XI_00077b4c[26];
        tmp42[27] = s_Detect_512MB_control_board_of_XI_00077b4c[27];
        tmp42[28] = s_Detect_512MB_control_board_of_XI_00077b4c[28];
        tmp42[29] = s_Detect_512MB_control_board_of_XI_00077b4c[29];
        tmp42[30] = s_Detect_512MB_control_board_of_XI_00077b4c[30];
        tmp42[31] = s_Detect_512MB_control_board_of_XI_00077b4c[31];
        tmp42[32] = s_Detect_512MB_control_board_of_XI_00077b4c[32];
        tmp42[33] = s_Detect_512MB_control_board_of_XI_00077b4c[33];
        tmp42[34] = s_Detect_512MB_control_board_of_XI_00077b4c[34];
        tmp42[35] = s_Detect_512MB_control_board_of_XI_00077b4c[35];
        tmp42._36_2_ = (undefined2)ram0x00077b70;
        _applog(5,tmp42,false);
      }
    }
  }
  else {
    PHY_MEM_NONCE2_JOBID_ADDRESS = 0x3f000000;
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      tmp42[0] = s_Detect_1GB_control_board_of_XILI_00077b28[0];
      tmp42[1] = s_Detect_1GB_control_board_of_XILI_00077b28[1];
      tmp42[2] = s_Detect_1GB_control_board_of_XILI_00077b28[2];
      tmp42[3] = s_Detect_1GB_control_board_of_XILI_00077b28[3];
      tmp42[4] = s_Detect_1GB_control_board_of_XILI_00077b28[4];
      tmp42[5] = s_Detect_1GB_control_board_of_XILI_00077b28[5];
      tmp42[6] = s_Detect_1GB_control_board_of_XILI_00077b28[6];
      tmp42[7] = s_Detect_1GB_control_board_of_XILI_00077b28[7];
      tmp42[8] = s_Detect_1GB_control_board_of_XILI_00077b28[8];
      tmp42[9] = s_Detect_1GB_control_board_of_XILI_00077b28[9];
      tmp42[10] = s_Detect_1GB_control_board_of_XILI_00077b28[10];
      tmp42[11] = s_Detect_1GB_control_board_of_XILI_00077b28[11];
      tmp42[12] = s_Detect_1GB_control_board_of_XILI_00077b28[12];
      tmp42[13] = s_Detect_1GB_control_board_of_XILI_00077b28[13];
      tmp42[14] = s_Detect_1GB_control_board_of_XILI_00077b28[14];
      tmp42[15] = s_Detect_1GB_control_board_of_XILI_00077b28[15];
      tmp42[16] = s_Detect_1GB_control_board_of_XILI_00077b28[16];
      tmp42[17] = s_Detect_1GB_control_board_of_XILI_00077b28[17];
      tmp42[18] = s_Detect_1GB_control_board_of_XILI_00077b28[18];
      tmp42[19] = s_Detect_1GB_control_board_of_XILI_00077b28[19];
      tmp42[20] = s_Detect_1GB_control_board_of_XILI_00077b28[20];
      tmp42[21] = s_Detect_1GB_control_board_of_XILI_00077b28[21];
      tmp42[22] = s_Detect_1GB_control_board_of_XILI_00077b28[22];
      tmp42[23] = s_Detect_1GB_control_board_of_XILI_00077b28[23];
      tmp42[24] = s_Detect_1GB_control_board_of_XILI_00077b28[24];
      tmp42[25] = s_Detect_1GB_control_board_of_XILI_00077b28[25];
      tmp42[26] = s_Detect_1GB_control_board_of_XILI_00077b28[26];
      tmp42[27] = s_Detect_1GB_control_board_of_XILI_00077b28[27];
      tmp42[28] = s_Detect_1GB_control_board_of_XILI_00077b28[28];
      tmp42[29] = s_Detect_1GB_control_board_of_XILI_00077b28[29];
      tmp42[30] = s_Detect_1GB_control_board_of_XILI_00077b28[30];
      tmp42[31] = s_Detect_1GB_control_board_of_XILI_00077b28[31];
      tmp42[32] = s_Detect_1GB_control_board_of_XILI_00077b28[32];
      tmp42[33] = s_Detect_1GB_control_board_of_XILI_00077b28[33];
      tmp42[34] = s_Detect_1GB_control_board_of_XILI_00077b28[34];
      tmp42[35] = s_Detect_1GB_control_board_of_XILI_00077b28[35];
      _applog(5,tmp42,false);
    }
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    tmp42[0] = s_Miner_Type___S11_00078c74[0];
    tmp42[1] = s_Miner_Type___S11_00078c74[1];
    tmp42[2] = s_Miner_Type___S11_00078c74[2];
    tmp42[3] = s_Miner_Type___S11_00078c74[3];
    tmp42[4] = s_Miner_Type___S11_00078c74[4];
    tmp42[5] = s_Miner_Type___S11_00078c74[5];
    tmp42[6] = s_Miner_Type___S11_00078c74[6];
    tmp42[7] = s_Miner_Type___S11_00078c74[7];
    tmp42[8] = s_Miner_Type___S11_00078c74[8];
    tmp42[9] = s_Miner_Type___S11_00078c74[9];
    tmp42[10] = s_Miner_Type___S11_00078c74[10];
    tmp42[11] = s_Miner_Type___S11_00078c74[11];
    tmp42[12] = s_Miner_Type___S11_00078c74[12];
    tmp42[13] = s_Miner_Type___S11_00078c74[13];
    tmp42[14] = s_Miner_Type___S11_00078c74[14];
    tmp42[15] = s_Miner_Type___S11_00078c74[15];
    tmp42[16] = (char)(short)ram0x00078c84;
    tmp42[17] = (char)((ushort)(short)ram0x00078c84 >> 8);
    _applog(5,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"Miner compile time: %s type: %s",g_miner_compiletime,g_miner_type);
    _applog(5,tmp42,false);
  }
  config_parameter._16_4_ = config._0_4_;
  config_parameter.reg_data = config._4_4_;
  config_parameter._24_4_ = config._8_4_;
  config_parameter._28_4_ = config._12_4_;
  config_parameter.token_type = (uchar)in_r0;
  config_parameter._0_4_ = in_r0;
  config_parameter._4_4_ = in_r1;
  config_parameter._8_4_ = in_r2;
  config_parameter._12_4_ = in_r3;
  if (config_parameter.token_type == 'Q') {
    uVar2 = CRC16(&config_parameter.token_type,0x1e);
    if (uVar2 == config_parameter.crc) {
      read_nonce_reg_id = (thr_info *)calloc(1,0x40);
      iVar4 = thr_info_create(read_nonce_reg_id,(pthread_attr_t *)0x0,get_nonce_and_register + 1,
                              read_nonce_reg_id);
      if (iVar4 == 0) {
        pthread_detach(read_nonce_reg_id->pth);
        if ((config_parameter._4_4_ & 1) != 0) {
          set_QN_write_data_command(0x8080800f);
          sleep(2);
          set_PWM('d');
        }
        set_Hardware_version(0x40000000);
        read_fpga_id(FPGA_ID_str);
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"miner ID : %s\n",FPGA_ID_str);
          _applog(5,tmp42,false);
        }
        uVar3 = get_hardware_version();
        pcb_version = (int)uVar3 >> 0x10 & 0x7fff;
        fpga_version = uVar3 & 0xff;
        fpga_major_version = uVar3 >> 8 & 0xff;
        sprintf(g_miner_version,"%d.%d.%d.%d",(fpga_major_version - 0xc5U) * 0x100 + fpga_version,
                pcb_version,1,3);
        dev->baud = '\x1a';
        set_nonce2_and_job_id_store_address(PHY_MEM_NONCE2_JOBID_ADDRESS);
        set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          tmp42[0] = s_begin_to_check_chain_00078d20[0];
          tmp42[1] = s_begin_to_check_chain_00078d20[1];
          tmp42[2] = s_begin_to_check_chain_00078d20[2];
          tmp42[3] = s_begin_to_check_chain_00078d20[3];
          tmp42[4] = s_begin_to_check_chain_00078d20[4];
          tmp42[5] = s_begin_to_check_chain_00078d20[5];
          tmp42[6] = s_begin_to_check_chain_00078d20[6];
          tmp42[7] = s_begin_to_check_chain_00078d20[7];
          tmp42[8] = s_begin_to_check_chain_00078d20[8];
          tmp42[9] = s_begin_to_check_chain_00078d20[9];
          tmp42[10] = s_begin_to_check_chain_00078d20[10];
          tmp42[11] = s_begin_to_check_chain_00078d20[11];
          tmp42[12] = s_begin_to_check_chain_00078d20[12];
          tmp42[13] = s_begin_to_check_chain_00078d20[13];
          tmp42[14] = s_begin_to_check_chain_00078d20[14];
          tmp42[15] = s_begin_to_check_chain_00078d20[15];
          tmp42[16] = s_begin_to_check_chain_00078d20[16];
          tmp42[17] = s_begin_to_check_chain_00078d20[17];
          tmp42[18] = s_begin_to_check_chain_00078d20[18];
          tmp42[19] = s_begin_to_check_chain_00078d20[19];
          tmp42[20] = (char)(short)ram0x00078d34;
          tmp42[21] = (char)((ushort)(short)ram0x00078d34 >> 8);
          _applog(5,tmp42,false);
        }
        check_chain();
        set_PWM('d');
        puts("reset down");
        reset_down_hash_board();
        for (i = 0; i < 0x10; i = i + 1) {
          if (dev->chain_exist[i] == 1) {
            pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
            dsPIC33EP16GS202_reset_pic((uchar)i);
            pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
            cgsleep_ms(100);
            pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
            dsPIC33EP16GS202_jump_to_app_from_loader((uchar)i);
            pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
            cgsleep_ms(100);
          }
        }
        pic_heart_beat = (thr_info *)calloc(1,0x40);
        iVar4 = thr_info_create(pic_heart_beat,(pthread_attr_t *)0x0,pic_heart_beat_func + 1,
                                pic_heart_beat);
        if (iVar4 == 0) {
          pthread_detach(pic_heart_beat->pth);
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            snprintf(tmp42,0x800,"============%s=========%d==========================",
                     "bitmain_soc_init",0x2ac1);
            _applog(5,tmp42,false);
          }
          for (i = 0; i < 0x10; i = i + 1) {
            if (dev->chain_exist[i] == 1) {
              pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
              AT24C02_read_voltage((uchar)i);
              pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
              printf("Chain[%d] read pic voltage=%d\n",i,0x21);
              pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
              set_voltage_T9_18_into_PIC((uchar)i,'!');
              pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
            }
          }
          reset_up_hash_board();
          usleep(200000);
          reset_hash_board();
          puts("reset over, send data");
          if (opt_multi_version != 0) {
            uVar3 = get_dhash_acc_control();
            set_dhash_acc_control(uVar3 & 0xffff70df | 0x8100);
          }
          cgsleep_ms(10);
          dev->corenum = 0xd0;
          check_asic_reg(0);
          cgsleep_ms(10);
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            memcpy(tmp42,
                   "------------------------------------------------------------------------------------"
                   ,0x55);
            _applog(5,tmp42,false);
          }
          for (i = 0; i < 0x10; i = i + 1) {
            if (dev->chain_exist[i] == 1) {
              retry_count = 0;
              if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
                snprintf(tmp42,0x800,"Chain[J%d] has %d asic\n",i + 1,(uint)dev->chain_asic_num[i]);
                _applog(5,tmp42,false);
              }
              for (; (dev->chain_asic_num[i] != 'l' && (retry_count < 6));
                  retry_count = retry_count + 1) {
                dev->chain_asic_num[i] = '\0';
                set_reset_hashboard(i,1);
                pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
                dsPIC33EP16GS202_enable_pic_dc_dc((uchar)i,'\0');
                pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
                sleep(1);
                pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
                dsPIC33EP16GS202_enable_pic_dc_dc((uchar)i,'\x01');
                pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
                sleep(2);
                set_reset_hashboard(i,0);
                sleep(1);
                check_asic_reg_oneChain(i,0);
                if ((use_syslog != false) || ((opt_log_output != false || (4 < opt_log_level)))) {
                  snprintf(tmp42,0x800,"retry Chain[J%d] has %d asic\n",i + 1,
                           (uint)dev->chain_asic_num[i]);
                  _applog(5,tmp42,false);
                }
              }
              if (dev->chain_asic_num[i] == '\0') {
                dev->chain_exist[i] = 0;
              }
            }
          }
          for (i = 0; i < 0x10; i = i + 1) {
            if ((dev->chain_exist[i] != 0) &&
               (((use_syslog != false || (opt_log_output != false)) || (4 < opt_log_level)))) {
              snprintf(tmp42,0x800,"Chain%d has %d ASICs",i,(uint)dev->chain_asic_num[i]);
              _applog(5,tmp42,false);
            }
          }
          software_set_address(2);
          cgsleep_ms(10);
          if ((config_parameter._4_4_ & 8) != 0) {
            dev->frequency = config_parameter.frequency;
            sprintf(dev->frequency_t,"%u",(uint)dev->frequency);
          }
          cgsleep_ms(10);
          dev->fan_eft = (byte)((uint)(config_parameter._4_4_ << 0x1e) >> 0x1f);
          dev->fan_pwm = config_parameter.fan_pwm_percent;
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"%s: fan_eft : %d  fan_pwm : %d\n","bitmain_soc_init",
                     (uint)dev->fan_eft,(uint)dev->fan_pwm);
            _applog(7,tmp42,false);
          }
          if ((config_parameter._4_4_ & 2) == 0) {
            set_PWM_according_to_temperature();
          }
          else if (config_parameter.fan_pwm_percent < 0x65) {
            set_PWM(config_parameter.fan_pwm_percent);
          }
          else {
            set_PWM_according_to_temperature();
          }
          paVar1 = dev;
          if ((config_parameter._4_4_ & 4) != 0) {
            if ((config_parameter.timeout_data_integer == '\0') &&
               (config_parameter.timeout_data_fractions == '\0')) {
              iVar4 = calculate_core_number((uint)dev->corenum);
              iVar4 = __aeabi_idiv(0x1000000,iVar4);
              iVar4 = __aeabi_idiv((uint)dev->addrInterval * iVar4,dev->frequency);
              paVar1->timeout = (iVar4 * 0x5a) / 100;
              if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
                snprintf(tmp42,0x800,"dev->timeout = %d\n",dev->timeout);
                _applog(5,tmp42,false);
              }
            }
            else {
              dev->timeout = (uint)config_parameter.timeout_data_integer * 1000 +
                             (uint)config_parameter.timeout_data_fractions;
            }
            if (0x1ffff < dev->timeout) {
              dev->timeout = 0x1ffff;
            }
          }
          init_uart_baud();
          cgsleep_ms(10);
          set_clock_delay_control();
          puts("===pre open core===");
          open_core_BM1393_pre_open('\x05','\x01');
          for (i = 0; i < 0x10; i = i + 1) {
            if ((dev->chain_exist[i] == 1) && (dev->chain_asic_num[i] == 'l')) {
              calibration_sensor_offset(0x98,i);
              cgsleep_ms(10);
            }
          }
          if (opt_multi_version == 0) {
            set_time_out_control(dev->timeout / 10 & 0x1ffff | 0x80000000);
          }
          else {
            set_time_out_control(0x8000c350);
          }
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            tmp42[0] = s_set_TICKET_MASK_00078e20[0];
            tmp42[1] = s_set_TICKET_MASK_00078e20[1];
            tmp42[2] = s_set_TICKET_MASK_00078e20[2];
            tmp42[3] = s_set_TICKET_MASK_00078e20[3];
            tmp42[4] = s_set_TICKET_MASK_00078e20[4];
            tmp42[5] = s_set_TICKET_MASK_00078e20[5];
            tmp42[6] = s_set_TICKET_MASK_00078e20[6];
            tmp42[7] = s_set_TICKET_MASK_00078e20[7];
            tmp42[8] = s_set_TICKET_MASK_00078e20[8];
            tmp42[9] = s_set_TICKET_MASK_00078e20[9];
            tmp42[10] = s_set_TICKET_MASK_00078e20[10];
            tmp42[11] = s_set_TICKET_MASK_00078e20[11];
            tmp42[12] = s_set_TICKET_MASK_00078e20[12];
            tmp42[13] = s_set_TICKET_MASK_00078e20[13];
            tmp42[14] = s_set_TICKET_MASK_00078e20[14];
            tmp42[15] = s_set_TICKET_MASK_00078e20[15];
            _applog(5,tmp42,false);
          }
          set_asic_ticket_mask(ticket_mask);
          cgsleep_ms(10);
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            tmp42[0] = s_Start_Open_Core___00078e30[0];
            tmp42[1] = s_Start_Open_Core___00078e30[1];
            tmp42[2] = s_Start_Open_Core___00078e30[2];
            tmp42[3] = s_Start_Open_Core___00078e30[3];
            tmp42[4] = s_Start_Open_Core___00078e30[4];
            tmp42[5] = s_Start_Open_Core___00078e30[5];
            tmp42[6] = s_Start_Open_Core___00078e30[6];
            tmp42[7] = s_Start_Open_Core___00078e30[7];
            tmp42[8] = s_Start_Open_Core___00078e30[8];
            tmp42[9] = s_Start_Open_Core___00078e30[9];
            tmp42[10] = s_Start_Open_Core___00078e30[10];
            tmp42[11] = s_Start_Open_Core___00078e30[11];
            tmp42[12] = s_Start_Open_Core___00078e30[12];
            tmp42[13] = s_Start_Open_Core___00078e30[13];
            tmp42[14] = s_Start_Open_Core___00078e30[14];
            tmp42[15] = s_Start_Open_Core___00078e30[15];
            tmp42[16] = (char)(short)ram0x00078e40;
            tmp42[17] = (char)((ushort)(short)ram0x00078e40 >> 8);
            _applog(5,tmp42,false);
          }
          open_core_bm1393(false);
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            tmp42[0] = s_End_Open_Core___00078e44[0];
            tmp42[1] = s_End_Open_Core___00078e44[1];
            tmp42[2] = s_End_Open_Core___00078e44[2];
            tmp42[3] = s_End_Open_Core___00078e44[3];
            tmp42[4] = s_End_Open_Core___00078e44[4];
            tmp42[5] = s_End_Open_Core___00078e44[5];
            tmp42[6] = s_End_Open_Core___00078e44[6];
            tmp42[7] = s_End_Open_Core___00078e44[7];
            tmp42[8] = s_End_Open_Core___00078e44[8];
            tmp42[9] = s_End_Open_Core___00078e44[9];
            tmp42[10] = s_End_Open_Core___00078e44[10];
            tmp42[11] = s_End_Open_Core___00078e44[11];
            tmp42[12] = s_End_Open_Core___00078e44[12];
            tmp42[13] = s_End_Open_Core___00078e44[13];
            tmp42[14] = s_End_Open_Core___00078e44[14];
            tmp42[15] = s_End_Open_Core___00078e44[15];
            _applog(5,tmp42,false);
          }
          if (opt_multi_version == 0) {
            set_time_out_control(dev->timeout / 10 & 0x1ffff | 0x80000000);
          }
          else {
            set_time_out_control(dev->timeout / 10 & 0x1ffff | 0x80000000);
          }
          for (x = 0; x < 0x10; x = x + 1) {
            if (dev->chain_exist[x] != 0) {
              offset = 0;
              for (y = 0; y < (int)(uint)dev->chain_asic_num[x]; y = y + 1) {
                if ((y & 7U) == 0) {
                  dev->chain_asic_status_string[x][y + offset] = ' ';
                  offset = offset + 1;
                }
                dev->chain_asic_status_string[x][y + offset] = 'o';
                paVar1 = dev;
                *(undefined4 *)(dev->chain_asic_nonce[x] + y) = 0;
                *(undefined4 *)((int)paVar1->chain_asic_nonce[x] + y * 8 + 4) = 0;
              }
              dev->chain_asic_status_string[x][y + offset] = '\0';
            }
          }
          read_temp_id = (thr_info *)calloc(1,0x40);
          iVar4 = thr_info_create(read_temp_id,(pthread_attr_t *)0x0,read_temp_func + 1,read_temp_id
                                 );
          if (iVar4 == 0) {
            pthread_detach(read_temp_id->pth);
            cgtime(&tv_send_job);
            cgtime(&tv_send);
            startCheckNetworkJob = true;
            read_hash_rate = (thr_info *)calloc(1,0x40);
            iVar4 = thr_info_create(read_hash_rate,(pthread_attr_t *)0x0,get_hash_rate + 1,
                                    read_hash_rate);
            if (iVar4 == 0) {
              pthread_detach(read_hash_rate->pth);
              cgsleep_ms(500);
              setStartTimePoint();
              if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
                tmp42[0] = s_Init_OK__00078eac[0];
                tmp42[1] = s_Init_OK__00078eac[1];
                tmp42[2] = s_Init_OK__00078eac[2];
                tmp42[3] = s_Init_OK__00078eac[3];
                tmp42[4] = s_Init_OK__00078eac[4];
                tmp42[5] = s_Init_OK__00078eac[5];
                tmp42[6] = s_Init_OK__00078eac[6];
                tmp42[7] = s_Init_OK__00078eac[7];
                tmp42[8] = (char)ram0x00078eb4;
                _applog(5,tmp42,false);
              }
              iVar4 = 0;
            }
            else {
              if ((opt_debug != false) &&
                 (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                snprintf(tmp42,0x800,"%s: create thread for get hashrate from asic failed",
                         "bitmain_soc_init");
                _applog(7,tmp42,false);
              }
              iVar4 = -6;
            }
          }
          else {
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              snprintf(tmp42,0x800,"%s: create thread for read temp\n","bitmain_soc_init");
              _applog(7,tmp42,false);
            }
            iVar4 = -7;
          }
        }
        else {
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"%s: create thread for get nonce and register from FPGA failed\n",
                     "bitmain_soc_init");
            _applog(7,tmp42,false);
          }
          iVar4 = -5;
        }
      }
      else {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"%s: create thread for get nonce and register from FPGA failed\n",
                   "bitmain_soc_init");
          _applog(7,tmp42,false);
        }
        iVar4 = -5;
      }
    }
    else {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"%s: config_parameter.crc = 0x%x, but we calculate it as 0x%x\n",
                 "bitmain_soc_init",(uint)config_parameter.crc,(uint)uVar2);
        _applog(7,tmp42,false);
      }
      iVar4 = -2;
    }
  }
  else {
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"%s: config_parameter.token_type != 0x%x, it is 0x%x\n",
               "bitmain_soc_init",0x51,in_r0 & 0xff);
      _applog(7,tmp42,false);
    }
    iVar4 = -1;
  }
  return iVar4;
}

