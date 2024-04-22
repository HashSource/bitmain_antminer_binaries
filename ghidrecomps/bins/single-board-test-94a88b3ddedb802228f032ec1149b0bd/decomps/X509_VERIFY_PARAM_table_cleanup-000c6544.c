
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void X509_VERIFY_PARAM_table_cleanup(void)

{
  _STACK **pp_Var1;
  
  pp_Var1 = DAT_000c6558;
  if (*DAT_000c6558 != (_STACK *)0x0) {
    sk_pop_free(*DAT_000c6558,DAT_000c655c);
  }
  *pp_Var1 = (_STACK *)0x0;
  return;
}

