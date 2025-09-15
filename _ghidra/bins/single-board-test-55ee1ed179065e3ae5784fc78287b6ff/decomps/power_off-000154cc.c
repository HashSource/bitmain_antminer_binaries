
void power_off(void)

{
  int iVar1;
  
  iVar1 = access("/sys/class/gpio/gpio907",0);
  if (iVar1 == -1) {
    system("echo 907 > /sys/class/gpio/export");
    system("echo out > /sys/class/gpio/gpio907/direction");
    puts("init gpio907");
  }
  system("echo 1 > /sys/class/gpio/gpio907/value");
  sleep(1);
  return;
}

