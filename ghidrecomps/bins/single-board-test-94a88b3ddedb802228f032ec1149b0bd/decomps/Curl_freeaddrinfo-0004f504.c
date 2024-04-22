
void Curl_freeaddrinfo(int param_1)

{
  code **ppcVar1;
  int iVar2;
  
  ppcVar1 = DAT_0004f528;
  if (param_1 != 0) {
    do {
      (**ppcVar1)(*(undefined4 *)(param_1 + 0x18));
      (**ppcVar1)(*(undefined4 *)(param_1 + 0x14));
      iVar2 = *(int *)(param_1 + 0x1c);
      (**ppcVar1)(param_1);
      param_1 = iVar2;
    } while (iVar2 != 0);
  }
  return;
}

