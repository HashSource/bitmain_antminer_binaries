
int * ssl_get_cipher_by_char(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*(int *)(param_1 + 8) + 0x48))(param_2);
  if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
    return piVar1;
  }
  return (int *)0x0;
}

