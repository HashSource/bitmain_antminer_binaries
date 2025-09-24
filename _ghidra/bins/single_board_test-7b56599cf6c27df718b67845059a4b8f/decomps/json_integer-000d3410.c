
json_t * json_integer(json_int_t value)

{
  json_t *pjVar1;
  
  pjVar1 = (json_t *)jsonp_malloc(0x10);
  if (pjVar1 != (json_t *)0x0) {
    pjVar1[1].type = (int)value;
    pjVar1[1].refcount = (int)((ulonglong)value >> 0x20);
    pjVar1->type = JSON_INTEGER;
    pjVar1->refcount = 1;
  }
  return pjVar1;
}

