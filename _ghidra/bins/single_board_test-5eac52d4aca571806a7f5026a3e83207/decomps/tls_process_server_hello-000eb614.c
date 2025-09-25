
undefined4 tls_process_server_hello(int *param_1,int *param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  size_t __n;
  int *piVar8;
  uint uVar9;
  undefined4 uVar10;
  int iVar11;
  byte *pbVar12;
  int *piVar13;
  undefined1 *puVar14;
  byte *pbVar15;
  byte *__s1;
  undefined4 *__s2;
  bool bVar16;
  void *pvVar17;
  void *local_3c;
  int local_38;
  void *local_34;
  byte *local_30;
  uint local_2c;
  
  uVar9 = param_2[1];
  local_3c = (void *)0x0;
  if (uVar9 < 2) {
    ossl_statem_fatal(param_1,0x32,0x171,0x9f,"ssl/statem/statem_clnt.c",0x588);
    goto LAB_000eb696;
  }
  puVar14 = (undefined1 *)*param_2;
  iVar3 = *param_1;
  uVar5 = uVar9 - 2;
  uVar2 = *puVar14;
  __s2 = (undefined4 *)(puVar14 + 2);
  uVar1 = puVar14[1];
  *param_2 = (int)__s2;
  param_2[1] = uVar5;
  if (iVar3 == 0x304 && CONCAT11(uVar2,uVar1) == 0x303) {
    if (0x1f < uVar5) {
      iVar3 = memcmp(hrrrandom,__s2,0x20);
      if (iVar3 != 0) {
        iVar3 = param_1[0x1f];
        goto LAB_000eb6b0;
      }
      if (param_1[0x113] != 0) {
        ossl_statem_fatal(param_1,10,0x171,0xf4,"ssl/statem/statem_clnt.c",0x593);
        goto LAB_000eb696;
      }
      iVar3 = uVar9 - 0x22;
      bVar16 = true;
      pbVar15 = puVar14 + 0x22;
      param_1[0x113] = 1;
      *param_2 = (int)pbVar15;
      param_2[1] = iVar3;
      goto LAB_000eb6f0;
    }
LAB_000eb65e:
    uVar10 = 0x5a0;
    goto LAB_000eb668;
  }
  iVar3 = param_1[0x1f];
  if (uVar5 < 0x20) goto LAB_000eb65e;
LAB_000eb6b0:
  bVar16 = false;
  uVar10 = *(undefined4 *)(puVar14 + 6);
  uVar4 = *(undefined4 *)(puVar14 + 10);
  uVar6 = *(undefined4 *)(puVar14 + 0xe);
  *(undefined4 *)(iVar3 + 0x8c) = *__s2;
  *(undefined4 *)(iVar3 + 0x90) = uVar10;
  *(undefined4 *)(iVar3 + 0x94) = uVar4;
  *(undefined4 *)(iVar3 + 0x98) = uVar6;
  uVar10 = *(undefined4 *)(puVar14 + 0x16);
  uVar4 = *(undefined4 *)(puVar14 + 0x1a);
  uVar6 = *(undefined4 *)(puVar14 + 0x1e);
  *(undefined4 *)(iVar3 + 0x9c) = *(undefined4 *)(puVar14 + 0x12);
  *(undefined4 *)(iVar3 + 0xa0) = uVar10;
  *(undefined4 *)(iVar3 + 0xa4) = uVar4;
  *(undefined4 *)(iVar3 + 0xa8) = uVar6;
  pbVar15 = (byte *)(*param_2 + 0x20);
  iVar3 = param_2[1] + -0x20;
  *param_2 = (int)pbVar15;
  param_2[1] = iVar3;
LAB_000eb6f0:
  if (iVar3 == 0) {
LAB_000eb6fc:
    uVar10 = 0x5a8;
  }
  else {
    __s1 = pbVar15 + 1;
    uVar9 = (uint)*pbVar15;
    if (iVar3 - 1U < uVar9) goto LAB_000eb6fc;
    uVar5 = (iVar3 - 1U) - uVar9;
    pbVar15 = __s1 + uVar9;
    param_2[1] = uVar5;
    *param_2 = (int)pbVar15;
    if (0x20 < uVar9) {
      ossl_statem_fatal(param_1,0x2f,0x171,300,"ssl/statem/statem_clnt.c",0x5af);
      goto LAB_000eb696;
    }
    if (uVar5 < 2) {
      uVar10 = 0x5b5;
    }
    else {
      *param_2 = (int)(pbVar15 + 2);
      param_2[1] = uVar5 - 2;
      if (uVar5 - 2 != 0) {
        iVar3 = uVar5 - 3;
        pvVar17 = (void *)(uint)pbVar15[2];
        param_2[1] = iVar3;
        *param_2 = (int)(pbVar15 + 3);
        if (iVar3 == 0) {
          if (!bVar16) {
            local_30 = (byte *)0x0;
            local_2c = 0;
LAB_000eb752:
            iVar3 = tls_collect_extensions(param_1,&local_30,0x300,&local_3c,0,1);
            if ((iVar3 == 0) ||
               (iVar3 = ssl_choose_client_version(param_1,CONCAT11(uVar2,uVar1),local_3c),
               iVar3 == 0)) goto LAB_000eb696;
            piVar13 = (int *)param_1[1];
            if (*(int *)(piVar13[0x19] + 0x30) << 0x1c < 0) {
LAB_000eb786:
              uVar10 = 0x100;
              uVar4 = 0x100;
            }
            else {
LAB_000eb8c6:
              uVar5 = 0;
              if (*piVar13 == 0x10000 || *piVar13 < 0x304) {
                if (!bVar16) goto LAB_000eb786;
                uVar5 = 0;
              }
LAB_000eb8e0:
              if (pvVar17 != (void *)0x0) {
                ossl_statem_fatal(param_1,0x2f,0x171,0x155,"ssl/statem/statem_clnt.c",0x5dc);
                goto LAB_000eb696;
              }
              if ((param_1[0x12a] != uVar9) ||
                 (iVar3 = memcmp(__s1,param_1 + 0x122,uVar9), iVar3 != 0)) {
                ossl_statem_fatal(param_1,0x2f,0x171,999,"ssl/statem/statem_clnt.c",0x5e4);
                goto LAB_000eb696;
              }
              if (bVar16) {
                iVar3 = set_client_ciphersuite(param_1,pbVar15);
                if (iVar3 != 0) {
                  local_34 = pvVar17;
                  EVP_CIPHER_CTX_free((EVP_CIPHER_CTX *)param_1[0xfb]);
                  param_1[0xfb] = 0;
                  iVar3 = tls_collect_extensions(param_1,&local_30,0x800,&local_34,0,1);
                  if ((iVar3 != 0) &&
                     (iVar3 = tls_parse_all_extensions(param_1,0x800,local_34,0,0,1), iVar3 != 0)) {
                    CRYPTO_free(local_34);
                    if ((param_1[0x16e] == 0) && (*(int *)(param_1[0x1f] + 0x214) != 0)) {
                      local_34 = pvVar17;
                      ossl_statem_fatal(param_1,0x2f,0x262,0xd6,"ssl/statem/statem_clnt.c",0x6fd);
                    }
                    else {
                      local_34 = pvVar17;
                      iVar3 = create_synthetic_message_hash(param_1,0,0,0,0);
                      if ((iVar3 != 0) &&
                         (iVar3 = ssl3_finish_mac(param_1,*(undefined4 *)(param_1[0x1b] + 4),
                                                  param_1[0x1d] + 4), iVar3 != 0)) {
                        return 1;
                      }
                    }
                  }
                  CRYPTO_free(local_34);
                  return 0;
                }
                goto LAB_000eb696;
              }
              if ((uVar5 != 0) || (*piVar13 == 0x10000 || *piVar13 < 0x304)) goto LAB_000eb786;
              uVar10 = 0x200;
              uVar4 = 0x200;
            }
            iVar3 = tls_validate_all_contexts(param_1,uVar4,local_3c);
            if (iVar3 == 0) {
              ossl_statem_fatal(param_1,0x2f,0x171,0x6e,"ssl/statem/statem_clnt.c",0x5fa);
              goto LAB_000eb696;
            }
            param_1[0x23] = 0;
            if (*(int *)(((int *)param_1[1])[0x19] + 0x30) << 0x1c < 0) {
LAB_000eb99e:
              if ((*param_1 < 0x301) || ((code *)param_1[0x163] == (code *)0x0)) {
                piVar13 = (int *)param_1[0x11d];
LAB_000eba7c:
                if ((uVar9 != 0) && (__n = piVar13[0x52], uVar9 == __n)) goto LAB_000eba8a;
                goto LAB_000ebad8;
              }
              piVar13 = (int *)param_1[0x11d];
              if (piVar13[0x74] == 0) goto LAB_000eba7c;
              local_34 = (void *)0x100;
              local_38 = 0;
              iVar3 = (*(code *)param_1[0x163])
                                (param_1,piVar13 + 0x12,&local_34,0,&local_38,param_1[0x164]);
              if ((iVar3 == 0) || ((int)local_34 < 1)) {
                ossl_statem_fatal(param_1,0x50,0x171,0x44,"ssl/statem/statem_clnt.c",0x633);
                goto LAB_000eb696;
              }
              piVar8 = (int *)param_1[0x11d];
              piVar8[1] = (int)local_34;
              iVar3 = local_38;
              piVar13 = piVar8;
              if (local_38 == 0) {
                iVar3 = ssl_get_cipher_by_char(param_1,pbVar15);
                piVar13 = (int *)param_1[0x11d];
              }
              piVar8[0x6e] = iVar3;
              if ((uVar9 == 0) || (__n = piVar13[0x52], __n != uVar9)) goto LAB_000eba0e;
LAB_000eba8a:
              iVar3 = memcmp(__s1,piVar13 + 0x53,__n);
              if (iVar3 != 0) goto LAB_000eba0e;
              param_1[0x23] = 1;
LAB_000eba16:
              if ((param_1[0x114] != piVar13[0x5b]) ||
                 (iVar3 = memcmp(piVar13 + 0x5c,param_1 + 0x115,param_1[0x114]), iVar3 != 0)) {
                ossl_statem_fatal(param_1,0x2f,0x171,0x110,"ssl/statem/statem_clnt.c",0x645);
                goto LAB_000eb696;
              }
LAB_000eba36:
              iVar11 = *piVar13;
              if (*param_1 != iVar11) {
                ossl_statem_fatal(param_1,0x46,0x171,0xd2,"ssl/statem/statem_clnt.c",0x66b);
                goto LAB_000eb696;
              }
            }
            else {
              iVar11 = *(int *)param_1[1];
              iVar3 = iVar11 + -0x10000;
              if (iVar3 != 0) {
                iVar3 = 1;
              }
              if (iVar11 < 0x304) {
                iVar3 = 0;
              }
              if (iVar3 == 0) goto LAB_000eb99e;
              iVar3 = RECORD_LAYER_processed_read_pending(param_1 + 0x194);
              if (iVar3 != 0) {
                ossl_statem_fatal(param_1,10,0x171,0xb6,"ssl/statem/statem_clnt.c",0x608);
                goto LAB_000eb696;
              }
              iVar3 = tls_parse_extension(param_1,0x19,0x200,local_3c,0,0);
              if (iVar3 == 0) goto LAB_000eb696;
              piVar13 = (int *)param_1[0x11d];
LAB_000eba0e:
              if (param_1[0x23] != 0) goto LAB_000eba16;
LAB_000ebad8:
              if (piVar13[0x52] != 0) {
                piVar13 = (int *)(param_1[0x178] + 0x50);
                do {
                  ExclusiveAccess(piVar13);
                  bVar16 = (bool)hasExclusiveAccess(piVar13);
                } while (!bVar16);
                *piVar13 = *piVar13 + 1;
                iVar3 = ssl_get_new_session(param_1,0);
                if (iVar3 == 0) goto LAB_000eb696;
                piVar13 = (int *)param_1[0x11d];
              }
              piVar8 = (int *)param_1[1];
              iVar11 = *param_1;
              iVar3 = piVar8[0x19];
              *piVar13 = iVar11;
              if (((*(int *)(iVar3 + 0x30) << 0x1c < 0) ||
                  (iVar3 = *piVar8, iVar3 == 0x10000 || iVar3 < 0x304)) &&
                 (piVar13[0x52] = uVar9, uVar9 != 0)) {
                memcpy(piVar13 + 0x53,__s1,uVar9);
                piVar13 = (int *)param_1[0x11d];
                goto LAB_000eba36;
              }
            }
            iVar3 = param_1[0x1f];
            *(int *)(iVar3 + 0x2a8) = iVar11;
            *(int *)(iVar3 + 0x2ac) = iVar11;
            iVar3 = set_client_ciphersuite(param_1,pbVar15);
            if (iVar3 != 0) {
              if ((param_1[0x23] == 0) || (*(void **)(param_1[0x11d] + 0x1b4) == pvVar17)) {
                if (pvVar17 == (void *)0x0) {
                  iVar3 = 0;
                }
                else {
                  iVar3 = ssl_allow_compression(param_1);
                  if (iVar3 == 0) {
                    ossl_statem_fatal(param_1,0x2f,0x171,0x157,"ssl/statem/statem_clnt.c",0x693);
                    goto LAB_000eb696;
                  }
                  iVar3 = ssl3_comp_find(*(undefined4 *)(param_1[0x134] + 0x9c),pvVar17);
                  if (iVar3 == 0) {
                    ossl_statem_fatal(param_1,0x2f,0x171,0x101,"ssl/statem/statem_clnt.c",0x69b);
                    goto LAB_000eb696;
                  }
                }
                *(int *)(param_1[0x1f] + 0x240) = iVar3;
                iVar3 = tls_parse_all_extensions(param_1,uVar10,local_3c,0,0,1);
                if (iVar3 != 0) {
                  iVar3 = ((int *)param_1[1])[0x19];
                  if ((((*(int *)(iVar3 + 0x30) << 0x1c < 0) ||
                       (iVar11 = *(int *)param_1[1], iVar11 < 0x304)) || (iVar11 == 0x10000)) ||
                     ((iVar3 = (**(code **)(iVar3 + 8))(param_1), iVar3 != 0 &&
                      (iVar3 = (**(code **)(*(int *)(param_1[1] + 100) + 0x10))(param_1,0x91),
                      iVar3 != 0)))) {
                    CRYPTO_free(local_3c);
                    return 3;
                  }
                }
              }
              else {
                ossl_statem_fatal(param_1,0x2f,0x171,0x158,"ssl/statem/statem_clnt.c",0x68c);
              }
            }
            goto LAB_000eb696;
          }
        }
        else if (iVar3 != 1) {
          uVar7 = (uint)CONCAT11(pbVar15[3],pbVar15[4]);
          if (uVar7 <= uVar5 - 5) {
            pbVar12 = pbVar15 + 5;
            if (uVar7 == uVar5 - 5) {
              *param_2 = (int)(pbVar12 + uVar7);
              param_2[1] = 0;
              local_30 = pbVar12;
              local_2c = uVar7;
              if (!bVar16) goto LAB_000eb752;
              piVar13 = (int *)param_1[1];
              uVar5 = *(uint *)(piVar13[0x19] + 0x30) & 8;
              if (uVar5 == 0) goto LAB_000eb8c6;
              goto LAB_000eb8e0;
            }
          }
        }
        ossl_statem_fatal(param_1,0x32,0x171,0x10f,"ssl/statem/statem_clnt.c",0x5c5);
        goto LAB_000eb696;
      }
      uVar10 = 0x5bb;
    }
  }
LAB_000eb668:
  ossl_statem_fatal(param_1,0x32,0x171,0x9f,"ssl/statem/statem_clnt.c",uVar10);
LAB_000eb696:
  CRYPTO_free(local_3c);
  return 0;
}

