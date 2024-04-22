
json_t * json_real(double value)

{
  json_t *json;
  double in_d0;
  double dVar1;
  double value_local;
  json_real_t *real;
  
  if ((NAN(in_d0)) ||
     (dVar1 = ABS(in_d0),
     dVar1 != DAT_00090fa8 && dVar1 < DAT_00090fa8 == (NAN(dVar1) || NAN(DAT_00090fa8)))) {
    json = (json_t *)0x0;
  }
  else {
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
  return json;
}

