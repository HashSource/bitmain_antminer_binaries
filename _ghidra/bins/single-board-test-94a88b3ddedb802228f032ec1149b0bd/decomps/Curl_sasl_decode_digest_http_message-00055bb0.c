
/* WARNING: Type propagation algorithm not settling */

undefined4 Curl_sasl_decode_digest_http_message(byte *param_1,int *param_2)

{
  byte bVar1;
  char cVar2;
  bool bVar3;
  bool bVar4;
  char *pcVar5;
  ushort **ppuVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  char *pcVar10;
  uint uVar11;
  byte *pbVar12;
  char *pcVar13;
  byte *local_52c;
  undefined1 auStack_528 [256];
  undefined1 auStack_428 [1028];
  
  iVar9 = *param_2;
  bVar4 = false;
  bVar3 = false;
  local_52c = param_1;
  Curl_sasl_digest_cleanup(param_2);
  do {
    bVar1 = *local_52c;
    pbVar12 = local_52c;
    while ((local_52c = pbVar12, bVar1 != 0 &&
           (ppuVar6 = __ctype_b_loc(), (int)((uint)(*ppuVar6)[bVar1] << 0x12) < 0))) {
      pbVar12 = pbVar12 + 1;
      bVar1 = *pbVar12;
    }
    iVar7 = Curl_sasl_digest_get_pair(pbVar12,auStack_528,auStack_428,&local_52c);
    if (iVar7 == 0) {
      if (((iVar9 == 0) || ((char)param_2[4] != '\0')) && (*param_2 != 0)) {
        return 0;
      }
      return 0x3d;
    }
    iVar7 = Curl_raw_equal(auStack_528,"nonce");
    if (iVar7 != 0) {
      (*Curl_cfree)(*param_2);
      iVar7 = (*Curl_cstrdup)(auStack_428);
      *param_2 = iVar7;
      goto joined_r0x00055d0e;
    }
    iVar7 = Curl_raw_equal(auStack_528,"stale");
    if (iVar7 != 0) {
      iVar7 = Curl_raw_equal(auStack_428,&DAT_0013a938);
      if (iVar7 != 0) {
        *(undefined1 *)(param_2 + 4) = 1;
        param_2[8] = 1;
      }
      goto LAB_00055c1e;
    }
    iVar7 = Curl_raw_equal(auStack_528,"realm");
    if (iVar7 == 0) {
      iVar7 = Curl_raw_equal(auStack_528,"opaque");
      if (iVar7 != 0) {
        (*Curl_cfree)(param_2[5]);
        iVar7 = (*Curl_cstrdup)(auStack_428);
        param_2[5] = iVar7;
        goto joined_r0x00055d0e;
      }
      iVar7 = Curl_raw_equal(auStack_528,&DAT_0013a950);
      if (iVar7 != 0) {
        pcVar8 = (char *)(*Curl_cstrdup)(auStack_428);
        if (pcVar8 == (char *)0x0) {
          return 0x1b;
        }
        cVar2 = *pcVar8;
        pcVar10 = pcVar8;
        while (cVar2 == ',') {
          pcVar10 = pcVar10 + 1;
          cVar2 = *pcVar10;
        }
        pcVar5 = pcVar10 + 1;
        if (cVar2 != '\0') {
          do {
            pcVar13 = pcVar5;
            if (*pcVar13 == '\0') goto LAB_00055d26;
            pcVar5 = pcVar13 + 1;
          } while (*pcVar13 != ',');
          *pcVar13 = '\0';
          pcVar13 = pcVar13 + 1;
LAB_00055d26:
          if (pcVar10 != (char *)0x0) {
            iVar7 = Curl_raw_equal(pcVar10,&DAT_0013a788);
            if (iVar7 == 0) goto LAB_00055d7e;
            do {
              cVar2 = *pcVar13;
              bVar3 = true;
              pcVar10 = pcVar13;
joined_r0x00055d42:
              while (cVar2 == ',') {
                cVar2 = pcVar10[1];
                pcVar10 = pcVar10 + 1;
              }
              if (cVar2 == '\0') goto LAB_00055ce8;
              pcVar5 = pcVar10 + 1;
              do {
                pcVar13 = pcVar5;
                if (*pcVar13 == '\0') goto joined_r0x00055df6;
                pcVar5 = pcVar13 + 1;
              } while (*pcVar13 != ',');
              *pcVar13 = '\0';
              pcVar13 = pcVar13 + 1;
joined_r0x00055df6:
              if (pcVar10 == (char *)0x0) goto LAB_00055ce8;
              iVar7 = Curl_raw_equal(pcVar10,&DAT_0013a788);
            } while (iVar7 != 0);
LAB_00055d7e:
            iVar7 = Curl_raw_equal(pcVar10,"auth-int");
            cVar2 = *pcVar13;
            pcVar10 = pcVar13;
            if (iVar7 != 0) {
              bVar4 = true;
            }
            goto joined_r0x00055d42;
          }
        }
LAB_00055ce8:
        (*Curl_cfree)(pcVar8);
        if (bVar3) {
          (*Curl_cfree)(param_2[6]);
          iVar7 = (*Curl_cstrdup)(&DAT_0013a788);
          param_2[6] = iVar7;
        }
        else {
          if (!bVar4) goto LAB_00055c1e;
          (*Curl_cfree)(param_2[6]);
          iVar7 = (*Curl_cstrdup)("auth-int");
          param_2[6] = iVar7;
        }
        goto joined_r0x00055d0e;
      }
      iVar7 = Curl_raw_equal(auStack_528,"algorithm");
      if (iVar7 != 0) {
        (*Curl_cfree)(param_2[7]);
        iVar7 = (*Curl_cstrdup)(auStack_428);
        param_2[7] = iVar7;
        if (iVar7 == 0) {
          return 0x1b;
        }
        iVar7 = Curl_raw_equal(auStack_428,"MD5-sess");
        if (iVar7 == 0) {
          iVar7 = Curl_raw_equal(auStack_428,&DAT_001402ec);
          if (iVar7 == 0) {
            return 0x3d;
          }
          param_2[3] = 0;
        }
        else {
          param_2[3] = 1;
        }
      }
    }
    else {
      (*Curl_cfree)(param_2[2]);
      iVar7 = (*Curl_cstrdup)(auStack_428);
      param_2[2] = iVar7;
joined_r0x00055d0e:
      if (iVar7 == 0) {
        return 0x1b;
      }
    }
LAB_00055c1e:
    pbVar12 = local_52c;
    uVar11 = (uint)*local_52c;
    if (uVar11 != 0) {
      ppuVar6 = __ctype_b_loc();
      do {
        if (-1 < (int)((uint)(*ppuVar6)[uVar11] << 0x12)) {
          if (uVar11 == 0x2c) {
            local_52c = pbVar12 + 1;
          }
          break;
        }
        local_52c = pbVar12 + 1;
        uVar11 = (uint)pbVar12[1];
        pbVar12 = local_52c;
      } while (uVar11 != 0);
    }
  } while( true );
}

