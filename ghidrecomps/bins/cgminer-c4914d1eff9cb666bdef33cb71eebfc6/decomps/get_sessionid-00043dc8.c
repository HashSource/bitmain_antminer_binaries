
char * get_sessionid(json_t *val)

{
  json_t *json;
  size_t sVar1;
  json_t *val_00;
  char *pcVar2;
  int iVar3;
  byte bVar4;
  byte bVar5;
  json_t *pjVar6;
  json_t *val_local;
  char *notify;
  json_t *arr;
  int arrsize;
  json_t *arr_val;
  int i;
  char *ret;
  
  json = json_array_get(val,0);
  if (((json != (json_t *)0x0) && (json != (json_t *)0x0)) && (json->type == JSON_ARRAY)) {
    sVar1 = json_array_size(json);
    for (i = 0; i < (int)sVar1; i = i + 1) {
      val_00 = json_array_get(json,i);
      pjVar6 = val_00;
      if (val_00 == (json_t *)0x0) {
        pjVar6 = (json_t *)0x1;
      }
      bVar4 = (byte)pjVar6;
      if ((val_00 == (json_t *)0x0) || (bVar4 = 0, val_00->type != JSON_ARRAY)) {
        bVar5 = 1;
      }
      else {
        bVar5 = 0;
      }
      if ((bVar5 | bVar4) != 0) {
        return (char *)0x0;
      }
      pcVar2 = __json_array_string(val_00,0);
      if ((pcVar2 != (char *)0x0) && (iVar3 = strncasecmp(pcVar2,"mining.notify",0xd), iVar3 == 0))
      {
        pcVar2 = json_array_string(val_00,1);
        return pcVar2;
      }
    }
  }
  return (char *)0x0;
}

