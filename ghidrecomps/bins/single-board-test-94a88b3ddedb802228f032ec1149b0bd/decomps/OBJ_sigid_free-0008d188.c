
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void OBJ_sigid_free(void)

{
  _STACK **pp_Var1;
  
  pp_Var1 = DAT_0008d1ac;
  if (*DAT_0008d1ac != (_STACK *)0x0) {
    sk_pop_free(*DAT_0008d1ac,DAT_0008d1b0);
    *pp_Var1 = (_STACK *)0x0;
  }
  pp_Var1 = DAT_0008d1b4;
  if (*DAT_0008d1b4 != (_STACK *)0x0) {
    sk_free(*DAT_0008d1b4);
    *pp_Var1 = (_STACK *)0x0;
  }
  return;
}

