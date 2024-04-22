
int ssl_verify_alarm_type(int param_1)

{
  int iVar1;
  
  if (param_1 - 2U < 0x31) {
    iVar1 = (int)*(char *)(DAT_0006d65c + (param_1 - 2U));
  }
  else {
    iVar1 = 0x2e;
  }
  return iVar1;
}

