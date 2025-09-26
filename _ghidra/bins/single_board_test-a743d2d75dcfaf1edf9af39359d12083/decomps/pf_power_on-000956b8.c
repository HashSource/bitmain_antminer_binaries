
_Bool pf_power_on(uint32_t voltage)

{
  int32_t iVar1;
  _Bool _Var2;
  undefined *puVar3;
  double dVar4;
  uint32_t voltage_local;
  char tmp42 [256];
  int32_t ret;
  
  snprintf(tmp42,0x100,"%s","pf_power_on");
  puts(tmp42);
  snprintf(tmp42,0x100,"APW power on, voltage:%d",voltage);
  puts(tmp42);
  iVar1 = bitmain_power_version();
  if (iVar1 - 0x75U < 4) {
    bitmain_set_watchdog('\0');
  }
  ret = bitmain_set_voltage((double)voltage / 100.0);
  if (ret < 0) {
    ret = bitmain_set_voltage((double)voltage / 100.0);
  }
  if (ret < 0) {
    builtin_strncpy(tmp42,"set voltage fail",0x10);
    tmp42[0x10] = 'e';
    tmp42[0x11] = 'd';
    tmp42[0x12] = '\0';
    puts(tmp42);
    _Var2 = false;
  }
  else {
    dVar4 = (double)voltage / 100.0;
    snprintf(tmp42,0x100,"APW set voltage ok, voltage is %02f",tmp42,dVar4);
    puts(tmp42);
    ret = bitmain_power_on();
    if (ret != 0) {
      ret = bitmain_power_on();
    }
    if (ret == 0) {
      puVar3 = &DAT_001e99b8;
    }
    else {
      puVar3 = &DAT_001e99bc;
    }
    snprintf(tmp42,0x100,"APW power on %s.",puVar3,dVar4);
    puts(tmp42);
    usleep(300000);
    _Var2 = true;
  }
  return _Var2;
}

