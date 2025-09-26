
json_t * json_real(double value)

{
  int iVar1;
  json_t *pjVar2;
  
  iVar1 = __isnan(value);
  if (((iVar1 == 0) && (iVar1 = __isinf(value), iVar1 == 0)) &&
     (pjVar2 = (json_t *)jsonp_malloc(0x10), pjVar2 != (json_t *)0x0)) {
    pjVar2[1] = (json_t)value;
    pjVar2->type = JSON_REAL;
    pjVar2->refcount = 1;
  }
  else {
    pjVar2 = (json_t *)0x0;
  }
  return pjVar2;
}

