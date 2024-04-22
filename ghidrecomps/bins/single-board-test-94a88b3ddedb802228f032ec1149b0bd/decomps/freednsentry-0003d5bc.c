
void freednsentry(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[2];
  param_1[2] = iVar1 + -1;
  if (iVar1 + -1 == 0) {
    Curl_freeaddrinfo(*param_1);
    (**DAT_0003d5d8)(param_1);
  }
  return;
}

