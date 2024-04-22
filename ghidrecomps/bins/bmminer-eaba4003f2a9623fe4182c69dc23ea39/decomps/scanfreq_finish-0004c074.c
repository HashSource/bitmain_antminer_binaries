
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

void scanfreq_finish(void)

{
  int iVar1;
  char tmp42 [2048];
  int index;
  float volt;
  int i;
  int chain;
  
  if (((use_syslog) || (opt_log_output)) || (4 < opt_log_level)) {
    tmp42._0_3_ = (undefined3)DAT_0007854c;
    _applog(5,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    tmp42[0] = s_____________Scan_Result__________00078998[0];
    tmp42[1] = s_____________Scan_Result__________00078998[1];
    tmp42[2] = s_____________Scan_Result__________00078998[2];
    tmp42[3] = s_____________Scan_Result__________00078998[3];
    tmp42[4] = s_____________Scan_Result__________00078998[4];
    tmp42[5] = s_____________Scan_Result__________00078998[5];
    tmp42[6] = s_____________Scan_Result__________00078998[6];
    tmp42[7] = s_____________Scan_Result__________00078998[7];
    tmp42[8] = s_____________Scan_Result__________00078998[8];
    tmp42[9] = s_____________Scan_Result__________00078998[9];
    tmp42[10] = s_____________Scan_Result__________00078998[10];
    tmp42[11] = s_____________Scan_Result__________00078998[11];
    tmp42[12] = s_____________Scan_Result__________00078998[12];
    tmp42[13] = s_____________Scan_Result__________00078998[13];
    tmp42[14] = s_____________Scan_Result__________00078998[14];
    tmp42[15] = s_____________Scan_Result__________00078998[15];
    tmp42[16] = s_____________Scan_Result__________00078998[16];
    tmp42[17] = s_____________Scan_Result__________00078998[17];
    tmp42[18] = s_____________Scan_Result__________00078998[18];
    tmp42[19] = s_____________Scan_Result__________00078998[19];
    tmp42[20] = s_____________Scan_Result__________00078998[20];
    tmp42[21] = s_____________Scan_Result__________00078998[21];
    tmp42[22] = s_____________Scan_Result__________00078998[22];
    tmp42[23] = s_____________Scan_Result__________00078998[23];
    tmp42[24] = s_____________Scan_Result__________00078998[24];
    tmp42[25] = s_____________Scan_Result__________00078998[25];
    tmp42[26] = s_____________Scan_Result__________00078998[26];
    tmp42[27] = s_____________Scan_Result__________00078998[27];
    tmp42[28] = s_____________Scan_Result__________00078998[28];
    tmp42[29] = s_____________Scan_Result__________00078998[29];
    tmp42[30] = s_____________Scan_Result__________00078998[30];
    tmp42[31] = s_____________Scan_Result__________00078998[31];
    tmp42[32] = s_____________Scan_Result__________00078998[32];
    tmp42[33] = s_____________Scan_Result__________00078998[33];
    tmp42[34] = s_____________Scan_Result__________00078998[34];
    tmp42[35] = s_____________Scan_Result__________00078998[35];
    tmp42[36] = s_____________Scan_Result__________00078998[36];
    tmp42[37] = s_____________Scan_Result__________00078998[37];
    tmp42[38] = s_____________Scan_Result__________00078998[38];
    tmp42[39] = s_____________Scan_Result__________00078998[39];
    _applog(5,tmp42,false);
  }
  scanfreq_info.all_chain_scan_success = true;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      iVar1 = getVolValueFromPICvoltage((uchar)scanfreq_info.scan_pic_voltage[chain]);
      if (scanfreq_info.scan_success[chain] == false) {
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"******Chain[%d] Failed, voltage=%.1fV  **********",chain,
                   (double)((float)(longlong)iVar1 / DAT_0004c4d4));
          _applog(5,tmp42,false);
        }
        scanfreq_info.all_chain_scan_success = false;
      }
      else if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,
                 "******Chain[%d] Success, Freq=%dM, voltage=%.1fV, NonceRate=%.1f**********",chain,
                 freq_pll_1393[scanfreq_info.scan_index[scanfreq_info.pass_freq_index[chain]]].freq)
        ;
        _applog(5,tmp42,false);
      }
      for (i = 0; i < scanfreq_info.scan_record_count[chain]; i = i + 1) {
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"%d. No=%d, Freq=%dM, NonceRate=%.1f%%",i + 1,
                   scanfreq_info.scan_freq_index_record[chain][i],
                   freq_pll_1393
                   [scanfreq_info.scan_index[scanfreq_info.scan_freq_index_record[chain][i]]].freq,
                   (double)scanfreq_info.scan_noncerate_record[chain][i]);
          _applog(5,tmp42,false);
        }
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        tmp42._0_3_ = (undefined3)DAT_0007854c;
        _applog(5,tmp42,false);
      }
    }
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    tmp42[0] = s_read_clock_delay_control_after_t_00078a68[0];
    tmp42[1] = s_read_clock_delay_control_after_t_00078a68[1];
    tmp42[2] = s_read_clock_delay_control_after_t_00078a68[2];
    tmp42[3] = s_read_clock_delay_control_after_t_00078a68[3];
    tmp42[4] = s_read_clock_delay_control_after_t_00078a68[4];
    tmp42[5] = s_read_clock_delay_control_after_t_00078a68[5];
    tmp42[6] = s_read_clock_delay_control_after_t_00078a68[6];
    tmp42[7] = s_read_clock_delay_control_after_t_00078a68[7];
    tmp42[8] = s_read_clock_delay_control_after_t_00078a68[8];
    tmp42[9] = s_read_clock_delay_control_after_t_00078a68[9];
    tmp42[10] = s_read_clock_delay_control_after_t_00078a68[10];
    tmp42[11] = s_read_clock_delay_control_after_t_00078a68[11];
    tmp42[12] = s_read_clock_delay_control_after_t_00078a68[12];
    tmp42[13] = s_read_clock_delay_control_after_t_00078a68[13];
    tmp42[14] = s_read_clock_delay_control_after_t_00078a68[14];
    tmp42[15] = s_read_clock_delay_control_after_t_00078a68[15];
    tmp42[16] = s_read_clock_delay_control_after_t_00078a68[16];
    tmp42[17] = s_read_clock_delay_control_after_t_00078a68[17];
    tmp42[18] = s_read_clock_delay_control_after_t_00078a68[18];
    tmp42[19] = s_read_clock_delay_control_after_t_00078a68[19];
    tmp42[20] = s_read_clock_delay_control_after_t_00078a68[20];
    tmp42[21] = s_read_clock_delay_control_after_t_00078a68[21];
    tmp42[22] = s_read_clock_delay_control_after_t_00078a68[22];
    tmp42[23] = s_read_clock_delay_control_after_t_00078a68[23];
    tmp42[24] = s_read_clock_delay_control_after_t_00078a68[24];
    tmp42[25] = s_read_clock_delay_control_after_t_00078a68[25];
    tmp42[26] = s_read_clock_delay_control_after_t_00078a68[26];
    tmp42[27] = s_read_clock_delay_control_after_t_00078a68[27];
    tmp42[28] = s_read_clock_delay_control_after_t_00078a68[28];
    tmp42[29] = s_read_clock_delay_control_after_t_00078a68[29];
    tmp42[30] = s_read_clock_delay_control_after_t_00078a68[30];
    tmp42[31] = s_read_clock_delay_control_after_t_00078a68[31];
    tmp42[32] = s_read_clock_delay_control_after_t_00078a68[32];
    tmp42[33] = s_read_clock_delay_control_after_t_00078a68[33];
    tmp42[34] = s_read_clock_delay_control_after_t_00078a68[34];
    tmp42[35] = s_read_clock_delay_control_after_t_00078a68[35];
    tmp42[36] = s_read_clock_delay_control_after_t_00078a68[36];
    tmp42[37] = s_read_clock_delay_control_after_t_00078a68[37];
    tmp42[38] = s_read_clock_delay_control_after_t_00078a68[38];
    tmp42[39] = s_read_clock_delay_control_after_t_00078a68[39];
    tmp42[40] = s_read_clock_delay_control_after_t_00078a68[40];
    tmp42[41] = s_read_clock_delay_control_after_t_00078a68[41];
    tmp42[42] = s_read_clock_delay_control_after_t_00078a68[42];
    tmp42[43] = s_read_clock_delay_control_after_t_00078a68[43];
    tmp42._44_2_ = (undefined2)ram0x00078a94;
    _applog(5,tmp42,false);
  }
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
      dsPIC33EP16GS202_enable_pic_dc_dc((uchar)chain,'\0');
      pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
    }
  }
  pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
  pthread_cancel(receive_id);
  pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
  return;
}

