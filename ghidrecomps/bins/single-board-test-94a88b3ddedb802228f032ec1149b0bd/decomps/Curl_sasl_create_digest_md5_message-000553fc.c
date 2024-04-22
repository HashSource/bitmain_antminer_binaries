
/* WARNING: Type propagation algorithm not settling */

int Curl_sasl_create_digest_md5_message
              (undefined4 param_1,char *param_2,char *param_3,char *param_4,undefined4 param_5,
              undefined4 param_6,undefined4 param_7)

{
  undefined *puVar1;
  char cVar2;
  code **ppcVar3;
  code **ppcVar4;
  char *pcVar5;
  size_t sVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  char *pcVar14;
  char *pcVar15;
  int local_234;
  undefined4 local_230;
  undefined4 local_22c;
  undefined local_228;
  undefined4 local_224;
  undefined4 uStack_220;
  undefined local_21c;
  undefined4 local_218;
  undefined4 uStack_214;
  undefined4 uStack_210;
  undefined local_20c;
  undefined local_208 [16];
  undefined auStack_1f8 [36];
  undefined auStack_1d4 [36];
  undefined auStack_1b0 [36];
  char acStack_18c [36];
  char acStack_168 [64];
  char acStack_128 [64];
  undefined auStack_e8 [64];
  char local_a8 [132];
  
  local_224 = *DAT_00055510;
  uStack_220 = DAT_00055510[1];
  local_21c = (undefined)DAT_00055510[2];
  local_218 = *DAT_00055534;
  uStack_214 = DAT_00055534[1];
  uStack_210 = DAT_00055534[2];
  local_22c = *DAT_00055530;
  local_20c = (undefined)DAT_00055534[3];
  local_228 = (undefined)DAT_00055530[1];
  local_234 = 0;
  local_230 = 0;
  sVar6 = strlen(param_2);
  if (sVar6 != 0) {
    if (*param_2 == '=') {
      return 0x3d;
    }
    iVar7 = Curl_base64_decode(param_2,&local_234,&local_230);
    if (iVar7 != 0) {
      return iVar7;
    }
    if (local_234 != 0) {
      iVar7 = sasl_digest_get_key_value(local_234,DAT_00055514,acStack_168,0x40,0x22);
      if (iVar7 != 0) {
        iVar7 = sasl_digest_get_key_value(local_234,DAT_0005551c,local_a8,0x80,0x22);
        if (iVar7 == 0) {
          local_a8[0] = '\0';
        }
        iVar7 = sasl_digest_get_key_value(local_234,DAT_00055520,acStack_128,0x40,0x2c);
        if ((iVar7 != 0) &&
           (iVar7 = sasl_digest_get_key_value(local_234,DAT_00055524,auStack_e8,0x40,0x22),
           ppcVar3 = DAT_00055518, iVar7 != 0)) {
          (**DAT_00055518)(local_234);
          iVar7 = strcmp(acStack_128,DAT_00055528);
          if (iVar7 != 0) {
            return 0x3d;
          }
          pcVar8 = (char *)(**DAT_0005552c)(auStack_e8);
          if (pcVar8 == (char *)0x0) {
            return 0x1b;
          }
          cVar2 = *pcVar8;
          pcVar14 = pcVar8;
          while (cVar2 == ',') {
            pcVar14 = pcVar14 + 1;
            cVar2 = *pcVar14;
          }
          pcVar5 = pcVar14 + 1;
          if (cVar2 != '\0') {
            do {
              pcVar15 = pcVar5;
              if (*pcVar15 == '\0') goto LAB_0005554c;
              pcVar5 = pcVar15 + 1;
            } while (*pcVar15 != ',');
            *pcVar15 = '\0';
            pcVar15 = pcVar15 + 1;
LAB_0005554c:
            if (pcVar14 != (char *)0x0) {
              iVar7 = 0;
              iVar9 = Curl_raw_equal(pcVar14,DAT_00055808);
              while( true ) {
                if (iVar9 == 0) {
                  iVar9 = Curl_raw_equal(pcVar14,DAT_000558b0);
                  if (iVar9 == 0) {
                    Curl_raw_equal(pcVar14,DAT_000558b4);
                  }
                }
                else {
                  iVar7 = 1;
                }
                cVar2 = *pcVar15;
                pcVar14 = pcVar15;
                while (cVar2 == ',') {
                  pcVar14 = pcVar14 + 1;
                  cVar2 = *pcVar14;
                }
                if (cVar2 == '\0') break;
                pcVar5 = pcVar14 + 1;
                do {
                  pcVar15 = pcVar5;
                  if (*pcVar15 == '\0') goto LAB_00055858;
                  pcVar5 = pcVar15 + 1;
                } while (*pcVar15 != ',');
                *pcVar15 = '\0';
                pcVar15 = pcVar15 + 1;
LAB_00055858:
                if (pcVar14 == (char *)0x0) break;
                iVar9 = Curl_raw_equal(pcVar14,DAT_000558ac);
              }
              (**ppcVar3)(pcVar8);
              if (-1 < iVar7 << 0x1f) {
                return 0x3d;
              }
              uVar10 = Curl_rand(param_1);
              uVar11 = Curl_rand(param_1);
              uVar12 = Curl_rand(param_1);
              uVar13 = Curl_rand(param_1);
              curl_msnprintf(acStack_18c,0x21,DAT_0005580c,uVar10,uVar11,uVar12,uVar13);
              iVar7 = Curl_MD5_init(DAT_00055810);
              if (iVar7 != 0) {
                strlen(param_3);
                uVar10 = curlx_uztoui();
                Curl_MD5_update(iVar7,param_3,uVar10);
                Curl_MD5_update(iVar7,DAT_00055814,1);
                strlen(local_a8);
                uVar10 = curlx_uztoui();
                Curl_MD5_update(iVar7,local_a8,uVar10);
                Curl_MD5_update(iVar7,DAT_00055814,1);
                strlen(param_4);
                uVar10 = curlx_uztoui();
                Curl_MD5_update(iVar7,param_4,uVar10);
                Curl_MD5_final(iVar7,local_208);
                iVar7 = Curl_MD5_init(DAT_00055810);
                if (iVar7 != 0) {
                  Curl_MD5_update(iVar7,local_208,0x10);
                  iVar9 = 0;
                  Curl_MD5_update(iVar7,DAT_00055814,1);
                  strlen(acStack_168);
                  uVar10 = curlx_uztoui();
                  Curl_MD5_update(iVar7,acStack_168,uVar10);
                  Curl_MD5_update(iVar7,DAT_00055814,1);
                  strlen(acStack_18c);
                  uVar10 = curlx_uztoui();
                  Curl_MD5_update(iVar7,acStack_18c,uVar10);
                  Curl_MD5_final(iVar7,local_208);
                  do {
                    iVar7 = iVar9 * 2;
                    puVar1 = local_208 + iVar9;
                    iVar9 = iVar9 + 1;
                    curl_msnprintf(auStack_1f8 + iVar7,3,DAT_00055818,*puVar1);
                  } while (iVar9 != 0x10);
                  pcVar8 = (char *)Curl_sasl_build_spn(param_5,local_a8);
                  if (pcVar8 != (char *)0x0) {
                    iVar7 = Curl_MD5_init(DAT_00055810);
                    if (iVar7 != 0) {
                      iVar9 = 0;
                      strlen((char *)&local_218);
                      uVar10 = curlx_uztoui();
                      Curl_MD5_update(iVar7,&local_218,uVar10);
                      Curl_MD5_update(iVar7,DAT_00055814,1);
                      strlen(pcVar8);
                      uVar10 = curlx_uztoui();
                      Curl_MD5_update(iVar7,pcVar8,uVar10);
                      Curl_MD5_final(iVar7,local_208);
                      do {
                        iVar7 = iVar9 * 2;
                        puVar1 = local_208 + iVar9;
                        iVar9 = iVar9 + 1;
                        curl_msnprintf(auStack_1d4 + iVar7,3,DAT_00055818,*puVar1);
                      } while (iVar9 != 0x10);
                      iVar7 = Curl_MD5_init(DAT_00055810);
                      if (iVar7 != 0) {
                        Curl_MD5_update(iVar7,auStack_1f8,0x20);
                        iVar9 = 0;
                        Curl_MD5_update(iVar7,DAT_00055814,1);
                        strlen(acStack_168);
                        uVar10 = curlx_uztoui();
                        Curl_MD5_update(iVar7,acStack_168,uVar10);
                        Curl_MD5_update(iVar7,DAT_00055814,1);
                        strlen((char *)&local_224);
                        uVar10 = curlx_uztoui();
                        Curl_MD5_update(iVar7,&local_224,uVar10);
                        Curl_MD5_update(iVar7,DAT_00055814,1);
                        strlen(acStack_18c);
                        uVar10 = curlx_uztoui();
                        Curl_MD5_update(iVar7,acStack_18c,uVar10);
                        Curl_MD5_update(iVar7,DAT_00055814,1);
                        strlen((char *)&local_22c);
                        uVar10 = curlx_uztoui();
                        Curl_MD5_update(iVar7,&local_22c,uVar10);
                        Curl_MD5_update(iVar7,DAT_00055814,1);
                        Curl_MD5_update(iVar7,auStack_1d4,0x20);
                        Curl_MD5_final(iVar7,local_208);
                        do {
                          iVar7 = iVar9 * 2;
                          puVar1 = local_208 + iVar9;
                          iVar9 = iVar9 + 1;
                          curl_msnprintf(auStack_1b0 + iVar7,3,DAT_00055818,*puVar1);
                        } while (iVar9 != 0x10);
                        iVar7 = curl_maprintf(DAT_0005581c,param_3,local_a8,acStack_168,acStack_18c,
                                              &local_224,pcVar8,auStack_1b0,&local_22c);
                        ppcVar4 = DAT_00055820;
                        (**ppcVar3)(pcVar8);
                        if (iVar7 == 0) {
                          return 0x1b;
                        }
                        iVar9 = Curl_base64_encode(param_1,iVar7,0,param_6,param_7);
                        (**ppcVar4)(iVar7);
                        return iVar9;
                      }
                    }
                    (**ppcVar3)(pcVar8);
                  }
                }
              }
              return 0x1b;
            }
          }
          (**ppcVar3)(pcVar8);
          return 0x3d;
        }
      }
      (**DAT_00055518)(local_234);
      return 0x3d;
    }
  }
  return 0x3d;
}

