
int Curl_num_addresses(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = 0;
    do {
      param_1 = *(int *)(param_1 + 0x1c);
      iVar1 = iVar1 + 1;
    } while (param_1 != 0);
    return iVar1;
  }
  return 0;
}

