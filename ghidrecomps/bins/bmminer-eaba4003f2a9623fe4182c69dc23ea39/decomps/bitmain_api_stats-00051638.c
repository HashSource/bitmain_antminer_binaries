
api_data * bitmain_api_stats(cgpu_info *cgpu)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  api_data *paVar4;
  size_t sVar5;
  bool bVar6;
  double dVar7;
  cgpu_info *cgpu_local;
  char freq_sum_1 [32];
  char tmp_2 [20];
  char chain_opencore [20];
  char tmp_1 [20];
  char chain_offside [20];
  char tmp [20];
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
  char temp3_name [12];
  char temp2_name [12];
  char temp_name [12];
  char fan_name [12];
  double dev_hwp;
  char displayed_rate_all [16];
  char buf [64];
  int j_6;
  int j_5;
  int temp_4;
  int temp_3;
  int temp_2;
  int temp_1;
  int temp;
  _Bool copy_data;
  bitmain_soc_info *info;
  int j_4;
  _Bool first;
  int j_3;
  int total_acn_num;
  int j_2;
  int j_1;
  int j;
  uint64_t hash_rate_all;
  int i;
  api_data *root;
  
  paVar4 = api_add_uint8((api_data *)0x0,"miner_count",&dev->chain_num,true);
  paVar4 = api_add_string(paVar4,"frequency",dev->frequency_t,true);
  root = api_add_uint8(paVar4,"fan_num",&dev->fan_num,true);
  for (i = 0; i < 8; i = i + 1) {
    sprintf(fan_name,"fan%d",i + 1);
    root = api_add_uint(root,fan_name,dev->fan_speed_value + i,true);
  }
  root = api_add_uint8(root,"temp_num",&dev->chain_num,true);
  for (i = 0; i < 0x10; i = i + 1) {
    sprintf(temp_name,"temp%d",i + 1);
    root = api_add_int16(root,temp_name,(uint16_t *)(dev->chain_asic_maxtemp + i),true);
  }
  for (i = 0; i < 0x10; i = i + 1) {
    sprintf(temp2_name,"temp2_%d",i + 1);
    root = api_add_int16(root,temp2_name,(uint16_t *)(dev->chain_asic_temp[i][0] + 1),true);
  }
  for (i = 0; i < 0x10; i = i + 1) {
    sprintf(temp3_name,"temp3_%d",i + 1);
    root = api_add_int16(root,temp3_name,(uint16_t *)(dev->chain_asic_temp[i][1] + 1),true);
  }
  for (i = 0; i < 0x10; i = i + 1) {
    dev_sum_freq = 0.0;
    sprintf(freq_sum,"freq_avg%d",i + 1);
    if (dev->chain_exist[i] == 1) {
      if (last_freq[i][1] == '}') {
        for (j = 0; j < (int)(uint)dev->chain_asic_num[i]; j = j + 1) {
          iVar2 = freq_pll_1393[0xc].freq;
          if (chain_badcore_num[i][j] < 0xf) {
            iVar2 = freq_pll_1393[last_freq[i][j * 2 + 3]].freq;
          }
          dev_sum_freq = (double)(longlong)iVar2 + dev_sum_freq;
        }
        if (dev->chain_asic_num[i] != '\0') {
          dev_sum_freq = dev_sum_freq / (double)dev->chain_asic_num[i];
        }
        dev_sum_freq = (double)(longlong)(int)(longlong)(dev_sum_freq * 100.0) / 100.0;
        root = api_add_mhs(root,freq_sum,&dev_sum_freq,true);
      }
      else {
        dev_sum_freq = (double)(longlong)(int)(longlong)(dev_sum_freq * 100.0) / 100.0;
        root = api_add_mhs(root,freq_sum,&dev_sum_freq,true);
      }
    }
    else {
      dev_sum_freq = (double)(longlong)(int)(longlong)(dev_sum_freq * 100.0) / 100.0;
      root = api_add_mhs(root,freq_sum,&dev_sum_freq,true);
    }
  }
  dev_sum_freq_1 = 0.0;
  builtin_strncpy(freq_sum_1,"total_rateideal",0x10);
  for (i = 0; i < 0x10; i = i + 1) {
    if ((dev->chain_exist[i] == 1) && (last_freq[i][1] == '}')) {
      for (j_1 = 0; j_1 < (int)(uint)dev->chain_asic_num[i]; j_1 = j_1 + 1) {
        if (chain_badcore_num[i][j_1] < 0xf) {
          dev_sum_freq_1 =
               (double)(longlong)
                       ((0xd0 - chain_badcore_num[i][j_1]) *
                       freq_pll_1393[last_freq[i][j_1 * 2 + 3]].freq) + dev_sum_freq_1;
        }
      }
    }
  }
  dev_sum_freq_1 = (double)(longlong)(int)(longlong)((dev_sum_freq_1 / 1000.0) * 100.0) / 100.0;
  paVar4 = api_add_mhs(root,freq_sum_1,&dev_sum_freq_1,true);
  total_acn_num = 0;
  dev_sum_freq_2 = 0.0;
  builtin_strncpy(freq_sum_1,"total_freqav",0xc);
  freq_sum_1[0xc] = 'g';
  freq_sum_1[0xd] = '\0';
  for (i = 0; i < 0x10; i = i + 1) {
    if ((dev->chain_exist[i] == 1) && (last_freq[i][1] == '}')) {
      for (j_2 = 0; j_2 < (int)(uint)dev->chain_asic_num[i]; j_2 = j_2 + 1) {
        iVar2 = freq_pll_1393[0xc].freq;
        if (chain_badcore_num[i][j_2] < 0xf) {
          iVar2 = freq_pll_1393[last_freq[i][j_2 * 2 + 3]].freq;
        }
        dev_sum_freq_2 = (double)(longlong)iVar2 + dev_sum_freq_2;
        total_acn_num = total_acn_num + 1;
      }
    }
  }
  dev_sum_freq_2 =
       (double)(longlong)(int)(longlong)((dev_sum_freq_2 / (double)(longlong)total_acn_num) * 100.0)
       / 100.0;
  paVar4 = api_add_mhs(paVar4,freq_sum_1,&dev_sum_freq_2,true);
  uVar3 = freq_sum_1._8_4_;
  asic_num_total = 0;
  builtin_strncpy(freq_sum_1,"total_acn",10);
  freq_sum_1._10_2_ = SUB42(uVar3,2);
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      asic_num_total = (ushort)dev->chain_asic_num[i] + asic_num_total;
    }
  }
  paVar4 = api_add_int16(paVar4,freq_sum_1,(uint16_t *)&asic_num_total,true);
  total_rate = 0.0;
  builtin_strncpy(freq_sum_1,"total_ra",8);
  freq_sum_1[8] = 't';
  freq_sum_1[9] = 'e';
  freq_sum_1[10] = '\0';
  for (i = 0; i < 0x10; i = i + 1) {
    if ((dev->chain_exist[i] == 1) && (displayed_rate[i][0] != '\0')) {
      dVar7 = atof(displayed_rate[i]);
      total_rate = dVar7 + total_rate;
    }
  }
  total_rate = (double)(longlong)(int)(longlong)(total_rate * 100.0) / 100.0;
  root = api_add_mhs(paVar4,freq_sum_1,&total_rate,true);
  for (i = 0; i < 0x10; i = i + 1) {
    dev_sum_freq_3 = 0.0;
    sprintf(freq_sum_1,"chain_rateideal%d",i + 1);
    if (dev->chain_exist[i] == 1) {
      if (last_freq[i][1] == '}') {
        for (j_3 = 0; j_3 < (int)(uint)dev->chain_asic_num[i]; j_3 = j_3 + 1) {
          if (chain_badcore_num[i][j_3] < 0xf) {
            dev_sum_freq_3 =
                 (double)(longlong)
                         ((0xd0 - chain_badcore_num[i][j_3]) *
                         freq_pll_1393[last_freq[i][j_3 * 2 + 3]].freq) + dev_sum_freq_3;
          }
        }
        dev_sum_freq_3 =
             (double)(longlong)(int)(longlong)((dev_sum_freq_3 / 1000.0) * 100.0) / 100.0;
        root = api_add_mhs(root,freq_sum_1,&dev_sum_freq_3,true);
      }
      else {
        dev_sum_freq_3 =
             (double)(longlong)(int)(longlong)((dev_sum_freq_3 / 1000.0) * 100.0) / 100.0;
        root = api_add_mhs(root,freq_sum_1,&dev_sum_freq_3,true);
      }
    }
    else {
      dev_sum_freq_3 = (double)(longlong)(int)(longlong)((dev_sum_freq_3 / 1000.0) * 100.0) / 100.0;
      root = api_add_mhs(root,freq_sum_1,&dev_sum_freq_3,true);
    }
  }
  paVar4 = api_add_int(root,"temp_max",dev->temp_top1,true);
  dVar7 = total_diff_accepted + total_diff_rejected + total_diff_stale;
  total_diff1 = __aeabi_d2lz(SUB84(dVar7,0),(int)((ulonglong)dVar7 >> 0x20));
  if (total_diff1 + hw_errors == 0) {
    dev_hwp = 0.0;
  }
  else {
    lVar1 = (longlong)hw_errors;
    dVar7 = (double)__aeabi_l2d((int)(total_diff1 + hw_errors),
                                (int)((ulonglong)(total_diff1 + hw_errors) >> 0x20));
    dev_hwp = (double)lVar1 / dVar7;
  }
  paVar4 = api_add_percent(paVar4,"Device Hardware%",&dev_hwp,true);
  root = api_add_int(paVar4,"no_matching_work",&hw_errors,true);
  for (i = 0; i < 0x10; i = i + 1) {
    sprintf(chain_name,"chain_acn%d",i + 1);
    root = api_add_uint8(root,chain_name,dev->chain_asic_num + i,true);
  }
  for (i = 0; i < 0x10; i = i + 1) {
    sprintf(chain_asic_name,"chain_acs%d",i + 1);
    root = api_add_string(root,chain_asic_name,dev->chain_asic_status_string[i],true);
  }
  for (i = 0; i < 0x10; i = i + 1) {
    sprintf(chain_hw,"chain_hw%d",i + 1);
    root = api_add_uint32(root,chain_hw,dev->chain_hw + i,true);
  }
  for (i = 0; i < 0x10; i = i + 1) {
    sprintf(chain_rate,"chain_rate%d",i + 1);
    root = api_add_string(root,chain_rate,displayed_rate[i],true);
  }
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      printf("chain_rate[%d]=(%s) ",i + 1,displayed_rate + i);
    }
  }
  putchar(10);
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      freq_sum_1[0] = '{';
      freq_sum_1[1] = '\0';
      freq_sum_1[2] = '\0';
      freq_sum_1[3] = '\0';
      memset(freq_sum_1 + 4,0,0x7fc);
      tmp[0] = '\0';
      tmp[1] = '\0';
      tmp[2] = '\0';
      tmp[3] = '\0';
      tmp[4] = '\0';
      tmp[5] = '\0';
      tmp[6] = '\0';
      tmp[7] = '\0';
      tmp[8] = '\0';
      tmp[9] = '\0';
      tmp[10] = '\0';
      tmp[0xb] = '\0';
      tmp[0xc] = '\0';
      tmp[0xd] = '\0';
      tmp[0xe] = '\0';
      tmp[0xf] = '\0';
      tmp[0x10] = '\0';
      tmp[0x11] = '\0';
      tmp[0x12] = '\0';
      tmp[0x13] = '\0';
      sprintf(chain_xtime,"chain_xtime%d",i + 1);
      bVar6 = x_time[i][0] != 0;
      if (bVar6) {
        sprintf(tmp,"X%d=%d",0,x_time[i][0]);
        strcat(freq_sum_1,tmp);
      }
      first = !bVar6;
      for (j_4 = 1; j_4 < (int)(uint)dev->chain_asic_num[i]; j_4 = j_4 + 1) {
        if (x_time[i][j_4] != 0) {
          if (first) {
            sprintf(tmp,"X%d=%d",j_4,x_time[i][j_4]);
            first = false;
          }
          else {
            sprintf(tmp,",X%d=%d",j_4,x_time[i][j_4]);
          }
          strcat(freq_sum_1,tmp);
        }
      }
      sVar5 = strlen(freq_sum_1);
      (freq_sum_1 + sVar5)[0] = '}';
      (freq_sum_1 + sVar5)[1] = '\0';
      root = api_add_string(root,chain_xtime,freq_sum_1,true);
    }
  }
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      sprintf(chain_offside,"chain_offside_%d",i + 1);
      sprintf(tmp_1,"%d",temp_offside[i]);
      root = api_add_string(root,chain_offside,tmp_1,true);
    }
  }
  for (i = 0; uVar3 = freq_sum_1._12_4_, i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      sprintf(chain_opencore,"chain_opencore_%d",i + 1);
      if (isChainAllCoresOpened[i] == false) {
        tmp_2[0] = '0';
        tmp_2[1] = '\0';
      }
      else {
        tmp_2[0] = '1';
        tmp_2[1] = '\0';
      }
      root = api_add_string(root,chain_opencore,tmp_2,true);
    }
  }
  for (i = 0; i < 0x10; i = i + 1) {
  }
  builtin_strncpy(freq_sum_1,"miner_version",0xe);
  freq_sum_1._14_2_ = SUB42(uVar3,2);
  paVar4 = api_add_string(root,freq_sum_1,g_miner_version,true);
  builtin_strncpy(freq_sum_1,"miner_id",8);
  freq_sum_1._8_4_ = freq_sum_1._8_4_ & 0xffffff00;
  paVar4 = api_add_string(paVar4,freq_sum_1,FPGA_ID_str,true);
  return paVar4;
}

