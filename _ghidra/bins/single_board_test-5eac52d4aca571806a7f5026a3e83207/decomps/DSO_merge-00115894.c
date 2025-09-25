
char * DSO_merge(DSO *dso,char *filespec1,char *filespec2)

{
  char *pcVar1;
  DSO_NAME_CONVERTER_FUNC UNRECOVERED_JUMPTABLE;
  
  if (filespec1 == (char *)0x0 || dso == (DSO *)0x0) {
    ERR_put_error(0x25,0x84,0x43,"crypto/dso/dso_lib.c",0x10c);
  }
  else if ((-1 < dso->flags << 0x1f) &&
          ((UNRECOVERED_JUMPTABLE = dso->name_converter,
           UNRECOVERED_JUMPTABLE != (DSO_NAME_CONVERTER_FUNC)0x0 ||
           (UNRECOVERED_JUMPTABLE = dso->meth->dso_name_converter,
           UNRECOVERED_JUMPTABLE != (DSO_NAME_CONVERTER_FUNC)0x0)))) {
                    /* WARNING: Could not recover jumptable at 0x001158b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar1 = (*UNRECOVERED_JUMPTABLE)(dso,filespec1);
    return pcVar1;
  }
  return (char *)0x0;
}

