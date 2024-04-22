
/* WARNING: Unknown calling convention */

int get_max_temperature(void)

{
  int iVar1;
  int temp;
  
  iVar1 = max_temperature;
  max_temperature = 0;
  return iVar1;
}

