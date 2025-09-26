
int RSA_set_method(RSA *rsa,RSA_METHOD *meth)

{
  _func_1767 *p_Var1;
  _func_1766 *p_Var2;
  
  p_Var1 = rsa->meth->finish;
  if (p_Var1 != (_func_1767 *)0x0) {
    (*p_Var1)(rsa);
  }
  ENGINE_finish(rsa->engine);
  p_Var2 = meth->init;
  rsa->meth = meth;
  rsa->engine = (ENGINE *)0x0;
  if (p_Var2 != (_func_1766 *)0x0) {
    (*p_Var2)(rsa);
  }
  return 1;
}

