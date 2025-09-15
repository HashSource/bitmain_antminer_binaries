
void power_type_detect(int *param_1)

{
  FILE *pFVar1;
  int iVar2;
  char *pcVar3;
  
  power_check_protocal_type();
  *param_1 = 2;
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: start detect power type\n","power.c",0xae);
    }
    fclose(pFVar1);
  }
  iVar2 = is7007_Board();
  if (iVar2 == 0) {
    iVar2 = access("/sys/class/gpio/gpio36",0);
    if (iVar2 == -1) {
      system("echo 36 > /sys/class/gpio/export");
      system("echo out > /sys/class/gpio/gpio36/direction");
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d: init gpio36\n","power.c",0xc2);
        }
        fclose(pFVar1);
      }
    }
    system("echo 0 > /sys/class/gpio/gpio36/value");
  }
  else {
    iVar2 = access("/sys/class/gpio/gpio907",0);
    if (iVar2 == -1) {
      system("echo 907 > /sys/class/gpio/export");
      system("echo out > /sys/class/gpio/gpio907/direction");
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d: init gpio907\n","power.c",0xb6);
        }
        fclose(pFVar1);
      }
    }
    system("echo 0 > /sys/class/gpio/gpio907/value");
  }
  sleep(1);
  save_power_type(*param_1);
  iVar2 = is7007_Board();
  if (iVar2 == 0) {
    system("echo 1 > /sys/class/gpio/gpio36/value");
  }
  else {
    system("echo 1 > /sys/class/gpio/gpio907/value");
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      if (*param_1 == 2) {
        pcVar3 = "APW8 new type";
      }
      else {
        pcVar3 = "APW8 old type";
      }
      fprintf(pFVar1,"%s:%d: power type is %s\n","power.c",0xd4,pcVar3);
    }
    fclose(pFVar1);
  }
  return;
}

