
void Curl_cookie_freelist(int *param_1,int param_2)

{
  code **ppcVar1;
  int *piVar2;
  
  ppcVar1 = DAT_0003f5c0;
  if (param_1 != (int *)0x0) {
    do {
      while (piVar2 = (int *)*param_1, param_2 != 0) {
        freecookie(param_1);
        param_1 = piVar2;
        if (piVar2 == (int *)0x0) {
          return;
        }
      }
      (**ppcVar1)(param_1);
      param_1 = piVar2;
    } while (piVar2 != (int *)0x0);
  }
  return;
}

