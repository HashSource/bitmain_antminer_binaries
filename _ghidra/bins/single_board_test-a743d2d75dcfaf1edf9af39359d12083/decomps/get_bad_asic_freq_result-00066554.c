
int32_t get_bad_asic_freq_result(bad_asic_cfg_freq *bad_asic_freq_result)

{
  uint8_t uVar1;
  undefined2 uVar2;
  uint32_t uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int32_t iVar6;
  bad_asic_cfg_freq *bad_asic_freq_result_local;
  char time_stamp [48];
  char tmp1 [2048];
  
  uVar5 = gbad_asic_cfg_freq._12_4_;
  uVar4 = gbad_asic_cfg_freq.asic_id._0_4_;
  uVar3 = gbad_asic_cfg_freq.freq;
  if (bad_asic_freq_result == (bad_asic_cfg_freq *)0x0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: bad_asic_freq_result is null\n","get_bad_asic_freq_result");
    builtin_strncpy(tmp1,"bad_asic_freq_result is null",0x1c);
    tmp1[0x1c] = '\0';
    log_to_file(tmp1,time_stamp);
    iVar6 = -1;
  }
  else {
    uVar1 = gbad_asic_cfg_freq.bad_asic_num;
    uVar2 = gbad_asic_cfg_freq._2_2_;
    bad_asic_freq_result->freq_cfg_flag = gbad_asic_cfg_freq.freq_cfg_flag;
    bad_asic_freq_result->bad_asic_num = uVar1;
    *(undefined2 *)&bad_asic_freq_result->field_0x2 = uVar2;
    bad_asic_freq_result->freq = uVar3;
    *(undefined4 *)bad_asic_freq_result->asic_id = uVar4;
    *(undefined4 *)(bad_asic_freq_result->asic_id + 4) = uVar5;
    iVar6 = 0;
  }
  return iVar6;
}

