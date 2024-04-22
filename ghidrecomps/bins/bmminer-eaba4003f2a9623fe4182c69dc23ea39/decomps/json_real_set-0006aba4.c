
/* WARNING: Variable defined which should be unmapped: value-local */

int json_real_set(json_t *json,double value)

{
  int iVar1;
  double in_d0;
  double value_local;
  json_t *json_local;
  
  if ((((json == (json_t *)0x0) || (json->type != JSON_REAL)) ||
      (iVar1 = __isnan(in_d0), iVar1 != 0)) || (iVar1 = __isinf(in_d0), iVar1 != 0)) {
    iVar1 = -1;
  }
  else {
    value_local._0_4_ = SUB84(in_d0,0);
    value_local._4_4_ = (size_t)((ulonglong)in_d0 >> 0x20);
    json[1].type = value_local._0_4_;
    json[1].refcount = value_local._4_4_;
    iVar1 = 0;
  }
  return iVar1;
}

