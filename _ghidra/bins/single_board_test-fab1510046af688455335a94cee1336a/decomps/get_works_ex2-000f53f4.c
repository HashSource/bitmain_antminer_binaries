
/* WARNING: Unknown calling convention */

_Bool get_works_ex2(void)

{
  work_new *pwVar1;
  int iVar2;
  uint uVar3;
  undefined1 uVar4;
  bool bVar5;
  char time_stamp [48];
  char tmp1 [2048];
  FILE *fp_super;
  FILE *fp_soft;
  uint32_t work_count_of_asic;
  uint32_t work_count_target;
  FILE *fp_auto;
  uint32_t super_work_count_target;
  uint32_t soft_work_count_target;
  int32_t ret;
  uint32_t soft_work_count_of_asic;
  uint32_t super_work_count_of_asic;
  uint32_t core;
  uint32_t asic;
  
  super_work_count_of_asic = 0;
  soft_work_count_of_asic = 0;
  ret = 1;
  if ((Local_Config_Information->Test_Info).Test_Method.Capture_Pattern != false) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: capture_pattern mode will generate patter file\n","get_works_ex2");
    builtin_strncpy(tmp1,"capture_pattern mode will generate patter fi",0x2c);
    tmp1[0x2c] = 'l';
    tmp1[0x2d] = 'e';
    tmp1[0x2e] = '\0';
    log_to_file(tmp1,time_stamp);
    return true;
  }
  if ((Local_Config_Information->Test_Info).Test_Method.Software_Pattern == false) {
    if ((Local_Config_Information->Test_Info).Test_Method.Super_Software_Pattern == false) {
      fp_auto = (FILE *)fopen("/mnt/card/BM1370-pattern/pattern_midautogen.bin","r");
      if (fp_auto == (FILE *)0x0) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Fail to open pattern file %s.\n\n","get_works_ex2",
               "/mnt/card/BM1370-pattern/pattern_midautogen.bin");
        snprintf(tmp1,0x800,"Fail to open pattern file %s.\n",
                 "/mnt/card/BM1370-pattern/pattern_midautogen.bin");
        log_to_file(tmp1,time_stamp);
        return false;
      }
      work_count_target =
           (Local_Config_Information->Hash_Board).Small_Core_Num_In_Big_Core *
           (Local_Config_Information->Hash_Board).Big_Core_Num *
           (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number;
      asic = 0;
      do {
        if ((Local_Config_Information->Hash_Board).Asic_Num <= asic) {
LAB_000f5a94:
          fclose((FILE *)fp_auto);
          bVar5 = ret != 0;
          if (bVar5) {
            ret = 1;
          }
          if (bVar5) {
            return (_Bool)(char)ret;
          }
          return false;
        }
        work_count_of_asic = 0;
        if (work_count_target != 0) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: No enough work, asic = %d, work_count = %d, work_count_target = %d.\n\n",
                 "get_works_ex2",asic,work_count_of_asic,work_count_target);
          snprintf(tmp1,0x800,
                   "No enough work, asic = %d, work_count = %d, work_count_target = %d.\n",asic,
                   work_count_of_asic,work_count_target);
          log_to_file(tmp1,time_stamp);
          ret = 0;
          goto LAB_000f5a94;
        }
        asic = asic + 1;
      } while( true );
    }
    fp_super = (FILE *)fopen("/mnt/card/BM1370-pattern/pattern_1midstate_super.bin","r");
    if (fp_super == (FILE *)0x0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Fail to open pattern file %s.\n\n","get_works_ex2",
             "/mnt/card/BM1370-pattern/pattern_1midstate_super.bin");
      snprintf(tmp1,0x800,"Fail to open pattern file %s.\n",
               "/mnt/card/BM1370-pattern/pattern_1midstate_super.bin");
      log_to_file(tmp1,time_stamp);
      fclose((FILE *)fp_soft);
      return false;
    }
    super_work_count_target = (Local_Config_Information->Hash_Board).Big_Core_Num;
    pattern_info.works[0] = (work *)calloc(0x34,super_work_count_target);
    if (pattern_info.works[0] != (work *)0x0) {
      for (core = 0; core < (Local_Config_Information->Hash_Board).Big_Core_Num; core = core + 1) {
        iVar2 = parse_bin_file_16midstate_super(&fp_super,0,core,1);
        super_work_count_of_asic = super_work_count_of_asic + iVar2;
      }
      if (super_work_count_of_asic < super_work_count_target) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: No enough work, work_count = %d, work_count_target = %d.\n\n","get_works_ex2",
               super_work_count_of_asic,super_work_count_target);
        snprintf(tmp1,0x800,"No enough work, work_count = %d, work_count_target = %d.\n",
                 super_work_count_of_asic,super_work_count_target);
        log_to_file(tmp1,time_stamp);
        ret = 0;
      }
      fclose((FILE *)fp_super);
      bVar5 = ret != 0;
      if (bVar5) {
        ret = 1;
      }
      if (bVar5) {
        return (_Bool)(char)ret;
      }
      return false;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: super malloc pattern buffer fail\n","get_works_ex2");
    builtin_strncpy(tmp1,"super malloc pattern buffer fail",0x20);
    tmp1._32_4_ = tmp1._32_4_ & 0xffffff00;
    log_to_file(tmp1,time_stamp);
    ret = 0;
  }
  else {
    fp_soft = (FILE *)fopen("/mnt/card/BM1370-pattern/pattern_16midstate.bin","r");
    if (fp_soft == (FILE *)0x0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Fail to open pattern file %s.\n\n","get_works_ex2",
             "/mnt/card/BM1370-pattern/pattern_16midstate.bin");
      snprintf(tmp1,0x800,"Fail to open pattern file %s.\n",
               "/mnt/card/BM1370-pattern/pattern_16midstate.bin");
      log_to_file(tmp1,time_stamp);
      return false;
    }
    soft_work_count_target =
         (Local_Config_Information->Hash_Board).Small_Core_Num_In_Big_Core *
         (Local_Config_Information->Hash_Board).Big_Core_Num *
         (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number;
    for (asic = 0; asic < (Local_Config_Information->Hash_Board).Asic_Num; asic = asic + 1) {
      soft_work_count_of_asic = 0;
      pwVar1 = (work_new *)calloc(0x10,soft_work_count_target);
      pattern_info_new.works[asic] = pwVar1;
      if (pattern_info_new.works[asic] == (work_new *)0x0) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: soft malloc pattern buffer fail for asic %d\n","get_works_ex2",asic);
        snprintf(tmp1,0x800,"soft malloc pattern buffer fail for asic %d",asic);
        log_to_file(tmp1,time_stamp);
        ret = 0;
        break;
      }
      for (core = 0;
          uVar3 = (Local_Config_Information->Hash_Board).Small_Core_Num_In_Big_Core *
                  (Local_Config_Information->Hash_Board).Big_Core_Num,
          core <= uVar3 && uVar3 - core != 0; core = core + 1) {
        iVar2 = parse_bin_file_16midstate_sf
                          (&fp_soft,asic,core,
                           (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number);
        soft_work_count_of_asic = soft_work_count_of_asic + iVar2;
      }
      if (soft_work_count_of_asic < soft_work_count_target) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: No enough work, asic = %d, work_count = %d, work_count_target = %d.\n\n",
               "get_works_ex2",asic,soft_work_count_of_asic,soft_work_count_target);
        snprintf(tmp1,0x800,"No enough work, asic = %d, work_count = %d, work_count_target = %d.\n",
                 asic,soft_work_count_of_asic,soft_work_count_target);
        log_to_file(tmp1,time_stamp);
        ret = 0;
        break;
      }
    }
  }
  fclose((FILE *)fp_soft);
  bVar5 = ret != 0;
  if (bVar5) {
    ret = 1;
  }
  uVar4 = (undefined1)ret;
  if (!bVar5) {
    uVar4 = 0;
  }
  return (_Bool)uVar4;
}

