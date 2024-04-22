
undefined4 curl_easy_strerror(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_0003b934;
  if (param_1 < 0x5c) {
    uVar1 = *(undefined4 *)(DAT_0003b930 + param_1 * 4);
  }
  return uVar1;
}

