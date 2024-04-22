
json_t * json_real(double value)

{
  int iVar1;
  json_t *pjVar2;
  json_real_t *real;
  json_t in_d0;
  double unaff_d8;
  
  iVar1 = __isnan(unaff_d8);
  if (((iVar1 == 0) && (iVar1 = __isinf(unaff_d8), iVar1 == 0)) &&
     (pjVar2 = (json_t *)jsonp_malloc(0x10), pjVar2 != (json_t *)0x0)) {
    pjVar2[1] = in_d0;
    pjVar2->type = JSON_REAL;
    pjVar2->refcount = 1;
  }
  else {
    pjVar2 = (json_t *)0x0;
  }
  return pjVar2;
}

