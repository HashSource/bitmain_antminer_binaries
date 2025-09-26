
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void fake_more_levels(void)

{
  uint32_t uVar1;
  double dVar2;
  char time_stamp [48];
  char tmp1 [256];
  int vol;
  int index;
  int i;
  
  gTest_loop = 0xd;
  uVar1 = (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[0].Voltage;
  for (i = 0xc; -1 < i; i = i + -1) {
    (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[i].Level = i;
    (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[i].Voltage = uVar1;
    (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[i].Pre_Open_Core_Voltage = 0x5dc;
    dVar2 = 485.0 - (double)(longlong)i * 6.25;
    (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[i].Frequence =
         (uint)(0.0 < dVar2) * (int)(longlong)dVar2;
  }
  for (index = 0; (uint)index < gTest_loop; index = index + 1) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Test_Loop[%d]->Level : %d\n","fake_more_levels",index,
           (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[index].Level);
    snprintf(tmp1,0x100,"Test_Loop[%d]->Level : %d",index,
             (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[index].Level);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Test_Loop[%d]->Pre_Open_Core_Voltage : %d\n","fake_more_levels",index,
           (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[index].
           Pre_Open_Core_Voltage);
    snprintf(tmp1,0x100,"Test_Loop[%d]->Pre_Open_Core_Voltage : %d",index,
             (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[index].
             Pre_Open_Core_Voltage);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Test_Loop[%d]->Voltage : %d\n","fake_more_levels",index,
           (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[index].Voltage);
    snprintf(tmp1,0x100,"Test_Loop[%d]->Voltage : %d",index,
             (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[index].Voltage);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Test_Loop[%d]->Frequence : %d\n","fake_more_levels",index,
           (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[index].Frequence);
    snprintf(tmp1,0x100,"Test_Loop[%d]->Frequence : %d",index,
             (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[index].Frequence);
    log_to_file(tmp1,time_stamp);
  }
  return;
}

