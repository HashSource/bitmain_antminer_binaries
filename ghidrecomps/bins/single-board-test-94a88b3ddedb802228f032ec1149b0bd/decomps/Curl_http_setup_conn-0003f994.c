
undefined4 Curl_http_setup_conn(int *param_1)

{
  int iVar1;
  
  iVar1 = (**DAT_0003f9b4)(1,0x60);
  if (iVar1 != 0) {
    *(int *)(*param_1 + 0x14c) = iVar1;
    return 0;
  }
  return 0x1b;
}

