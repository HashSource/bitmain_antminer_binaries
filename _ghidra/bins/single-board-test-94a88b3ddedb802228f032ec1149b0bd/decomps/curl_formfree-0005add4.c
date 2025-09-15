
void curl_formfree(int *param_1)

{
  uint uVar1;
  int *piVar2;
  
  if (param_1 != (int *)0x0) {
    do {
      piVar2 = (int *)*param_1;
      curl_formfree(param_1[9]);
      uVar1 = param_1[10];
      if (-1 < (int)(uVar1 << 0x1d)) {
        (*Curl_cfree)(param_1[1]);
        uVar1 = param_1[10];
      }
      if ((uVar1 & 0x58) == 0) {
        (*Curl_cfree)(param_1[3]);
      }
      (*Curl_cfree)(param_1[7]);
      (*Curl_cfree)(param_1[0xb]);
      (*Curl_cfree)(param_1);
      param_1 = piVar2;
    } while (piVar2 != (int *)0x0);
  }
  return;
}

