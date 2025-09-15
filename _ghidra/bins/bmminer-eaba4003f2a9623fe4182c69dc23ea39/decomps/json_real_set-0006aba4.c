
int json_real_set(json_t *json,double value)

{
  int iVar1;
  double value_local;
  json_t *json_local;
  
  if ((((json == (json_t *)0x0) || (json->type != JSON_REAL)) ||
      (iVar1 = __isnan(value), iVar1 != 0)) || (iVar1 = __isinf(value), iVar1 != 0)) {
    iVar1 = -1;
  }
  else {
    json[1] = (json_t)value;
    iVar1 = 0;
  }
  return iVar1;
}

