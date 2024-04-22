
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

api_data * bitmain_api_stats(cgpu_info *cgpu)

{
  longlong lVar1;
  int iVar2;
  api_data *paVar3;
  size_t sVar4;
  bool bVar5;
  double dVar6;
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
  
  copy_data = true;
  paVar3 = api_add_uint8((api_data *)0x0,"miner_count",&dev->chain_num,true);
  paVar3 = api_add_string(paVar3,"frequency",dev->frequency_t,true);
  root = api_add_uint8(paVar3,"fan_num",&dev->fan_num,true);
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
          iVar2 = freq_pll_1393[12].freq;
          if (chain_badcore_num[i][j] < 0xf) {
            iVar2 = freq_pll_1393[last_freq[i][j * 2 + 3]].freq;
          }
          dev_sum_freq = (double)(longlong)iVar2 + dev_sum_freq;
        }
        if (dev->chain_asic_num[i] != '\0') {
          dev_sum_freq = dev_sum_freq / (double)(longlong)(int)(uint)dev->chain_asic_num[i];
        }
        dev_sum_freq = (double)(longlong)(int)(longlong)(dev_sum_freq * DAT_00051d90) / DAT_00051d90
        ;
        root = api_add_mhs(root,freq_sum,&dev_sum_freq,true);
      }
      else {
        dev_sum_freq = (double)(longlong)(int)(longlong)(dev_sum_freq * DAT_00051d90) / DAT_00051d90
        ;
        root = api_add_mhs(root,freq_sum,&dev_sum_freq,true);
      }
    }
    else {
      dev_sum_freq = (double)(longlong)(int)(longlong)(dev_sum_freq * DAT_00051d90) / DAT_00051d90;
      root = api_add_mhs(root,freq_sum,&dev_sum_freq,true);
    }
  }
  dev_sum_freq_1 = 0.0;
  freq_sum_1[0] = s_total_rateideal_00079564[0];
  freq_sum_1[1] = s_total_rateideal_00079564[1];
  freq_sum_1[2] = s_total_rateideal_00079564[2];
  freq_sum_1[3] = s_total_rateideal_00079564[3];
  freq_sum_1[4] = s_total_rateideal_00079564[4];
  freq_sum_1[5] = s_total_rateideal_00079564[5];
  freq_sum_1[6] = s_total_rateideal_00079564[6];
  freq_sum_1[7] = s_total_rateideal_00079564[7];
  freq_sum_1[8] = s_total_rateideal_00079564[8];
  freq_sum_1[9] = s_total_rateideal_00079564[9];
  freq_sum_1[10] = s_total_rateideal_00079564[10];
  freq_sum_1[11] = s_total_rateideal_00079564[11];
  freq_sum_1[12] = s_total_rateideal_00079564[12];
  freq_sum_1[13] = s_total_rateideal_00079564[13];
  freq_sum_1[14] = s_total_rateideal_00079564[14];
  freq_sum_1[15] = s_total_rateideal_00079564[15];
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
  dev_sum_freq_1 =
       (double)(longlong)(int)(longlong)((dev_sum_freq_1 / DAT_00051d88) * DAT_00051d90) /
       DAT_00051d90;
  paVar3 = api_add_mhs(root,freq_sum_1,&dev_sum_freq_1,true);
  total_acn_num = 0;
  dev_sum_freq_2 = 0.0;
  freq_sum_1[0] = s_total_freqavg_00079574[0];
  freq_sum_1[1] = s_total_freqavg_00079574[1];
  freq_sum_1[2] = s_total_freqavg_00079574[2];
  freq_sum_1[3] = s_total_freqavg_00079574[3];
  freq_sum_1[4] = s_total_freqavg_00079574[4];
  freq_sum_1[5] = s_total_freqavg_00079574[5];
  freq_sum_1[6] = s_total_freqavg_00079574[6];
  freq_sum_1[7] = s_total_freqavg_00079574[7];
  freq_sum_1[8] = s_total_freqavg_00079574[8];
  freq_sum_1[9] = s_total_freqavg_00079574[9];
  freq_sum_1[10] = s_total_freqavg_00079574[10];
  freq_sum_1[11] = s_total_freqavg_00079574[11];
  freq_sum_1[12] = (char)(short)ram0x00079580;
  freq_sum_1[13] = (char)((ushort)(short)ram0x00079580 >> 8);
  for (i = 0; i < 0x10; i = i + 1) {
    if ((dev->chain_exist[i] == 1) && (last_freq[i][1] == '}')) {
      for (j_2 = 0; j_2 < (int)(uint)dev->chain_asic_num[i]; j_2 = j_2 + 1) {
        iVar2 = freq_pll_1393[12].freq;
        if (chain_badcore_num[i][j_2] < 0xf) {
          iVar2 = freq_pll_1393[last_freq[i][j_2 * 2 + 3]].freq;
        }
        dev_sum_freq_2 = (double)(longlong)iVar2 + dev_sum_freq_2;
        total_acn_num = total_acn_num + 1;
      }
    }
  }
  dev_sum_freq_2 =
       (double)(longlong)
               (int)(longlong)((dev_sum_freq_2 / (double)(longlong)total_acn_num) * DAT_00051d90) /
       DAT_00051d90;
  paVar3 = api_add_mhs(paVar3,freq_sum_1,&dev_sum_freq_2,true);
  asic_num_total = 0;
  freq_sum_1[0] = s_total_acn_00079584[0];
  freq_sum_1[1] = s_total_acn_00079584[1];
  freq_sum_1[2] = s_total_acn_00079584[2];
  freq_sum_1[3] = s_total_acn_00079584[3];
  freq_sum_1[4] = s_total_acn_00079584[4];
  freq_sum_1[5] = s_total_acn_00079584[5];
  freq_sum_1[6] = s_total_acn_00079584[6];
  freq_sum_1[7] = s_total_acn_00079584[7];
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      asic_num_total = (ushort)dev->chain_asic_num[i] + asic_num_total;
    }
  }
  freq_sum_1._8_2_ = (short)ram0x0007958c;
  paVar3 = api_add_int16(paVar3,freq_sum_1,(uint16_t *)&asic_num_total,true);
  total_rate = 0.0;
  freq_sum_1[0] = s_total_rate_00079590[0];
  freq_sum_1[1] = s_total_rate_00079590[1];
  freq_sum_1[2] = s_total_rate_00079590[2];
  freq_sum_1[3] = s_total_rate_00079590[3];
  freq_sum_1[4] = s_total_rate_00079590[4];
  freq_sum_1[5] = s_total_rate_00079590[5];
  freq_sum_1[6] = s_total_rate_00079590[6];
  freq_sum_1[7] = s_total_rate_00079590[7];
  freq_sum_1._8_3_ = (undefined3)ram0x00079598;
  for (i = 0; i < 0x10; i = i + 1) {
    if ((dev->chain_exist[i] == 1) && (displayed_rate[i][0] != '\0')) {
      dVar6 = atof(displayed_rate[i]);
      total_rate = dVar6 + total_rate;
    }
  }
  total_rate = (double)(longlong)(int)(longlong)(total_rate * DAT_00051d90) / DAT_00051d90;
  root = api_add_mhs(paVar3,freq_sum_1,&total_rate,true);
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
             (double)(longlong)(int)(longlong)((dev_sum_freq_3 / DAT_000524c0) * DAT_000524c8) /
             DAT_000524c8;
        root = api_add_mhs(root,freq_sum_1,&dev_sum_freq_3,true);
      }
      else {
        dev_sum_freq_3 =
             (double)(longlong)(int)(longlong)((dev_sum_freq_3 / DAT_000524c0) * DAT_000524c8) /
             DAT_000524c8;
        root = api_add_mhs(root,freq_sum_1,&dev_sum_freq_3,true);
      }
    }
    else {
      dev_sum_freq_3 =
           (double)(longlong)(int)(longlong)((dev_sum_freq_3 / DAT_000524c0) * DAT_000524c8) /
           DAT_000524c8;
      root = api_add_mhs(root,freq_sum_1,&dev_sum_freq_3,true);
    }
  }
  paVar3 = api_add_int(root,"temp_max",dev->temp_top1,true);
  dVar6 = total_diff_accepted + total_diff_rejected + total_diff_stale;
  total_diff1 = __aeabi_d2lz(SUB84(dVar6,0),(int)((ulonglong)dVar6 >> 0x20));
  dev_hwp = DAT_000524d0;
  if (total_diff1 + hw_errors != 0) {
    lVar1 = (longlong)hw_errors;
    dVar6 = (double)__aeabi_l2d((int)(total_diff1 + hw_errors),
                                (int)((ulonglong)(total_diff1 + hw_errors) >> 0x20));
    dev_hwp = (double)lVar1 / dVar6;
  }
  paVar3 = api_add_percent(paVar3,"Device Hardware%",&dev_hwp,true);
  root = api_add_int(paVar3,"no_matching_work",&hw_errors,true);
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
      tmp[11] = '\0';
      tmp[12] = '\0';
      tmp[13] = '\0';
      tmp[14] = '\0';
      tmp[15] = '\0';
      tmp[16] = '\0';
      tmp[17] = '\0';
      tmp[18] = '\0';
      tmp[19] = '\0';
      sprintf(chain_xtime,"chain_xtime%d",i + 1);
      bVar5 = x_time[i][0] != 0;
      if (bVar5) {
        sprintf(tmp,"X%d=%d",0,x_time[i][0]);
        strcat(freq_sum_1,tmp);
      }
      first = !bVar5;
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
      sVar4 = strlen(freq_sum_1);
      *(undefined2 *)(freq_sum_1 + sVar4) = DAT_00079650;
      root = api_add_string(root,chain_xtime,freq_sum_1,copy_data);
    }
  }
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      sprintf(chain_offside,"chain_offside_%d",i + 1);
      sprintf(tmp_1,"%d",temp_offside[i]);
      root = api_add_string(root,chain_offside,tmp_1,copy_data);
    }
  }
  for (i = 0; i < 0x10; i = i + 1) {
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
      root = api_add_string(root,chain_opencore,tmp_2,copy_data);
    }
  }
  for (i = 0; i < 0x10; i = i + 1) {
  }
  freq_sum_1[0] = s_miner_version_00079680[0];
  freq_sum_1[1] = s_miner_version_00079680[1];
  freq_sum_1[2] = s_miner_version_00079680[2];
  freq_sum_1[3] = s_miner_version_00079680[3];
  freq_sum_1[4] = s_miner_version_00079680[4];
  freq_sum_1[5] = s_miner_version_00079680[5];
  freq_sum_1[6] = s_miner_version_00079680[6];
  freq_sum_1[7] = s_miner_version_00079680[7];
  freq_sum_1[8] = s_miner_version_00079680[8];
  freq_sum_1[9] = s_miner_version_00079680[9];
  freq_sum_1[10] = s_miner_version_00079680[10];
  freq_sum_1[11] = s_miner_version_00079680[11];
  freq_sum_1[12] = (char)(short)ram0x0007968c;
  freq_sum_1[13] = (char)((ushort)(short)ram0x0007968c >> 8);
  paVar3 = api_add_string(root,freq_sum_1,g_miner_version,copy_data);
  freq_sum_1[0] = s_miner_id_00079690[0];
  freq_sum_1[1] = s_miner_id_00079690[1];
  freq_sum_1[2] = s_miner_id_00079690[2];
  freq_sum_1[3] = s_miner_id_00079690[3];
  freq_sum_1[4] = s_miner_id_00079690[4];
  freq_sum_1[5] = s_miner_id_00079690[5];
  freq_sum_1[6] = s_miner_id_00079690[6];
  freq_sum_1[7] = s_miner_id_00079690[7];
  freq_sum_1[8] = (char)ram0x00079698;
  paVar3 = api_add_string(paVar3,freq_sum_1,FPGA_ID_str,copy_data);
  return paVar3;
}

