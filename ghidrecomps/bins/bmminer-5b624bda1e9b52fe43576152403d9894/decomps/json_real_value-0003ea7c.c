
/* WARNING: Unknown calling convention */

double json_real_value(json_t *json)

{
  if ((json != (json_t *)0x0) && (json->type == JSON_REAL)) {
    return (double)json[1];
  }
  return DAT_0003ea90;
}

