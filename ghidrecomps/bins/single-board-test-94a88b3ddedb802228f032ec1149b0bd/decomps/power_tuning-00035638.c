
void power_tuning(void)

{
  char cVar1;
  int iVar2;
  FILE *__stream;
  double dVar3;
  
  iVar2 = is7007_Board();
  if (iVar2 == 0) {
    system("echo 0 > /sys/class/gpio/gpio36/value");
  }
  else {
    system("echo 0 > /sys/class/gpio/gpio907/value");
  }
  sleep(1);
  cVar1 = set_iic_power_voltage((int)DAT_003b0f50,&power_info,1);
  if (cVar1 != '\x01') {
    dVar3 = (double)get_avg_voltage();
    if ((int)((uint)(dVar3 < DAT_00035748) << 0x1f) < 0) {
      stop_mining("power voltage too low\n");
    }
  }
  DAT_003b0f64 = DAT_003b0f60;
  cVar1 = set_iic_power_voltage((undefined4)DAT_003b0f58,&power_info,0);
  if ((cVar1 != '\x01') && (1 < log_level)) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: Warning! power voltage couldn\'t up to %f\n","power.c",0x305,
              (undefined4)DAT_003b0f58,DAT_003b0f58._4_4_);
    }
    fclose(__stream);
  }
  DAT_003b0f68 = DAT_003b0f60;
  return;
}

