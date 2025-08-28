
void Curl_formclean(int *param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    do {
      piVar2 = (int *)*piVar1;
      if ((uint)piVar1[1] < 2) {
        (*Curl_cfree)(piVar1[2]);
      }
      (*Curl_cfree)(piVar1);
      piVar1 = piVar2;
    } while (piVar2 != (int *)0x0);
    *param_1 = 0;
  }
  return;
}

