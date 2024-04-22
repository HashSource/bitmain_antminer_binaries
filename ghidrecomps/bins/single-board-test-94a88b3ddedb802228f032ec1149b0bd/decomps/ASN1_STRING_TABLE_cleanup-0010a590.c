
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ASN1_STRING_TABLE_cleanup(void)

{
  func *func;
  _STACK *st;
  
  func = DAT_0010a5a8;
  st = *DAT_0010a5a4;
  if (st != (_STACK *)0x0) {
    *DAT_0010a5a4 = (_STACK *)0x0;
    sk_pop_free(st,func);
    return;
  }
  return;
}

