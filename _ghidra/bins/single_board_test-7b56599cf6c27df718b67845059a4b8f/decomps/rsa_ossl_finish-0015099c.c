
undefined4 rsa_ossl_finish(int param_1)

{
  int iVar1;
  int iVar2;
  
  BN_MONT_CTX_free(*(BN_MONT_CTX **)(param_1 + 0x44));
  BN_MONT_CTX_free(*(BN_MONT_CTX **)(param_1 + 0x48));
  BN_MONT_CTX_free(*(BN_MONT_CTX **)(param_1 + 0x4c));
  iVar2 = 0;
  while( true ) {
    iVar1 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 0x30));
    if (iVar1 <= iVar2) break;
    iVar1 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar2);
    BN_MONT_CTX_free(*(BN_MONT_CTX **)(iVar1 + 0x10));
    iVar2 = iVar2 + 1;
  }
  return 1;
}

