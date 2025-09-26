
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void print_works(void)

{
  uint uVar1;
  work_new *pwVar2;
  int iVar3;
  char time_stamp [48];
  char tmp1 [256];
  work_new *work;
  work_new *works;
  uint32_t read_asic_num;
  uint32_t i;
  uint32_t which_pattern;
  uint32_t which_core;
  uint32_t which_asic;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s :  \n","print_works");
  tmp1[0] = ' ';
  tmp1[1] = '\0';
  log_to_file(tmp1,time_stamp);
  if ((Local_Config_Information->Test_Info).Test_Method.Super_Software_Pattern == false) {
    uVar1 = (Local_Config_Information->Hash_Board).Asic_Num;
  }
  else {
    uVar1 = 1;
  }
  for (which_asic = 0; which_asic < uVar1; which_asic = which_asic + 1) {
    pwVar2 = pattern_info_new.works[which_asic];
    for (which_core = 0; which_core < (Local_Config_Information->Hash_Board).Small_Core_Num;
        which_core = which_core + 1) {
      for (which_pattern = 0;
          which_pattern < (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number;
          which_pattern = which_pattern + 1) {
        iVar3 = which_pattern +
                which_core * (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number;
        printf("\n[ASIC %03d][CORE %03d][PATTERN %d]:\n",which_asic,which_core,which_pattern);
        printf("\nmidstate=0x");
        for (i = 0; i < 8; i = i + 1) {
          printf("%02x",(uint)pwVar2[iVar3].pattern.midstate[i]);
        }
        printf("\nnonce=0x%08x",pwVar2[iVar3].pattern.nonce);
        putchar(10);
      }
    }
  }
  return;
}

