
void Curl_cookie_clearsess(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  if ((param_1 != (undefined4 *)0x0) &&
     (piVar2 = (int *)*param_1, piVar3 = piVar2, piVar4 = piVar2, piVar2 != (int *)0x0)) {
    do {
      piVar1 = (int *)*piVar2;
      piVar5 = piVar2;
      if (piVar2[6] == 0 && piVar2[7] == 0) {
        if (piVar3 == piVar2) {
          piVar3 = piVar1;
        }
        piVar5 = piVar1;
        if (piVar4 != piVar2) {
          *piVar4 = (int)piVar1;
          piVar5 = piVar4;
        }
        freecookie();
        param_1[3] = param_1[3] + -1;
      }
      piVar2 = piVar1;
      piVar4 = piVar5;
    } while (piVar1 != (int *)0x0);
    *param_1 = piVar3;
  }
  return;
}

