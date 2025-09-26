
int32_t parse_bin_file_to_pattern_ex
                  (char *asic_pattern_file,uint32_t small_core_num,uint32_t pattern_num,work *work)

{
  int iVar1;
  FILE *__stream;
  uint16_t extraout_r1;
  int32_t iVar2;
  work *work_local;
  uint32_t pattern_num_local;
  uint32_t small_core_num_local;
  char *asic_pattern_file_local;
  char time_stamp [48];
  char tmp1 [2048];
  test_pattern *which_pattern;
  FILE *asic_pattern_file_handle;
  work *small_core_works;
  uint32_t pattern_index;
  uint32_t core_index;
  
  if (asic_pattern_file == (char *)0x0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: pattern file is NULL\n","parse_bin_file_to_pattern_ex");
    builtin_strncpy(tmp1,"pattern file is NULL",0x14);
    tmp1._20_4_ = tmp1._20_4_ & 0xffffff00;
    log_to_file(tmp1,time_stamp);
    iVar2 = -1;
  }
  else if (*asic_pattern_file == '\0') {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: pattern file name is empty\n","parse_bin_file_to_pattern_ex");
    builtin_strncpy(tmp1,"pattern file name is emp",0x18);
    tmp1[0x18] = 't';
    tmp1[0x19] = 'y';
    tmp1[0x1a] = '\0';
    log_to_file(tmp1,time_stamp);
    iVar2 = -2;
  }
  else {
    iVar1 = access(asic_pattern_file,0);
    if (iVar1 == 0) {
      __stream = fopen(asic_pattern_file,"rb");
      if (__stream == (FILE *)0x0) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Open pattern file: %s failed !!!\n","parse_bin_file_to_pattern_ex",
               asic_pattern_file);
        snprintf(tmp1,0x800,"Open pattern file: %s failed !!!",asic_pattern_file);
        log_to_file(tmp1,time_stamp);
        iVar2 = -4;
      }
      else {
        for (core_index = 0; core_index < small_core_num; core_index = core_index + 1) {
          for (pattern_index = 0; pattern_index < pattern_num; pattern_index = pattern_index + 1) {
            fread(&work[pattern_num * core_index + pattern_index].pattern,1,0x30,__stream);
            __aeabi_uidivmod(pattern_index,
                             (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number);
            work[pattern_num * core_index + pattern_index].id = extraout_r1;
          }
          skip_rows((FILE *)__stream,8 - pattern_num);
        }
        iVar2 = 0;
      }
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: pattern file: %s don\'t exist!!!\n","parse_bin_file_to_pattern_ex",
             asic_pattern_file);
      snprintf(tmp1,0x800,"pattern file: %s don\'t exist!!!",asic_pattern_file);
      log_to_file(tmp1,time_stamp);
      iVar2 = -3;
    }
  }
  return iVar2;
}

