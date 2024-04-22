
int Curl_sasl_create_digest_http_message
              (undefined4 param_1,char *param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 *param_6,char **param_7,size_t *param_8)

{
  bool bVar1;
  code **ppcVar2;
  code **ppcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  size_t sVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  char *pcVar13;
  char *pcVar14;
  char cVar15;
  char *pcVar16;
  bool bVar17;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined auStack_c8 [16];
  undefined auStack_b8 [36];
  undefined auStack_94 [36];
  undefined auStack_70 [36];
  char acStack_4c [40];
  
  local_d0 = 0;
  local_cc = 0;
  if (param_6[8] == 0) {
    param_6[8] = 1;
  }
  if (param_6[1] == 0) {
    uVar9 = Curl_rand(param_1);
    uVar10 = Curl_rand(param_1);
    uVar11 = Curl_rand(param_1);
    uVar12 = Curl_rand(param_1);
    curl_msnprintf(acStack_4c,0x21,DAT_00055b58,uVar9,uVar10,uVar11,uVar12);
    sVar8 = strlen(acStack_4c);
    iVar4 = Curl_base64_encode(param_1,acStack_4c,sVar8,&local_d0,&local_cc);
    if (iVar4 != 0) {
      return iVar4;
    }
    param_6[1] = local_d0;
  }
  iVar4 = curl_maprintf(DAT_00055b2c,param_2,param_6[2],param_3);
  ppcVar2 = DAT_00055b30;
  if (iVar4 != 0) {
    Curl_md5it(auStack_c8,iVar4);
    (**ppcVar2)(iVar4);
    sasl_digest_md5_to_ascii(auStack_c8,auStack_94);
    if (param_6[3] == 1) {
      iVar4 = curl_maprintf(DAT_00055b2c,auStack_94,*param_6,param_6[1]);
      if (iVar4 == 0) {
        return 0x1b;
      }
      Curl_md5it(auStack_c8,iVar4);
      (**ppcVar2)(iVar4);
      sasl_digest_md5_to_ascii(auStack_c8,auStack_94);
    }
    iVar5 = curl_maprintf(DAT_00055b34,param_4,param_5);
    iVar4 = iVar5;
    if ((param_6[6] != 0) && (iVar6 = Curl_raw_equal(param_6[6],DAT_00055b38), iVar6 != 0)) {
      iVar4 = curl_maprintf(DAT_00055b34,iVar5,DAT_00055b54);
      (**ppcVar2)(iVar5);
    }
    if (iVar4 != 0) {
      Curl_md5it(auStack_c8,iVar4);
      (**ppcVar2)(iVar4);
      sasl_digest_md5_to_ascii(auStack_c8,auStack_70);
      if (param_6[6] == 0) {
        iVar4 = curl_maprintf(DAT_00055b2c,auStack_94,*param_6,auStack_70);
      }
      else {
        iVar4 = curl_maprintf(DAT_00055b3c,auStack_94,*param_6,param_6[8],param_6[1],param_6[6],
                              auStack_70);
      }
      if (iVar4 != 0) {
        Curl_md5it(auStack_c8,iVar4);
        (**ppcVar2)(iVar4);
        sasl_digest_md5_to_ascii(auStack_c8,auStack_b8);
        cVar15 = *param_2;
        if (cVar15 == '\0') {
          iVar4 = 1;
        }
        else {
          iVar4 = 1;
          pcVar7 = param_2;
          do {
            bVar17 = cVar15 == '\"';
            bVar1 = cVar15 == '\\';
            pcVar7 = pcVar7 + 1;
            cVar15 = *pcVar7;
            if (bVar17 || bVar1) {
              iVar4 = iVar4 + 2;
            }
            else {
              iVar4 = iVar4 + 1;
            }
          } while (cVar15 != '\0');
        }
        pcVar7 = (char *)(**DAT_00055b40)(iVar4);
        if (pcVar7 != (char *)0x0) {
          cVar15 = *param_2;
          pcVar14 = pcVar7;
          if (cVar15 != '\0') {
            pcVar16 = param_2 + -1;
            do {
              pcVar13 = pcVar14;
              if (cVar15 == '\"' || cVar15 == '\\') {
                pcVar13 = pcVar14 + 1;
                *pcVar14 = '\\';
              }
              pcVar14 = pcVar13 + 1;
              *pcVar13 = pcVar16[1];
              cVar15 = pcVar16[2];
              pcVar16 = pcVar16 + 1;
            } while (cVar15 != '\0');
          }
          *pcVar14 = '\0';
          if (param_6[6] == 0) {
            pcVar14 = (char *)curl_maprintf(DAT_00055b5c,pcVar7,param_6[2],*param_6,param_5,
                                            auStack_b8);
          }
          else {
            pcVar14 = (char *)curl_maprintf(DAT_00055b44,pcVar7,param_6[2],*param_6,param_5,
                                            param_6[1],param_6[8],param_6[6],auStack_b8);
            iVar4 = Curl_raw_equal(param_6[6],DAT_00055b48);
            if (iVar4 != 0) {
              param_6[8] = param_6[8] + 1;
            }
          }
          ppcVar3 = DAT_00055b30;
          (**ppcVar2)(pcVar7);
          if (pcVar14 != (char *)0x0) {
            pcVar7 = pcVar14;
            if (param_6[5] != 0) {
              pcVar7 = (char *)curl_maprintf(DAT_00055b4c,pcVar14);
              (**ppcVar3)(pcVar14);
              if (pcVar7 == (char *)0x0) {
                return 0x1b;
              }
            }
            pcVar14 = pcVar7;
            if (param_6[7] != 0) {
              pcVar14 = (char *)curl_maprintf(DAT_00055b50,pcVar7);
              (**ppcVar2)(pcVar7);
              if (pcVar14 == (char *)0x0) {
                return 0x1b;
              }
            }
            *param_7 = pcVar14;
            sVar8 = strlen(pcVar14);
            *param_8 = sVar8;
            return 0;
          }
        }
      }
    }
  }
  return 0x1b;
}

