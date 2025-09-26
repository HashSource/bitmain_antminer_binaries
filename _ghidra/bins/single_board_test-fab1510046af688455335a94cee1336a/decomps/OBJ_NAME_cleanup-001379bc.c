
void OBJ_NAME_cleanup(int type)

{
  _LHASH *extraout_r3;
  _LHASH *p_Var1;
  ulong uVar2;
  
  p_Var1 = names_lh;
  if (names_lh != (_LHASH *)0x0) {
    uVar2 = names_lh->down_load;
    names_lh->down_load = 0;
    free_type = type;
    lh_doall(p_Var1,(LHASH_DOALL_FN_TYPE)0x137545);
    p_Var1 = extraout_r3;
    if (-1 < type) {
      p_Var1 = names_lh;
    }
    if (-1 >= type) {
      lh_free(names_lh);
      sk_pop_free(name_funcs_stack,(func *)0x137491);
      names_lh = (_LHASH *)0x0;
      name_funcs_stack = (_STACK *)0x0;
      return;
    }
    p_Var1->down_load = uVar2;
  }
  return;
}

