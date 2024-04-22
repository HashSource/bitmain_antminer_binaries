
int json_real_set(json_t *json,double value)

{
  int iVar1;
  json_t in_d0;
  double unaff_d8;
  
  if ((((json == (json_t *)0x0) || (json->type != JSON_REAL)) ||
      (iVar1 = __isnan(unaff_d8), iVar1 != 0)) || (iVar1 = __isinf(unaff_d8), iVar1 != 0)) {
    iVar1 = -1;
  }
  else {
    json[1] = in_d0;
    iVar1 = 0;
  }
  return iVar1;
}

