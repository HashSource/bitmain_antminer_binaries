
void set_lowprio_part_17(void)

{
  char local_810 [2052];
  
  builtin_strncpy(local_810,"Unable to set thread to low priority",0x24);
  local_810[0x24] = 0;
  _applog(6,local_810,0);
  return;
}

