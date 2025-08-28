
int Curl_sasl_create_digest_http_message
              (undefined4 param_1,char *param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 *param_6,undefined4 *param_7,size_t *param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  size_t sVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  char *pcVar10;
  char *pcVar11;
  char cVar12;
  char *pcVar13;
  bool bVar14;
  bool bVar15;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined1 auStack_c8 [16];
  undefined1 auStack_b8 [36];
  undefined1 auStack_94 [36];
  undefined1 auStack_70 [36];
  char acStack_4c [40];
  
  local_d0 = 0;
  local_cc = 0;
  if (param_6[8] == 0) {
    param_6[8] = 1;
  }
  if (param_6[1] == 0) {
    uVar6 = Curl_rand(param_1);
    uVar7 = Curl_rand(param_1);
    uVar8 = Curl_rand(param_1);
    uVar9 = Curl_rand(param_1);
    curl_msnprintf(acStack_4c,0x21,"%08x%08x%08x%08x",uVar6,uVar7,uVar8,uVar9);
    sVar5 = strlen(acStack_4c);
    iVar1 = Curl_base64_encode(param_1,acStack_4c,sVar5,&local_d0,&local_cc);
    if (iVar1 != 0) {
      return iVar1;
    }
    param_6[1] = local_d0;
  }
  iVar1 = curl_maprintf("%s:%s:%s",param_2,param_6[2],param_3);
  if (iVar1 != 0) {
    Curl_md5it(auStack_c8,iVar1);
    (*Curl_cfree)(iVar1);
    sasl_digest_md5_to_ascii(auStack_c8,auStack_94);
    if (param_6[3] == 1) {
      iVar1 = curl_maprintf("%s:%s:%s",auStack_94,*param_6,param_6[1]);
      if (iVar1 == 0) {
        return 0x1b;
      }
      Curl_md5it(auStack_c8,iVar1);
      (*Curl_cfree)(iVar1);
      sasl_digest_md5_to_ascii(auStack_c8,auStack_94);
    }
    iVar2 = curl_maprintf("%s:%s",param_4,param_5);
    iVar1 = iVar2;
    if ((param_6[6] != 0) && (iVar3 = Curl_raw_equal(param_6[6],"auth-int"), iVar3 != 0)) {
      iVar1 = curl_maprintf("%s:%s",iVar2,"d41d8cd98f00b204e9800998ecf8427e");
      (*Curl_cfree)(iVar2);
    }
    if (iVar1 != 0) {
      Curl_md5it(auStack_c8,iVar1);
      (*Curl_cfree)(iVar1);
      sasl_digest_md5_to_ascii(auStack_c8,auStack_70);
      if (param_6[6] == 0) {
        iVar1 = curl_maprintf("%s:%s:%s",auStack_94,*param_6,auStack_70);
      }
      else {
        iVar1 = curl_maprintf("%s:%s:%08x:%s:%s:%s",auStack_94,*param_6,param_6[8],param_6[1],
                              param_6[6],auStack_70);
      }
      if (iVar1 != 0) {
        Curl_md5it(auStack_c8,iVar1);
        (*Curl_cfree)(iVar1);
        sasl_digest_md5_to_ascii(auStack_c8,auStack_b8);
        cVar12 = *param_2;
        if (cVar12 == '\0') {
          iVar1 = 1;
        }
        else {
          iVar1 = 1;
          pcVar4 = param_2;
          do {
            bVar14 = cVar12 == '\"';
            bVar15 = cVar12 == '\\';
            pcVar4 = pcVar4 + 1;
            cVar12 = *pcVar4;
            if (bVar14 || bVar15) {
              iVar1 = iVar1 + 2;
            }
            else {
              iVar1 = iVar1 + 1;
            }
          } while (cVar12 != '\0');
        }
        pcVar4 = (char *)(*Curl_cmalloc)(iVar1);
        if (pcVar4 != (char *)0x0) {
          cVar12 = *param_2;
          pcVar11 = pcVar4;
          if (cVar12 != '\0') {
            pcVar13 = param_2 + -1;
            do {
              pcVar10 = pcVar11;
              if (cVar12 == '\"' || cVar12 == '\\') {
                pcVar10 = pcVar11 + 1;
                *pcVar11 = '\\';
              }
              pcVar11 = pcVar10 + 1;
              *pcVar10 = pcVar13[1];
              cVar12 = pcVar13[2];
              pcVar13 = pcVar13 + 1;
            } while (cVar12 != '\0');
          }
          *pcVar11 = '\0';
          if (param_6[6] == 0) {
            pcVar11 = (char *)curl_maprintf("username=\"%s\", realm=\"%s\", nonce=\"%s\", uri=\"%s\", response=\"%s\""
                                            ,pcVar4,param_6[2],*param_6,param_5,auStack_b8);
          }
          else {
            pcVar11 = (char *)curl_maprintf("username=\"%s\", realm=\"%s\", nonce=\"%s\", uri=\"%s\", cnonce=\"%s\", nc=%08x, qop=%s, response=\"%s\""
                                            ,pcVar4,param_6[2],*param_6,param_5,param_6[1],
                                            param_6[8],param_6[6],auStack_b8);
            iVar1 = Curl_raw_equal(param_6[6],&DAT_0013a788);
            if (iVar1 != 0) {
              param_6[8] = param_6[8] + 1;
            }
          }
          (*Curl_cfree)(pcVar4);
          if (pcVar11 != (char *)0x0) {
            pcVar4 = pcVar11;
            if (param_6[5] != 0) {
              pcVar4 = (char *)curl_maprintf("%s, opaque=\"%s\"",pcVar11);
              (*Curl_cfree)(pcVar11);
              if (pcVar4 == (char *)0x0) {
                return 0x1b;
              }
            }
            pcVar11 = pcVar4;
            if (param_6[7] != 0) {
              pcVar11 = (char *)curl_maprintf("%s, algorithm=\"%s\"",pcVar4);
              (*Curl_cfree)(pcVar4);
              if (pcVar11 == (char *)0x0) {
                return 0x1b;
              }
            }
            *param_7 = pcVar11;
            sVar5 = strlen(pcVar11);
            *param_8 = sVar5;
            return 0;
          }
        }
      }
    }
  }
  return 0x1b;
}

