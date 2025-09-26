
_Bool prepare_eeprom_data_region3(uint8_t *eeprom_data,size_t *len_p,size_t *offset_p)

{
  uint32_t uVar1;
  int32_t iVar2;
  int iVar3;
  byte bVar4;
  _Bool _Var5;
  size_t *offset_p_local;
  size_t *len_p_local;
  uint8_t *eeprom_data_local;
  char time_stamp [48];
  char tmp1 [2048];
  size_t len;
  uint8_t freq_level [128];
  char buf [256];
  bad_asic_cfg_freq bad_asic_freq_cfg;
  uint8_t level;
  uint32_t i;
  int32_t ret;
  uint32_t freq;
  uint32_t hashrate;
  uint8_t bad_asic_count;
  uint32_t asic_index;
  
  bad_asic_count = '\0';
  bad_asic_freq_cfg.freq_cfg_flag = '\0';
  bad_asic_freq_cfg.bad_asic_num = '\0';
  bad_asic_freq_cfg._2_2_ = 0;
  bad_asic_freq_cfg.freq = 0;
  bad_asic_freq_cfg.asic_id[0] = '\0';
  bad_asic_freq_cfg.asic_id[1] = '\0';
  bad_asic_freq_cfg.asic_id[2] = '\0';
  bad_asic_freq_cfg.asic_id[3] = '\0';
  bad_asic_freq_cfg.asic_id[4] = '\0';
  bad_asic_freq_cfg._13_3_ = 0;
  hashrate = 0;
  memset(freq_level,0,0x80);
  len = 0x80;
  if (ctx == (eeprom_data_format_t *)0x0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: edf ctx should not be NULL\n\n","prepare_eeprom_data_region3");
    builtin_strncpy(tmp1,"edf ctx should not be NULL\n",0x1c);
    log_to_file(tmp1,time_stamp);
    _Var5 = false;
  }
  else {
    iVar2 = get_bad_asic_freq_result(&bad_asic_freq_cfg);
    if (iVar2 == 0) {
      if (bad_asic_freq_cfg.freq_cfg_flag == 0xa5) {
        (*ctx->sweep_result_set)(ctx,'\x01');
        (*ctx->sweep_freq_step_set)(ctx,'\x05');
        (*ctx->sweep_freq_base_set)(ctx,(uint16_t)bad_asic_freq_cfg.freq);
        for (asic_index = 0; uVar1 = bad_asic_freq_cfg.freq,
            asic_index < (Local_Config_Information->Hash_Board).Asic_Num;
            asic_index = asic_index + 1) {
          if ((bad_asic_count < bad_asic_freq_cfg.bad_asic_num) &&
             (bad_asic_freq_cfg.asic_id[bad_asic_count] == asic_index)) {
            iVar3 = get_freq_comp(0);
            freq = uVar1 - iVar3;
            bad_asic_count = bad_asic_count + '\x01';
          }
          else {
            freq = (Local_Config_Information->Test_Info).Test_Standard.Test_Loop
                   [gPattern_test_counter].Frequence;
          }
          bVar4 = (byte)((freq - bad_asic_freq_cfg.freq) / 5);
          if ((asic_index & 1) == 0) {
            bVar4 = bVar4 & 0xf;
          }
          else {
            bVar4 = bVar4 << 4;
          }
          freq_level[asic_index >> 1] = bVar4 | freq_level[asic_index >> 1];
          hashrate = freq * (Local_Config_Information->Hash_Board).Small_Core_Num + hashrate;
        }
        printf("len = %d\n",len);
        (*ctx->sweep_level_set)(ctx,freq_level,&len);
        printf("hashrate = %d\n",hashrate / 100000);
        (*ctx->sweep_hashrate_set)(ctx,(uint16_t)(hashrate / 100000));
      }
      (*ctx->region_3_encode)(ctx,(char *)eeprom_data,len_p,offset_p);
      (*ctx->dump_data)(ctx);
      _Var5 = true;
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: get_bad_asic_freq_result error\n\n","prepare_eeprom_data_region3");
      builtin_strncpy(tmp1,"get_bad_asic_freq_result error\n",0x20);
      log_to_file(tmp1,time_stamp);
      _Var5 = false;
    }
  }
  return _Var5;
}

