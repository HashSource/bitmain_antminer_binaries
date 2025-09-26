
int ssl_verify_alarm_type(int param_1)

{
  int iVar1;
  
  if (param_1 - 2U < 0x31) {
    iVar1 = (int)(char)(&DAT_001f6796)[param_1];
  }
  else {
    iVar1 = 0x2e;
  }
  return iVar1;
}

