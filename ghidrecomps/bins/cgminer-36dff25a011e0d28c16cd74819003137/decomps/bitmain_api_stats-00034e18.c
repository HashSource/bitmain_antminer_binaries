
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

api_data * bitmain_api_stats(cgpu_info *cgpu)

{
  longlong lVar1;
  int iVar2;
  size_t sVar3;
  api_data *paVar4;
  bool bVar5;
  double dVar6;
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
  uint16_t asic_num_total;
  double dev_sum_freq_2;
  double dev_sum_freq_1;
  double dev_sum_freq;
  char freq_sum [12];
  char temp_chip_name [12];
  char no_value_1 [2];
  char temp_pcb_name [12];
  char no_value [2];
  char temp3_name [12];
  char temp2_name [12];
  char temp_name [12];
  char fan_name [12];
  char chain_freq [12];
  char tmp [12];
  double dev_hwp;
  int temp;
  int temp_3;
  int temp_2;
  int temp_1;
  _Bool copy_data;
  int j_5;
  _Bool first;
  int j_4;
  int total_acn_num;
  int j_3;
  int j_2;
  int len_1;
  int j_1;
  int len;
  int j;
  uint64_t hash_rate_all;
  int i;
  api_data *root;
  
  root = (api_data *)0x0;
  i = 0;
  hash_rate_all._0_4_ = 0;
  hash_rate_all._4_4_ = 0;
  copy_data = true;
  root = api_add_uint8((api_data *)0x0,"miner_count",&dev->chain_num,true);
  root = api_add_string(root,"frequency",dev->frequency_t,copy_data);
  for (i = 0; i < 0x10; i = i + 1) {
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
  root = api_add_uint8(root,"temp_num",&dev->chain_num,copy_data);
  for (i = 0; i < 0x10; i = i + 1) {
    sprintf(temp_name,"temp%d",i + 1);
    root = api_add_int16(root,temp_name,(uint16_t *)(dev->chain_asic_maxtemp + i),copy_data);
  }
  for (i = 0; i < 0x10; i = i + 1) {
    sprintf(temp2_name,"temp2_%d",i + 1);
    root = api_add_int16(root,temp2_name,(uint16_t *)(dev->chain_asic_temp[i][0] + 1),copy_data);
  }
  for (i = 0; i < 0x10; i = i + 1) {
    sprintf(temp3_name,"temp3_%d",i + 1);
    root = api_add_int16(root,temp3_name,(uint16_t *)(dev->chain_asic_temp[i][1] + 1),copy_data);
  }
  for (i = 0; i < 0x10; i = i + 1) {
    no_value[0] = '-';
    no_value[1] = '\0';
    len = 0;
    for (j = 0; j < dev->chain_asic_temp_num[i]; j = j + 1) {
      iVar2 = sprintf(temp_pcb_value + len,"%d",(int)dev->chain_asic_temp[i][j][0]);
      len = len + iVar2;
      if (j + 1 < (int)dev->chain_asic_temp_num[i]) {
        *(undefined2 *)(temp_pcb_value + len) = DAT_0009dad4;
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
    for (j_1 = 0; j_1 < dev->chain_asic_temp_num[i]; j_1 = j_1 + 1) {
      iVar2 = sprintf(temp_pcb_value + len_1,"%d",(int)dev->chain_asic_temp[i][j_1][1]);
      len_1 = len_1 + iVar2;
      if (j_1 + 1 < (int)dev->chain_asic_temp_num[i]) {
        *(undefined2 *)(temp_pcb_value + len_1) = DAT_0009dad4;
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
    j_2 = 0;
    dev_sum_freq = 0.0;
    sprintf(freq_sum,"freq_avg%d",i + 1);
    if (dev->chain_exist[i] == 1) {
      if (last_freq[i][1] == '}') {
        for (j_2 = 0; j_2 < (int)(uint)dev->chain_asic_num[i]; j_2 = j_2 + 1) {
          iVar2 = freq_pll_1391[12].freq;
          if (chain_badcore_num[i][j_2] < 0xf) {
            iVar2 = freq_pll_1391[*(byte *)(i * 0x100 + j_2 * 2 + 0x3aeccf)].freq;
          }
          dev_sum_freq = (double)(longlong)iVar2 + dev_sum_freq;
        }
        if (dev->chain_asic_num[i] != '\0') {
          dev_sum_freq = dev_sum_freq / (double)(longlong)(int)(uint)dev->chain_asic_num[i];
        }
        temp = (int)(longlong)(dev_sum_freq * DAT_00035a68);
        dev_sum_freq = (double)(longlong)temp / DAT_00035a68;
        root = api_add_mhs(root,freq_sum,&dev_sum_freq,true);
      }
      else {
        temp = (int)(longlong)(dev_sum_freq * DAT_00035a68);
        dev_sum_freq = (double)(longlong)temp / DAT_00035a68;
        root = api_add_mhs(root,freq_sum,&dev_sum_freq,true);
      }
    }
    else {
      temp = (int)(longlong)(dev_sum_freq * DAT_00035a68);
      dev_sum_freq = (double)(longlong)temp / DAT_00035a68;
      root = api_add_mhs(root,freq_sum,&dev_sum_freq,true);
    }
  }
  dev_sum_freq_1 = 0.0;
  temp_pcb_value[0] = s_total_rateideal_0009dafc[0];
  temp_pcb_value[1] = s_total_rateideal_0009dafc[1];
  temp_pcb_value[2] = s_total_rateideal_0009dafc[2];
  temp_pcb_value[3] = s_total_rateideal_0009dafc[3];
  temp_pcb_value[4] = s_total_rateideal_0009dafc[4];
  temp_pcb_value[5] = s_total_rateideal_0009dafc[5];
  temp_pcb_value[6] = s_total_rateideal_0009dafc[6];
  temp_pcb_value[7] = s_total_rateideal_0009dafc[7];
  temp_pcb_value[8] = s_total_rateideal_0009dafc[8];
  temp_pcb_value[9] = s_total_rateideal_0009dafc[9];
  temp_pcb_value[10] = s_total_rateideal_0009dafc[10];
  temp_pcb_value[11] = s_total_rateideal_0009dafc[11];
  temp_pcb_value[12] = s_total_rateideal_0009dafc[12];
  temp_pcb_value[13] = s_total_rateideal_0009dafc[13];
  temp_pcb_value[14] = s_total_rateideal_0009dafc[14];
  temp_pcb_value[15] = s_total_rateideal_0009dafc[15];
  iVar2 = get_total_rate();
  dev_sum_freq_1 = (double)(longlong)iVar2;
  root = api_add_mhs(root,temp_pcb_value,&dev_sum_freq_1,true);
  j_3 = 0;
  total_acn_num = 0;
  dev_sum_freq_2 = 0.0;
  temp_pcb_value[0] = s_total_freqavg_0009db0c[0];
  temp_pcb_value[1] = s_total_freqavg_0009db0c[1];
  temp_pcb_value[2] = s_total_freqavg_0009db0c[2];
  temp_pcb_value[3] = s_total_freqavg_0009db0c[3];
  temp_pcb_value[4] = s_total_freqavg_0009db0c[4];
  temp_pcb_value[5] = s_total_freqavg_0009db0c[5];
  temp_pcb_value[6] = s_total_freqavg_0009db0c[6];
  temp_pcb_value[7] = s_total_freqavg_0009db0c[7];
  temp_pcb_value[8] = s_total_freqavg_0009db0c[8];
  temp_pcb_value[9] = s_total_freqavg_0009db0c[9];
  temp_pcb_value[10] = s_total_freqavg_0009db0c[10];
  temp_pcb_value[11] = s_total_freqavg_0009db0c[11];
  temp_pcb_value[12] = (char)(short)ram0x0009db18;
  temp_pcb_value[13] = (char)((ushort)(short)ram0x0009db18 >> 8);
  for (i = 0; i < 0x10; i = i + 1) {
    if ((dev->chain_exist[i] == 1) && (last_freq[i][1] == '}')) {
      for (j_3 = 0; j_3 < (int)(uint)dev->chain_asic_num[i]; j_3 = j_3 + 1) {
        iVar2 = freq_pll_1391[12].freq;
        if (chain_badcore_num[i][j_3] < 0xf) {
          iVar2 = freq_pll_1391[*(byte *)(i * 0x100 + j_3 * 2 + 0x3aeccf)].freq;
        }
        dev_sum_freq_2 = (double)(longlong)iVar2 + dev_sum_freq_2;
        total_acn_num = total_acn_num + 1;
      }
    }
  }
  temp_1 = (int)(longlong)((dev_sum_freq_2 / (double)(longlong)total_acn_num) * DAT_00035a68);
  dev_sum_freq_2 = (double)(longlong)temp_1 / DAT_00035a68;
  root = api_add_mhs(root,temp_pcb_value,&dev_sum_freq_2,true);
  asic_num_total = 0;
  temp_pcb_value[0] = s_total_acn_0009db1c[0];
  temp_pcb_value[1] = s_total_acn_0009db1c[1];
  temp_pcb_value[2] = s_total_acn_0009db1c[2];
  temp_pcb_value[3] = s_total_acn_0009db1c[3];
  temp_pcb_value[4] = s_total_acn_0009db1c[4];
  temp_pcb_value[5] = s_total_acn_0009db1c[5];
  temp_pcb_value[6] = s_total_acn_0009db1c[6];
  temp_pcb_value[7] = s_total_acn_0009db1c[7];
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      asic_num_total = dev->chain_asic_num[i] + asic_num_total;
    }
  }
  temp_pcb_value._8_2_ = (short)ram0x0009db24;
  root = api_add_int16(root,temp_pcb_value,&asic_num_total,true);
  total_rate = 0.0;
  temp_pcb_value[0] = s_total_rate_0009db28[0];
  temp_pcb_value[1] = s_total_rate_0009db28[1];
  temp_pcb_value[2] = s_total_rate_0009db28[2];
  temp_pcb_value[3] = s_total_rate_0009db28[3];
  temp_pcb_value[4] = s_total_rate_0009db28[4];
  temp_pcb_value[5] = s_total_rate_0009db28[5];
  temp_pcb_value[6] = s_total_rate_0009db28[6];
  temp_pcb_value[7] = s_total_rate_0009db28[7];
  temp_pcb_value._8_3_ = (undefined3)ram0x0009db30;
  for (i = 0; i < 0x10; i = i + 1) {
    if ((dev->chain_exist[i] == 1) && (displayed_rate[i][0] != '\0')) {
      dVar6 = atof(displayed_rate[i]);
      total_rate = dVar6 + total_rate;
    }
  }
  temp_2 = (int)(longlong)(total_rate * DAT_00035a68);
  total_rate = (double)(longlong)temp_2 / DAT_00035a68;
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
                         ((0x2a0 - chain_badcore_num[i][j_4]) *
                         freq_pll_1391[*(byte *)(i * 0x100 + j_4 * 2 + 0x3aeccf)].freq) +
                 dev_sum_freq_3;
          }
        }
        temp_3 = (int)(longlong)((dev_sum_freq_3 / DAT_00035a60) * DAT_00035a68);
        dev_sum_freq_3 = (double)(longlong)temp_3 / DAT_00035a68;
        root = api_add_mhs(root,temp_pcb_value,&dev_sum_freq_3,true);
      }
      else {
        temp_3 = (int)(longlong)((dev_sum_freq_3 / DAT_00035a60) * DAT_00035a68);
        dev_sum_freq_3 = (double)(longlong)temp_3 / DAT_00035a68;
        root = api_add_mhs(root,temp_pcb_value,&dev_sum_freq_3,true);
      }
    }
    else {
      temp_3 = (int)(longlong)((dev_sum_freq_3 / DAT_000361e0) * DAT_000361e8);
      dev_sum_freq_3 = (double)(longlong)temp_3 / DAT_000361e8;
      root = api_add_mhs(root,temp_pcb_value,&dev_sum_freq_3,true);
    }
  }
  root = api_add_int(root,"temp_max",dev->temp_top1,copy_data);
  dVar6 = total_diff_accepted + total_diff_rejected + total_diff_stale;
  total_diff1 = __fixdfdi(SUB84(dVar6,0),(int)((ulonglong)dVar6 >> 0x20));
  dev_hwp = DAT_000361f0;
  if (total_diff1 + hw_errors != 0) {
    lVar1 = (longlong)hw_errors;
    dVar6 = (double)__aeabi_l2d((int)(total_diff1 + hw_errors),
                                (int)((ulonglong)(total_diff1 + hw_errors) >> 0x20));
    dev_hwp = (double)lVar1 / dVar6;
  }
  root = api_add_percent(root,"Device Hardware%",&dev_hwp,true);
  root = api_add_int(root,"no_matching_work",&hw_errors,copy_data);
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
      tmp_1[11] = '\0';
      tmp_1[12] = '\0';
      tmp_1[13] = '\0';
      tmp_1[14] = '\0';
      tmp_1[15] = '\0';
      tmp_1[16] = '\0';
      tmp_1[17] = '\0';
      tmp_1[18] = '\0';
      tmp_1[19] = '\0';
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
      sVar3 = strlen(temp_pcb_value);
      *(undefined2 *)(temp_pcb_value + sVar3) = DAT_0009dbe8;
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
  for (i = 0; i < 0x10; i = i + 1) {
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
      bVar5 = CARRY4((uint)hash_rate_all,*(uint *)(rate + i));
      hash_rate_all._0_4_ = (uint)hash_rate_all + *(uint *)(rate + i);
      hash_rate_all._4_4_ = hash_rate_all._4_4_ + *(int *)((int)rate + i * 8 + 4) + (uint)bVar5;
    }
  }
  temp_pcb_value[0] = s_miner_version_0009dc14[0];
  temp_pcb_value[1] = s_miner_version_0009dc14[1];
  temp_pcb_value[2] = s_miner_version_0009dc14[2];
  temp_pcb_value[3] = s_miner_version_0009dc14[3];
  temp_pcb_value[4] = s_miner_version_0009dc14[4];
  temp_pcb_value[5] = s_miner_version_0009dc14[5];
  temp_pcb_value[6] = s_miner_version_0009dc14[6];
  temp_pcb_value[7] = s_miner_version_0009dc14[7];
  temp_pcb_value[8] = s_miner_version_0009dc14[8];
  temp_pcb_value[9] = s_miner_version_0009dc14[9];
  temp_pcb_value[10] = s_miner_version_0009dc14[10];
  temp_pcb_value[11] = s_miner_version_0009dc14[11];
  temp_pcb_value[12] = (char)(short)ram0x0009dc20;
  temp_pcb_value[13] = (char)((ushort)(short)ram0x0009dc20 >> 8);
  root = api_add_string(root,temp_pcb_value,g_miner_version,copy_data);
  temp_pcb_value[0] = s_miner_id_0009dc24[0];
  temp_pcb_value[1] = s_miner_id_0009dc24[1];
  temp_pcb_value[2] = s_miner_id_0009dc24[2];
  temp_pcb_value[3] = s_miner_id_0009dc24[3];
  temp_pcb_value[4] = s_miner_id_0009dc24[4];
  temp_pcb_value[5] = s_miner_id_0009dc24[5];
  temp_pcb_value[6] = s_miner_id_0009dc24[6];
  temp_pcb_value[7] = s_miner_id_0009dc24[7];
  temp_pcb_value[8] = (char)ram0x0009dc2c;
  paVar4 = api_add_string(root,temp_pcb_value,FPGA_ID_str,copy_data);
  return paVar4;
}

