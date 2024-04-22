
/* WARNING: Unknown calling convention */

int get_min_chip_temperature(void)

{
  int iVar1;
  int temp;
  
  iVar1 = min_chip_temperature;
  min_chip_temperature = 1000;
  return iVar1;
}

