
char * set_sched_stop(char *param_1)

{
  int iVar1;
  
  iVar1 = sscanf(param_1,"%d:%d",0x80ba10,0x80ba0c);
  if (iVar1 != 2) {
    return "Invalid time set, should be HH:MM";
  }
  if (((uint)schedstop._12_4_ < 0x18) && ((uint)schedstop._8_4_ < 0x3c)) {
    schedstop[0] = 1;
    return (char *)0x0;
  }
  return "Invalid time set.";
}

