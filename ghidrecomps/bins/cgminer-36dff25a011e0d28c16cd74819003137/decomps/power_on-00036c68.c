
/* WARNING: Unknown calling convention */

void power_on(void)

{
  int iVar1;
  FILE *__stream;
  FILE *pFile;
  
  iVar1 = access("/sys/class/gpio/gpio907",0);
  if (iVar1 == -1) {
    system("echo 907 > /sys/class/gpio/export");
    system("echo out > /sys/class/gpio/gpio907/direction");
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: init gpio907\n","power.c",0x98,"power_on");
      }
      fclose(__stream);
    }
  }
  system("echo 0 > /sys/class/gpio/gpio907/value");
  sleep(1);
  return;
}

