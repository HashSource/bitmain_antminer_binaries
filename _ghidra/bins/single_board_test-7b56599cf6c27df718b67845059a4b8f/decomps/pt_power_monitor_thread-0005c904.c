
/* WARNING: Unknown calling convention */

void * pt_power_monitor_thread(void)

{
  int32_t iVar1;
  char time_stamp [48];
  char tmp1 [256];
  uint32_t cur_voltage;
  uint32_t status;
  
  iVar1 = bitmain_set_watchdog('\x01');
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : enable power watchdog: 0x%04x\n","pt_power_monitor_thread",iVar1);
  snprintf(tmp1,0x100,"enable power watchdog: 0x%04x",iVar1);
  log_to_file(tmp1,time_stamp);
  if (iVar1 != 1) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : %s power enable watchdog error.\n","pt_power_monitor_thread",
           "pt_power_monitor_thread");
    snprintf(tmp1,0x100,"%s power enable watchdog error.","pt_power_monitor_thread");
    log_to_file(tmp1,time_stamp);
    return (void *)0x0;
  }
  do {
    pthread_setcancelstate(1,(int *)0x0);
    bitmain_get_power_status();
    pthread_setcancelstate(0,(int *)0x0);
    pthread_testcancel();
    sleep(3);
  } while( true );
}

