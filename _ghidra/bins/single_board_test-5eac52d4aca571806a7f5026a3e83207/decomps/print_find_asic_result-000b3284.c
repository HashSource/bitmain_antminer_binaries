
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void print_find_asic_result(void)

{
  int extraout_r1;
  undefined *puVar1;
  int i;
  
  for (i = 1; (uint)i <= (Local_Config_Information->Hash_Board).Asic_Num; i = i + 1) {
    if (gHistory_Result[gPattern_test_counter].ok_asic_list[i + -1] == false) {
      puVar1 = &DAT_001f5488;
    }
    else {
      puVar1 = &DAT_001f5484;
    }
    printf("[%02d] %s   ",i,puVar1);
    __aeabi_uidivmod(i,(Local_Config_Information->Hash_Board).Asic_Num_Per_Voltage_Domain);
    if (extraout_r1 == 0) {
      putchar(10);
    }
  }
  putchar(10);
  return;
}

