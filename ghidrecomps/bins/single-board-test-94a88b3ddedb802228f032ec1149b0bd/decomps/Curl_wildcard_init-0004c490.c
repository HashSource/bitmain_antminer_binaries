
undefined4 Curl_wildcard_init(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Curl_llist_alloc(DAT_0004c4a8);
  *(int *)(param_1 + 0xc) = iVar1;
  if (iVar1 == 0) {
    uVar2 = 0x1b;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

