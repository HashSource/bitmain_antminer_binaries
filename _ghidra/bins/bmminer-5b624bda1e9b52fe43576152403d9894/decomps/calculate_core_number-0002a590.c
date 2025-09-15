
/* WARNING: Unknown calling convention */

int calculate_core_number(uint actual_core_number)

{
  char tmp42 [2048];
  
  snprintf(tmp42,0x800,"actual_core_number = %d, but it is error\n",actual_core_number);
  _applog(7,tmp42,false);
  return -1;
}

