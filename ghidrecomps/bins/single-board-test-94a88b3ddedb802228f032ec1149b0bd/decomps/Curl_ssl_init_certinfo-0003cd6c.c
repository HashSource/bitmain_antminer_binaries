
undefined4 Curl_ssl_init_certinfo(int param_1,undefined4 param_2)

{
  int iVar1;
  
  Curl_ssl_free_certinfo();
  iVar1 = (**DAT_0003cd98)(param_2,4);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x878c) = param_2;
    *(int *)(param_1 + 0x8790) = iVar1;
    return 0;
  }
  return 0x1b;
}

