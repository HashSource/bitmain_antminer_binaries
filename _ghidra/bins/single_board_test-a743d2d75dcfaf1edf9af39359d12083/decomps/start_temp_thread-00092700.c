
/* WARNING: Unknown calling convention */

int start_temp_thread(void)

{
  int iVar1;
  char tmp42 [256];
  int ret;
  
  g_rt.read_temp = 1;
  iVar1 = pthread_create(&g_temp_handle,(pthread_attr_t *)0x0,(__start_routine *)0x8ff51,&g_rt);
  if (iVar1 == 0) {
    while (g_rt.tempval[0] == '\0') {
      builtin_strncpy(tmp42,"can not read senor temp",0x18);
      puts(tmp42);
      sleep(1);
    }
    builtin_strncpy(tmp42,"read sensor temp ok",0x14);
    puts(tmp42);
    iVar1 = 0;
  }
  else {
    builtin_strncpy(tmp42,"create read temp thread fail",0x1c);
    tmp42[0x1c] = 'e';
    tmp42[0x1d] = 'd';
    tmp42[0x1e] = '\0';
    puts(tmp42);
  }
  return iVar1;
}

