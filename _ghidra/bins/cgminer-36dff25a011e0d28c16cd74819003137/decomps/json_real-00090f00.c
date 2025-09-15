
json_t * json_real(double value)

{
  json_t *json;
  double value_local;
  json_real_t *real;
  
  if ((NAN(value)) || (1.79769313486232e+308 < ABS(value))) {
    json = (json_t *)0x0;
  }
  else {
    json = (json_t *)jsonp_malloc(0x10);
    if (json == (json_t *)0x0) {
      json = (json_t *)0x0;
    }
    else {
      json_init(json,JSON_REAL);
      json[1] = (json_t)value;
    }
  }
  return json;
}

