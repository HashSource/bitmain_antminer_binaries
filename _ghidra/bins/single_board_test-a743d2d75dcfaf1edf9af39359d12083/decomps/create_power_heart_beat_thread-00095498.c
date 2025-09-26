
/* WARNING: Unknown calling convention */

int32_t create_power_heart_beat_thread(void)

{
  int iVar1;
  int32_t iVar2;
  char tmp42 [256];
  int ret;
  
  iVar1 = pthread_create(&g_power_handle,(pthread_attr_t *)0x0,(__start_routine *)0x953fd,
                         (void *)0x0);
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  else {
    builtin_strncpy(tmp42,"create send work thread failed\n",0x20);
    puts(tmp42);
    iVar2 = -1;
  }
  return iVar2;
}

