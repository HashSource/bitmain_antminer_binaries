
/* WARNING: Type propagation algorithm not settling */

int Curl_readwrite(int *param_1,int param_2,char *param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  char cVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  int iVar13;
  uint uVar14;
  code *pcVar15;
  undefined4 *puVar16;
  uint *puVar17;
  bool bVar18;
  bool bVar19;
  int local_50;
  uint local_40;
  undefined4 local_38;
  undefined4 uStack_34;
  char local_2e;
  char local_2d;
  uint local_2c [2];
  
  uVar10 = *(uint *)(param_2 + 0x130);
  uVar14 = param_1[0x114];
  param_1[0x114] = 0;
  if ((uVar10 & 0x15) == 1) {
    iVar2 = param_1[0x89];
  }
  else {
    iVar2 = -1;
  }
  puVar17 = (uint *)(param_2 + 0x50);
  if ((uVar10 & 0x2a) == 2) {
    iVar6 = param_1[0x8a];
  }
  else {
    iVar6 = -1;
  }
  if (*(int *)(*param_1 + 0x86b8) == 0) {
    if (uVar14 == 0) {
      uVar14 = Curl_socket_check(iVar2,0xffffffff,iVar6,0);
    }
  }
  else {
    uVar14 = uVar14 | 1;
  }
  if (uVar14 == 4) {
    Curl_failf(param_2,DAT_0004b4b4);
    return 0x37;
  }
  uVar11 = *(uint *)(param_2 + 0x130);
  uVar10 = uVar11 & 1;
  if (uVar10 != 0) {
    if (((int)(uVar14 << 0x1f) < 0) || (*(char *)((int)param_1 + 0x201) != '\0')) {
      uVar11 = 0;
      local_40 = 0;
      local_2e = '\0';
      *param_3 = '\0';
      local_50 = 0x65;
      do {
        uVar10 = *(uint *)(param_2 + 0x2cc);
        uVar7 = *puVar17;
        if (uVar10 == 0) {
          uVar10 = 0x4000;
        }
        if ((*(int *)(param_2 + 0x54) == -1 && uVar7 == 0xffffffff) ||
           (*(char *)(param_2 + 0x98) != '\0')) {
LAB_0004b13c:
          iVar2 = Curl_read(param_1,param_1[0x89],*(undefined4 *)(param_2 + 0x124),uVar10,local_2c);
          uVar10 = uVar11;
          if (iVar2 == 0x51) break;
          if (iVar2 != 0) {
            return iVar2;
          }
          uVar3 = *(uint *)(param_2 + 0x70);
          uVar4 = *(uint *)(param_2 + 0x74);
        }
        else {
          uVar3 = *(uint *)(param_2 + 0x70);
          uVar4 = *(uint *)(param_2 + 0x74);
          uVar8 = uVar7 - uVar3;
          iVar2 = (*(int *)(param_2 + 0x54) - uVar4) - (uint)(uVar7 < uVar3);
          if (((int)(iVar2 - (uint)(uVar8 < uVar10)) < 0 ==
               (SBORROW4(iVar2,(uint)(uVar8 < uVar10)) != false)) || (uVar10 = uVar8, uVar8 != 0))
          goto LAB_0004b13c;
          local_2c[0] = 0;
        }
        if ((((uVar3 | uVar4) == 0) &&
            ((*(uint *)(param_2 + 0x78) | *(uint *)(param_2 + 0x7c)) == 0)) &&
           (Curl_pgrsTime(param_2,7), *(int *)(param_2 + 0xd4) != 0)) {
          curlx_tvnow(&local_38);
          *(undefined4 *)(param_2 + 0xcc) = local_38;
          *(undefined4 *)(param_2 + 0xd0) = uStack_34;
        }
        if (local_2c[0] == 0) {
          if (*(int *)(param_2 + 0x120) != 0) {
LAB_0004b60e:
            uVar10 = 1;
            uVar11 = *(uint *)(param_2 + 0x130) & 0xfffffffe;
            *(uint *)(param_2 + 0x130) = uVar11;
            goto LAB_0004b558;
          }
          bVar19 = true;
        }
        else {
          if ((int)local_2c[0] < 1) goto LAB_0004b60e;
          bVar19 = false;
        }
        *(undefined *)(*(int *)(param_2 + 0x124) + local_2c[0]) = 0;
        pcVar15 = *(code **)(param_1[0x86] + 0x34);
        *(undefined4 *)(param_2 + 0xac) = *(undefined4 *)(param_2 + 0x124);
        if (pcVar15 != (code *)0x0) {
          iVar2 = (*pcVar15)(param_2,param_1,local_2c,&local_2e);
          if (iVar2 != 0) {
            return iVar2;
          }
          if (local_2e == '\0') goto LAB_0004b1ba;
LAB_0004b550:
          uVar11 = *(uint *)(param_2 + 0x130);
          uVar10 = 1;
          goto LAB_0004b558;
        }
LAB_0004b1ba:
        if (*(char *)(param_2 + 0x98) != '\0') {
          local_2d = '\0';
          iVar2 = Curl_http_readwrite_headers(param_2,param_1,local_2c,&local_2d);
          if (iVar2 != 0) {
            return iVar2;
          }
          if (((*(code **)(param_1[0x86] + 0x34) != (code *)0x0) &&
              (bVar18 = *(int *)(param_2 + 0x60) == 0,
              (int)(*(int *)(param_2 + 100) - (uint)bVar18) < 0 !=
              (SBORROW4(*(int *)(param_2 + 100),(uint)bVar18) != false))) && (0 < (int)local_2c[0]))
          {
            iVar2 = (**(code **)(param_1[0x86] + 0x34))(param_2,param_1,local_2c,&local_2e);
            if (iVar2 != 0) {
              return iVar2;
            }
            if (local_2e != '\0') goto LAB_0004b550;
          }
          if (local_2d != '\0') {
            if (0 < (int)local_2c[0]) {
              iVar2 = Curl_pipeline_wanted(*(undefined4 *)(*param_1 + 0x40),1);
              if (iVar2 == 0) {
                Curl_infof(param_2,DAT_0004bce4,local_2c[0],*(undefined4 *)(param_2 + 0x868c));
              }
              else {
                Curl_infof(param_2,DAT_0004b7f0,local_2c[0],*(undefined4 *)(param_2 + 0x868c));
                *(undefined *)((int)param_1 + 0x201) = 1;
                param_1[0x99] = param_1[0x99] - local_2c[0];
              }
            }
            goto LAB_0004b550;
          }
        }
        if ((*(int *)(param_2 + 0xac) != 0) && (*(char *)(param_2 + 0x98) == '\0')) {
          if ((int)local_2c[0] < 1) {
            if (bVar19) goto LAB_0004b32e;
          }
          else {
            iVar2 = *(int *)(param_2 + 0x120);
            if (((iVar2 == 0) && (!bVar19)) && ((*(uint *)(param_1[0x86] + 0x3c) & 0x40003) != 0)) {
              if (*(int *)(param_2 + 0x13c) != 0) {
                if (*(char *)((int)param_1 + 0x1ed) != '\0') {
                  *(uint *)(param_2 + 0x130) = *(uint *)(param_2 + 0x130) & 0xfffffffe;
                  *param_3 = '\x01';
                  return 0;
                }
                *(undefined *)(param_2 + 0x135) = 1;
                Curl_infof(param_2,DAT_0004b4a8);
              }
              if ((((*(uint *)(param_2 + 0x8698) | *(uint *)(param_2 + 0x869c)) != 0) &&
                  (*(char *)(param_2 + 0xbc) == '\0')) &&
                 ((*(int *)(param_2 + 0x278) == 1 && (*(char *)(param_2 + 0x135) == '\0')))) {
                if (*(uint *)(param_2 + 0x869c) == *(uint *)(param_2 + 0x54) &&
                    *(uint *)(param_2 + 0x8698) == *(uint *)(param_2 + 0x50)) {
                  Curl_infof(param_2,DAT_0004bcf4);
                  uVar14 = *(uint *)(param_2 + 0x130);
                  *(undefined *)((int)param_1 + 0x1ed) = 1;
                  *(uint *)(param_2 + 0x130) = uVar14 & 0xfffffffe;
                  *param_3 = '\x01';
                  return 0;
                }
                Curl_failf(param_2,DAT_0004b4ac);
                return 0x21;
              }
              if (((*(int *)(param_2 + 0x270) != 0) && (*(int *)(param_2 + 0x8694) == 0)) &&
                 (iVar2 = Curl_meets_timecondition(param_2,*(undefined4 *)(param_2 + 0x11c)),
                 uVar12 = DAT_0004b4b0, iVar2 == 0)) {
                uVar10 = 1;
                *param_3 = '\x01';
                *(undefined4 *)(param_2 + 0x86f4) = 0x130;
                Curl_infof(param_2,uVar12);
                *(undefined *)((int)param_1 + 0x1ed) = 1;
                cVar9 = *param_3;
                goto LAB_0004b29c;
              }
LAB_0004b32e:
              iVar2 = *(int *)(param_2 + 0x120);
            }
            *(int *)(param_2 + 0x120) = iVar2 + 1;
            if ((*(char *)(param_2 + 0x310) == '\0') ||
               ((*(int *)(param_2 + 0x9c) != 0 &&
                (Curl_debug(param_2,3,*(undefined4 *)(param_2 + 0x594),
                            *(undefined4 *)(param_2 + 0xa8),param_1), *(int *)(param_2 + 0x9c) != 1)
                ))) {
              cVar9 = *(char *)(param_2 + 0x148);
            }
            else {
              Curl_debug(param_2,3,*(undefined4 *)(param_2 + 0xac),local_2c[0],param_1);
              cVar9 = *(char *)(param_2 + 0x148);
            }
            if (cVar9 != '\0') {
              iVar2 = Curl_httpchunk_read(param_1,*(undefined4 *)(param_2 + 0xac),local_2c[0],
                                          local_2c);
              if (0 < iVar2) {
                if (iVar2 == 4) {
                  Curl_failf(param_2,DAT_0004bce8);
                  return 0x17;
                }
                uVar12 = Curl_chunked_strerror();
                Curl_failf(param_2,DAT_0004bc7c,uVar12);
                return 0x38;
              }
              if (iVar2 == -1) {
                iVar2 = param_1[0xc];
                *(uint *)(param_2 + 0x130) = *(uint *)(param_2 + 0x130) & 0xfffffffe;
                if (iVar2 != 0) {
                  Curl_infof(*param_1,DAT_0004b7e8,iVar2);
                  iVar6 = Curl_pipeline_wanted(*(undefined4 *)(*param_1 + 0x40),1);
                  if (iVar6 != 0) {
                    Curl_infof(*param_1,DAT_0004b7ec,iVar2);
                    *(undefined *)((int)param_1 + 0x201) = 1;
                    param_1[0x99] = param_1[0x99] - iVar2;
                  }
                }
              }
            }
            if ((*(int *)(param_2 + 0x9c) == 0) || (*(char *)(param_2 + 0x135) != '\0')) {
              uVar10 = *(uint *)(param_2 + 0x70);
              iVar2 = *(int *)(param_2 + 0x74);
            }
            else {
              uVar10 = *(uint *)(param_2 + 0x70) + *(uint *)(param_2 + 0xa8);
              iVar2 = *(int *)(param_2 + 0x74) +
                      (uint)CARRY4(*(uint *)(param_2 + 0x70),*(uint *)(param_2 + 0xa8));
              *(uint *)(param_2 + 0x70) = uVar10;
              *(int *)(param_2 + 0x74) = iVar2;
            }
            uVar11 = *(uint *)(param_2 + 0x60);
            iVar6 = *(int *)(param_2 + 100);
            if (iVar6 == -1 && uVar11 == 0xffffffff) {
              uVar7 = uVar10 + local_2c[0];
              iVar13 = iVar2 + ((int)local_2c[0] >> 0x1f) + (uint)CARRY4(uVar10,local_2c[0]);
            }
            else {
              uVar7 = uVar10 + local_2c[0];
              iVar13 = iVar2 + ((int)local_2c[0] >> 0x1f) + (uint)CARRY4(uVar10,local_2c[0]);
              if ((int)((iVar13 - iVar6) - (uint)(uVar7 < uVar11)) < 0 ==
                  (SBORROW4(iVar13,iVar6) != SBORROW4(iVar13 - iVar6,(uint)(uVar7 < uVar11)))) {
                local_40 = (local_2c[0] - uVar11) + uVar10;
                if ((local_40 != 0) && (*(char *)(param_2 + 0x135) == '\0')) {
                  iVar2 = Curl_pipeline_wanted(*(undefined4 *)(*param_1 + 0x40),1);
                  if (iVar2 == 0) {
                    Curl_infof(param_2,DAT_0004bc70);
                    uVar10 = *(uint *)(param_2 + 0x70);
                    iVar2 = *(int *)(param_2 + 0x74);
                    uVar11 = *(uint *)(param_2 + 0x60);
                  }
                  else {
                    Curl_infof(param_2,DAT_0004b7f8,local_40,*(undefined4 *)(param_2 + 0x868c),
                               *puVar17,*(undefined4 *)(param_2 + 0x54),
                               *(undefined4 *)(param_2 + 0x60),*(undefined4 *)(param_2 + 100),
                               *(undefined4 *)(param_2 + 0x70),*(undefined4 *)(param_2 + 0x74),
                               local_2c[0]);
                    uVar10 = *(uint *)(param_2 + 0x70);
                    iVar2 = *(int *)(param_2 + 0x74);
                    uVar11 = *(uint *)(param_2 + 0x60);
                    *(undefined *)((int)param_1 + 0x201) = 1;
                    param_1[0x99] = param_1[0x99] - local_40;
                  }
                }
                local_2c[0] = uVar11 - uVar10;
                bVar18 = (int)local_2c[0] < 0;
                if (bVar18) {
                  local_2c[0] = 0;
                  uVar11 = uVar10;
                }
                else {
                  uVar11 = (int)local_2c[0] >> 0x1f;
                }
                if (bVar18) {
                  uVar11 = 0;
                }
                uVar7 = local_2c[0] + uVar10;
                iVar13 = uVar11 + iVar2 + (uint)CARRY4(local_2c[0],uVar10);
                *(uint *)(param_2 + 0x130) = *(uint *)(param_2 + 0x130) & 0xfffffffe;
              }
            }
            *(uint *)(param_2 + 0x70) = uVar7;
            *(int *)(param_2 + 0x74) = iVar13;
            Curl_pgrsSetDownloadCounter(param_2);
            if (*(char *)(param_2 + 0x148) == '\0') {
              if (local_2c[0] == 0) {
                uVar10 = *(uint *)(param_2 + 0x9c);
                if (uVar10 != 0) goto LAB_0004b414;
                if (bVar19) goto LAB_0004b69a;
              }
              else {
                uVar10 = *(uint *)(param_2 + 0x9c);
                if (uVar10 != 0) {
LAB_0004b414:
                  if (*(char *)(param_2 + 0x135) == '\0') {
                    uVar10 = *(uint *)(param_2 + 0x60);
                    iVar2 = *(int *)(param_2 + 100);
                    if (iVar2 == -1 && uVar10 == 0xffffffff) {
                      uVar11 = *(uint *)(param_2 + 0xa8);
LAB_0004b442:
                      iVar2 = Curl_client_write(param_1,1,*(undefined4 *)(param_2 + 0x594),uVar11);
                    }
                    else {
                      uVar11 = *(uint *)(param_2 + 0xa8);
                      if ((int)(iVar2 - (uint)(uVar10 < uVar11)) < 0 ==
                          (SBORROW4(iVar2,(uint)(uVar10 < uVar11)) != false)) goto LAB_0004b442;
                      iVar2 = Curl_client_write(param_1,1,*(undefined4 *)(param_2 + 0x594),uVar10);
                    }
                    if (iVar2 != 0) {
                      return iVar2;
                    }
                    uVar10 = *(uint *)(param_2 + 0x9c);
                  }
                  if (uVar10 < 2) goto LAB_0004b69a;
                  goto LAB_0004b460;
                }
LAB_0004b69a:
                if (*(char *)(*param_1 + 0x331) == '\0') {
                  iVar2 = *(int *)(param_2 + 0xdc);
                  if (iVar2 == 1) {
                    if (*(char *)(param_2 + 0x135) == '\0') {
                      iVar2 = Curl_unencode_deflate_write(param_1,puVar17,local_2c[0]);
                      goto LAB_0004b9bc;
                    }
                  }
                  else {
                    if (iVar2 != 2) {
                      if (iVar2 != 0) {
                        Curl_failf(param_2,DAT_0004bc68);
                        *(undefined4 *)(param_2 + 0x9c) = 0;
                        return 0x3d;
                      }
                      goto LAB_0004b6a8;
                    }
                    if (*(char *)(param_2 + 0x135) == '\0') {
                      iVar2 = Curl_unencode_gzip_write(param_1,puVar17,local_2c[0]);
                      goto LAB_0004b9bc;
                    }
                  }
                }
                else {
LAB_0004b6a8:
                  if (*(char *)(param_2 + 0x135) == '\0') {
                    if ((*(uint *)(param_1[0x86] + 0x3c) & 0xc000) == 0) {
                      iVar2 = Curl_client_write(param_1,1,*(undefined4 *)(param_2 + 0xac),
                                                local_2c[0]);
                    }
                    else {
                      iVar2 = Curl_pop3_write(param_1,*(undefined4 *)(param_2 + 0xac),local_2c[0]);
                    }
LAB_0004b9bc:
                    *(undefined4 *)(param_2 + 0x9c) = 0;
                    if (iVar2 != 0) {
                      return iVar2;
                    }
                    goto LAB_0004b466;
                  }
                }
LAB_0004b460:
                *(undefined4 *)(param_2 + 0x9c) = 0;
              }
            }
          }
        }
LAB_0004b466:
        iVar2 = param_1[0x86];
        pcVar15 = *(code **)(iVar2 + 0x34);
        if (((pcVar15 != (code *)0x0) && (local_40 != 0)) &&
           (*(char *)((int)param_1 + 0x201) == '\0')) {
          iVar2 = *(int *)(param_2 + 0xac) + local_2c[0];
          local_2c[0] = local_40;
          *(int *)(param_2 + 0xac) = iVar2;
          iVar2 = (*pcVar15)(param_2,param_1,local_2c,&local_2e);
          if (iVar2 != 0) {
            return iVar2;
          }
          if (local_2e == '\0') goto LAB_0004b550;
          uVar10 = 1;
          uVar11 = *(uint *)(param_2 + 0x130) | 1;
          *(uint *)(param_2 + 0x130) = uVar11;
          goto LAB_0004b558;
        }
        if (bVar19) {
          *(uint *)(param_2 + 0x130) = *(uint *)(param_2 + 0x130) & 0xfffffffe;
        }
        if (((*(uint *)(iVar2 + 0x3c) & 0x30) == 0) &&
           (iVar2 = Curl_ssl_data_pending(param_1), iVar2 == 0)) goto LAB_0004b550;
        uVar11 = 1;
        uVar10 = 1;
        local_50 = local_50 + -1;
      } while (local_50 != 0);
      uVar11 = *(uint *)(param_2 + 0x130);
LAB_0004b558:
      if ((uVar11 & 3) == 2) {
        if (*(char *)((int)param_1 + 0x1ed) == '\0') {
          cVar9 = *param_3;
        }
        else {
          Curl_infof(param_2,DAT_0004bc6c);
          cVar9 = *param_3;
          *(uint *)(param_2 + 0x130) = *(uint *)(param_2 + 0x130) & 0xfffffffd;
        }
      }
      else {
        cVar9 = *param_3;
      }
LAB_0004b29c:
      if (cVar9 != '\0') {
        return 0;
      }
      uVar11 = *(uint *)(param_2 + 0x130);
    }
    else {
      uVar10 = 0;
    }
  }
  if (((int)(uVar11 << 0x1e) < 0) && ((int)(uVar14 << 0x1e) < 0)) {
    if (((*(uint *)(param_2 + 0x70) | *(uint *)(param_2 + 0x74)) == 0) &&
       ((*(uint *)(param_2 + 0x78) | *(uint *)(param_2 + 0x7c)) == 0)) {
      Curl_pgrsTime(param_2,7);
    }
    iVar2 = *(int *)(param_2 + 0x140);
    uVar14 = uVar10 | 2;
    if (iVar2 == 0) {
      *(undefined4 *)(param_2 + 0x144) = *(undefined4 *)(param_2 + 0x128);
      if (*(char *)(param_2 + 0x134) == '\0') {
        if ((*(int *)(param_2 + 0xd4) != 2) || (*(int *)(*(int *)(param_2 + 0x14c) + 0x58) != 2)) {
          uVar10 = *(uint *)(param_1[0x86] + 0x3c) & 0x40003;
          if (uVar10 != 0) {
            uVar10 = (uint)(*(int *)(*(int *)(param_2 + 0x14c) + 0x58) == 1);
          }
          iVar2 = Curl_fillreadbuffer(param_1,0x4000,local_2c);
          uVar11 = local_2c[0];
          if (iVar2 != 0) {
            return iVar2;
          }
          if (local_2c[0] == 0) goto LAB_0004b9e2;
          if (0 < (int)local_2c[0]) {
            *(uint *)(param_2 + 0x140) = local_2c[0];
            if ((uVar10 == 0) &&
               ((*(char *)(param_2 + 0x2fb) != '\0' || (*(char *)(param_2 + 0x24e) != '\0')))) {
              iVar2 = *(int *)(param_2 + 0x85c4);
              if (iVar2 == 0) {
                iVar2 = (**DAT_0004bcec)(0x8000);
                *(int *)(param_2 + 0x85c4) = iVar2;
                if (iVar2 == 0) {
                  Curl_failf(param_2,DAT_0004bcf0);
                  return 0x1b;
                }
              }
              uVar7 = 0;
              uVar10 = 0;
              while( true ) {
                bVar1 = *(byte *)(*(int *)(param_2 + 0x144) + uVar7);
                uVar3 = (uint)bVar1;
                if (uVar3 == 10) {
                  *(undefined *)(iVar2 + uVar10) = 0xd;
                  uVar10 = uVar10 + 1;
                  *(byte *)(*(int *)(param_2 + 0x85c4) + uVar10) = bVar1;
                  if (*(char *)(param_2 + 0x24e) == '\0') {
                    uVar3 = *(uint *)(param_2 + 0x86b0);
                    if (*(int *)(param_2 + 0x86b4) != -1 || uVar3 != 0xffffffff) {
                      bVar19 = 0xfffffffe < uVar3;
                      uVar3 = uVar3 + 1;
                      *(uint *)(param_2 + 0x86b0) = uVar3;
                      *(uint *)(param_2 + 0x86b4) = *(int *)(param_2 + 0x86b4) + (uint)bVar19;
                    }
                  }
                }
                else {
                  *(byte *)(iVar2 + uVar10) = bVar1;
                }
                uVar7 = uVar7 + 1;
                uVar10 = uVar10 + 1;
                if (uVar7 == uVar11) break;
                iVar2 = *(int *)(param_2 + 0x85c4);
              }
              bVar19 = uVar11 != uVar10;
              if (bVar19) {
                uVar3 = *(uint *)(param_2 + 0x85c4);
                uVar11 = uVar10;
              }
              if (bVar19) {
                *(uint *)(param_2 + 0x140) = uVar10;
              }
              if (bVar19) {
                *(uint *)(param_2 + 0x144) = uVar3;
              }
            }
            if (((*(uint *)(param_1[0x86] + 0x3c) & 0x30000) != 0) &&
               (iVar2 = Curl_smtp_escape_eob(param_1,uVar11), iVar2 != 0)) {
              return iVar2;
            }
            iVar2 = *(int *)(param_2 + 0x140);
            goto LAB_0004baae;
          }
          uVar11 = *(uint *)(param_2 + 0x130);
          goto LAB_0004b9ea;
        }
        *(undefined4 *)(param_2 + 0xd4) = 1;
        *(uint *)(param_2 + 0x130) = *(uint *)(param_2 + 0x130) & 0xfffffffd;
        curlx_tvnow(&local_38);
        *(undefined4 *)(param_2 + 0xcc) = local_38;
        *(undefined4 *)(param_2 + 0xd0) = uStack_34;
        Curl_expire(param_2,*(undefined4 *)(param_2 + 0x440));
      }
      else {
LAB_0004b9e2:
        uVar11 = *(uint *)(param_2 + 0x130);
        uVar10 = uVar14;
        if (-1 < (int)(uVar11 << 0x1a)) {
LAB_0004b9ea:
          cVar9 = *(char *)(param_1 + 0x7f);
          *(uint *)(param_2 + 0x130) = uVar11 & 0xfffffffd;
          uVar10 = uVar14;
          if ((cVar9 != '\0') && (iVar2 = Curl_readrewind(param_1), iVar2 != 0)) {
            return iVar2;
          }
        }
      }
    }
    else {
LAB_0004baae:
      iVar2 = Curl_write(param_1,param_1[0x8a],*(undefined4 *)(param_2 + 0x144),iVar2,local_2c);
      if (iVar2 != 0) {
        return iVar2;
      }
      if (*(char *)(param_2 + 0x310) != '\0') {
        Curl_debug(param_2,4,*(undefined4 *)(param_2 + 0x144),local_2c[0],param_1);
      }
      iVar2 = *(uint *)(param_2 + 0x78) + local_2c[0];
      iVar6 = *(int *)(param_2 + 0x7c) +
              ((int)local_2c[0] >> 0x1f) + (uint)CARRY4(*(uint *)(param_2 + 0x78),local_2c[0]);
      *(int *)(param_2 + 0x78) = iVar2;
      *(int *)(param_2 + 0x7c) = iVar6;
      if (iVar6 == *(int *)(param_2 + 0x86b4) && iVar2 == *(int *)(param_2 + 0x86b0)) {
        *(undefined *)(param_2 + 0x134) = 1;
        Curl_infof(param_2,DAT_0004bc78);
        iVar2 = *(int *)(param_2 + 0x78);
        iVar6 = *(int *)(param_2 + 0x7c);
      }
      if (*(uint *)(param_2 + 0x140) == local_2c[0]) {
        uVar10 = *(uint *)(param_2 + 0x128);
        *(undefined4 *)(param_2 + 0x140) = 0;
        *(uint *)(param_2 + 0x144) = uVar10;
        if (*(char *)(param_2 + 0x134) != '\0') {
          uVar10 = *(uint *)(param_2 + 0x130) & 0xfffffffd;
          *(uint *)(param_2 + 0x130) = uVar10;
        }
      }
      else {
        *(uint *)(param_2 + 0x140) = *(uint *)(param_2 + 0x140) - local_2c[0];
        uVar10 = *(int *)(param_2 + 0x144) + local_2c[0];
        *(uint *)(param_2 + 0x144) = uVar10;
      }
      Curl_pgrsSetUploadCounter(param_2,uVar10,iVar2,iVar6);
      uVar10 = uVar14;
    }
  }
  puVar16 = (undefined4 *)(param_2 + 0x90);
  curlx_tvnow(&local_38);
  *puVar16 = local_38;
  *(undefined4 *)(param_2 + 0x94) = uStack_34;
  if (uVar10 == 0) {
    if ((*(int *)(param_2 + 0xd4) == 1) &&
       (iVar2 = curlx_tvdiff(*puVar16,*(undefined4 *)(param_2 + 0x94),
                             *(undefined4 *)(param_2 + 0xcc),*(undefined4 *)(param_2 + 0xd0)),
       *(int *)(param_2 + 0x440) <= iVar2)) {
      *(undefined4 *)(param_2 + 0xd4) = 0;
      uVar12 = DAT_0004b7f4;
      *(uint *)(param_2 + 0x130) = *(uint *)(param_2 + 0x130) | 2;
      Curl_infof(param_2,uVar12);
    }
  }
  else {
    puVar5 = *(undefined4 **)(param_2 + 0x58);
    if (puVar5 != (undefined4 *)0x0) {
      uVar12 = *(undefined4 *)(param_2 + 0x74);
      *puVar5 = *(undefined4 *)(param_2 + 0x70);
      puVar5[1] = uVar12;
    }
    puVar5 = *(undefined4 **)(param_2 + 0x68);
    if (puVar5 != (undefined4 *)0x0) {
      uVar12 = *(undefined4 *)(param_2 + 0x7c);
      *puVar5 = *(undefined4 *)(param_2 + 0x78);
      puVar5[1] = uVar12;
    }
  }
  iVar2 = Curl_pgrsUpdate(param_1);
  if (iVar2 == 0) {
    iVar2 = Curl_speedcheck(param_2,*puVar16,*(undefined4 *)(param_2 + 0x94));
    if (iVar2 != 0) {
      return iVar2;
    }
    if (*(int *)(param_2 + 0x130) == 0) {
      if (*(char *)(param_2 + 0x307) == '\0') {
        uVar14 = *(uint *)(param_2 + 0x50);
        iVar2 = *(int *)(param_2 + 0x54);
        if (iVar2 != -1 || uVar14 != 0xffffffff) {
          uVar10 = *(uint *)(param_2 + 0x70);
          iVar6 = *(int *)(param_2 + 0x74);
          if (((iVar2 != iVar6 || uVar14 != uVar10) &&
              (iVar6 != *(int *)(param_2 + 0x8684) +
                        iVar2 + (uint)CARRY4(*(uint *)(param_2 + 0x8680),uVar14) ||
               uVar10 != *(uint *)(param_2 + 0x8680) + uVar14)) && (*(int *)(param_2 + 0x13c) == 0))
          {
            Curl_failf(param_2,DAT_0004b7fc,uVar14 - uVar10,
                       (iVar2 - iVar6) - (uint)(uVar14 < uVar10));
            return 0x12;
          }
        }
        if ((*(char *)(param_2 + 0x148) != '\0') && (param_1[8] != 4)) {
          Curl_failf(param_2,DAT_0004b800);
          return 0x12;
        }
      }
      iVar2 = Curl_pgrsUpdate(param_1);
      if (iVar2 != 0) goto LAB_0004b2f6;
    }
    else {
      iVar2 = Curl_timeleft(param_2,param_2 + 0x90,0);
      if (iVar2 < 0) {
        if (*(int *)(param_2 + 0x54) == -1 && *(int *)(param_2 + 0x50) == -1) {
          uVar12 = curlx_tvdiff(*puVar16,*(undefined4 *)(param_2 + 0x94),
                                *(undefined4 *)(param_2 + 0x500),*(undefined4 *)(param_2 + 0x504));
          Curl_failf(param_2,DAT_0004bc74,uVar12);
          return 0x1c;
        }
        uVar12 = curlx_tvdiff(*puVar16,*(undefined4 *)(param_2 + 0x94),
                              *(undefined4 *)(param_2 + 0x500),*(undefined4 *)(param_2 + 0x504));
        Curl_failf(param_2,DAT_0004bc64,uVar12);
        return 0x1c;
      }
    }
    *param_3 = (*(uint *)(param_2 + 0x130) & 0x33) == 0;
    iVar2 = 0;
  }
  else {
LAB_0004b2f6:
    iVar2 = 0x2a;
  }
  return iVar2;
}

