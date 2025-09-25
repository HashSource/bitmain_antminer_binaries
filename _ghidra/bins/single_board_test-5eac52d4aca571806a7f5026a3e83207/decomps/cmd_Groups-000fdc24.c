
bool cmd_Groups(int param_1,void *param_2)

{
  int iVar1;
  
  if (*(SSL **)(param_1 + 0x10) == (SSL *)0x0) {
    iVar1 = SSL_CTX_ctrl(*(SSL_CTX **)(param_1 + 0xc),0x5c,0,param_2);
  }
  else {
    iVar1 = SSL_ctrl(*(SSL **)(param_1 + 0x10),0x5c,0,param_2);
  }
  return 0 < iVar1;
}

