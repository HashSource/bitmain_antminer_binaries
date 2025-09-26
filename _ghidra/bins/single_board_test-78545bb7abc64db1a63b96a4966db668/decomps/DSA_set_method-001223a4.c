
int DSA_set_method(DSA *dsa,DSA_METHOD *param_2)

{
  code *pcVar1;
  _func_1880 *p_Var2;
  
  pcVar1 = (code *)(dsa->method_mont_p->N).top;
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)();
  }
  ENGINE_finish((ENGINE *)dsa->references);
  p_Var2 = param_2->init;
  dsa->method_mont_p = (BN_MONT_CTX *)param_2;
  dsa->references = 0;
  if (p_Var2 != (_func_1880 *)0x0) {
    (*p_Var2)(dsa);
  }
  return 1;
}

