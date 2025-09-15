
double json_number_value(json_t *json)

{
  json_int_t jVar1;
  double dVar2;
  json_t *json_local;
  
  if ((json == (json_t *)0x0) || (json->type != JSON_INTEGER)) {
    if ((json == (json_t *)0x0) || (json->type != JSON_REAL)) {
      dVar2 = 0.0;
    }
    else {
      dVar2 = json_real_value(json);
    }
  }
  else {
    jVar1 = json_integer_value(json);
    dVar2 = (double)__aeabi_l2d((int)jVar1,(int)((ulonglong)jVar1 >> 0x20));
  }
  return dVar2;
}

