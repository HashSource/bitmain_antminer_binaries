
void ssl_cert_set_default_md(int param_1)

{
  EVP_MD *pEVar1;
  
  pEVar1 = EVP_sha1();
  *(EVP_MD **)(param_1 + 0x7c) = pEVar1;
  pEVar1 = EVP_sha1();
  *(EVP_MD **)(param_1 + 0x60) = pEVar1;
  pEVar1 = EVP_sha1();
  *(EVP_MD **)(param_1 + 0x44) = pEVar1;
  pEVar1 = EVP_sha1();
  *(EVP_MD **)(param_1 + 0xd0) = pEVar1;
  return;
}

