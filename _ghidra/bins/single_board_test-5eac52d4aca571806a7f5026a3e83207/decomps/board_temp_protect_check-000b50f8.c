
_Bool board_temp_protect_check(int8_t max_temp,int8_t min_temp)

{
  bool bVar1;
  int8_t min_temp_local;
  int8_t max_temp_local;
  char time_stamp [48];
  char tmp1 [256];
  
  bVar1 = (int)max_temp < (Local_Config_Information->Test_Info).Temperature.Max_Board_Temp;
  if (!bVar1) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Max temp out of protect temp,min:%d,max:%d\n","board_temp_protect_check",
           (int)min_temp,(int)max_temp);
    snprintf(tmp1,0x100,"Max temp out of protect temp,min:%d,max:%d",(int)min_temp,(int)max_temp);
    log_to_file(tmp1,time_stamp);
  }
  return bVar1;
}

