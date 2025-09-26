
/* WARNING: Unknown calling convention */

void * pt_power_monitor_thread(void)

{
  int32_t iVar1;
  char tmp42 [256];
  uint32_t cur_voltage;
  uint32_t status;
  
  iVar1 = bitmain_set_watchdog('\x01');
  snprintf(tmp42,0x100,"enable power watchdog: 0x%04x\n",iVar1);
  puts(tmp42);
  if (iVar1 != 1) {
    snprintf(tmp42,0x100,"%s power enable watchdog error.\n","pt_power_monitor_thread");
    puts(tmp42);
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

