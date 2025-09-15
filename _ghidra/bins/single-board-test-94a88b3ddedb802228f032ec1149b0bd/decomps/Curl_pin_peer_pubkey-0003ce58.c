
int Curl_pin_peer_pubkey(undefined4 param_1,char *param_2,void *param_3,uint param_4)

{
  char cVar1;
  void *pvVar2;
  int iVar3;
  FILE *__stream;
  char *__haystack;
  uint uVar4;
  size_t sVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  void *local_34;
  size_t local_30;
  void *local_2c [2];
  
  local_34 = (void *)0x0;
  if (param_2 == (char *)0x0) {
    return 0;
  }
  if (param_3 == (void *)0x0 || param_4 == 0) {
    return 0x5a;
  }
  iVar3 = strncmp(param_2,"sha256//",8);
  if (iVar3 == 0) {
    iVar3 = (*Curl_cmalloc)(0x20);
    if (iVar3 == 0) {
      return 0x1b;
    }
    Curl_ossl_sha256sum(param_3,param_4,iVar3,0x20);
    iVar7 = Curl_base64_encode(param_1,iVar3,0x20,local_2c,&local_30);
    (*Curl_cfree)(iVar3);
    if (iVar7 != 0) {
      return iVar7;
    }
    Curl_infof(param_1,"\t public key hash: sha256//%s\n",local_2c[0]);
    sVar5 = strlen(param_2);
    pcVar8 = (char *)(*Curl_cmalloc)(sVar5 + 1);
    if (pcVar8 == (char *)0x0) {
      (*Curl_cfree)(local_2c[0]);
      return 0x1b;
    }
    memcpy(pcVar8,param_2,sVar5 + 1);
    pcVar6 = pcVar8;
    do {
      __haystack = strstr(pcVar6,";sha256//");
      if (__haystack != (char *)0x0) {
        *__haystack = '\0';
      }
      sVar5 = strlen(pcVar6 + 8);
      pvVar2 = local_2c[0];
      if ((sVar5 == local_30) && (iVar3 = memcmp(local_2c[0],pcVar6 + 8,sVar5), iVar3 == 0)) {
        iVar3 = 0;
        local_2c[0] = pvVar2;
        goto LAB_0003cf94;
      }
      if (__haystack == (char *)0x0) break;
      *__haystack = ';';
      pcVar6 = strstr(__haystack,"sha256//");
    } while (pcVar6 != (char *)0x0);
    iVar3 = 0x5a;
LAB_0003cf94:
    (*Curl_cfree)(local_2c[0]);
    local_2c[0] = (void *)0x0;
    (*Curl_cfree)(pcVar8);
    return iVar3;
  }
  __stream = fopen64(param_2,"rb");
  if (__stream == (FILE *)0x0) {
    return 0x5a;
  }
  iVar3 = fseek(__stream,0,2);
  if (iVar3 == 0) {
    uVar4 = ftell(__stream);
    iVar3 = fseek(__stream,0,0);
    if ((((iVar3 == 0) && (uVar4 < 0x100001)) &&
        (uVar4 = curlx_sotouz(uVar4,(int)uVar4 >> 0x1f), param_4 <= uVar4)) &&
       (pcVar8 = (char *)(*Curl_cmalloc)(uVar4 + 1), pcVar8 != (char *)0x0)) {
      sVar5 = fread(pcVar8,uVar4,1,__stream);
      if (sVar5 == 1) {
        if (param_4 == uVar4) {
          iVar3 = memcmp(param_3,pcVar8,param_4);
          if (iVar3 == 0) {
            iVar3 = 0;
          }
          else {
            iVar3 = 0x5a;
          }
          goto LAB_0003ceba;
        }
        pcVar8[uVar4] = '\0';
        pcVar6 = strstr(pcVar8,"-----BEGIN PUBLIC KEY-----");
        if ((pcVar6 != (char *)0x0) &&
           ((iVar3 = (int)pcVar6 - (int)pcVar8, iVar3 == 0 || (pcVar8[iVar3 + -1] == '\n')))) {
          uVar4 = iVar3 + 0x1a;
          pcVar6 = strstr(pcVar8 + uVar4,"\n-----END PUBLIC KEY-----");
          if (pcVar6 != (char *)0x0) {
            iVar3 = (*Curl_cmalloc)((-0x19 - iVar3) + ((int)pcVar6 - (int)pcVar8));
            if (iVar3 != 0) {
              iVar7 = 0;
              while (uVar4 < (uint)((int)pcVar6 - (int)pcVar8)) {
                cVar1 = pcVar8[uVar4];
                uVar4 = uVar4 + 1;
                if ((cVar1 != '\r') && (cVar1 != '\n')) {
                  *(char *)(iVar3 + iVar7) = cVar1;
                  iVar7 = iVar7 + 1;
                }
              }
              *(undefined1 *)(iVar3 + iVar7) = 0;
              iVar7 = Curl_base64_decode(iVar3,&local_34,&local_30);
              (*Curl_cfree)(iVar3);
              if ((iVar7 == 0) && (param_4 == local_30)) {
                iVar3 = memcmp(param_3,local_34,param_4);
                if (iVar3 == 0) {
                  iVar3 = 0;
                }
                else {
                  iVar3 = 0x5a;
                }
              }
              else {
                iVar3 = 0x5a;
              }
              goto LAB_0003ceba;
            }
          }
        }
      }
      iVar3 = 0x5a;
      goto LAB_0003ceba;
    }
  }
  iVar3 = 0x5a;
  pcVar8 = (char *)0x0;
LAB_0003ceba:
  (*Curl_cfree)(pcVar8);
  (*Curl_cfree)(local_34);
  local_34 = (void *)0x0;
  fclose(__stream);
  return iVar3;
}

