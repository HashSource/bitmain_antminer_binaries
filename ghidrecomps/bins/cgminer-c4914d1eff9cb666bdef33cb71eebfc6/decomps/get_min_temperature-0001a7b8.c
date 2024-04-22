
/* WARNING: Unknown calling convention */

int get_min_temperature(void)

{
  int iVar1;
  int temp;
  
  iVar1 = min_temperature;
  min_temperature = 1000;
  return iVar1;
}

