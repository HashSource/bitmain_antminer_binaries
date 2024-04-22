
long DSO_ctrl(DSO *dso,int cmd,long larg,void *parg)

{
  long lVar1;
  _func_3878 *p_Var2;
  
  if (dso == (DSO *)0x0) {
    ERR_put_error(0x25,0x6e,0x43,DAT_0010166c,0x127);
    lVar1 = -1;
  }
  else if (cmd == 2) {
    dso->flags = larg;
    lVar1 = 0;
  }
  else if (cmd == 3) {
    lVar1 = 0;
    dso->flags = dso->flags | larg;
  }
  else if (cmd == 1) {
    lVar1 = dso->flags;
  }
  else if ((dso->meth == (DSO_METHOD *)0x0) ||
          (p_Var2 = dso->meth->dso_ctrl, p_Var2 == (_func_3878 *)0x0)) {
    ERR_put_error(0x25,0x6e,0x6c,DAT_0010166c,0x13b);
    lVar1 = -1;
  }
  else {
    lVar1 = (*p_Var2)(dso,cmd,larg,parg);
  }
  return lVar1;
}

