
int Curl_cookie_list(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar2 = *(int **)(param_1 + 0x468);
  if (piVar2 == (int *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = piVar2[3];
    if (iVar3 != 0) {
      piVar2 = (int *)*piVar2;
      if (piVar2 == (int *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar4 = 0;
        do {
          iVar3 = iVar4;
          if (piVar2[5] != 0) {
            iVar1 = get_netscape_format(piVar2);
            if (iVar1 == 0) {
              curl_slist_free_all(iVar4,0);
              return 0;
            }
            iVar3 = Curl_slist_append_nodup();
            if (iVar3 == 0) {
              (*Curl_cfree)(iVar1);
              curl_slist_free_all(iVar4);
              return 0;
            }
          }
          piVar2 = (int *)*piVar2;
          iVar4 = iVar3;
        } while (piVar2 != (int *)0x0);
      }
    }
  }
  return iVar3;
}

