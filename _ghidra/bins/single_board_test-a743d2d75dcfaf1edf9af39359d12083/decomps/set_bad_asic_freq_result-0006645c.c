
int32_t set_bad_asic_freq_result(bad_asic_list *bad_asic_list)

{
  int iVar1;
  int32_t iVar2;
  bad_asic_list *bad_asic_list_local;
  char time_stamp [48];
  char tmp1 [2048];
  uint8_t bad_asic_index;
  
  if (bad_asic_list == (bad_asic_list *)0x0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: bad_asic_cfg_res is null\n","set_bad_asic_freq_result");
    builtin_strncpy(tmp1,"bad_asic_cfg_res is null",0x18);
    tmp1[0x18] = '\0';
    log_to_file(tmp1,time_stamp);
    iVar2 = -1;
  }
  else {
    memset(&gbad_asic_cfg_freq,0,0x10);
    gbad_asic_cfg_freq.bad_asic_num = bad_asic_list->bad_asic_num;
    iVar1 = get_freq_comp((Local_Config_Information->Test_Info).Test_Standard.Test_Loop
                          [gPattern_test_counter].Frequence);
    gbad_asic_cfg_freq.freq = iVar1 - 0x14;
    memcpy(gbad_asic_cfg_freq.asic_id,bad_asic_list->asic_list,(uint)bad_asic_list->bad_asic_num);
    iVar2 = 0;
  }
  return iVar2;
}

