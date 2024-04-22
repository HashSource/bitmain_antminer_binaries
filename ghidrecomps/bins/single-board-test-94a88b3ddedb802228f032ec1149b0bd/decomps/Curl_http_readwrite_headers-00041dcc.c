
/* WARNING: Type propagation algorithm not settling */

uint Curl_http_readwrite_headers(int param_1,int param_2,size_t *param_3,char *param_4)

{
  byte bVar1;
  char cVar2;
  void *pvVar3;
  uint uVar4;
  ushort **ppuVar5;
  char *pcVar6;
  int iVar7;
  undefined4 uVar8;
  ushort *puVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  char cVar13;
  char *pcVar14;
  byte *pbVar15;
  size_t sVar16;
  uint uVar17;
  size_t sVar18;
  longlong lVar19;
  int local_34;
  int local_30;
  time_t local_2c [2];
  
  pcVar14 = *(char **)(param_1 + 0xac);
  do {
    sVar16 = *param_3;
    *(char **)(param_1 + 0xb0) = pcVar14;
    pvVar3 = memchr(pcVar14,10,sVar16);
    *(void **)(param_1 + 0xb4) = pvVar3;
    if (pvVar3 == (void *)0x0) {
      uVar4 = header_append(param_1,param_1 + 0x50,sVar16);
      if (uVar4 != 0) {
        return uVar4;
      }
      if (*(int *)(param_1 + 0xa0) != 0) {
        return 0;
      }
      if (*(uint *)(param_1 + 0xa8) < 6) {
        return 0;
      }
      iVar7 = checkprotoprefix(param_1,param_2,*(undefined4 *)(param_1 + 0x594));
      if (iVar7 == 0) {
        *(undefined *)(param_1 + 0x98) = 0;
        *(undefined4 *)(param_1 + 0x9c) = 2;
        return 0;
      }
      return 0;
    }
    sVar18 = (int)pvVar3 + (1 - (int)pcVar14);
    *param_3 = sVar16 - sVar18;
    *(int *)(param_1 + 0xac) = (int)pvVar3 + 1;
    uVar4 = header_append(param_1,param_1 + 0x50,((int)pvVar3 + 1) - (int)pcVar14);
    if (uVar4 != 0) {
      return uVar4;
    }
    pcVar14 = *(char **)(param_1 + 0x594);
    *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_1 + 0xa4);
    *(char **)(param_1 + 0xb8) = pcVar14;
    if ((*(int *)(param_1 + 0xa0) == 0) && (5 < *(uint *)(param_1 + 0xa8))) {
      iVar7 = checkprotoprefix(param_1,param_2,pcVar14);
      if (iVar7 == 0) {
        sVar16 = *param_3;
        *(undefined *)(param_1 + 0x98) = 0;
        if (sVar16 == 0) {
          *(undefined4 *)(param_1 + 0x9c) = 2;
          *param_3 = sVar18;
          return 0;
        }
        *(undefined4 *)(param_1 + 0x9c) = 1;
        return 0;
      }
      pcVar14 = *(char **)(param_1 + 0xb8);
    }
    cVar13 = *pcVar14;
    if (cVar13 == '\r' || cVar13 == '\n') {
      pcVar6 = pcVar14;
      if (cVar13 == '\r') {
        pcVar6 = pcVar14 + 1;
        *(char **)(param_1 + 0xb8) = pcVar6;
        cVar13 = pcVar14[1];
      }
      if (cVar13 == '\n') {
        pcVar6 = pcVar6 + 1;
      }
      if (cVar13 == '\n') {
        *(char **)(param_1 + 0xb8) = pcVar6;
      }
      iVar7 = *(int *)(param_1 + 200);
      if (iVar7 - 100U < 100) {
        *(undefined *)(param_1 + 0x98) = 1;
        *(undefined4 *)(param_1 + 0xa0) = 0;
        if (iVar7 == 100) {
          if (*(int *)(param_1 + 0xd4) != 0) {
            *(undefined4 *)(param_1 + 0xd4) = 0;
            *(uint *)(param_1 + 0x130) = *(uint *)(param_1 + 0x130) | 2;
          }
        }
        else if ((iVar7 == 0x65) && (*(int *)(param_1 + 0xd8) == 1)) {
          Curl_infof(param_1,DAT_00042558);
          *(undefined4 *)(param_1 + 0xd8) = 2;
          return 1;
        }
LAB_00041e98:
        if (*(char *)(param_2 + 0x1ed) != '\0') {
          iVar7 = *(int *)(param_1 + 200);
LAB_00041ea2:
          if (iVar7 == 0x191) {
            iVar7 = *(int *)(param_2 + 0x274);
          }
          else {
            if (iVar7 != 0x197) goto LAB_00041eb6;
            iVar7 = *(int *)(param_2 + 0x28c);
          }
          if (iVar7 == 2) {
            Curl_infof(param_1,DAT_00042554);
            *(undefined *)(param_1 + 0x8640) = 1;
          }
        }
      }
      else {
        *(undefined *)(param_1 + 0x98) = 0;
        if ((*(int *)(param_1 + 0x54) != -1 || *(int *)(param_1 + 0x50) != -1) ||
           (*(char *)(param_1 + 0x148) != '\0')) goto LAB_00041e98;
        if (*(char *)(param_2 + 0x1ed) != '\0') goto LAB_00041ea2;
        if (((*(int *)(param_2 + 0x13c) == 0xb) &&
            (-1 < *(int *)(*(int *)(param_2 + 0x218) + 0x3c) << 0xd)) &&
           (*(int *)(param_1 + 0x278) != 5)) {
          Curl_infof(param_1,DAT_00042288);
          iVar7 = *(int *)(param_1 + 200);
          *(undefined *)(param_2 + 0x1ed) = 1;
          goto LAB_00041ea2;
        }
      }
LAB_00041eb6:
      iVar7 = http_should_fail(param_2);
      if (iVar7 != 0) {
        Curl_failf(param_1,DAT_000428a4,*(undefined4 *)(param_1 + 200));
        return 0x16;
      }
      iVar7 = *(int *)(param_1 + 0xb8) - *(int *)(param_1 + 0x594);
      if (*(char *)(param_1 + 0x304) == '\0') {
        uVar8 = 2;
      }
      else {
        uVar8 = 3;
      }
      uVar4 = Curl_client_write(param_2,uVar8,*(int *)(param_1 + 0x594),iVar7);
      if (uVar4 != 0) {
        return uVar4;
      }
      cVar13 = *param_4;
      iVar10 = *(int *)(param_1 + 0x80) + iVar7;
      *(int *)(param_1 + 0x80) = iVar10;
      if (99 < *(int *)(param_1 + 200) - 100U) {
        iVar10 = 0;
      }
      *(int *)(param_1 + 0x84) = iVar10;
      *(int *)(param_1 + 0x8708) = *(int *)(param_1 + 0x8708) + iVar7;
      if (cVar13 == '\0') {
        uVar4 = Curl_http_auth_act(param_2);
        if (uVar4 != 0) {
          return uVar4;
        }
        if (((*(int *)(param_1 + 200) < 300) || (*(char *)(param_2 + 0x1fb) != '\0')) ||
           (*(char *)(param_2 + 0x1ed) != '\0')) {
          cVar13 = *(char *)(param_2 + 0x1fc);
joined_r0x00042220:
          if (cVar13 == '\0') goto LAB_00041f18;
        }
        else if (*(char *)(param_2 + 0x1fc) == '\0') {
          if ((2 < *(int *)(param_1 + 0x278) - 2U) || (*(char *)(param_1 + 0x134) != '\0'))
          goto LAB_00041f18;
          Curl_infof(param_1,DAT_00042298);
          uVar4 = *(uint *)(param_1 + 0x130);
          cVar2 = *(char *)(param_1 + 0x867c);
          *(undefined *)(param_2 + 0x1ed) = 1;
          *(undefined *)(param_1 + 0x134) = 1;
          *(uint *)(param_1 + 0x130) = uVar4 & 0xfffffffd;
          cVar13 = *(char *)(param_2 + 0x1fc);
          if (cVar2 != '\0') {
            *(undefined4 *)(param_1 + 0xd4) = 3;
          }
          goto joined_r0x00042220;
        }
        Curl_infof(param_1,DAT_0004229c);
        *(uint *)(param_1 + 0x130) = *(uint *)(param_1 + 0x130) | 2;
      }
LAB_00041f18:
      if (*(char *)(param_1 + 0x98) == '\0') {
        if (*(char *)(param_1 + 0x307) == '\0') {
          if ((*(int *)(*(int *)(param_2 + 0x218) + 0x3c) << 0xd < 0) &&
             (*(int *)(param_1 + 0x40c) == 2)) {
            iVar10 = *(int *)(param_1 + 0x50);
            iVar11 = *(int *)(param_1 + 0x54);
            if (iVar11 < 0) {
              *param_4 = '\x01';
              goto LAB_00041f36;
            }
          }
          if (*(char *)(param_1 + 0x148) == '\0') {
            iVar10 = *(int *)(param_1 + 0x50);
            iVar11 = *(int *)(param_1 + 0x54);
            goto LAB_00041f36;
          }
          *(undefined4 *)(param_1 + 0x50) = 0xffffffff;
          *(undefined4 *)(param_1 + 0x54) = 0xffffffff;
          *(undefined4 *)(param_1 + 0x60) = 0xffffffff;
          *(undefined4 *)(param_1 + 100) = 0xffffffff;
LAB_00042116:
          uVar4 = *(uint *)(param_1 + 0x60);
          uVar17 = *(uint *)(param_1 + 100);
        }
        else {
          iVar10 = *(int *)(param_1 + 0x50);
          iVar11 = *(int *)(param_1 + 0x54);
          *param_4 = '\x01';
LAB_00041f36:
          if (iVar11 == -1 && iVar10 == -1) goto LAB_00042116;
          Curl_pgrsSetDownloadSize(param_1);
          uVar4 = *(uint *)(param_1 + 0x50);
          uVar17 = *(uint *)(param_1 + 0x54);
          *(uint *)(param_1 + 0x60) = uVar4;
          *(uint *)(param_1 + 100) = uVar17;
        }
        if ((uVar4 | uVar17) == 0) {
          *param_4 = '\x01';
        }
        else if (*param_4 == '\0') {
          bVar1 = *(byte *)(param_1 + 0x310);
          goto joined_r0x00042238;
        }
        bVar1 = *(byte *)(param_1 + 0x310);
        *(uint *)(param_1 + 0x130) = *(uint *)(param_1 + 0x130) & 0xfffffffe;
joined_r0x00042238:
        uVar4 = (uint)bVar1;
        if (uVar4 != 0) {
          uVar4 = 0;
          Curl_debug(param_1,1,*(undefined4 *)(param_1 + 0xb0),iVar7,param_2);
        }
        return uVar4;
      }
      *(undefined4 *)(param_1 + 0xa8) = 0;
      *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_1 + 0x594);
    }
    else {
      iVar7 = *(int *)(param_1 + 0xa0);
      *(int *)(param_1 + 0xa0) = iVar7 + 1;
      if (iVar7 == 0) {
        uVar4 = *(uint *)(*(int *)(param_2 + 0x218) + 0x3c);
        if ((uVar4 & 3) == 0) {
          if ((-1 < (int)(uVar4 << 0xd)) ||
             (iVar7 = __isoc99_sscanf(pcVar14,DAT_00042578,&local_30,param_2 + 0x140,param_1 + 200),
             iVar7 != 3)) {
LAB_0004203a:
            *(undefined *)(param_1 + 0x98) = 0;
            return 0;
          }
          iVar7 = 0xb;
          *(undefined4 *)(param_2 + 0x13c) = 0xb;
          *(int *)(param_2 + 0x140) = *(int *)(param_2 + 0x140) + local_30 * 10;
        }
        else {
          iVar7 = __isoc99_sscanf(pcVar14,DAT_00042550,&local_34,param_2 + 0x13c,param_1 + 200);
          if (iVar7 == 3) {
            iVar10 = *(int *)(param_1 + 0xd8);
            iVar7 = *(int *)(param_2 + 0x13c) + local_34 * 10;
            *(int *)(param_2 + 0x13c) = iVar7;
            if ((iVar10 == 2) && (iVar7 != 0x14)) {
              Curl_infof(param_1,DAT_000428a0);
              iVar7 = *(int *)(param_2 + 0x13c);
            }
          }
          else {
            iVar10 = __isoc99_sscanf(*(undefined4 *)(param_1 + 0xb8),DAT_0004257c,param_1 + 200);
            *(undefined4 *)(param_2 + 0x13c) = 10;
            iVar7 = 10;
            if (iVar10 == 0) {
              iVar7 = checkhttpprefix(param_1,*(undefined4 *)(param_1 + 0xb8));
              if (iVar7 == 0) goto LAB_0004203a;
              iVar7 = 10;
              *(undefined4 *)(param_1 + 200) = 200;
              *(undefined4 *)(param_2 + 0x13c) = 10;
            }
          }
        }
        iVar10 = *(int *)(param_1 + 200);
        *(int *)(param_1 + 0x86fc) = iVar7;
        *(int *)(param_1 + 0x86f4) = iVar10;
        if ((*(int *)(param_1 + 0x8678) == 0) || (iVar7 < *(int *)(param_1 + 0x8678))) {
          *(int *)(param_1 + 0x8678) = iVar7;
        }
        if ((*(char *)(param_1 + 0x300) != '\0') && (399 < iVar10)) {
          if (iVar10 == 0x191) {
            cVar13 = *(char *)(param_2 + 0x1f1);
joined_r0x0004277a:
            if (cVar13 != '\0') goto LAB_00042332;
          }
          else if (iVar10 == 0x197) {
            cVar13 = *(char *)(param_2 + 0x1f2);
            goto joined_r0x0004277a;
          }
          if ((((*(uint *)(param_1 + 0x8698) | *(uint *)(param_1 + 0x869c)) == 0) ||
              (*(int *)(param_1 + 0x278) != 1)) || (iVar10 != 0x1a0)) {
            pcVar14 = *(char **)(param_1 + 0xb8);
            iVar7 = strncmp(pcVar14,DAT_00042b2c,4);
            if (((iVar7 == 0) && (pcVar14 = strchr(pcVar14,0x20), pcVar14 != (char *)0x0)) &&
               (pcVar14[1] != '\0')) {
              pcVar14 = pcVar14 + 1;
              pcVar6 = strchr(pcVar14,0xd);
              if (pcVar6 == (char *)0x0) {
                pcVar6 = strchr(pcVar14,10);
                if (pcVar6 == (char *)0x0) goto LAB_0004293c;
                cVar13 = '\n';
              }
              else {
                cVar13 = '\r';
              }
              *pcVar6 = '\0';
              Curl_failf(param_1,DAT_00042b30,pcVar14);
              *pcVar6 = cVar13;
            }
            else {
LAB_0004293c:
              Curl_failf(param_1,DAT_00042b38,iVar10);
            }
            return 0x16;
          }
        }
LAB_00042332:
        if (iVar7 == 10) {
          Curl_infof(param_1,DAT_00042580);
          iVar10 = *(int *)(param_1 + 200);
          *(undefined *)(param_2 + 0x1ed) = 1;
        }
        else if ((iVar7 == 0x14) || ((*(int *)(param_1 + 0xd8) == 1 && (iVar10 == 0x65)))) {
          **(undefined4 **)(param_2 + 0x470) = 2;
        }
        else if (((10 < iVar7) && (*(char *)(param_2 + 0x1ed) == '\0')) &&
                (*(int *)(param_2 + 0x470) != 0)) {
          iVar7 = Curl_pipeline_site_blacklisted(param_1,param_2);
          iVar10 = *(int *)(param_1 + 200);
          if (iVar7 == 0) {
            **(undefined4 **)(param_2 + 0x470) = 1;
          }
        }
        if ((iVar10 == 0xcc) || (iVar10 == 0x130)) {
          if (*(int *)(param_1 + 0x270) != 0) {
            *(undefined *)(param_1 + 0x8704) = 1;
          }
          cVar13 = '\x01';
          *(undefined *)(param_1 + 0x136) = 1;
          *(undefined4 *)(param_1 + 0x50) = 0;
          *(undefined4 *)(param_1 + 0x54) = 0;
          *(undefined4 *)(param_1 + 0x60) = 0;
          *(undefined4 *)(param_1 + 100) = 0;
        }
        else {
          cVar13 = *(char *)(param_1 + 0x136);
        }
        pcVar14 = *(char **)(param_1 + 0xb8);
      }
      else {
        cVar13 = *(char *)(param_1 + 0x136);
      }
      if ((cVar13 == '\0') && (*(char *)(param_1 + 0x327) == '\0')) {
        iVar7 = Curl_raw_nequal(DAT_000422a0,pcVar14,0xf);
        if (iVar7 == 0) {
          pcVar14 = *(char **)(param_1 + 0xb8);
          goto LAB_00041f9c;
        }
        lVar19 = strtoll((char *)(*(int *)(param_1 + 0xb8) + 0xf),(char **)0x0,10);
        iVar7 = (int)((ulonglong)lVar19 >> 0x20);
        uVar4 = (uint)lVar19;
        uVar17 = *(uint *)(param_1 + 0x2e0);
        uVar12 = *(uint *)(param_1 + 0x2e4);
        if (((uVar17 | uVar12) != 0) &&
           ((int)((uVar12 - iVar7) - (uint)(uVar17 < uVar4)) < 0 !=
            (SBORROW4(uVar12,iVar7) != SBORROW4(uVar12 - iVar7,(uint)(uVar17 < uVar4))))) {
          Curl_failf(param_1,DAT_00042574);
          return 0x3f;
        }
        if (lVar19 < 0) {
          *(undefined *)(param_2 + 0x1ed) = 1;
          Curl_infof(param_1,DAT_00042890,uVar4,iVar7);
          iVar7 = *(int *)(param_1 + 0xb8);
        }
        else {
          *(longlong *)(param_1 + 0x50) = lVar19;
          *(longlong *)(param_1 + 0x60) = lVar19;
          Curl_pgrsSetDownloadSize(param_1,iVar7,uVar4,iVar7);
          iVar7 = *(int *)(param_1 + 0xb8);
        }
      }
      else {
LAB_00041f9c:
        iVar7 = Curl_raw_nequal(DAT_00042280,pcVar14,0xd);
        if (iVar7 == 0) {
          iVar7 = Curl_raw_nequal(DAT_0004228c,*(undefined4 *)(param_1 + 0xb8),7);
          iVar10 = *(int *)(param_2 + 0x13c);
          if (iVar7 != 0) {
            if (iVar10 < 0x14) {
              uVar8 = Curl_copy_header_value(*(undefined4 *)(param_1 + 0xb8));
              if (((*(int **)(param_2 + 0x470) != (int *)0x0) && (**(int **)(param_2 + 0x470) == 1))
                 && (iVar7 = Curl_pipeline_server_blacklisted(param_1,uVar8), iVar7 != 0)) {
                **(undefined4 **)(param_2 + 0x470) = 0xffffffff;
              }
              (**DAT_0004255c)(uVar8);
              iVar7 = *(int *)(param_1 + 0xb8);
              goto LAB_00041fd8;
            }
            goto LAB_000420e2;
          }
          if (iVar10 == 10) {
            if (*(char *)(param_2 + 0x1f0) != '\0') {
              iVar7 = Curl_compareheader(*(undefined4 *)(param_1 + 0xb8),DAT_000428a8,DAT_000428ac);
              if (iVar7 != 0) {
                *(undefined *)(param_2 + 0x1ed) = 0;
                Curl_infof(param_1,DAT_00042b28);
                iVar7 = *(int *)(param_1 + 0xb8);
                goto LAB_00041fd8;
              }
              iVar10 = *(int *)(param_2 + 0x13c);
              goto LAB_00042122;
            }
LAB_000423fe:
            iVar7 = Curl_compareheader(*(undefined4 *)(param_1 + 0xb8),DAT_00042560,DAT_00042564);
            if (iVar7 != 0) {
              *(undefined *)(param_2 + 0x1ed) = 0;
              Curl_infof(param_1,DAT_00042568);
              iVar7 = *(int *)(param_1 + 0xb8);
              goto LAB_00041fd8;
            }
          }
          else {
LAB_00042122:
            if (iVar10 == 0xb) {
              if (*(char *)(param_2 + 0x1f0) != '\0') {
                iVar7 = Curl_compareheader(*(undefined4 *)(param_1 + 0xb8),DAT_0004256c,DAT_00042570
                                          );
                if (iVar7 != 0) {
                  *(undefined *)(param_2 + 0x1ed) = 1;
                  Curl_infof(param_1,DAT_00042b34);
                  iVar7 = *(int *)(param_1 + 0xb8);
                  goto LAB_00041fd8;
                }
                iVar10 = *(int *)(param_2 + 0x13c);
                goto LAB_00042128;
              }
            }
            else {
LAB_00042128:
              if (iVar10 == 10) goto LAB_000423fe;
            }
          }
          iVar7 = Curl_compareheader(*(undefined4 *)(param_1 + 0xb8),DAT_00042290,DAT_00042294);
          if (iVar7 == 0) {
            iVar7 = Curl_raw_nequal(DAT_00042878,*(undefined4 *)(param_1 + 0xb8),0x12);
            if (iVar7 != 0) {
              pbVar15 = (byte *)(*(int *)(param_1 + 0xb8) + 0x12);
LAB_0004259a:
              do {
                bVar1 = *pbVar15;
                while( true ) {
                  uVar4 = (uint)bVar1;
                  if ((uVar4 != 0) &&
                     ((ppuVar5 = __ctype_b_loc(), (int)((uint)(*ppuVar5)[uVar4] << 0x12) < 0 ||
                      (uVar4 == 0x2c)))) {
                    pbVar15 = pbVar15 + 1;
                    goto LAB_0004259a;
                  }
                  iVar7 = Curl_raw_nequal(DAT_0004287c,pbVar15,7);
                  if (iVar7 != 0) {
                    *(undefined *)(param_1 + 0x148) = 1;
                    pbVar15 = pbVar15 + 7;
                    Curl_httpchunk_init(param_2);
                  }
                  if (*(int *)(param_1 + 0xdc) != 0) goto LAB_000420e2;
                  iVar7 = Curl_raw_nequal(DAT_00042880,pbVar15,8);
                  if (iVar7 == 0) break;
                  pbVar15 = pbVar15 + 8;
                  *(undefined4 *)(param_1 + 0xdc) = 0;
                  bVar1 = *pbVar15;
                }
                iVar7 = Curl_raw_nequal(DAT_00042894,pbVar15,7);
                if (iVar7 != 0) {
                  pbVar15 = pbVar15 + 7;
                  *(undefined4 *)(param_1 + 0xdc) = 1;
                  goto LAB_0004259a;
                }
                iVar7 = Curl_raw_nequal(DAT_00042898,pbVar15,4);
                if (iVar7 == 0) {
                  iVar7 = Curl_raw_nequal(DAT_0004289c,pbVar15,6);
                  if (iVar7 == 0) goto LAB_000420e2;
                  pbVar15 = pbVar15 + 6;
                  *(undefined4 *)(param_1 + 0xdc) = 2;
                }
                else {
                  pbVar15 = pbVar15 + 4;
                  *(undefined4 *)(param_1 + 0xdc) = 2;
                }
              } while( true );
            }
            iVar7 = Curl_raw_nequal(DAT_0004288c,*(undefined4 *)(param_1 + 0xb8),0x11);
            if ((iVar7 == 0) || (*(int *)(param_1 + 0x35c) == 0)) {
              iVar7 = Curl_raw_nequal(DAT_000428b0,*(undefined4 *)(param_1 + 0xb8),0xe);
              if (iVar7 == 0) {
                if ((*(int *)(param_1 + 0x468) == 0) ||
                   (iVar7 = Curl_raw_nequal(DAT_00042b3c,*(undefined4 *)(param_1 + 0xb8),0xb),
                   iVar7 == 0)) {
                  iVar7 = Curl_raw_nequal(DAT_00042b40,*(undefined4 *)(param_1 + 0xb8),0xe);
                  if ((iVar7 != 0) &&
                     ((*(int *)(param_1 + 0x270) != 0 || (*(char *)(param_1 + 0x2f9) != '\0')))) {
                    local_2c[0] = time((time_t *)0x0);
                    uVar8 = curl_getdate(*(int *)(param_1 + 0xb8) + 0xe,local_2c);
                    *(undefined4 *)(param_1 + 0x11c) = uVar8;
                    if (*(char *)(param_1 + 0x2f9) != '\0') {
                      *(undefined4 *)(param_1 + 0x8700) = uVar8;
                    }
                    goto LAB_000420e2;
                  }
                  iVar7 = Curl_raw_nequal(DAT_00042884,*(undefined4 *)(param_1 + 0xb8),0x11);
                  if ((iVar7 == 0) || (iVar7 = *(int *)(param_1 + 200), iVar7 != 0x191)) {
                    iVar10 = Curl_raw_nequal(DAT_00042888,*(undefined4 *)(param_1 + 0xb8),0x13);
                    iVar7 = *(int *)(param_1 + 200);
                    if ((iVar10 != 0) && (iVar7 == 0x197)) goto LAB_00042a5a;
                    if (((99 < iVar7 - 300U) ||
                        (iVar7 = Curl_raw_nequal(DAT_00042b54,*(undefined4 *)(param_1 + 0xb8),9),
                        iVar7 == 0)) || (*(int *)(param_1 + 0x138) != 0)) {
                      if (-1 < *(int *)(*(int *)(param_2 + 0x218) + 0x3c) << 0xd) goto LAB_000420e2;
                      uVar4 = Curl_rtsp_parseheader(param_2,*(undefined4 *)(param_1 + 0xb8));
                      goto joined_r0x00042b1a;
                    }
                    pcVar14 = (char *)Curl_copy_header_value(*(undefined4 *)(param_1 + 0xb8));
                    if (pcVar14 == (char *)0x0) {
                      return 0x1b;
                    }
                    if (*pcVar14 == '\0') goto LAB_0004214c;
                    *(char **)(param_1 + 0x138) = pcVar14;
                    if (*(char *)(param_1 + 0x301) != '\0') {
                      iVar7 = (**DAT_00042b58)();
                      *(int *)(param_1 + 0x13c) = iVar7;
                      if (iVar7 == 0) {
                        return 0x1b;
                      }
                      uVar4 = http_perhapsrewind(param_2);
                      goto joined_r0x00042b1a;
                    }
                  }
                  else {
LAB_00042a5a:
                    iVar10 = Curl_copy_header_value(*(undefined4 *)(param_1 + 0xb8));
                    if (iVar10 == 0) {
                      return 0x1b;
                    }
                    uVar4 = Curl_http_input_auth(param_2,iVar7 == 0x197,iVar10);
                    (**DAT_00042b4c)(iVar10);
joined_r0x00042b1a:
                    if (uVar4 != 0) {
                      return uVar4;
                    }
                  }
LAB_000420e2:
                  iVar7 = *(int *)(param_1 + 0xb8);
                }
                else {
                  Curl_share_lock(param_1,2,2);
                  iVar7 = *(int *)(param_2 + 0x248);
                  if (iVar7 == 0) {
                    iVar7 = *(int *)(param_2 + 0x98);
                  }
                  Curl_cookie_add(param_1,*(undefined4 *)(param_1 + 0x468),1,
                                  *(int *)(param_1 + 0xb8) + 0xb,iVar7,
                                  *(undefined4 *)(param_1 + 0x868c));
                  Curl_share_unlock(param_1,2);
                  iVar7 = *(int *)(param_1 + 0xb8);
                }
              }
              else {
                iVar7 = *(int *)(param_1 + 0xb8);
                uVar4 = (uint)*(byte *)(iVar7 + 0xe);
                pbVar15 = (byte *)(iVar7 + 0xe);
                if (uVar4 == 0) {
                  ppuVar5 = __ctype_b_loc();
                  puVar9 = *ppuVar5;
                  uVar4 = 0;
                }
                else {
                  ppuVar5 = __ctype_b_loc();
                  puVar9 = *ppuVar5;
                  do {
                    if ((int)((uint)puVar9[uVar4] << 0x14) < 0) goto LAB_00042848;
                    if (uVar4 == 0x2a) {
                      uVar4 = 0x54;
                      break;
                    }
                    pbVar15 = pbVar15 + 1;
                    uVar4 = (uint)*pbVar15;
                  } while (uVar4 != 0);
                }
                if ((int)((uint)*(ushort *)((int)puVar9 + uVar4) << 0x14) < 0) {
LAB_00042848:
                  lVar19 = strtoll((char *)pbVar15,(char **)0x0,10);
                  *(longlong *)(param_1 + 0xc0) = lVar19;
                  if ((int)((ulonglong)lVar19 >> 0x20) != *(int *)(param_1 + 0x869c) ||
                      (int)lVar19 != *(int *)(param_1 + 0x8698)) goto LAB_000420e2;
                  iVar7 = *(int *)(param_1 + 0xb8);
                  *(undefined *)(param_1 + 0xbc) = 1;
                }
                else {
                  *(undefined4 *)(param_1 + 0x8698) = 0;
                  *(undefined4 *)(param_1 + 0x869c) = 0;
                }
              }
            }
            else {
              uVar4 = (uint)*(byte *)(*(int *)(param_1 + 0xb8) + 0x11);
              pbVar15 = (byte *)(*(int *)(param_1 + 0xb8) + 0x11);
              if (uVar4 != 0) {
                ppuVar5 = __ctype_b_loc();
                do {
                  if (-1 < (int)((uint)(*ppuVar5)[uVar4] << 0x12)) break;
                  pbVar15 = pbVar15 + 1;
                  uVar4 = (uint)*pbVar15;
                } while (uVar4 != 0);
              }
              iVar7 = Curl_raw_nequal(DAT_00042880,pbVar15,8);
              if (iVar7 == 0) {
                iVar7 = Curl_raw_nequal(DAT_00042b44,pbVar15,7);
                if (iVar7 == 0) {
                  iVar7 = Curl_raw_nequal(DAT_00042b48,pbVar15,4);
                  if ((iVar7 == 0) && (iVar7 = Curl_raw_nequal(DAT_00042b50,pbVar15,6), iVar7 == 0))
                  goto LAB_000420e2;
                  iVar7 = *(int *)(param_1 + 0xb8);
                  *(undefined4 *)(param_1 + 0xdc) = 2;
                }
                else {
                  iVar7 = *(int *)(param_1 + 0xb8);
                  *(undefined4 *)(param_1 + 0xdc) = 1;
                }
              }
              else {
                iVar7 = *(int *)(param_1 + 0xb8);
                *(undefined4 *)(param_1 + 0xdc) = 0;
              }
            }
          }
          else {
            iVar7 = *(int *)(param_1 + 0xb8);
            *(undefined *)(param_2 + 0x1ed) = 1;
          }
        }
        else {
          pcVar14 = (char *)Curl_copy_header_value(*(undefined4 *)(param_1 + 0xb8));
          if (pcVar14 == (char *)0x0) {
            return 0x1b;
          }
          if (*pcVar14 != '\0') {
            (**DAT_00042284)(*(undefined4 *)(param_1 + 0x871c));
            iVar7 = *(int *)(param_1 + 0xb8);
            *(char **)(param_1 + 0x871c) = pcVar14;
            goto LAB_00041fd8;
          }
LAB_0004214c:
          (**DAT_00042284)();
          iVar7 = *(int *)(param_1 + 0xb8);
        }
      }
LAB_00041fd8:
      if (*(char *)(param_1 + 0x304) == '\0') {
        uVar8 = 2;
      }
      else {
        uVar8 = 3;
      }
      if (*(char *)(param_1 + 0x310) != '\0') {
        Curl_debug(param_1,1,iVar7,*(undefined4 *)(param_1 + 0xa8),param_2);
        iVar7 = *(int *)(param_1 + 0xb8);
      }
      uVar4 = Curl_client_write(param_2,uVar8,iVar7,*(undefined4 *)(param_1 + 0xa8));
      if (uVar4 != 0) {
        return uVar4;
      }
      *(int *)(param_1 + 0x8708) = *(int *)(param_1 + 0x8708) + *(int *)(param_1 + 0xa8);
      *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) + *(int *)(param_1 + 0xa8);
      *(undefined4 *)(param_1 + 0xa8) = 0;
      *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_1 + 0x594);
    }
    if (*param_4 != '\0') {
      return 0;
    }
    pcVar14 = *(char **)(param_1 + 0xac);
    if (*pcVar14 == '\0') {
      return 0;
    }
  } while( true );
}

