
/* WARNING: Type propagation algorithm not settling */

undefined4 Curl_sasl_decode_digest_http_message(byte *param_1,int *param_2)

{
  byte bVar1;
  char cVar2;
  bool bVar3;
  bool bVar4;
  code **ppcVar5;
  code **ppcVar6;
  char *pcVar7;
  ushort **ppuVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  char *pcVar12;
  uint uVar13;
  byte *pbVar14;
  char *pcVar15;
  byte *local_52c;
  undefined auStack_528 [256];
  undefined auStack_428 [1028];
  
  iVar11 = *param_2;
  bVar4 = false;
  bVar3 = false;
  local_52c = param_1;
  Curl_sasl_digest_cleanup(param_2);
  do {
    bVar1 = *local_52c;
    pbVar14 = local_52c;
    while ((local_52c = pbVar14, bVar1 != 0 &&
           (ppuVar8 = __ctype_b_loc(), (int)((uint)(*ppuVar8)[bVar1] << 0x12) < 0))) {
      pbVar14 = pbVar14 + 1;
      bVar1 = *pbVar14;
    }
    iVar9 = Curl_sasl_digest_get_pair(pbVar14,auStack_528,auStack_428,&local_52c);
    if (iVar9 == 0) {
      if (((iVar11 == 0) || (*(char *)(param_2 + 4) != '\0')) && (*param_2 != 0)) {
        return 0;
      }
      return 0x3d;
    }
    iVar9 = Curl_raw_equal(auStack_528,DAT_00055e28);
    if (iVar9 != 0) {
      (**DAT_00055e2c)(*param_2);
      iVar9 = (**DAT_00055e30)(auStack_428);
      *param_2 = iVar9;
      goto joined_r0x00055d0e;
    }
    iVar9 = Curl_raw_equal(auStack_528,DAT_00055e34);
    if (iVar9 != 0) {
      iVar9 = Curl_raw_equal(auStack_428,DAT_00055e38);
      if (iVar9 != 0) {
        *(undefined *)(param_2 + 4) = 1;
        param_2[8] = 1;
      }
      goto LAB_00055c1e;
    }
    iVar9 = Curl_raw_equal(auStack_528,DAT_00055e3c);
    if (iVar9 == 0) {
      iVar9 = Curl_raw_equal(auStack_528,DAT_00055e40);
      if (iVar9 != 0) {
        (**DAT_00055e2c)(param_2[5]);
        iVar9 = (**DAT_00055e30)(auStack_428);
        param_2[5] = iVar9;
        goto joined_r0x00055d0e;
      }
      iVar9 = Curl_raw_equal(auStack_528,DAT_00055e44);
      ppcVar6 = DAT_00055e30;
      if (iVar9 != 0) {
        pcVar10 = (char *)(**DAT_00055e30)(auStack_428);
        if (pcVar10 == (char *)0x0) {
          return 0x1b;
        }
        cVar2 = *pcVar10;
        pcVar12 = pcVar10;
        while (cVar2 == ',') {
          pcVar12 = pcVar12 + 1;
          cVar2 = *pcVar12;
        }
        pcVar7 = pcVar12 + 1;
        if (cVar2 != '\0') {
          do {
            pcVar15 = pcVar7;
            if (*pcVar15 == '\0') goto LAB_00055d26;
            pcVar7 = pcVar15 + 1;
          } while (*pcVar15 != ',');
          *pcVar15 = '\0';
          pcVar15 = pcVar15 + 1;
LAB_00055d26:
          if (pcVar12 != (char *)0x0) {
            iVar9 = Curl_raw_equal(pcVar12,DAT_00055e4c);
            if (iVar9 == 0) goto LAB_00055d7e;
            do {
              cVar2 = *pcVar15;
              bVar3 = true;
              pcVar12 = pcVar15;
joined_r0x00055d42:
              while (cVar2 == ',') {
                cVar2 = pcVar12[1];
                pcVar12 = pcVar12 + 1;
              }
              if (cVar2 == '\0') goto LAB_00055ce8;
              pcVar7 = pcVar12 + 1;
              do {
                pcVar15 = pcVar7;
                if (*pcVar15 == '\0') goto joined_r0x00055df6;
                pcVar7 = pcVar15 + 1;
              } while (*pcVar15 != ',');
              *pcVar15 = '\0';
              pcVar15 = pcVar15 + 1;
joined_r0x00055df6:
              if (pcVar12 == (char *)0x0) goto LAB_00055ce8;
              iVar9 = Curl_raw_equal(pcVar12,DAT_00055e4c);
            } while (iVar9 != 0);
LAB_00055d7e:
            iVar9 = Curl_raw_equal(pcVar12,DAT_00055e48);
            cVar2 = *pcVar15;
            pcVar12 = pcVar15;
            if (iVar9 != 0) {
              bVar4 = true;
            }
            goto joined_r0x00055d42;
          }
        }
LAB_00055ce8:
        ppcVar5 = DAT_00055e2c;
        (**DAT_00055e2c)(pcVar10);
        if (bVar3) {
          (**ppcVar5)(param_2[6]);
          iVar9 = (**ppcVar6)(DAT_00055e4c);
          param_2[6] = iVar9;
        }
        else {
          if (!bVar4) goto LAB_00055c1e;
          (**ppcVar5)(param_2[6]);
          iVar9 = (**ppcVar6)(DAT_00055e48);
          param_2[6] = iVar9;
        }
        goto joined_r0x00055d0e;
      }
      iVar9 = Curl_raw_equal(auStack_528,DAT_00055e50);
      if (iVar9 != 0) {
        (**DAT_00055e2c)(param_2[7]);
        iVar9 = (**DAT_00055e30)(auStack_428);
        param_2[7] = iVar9;
        if (iVar9 == 0) {
          return 0x1b;
        }
        iVar9 = Curl_raw_equal(auStack_428,DAT_00055e54);
        if (iVar9 == 0) {
          iVar9 = Curl_raw_equal(auStack_428,DAT_00055e58);
          if (iVar9 == 0) {
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
      (**DAT_00055e2c)(param_2[2]);
      iVar9 = (**DAT_00055e30)(auStack_428);
      param_2[2] = iVar9;
joined_r0x00055d0e:
      if (iVar9 == 0) {
        return 0x1b;
      }
    }
LAB_00055c1e:
    pbVar14 = local_52c;
    uVar13 = (uint)*local_52c;
    if (uVar13 != 0) {
      ppuVar8 = __ctype_b_loc();
      do {
        if (-1 < (int)((uint)(*ppuVar8)[uVar13] << 0x12)) {
          if (uVar13 == 0x2c) {
            local_52c = pbVar14 + 1;
          }
          break;
        }
        local_52c = pbVar14 + 1;
        uVar13 = (uint)pbVar14[1];
        pbVar14 = local_52c;
      } while (uVar13 != 0);
    }
  } while( true );
}

