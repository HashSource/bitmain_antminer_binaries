
long DSO_ctrl(DSO *dso,int cmd,long larg,void *parg)

{
  int iVar1;
  DSO_FUNC_TYPE pDVar2;
  _func_3877 *UNRECOVERED_JUMPTABLE;
  
  if (dso == (DSO *)0x0) {
    ERR_put_error(0x25,0x6e,0x43,"crypto/dso/dso_lib.c",0xcd);
    iVar1 = -1;
  }
  else {
    if (cmd == 2) {
      dso->flags = larg;
      return 0;
    }
    if (cmd == 3) {
      iVar1 = 0;
      dso->flags = larg | dso->flags;
    }
    else if (cmd == 1) {
      iVar1 = dso->flags;
    }
    else {
      if ((dso->meth != (DSO_METHOD *)0x0) &&
         (UNRECOVERED_JUMPTABLE = dso->meth->dso_bind_func,
         UNRECOVERED_JUMPTABLE != (_func_3877 *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001155c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        pDVar2 = (*UNRECOVERED_JUMPTABLE)(dso,(char *)cmd);
        return (long)pDVar2;
      }
      ERR_put_error(0x25,0x6e,0x6c,"crypto/dso/dso_lib.c",0xe1);
      iVar1 = -1;
    }
  }
  return iVar1;
}

