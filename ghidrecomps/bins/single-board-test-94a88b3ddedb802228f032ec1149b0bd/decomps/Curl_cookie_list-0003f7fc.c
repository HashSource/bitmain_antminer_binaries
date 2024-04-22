
int * Curl_cookie_list(int param_1)

{
  int iVar1;
  int **ppiVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  ppiVar2 = *(int ***)(param_1 + 0x468);
  if (ppiVar2 == (int **)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = ppiVar2[3];
    if (piVar4 != (int *)0x0) {
      piVar3 = *ppiVar2;
      if (piVar3 == (int *)0x0) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar5 = (int *)0x0;
        do {
          piVar4 = piVar5;
          if (piVar3[5] != 0) {
            iVar1 = get_netscape_format(piVar3);
            if (iVar1 == 0) {
              curl_slist_free_all(piVar5,0);
              return (int *)0x0;
            }
            piVar4 = (int *)Curl_slist_append_nodup();
            if (piVar4 == (int *)0x0) {
              (**DAT_0003f860)(iVar1);
              curl_slist_free_all(piVar5);
              return (int *)0x0;
            }
          }
          piVar3 = (int *)*piVar3;
          piVar5 = piVar4;
        } while (piVar3 != (int *)0x0);
      }
    }
  }
  return piVar4;
}

