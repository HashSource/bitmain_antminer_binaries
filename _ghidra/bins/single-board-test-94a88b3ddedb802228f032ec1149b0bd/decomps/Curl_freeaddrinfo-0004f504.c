
void Curl_freeaddrinfo(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    do {
      (*Curl_cfree)(*(undefined4 *)(param_1 + 0x18));
      (*Curl_cfree)(*(undefined4 *)(param_1 + 0x14));
      iVar1 = *(int *)(param_1 + 0x1c);
      (*Curl_cfree)(param_1);
      param_1 = iVar1;
    } while (iVar1 != 0);
  }
  return;
}

