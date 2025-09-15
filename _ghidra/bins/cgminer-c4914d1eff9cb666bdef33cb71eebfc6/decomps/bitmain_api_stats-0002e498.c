
api_data * bitmain_api_stats(cgpu_info *cgpu)

{
  longlong lVar1;
  undefined4 uVar2;
  _Bool _Var3;
  int iVar4;
  size_t sVar5;
  api_data *paVar6;
  char *pcVar7;
  int iVar8;
  bool bVar9;
  DFtype a;
  double dVar10;
  DItype DVar11;
  cgpu_info *cgpu_local;
  char temp_pcb_value [64];
  char tmp_3 [20];
  char chain_opencore [20];
  char tmp_2 [20];
  char chain_offside [20];
  char tmp_1 [20];
  char chain_xtime [16];
  char chain_rate [16];
  char chain_hw [16];
  char chain_asic_name [12];
  char chain_name [12];
  double dev_sum_freq_3;
  double total_rate;
  int16_t asic_num_total;
  double dev_sum_freq_2;
  double dev_sum_freq_1;
  double dev_sum_freq;
  char freq_sum [12];
  char temp_chip_name [12];
  char no_value_1 [2];
  char temp_pcb_name [12];
  char no_value [2];
  char temp2_name [12];
  char temp_name [12];
  char fan_name [12];
  char chain_freq [12];
  char tmp [12];
  double dev_hwp;
  int temp_offside [16];
  int hw_errors_temp;
  int8_t temp_senor_num;
  int temp_3;
  int temp_2;
  int temp_1;
  int t11a_eco_rate;
  int t11_eco_rate;
  _Bool copy_data;
  int temp;
  int j_5;
  _Bool first;
  int j_4;
  int total_acn_num;
  int j_3;
  int len_1;
  int j_2;
  int len;
  int j_1;
  uint64_t hash_rate_all;
  int j;
  int i;
  api_data *root;
  
  root = (api_data *)0x0;
  i = 0;
  temp = 0;
  j = 0;
  temp_senor_num = '\0';
  hash_rate_all._0_4_ = 0;
  hash_rate_all._4_4_ = 0;
  copy_data = true;
  hw_errors_temp = get_hw_errors();
  memset(temp_offside,0,0x40);
  root = api_add_uint8(root,"miner_count",&dev->chain_num,copy_data);
  root = api_add_string(root,"frequency",dev->frequency_t,copy_data);
  for (i = 0; i < 8; i = i + 1) {
    sprintf(chain_freq,"freq%d",i + 1);
    if (freq_mode == 2) {
      sprintf(tmp,"%u",(int)freq_from_board[i]);
    }
    else {
      sprintf(tmp,"%u",scan_freq_average[i]);
    }
    root = api_add_string(root,chain_freq,tmp,copy_data);
  }
  root = api_add_uint8(root,"fan_num",&dev->fan_num,copy_data);
  for (i = 0; i < 8; i = i + 1) {
    sprintf(fan_name,"fan%d",i + 1);
    root = api_add_uint(root,fan_name,dev->fan_speed_value + i,copy_data);
  }
  temp_senor_num = dev->chain_num << 1;
  root = api_add_uint8(root,"temp_num",(uint8_t *)&temp_senor_num,copy_data);
  for (i = 0; i < 0x10; i = i + 1) {
    sprintf(temp_name,"temp%d",i + 1);
    root = api_add_int16(root,temp_name,dev->chain_asic_maxtemp[i],copy_data);
  }
  for (i = 0; i < 0x10; i = i + 1) {
    sprintf(temp2_name,"temp2_%d",i + 1);
    root = api_add_int16(root,temp2_name,dev->chain_asic_temp[i][0] + 1,copy_data);
  }
  for (i = 0; i < 0x10; i = i + 1) {
    no_value[0] = '-';
    no_value[1] = '\0';
    len = 0;
    for (j_1 = 0; j_1 < dev->chain_asic_temp_num[i]; j_1 = j_1 + 1) {
      iVar4 = sprintf(temp_pcb_value + len,"%d",(int)dev->chain_asic_temp[i][j_1][0]);
      len = len + iVar4;
      if (j_1 + 1 < (int)dev->chain_asic_temp_num[i]) {
        pcVar7 = temp_pcb_value + len;
        pcVar7[0] = '-';
        pcVar7[1] = '\0';
        len = len + 1;
      }
    }
    sprintf(temp_pcb_name,"temp_pcb%d",i + 1);
    if (len < 1) {
      root = api_add_string(root,temp_pcb_name,no_value,copy_data);
    }
    else {
      root = api_add_string(root,temp_pcb_name,temp_pcb_value,copy_data);
    }
  }
  for (i = 0; i < 0x10; i = i + 1) {
    no_value_1[0] = '-';
    no_value_1[1] = '\0';
    len_1 = 0;
    for (j_2 = 0; j_2 < dev->chain_asic_temp_num[i]; j_2 = j_2 + 1) {
      iVar4 = sprintf(temp_pcb_value + len_1,"%d",(int)dev->chain_asic_temp[i][j_2][1]);
      len_1 = len_1 + iVar4;
      if (j_2 + 1 < (int)dev->chain_asic_temp_num[i]) {
        pcVar7 = temp_pcb_value + len_1;
        pcVar7[0] = '-';
        pcVar7[1] = '\0';
        len_1 = len_1 + 1;
      }
    }
    sprintf(temp_chip_name,"temp_chip%d",i + 1);
    if (len_1 < 1) {
      root = api_add_string(root,temp_chip_name,no_value_1,copy_data);
    }
    else {
      root = api_add_string(root,temp_chip_name,temp_pcb_value,copy_data);
    }
  }
  for (i = 0; i < 0x10; i = i + 1) {
    dev_sum_freq = 0.0;
    sprintf(freq_sum,"freq_avg%d",i + 1);
    if (dev->chain_exist[i] == 1) {
      if (last_freq[i][1] == '}') {
        for (j = 0; j < (int)(uint)dev->chain_asic_num[i]; j = j + 1) {
          iVar4 = freq_pll_1393[0xc].freq;
          if (chain_badcore_num[i][j] < 0xf) {
            iVar4 = freq_pll_1393[*(byte *)(i * 0x100 + j * 2 + 0xb3b797)].freq;
          }
          dev_sum_freq = (double)(longlong)iVar4 + dev_sum_freq;
        }
        if (dev->chain_asic_num[i] != '\0') {
          dev_sum_freq = dev_sum_freq / (double)dev->chain_asic_num[i];
        }
        temp = (int)(longlong)(dev_sum_freq * 100.0);
        dev_sum_freq = (double)(longlong)temp / 100.0;
        root = api_add_mhs(root,freq_sum,&dev_sum_freq,true);
      }
      else {
        temp = (int)(longlong)(dev_sum_freq * 100.0);
        dev_sum_freq = (double)(longlong)temp / 100.0;
        root = api_add_mhs(root,freq_sum,&dev_sum_freq,true);
      }
    }
    else {
      temp = (int)(longlong)(dev_sum_freq * 100.0);
      dev_sum_freq = (double)(longlong)temp / 100.0;
      root = api_add_mhs(root,freq_sum,&dev_sum_freq,true);
    }
  }
  dev_sum_freq_1 = 0.0;
  builtin_strncpy(temp_pcb_value,"total_rateideal",0x10);
  t11_eco_rate = GetTotalRate();
  t11a_eco_rate = 0x445c;
  _Var3 = is_economic_mode();
  if (_Var3) {
    _Var3 = is_T11();
    if (_Var3) {
      dev_sum_freq_1 = (double)(longlong)t11_eco_rate;
    }
    else {
      dev_sum_freq_1 = (double)(longlong)t11a_eco_rate;
    }
  }
  else {
    iVar4 = GetTotalRate();
    dev_sum_freq_1 = (double)(longlong)iVar4;
  }
  root = api_add_mhs(root,temp_pcb_value,&dev_sum_freq_1,true);
  j_3 = 0;
  total_acn_num = 0;
  dev_sum_freq_2 = 0.0;
  builtin_strncpy(temp_pcb_value,"total_freqav",0xc);
  temp_pcb_value[0xc] = 'g';
  temp_pcb_value[0xd] = '\0';
  for (i = 0; i < 0x10; i = i + 1) {
    if ((dev->chain_exist[i] == 1) && (last_freq[i][1] == '}')) {
      for (j_3 = 0; j_3 < (int)(uint)dev->chain_asic_num[i]; j_3 = j_3 + 1) {
        iVar4 = freq_pll_1393[0xc].freq;
        if (chain_badcore_num[i][j_3] < 0xf) {
          iVar4 = freq_pll_1393[*(byte *)(i * 0x100 + j_3 * 2 + 0xb3b797)].freq;
        }
        dev_sum_freq_2 = (double)(longlong)iVar4 + dev_sum_freq_2;
        total_acn_num = total_acn_num + 1;
      }
    }
  }
  temp_1 = (int)(longlong)((dev_sum_freq_2 / (double)(longlong)total_acn_num) * 100.0);
  dev_sum_freq_2 = (double)(longlong)temp_1 / 100.0;
  root = api_add_mhs(root,temp_pcb_value,&dev_sum_freq_2,true);
  uVar2 = temp_pcb_value._8_4_;
  asic_num_total = 0;
  builtin_strncpy(temp_pcb_value,"total_acn",10);
  temp_pcb_value._10_2_ = SUB42(uVar2,2);
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      asic_num_total = asic_num_total + (ushort)dev->chain_asic_num[i];
    }
  }
  root = api_add_int16(root,temp_pcb_value,&asic_num_total,true);
  total_rate = 0.0;
  builtin_strncpy(temp_pcb_value,"total_ra",8);
  temp_pcb_value[8] = 't';
  temp_pcb_value[9] = 'e';
  temp_pcb_value[10] = '\0';
  for (i = 0; i < 0x10; i = i + 1) {
    if ((dev->chain_exist[i] == 1) && (displayed_rate[i][0] != '\0')) {
      dVar10 = atof(displayed_rate[i]);
      total_rate = dVar10 + total_rate;
    }
  }
  temp_2 = (int)(longlong)(total_rate * 100.0);
  total_rate = (double)(longlong)temp_2 / 100.0;
  root = api_add_mhs(root,temp_pcb_value,&total_rate,true);
  for (i = 0; i < 0x10; i = i + 1) {
    j_4 = 0;
    dev_sum_freq_3 = 0.0;
    sprintf(temp_pcb_value,"chain_rateideal%d",i + 1);
    if (dev->chain_exist[i] == 1) {
      if (last_freq[i][1] == '}') {
        for (j_4 = 0; j_4 < (int)(uint)dev->chain_asic_num[i]; j_4 = j_4 + 1) {
          if (chain_badcore_num[i][j_4] < 0xf) {
            dev_sum_freq_3 =
                 (double)(longlong)
                         ((0xd0 - chain_badcore_num[i][j_4]) *
                         freq_pll_1393[*(byte *)(i * 0x100 + j_4 * 2 + 0xb3b797)].freq) +
                 dev_sum_freq_3;
          }
        }
        temp_3 = (int)(longlong)((dev_sum_freq_3 / 1000.0) * 100.0);
        dev_sum_freq_3 = (double)(longlong)temp_3 / 100.0;
        root = api_add_mhs(root,temp_pcb_value,&dev_sum_freq_3,true);
      }
      else {
        temp_3 = (int)(longlong)((dev_sum_freq_3 / 1000.0) * 100.0);
        dev_sum_freq_3 = (double)(longlong)temp_3 / 100.0;
        root = api_add_mhs(root,temp_pcb_value,&dev_sum_freq_3,true);
      }
    }
    else {
      temp_3 = (int)(longlong)((dev_sum_freq_3 / 1000.0) * 100.0);
      dev_sum_freq_3 = (double)(longlong)temp_3 / 100.0;
      root = api_add_mhs(root,temp_pcb_value,&dev_sum_freq_3,true);
    }
  }
  root = api_add_int(root,"temp_max",dev->temp_top1,copy_data);
  DVar11 = __fixdfdi(a);
  total_diff1._0_4_ = (uint)DVar11;
  total_diff1._4_4_ = (int)((ulonglong)DVar11 >> 0x20);
  total_diff1 = DVar11;
  if (hw_errors_temp + (uint)total_diff1 == 0 &&
      (hw_errors_temp >> 0x1f) + total_diff1._4_4_ + (uint)CARRY4(hw_errors_temp,(uint)total_diff1)
      == 0) {
    dev_hwp = 0.0;
  }
  else {
    lVar1 = (longlong)hw_errors_temp;
    iVar8 = hw_errors_temp + (uint)total_diff1;
    iVar4 = total_diff1._4_4_ + (uint)CARRY4(hw_errors_temp,(uint)total_diff1);
    dVar10 = (double)__aeabi_l2d(iVar8,(hw_errors_temp >> 0x1f) + iVar4);
    dev_hwp = (double)lVar1 / dVar10;
  }
  root = api_add_percent(root,"Device Hardware%",&dev_hwp,true);
  root = api_add_int(root,"no_matching_work",&hw_errors_temp,copy_data);
  for (i = 0; i < 0x10; i = i + 1) {
    sprintf(chain_name,"chain_acn%d",i + 1);
    root = api_add_uint8(root,chain_name,dev->chain_asic_num + i,copy_data);
  }
  for (i = 0; i < 0x10; i = i + 1) {
    sprintf(chain_asic_name,"chain_acs%d",i + 1);
    root = api_add_string(root,chain_asic_name,dev->chain_asic_status_string[i],copy_data);
  }
  for (i = 0; i < 0x10; i = i + 1) {
    sprintf(chain_hw,"chain_hw%d",i + 1);
    root = api_add_uint32(root,chain_hw,dev->chain_hw + i,copy_data);
  }
  for (i = 0; i < 0x10; i = i + 1) {
    sprintf(chain_rate,"chain_rate%d",i + 1);
    root = api_add_string(root,chain_rate,displayed_rate[i],copy_data);
  }
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      printf("chain_rate[%d]=(%s) ",i + 1,displayed_rate + i);
    }
  }
  putchar(10);
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      first = true;
      j_5 = 0;
      temp_pcb_value[0] = '{';
      temp_pcb_value[1] = '\0';
      temp_pcb_value[2] = '\0';
      temp_pcb_value[3] = '\0';
      memset(temp_pcb_value + 4,0,0x7fc);
      tmp_1[0] = '\0';
      tmp_1[1] = '\0';
      tmp_1[2] = '\0';
      tmp_1[3] = '\0';
      tmp_1[4] = '\0';
      tmp_1[5] = '\0';
      tmp_1[6] = '\0';
      tmp_1[7] = '\0';
      tmp_1[8] = '\0';
      tmp_1[9] = '\0';
      tmp_1[10] = '\0';
      tmp_1[0xb] = '\0';
      tmp_1[0xc] = '\0';
      tmp_1[0xd] = '\0';
      tmp_1[0xe] = '\0';
      tmp_1[0xf] = '\0';
      tmp_1[0x10] = '\0';
      tmp_1[0x11] = '\0';
      tmp_1[0x12] = '\0';
      tmp_1[0x13] = '\0';
      sprintf(chain_xtime,"chain_xtime%d",i + 1);
      if (x_time[i][0] != 0) {
        sprintf(tmp_1,"X%d=%d",0,x_time[i][0]);
        strcat(temp_pcb_value,tmp_1);
        first = false;
      }
      for (j_5 = 1; j_5 < (int)(uint)dev->chain_asic_num[i]; j_5 = j_5 + 1) {
        if (x_time[i][j_5] != 0) {
          if (first == false) {
            sprintf(tmp_1,",X%d=%d",j_5,x_time[i][j_5]);
          }
          else {
            sprintf(tmp_1,"X%d=%d",j_5,x_time[i][j_5]);
            first = false;
          }
          strcat(temp_pcb_value,tmp_1);
        }
      }
      sVar5 = strlen(temp_pcb_value);
      (temp_pcb_value + sVar5)[0] = '}';
      (temp_pcb_value + sVar5)[1] = '\0';
      root = api_add_string(root,chain_xtime,temp_pcb_value,copy_data);
    }
  }
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      sprintf(chain_offside,"chain_offside_%d",i + 1);
      sprintf(tmp_2,"%d",temp_offside[i]);
      root = api_add_string(root,chain_offside,tmp_2,copy_data);
    }
  }
  for (i = 0; uVar2 = temp_pcb_value._12_4_, i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      sprintf(chain_opencore,"chain_opencore_%d",i + 1);
      if (isChainAllCoresOpened[i] == false) {
        tmp_3[0] = '0';
        tmp_3[1] = '\0';
      }
      else {
        tmp_3[0] = '1';
        tmp_3[1] = '\0';
      }
      root = api_add_string(root,chain_opencore,tmp_3,copy_data);
    }
  }
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      bVar9 = CARRY4((uint)hash_rate_all,(uint)rate[i]);
      hash_rate_all._0_4_ = (uint)hash_rate_all + (uint)rate[i];
      hash_rate_all._4_4_ = hash_rate_all._4_4_ + *(int *)((int)rate + i * 8 + 4) + (uint)bVar9;
    }
  }
  builtin_strncpy(temp_pcb_value,"miner_version",0xe);
  temp_pcb_value._14_2_ = SUB42(uVar2,2);
  root = api_add_string(root,temp_pcb_value,g_miner_version,copy_data);
  builtin_strncpy(temp_pcb_value,"miner_id",8);
  temp_pcb_value._8_4_ = temp_pcb_value._8_4_ & 0xffffff00;
  paVar6 = api_add_string(root,temp_pcb_value,FPGA_ID_str,copy_data);
  return paVar6;
}

