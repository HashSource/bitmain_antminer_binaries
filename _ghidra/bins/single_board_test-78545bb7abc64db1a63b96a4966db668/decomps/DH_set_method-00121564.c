
int DH_set_method(DH *dh,DH_METHOD *meth)

{
  code *pcVar1;
  _func_1846 *p_Var2;
  
  pcVar1 = *(code **)((dh->ex_data).dummy + 0x14);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)();
  }
  ENGINE_finish((ENGINE *)dh->meth);
  p_Var2 = meth->init;
  (dh->ex_data).dummy = (int)meth;
  dh->meth = (DH_METHOD *)0x0;
  if (p_Var2 != (_func_1846 *)0x0) {
    (*p_Var2)(dh);
  }
  return 1;
}

