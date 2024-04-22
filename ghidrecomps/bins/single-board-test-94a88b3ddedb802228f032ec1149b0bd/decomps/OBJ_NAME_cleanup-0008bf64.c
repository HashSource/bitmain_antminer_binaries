
void OBJ_NAME_cleanup(int type)

{
  _STACK **pp_Var1;
  LHASH_DOALL_FN_TYPE func;
  _LHASH *lh;
  ulong uVar2;
  
  pp_Var1 = DAT_0008bfa0;
  lh = (_LHASH *)DAT_0008bfa0[2];
  if (lh != (_LHASH *)0x0) {
    uVar2 = lh->down_load;
    lh->down_load = 0;
    func = DAT_0008bfa4;
    pp_Var1[1] = (_STACK *)type;
    lh_doall(lh,func);
    if (-1 < type) {
      lh = (_LHASH *)pp_Var1[2];
    }
    if (-1 >= type) {
      lh_free((_LHASH *)pp_Var1[2]);
      sk_pop_free(*pp_Var1,DAT_0008bfa8);
      pp_Var1[2] = (_STACK *)0x0;
      *pp_Var1 = (_STACK *)0x0;
      return;
    }
    lh->down_load = uVar2;
  }
  return;
}

