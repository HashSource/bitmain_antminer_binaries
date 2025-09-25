
int EVP_PKEY_CTX_ctrl_str(EVP_PKEY_CTX *ctx,char *type,char *value)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (((ctx != (EVP_PKEY_CTX *)0x0) && (*(int *)ctx != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(int *)ctx + 0x68), UNRECOVERED_JUMPTABLE != (code *)0x0))
  {
    iVar1 = strcmp(type,"digest");
    if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0012f512. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)(ctx,type,value);
      return iVar1;
    }
    iVar1 = EVP_PKEY_CTX_md(ctx,0xf8,1,value);
    return iVar1;
  }
  ERR_put_error(6,0x96,0x93,"crypto/evp/pmeth_lib.c",0x19b);
  return -2;
}

