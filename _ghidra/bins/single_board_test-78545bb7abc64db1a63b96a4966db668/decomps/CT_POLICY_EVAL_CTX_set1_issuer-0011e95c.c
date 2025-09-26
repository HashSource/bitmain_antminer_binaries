
int CT_POLICY_EVAL_CTX_set1_issuer(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = X509_up_ref(param_2);
  if (iVar1 != 0) {
    iVar1 = 1;
    *(undefined4 *)(param_1 + 4) = param_2;
  }
  return iVar1;
}

