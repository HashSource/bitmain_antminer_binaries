
_LHASH * int_err_get(int param_1)

{
  _LHASH **pp_Var1;
  _LHASH *p_Var2;
  
  pp_Var1 = DAT_000ac6f4;
  CRYPTO_lock(9,1,DAT_000ac6f8,0x168);
  p_Var2 = *pp_Var1;
  if ((p_Var2 == (_LHASH *)0x0) && (param_1 != 0)) {
    CRYPTO_push_info_(DAT_000ac6fc,DAT_000ac6f8,0x16a);
    p_Var2 = lh_new(DAT_000ac704,DAT_000ac700);
    *pp_Var1 = p_Var2;
    CRYPTO_pop_info();
    p_Var2 = *pp_Var1;
  }
  CRYPTO_lock(10,1,DAT_000ac6f8,0x170);
  return p_Var2;
}

