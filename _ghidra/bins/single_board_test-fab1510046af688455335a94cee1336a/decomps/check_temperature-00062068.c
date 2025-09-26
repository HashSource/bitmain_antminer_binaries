
/* WARNING: Unknown calling convention */

_Bool check_temperature(void)

{
  char cVar1;
  char cVar2;
  int8_t iVar3;
  int iVar4;
  char time_stamp [48];
  char tmp1 [2048];
  int8_t min_temp_water;
  int8_t max_temp_board;
  int8_t temp;
  _Bool res;
  
  iVar3 = get_max_value(gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_pic,
                        (uint8_t)gPic_sensor_num);
  if ('A' < iVar3) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: max temperature = %d over 65\n","check_temperature",(int)iVar3);
    snprintf(tmp1,0x800,"max temperature = %d over 65",(int)iVar3);
    log_to_file(tmp1,time_stamp);
  }
  res = 'A' >= iVar3;
  cVar1 = gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_pic[2];
  cVar2 = gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_pic[1];
  if (0x13 < (int)cVar1 - (int)cVar2) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: max_temp_board(%d) - min_temp_water(%d) = %d over 20\n","check_temperature",
           (int)cVar1,(int)cVar2,(int)cVar1 - (int)cVar2);
    snprintf(tmp1,0x800,"max_temp_board(%d) - min_temp_water(%d) = %d over 20",(int)cVar1,(int)cVar2
             ,(int)cVar1 - (int)cVar2);
    log_to_file(tmp1,time_stamp);
    res = false;
  }
  cVar1 = gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_pic[3];
  cVar2 = gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_pic[0];
  if (0x13 < (int)cVar1 - (int)cVar2) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: max_temp_board(%d) - min_temp_water(%d) = %d over 20\n","check_temperature",
           (int)cVar1,(int)cVar2,(int)cVar1 - (int)cVar2);
    snprintf(tmp1,0x800,"max_temp_board(%d) - min_temp_water(%d) = %d over 20",(int)cVar1,(int)cVar2
             ,(int)cVar1 - (int)cVar2);
    log_to_file(tmp1,time_stamp);
    res = false;
  }
  iVar4 = (int)gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_pic[2] -
          (int)gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_pic[3];
  if (iVar4 < 0) {
    iVar4 = -iVar4;
  }
  cVar1 = (char)iVar4;
  if ('\f' < cVar1) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: board temperature difference = %d over 11\n","check_temperature",(int)cVar1);
    snprintf(tmp1,0x800,"board temperature difference = %d over 11",(int)cVar1);
    log_to_file(tmp1,time_stamp);
    res = false;
  }
  iVar4 = (int)gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_pic[0] -
          (int)gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_pic[1];
  if (iVar4 < 0) {
    iVar4 = -iVar4;
  }
  cVar1 = (char)iVar4;
  if ('\v' < cVar1) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: water inlet/outlet temperature difference = %d over 11\n","check_temperature",
           (int)cVar1);
    snprintf(tmp1,0x800,"water inlet/outlet temperature difference = %d over 11",(int)cVar1);
    log_to_file(tmp1,time_stamp);
    res = false;
  }
  return res;
}

