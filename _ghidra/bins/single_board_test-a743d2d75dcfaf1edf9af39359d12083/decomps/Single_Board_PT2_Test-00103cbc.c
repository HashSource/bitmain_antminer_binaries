
/* WARNING: Unknown calling convention */

int Single_Board_PT2_Test(void)

{
  int iVar1;
  char time_stamp [48];
  char tmp1 [2048];
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s:  \n","Single_Board_PT2_Test");
  tmp1[0] = ' ';
  tmp1[1] = '\0';
  log_to_file(tmp1,time_stamp);
  if ((Local_Config_Information->Test_Info).Test_Method.Software_Pattern == false) {
    if ((Local_Config_Information->Test_Info).Test_Method.Super_Software_Pattern == false) {
      if ((Local_Config_Information->Test_Info).Test_Method.Hardware_Pattern == false) {
        if ((Local_Config_Information->Test_Info).Test_Method.Autogen_Pattern == false) {
          lcd_clear_result();
          lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
          lcd_show(1,"Do not support");
          lcd_show(2,"Test Mode");
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: Do not support Test Mode\n","Single_Board_PT2_Test");
          builtin_strncpy(tmp1,"Do not support Test Mode",0x18);
          tmp1[0x18] = '\0';
          log_to_file(tmp1,time_stamp);
        }
        iVar1 = 0xc;
      }
      else {
        iVar1 = Single_Board_PT2_Hardware_Pattern_Test();
      }
    }
    else {
      iVar1 = Single_Board_PT2_Super_Software_Pattern_Test();
    }
  }
  else {
    iVar1 = Single_Board_PT2_Software_Pattern_Test();
  }
  return iVar1;
}

