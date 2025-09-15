
int tls1_alert_code(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = param_1;
  if (param_1 < (undefined1 *)0x74) {
    puVar1 = &empty_18630 + (int)param_1;
  }
  if (param_1 < (undefined1 *)0x74) {
    iVar2 = (int)(char)puVar1[4];
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}

