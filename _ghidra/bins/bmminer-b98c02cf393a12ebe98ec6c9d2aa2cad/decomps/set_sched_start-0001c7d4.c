
char * set_sched_start(char *param_1)

{
  int iVar1;
  
  iVar1 = sscanf(param_1,"%d:%d",0x80bac8,0x80bac4);
  if (iVar1 != 2) {
    return "Invalid time set, should be HH:MM";
  }
  if (((uint)schedstart._12_4_ < 0x18) && ((uint)schedstart._8_4_ < 0x3c)) {
    schedstart[0] = 1;
    return (char *)0x0;
  }
  return "Invalid time set.";
}

