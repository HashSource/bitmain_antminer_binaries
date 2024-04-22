
int Curl_pin_peer_pubkey(undefined4 param_1,char *param_2,void *param_3,uint param_4)

{
  char cVar1;
  code **ppcVar2;
  void *pvVar3;
  int iVar4;
  FILE *__stream;
  char *__haystack;
  uint uVar5;
  size_t sVar6;
  size_t sVar7;
  char *pcVar8;
  int iVar9;
  code **ppcVar10;
  char *pcVar11;
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
  iVar4 = strncmp(param_2,DAT_0003d0e8,8);
  ppcVar2 = DAT_0003d104;
  if (iVar4 == 0) {
    iVar4 = (**DAT_0003d104)(0x20);
    ppcVar10 = DAT_0003d100;
    if (iVar4 == 0) {
      return 0x1b;
    }
    Curl_ossl_sha256sum(param_3,param_4,iVar4,0x20);
    iVar9 = Curl_base64_encode(param_1,iVar4,0x20,local_2c,&local_30);
    (**ppcVar10)(iVar4);
    if (iVar9 != 0) {
      return iVar9;
    }
    Curl_infof(param_1,DAT_0003d0f0,local_2c[0]);
    sVar6 = strlen(param_2);
    pcVar11 = (char *)(**ppcVar2)(sVar6 + 1);
    if (pcVar11 == (char *)0x0) {
      (**ppcVar10)(local_2c[0]);
      return 0x1b;
    }
    memcpy(pcVar11,param_2,sVar6 + 1);
    pcVar8 = pcVar11;
    do {
      __haystack = strstr(pcVar8,DAT_0003d0f4);
      if (__haystack != (char *)0x0) {
        *__haystack = '\0';
      }
      sVar6 = strlen(pcVar8 + 8);
      pvVar3 = local_2c[0];
      if ((sVar6 == local_30) && (iVar4 = memcmp(local_2c[0],pcVar8 + 8,sVar6), iVar4 == 0)) {
        iVar4 = 0;
        local_2c[0] = pvVar3;
        goto LAB_0003cf94;
      }
      pcVar8 = DAT_0003d0e8;
      if (__haystack == (char *)0x0) break;
      *__haystack = ';';
      pcVar8 = strstr(__haystack,pcVar8);
    } while (pcVar8 != (char *)0x0);
    iVar4 = 0x5a;
LAB_0003cf94:
    (**ppcVar10)(local_2c[0]);
    local_2c[0] = (void *)0x0;
    (**ppcVar10)(pcVar11);
    return iVar4;
  }
  __stream = fopen64(param_2,DAT_0003d0ec);
  if (__stream == (FILE *)0x0) {
    return 0x5a;
  }
  iVar4 = fseek(__stream,0,2);
  if (iVar4 == 0) {
    uVar5 = ftell(__stream);
    iVar4 = fseek(__stream,0,0);
    if ((((iVar4 == 0) && (uVar5 < 0x100001)) &&
        (sVar6 = curlx_sotouz(uVar5,(int)uVar5 >> 0x1f), ppcVar2 = DAT_0003d104, param_4 <= sVar6))
       && (pcVar11 = (char *)(**DAT_0003d104)(sVar6 + 1), pcVar11 != (char *)0x0)) {
      sVar7 = fread(pcVar11,sVar6,1,__stream);
      ppcVar10 = DAT_0003d100;
      if (sVar7 == 1) {
        if (param_4 == sVar6) {
          iVar4 = memcmp(param_3,pcVar11,param_4);
          if (iVar4 == 0) {
            iVar4 = 0;
          }
          else {
            iVar4 = 0x5a;
          }
          goto LAB_0003ceba;
        }
        pcVar11[sVar6] = '\0';
        pcVar8 = strstr(pcVar11,DAT_0003d0f8);
        if ((pcVar8 != (char *)0x0) &&
           ((iVar4 = (int)pcVar8 - (int)pcVar11, iVar4 == 0 || (pcVar11[iVar4 + -1] == '\n')))) {
          uVar5 = iVar4 + 0x1a;
          pcVar8 = strstr(pcVar11 + uVar5,DAT_0003d0fc);
          if (pcVar8 != (char *)0x0) {
            iVar4 = (**ppcVar2)((-0x19 - iVar4) + ((int)pcVar8 - (int)pcVar11));
            if (iVar4 != 0) {
              iVar9 = 0;
              while (ppcVar10 = DAT_0003d100, uVar5 < (uint)((int)pcVar8 - (int)pcVar11)) {
                cVar1 = pcVar11[uVar5];
                uVar5 = uVar5 + 1;
                if ((cVar1 != '\r') && (cVar1 != '\n')) {
                  *(char *)(iVar4 + iVar9) = cVar1;
                  iVar9 = iVar9 + 1;
                }
              }
              *(undefined *)(iVar4 + iVar9) = 0;
              iVar9 = Curl_base64_decode(iVar4,&local_34,&local_30);
              (**ppcVar10)(iVar4);
              if ((iVar9 == 0) && (param_4 == local_30)) {
                iVar4 = memcmp(param_3,local_34,param_4);
                if (iVar4 == 0) {
                  iVar4 = 0;
                }
                else {
                  iVar4 = 0x5a;
                }
              }
              else {
                iVar4 = 0x5a;
              }
              goto LAB_0003ceba;
            }
          }
        }
      }
      iVar4 = 0x5a;
      ppcVar10 = DAT_0003d100;
      goto LAB_0003ceba;
    }
  }
  iVar4 = 0x5a;
  pcVar11 = (char *)0x0;
  ppcVar10 = DAT_0003d100;
LAB_0003ceba:
  (**ppcVar10)(pcVar11);
  (**ppcVar10)(local_34);
  local_34 = (void *)0x0;
  fclose(__stream);
  return iVar4;
}

