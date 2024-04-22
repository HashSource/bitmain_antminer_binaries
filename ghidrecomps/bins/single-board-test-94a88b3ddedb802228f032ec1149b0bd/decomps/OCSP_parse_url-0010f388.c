
int OCSP_parse_url(char *url,char **phost,char **pport,char **ppath,int *pssl)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *__s;
  
  *phost = (char *)0x0;
  *pport = (char *)0x0;
  *ppath = (char *)0x0;
  pcVar1 = BUF_strdup(url);
  if (pcVar1 == (char *)0x0) {
    ERR_put_error(0x27,0x72,0x41,DAT_0010f4d8,0x10f);
    goto LAB_0010f3ec;
  }
  pcVar2 = strchr(pcVar1,0x3a);
  if (pcVar2 == (char *)0x0) {
LAB_0010f3d4:
    ERR_put_error(0x27,0x72,0x79,DAT_0010f4d8,0x113);
  }
  else {
    *pcVar2 = '\0';
    iVar3 = strcmp(pcVar1,DAT_0010f4d0);
    if (iVar3 == 0) {
      *pssl = 0;
      if (pcVar2[1] == '/') goto LAB_0010f418;
      goto LAB_0010f3d4;
    }
    iVar3 = strcmp(pcVar1,DAT_0010f4d4);
    if ((iVar3 != 0) || (*pssl = 1, pcVar2[1] != '/')) goto LAB_0010f3d4;
LAB_0010f418:
    if (pcVar2[2] != '/') goto LAB_0010f3d4;
    __s = pcVar2 + 3;
    pcVar4 = strchr(__s,0x2f);
    if (pcVar4 == (char *)0x0) {
      pcVar4 = BUF_strdup(DAT_0010f4dc);
      *ppath = pcVar4;
    }
    else {
      pcVar5 = BUF_strdup(pcVar4);
      *ppath = pcVar5;
      *pcVar4 = '\0';
      pcVar4 = *ppath;
    }
    if (pcVar4 != (char *)0x0) {
      pcVar4 = __s;
      if (pcVar2[3] == '[') {
        pcVar4 = strchr(pcVar2 + 4,0x5d);
        if (pcVar4 == (char *)0x0) goto LAB_0010f3d4;
        __s = pcVar4 + 1;
        *pcVar4 = '\0';
        pcVar4 = pcVar2 + 4;
      }
      pcVar2 = strchr(__s,0x3a);
      if (pcVar2 == (char *)0x0) {
        pcVar2 = DAT_0010f4e0;
        if (*pssl != 0) {
          pcVar2 = DAT_0010f4e4;
        }
      }
      else {
        *pcVar2 = '\0';
        pcVar2 = pcVar2 + 1;
      }
      pcVar2 = BUF_strdup(pcVar2);
      *pport = pcVar2;
      if (pcVar2 != (char *)0x0) {
        pcVar2 = BUF_strdup(pcVar4);
        *phost = pcVar2;
        if (pcVar2 != (char *)0x0) {
          CRYPTO_free(pcVar1);
          return 1;
        }
      }
    }
    ERR_put_error(0x27,0x72,0x41,DAT_0010f4d8,0x10f);
  }
  CRYPTO_free(pcVar1);
LAB_0010f3ec:
  if (*ppath != (char *)0x0) {
    CRYPTO_free(*ppath);
  }
  if (*pport != (char *)0x0) {
    CRYPTO_free(*pport);
  }
  pcVar1 = *phost;
  if (pcVar1 != (char *)0x0) {
    CRYPTO_free(pcVar1);
    pcVar1 = (char *)0x0;
  }
  return (int)pcVar1;
}

