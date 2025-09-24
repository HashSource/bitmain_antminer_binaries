
uint cmd_PrivateKey(int *param_1,char *param_2)

{
  int iVar1;
  
  if (-1 < *param_1 << 0x1a) {
    return 0xfffffffe;
  }
  if ((SSL_CTX *)param_1[3] == (SSL_CTX *)0x0) {
    iVar1 = 1;
  }
  else {
    iVar1 = SSL_CTX_use_PrivateKey_file((SSL_CTX *)param_1[3],param_2,1);
  }
  if ((SSL *)param_1[4] != (SSL *)0x0) {
    iVar1 = SSL_use_PrivateKey_file((SSL *)param_1[4],param_2,1);
  }
  return (uint)(0 < iVar1);
}

