
json_t * json_integer(json_int_t value)

{
  json_type in_r0;
  json_integer_t *integer;
  json_t *pjVar1;
  size_t in_r1;
  
  pjVar1 = (json_t *)jsonp_malloc(0x10);
  if (pjVar1 != (json_t *)0x0) {
    pjVar1[1].type = in_r0;
    pjVar1[1].refcount = in_r1;
    pjVar1->type = JSON_INTEGER;
    pjVar1->refcount = 1;
  }
  return pjVar1;
}

