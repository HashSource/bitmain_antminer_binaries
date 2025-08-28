
/* WARNING: Type propagation algorithm not settling */

int Curl_readwrite(int *param_1,int param_2,char *param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char cVar8;
  uint uVar9;
  uint uVar10;
  undefined4 uVar11;
  int iVar12;
  uint uVar13;
  code *pcVar14;
  undefined4 *puVar15;
  uint *puVar16;
  bool bVar17;
  bool bVar18;
  int local_50;
  uint local_40;
  undefined4 local_38;
  undefined4 uStack_34;
  char local_2e;
  char local_2d;
  uint local_2c [2];
  
  uVar9 = *(uint *)(param_2 + 0x130);
  uVar13 = param_1[0x114];
  param_1[0x114] = 0;
  if ((uVar9 & 0x15) == 1) {
    iVar2 = param_1[0x89];
  }
  else {
    iVar2 = -1;
  }
  puVar16 = (uint *)(param_2 + 0x50);
  if ((uVar9 & 0x2a) == 2) {
    iVar5 = param_1[0x8a];
  }
  else {
    iVar5 = -1;
  }
  if (*(int *)(*param_1 + 0x86b8) == 0) {
    if (uVar13 == 0) {
      uVar13 = Curl_socket_check(iVar2,0xffffffff,iVar5,0);
    }
  }
  else {
    uVar13 = uVar13 | 1;
  }
  if (uVar13 == 4) {
    Curl_failf(param_2,"select/poll returned error");
    return 0x37;
  }
  uVar10 = *(uint *)(param_2 + 0x130);
  uVar9 = uVar10 & 1;
  if (uVar9 != 0) {
    if (((int)(uVar13 << 0x1f) < 0) || (*(char *)((int)param_1 + 0x201) != '\0')) {
      uVar10 = 0;
      local_40 = 0;
      local_2e = '\0';
      *param_3 = '\0';
      local_50 = 0x65;
      do {
        uVar9 = *(uint *)(param_2 + 0x2cc);
        uVar6 = *puVar16;
        if (uVar9 == 0) {
          uVar9 = 0x4000;
        }
        if ((*(int *)(param_2 + 0x54) == -1 && uVar6 == 0xffffffff) ||
           (*(char *)(param_2 + 0x98) != '\0')) {
LAB_0004b13c:
          iVar2 = Curl_read(param_1,param_1[0x89],*(undefined4 *)(param_2 + 0x124),uVar9,local_2c);
          uVar9 = uVar10;
          if (iVar2 == 0x51) break;
          if (iVar2 != 0) {
            return iVar2;
          }
          uVar3 = *(uint *)(param_2 + 0x70);
          iVar2 = *(int *)(param_2 + 0x74);
        }
        else {
          uVar3 = *(uint *)(param_2 + 0x70);
          iVar2 = *(int *)(param_2 + 0x74);
          uVar7 = uVar6 - uVar3;
          if (((int)(uint)(uVar7 < uVar9) <=
               (int)((*(int *)(param_2 + 0x54) - iVar2) - (uint)(uVar6 < uVar3))) ||
             (uVar9 = uVar7, uVar7 != 0)) goto LAB_0004b13c;
          local_2c[0] = 0;
        }
        if (((uVar3 == 0 && iVar2 == 0) &&
            (*(int *)(param_2 + 0x78) == 0 && *(int *)(param_2 + 0x7c) == 0)) &&
           (Curl_pgrsTime(param_2,7), *(int *)(param_2 + 0xd4) != 0)) {
          curlx_tvnow(&local_38);
          *(undefined4 *)(param_2 + 0xcc) = local_38;
          *(undefined4 *)(param_2 + 0xd0) = uStack_34;
        }
        if (local_2c[0] == 0) {
          if (*(int *)(param_2 + 0x120) != 0) {
LAB_0004b60e:
            uVar9 = 1;
            uVar10 = *(uint *)(param_2 + 0x130) & 0xfffffffe;
            *(uint *)(param_2 + 0x130) = uVar10;
            goto LAB_0004b558;
          }
          bVar18 = true;
        }
        else {
          if ((int)local_2c[0] < 1) goto LAB_0004b60e;
          bVar18 = false;
        }
        *(undefined1 *)(*(int *)(param_2 + 0x124) + local_2c[0]) = 0;
        pcVar14 = *(code **)(param_1[0x86] + 0x34);
        *(undefined4 *)(param_2 + 0xac) = *(undefined4 *)(param_2 + 0x124);
        if (pcVar14 != (code *)0x0) {
          iVar2 = (*pcVar14)(param_2,param_1,local_2c,&local_2e);
          if (iVar2 != 0) {
            return iVar2;
          }
          if (local_2e == '\0') goto LAB_0004b1ba;
LAB_0004b550:
          uVar10 = *(uint *)(param_2 + 0x130);
          uVar9 = 1;
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
              (*(int *)(param_2 + 100) < (int)(uint)(*(int *)(param_2 + 0x60) == 0))) &&
             (0 < (int)local_2c[0])) {
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
                Curl_infof(param_2,
                           "Excess found in a non pipelined read: excess = %zd url = %s (zero-length body)\n"
                           ,local_2c[0],*(undefined4 *)(param_2 + 0x868c));
              }
              else {
                Curl_infof(param_2,"Rewinding stream by : %zd bytes on url %s (zero-length body)\n",
                           local_2c[0],*(undefined4 *)(param_2 + 0x868c));
                *(undefined1 *)((int)param_1 + 0x201) = 1;
                param_1[0x99] = param_1[0x99] - local_2c[0];
              }
            }
            goto LAB_0004b550;
          }
        }
        if ((*(int *)(param_2 + 0xac) != 0) && (*(char *)(param_2 + 0x98) == '\0')) {
          if ((int)local_2c[0] < 1) {
            if (bVar18) goto LAB_0004b32e;
          }
          else {
            iVar2 = *(int *)(param_2 + 0x120);
            if (((iVar2 == 0) && (!bVar18)) && ((*(uint *)(param_1[0x86] + 0x3c) & 0x40003) != 0)) {
              if (*(int *)(param_2 + 0x13c) != 0) {
                if (*(char *)((int)param_1 + 0x1ed) != '\0') {
                  *(uint *)(param_2 + 0x130) = *(uint *)(param_2 + 0x130) & 0xfffffffe;
                  *param_3 = '\x01';
                  return 0;
                }
                *(undefined1 *)(param_2 + 0x135) = 1;
                Curl_infof(param_2,"Ignoring the response-body\n");
              }
              if (((*(int *)(param_2 + 0x8698) != 0 || *(int *)(param_2 + 0x869c) != 0) &&
                  (*(char *)(param_2 + 0xbc) == '\0')) &&
                 ((*(int *)(param_2 + 0x278) == 1 && (*(char *)(param_2 + 0x135) == '\0')))) {
                if (*(int *)(param_2 + 0x869c) == *(int *)(param_2 + 0x54) &&
                    *(int *)(param_2 + 0x8698) == *(int *)(param_2 + 0x50)) {
                  Curl_infof(param_2,"The entire document is already downloaded");
                  uVar13 = *(uint *)(param_2 + 0x130);
                  *(undefined1 *)((int)param_1 + 0x1ed) = 1;
                  *(uint *)(param_2 + 0x130) = uVar13 & 0xfffffffe;
                  *param_3 = '\x01';
                  return 0;
                }
                Curl_failf(param_2,
                           "HTTP server doesn\'t seem to support byte ranges. Cannot resume.");
                return 0x21;
              }
              if (((*(int *)(param_2 + 0x270) != 0) && (*(int *)(param_2 + 0x8694) == 0)) &&
                 (iVar2 = Curl_meets_timecondition(param_2,*(undefined4 *)(param_2 + 0x11c)),
                 iVar2 == 0)) {
                uVar9 = 1;
                *param_3 = '\x01';
                *(undefined4 *)(param_2 + 0x86f4) = 0x130;
                Curl_infof(param_2,"Simulate a HTTP 304 response!\n");
                *(undefined1 *)((int)param_1 + 0x1ed) = 1;
                cVar8 = *param_3;
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
              cVar8 = *(char *)(param_2 + 0x148);
            }
            else {
              Curl_debug(param_2,3,*(undefined4 *)(param_2 + 0xac),local_2c[0],param_1);
              cVar8 = *(char *)(param_2 + 0x148);
            }
            if (cVar8 != '\0') {
              iVar2 = Curl_httpchunk_read(param_1,*(undefined4 *)(param_2 + 0xac),local_2c[0],
                                          local_2c);
              if (0 < iVar2) {
                if (iVar2 == 4) {
                  Curl_failf(param_2,"Failed writing data");
                  return 0x17;
                }
                uVar11 = Curl_chunked_strerror();
                Curl_failf(param_2,"%s in chunked-encoding",uVar11);
                return 0x38;
              }
              if (iVar2 == -1) {
                iVar2 = param_1[0xc];
                *(uint *)(param_2 + 0x130) = *(uint *)(param_2 + 0x130) & 0xfffffffe;
                if (iVar2 != 0) {
                  Curl_infof(*param_1,"Leftovers after chunking: %zu bytes\n",iVar2);
                  iVar5 = Curl_pipeline_wanted(*(undefined4 *)(*param_1 + 0x40),1);
                  if (iVar5 != 0) {
                    Curl_infof(*param_1,"Rewinding %zu bytes\n",iVar2);
                    *(undefined1 *)((int)param_1 + 0x201) = 1;
                    param_1[0x99] = param_1[0x99] - iVar2;
                  }
                }
              }
            }
            if ((*(int *)(param_2 + 0x9c) == 0) || (*(char *)(param_2 + 0x135) != '\0')) {
              uVar9 = *(uint *)(param_2 + 0x70);
              iVar2 = *(int *)(param_2 + 0x74);
            }
            else {
              uVar9 = *(uint *)(param_2 + 0x70) + *(uint *)(param_2 + 0xa8);
              iVar2 = *(int *)(param_2 + 0x74) +
                      (uint)CARRY4(*(uint *)(param_2 + 0x70),*(uint *)(param_2 + 0xa8));
              *(uint *)(param_2 + 0x70) = uVar9;
              *(int *)(param_2 + 0x74) = iVar2;
            }
            uVar10 = *(uint *)(param_2 + 0x60);
            iVar5 = *(int *)(param_2 + 100);
            if (iVar5 == -1 && uVar10 == 0xffffffff) {
              uVar6 = uVar9 + local_2c[0];
              iVar12 = iVar2 + ((int)local_2c[0] >> 0x1f) + (uint)CARRY4(uVar9,local_2c[0]);
            }
            else {
              uVar6 = uVar9 + local_2c[0];
              iVar12 = iVar2 + ((int)local_2c[0] >> 0x1f) + (uint)CARRY4(uVar9,local_2c[0]);
              if ((int)((iVar12 - iVar5) - (uint)(uVar6 < uVar10)) < 0 ==
                  (SBORROW4(iVar12,iVar5) != SBORROW4(iVar12 - iVar5,(uint)(uVar6 < uVar10)))) {
                local_40 = (local_2c[0] - uVar10) + uVar9;
                if ((local_40 != 0) && (*(char *)(param_2 + 0x135) == '\0')) {
                  iVar2 = Curl_pipeline_wanted(*(undefined4 *)(*param_1 + 0x40),1);
                  if (iVar2 == 0) {
                    Curl_infof(param_2,
                               "Excess found in a non pipelined read: excess = %zu, size = %lld, maxdownload = %lld, bytecount = %lld\n"
                               ,local_40);
                    uVar9 = *(uint *)(param_2 + 0x70);
                    iVar2 = *(int *)(param_2 + 0x74);
                    uVar10 = *(uint *)(param_2 + 0x60);
                  }
                  else {
                    Curl_infof(param_2,
                               "Rewinding stream by : %zu bytes on url %s (size = %lld, maxdownload = %lld, bytecount = %lld, nread = %zd)\n"
                               ,local_40,*(undefined4 *)(param_2 + 0x868c),*puVar16,
                               *(undefined4 *)(param_2 + 0x54),*(undefined4 *)(param_2 + 0x60),
                               *(undefined4 *)(param_2 + 100),*(undefined4 *)(param_2 + 0x70),
                               *(undefined4 *)(param_2 + 0x74),local_2c[0]);
                    uVar9 = *(uint *)(param_2 + 0x70);
                    iVar2 = *(int *)(param_2 + 0x74);
                    uVar10 = *(uint *)(param_2 + 0x60);
                    *(undefined1 *)((int)param_1 + 0x201) = 1;
                    param_1[0x99] = param_1[0x99] - local_40;
                  }
                }
                local_2c[0] = uVar10 - uVar9;
                bVar17 = (int)local_2c[0] < 0;
                if (bVar17) {
                  local_2c[0] = 0;
                  uVar10 = uVar9;
                }
                else {
                  uVar10 = (int)local_2c[0] >> 0x1f;
                }
                if (bVar17) {
                  uVar10 = 0;
                }
                uVar6 = local_2c[0] + uVar9;
                iVar12 = uVar10 + iVar2 + (uint)CARRY4(local_2c[0],uVar9);
                *(uint *)(param_2 + 0x130) = *(uint *)(param_2 + 0x130) & 0xfffffffe;
              }
            }
            *(uint *)(param_2 + 0x70) = uVar6;
            *(int *)(param_2 + 0x74) = iVar12;
            Curl_pgrsSetDownloadCounter(param_2);
            if (*(char *)(param_2 + 0x148) == '\0') {
              if (local_2c[0] == 0) {
                uVar9 = *(uint *)(param_2 + 0x9c);
                if (uVar9 != 0) goto LAB_0004b414;
                if (bVar18) goto LAB_0004b69a;
              }
              else {
                uVar9 = *(uint *)(param_2 + 0x9c);
                if (uVar9 != 0) {
LAB_0004b414:
                  if (*(char *)(param_2 + 0x135) == '\0') {
                    uVar9 = *(uint *)(param_2 + 0x60);
                    if (*(int *)(param_2 + 100) == -1 && uVar9 == 0xffffffff) {
                      uVar10 = *(uint *)(param_2 + 0xa8);
LAB_0004b442:
                      iVar2 = Curl_client_write(param_1,1,*(undefined4 *)(param_2 + 0x594),uVar10);
                    }
                    else {
                      uVar10 = *(uint *)(param_2 + 0xa8);
                      if ((int)(uint)(uVar9 < uVar10) <= *(int *)(param_2 + 100)) goto LAB_0004b442;
                      iVar2 = Curl_client_write(param_1,1,*(undefined4 *)(param_2 + 0x594),uVar9);
                    }
                    if (iVar2 != 0) {
                      return iVar2;
                    }
                    uVar9 = *(uint *)(param_2 + 0x9c);
                  }
                  if (uVar9 < 2) goto LAB_0004b69a;
                  goto LAB_0004b460;
                }
LAB_0004b69a:
                if (*(char *)(*param_1 + 0x331) == '\0') {
                  iVar2 = *(int *)(param_2 + 0xdc);
                  if (iVar2 == 1) {
                    if (*(char *)(param_2 + 0x135) == '\0') {
                      iVar2 = Curl_unencode_deflate_write(param_1,puVar16,local_2c[0]);
                      goto LAB_0004b9bc;
                    }
                  }
                  else {
                    if (iVar2 != 2) {
                      if (iVar2 != 0) {
                        Curl_failf(param_2,
                                   "Unrecognized content encoding type. libcurl understands `identity\', `deflate\' and `gzip\' content encodings."
                                  );
                        *(undefined4 *)(param_2 + 0x9c) = 0;
                        return 0x3d;
                      }
                      goto LAB_0004b6a8;
                    }
                    if (*(char *)(param_2 + 0x135) == '\0') {
                      iVar2 = Curl_unencode_gzip_write(param_1,puVar16,local_2c[0]);
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
        pcVar14 = *(code **)(iVar2 + 0x34);
        if (((pcVar14 != (code *)0x0) && (local_40 != 0)) &&
           (*(char *)((int)param_1 + 0x201) == '\0')) {
          iVar2 = *(int *)(param_2 + 0xac) + local_2c[0];
          local_2c[0] = local_40;
          *(int *)(param_2 + 0xac) = iVar2;
          iVar2 = (*pcVar14)(param_2,param_1,local_2c,&local_2e);
          if (iVar2 != 0) {
            return iVar2;
          }
          if (local_2e == '\0') goto LAB_0004b550;
          uVar9 = 1;
          uVar10 = *(uint *)(param_2 + 0x130) | 1;
          *(uint *)(param_2 + 0x130) = uVar10;
          goto LAB_0004b558;
        }
        if (bVar18) {
          *(uint *)(param_2 + 0x130) = *(uint *)(param_2 + 0x130) & 0xfffffffe;
        }
        if (((*(uint *)(iVar2 + 0x3c) & 0x30) == 0) &&
           (iVar2 = Curl_ssl_data_pending(param_1), iVar2 == 0)) goto LAB_0004b550;
        uVar10 = 1;
        uVar9 = 1;
        local_50 = local_50 + -1;
      } while (local_50 != 0);
      uVar10 = *(uint *)(param_2 + 0x130);
LAB_0004b558:
      if ((uVar10 & 3) == 2) {
        if (*(char *)((int)param_1 + 0x1ed) == '\0') {
          cVar8 = *param_3;
        }
        else {
          Curl_infof(param_2,"we are done reading and this is set to close, stop send\n");
          cVar8 = *param_3;
          *(uint *)(param_2 + 0x130) = *(uint *)(param_2 + 0x130) & 0xfffffffd;
        }
      }
      else {
        cVar8 = *param_3;
      }
LAB_0004b29c:
      if (cVar8 != '\0') {
        return 0;
      }
      uVar10 = *(uint *)(param_2 + 0x130);
    }
    else {
      uVar9 = 0;
    }
  }
  if (((int)(uVar10 << 0x1e) < 0) && ((int)(uVar13 << 0x1e) < 0)) {
    if ((*(int *)(param_2 + 0x70) == 0 && *(int *)(param_2 + 0x74) == 0) &&
       (*(int *)(param_2 + 0x78) == 0 && *(int *)(param_2 + 0x7c) == 0)) {
      Curl_pgrsTime(param_2,7);
    }
    iVar2 = *(int *)(param_2 + 0x140);
    uVar13 = uVar9 | 2;
    if (iVar2 == 0) {
      *(undefined4 *)(param_2 + 0x144) = *(undefined4 *)(param_2 + 0x128);
      if (*(char *)(param_2 + 0x134) == '\0') {
        if ((*(int *)(param_2 + 0xd4) != 2) || (*(int *)(*(int *)(param_2 + 0x14c) + 0x58) != 2)) {
          uVar9 = *(uint *)(param_1[0x86] + 0x3c) & 0x40003;
          if (uVar9 != 0) {
            uVar9 = (uint)(*(int *)(*(int *)(param_2 + 0x14c) + 0x58) == 1);
          }
          iVar2 = Curl_fillreadbuffer(param_1,0x4000,local_2c);
          uVar10 = local_2c[0];
          if (iVar2 != 0) {
            return iVar2;
          }
          if (local_2c[0] == 0) goto LAB_0004b9e2;
          if (0 < (int)local_2c[0]) {
            *(uint *)(param_2 + 0x140) = local_2c[0];
            if ((uVar9 == 0) &&
               ((*(char *)(param_2 + 0x2fb) != '\0' || (*(char *)(param_2 + 0x24e) != '\0')))) {
              iVar2 = *(int *)(param_2 + 0x85c4);
              if (iVar2 == 0) {
                iVar2 = (*Curl_cmalloc)(0x8000);
                *(int *)(param_2 + 0x85c4) = iVar2;
                if (iVar2 == 0) {
                  Curl_failf(param_2,"Failed to alloc scratch buffer!");
                  return 0x1b;
                }
              }
              uVar6 = 0;
              uVar9 = 0;
              while( true ) {
                bVar1 = *(byte *)(*(int *)(param_2 + 0x144) + uVar6);
                uVar3 = (uint)bVar1;
                if (uVar3 == 10) {
                  *(undefined1 *)(iVar2 + uVar9) = 0xd;
                  uVar9 = uVar9 + 1;
                  *(byte *)(*(int *)(param_2 + 0x85c4) + uVar9) = bVar1;
                  if (*(char *)(param_2 + 0x24e) == '\0') {
                    uVar3 = *(uint *)(param_2 + 0x86b0);
                    if (*(int *)(param_2 + 0x86b4) != -1 || uVar3 != 0xffffffff) {
                      bVar18 = 0xfffffffe < uVar3;
                      uVar3 = uVar3 + 1;
                      *(uint *)(param_2 + 0x86b0) = uVar3;
                      *(uint *)(param_2 + 0x86b4) = *(int *)(param_2 + 0x86b4) + (uint)bVar18;
                    }
                  }
                }
                else {
                  *(byte *)(iVar2 + uVar9) = bVar1;
                }
                uVar6 = uVar6 + 1;
                uVar9 = uVar9 + 1;
                if (uVar6 == uVar10) break;
                iVar2 = *(int *)(param_2 + 0x85c4);
              }
              bVar18 = uVar10 != uVar9;
              if (bVar18) {
                uVar3 = *(uint *)(param_2 + 0x85c4);
                uVar10 = uVar9;
              }
              if (bVar18) {
                *(uint *)(param_2 + 0x140) = uVar9;
              }
              if (bVar18) {
                *(uint *)(param_2 + 0x144) = uVar3;
              }
            }
            if (((*(uint *)(param_1[0x86] + 0x3c) & 0x30000) != 0) &&
               (iVar2 = Curl_smtp_escape_eob(param_1,uVar10), iVar2 != 0)) {
              return iVar2;
            }
            iVar2 = *(int *)(param_2 + 0x140);
            goto LAB_0004baae;
          }
          uVar10 = *(uint *)(param_2 + 0x130);
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
        uVar10 = *(uint *)(param_2 + 0x130);
        uVar9 = uVar13;
        if (-1 < (int)(uVar10 << 0x1a)) {
LAB_0004b9ea:
          iVar2 = param_1[0x7f];
          *(uint *)(param_2 + 0x130) = uVar10 & 0xfffffffd;
          uVar9 = uVar13;
          if (((char)iVar2 != '\0') && (iVar2 = Curl_readrewind(param_1), iVar2 != 0)) {
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
      iVar5 = *(int *)(param_2 + 0x7c) +
              ((int)local_2c[0] >> 0x1f) + (uint)CARRY4(*(uint *)(param_2 + 0x78),local_2c[0]);
      *(int *)(param_2 + 0x78) = iVar2;
      *(int *)(param_2 + 0x7c) = iVar5;
      if (iVar5 == *(int *)(param_2 + 0x86b4) && iVar2 == *(int *)(param_2 + 0x86b0)) {
        *(undefined1 *)(param_2 + 0x134) = 1;
        Curl_infof(param_2,"We are completely uploaded and fine\n");
        iVar2 = *(int *)(param_2 + 0x78);
        iVar5 = *(int *)(param_2 + 0x7c);
      }
      if (*(uint *)(param_2 + 0x140) == local_2c[0]) {
        uVar9 = *(uint *)(param_2 + 0x128);
        *(undefined4 *)(param_2 + 0x140) = 0;
        *(uint *)(param_2 + 0x144) = uVar9;
        if (*(char *)(param_2 + 0x134) != '\0') {
          uVar9 = *(uint *)(param_2 + 0x130) & 0xfffffffd;
          *(uint *)(param_2 + 0x130) = uVar9;
        }
      }
      else {
        *(uint *)(param_2 + 0x140) = *(uint *)(param_2 + 0x140) - local_2c[0];
        uVar9 = *(int *)(param_2 + 0x144) + local_2c[0];
        *(uint *)(param_2 + 0x144) = uVar9;
      }
      Curl_pgrsSetUploadCounter(param_2,uVar9,iVar2,iVar5);
      uVar9 = uVar13;
    }
  }
  puVar15 = (undefined4 *)(param_2 + 0x90);
  curlx_tvnow(&local_38);
  *puVar15 = local_38;
  *(undefined4 *)(param_2 + 0x94) = uStack_34;
  if (uVar9 == 0) {
    if ((*(int *)(param_2 + 0xd4) == 1) &&
       (iVar2 = curlx_tvdiff(*puVar15,*(undefined4 *)(param_2 + 0x94),
                             *(undefined4 *)(param_2 + 0xcc),*(undefined4 *)(param_2 + 0xd0)),
       *(int *)(param_2 + 0x440) <= iVar2)) {
      *(undefined4 *)(param_2 + 0xd4) = 0;
      *(uint *)(param_2 + 0x130) = *(uint *)(param_2 + 0x130) | 2;
      Curl_infof(param_2,"Done waiting for 100-continue\n");
    }
  }
  else {
    puVar4 = *(undefined4 **)(param_2 + 0x58);
    if (puVar4 != (undefined4 *)0x0) {
      uVar11 = *(undefined4 *)(param_2 + 0x74);
      *puVar4 = *(undefined4 *)(param_2 + 0x70);
      puVar4[1] = uVar11;
    }
    puVar4 = *(undefined4 **)(param_2 + 0x68);
    if (puVar4 != (undefined4 *)0x0) {
      uVar11 = *(undefined4 *)(param_2 + 0x7c);
      *puVar4 = *(undefined4 *)(param_2 + 0x78);
      puVar4[1] = uVar11;
    }
  }
  iVar2 = Curl_pgrsUpdate(param_1);
  if (iVar2 == 0) {
    iVar2 = Curl_speedcheck(param_2,*puVar15,*(undefined4 *)(param_2 + 0x94));
    if (iVar2 != 0) {
      return iVar2;
    }
    if (*(int *)(param_2 + 0x130) == 0) {
      if (*(char *)(param_2 + 0x307) == '\0') {
        uVar13 = *(uint *)(param_2 + 0x50);
        iVar2 = *(int *)(param_2 + 0x54);
        if (iVar2 != -1 || uVar13 != 0xffffffff) {
          uVar9 = *(uint *)(param_2 + 0x70);
          iVar5 = *(int *)(param_2 + 0x74);
          if (((iVar2 != iVar5 || uVar13 != uVar9) &&
              (iVar5 != *(int *)(param_2 + 0x8684) +
                        iVar2 + (uint)CARRY4(*(uint *)(param_2 + 0x8680),uVar13) ||
               uVar9 != *(uint *)(param_2 + 0x8680) + uVar13)) && (*(int *)(param_2 + 0x13c) == 0))
          {
            Curl_failf(param_2,"transfer closed with %lld bytes remaining to read",uVar13 - uVar9,
                       (iVar2 - iVar5) - (uint)(uVar13 < uVar9));
            return 0x12;
          }
        }
        if ((*(char *)(param_2 + 0x148) != '\0') && (param_1[8] != 4)) {
          Curl_failf(param_2,"transfer closed with outstanding read data remaining");
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
          uVar11 = curlx_tvdiff(*puVar15,*(undefined4 *)(param_2 + 0x94),
                                *(undefined4 *)(param_2 + 0x500),*(undefined4 *)(param_2 + 0x504));
          Curl_failf(param_2,"Operation timed out after %ld milliseconds with %lld bytes received",
                     uVar11);
          return 0x1c;
        }
        uVar11 = curlx_tvdiff(*puVar15,*(undefined4 *)(param_2 + 0x94),
                              *(undefined4 *)(param_2 + 0x500),*(undefined4 *)(param_2 + 0x504));
        Curl_failf(param_2,
                   "Operation timed out after %ld milliseconds with %lld out of %lld bytes received"
                   ,uVar11);
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

