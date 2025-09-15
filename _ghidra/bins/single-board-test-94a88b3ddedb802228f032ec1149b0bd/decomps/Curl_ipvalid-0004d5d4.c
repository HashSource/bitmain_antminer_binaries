
undefined4 Curl_ipvalid(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x220) != 2) {
    return 1;
  }
  uVar1 = Curl_ipv6works();
  return uVar1;
}

