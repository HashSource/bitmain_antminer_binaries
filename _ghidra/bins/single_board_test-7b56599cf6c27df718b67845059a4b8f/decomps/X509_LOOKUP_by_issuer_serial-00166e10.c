
int X509_LOOKUP_by_issuer_serial
              (X509_LOOKUP *ctx,int type,X509_NAME *name,ASN1_INTEGER *serial,X509_OBJECT *ret)

{
  int iVar1;
  _func_1982 *UNRECOVERED_JUMPTABLE;
  
  if ((ctx->method != (X509_LOOKUP_METHOD *)0x0) &&
     (UNRECOVERED_JUMPTABLE = ctx->method->get_by_issuer_serial,
     UNRECOVERED_JUMPTABLE != (_func_1982 *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00166e1e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)(ctx,type,name,serial,ret);
    return iVar1;
  }
  return 0;
}

