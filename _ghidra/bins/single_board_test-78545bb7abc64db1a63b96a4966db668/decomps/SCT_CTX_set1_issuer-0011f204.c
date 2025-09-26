
void SCT_CTX_set1_issuer(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = X509_get_X509_PUBKEY(param_2);
  SCT_CTX_set1_issuer_pubkey(param_1,uVar1);
  return;
}

