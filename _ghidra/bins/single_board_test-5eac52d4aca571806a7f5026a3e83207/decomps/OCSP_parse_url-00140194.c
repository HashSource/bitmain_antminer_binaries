
int OCSP_parse_url(char *url,char **phost,char **pport,char **ppath,int *pssl)

{
  char cVar1;
  char *__s;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *str;
  char *__s_00;
  
  *phost = (char *)0x0;
  *pport = (char *)0x0;
  *ppath = (char *)0x0;
  __s = CRYPTO_strdup(url,"crypto/ocsp/ocsp_lib.c",0x81);
  if (__s == (char *)0x0) {
LAB_001402ca:
    ERR_put_error(0x27,0x72,0x41,"crypto/ocsp/ocsp_lib.c",0xcc);
  }
  else {
    pcVar2 = strchr(__s,0x3a);
    if (pcVar2 != (char *)0x0) {
      *pcVar2 = '\0';
      iVar3 = strcmp(__s,"http");
      if (iVar3 == 0) {
        *pssl = 0;
        cVar1 = pcVar2[1];
        str = "80";
      }
      else {
        iVar3 = strcmp(__s,"https");
        if (iVar3 != 0) goto LAB_001401f0;
        *pssl = 1;
        cVar1 = pcVar2[1];
        str = "443";
      }
      if ((cVar1 == '/') && (pcVar2[2] == '/')) {
        __s_00 = pcVar2 + 3;
        pcVar4 = strchr(__s_00,0x2f);
        if (pcVar4 == (char *)0x0) {
          pcVar4 = CRYPTO_strdup("/","crypto/ocsp/ocsp_lib.c",0xa3);
          *ppath = pcVar4;
        }
        else {
          pcVar5 = CRYPTO_strdup(pcVar4,"crypto/ocsp/ocsp_lib.c",0xa5);
          *ppath = pcVar5;
          *pcVar4 = '\0';
          pcVar4 = *ppath;
        }
        if (pcVar4 != (char *)0x0) {
          pcVar4 = __s_00;
          if (pcVar2[3] == '[') {
            __s_00 = pcVar2 + 4;
            pcVar2 = strchr(__s_00,0x5d);
            if (pcVar2 == (char *)0x0) goto LAB_001401f0;
            *pcVar2 = '\0';
            pcVar4 = pcVar2 + 1;
          }
          pcVar2 = strchr(pcVar4,0x3a);
          if (pcVar2 != (char *)0x0) {
            str = pcVar2 + 1;
            *pcVar2 = '\0';
          }
          pcVar2 = CRYPTO_strdup(str,"crypto/ocsp/ocsp_lib.c",0xbe);
          *pport = pcVar2;
          if (pcVar2 != (char *)0x0) {
            pcVar2 = CRYPTO_strdup(__s_00,"crypto/ocsp/ocsp_lib.c",0xc2);
            *phost = pcVar2;
            if (pcVar2 != (char *)0x0) {
              CRYPTO_free(__s);
              return 1;
            }
          }
        }
        goto LAB_001402ca;
      }
    }
LAB_001401f0:
    ERR_put_error(0x27,0x72,0x79,"crypto/ocsp/ocsp_lib.c",0xd0);
  }
  CRYPTO_free(__s);
  CRYPTO_free(*ppath);
  *ppath = (char *)0x0;
  CRYPTO_free(*pport);
  *pport = (char *)0x0;
  CRYPTO_free(*phost);
  *phost = (char *)0x0;
  return 0;
}

