
/* WARNING: Unknown calling convention */

int Single_Board_PT1_Plus_Test(void)

{
  int iVar1;
  char time_stamp [48];
  char tmp1 [256];
  
  if ((Local_Config_Information->Test_Info).Test_Method.Software_Pattern == false) {
    lcd_clear_result();
    lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
    lcd_show(1,"Do not support");
    lcd_show(2,"Test Mode");
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Do not support Test Mode\n","Single_Board_PT1_Plus_Test");
    builtin_strncpy(tmp1,"Do not support Test Mode",0x18);
    tmp1[0x18] = '\0';
    log_to_file(tmp1,time_stamp);
    iVar1 = 0xc;
  }
  else {
    iVar1 = Single_Board_PT1_Plus_Software_Pattern_Test();
  }
  return iVar1;
}

