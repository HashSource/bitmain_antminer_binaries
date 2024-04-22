
void int_engine_module_finish(void)

{
  _STACK **pp_Var1;
  _STACK **pp_Var2;
  ENGINE *e;
  
  pp_Var1 = DAT_00101d04;
  while( true ) {
    e = (ENGINE *)sk_pop(*pp_Var1);
    pp_Var2 = DAT_00101d04;
    if (e == (ENGINE *)0x0) break;
    ENGINE_finish(e);
  }
  sk_free(*DAT_00101d04);
  *pp_Var2 = (_STACK *)0x0;
  return;
}

