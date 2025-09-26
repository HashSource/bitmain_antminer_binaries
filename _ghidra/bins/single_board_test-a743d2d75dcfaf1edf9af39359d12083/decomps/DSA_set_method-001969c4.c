
int DSA_set_method(DSA *dsa,DSA_METHOD *param_2)

{
  _func_1881 *p_Var1;
  _func_1880 *p_Var2;
  
  p_Var1 = dsa->meth->finish;
  if (p_Var1 != (_func_1881 *)0x0) {
    (*p_Var1)(dsa);
  }
  if (dsa->engine != (ENGINE *)0x0) {
    ENGINE_finish(dsa->engine);
    dsa->engine = (ENGINE *)0x0;
  }
  p_Var2 = param_2->init;
  dsa->meth = param_2;
  if (p_Var2 != (_func_1880 *)0x0) {
    (*p_Var2)(dsa);
  }
  return 1;
}

