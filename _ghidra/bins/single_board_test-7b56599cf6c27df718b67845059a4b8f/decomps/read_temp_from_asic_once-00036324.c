
_Bool read_temp_from_asic_once(_Bool logout)

{
  _Bool _Var1;
  _Bool logout_local;
  char time_stamp [48];
  char tmp1 [256];
  int readtimecounts;
  
  readtimecounts = 1;
  read_temperature_from_asic(&readtimecounts);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : ASIC TEMP,set max:%.2f\n","read_temp_from_asic_once",0,0x4057c000);
  snprintf(tmp1,0x100,"ASIC TEMP,set max:%.2f",0,0,0x4057c000);
  log_to_file(tmp1,time_stamp);
  _Var1 = check_asic_val(&g_asic_temp,95.0,logout);
  return _Var1;
}

