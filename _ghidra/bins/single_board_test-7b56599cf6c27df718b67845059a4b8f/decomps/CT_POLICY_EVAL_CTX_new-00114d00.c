
int CT_POLICY_EVAL_CTX_new(void)

{
  int iVar1;
  time_t tVar2;
  
  iVar1 = CRYPTO_zalloc(0x18,"crypto/ct/ct_policy.c",0x1e);
  if (iVar1 == 0) {
    ERR_put_error(0x32,0x85,0x41,"crypto/ct/ct_policy.c",0x21);
  }
  else {
    tVar2 = time((time_t *)0x0);
    *(longlong *)(iVar1 + 0x10) = (longlong)(tVar2 + 300) * 1000;
  }
  return iVar1;
}

