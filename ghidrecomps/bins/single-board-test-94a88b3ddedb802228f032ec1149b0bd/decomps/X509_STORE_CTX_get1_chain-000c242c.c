
stack_st_X509 * X509_STORE_CTX_get1_chain(X509_STORE_CTX *ctx)

{
  stack_st_X509 *psVar1;
  
  if (ctx->chain != (stack_st_X509 *)0x0) {
    psVar1 = (stack_st_X509 *)X509_chain_up_ref();
    return psVar1;
  }
  return (stack_st_X509 *)0x0;
}

