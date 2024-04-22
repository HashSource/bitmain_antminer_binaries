
void power_tuning(void)

{
  int iVar1;
  FILE *__stream;
  double dVar2;
  
  iVar1 = is7007_Board();
  if (iVar1 == 0) {
    system("echo 0 > /sys/class/gpio/gpio36/value");
  }
  else {
    system("echo 0 > /sys/class/gpio/gpio907/value");
  }
  sleep(1);
  iVar1 = set_iic_power_voltage((int)DAT_0080b6d8,&power_info,1);
  if ((iVar1 == 0) &&
     (dVar2 = (double)get_avg_voltage(), (int)((uint)(dVar2 < DAT_00042d40) << 0x1f) < 0)) {
    stop_mining("power voltage too low\n");
  }
  DAT_0080b6ec = DAT_0080b6e8;
  iVar1 = set_iic_power_voltage((undefined4)DAT_0080b6e0,&power_info,0);
  if ((iVar1 == 0) && (1 < log_level)) {
    __stream = fopen(log_file,(char *)&DAT_0005e760);
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: Warning! power voltage couldn\'t up to %f\n","power.c",0x31a,
              DAT_00042d48);
    }
    fclose(__stream);
  }
  DAT_0080b6f0 = DAT_0080b6e8;
  return;
}

