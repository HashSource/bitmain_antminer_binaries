
void Curl_cookie_freelist(int *param_1,int param_2)

{
  int *piVar1;
  
  if (param_1 != (int *)0x0) {
    do {
      while (piVar1 = (int *)*param_1, param_2 != 0) {
        freecookie(param_1);
        param_1 = piVar1;
        if (piVar1 == (int *)0x0) {
          return;
        }
      }
      (*Curl_cfree)(param_1);
      param_1 = piVar1;
    } while (piVar1 != (int *)0x0);
  }
  return;
}

