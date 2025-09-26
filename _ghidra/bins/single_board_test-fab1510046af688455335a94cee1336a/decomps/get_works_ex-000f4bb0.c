
_Bool get_works_ex(char *asic_type,uint32_t asic_num,uint32_t core_num,uint32_t pattern_num)

{
  int iVar1;
  work *pwVar2;
  int32_t iVar3;
  _Bool _Var4;
  uint32_t pattern_num_local;
  uint32_t core_num_local;
  uint32_t asic_num_local;
  char *asic_type_local;
  char time_stamp [48];
  char tmp1 [2048];
  char lcd_data [16];
  char pattern_file_path [100];
  char buf [50];
  char asic_pattern_file [128];
  int ret;
  uint32_t which_asic;
  
  memset(pattern_file_path,0,100);
  memset(pattern_file_path,0,100);
  iVar1 = strcmp((Local_Config_Information->Hash_Board).Asic_Type,"BM1398");
  if (((iVar1 == 0) ||
      (iVar1 = strcmp((Local_Config_Information->Hash_Board).Asic_Type,"BM1360"), iVar1 == 0)) ||
     (iVar1 = strcmp((Local_Config_Information->Hash_Board).Asic_Type,"BM1399"), iVar1 == 0)) {
    memcpy(pattern_file_path,"/mnt/card/BM1370-pattern/pattern_midautogen.bin",0x2f);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: pattern file path: %s\n","get_works_ex",pattern_file_path);
    snprintf(tmp1,0x800,"pattern file path: %s",pattern_file_path);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: asic_num = %d, core_num = %d, pattern_num = %d\n","get_works_ex",asic_num,core_num,
           pattern_num);
    snprintf(tmp1,0x800,"asic_num = %d, core_num = %d, pattern_num = %d",asic_num,core_num,
             pattern_num);
    log_to_file(tmp1,time_stamp);
    for (which_asic = 0; which_asic < asic_num; which_asic = which_asic + 1) {
      memset(asic_pattern_file,0,0x80);
      sprintf(asic_pattern_file,pattern_file_path,which_asic);
      pwVar2 = (work *)malloc(pattern_num * core_num * 0x34);
      pattern_info.works[which_asic] = pwVar2;
      if (pattern_info.works[which_asic] == (work *)0x0) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: malloc pattern buffer fail for asic %d\n","get_works_ex",which_asic);
        snprintf(tmp1,0x800,"malloc pattern buffer fail for asic %d",which_asic);
        log_to_file(tmp1,time_stamp);
        return false;
      }
      memset(pattern_info.works[which_asic],0,pattern_num * core_num * 0x34);
      iVar3 = parse_bin_file_to_pattern_ex
                        (asic_pattern_file,core_num,pattern_num,pattern_info.works[which_asic]);
      if (iVar3 != 0) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: get test pattern fail for asic %d\n","get_works_ex",which_asic);
        snprintf(tmp1,0x800,"get test pattern fail for asic %d",which_asic);
        log_to_file(tmp1,time_stamp);
        return false;
      }
    }
    _Var4 = true;
  }
  else {
    memset(lcd_data,0,0x10);
    lcd_clear_result();
    lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
    lcd_show(1,"Don\'t support");
    strcpy(lcd_data,(Local_Config_Information->Hash_Board).Asic_Type);
    lcd_show(2,lcd_data);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Don\'t support %s asic\n","get_works_ex",
           (Local_Config_Information->Hash_Board).Asic_Type);
    snprintf(tmp1,0x800,"Don\'t support %s asic",(Local_Config_Information->Hash_Board).Asic_Type);
    log_to_file(tmp1,time_stamp);
    _Var4 = false;
  }
  return _Var4;
}

