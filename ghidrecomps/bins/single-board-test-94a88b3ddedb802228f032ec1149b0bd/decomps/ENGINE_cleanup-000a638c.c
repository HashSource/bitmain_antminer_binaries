
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ENGINE_cleanup(void)

{
  _STACK **pp_Var1;
  
  pp_Var1 = DAT_000a63a8;
  if (*DAT_000a63a8 != (_STACK *)0x0) {
    sk_pop_free(*DAT_000a63a8,DAT_000a63ac);
    *pp_Var1 = (_STACK *)0x0;
  }
  RAND_set_rand_method((RAND_METHOD *)0x0);
  return;
}

