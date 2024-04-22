
/* WARNING: Unknown calling convention */

int get_max_chip_temperature(void)

{
  int iVar1;
  int temp;
  
  iVar1 = max_chip_temperature;
  max_chip_temperature = 0;
  return iVar1;
}

