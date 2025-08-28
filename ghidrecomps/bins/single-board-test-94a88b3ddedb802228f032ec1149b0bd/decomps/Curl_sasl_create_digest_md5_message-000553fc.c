
/* WARNING: Type propagation algorithm not settling */

int Curl_sasl_create_digest_md5_message
              (undefined4 param_1,char *param_2,char *param_3,char *param_4,undefined4 param_5,
              undefined4 param_6,undefined4 param_7)

{
  undefined1 *puVar1;
  char cVar2;
  char *pcVar3;
  size_t sVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  char *pcVar12;
  char *pcVar13;
  int local_234;
  undefined4 local_230;
  undefined4 local_22c;
  undefined1 local_228;
  char local_224 [12];
  char local_218 [16];
  undefined1 local_208 [16];
  undefined1 auStack_1f8 [36];
  undefined1 auStack_1d4 [36];
  undefined1 auStack_1b0 [36];
  char acStack_18c [36];
  char acStack_168 [64];
  char acStack_128 [64];
  undefined1 auStack_e8 [64];
  char local_a8 [132];
  
  builtin_strncpy(local_224,"00000001",8);
  local_224[8] = 0;
  builtin_strncpy(local_218,"AUTHENTICATE",0xc);
  local_218[0xc] = 0;
  local_22c = 0x68747561;
  local_228 = 0;
  local_234 = 0;
  local_230 = 0;
  sVar4 = strlen(param_2);
  if (sVar4 != 0) {
    if (*param_2 == '=') {
      return 0x3d;
    }
    iVar5 = Curl_base64_decode(param_2,&local_234,&local_230);
    if (iVar5 != 0) {
      return iVar5;
    }
    if (local_234 != 0) {
      iVar5 = sasl_digest_get_key_value(local_234,"nonce=\"",acStack_168,0x40,0x22);
      if (iVar5 != 0) {
        iVar5 = sasl_digest_get_key_value(local_234,"realm=\"",local_a8,0x80,0x22);
        if (iVar5 == 0) {
          local_a8[0] = '\0';
        }
        iVar5 = sasl_digest_get_key_value(local_234,"algorithm=",acStack_128,0x40,0x2c);
        if ((iVar5 != 0) &&
           (iVar5 = sasl_digest_get_key_value(local_234,"qop=\"",auStack_e8,0x40,0x22), iVar5 != 0))
        {
          (*Curl_cfree)(local_234);
          iVar5 = strcmp(acStack_128,"md5-sess");
          if (iVar5 != 0) {
            return 0x3d;
          }
          pcVar6 = (char *)(*Curl_cstrdup)(auStack_e8);
          if (pcVar6 == (char *)0x0) {
            return 0x1b;
          }
          cVar2 = *pcVar6;
          pcVar12 = pcVar6;
          while (cVar2 == ',') {
            pcVar12 = pcVar12 + 1;
            cVar2 = *pcVar12;
          }
          pcVar3 = pcVar12 + 1;
          if (cVar2 != '\0') {
            do {
              pcVar13 = pcVar3;
              if (*pcVar13 == '\0') goto LAB_0005554c;
              pcVar3 = pcVar13 + 1;
            } while (*pcVar13 != ',');
            *pcVar13 = '\0';
            pcVar13 = pcVar13 + 1;
LAB_0005554c:
            if (pcVar12 != (char *)0x0) {
              iVar5 = 0;
              iVar7 = Curl_raw_equal(pcVar12,&DAT_0013a788);
              while( true ) {
                if (iVar7 == 0) {
                  iVar7 = Curl_raw_equal(pcVar12,"auth-int");
                  if (iVar7 == 0) {
                    Curl_raw_equal(pcVar12,"auth-conf");
                  }
                }
                else {
                  iVar5 = 1;
                }
                cVar2 = *pcVar13;
                pcVar12 = pcVar13;
                while (cVar2 == ',') {
                  pcVar12 = pcVar12 + 1;
                  cVar2 = *pcVar12;
                }
                if (cVar2 == '\0') break;
                pcVar3 = pcVar12 + 1;
                do {
                  pcVar13 = pcVar3;
                  if (*pcVar13 == '\0') goto LAB_00055858;
                  pcVar3 = pcVar13 + 1;
                } while (*pcVar13 != ',');
                *pcVar13 = '\0';
                pcVar13 = pcVar13 + 1;
LAB_00055858:
                if (pcVar12 == (char *)0x0) break;
                iVar7 = Curl_raw_equal(pcVar12,&DAT_0013a788);
              }
              (*Curl_cfree)(pcVar6);
              if (-1 < iVar5 << 0x1f) {
                return 0x3d;
              }
              uVar8 = Curl_rand(param_1);
              uVar9 = Curl_rand(param_1);
              uVar10 = Curl_rand(param_1);
              uVar11 = Curl_rand(param_1);
              curl_msnprintf(acStack_18c,0x21,"%08x%08x%08x%08x",uVar8,uVar9,uVar10,uVar11);
              iVar5 = Curl_MD5_init(&Curl_DIGEST_MD5);
              if (iVar5 != 0) {
                strlen(param_3);
                uVar8 = curlx_uztoui();
                Curl_MD5_update(iVar5,param_3,uVar8);
                Curl_MD5_update(iVar5,":",1);
                strlen(local_a8);
                uVar8 = curlx_uztoui();
                Curl_MD5_update(iVar5,local_a8,uVar8);
                Curl_MD5_update(iVar5,":",1);
                strlen(param_4);
                uVar8 = curlx_uztoui();
                Curl_MD5_update(iVar5,param_4,uVar8);
                Curl_MD5_final(iVar5,local_208);
                iVar5 = Curl_MD5_init(&Curl_DIGEST_MD5);
                if (iVar5 != 0) {
                  Curl_MD5_update(iVar5,local_208,0x10);
                  iVar7 = 0;
                  Curl_MD5_update(iVar5,":",1);
                  strlen(acStack_168);
                  uVar8 = curlx_uztoui();
                  Curl_MD5_update(iVar5,acStack_168,uVar8);
                  Curl_MD5_update(iVar5,":",1);
                  strlen(acStack_18c);
                  uVar8 = curlx_uztoui();
                  Curl_MD5_update(iVar5,acStack_18c,uVar8);
                  Curl_MD5_final(iVar5,local_208);
                  do {
                    iVar5 = iVar7 * 2;
                    puVar1 = local_208 + iVar7;
                    iVar7 = iVar7 + 1;
                    curl_msnprintf(auStack_1f8 + iVar5,3,&DAT_001397a8,*puVar1);
                  } while (iVar7 != 0x10);
                  pcVar6 = (char *)Curl_sasl_build_spn(param_5,local_a8);
                  if (pcVar6 != (char *)0x0) {
                    iVar5 = Curl_MD5_init(&Curl_DIGEST_MD5);
                    if (iVar5 != 0) {
                      iVar7 = 0;
                      strlen(local_218);
                      uVar8 = curlx_uztoui();
                      Curl_MD5_update(iVar5,local_218,uVar8);
                      Curl_MD5_update(iVar5,":",1);
                      strlen(pcVar6);
                      uVar8 = curlx_uztoui();
                      Curl_MD5_update(iVar5,pcVar6,uVar8);
                      Curl_MD5_final(iVar5,local_208);
                      do {
                        iVar5 = iVar7 * 2;
                        puVar1 = local_208 + iVar7;
                        iVar7 = iVar7 + 1;
                        curl_msnprintf(auStack_1d4 + iVar5,3,&DAT_001397a8,*puVar1);
                      } while (iVar7 != 0x10);
                      iVar5 = Curl_MD5_init(&Curl_DIGEST_MD5);
                      if (iVar5 != 0) {
                        Curl_MD5_update(iVar5,auStack_1f8,0x20);
                        iVar7 = 0;
                        Curl_MD5_update(iVar5,":",1);
                        strlen(acStack_168);
                        uVar8 = curlx_uztoui();
                        Curl_MD5_update(iVar5,acStack_168,uVar8);
                        Curl_MD5_update(iVar5,":",1);
                        strlen(local_224);
                        uVar8 = curlx_uztoui();
                        Curl_MD5_update(iVar5,local_224,uVar8);
                        Curl_MD5_update(iVar5,":",1);
                        strlen(acStack_18c);
                        uVar8 = curlx_uztoui();
                        Curl_MD5_update(iVar5,acStack_18c,uVar8);
                        Curl_MD5_update(iVar5,":",1);
                        strlen((char *)&local_22c);
                        uVar8 = curlx_uztoui();
                        Curl_MD5_update(iVar5,&local_22c,uVar8);
                        Curl_MD5_update(iVar5,":",1);
                        Curl_MD5_update(iVar5,auStack_1d4,0x20);
                        Curl_MD5_final(iVar5,local_208);
                        do {
                          iVar5 = iVar7 * 2;
                          puVar1 = local_208 + iVar7;
                          iVar7 = iVar7 + 1;
                          curl_msnprintf(auStack_1b0 + iVar5,3,&DAT_001397a8,*puVar1);
                        } while (iVar7 != 0x10);
                        iVar5 = curl_maprintf("username=\"%s\",realm=\"%s\",nonce=\"%s\",cnonce=\"%s\",nc=\"%s\",digest-uri=\"%s\",response=%s,qop=%s"
                                              ,param_3,local_a8,acStack_168,acStack_18c,local_224,
                                              pcVar6,auStack_1b0,&local_22c);
                        (*Curl_cfree)(pcVar6);
                        if (iVar5 == 0) {
                          return 0x1b;
                        }
                        iVar7 = Curl_base64_encode(param_1,iVar5,0,param_6,param_7);
                        (*Curl_cfree)(iVar5);
                        return iVar7;
                      }
                    }
                    (*Curl_cfree)(pcVar6);
                  }
                }
              }
              return 0x1b;
            }
          }
          (*Curl_cfree)(pcVar6);
          return 0x3d;
        }
      }
      (*Curl_cfree)(local_234);
      return 0x3d;
    }
  }
  return 0x3d;
}

