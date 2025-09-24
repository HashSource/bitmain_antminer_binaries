
bool cmd_CipherString(int param_1,char *param_2)

{
  int iVar1;
  
  if (*(SSL_CTX **)(param_1 + 0xc) == (SSL_CTX *)0x0) {
    iVar1 = 1;
  }
  else {
    iVar1 = SSL_CTX_set_cipher_list(*(SSL_CTX **)(param_1 + 0xc),param_2);
  }
  if (*(SSL **)(param_1 + 0x10) != (SSL *)0x0) {
    iVar1 = SSL_set_cipher_list(*(SSL **)(param_1 + 0x10),param_2);
  }
  return 0 < iVar1;
}

