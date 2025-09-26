
int X509_LOOKUP_by_subject(X509_LOOKUP *ctx,int type,X509_NAME *name,X509_OBJECT *ret)

{
  int iVar1;
  _func_1981 *UNRECOVERED_JUMPTABLE;
  
  if (((ctx->method != (X509_LOOKUP_METHOD *)0x0) &&
      (UNRECOVERED_JUMPTABLE = ctx->method->get_by_subject,
      UNRECOVERED_JUMPTABLE != (_func_1981 *)0x0)) && (ctx->skip == 0)) {
                    /* WARNING: Could not recover jumptable at 0x001709e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)(ctx,type,name,ret);
    return iVar1;
  }
  return 0;
}

