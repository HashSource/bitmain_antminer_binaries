
void Curl_cookie_clearall(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    Curl_cookie_freelist(*param_1,1);
    *param_1 = 0;
    param_1[3] = 0;
  }
  return;
}

