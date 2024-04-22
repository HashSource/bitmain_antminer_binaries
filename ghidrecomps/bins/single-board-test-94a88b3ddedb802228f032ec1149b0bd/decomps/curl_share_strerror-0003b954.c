
undefined4 curl_share_strerror(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_0003b96c;
  if (param_1 < 6) {
    uVar1 = *(undefined4 *)(DAT_0003b968 + param_1 * 4 + 0x194);
  }
  return uVar1;
}

