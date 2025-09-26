
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void get_all_fan_speed(void)

{
  int32_t iVar1;
  int speed;
  int i;
  
  printf("fan:");
  i = 0;
  while ((i < 4 && (iVar1 = fan_get_realtime_speed(i), iVar1 != -1))) {
    printf("[%d:%d] ",i,iVar1);
    i = i + 1;
  }
  putchar(10);
  return;
}

