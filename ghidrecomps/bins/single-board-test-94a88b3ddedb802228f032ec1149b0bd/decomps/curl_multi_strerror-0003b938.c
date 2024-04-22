
undefined4 curl_multi_strerror(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_0003b950;
  if (param_1 + 1U < 9) {
    uVar1 = *(undefined4 *)(DAT_0003b94c + (param_1 + 1U) * 4 + 0x170);
  }
  return uVar1;
}

