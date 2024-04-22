
/* WARNING: Unknown calling convention */

_Bool is_in_error(void)

{
  undefined uVar1;
  STATUS_CODE SVar2;
  
  SVar2 = status_value;
  if (STATUS_OK < status_value) {
    SVar2 = STATUS_OK;
  }
  uVar1 = (undefined)SVar2;
  if (status_value < ERROR_OVER_MAXTEMP) {
    uVar1 = 0;
  }
  return (_Bool)uVar1;
}

