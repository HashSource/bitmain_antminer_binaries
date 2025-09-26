
bool eof_PKCS12(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = OPENSSL_sk_num();
    return iVar1 == 0;
  }
  return true;
}

