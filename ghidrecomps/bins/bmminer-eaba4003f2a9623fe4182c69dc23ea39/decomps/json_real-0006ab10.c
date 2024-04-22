
/* WARNING: Variable defined which should be unmapped: value-local */

json_t * json_real(double value)

{
  int iVar1;
  json_t *json;
  double in_d0;
  double value_local;
  json_real_t *real;
  
  iVar1 = __isnan(in_d0);
  if ((iVar1 == 0) && (iVar1 = __isinf(in_d0), iVar1 == 0)) {
    json = (json_t *)jsonp_malloc(0x10);
    if (json == (json_t *)0x0) {
      json = (json_t *)0x0;
    }
    else {
      json_init(json,JSON_REAL);
      value_local._0_4_ = SUB84(in_d0,0);
      value_local._4_4_ = (size_t)((ulonglong)in_d0 >> 0x20);
      json[1].type = value_local._0_4_;
      json[1].refcount = value_local._4_4_;
    }
  }
  else {
    json = (json_t *)0x0;
  }
  return json;
}

