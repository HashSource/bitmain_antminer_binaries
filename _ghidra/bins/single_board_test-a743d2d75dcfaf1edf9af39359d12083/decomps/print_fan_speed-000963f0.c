
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void print_fan_speed(void)

{
  int32_t iVar1;
  int32_t iVar2;
  int32_t iVar3;
  int speed;
  int i;
  
  i = 0;
  while ((i < 6 && (iVar1 = fan_get_realtime_speed(i), iVar1 != -1))) {
    iVar2 = fan_get_max_num();
    iVar3 = fan_get_max_speed(i);
    printf("fan [%d:%d] speed cur = %d, max = %d\n",i + 1,iVar2,iVar1,iVar3);
    i = i + 1;
  }
  return;
}

