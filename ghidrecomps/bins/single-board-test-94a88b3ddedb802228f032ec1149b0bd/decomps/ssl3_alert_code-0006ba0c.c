
int ssl3_alert_code(uint param_1)

{
  int iVar1;
  
  if (param_1 < 0x74) {
    iVar1 = (int)*(char *)(DAT_0006ba1c + param_1);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

