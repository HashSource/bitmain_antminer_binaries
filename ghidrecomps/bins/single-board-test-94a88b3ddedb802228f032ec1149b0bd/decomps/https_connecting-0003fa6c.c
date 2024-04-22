
void https_connecting(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = Curl_ssl_connect_nonblocking(param_1,0,param_2);
  if (iVar1 != 0) {
    *(undefined *)(param_1 + 0x1ed) = 1;
  }
  return;
}

