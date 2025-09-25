
_Bool find_APW_power_version(int32_t apw_power_version)

{
  int32_t apw_power_version_local;
  char time_stamp [48];
  char tmp1 [256];
  uint8_t i;
  
  i = '\0';
  while( true ) {
    if (gPower_version_array_size <= i) {
      return false;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : APW_power_version[%d]: %d, and we want to find apw_power_version: %d, \n",
           "find_APW_power_version",(uint)i,(uint)APW_power_version[i],apw_power_version);
    snprintf(tmp1,0x100,"APW_power_version[%d]: %d, and we want to find apw_power_version: %d, ",
             (uint)i,(uint)APW_power_version[i],apw_power_version);
    log_to_file(tmp1,time_stamp);
    if ((uint)APW_power_version[i] == apw_power_version) break;
    i = i + '\x01';
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Find APW power version. It is %d\n","find_APW_power_version",apw_power_version);
  snprintf(tmp1,0x100,"Find APW power version. It is %d",apw_power_version);
  log_to_file(tmp1,time_stamp);
  return true;
}

