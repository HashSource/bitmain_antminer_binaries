
void power_init(void)

{
  int iVar1;
  FILE *pFVar2;
  char *pcVar3;
  char acStack_38 [36];
  
  power_check_protocal_type();
  power_info = 2;
  if (3 < log_level) {
    pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: start detect power type\n","power.c",0xad,DAT_000417f0);
    }
    fclose(pFVar2);
  }
  iVar1 = is7007_Board();
  if (iVar1 == 0) {
    iVar1 = access("/sys/class/gpio/gpio36",0);
    if (iVar1 == -1) {
      system("echo 36 > /sys/class/gpio/export");
      system("echo out > /sys/class/gpio/gpio36/direction");
      if (3 < log_level) {
        pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: init gpio36\n","power.c",0xc1,DAT_000417f0);
        }
        fclose(pFVar2);
      }
    }
    system("echo 0 > /sys/class/gpio/gpio36/value");
  }
  else {
    iVar1 = access("/sys/class/gpio/gpio907",0);
    if (iVar1 == -1) {
      system("echo 907 > /sys/class/gpio/export");
      system("echo out > /sys/class/gpio/gpio907/direction");
      if (3 < log_level) {
        pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: init gpio907\n","power.c",0xb5,DAT_000417f0);
        }
        fclose(pFVar2);
      }
    }
    system("echo 0 > /sys/class/gpio/gpio907/value");
  }
  sleep(1);
  iVar1 = power_info;
  pFVar2 = fopen("/etc/config/S11_power_type","wb");
  if (pFVar2 != (FILE *)0x0) {
    memset(acStack_38,0,0x20);
    sprintf(acStack_38,"%d",iVar1);
    fwrite(acStack_38,1,0x20,pFVar2);
    fclose(pFVar2);
  }
  system("sync");
  iVar1 = is7007_Board();
  if (iVar1 == 0) {
    system("echo 1 > /sys/class/gpio/gpio36/value");
  }
  else {
    system("echo 1 > /sys/class/gpio/gpio907/value");
  }
  if (3 < log_level) {
    pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar2 != (FILE *)0x0) {
      pcVar3 = "APW8 new type";
      if (power_info != 2) {
        pcVar3 = "APW8 old type";
      }
      fprintf(pFVar2,"%s:%d:%s: power type is %s\n","power.c",0xd3,DAT_000417f0,pcVar3);
    }
    fclose(pFVar2);
  }
  DAT_0080b6e8 = 0;
  DAT_0080b6d4 = 0;
  if ((int)((uint)((double)CONCAT44(DAT_0080b6d8._4_4_,(undefined4)DAT_0080b6d8) < DAT_000417e8) <<
           0x1f) < 0) {
    DAT_0080b6d8._0_4_ = DAT_000417f4;
    DAT_0080b6d8._4_4_ = DAT_000417f8;
  }
  DAT_0080b6ec = 0;
  DAT_0080b6f0 = 0;
  DAT_0080b6e0._0_4_ = DAT_000417fc;
  DAT_0080b6e0._4_4_ = DAT_00041800;
  return;
}

