
void PreparePICandVoltage(void)

{
  char cVar1;
  int iVar2;
  undefined4 local_170;
  undefined auStack_16c [4];
  undefined auStack_168 [4];
  int local_164;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined2 local_150;
  undefined4 local_14c;
  uint local_148;
  uint local_144;
  uint local_140;
  undefined auStack_13c [64];
  undefined auStack_fc [128];
  FILE *local_7c;
  FILE *local_78;
  FILE *local_74;
  FILE *local_70;
  FILE *local_6c;
  FILE *local_68;
  FILE *local_64;
  undefined4 local_60;
  FILE *local_5c;
  undefined4 local_58;
  undefined4 local_54;
  FILE *local_50;
  FILE *local_4c;
  FILE *local_48;
  FILE *local_44;
  FILE *local_40;
  FILE *local_3c;
  FILE *local_38;
  FILE *local_34;
  FILE *local_30;
  FILE *local_2c;
  byte local_26;
  byte local_25;
  int local_24;
  int local_20;
  uint local_1c;
  
  local_24 = 0;
  memset(auStack_fc,0,0x80);
  memset(auStack_13c,0,0x40);
  local_14c = 0;
  local_148 = 0;
  local_144 = 0;
  local_140 = 0;
  local_160 = 0;
  local_15c = 0;
  local_158 = 0;
  local_154 = 0;
  local_150 = 0;
  local_26 = 0;
  start_pic_heart = 0;
  pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
  puts("clement2 init_fpga");
  reset_fpga();
  pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
  for (local_1c = 0; (int)local_1c < 0x10; local_1c = local_1c + 1) {
    *(undefined4 *)(cgpu + (local_1c + 0x9c638) * 4) = 0;
  }
  puts("clement check_chain");
  check_chain();
  set_reset_allhashboard(1);
  for (local_1c = 0; (int)local_1c < 0x10; local_1c = local_1c + 1) {
    *(undefined4 *)(disabled_cores_num + local_1c * 4) = 0;
    if ((*(int *)(cgpu + (local_1c + 0x9c638) * 4) != 0) && (testDone[local_1c] == '\0')) {
      reset_iic_pic(local_1c & 0xff);
      usleep(500000);
      jump_to_app_CheckAndRestorePIC(local_1c);
    }
  }
  for (local_1c = 0; (int)local_1c < 0x10; local_1c = local_1c + 1) {
    if ((*(int *)(cgpu + (local_1c + 0x9c638) * 4) != 0) && (testDone[local_1c] == '\0')) {
      read_freq_badcores(local_1c & 0xff,chain_pic_buf + local_1c * 0x80);
      if (3 < log_level) {
        local_2c = fopen(log_file,"a+");
        if (local_2c != (FILE *)0x0) {
          fprintf(local_2c,"%s:%d: Chain[%d] read_freq_badcores : ","main.c",0x2265,local_1c);
        }
        fclose(local_2c);
      }
      for (local_20 = 0; local_20 < 0x80; local_20 = local_20 + 1) {
        if (3 < log_level) {
          local_30 = fopen(log_file,"a+");
          if (local_30 != (FILE *)0x0) {
            fprintf(local_30,"0x%02x ",(uint)(byte)chain_pic_buf[local_20 + local_1c * 0x80]);
          }
          fclose(local_30);
        }
      }
      if (3 < log_level) {
        local_34 = fopen(log_file,"a+");
        if (local_34 != (FILE *)0x0) {
          fputc(10,local_34);
        }
        fclose(local_34);
      }
      read_disabled_cores(local_1c & 0xff,&local_14c);
      if (3 < log_level) {
        local_38 = fopen(log_file,"a+");
        if (local_38 != (FILE *)0x0) {
          fprintf(local_38,
                  "%s:%d: chain[%d]: [%d:%d] [%d:%d] [%d:%d] [%d:%d] [%d:%d] [%d:%d] [%d:%d] [%d:%d]\n"
                  ,"main.c",0x2271,local_1c,local_14c & 0xff,local_14c >> 8 & 0xff,
                  local_14c >> 0x10 & 0xff,local_14c >> 0x18,local_148 & 0xff,local_148 >> 8 & 0xff,
                  local_148 >> 0x10 & 0xff,local_148 >> 0x18,local_144 & 0xff,local_144 >> 8 & 0xff,
                  local_144 >> 0x10 & 0xff,local_144 >> 0x18,local_140 & 0xff,local_140 >> 8 & 0xff,
                  local_140 >> 0x10 & 0xff,local_140 >> 0x18);
        }
        fclose(local_38);
      }
      if (3 < log_level) {
        local_3c = fopen(log_file,"a+");
        if (local_3c != (FILE *)0x0) {
          fprintf(local_3c,
                  "%s:%d: chain[%d]: [%d:%d] [%d:%d] [%d:%d] [%d:%d] [%d:%d] [%d:%d] [%d:%d] [%d:%d]\n"
                  ,"main.c",0x2284,local_1c,local_14c & 0xff,local_14c >> 8 & 0xff,
                  local_14c >> 0x10 & 0xff,local_14c >> 0x18,local_148 & 0xff,local_148 >> 8 & 0xff,
                  local_148 >> 0x10 & 0xff,local_148 >> 0x18,local_144 & 0xff,local_144 >> 8 & 0xff,
                  local_144 >> 0x10 & 0xff,local_144 >> 0x18,local_140 & 0xff,local_140 >> 8 & 0xff,
                  local_140 >> 0x10 & 0xff,local_140 >> 0x18);
        }
        fclose(local_3c);
      }
      if (((local_14c & 0xff) == 0x2c) && (local_14c._1_1_ == 'e')) {
        for (local_20 = 1; local_20 < 8; local_20 = local_20 + 1) {
          if ((*(byte *)((int)&local_14c + local_20 * 2) < 0x54) &&
             (*(byte *)((int)&local_14c + local_20 * 2 + 1) < 0x72)) {
            disabled_cores_pos[(*(int *)(disabled_cores_num + local_1c * 4) + local_1c * 8) * 2] =
                 *(undefined *)((int)&local_14c + local_20 * 2);
            disabled_cores_pos[(*(int *)(disabled_cores_num + local_1c * 4) + local_1c * 8) * 2 + 1]
                 = *(undefined *)((int)&local_14c + local_20 * 2 + 1);
            if (3 < log_level) {
              local_40 = fopen(log_file,"a+");
              if (local_40 != (FILE *)0x0) {
                fprintf(local_40,"%s:%d: Chain[%d] disabled chip[%d] core[%d] \n","main.c",0x2291,
                        local_1c,(uint)*(byte *)((int)&local_14c + local_20 * 2),
                        (uint)*(byte *)((int)&local_14c + local_20 * 2 + 1));
              }
              fclose(local_40);
            }
            *(int *)(disabled_cores_num + local_1c * 4) =
                 *(int *)(disabled_cores_num + local_1c * 4) + 1;
          }
        }
      }
      iVar2 = getChainPICMagicNumber(local_1c);
      if (iVar2 == 0x7d) {
        if (conf._144_4_ == 0) {
          system(
                "cp /www/pages/cgi-bin/minerConfiguration2.cgi /www/pages/cgi-bin/minerConfiguration.cgi -f"
                );
          system("sync");
          if (3 < log_level) {
            local_44 = fopen(log_file,"a+");
            if (local_44 != (FILE *)0x0) {
              fprintf(local_44,"%s:%d: has freq in PIC, will disable freq setting.\n","main.c",
                      0x22db);
            }
            fclose(local_44);
          }
          for (local_24 = 0; local_24 < 0x54; local_24 = local_24 + 1) {
            *(uint *)(last_success_freq + (local_24 + local_1c * 0x100) * 4) =
                 (uint)*(byte *)(local_1c * 0x80 + local_24 + 0x1a3fbbe);
          }
          testDone[local_1c] = 1;
          search_over[local_1c] = 1;
          if (3 < log_level) {
            local_48 = fopen(log_file,"a+");
            if (local_48 != (FILE *)0x0) {
              fprintf(local_48,"%s:%d: chain[%d] has freq in PIC and will jump over...\n","main.c",
                      0x2325,local_1c);
            }
            fclose(local_48);
          }
          if (3 < log_level) {
            local_4c = fopen(log_file,"a+");
            if (local_4c != (FILE *)0x0) {
              fprintf(local_4c,"%s:%d: Chain[%d] has core num in PIC\n","main.c",8999,local_1c);
            }
            fclose(local_4c);
          }
          for (local_20 = 0; local_20 < 0x54; local_20 = local_20 + 1) {
            *(undefined4 *)(chain_badcore_num + (local_20 + local_1c * 0x100) * 4) = 0;
          }
        }
        else if (3 < log_level) {
          local_50 = fopen(log_file,"a+");
          if (local_50 != (FILE *)0x0) {
            fprintf(local_50,"%s:%d: Start search freq on chain[%d]...\n","main.c",0x22d5,local_1c);
          }
          fclose(local_50);
        }
      }
      else if (conf._144_4_ == 0) {
        local_54 = GetDefaultFreq();
        local_58 = get_pll_index(local_54);
        if (3 < log_level) {
          local_5c = fopen(log_file,"a+");
          if (local_5c != (FILE *)0x0) {
            fprintf(local_5c,
                    "%s:%d: chain[%d] has no freq in PIC! Will use default freq=%d and jump over...\n"
                    ,"main.c",0x236c,local_1c,local_54);
          }
          fclose(local_5c);
        }
        for (local_24 = 0; local_24 < 0x54; local_24 = local_24 + 1) {
          *(undefined4 *)(last_success_freq + (local_24 + local_1c * 0x100) * 4) = local_58;
        }
        testDone[local_1c] = 1;
        search_over[local_1c] = 1;
        IsSomeBoardHasNoFreq = 1;
      }
    }
  }
  for (local_1c = 0; (int)local_1c < 0x10; local_1c = local_1c + 1) {
    if (*(int *)(cgpu + (local_1c + 0x9c638) * 4) != 0) {
      getPICChainIndexOffset(local_1c,&local_164,auStack_168);
      iVar2 = is_S9_Hydro();
      if (iVar2 == 0) {
        local_25 = get_pic_voltage(local_1c & 0xff);
      }
      else {
        local_25 = chain_pic_buf[local_164 * 0x80 + 1] * '\x05';
      }
      local_60 = getVolValueFromPICvoltage(local_25);
      if (3 < log_level) {
        local_64 = fopen(log_file,"a+");
        if (local_64 != (FILE *)0x0) {
          fprintf(local_64,"%s:%d: get PIC voltage=%d on chain[%d], value=%d\n","main.c",0x238f,
                  (uint)local_25,local_1c,local_60);
        }
        fclose(local_64);
      }
    }
  }
  local_20 = 0;
  for (local_1c = 0; (int)local_1c < 0x10; local_1c = local_1c + 1) {
    if ((*(int *)(cgpu + (local_1c + 0x9c638) * 4) != 0) && (testDone[local_1c] == '\0')) {
      if (*(int *)(chain_vol_value + local_1c * 4) == 0) {
        getBoardTestVoltageAndFreq(0,&local_170,auStack_16c);
        *(undefined4 *)(chain_vol_value + local_1c * 4) = local_170;
      }
      *(undefined4 *)(chain_vol_added + local_1c * 4) = 0;
      local_25 = getPICvoltageFromValue(*(undefined4 *)(chain_vol_value + local_1c * 4));
      if (3 < log_level) {
        local_68 = fopen(log_file,"a+");
        if (local_68 != (FILE *)0x0) {
          fprintf(local_68,"%s:%d: set voltage=%d search freq on chain[%d]\n","main.c",0x23e4,
                  *(undefined4 *)(chain_vol_value + local_1c * 4),local_1c);
        }
        fclose(local_68);
      }
      if (3 < log_level) {
        local_6c = fopen(log_file,"a+");
        if (local_6c != (FILE *)0x0) {
          fprintf(local_6c,"%s:%d: now set pic voltage=%d on chain[%d]\n","main.c",0x23e5,
                  (uint)local_25,local_1c);
        }
        fclose(local_6c);
      }
      set_pic_voltage(local_1c & 0xff,local_25);
      local_20 = local_20 + 1;
    }
  }
  cVar1 = is_S9_plus();
  if (cVar1 != '\x01') {
    for (local_1c = 0; (int)local_1c < 0x10; local_1c = local_1c + 1) {
      if (((*(int *)(cgpu + (local_1c + 0x9c638) * 4) != 0) && (testDone[local_1c] == '\0')) &&
         (enable_pic_dac(local_1c & 0xff), 3 < log_level)) {
        local_70 = fopen(log_file,"a+");
        if (local_70 != (FILE *)0x0) {
          fprintf(local_70,"%s:%d: enable_pic_dac on chain[%d]\n","main.c",0x23f9,local_1c);
        }
        fclose(local_70);
      }
    }
    sleep(1);
  }
  start_pic_heart = 1;
  send_pic_heart_once();
  set_reset_allhashboard(0);
  for (local_1c = 0; (int)local_1c < 0x10; local_1c = local_1c + 1) {
    if (*(int *)(cgpu + (local_1c + 0x9c638) * 4) != 0) {
      get_temperature_offset_value(local_1c & 0xff,&local_160);
      if (3 < log_level) {
        local_74 = fopen(log_file,"a+");
        if (local_74 != (FILE *)0x0) {
          fprintf(local_74,"%s:%d: chain[%d] temp offset record: %d,%d,%d,%d,%d,%d,%d,%d\n","main.c"
                  ,0x2435,local_1c,(int)(char)local_160,(int)local_160._1_1_,(int)local_160._2_1_,
                  (int)local_160._3_1_,(int)(char)local_15c,(int)local_15c._1_1_,
                  (int)(char)local_15c._2_1_,(int)local_15c._3_1_);
        }
        fclose(local_74);
      }
      local_26 = local_15c._2_1_ & 0x1f;
      if (local_26 == 7) {
        *(undefined4 *)(DEVICEADDR + local_1c * 4) = 0x9c0000;
      }
      else if ((local_26 == 9) || (local_26 == 6)) {
        *(undefined4 *)(DEVICEADDR + local_1c * 4) = 0x9a0000;
      }
      else {
        *(undefined4 *)(DEVICEADDR + local_1c * 4) = 0x980000;
      }
      if (3 < log_level) {
        local_78 = fopen(log_file,"a+");
        if (local_78 != (FILE *)0x0) {
          fprintf(local_78,"%s:%d: chain[%d] temp chip I2C addr=0x%02x\n","main.c",0x2446,local_1c,
                  *(uint *)(DEVICEADDR + local_1c * 4) >> 0x10);
        }
        fclose(local_78);
      }
      if ((((local_26 == 3) || (local_26 == 4)) ||
          ((local_26 == 5 || ((local_26 == 6 || (local_26 == 7)))))) &&
         (temp_chip_no_middle[local_1c] = 1, 3 < log_level)) {
        local_7c = fopen(log_file,"a+");
        if (local_7c != (FILE *)0x0) {
          fprintf(local_7c,"%s:%d: chain[%d] has no middle temp, use special fix mode.\n","main.c",
                  0x244c,local_1c);
        }
        fclose(local_7c);
      }
      if ((char)local_160 < '\x01') {
        *(undefined4 *)(temp_chip_index + local_1c * 4) = 4;
        chip_temp_offset[local_1c] = 0x85;
      }
      else {
        *(int *)(temp_chip_index + local_1c * 4) = (int)(char)local_160;
        chip_temp_offset[local_1c] = local_160._1_1_;
      }
    }
  }
  return;
}

