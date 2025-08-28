
json_t * json_real(double value)

{
  int iVar1;
  json_t *json;
  double value_local;
  json_real_t *real;
  
  iVar1 = __isnan(value);
  if ((iVar1 == 0) && (iVar1 = __isinf(value), iVar1 == 0)) {
    json = (json_t *)jsonp_malloc(0x10);
    if (json == (json_t *)0x0) {
      json = (json_t *)0x0;
    }
    else {
      json_init(json,JSON_REAL);
      json[1] = (json_t)value;
    }
  }
  else {
    json = (json_t *)0x0;
  }
  return json;
}

