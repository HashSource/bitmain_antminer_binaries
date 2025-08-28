
void Curl_cookie_cleanup(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    (*Curl_cfree)(param_1[1]);
    Curl_cookie_freelist(*param_1,1);
    (*Curl_cfree)(param_1);
  }
  return;
}

