
undefined4 Curl_chunked_strerror(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_0004c86c;
  if (param_1 - 1U < 6) {
    uVar1 = *(undefined4 *)(DAT_0004c868 + (param_1 - 1U) * 4);
  }
  return uVar1;
}

