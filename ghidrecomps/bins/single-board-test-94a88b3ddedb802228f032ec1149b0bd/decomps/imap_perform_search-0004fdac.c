
int imap_perform_search(int *param_1)

{
  int iVar1;
  
  if (*(int *)(*(int *)(*param_1 + 0x14c) + 0x18) != 0) {
    iVar1 = imap_sendf(param_1,DAT_0004fdd8);
    if (iVar1 == 0) {
      param_1[0xfe] = 0xd;
    }
    return iVar1;
  }
  Curl_failf(*param_1,DAT_0004fddc);
  return 3;
}

