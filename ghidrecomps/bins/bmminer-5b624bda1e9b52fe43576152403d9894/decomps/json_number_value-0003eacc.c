
/* WARNING: Unknown calling convention */

double json_number_value(json_t *json)

{
  double dVar1;
  
  if (json != (json_t *)0x0) {
    if (json->type == JSON_INTEGER) {
      dVar1 = (double)__aeabi_l2d(json[1].type,json[1].refcount);
      return dVar1;
    }
    if (json->type == JSON_REAL) {
      return (double)json[1];
    }
  }
  return DAT_0003eaf8;
}

