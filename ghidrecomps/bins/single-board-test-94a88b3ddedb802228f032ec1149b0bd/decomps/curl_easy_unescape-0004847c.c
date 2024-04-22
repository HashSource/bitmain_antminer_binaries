
undefined4 curl_easy_unescape(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *in_r3;
  undefined4 local_1c;
  
  iVar1 = Curl_urldecode();
  if ((iVar1 == 0) && (in_r3 != (undefined4 *)0x0)) {
    uVar2 = curlx_uztosi(local_1c);
    *in_r3 = uVar2;
  }
  return 0;
}

