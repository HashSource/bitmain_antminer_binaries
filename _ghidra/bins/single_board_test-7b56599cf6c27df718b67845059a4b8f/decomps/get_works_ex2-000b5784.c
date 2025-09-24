
/* WARNING: Unknown calling convention */

_Bool get_works_ex2(void)

{
  work_new *pwVar1;
  int iVar2;
  uint uVar3;
  undefined1 uVar4;
  bool bVar5;
  char time_stamp [48];
  char tmp1 [256];
  FILE *fp;
  uint32_t work_count_target;
  int32_t ret;
  uint32_t work_count_of_asic;
  uint32_t core;
  uint32_t asic;
  char *pattern_file_path;
  
  ret = 1;
  if ((Local_Config_Information->Test_Info).Test_Method.Capture_Pattern == false) {
    if ((Local_Config_Information->Test_Info).Test_Method.Software_Pattern == false) {
      pattern_file_path = "/mnt/card/BM1368-pattern/pattern_midautogen.bin";
    }
    else {
      pattern_file_path = "/mnt/card/BM1368-pattern/pattern_16midstate.bin";
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : open file %s\n","get_works_ex2",pattern_file_path);
    snprintf(tmp1,0x100,"open file %s",pattern_file_path);
    log_to_file(tmp1,time_stamp);
    fp = (FILE *)fopen(pattern_file_path,"r");
    if (fp == (FILE *)0x0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Fail to open pattern file %s.\n\n","get_works_ex2",pattern_file_path);
      snprintf(tmp1,0x100,"Fail to open pattern file %s.\n",pattern_file_path);
      log_to_file(tmp1,time_stamp);
      uVar4 = 0;
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : open file succ\n","get_works_ex2");
      builtin_strncpy(tmp1,"open file su",0xc);
      tmp1[0xc] = 'c';
      tmp1[0xd] = 'c';
      tmp1[0xe] = '\0';
      log_to_file(tmp1,time_stamp);
      work_count_target =
           (Local_Config_Information->Hash_Board).Small_Core_Num_In_Big_Core *
           (Local_Config_Information->Hash_Board).Big_Core_Num *
           (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number;
      for (asic = 0; asic < (Local_Config_Information->Hash_Board).Asic_Num; asic = asic + 1) {
        work_count_of_asic = 0;
        pwVar1 = (work_new *)
                 calloc(0x10,(Local_Config_Information->Hash_Board).Small_Core_Num_In_Big_Core *
                             (Local_Config_Information->Hash_Board).Big_Core_Num *
                             (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number);
        pattern_info_new.works[asic] = pwVar1;
        for (core = 0;
            uVar3 = (Local_Config_Information->Hash_Board).Small_Core_Num_In_Big_Core *
                    (Local_Config_Information->Hash_Board).Big_Core_Num,
            core <= uVar3 && uVar3 - core != 0; core = core + 1) {
          if ((Local_Config_Information->Test_Info).Test_Method.Software_Pattern != false) {
            iVar2 = parse_bin_file_16midstate_sf
                              (&fp,asic,core,
                               (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number);
            work_count_of_asic = work_count_of_asic + iVar2;
          }
        }
        if (work_count_of_asic < work_count_target) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : No enough work, asic = %d, work_count = %d, work_count_target = %d.\n\n",
                 "get_works_ex2",asic,work_count_of_asic,work_count_target);
          snprintf(tmp1,0x100,
                   "No enough work, asic = %d, work_count = %d, work_count_target = %d.\n",asic,
                   work_count_of_asic,work_count_target);
          log_to_file(tmp1,time_stamp);
          ret = 0;
          break;
        }
      }
      fclose((FILE *)fp);
      fp = (FILE *)0x0;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : succ.\n","get_works_ex2");
      builtin_strncpy(tmp1,"succ",4);
      tmp1[4] = '.';
      tmp1[5] = '\0';
      log_to_file(tmp1,time_stamp);
      bVar5 = ret != 0;
      if (bVar5) {
        ret = 1;
      }
      uVar4 = (undefined1)ret;
      if (!bVar5) {
        uVar4 = 0;
      }
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : capture_pattern mode will generate patter file\n","get_works_ex2");
    builtin_strncpy(tmp1,"capture_pattern mode will generate patter fi",0x2c);
    tmp1[0x2c] = 'l';
    tmp1[0x2d] = 'e';
    tmp1[0x2e] = '\0';
    log_to_file(tmp1,time_stamp);
    uVar4 = 1;
  }
  return (_Bool)uVar4;
}

