
char * DSO_convert_filename(DSO *dso,char *filename)

{
  char *pcVar1;
  long in_r2;
  _func_3878 *parg;
  
  if (dso == (DSO *)0x0) {
    ERR_put_error(0x25,0x7e,0x43,"crypto/dso/dso_lib.c",0x11d);
    pcVar1 = (char *)0x0;
  }
  else if ((filename == (char *)0x0) &&
          (filename = (char *)dso->merger, (DSO_MERGER_FUNC)filename == (DSO_MERGER_FUNC)0x0)) {
    ERR_put_error(0x25,0x7e,0x6f,"crypto/dso/dso_lib.c",0x123);
    pcVar1 = (char *)0x0;
  }
  else if (((dso->flags << 0x1f < 0) ||
           (((parg = (_func_3878 *)(dso->ex_data).dummy, parg == (_func_3878 *)0x0 &&
             (parg = dso->meth->dso_ctrl, parg == (_func_3878 *)0x0)) ||
            (pcVar1 = (char *)(*parg)(dso,(int)filename,in_r2,parg), pcVar1 == (char *)0x0)))) &&
          (pcVar1 = CRYPTO_strdup(filename,"crypto/dso/dso_lib.c",0x12d), pcVar1 == (char *)0x0)) {
    ERR_put_error(0x25,0x7e,0x41,"crypto/dso/dso_lib.c",0x12f);
  }
  return pcVar1;
}

