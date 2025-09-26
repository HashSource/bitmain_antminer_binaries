
/* WARNING: Unknown calling convention */

int32_t pwm_get(int32_t ctx,uint32_t *duty)

{
  int32_t iVar1;
  char tmp42 [2048];
  
  if (ctx < 3) {
    if (ctx == 1) {
      fpga_read(0x13,duty);
      *duty = (uint)*(ushort *)((int)duty + 2);
      return 0;
    }
    iVar1 = -5;
  }
  else {
    iVar1 = -3;
    builtin_strncpy(tmp42,"bad para",8);
    tmp42[8] = 'm';
    tmp42[9] = '\n';
    tmp42[10] = '\0';
    _applog(0,tmp42,false);
  }
  return iVar1;
}

