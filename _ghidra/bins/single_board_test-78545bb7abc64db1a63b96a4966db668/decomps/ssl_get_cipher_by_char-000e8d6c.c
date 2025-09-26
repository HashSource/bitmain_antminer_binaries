
int * ssl_get_cipher_by_char(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*(int *)(param_1 + 4) + 0x4c))(param_2);
  if (((piVar1 != (int *)0x0) && (param_3 == 0)) && (*piVar1 == 0)) {
    piVar1 = (int *)0x0;
  }
  return piVar1;
}

