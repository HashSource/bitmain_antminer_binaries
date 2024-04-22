
void Curl_cookie_clearsess(int **param_1)

{
  int **ppiVar1;
  int **ppiVar2;
  int **ppiVar3;
  int **ppiVar4;
  int **ppiVar5;
  
  if ((param_1 != (int **)0x0) &&
     (ppiVar2 = (int **)*param_1, ppiVar3 = ppiVar2, ppiVar4 = ppiVar2, ppiVar2 != (int **)0x0)) {
    do {
      ppiVar1 = (int **)*ppiVar2;
      ppiVar5 = ppiVar2;
      if (((uint)ppiVar2[6] | (uint)ppiVar2[7]) == 0) {
        if (ppiVar3 == ppiVar2) {
          ppiVar3 = ppiVar1;
        }
        ppiVar5 = ppiVar1;
        if (ppiVar4 != ppiVar2) {
          *ppiVar4 = (int *)ppiVar1;
          ppiVar5 = ppiVar4;
        }
        freecookie();
        param_1[3] = (int *)((int)param_1[3] + -1);
      }
      ppiVar2 = ppiVar1;
      ppiVar4 = ppiVar5;
    } while (ppiVar1 != (int **)0x0);
    *param_1 = (int *)ppiVar3;
  }
  return;
}

