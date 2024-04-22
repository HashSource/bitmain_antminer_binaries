
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void set_frequency_new_B1393(ushort frequency)

{
  _Bool _Var1;
  int iVar2;
  int iVar3;
  ushort frequency_local;
  char tmp42 [2048];
  char logstr [1024];
  uint cmd_buf [3];
  uchar buf [9];
  uint value;
  int default_freq_index;
  uint reg_data_vil;
  uint16_t reg_data_pll2;
  uint reg_data_pll;
  int step_down;
  int chain_min_freq;
  int chain_max_freq;
  int max_freq_index;
  int j;
  int i;
  
  get_pll_index((uint)frequency);
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"--- %s","set_frequency_new_B1393");
    _applog(7,tmp42,false);
  }
  for (i = 0; i < 0x10; i = i + 1) {
    if ((dev->chain_exist[i] == 1) && (dev->chain_asic_num[i] != '\0')) {
      _Var1 = isFixedFreqMode();
      if ((_Var1) || (last_freq[i][1] != '}')) {
        isUseDefaultFreq = true;
        last_freq[i][0] = '\0';
        last_freq[i][1] = '}';
        for (j = 0; j < 0x6c; j = j + 1) {
          last_freq[i][j * 2 + 2] = '\0';
          last_freq[i][j * 2 + 3] = freq_one_board[i];
        }
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"Chain[J%d] has no freq in PIC, set default freq=%dM",i + 1,
                   freq_pll_1393[freq_one_board[i]].freq);
          _applog(5,tmp42,false);
        }
      }
      if ((badcore_num_buf[i][0] == '#') && (isUseDefaultFreq != true)) {
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"Chain[J%d] has core num in PIC\n",i + 1);
          _applog(5,tmp42,false);
        }
        for (j = 0; j < 0x6c; j = j + 1) {
          if ((j & 1U) == 0) {
            chain_badcore_num[i][j] = (uint)(badcore_num_buf[i][(j / 2) * 2 + 1] >> 4);
          }
          else {
            chain_badcore_num[i][j] = badcore_num_buf[i][(j / 2) * 2 + 1] & 0xf;
          }
          if ((0 < chain_badcore_num[i][j]) &&
             (((use_syslog != false || (opt_log_output != false)) || (4 < opt_log_level)))) {
            snprintf(tmp42,0x800,"Chain[J%d] ASIC[%d] has core num=%d",i + 1,j,
                     chain_badcore_num[i][j]);
            _applog(5,tmp42,false);
          }
        }
      }
      else {
        if ((use_syslog != false) || ((opt_log_output != false || (4 < opt_log_level)))) {
          snprintf(tmp42,0x800,"Chain[J%d] has no core num in PIC",i + 1);
          _applog(5,tmp42,false);
        }
        for (j = 0; j < 0x6c; j = j + 1) {
          chain_badcore_num[i][j] = 0;
        }
      }
    }
  }
  if ((isUseDefaultFreq != true) &&
     (((use_syslog != false || (opt_log_output != false)) || (4 < opt_log_level)))) {
    iVar2 = GetTotalRate();
    iVar3 = GetTotalRate();
    iVar3 = ConvirtTotalRate(iVar3);
    snprintf(tmp42,0x800,"miner total rate=%dGH/s fixed rate=%dGH/s",iVar2,iVar3);
    _applog(5,tmp42,false);
  }
  max_freq_index = 0;
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    tmp42[0] = s_Miner_fix_freq_____00076e84[0];
    tmp42[1] = s_Miner_fix_freq_____00076e84[1];
    tmp42[2] = s_Miner_fix_freq_____00076e84[2];
    tmp42[3] = s_Miner_fix_freq_____00076e84[3];
    tmp42[4] = s_Miner_fix_freq_____00076e84[4];
    tmp42[5] = s_Miner_fix_freq_____00076e84[5];
    tmp42[6] = s_Miner_fix_freq_____00076e84[6];
    tmp42[7] = s_Miner_fix_freq_____00076e84[7];
    tmp42[8] = s_Miner_fix_freq_____00076e84[8];
    tmp42[9] = s_Miner_fix_freq_____00076e84[9];
    tmp42[10] = s_Miner_fix_freq_____00076e84[10];
    tmp42[11] = s_Miner_fix_freq_____00076e84[11];
    tmp42[12] = s_Miner_fix_freq_____00076e84[12];
    tmp42[13] = s_Miner_fix_freq_____00076e84[13];
    tmp42[14] = s_Miner_fix_freq_____00076e84[14];
    tmp42[15] = s_Miner_fix_freq_____00076e84[15];
    tmp42._16_2_ = (undefined2)ram0x00076e94;
    tmp42[18] = (char)((uint)ram0x00076e94 >> 0x10);
    _applog(5,tmp42,false);
  }
  if ((isUseDefaultFreq != true) && (_Var1 = isChainEnough(), _Var1)) {
    ProcessFixFreqForChips();
  }
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      memcpy(chip_last_freq + i,last_freq + i,0x100);
    }
  }
  for (i = 0; i < 0x10; i = i + 1) {
    chain_max_freq = 0;
    chain_min_freq = 100;
    if ((dev->chain_exist[i] == 1) && (dev->chain_asic_num[i] != '\0')) {
      if ((use_syslog != false) || ((opt_log_output != false || (4 < opt_log_level)))) {
        snprintf(tmp42,0x800,"Chain:%d chipnum=%d",i,(uint)dev->chain_asic_num[i]);
        _applog(5,tmp42,false);
      }
      for (j = 0; j < (int)(uint)dev->chain_asic_num[i]; j = j + 1) {
        if (last_freq[i][j * 2 + 3] < 4) {
          last_freq[i][j * 2 + 3] = '\x04';
        }
        if (100 < last_freq[i][j * 2 + 3]) {
          last_freq[i][j * 2 + 3] = 'd';
        }
        if ((uint)max_freq_index < (uint)last_freq[i][j * 2 + 3]) {
          max_freq_index = (int)last_freq[i][j * 2 + 3];
        }
        if ((uint)chain_max_freq < (uint)last_freq[i][j * 2 + 3]) {
          chain_max_freq = (int)last_freq[i][j * 2 + 3];
        }
        if ((uint)last_freq[i][j * 2 + 3] < (uint)chain_min_freq) {
          chain_min_freq = (int)last_freq[i][j * 2 + 3];
        }
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"Chain:%d max freq=%d",i,freq_pll_1393[chain_max_freq].freq);
        _applog(5,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"Chain:%d min freq=%d",i,freq_pll_1393[chain_min_freq].freq);
        _applog(5,tmp42,false);
      }
    }
  }
  dev->frequency = (ushort)freq_pll_1393[max_freq_index].freq;
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"max freq = %d",(uint)dev->frequency);
    _applog(5,tmp42,false);
  }
  if (isUseDefaultFreq != true) {
    ProcessFixFreq();
  }
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      memcpy(show_last_freq + i,last_freq + i,0x100);
    }
  }
  return;
}

