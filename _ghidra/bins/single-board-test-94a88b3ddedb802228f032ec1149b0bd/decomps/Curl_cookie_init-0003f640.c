
int Curl_cookie_init(undefined4 param_1,char *param_2,int param_3,undefined1 param_4)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  FILE *__stream;
  int iVar6;
  
  iVar6 = param_3;
  if (param_3 == 0) {
    iVar6 = (*Curl_ccalloc)(1,0x14);
    if (iVar6 != 0) {
      pcVar4 = "none";
      if (param_2 != (char *)0x0) {
        pcVar4 = param_2;
      }
      iVar3 = (*Curl_cstrdup)(pcVar4);
      *(int *)(iVar6 + 4) = iVar3;
      if (iVar3 != 0) goto LAB_0003f654;
      (*Curl_cfree)();
      __stream = (FILE *)0x0;
      bVar2 = false;
LAB_0003f766:
      Curl_cookie_cleanup(iVar6);
LAB_0003f728:
      if (bVar2) {
        fclose(__stream);
        return 0;
      }
    }
    iVar6 = 0;
  }
  else {
LAB_0003f654:
    bVar2 = false;
    *(undefined1 *)(iVar6 + 8) = 0;
    if (param_2 == (char *)0x0) {
LAB_0003f6e8:
      *(undefined1 *)(iVar6 + 0x10) = param_4;
    }
    else {
      iVar3 = curl_strequal(param_2,"-");
      __stream = stdin;
      if (iVar3 == 0) {
        if (*param_2 == '\0') goto LAB_0003f6e8;
        __stream = fopen64(param_2,"r");
        bVar2 = true;
      }
      *(undefined1 *)(iVar6 + 0x10) = param_4;
      if (__stream != (FILE *)0x0) {
        pcVar4 = (char *)(*Curl_cmalloc)(5000);
        if (pcVar4 == (char *)0x0) {
          (*Curl_cfree)();
          if (param_3 == 0) goto LAB_0003f766;
          goto LAB_0003f728;
        }
        while (pcVar5 = fgets(pcVar4,5000,__stream), pcVar5 != (char *)0x0) {
          iVar3 = Curl_raw_nequal("Set-Cookie:",pcVar4,0xb);
          pcVar5 = pcVar4 + 0xb;
          if (iVar3 == 0) {
            pcVar5 = pcVar4;
          }
          cVar1 = *pcVar5;
          if ((cVar1 != '\0') && (cVar1 == '\t' || cVar1 == ' ')) {
            do {
              pcVar5 = pcVar5 + 1;
              cVar1 = *pcVar5;
              if (cVar1 == '\0') break;
            } while (cVar1 == ' ' || cVar1 == '\t');
          }
          Curl_cookie_add(param_1,iVar6,iVar3 != 0,pcVar5,0,0);
        }
        (*Curl_cfree)(pcVar4);
        if (bVar2) {
          fclose(__stream);
        }
      }
    }
    *(undefined1 *)(iVar6 + 8) = 1;
  }
  return iVar6;
}

