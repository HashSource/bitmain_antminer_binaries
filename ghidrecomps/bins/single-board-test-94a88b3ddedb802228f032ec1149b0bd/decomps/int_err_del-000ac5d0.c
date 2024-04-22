
void int_err_del(void)

{
  _LHASH **pp_Var1;
  _LHASH *lh;
  
  pp_Var1 = DAT_000ac600;
  CRYPTO_lock(9,1,DAT_000ac604,0x177);
  lh = *pp_Var1;
  if (lh != (_LHASH *)0x0) {
    lh_free(lh);
    *pp_Var1 = (_LHASH *)0x0;
  }
  CRYPTO_lock(10,1,DAT_000ac604,0x17c);
  return;
}

