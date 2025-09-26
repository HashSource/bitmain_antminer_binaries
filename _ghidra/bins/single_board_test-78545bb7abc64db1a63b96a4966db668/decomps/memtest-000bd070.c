
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void memtest(void)

{
  work_new *pwVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  char time_stamp [48];
  char tmp1 [256];
  int work_count_target;
  int asic_1;
  int asic;
  
  uVar2 = (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number;
  uVar3 = (Local_Config_Information->Hash_Board).Small_Core_Num;
  for (asic = 0; (uint)asic < (Local_Config_Information->Hash_Board).Asic_Num; asic = asic + 1) {
    pwVar1 = (work_new *)calloc(0x10,uVar3 * uVar2);
    pattern_info_new.works[asic] = pwVar1;
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : calloc ok.\n","memtest");
  builtin_strncpy(tmp1,"calloc o",8);
  tmp1[8] = 'k';
  tmp1[9] = '.';
  tmp1[10] = '\0';
  log_to_file(tmp1,time_stamp);
  for (asic_1 = 0; (uint)asic_1 < (Local_Config_Information->Hash_Board).Asic_Num;
      asic_1 = asic_1 + 1) {
    free(pattern_info_new.works[asic_1]);
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : memtest ok.\n","memtest");
  builtin_strncpy(tmp1,"memtest ok.",0xc);
  log_to_file(tmp1,time_stamp);
  return;
}

