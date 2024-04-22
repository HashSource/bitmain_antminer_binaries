
void int_cleanup(void)

{
  _LHASH **pp_Var1;
  _LHASH *p_Var2;
  
  pp_Var1 = DAT_0008aee8;
  p_Var2 = *DAT_0008aee8;
  if (p_Var2 == (_LHASH *)0x0) {
    CRYPTO_lock(9,2,DAT_0008aef0,0x116);
    if (*pp_Var1 == (_LHASH *)0x0) {
      p_Var2 = lh_new(DAT_0008aef4,DAT_0008aef8);
      *pp_Var1 = p_Var2;
      if (p_Var2 == (_LHASH *)0x0) {
        CRYPTO_lock(10,2,DAT_0008aef0,0x119);
        return;
      }
    }
    CRYPTO_lock(10,2,DAT_0008aef0,0x119);
    p_Var2 = *pp_Var1;
  }
  lh_doall(p_Var2,DAT_0008aeec);
  lh_free(*pp_Var1);
  *pp_Var1 = (_LHASH *)0x0;
  pp_Var1[1] = (_LHASH *)0x0;
  return;
}

