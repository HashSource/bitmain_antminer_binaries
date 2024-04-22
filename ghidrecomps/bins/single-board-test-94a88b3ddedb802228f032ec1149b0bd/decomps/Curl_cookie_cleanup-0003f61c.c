
void Curl_cookie_cleanup(undefined4 *param_1)

{
  code **ppcVar1;
  
  ppcVar1 = DAT_0003f63c;
  if (param_1 != (undefined4 *)0x0) {
    (**DAT_0003f63c)(param_1[1]);
    Curl_cookie_freelist(*param_1,1);
    (**ppcVar1)(param_1);
  }
  return;
}

