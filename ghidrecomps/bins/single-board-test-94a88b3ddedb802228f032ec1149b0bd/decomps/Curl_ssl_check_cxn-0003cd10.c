
int Curl_ssl_check_cxn(int param_1)

{
  int iVar1;
  undefined auStack_9 [9];
  
  iVar1 = SSL_peek(*(SSL **)(param_1 + 0x188),auStack_9,1);
  if (iVar1 < 1) {
    if (iVar1 != 0) {
      iVar1 = -1;
    }
  }
  else {
    iVar1 = 1;
  }
  return iVar1;
}

