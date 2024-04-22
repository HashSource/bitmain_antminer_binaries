
int tls1_alert_code(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_1;
  if (param_1 < 0x74) {
    uVar1 = DAT_00075280 + param_1;
  }
  if (param_1 < 0x74) {
    iVar2 = (int)*(char *)(uVar1 + 4);
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}

