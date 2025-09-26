
uint * ssl3_get_record(uint *param_1)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  byte *pbVar4;
  uint *puVar5;
  EVP_CIPHER *pEVar6;
  uint *puVar7;
  EVP_MD *pEVar8;
  byte *pbVar9;
  ulong uVar10;
  byte bVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  int *piVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  uint *puVar20;
  char *__s1;
  uint *puVar21;
  byte *pbVar22;
  byte *pbVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  bool bVar28;
  bool bVar29;
  bool bVar30;
  int local_c8;
  undefined1 *local_c4;
  undefined1 auStack_ac [4];
  undefined1 auStack_a8 [64];
  undefined1 auStack_68 [68];
  
  puVar21 = param_1 + 0x23e;
  uVar25 = param_1[0x144];
  uVar24 = 0;
  uVar14 = param_1[0x11d];
  puVar7 = param_1;
  puVar5 = param_1 + 0x24c;
  if (uVar25 == 0) {
    uVar25 = 1;
  }
  do {
    puVar20 = puVar5;
    if ((param_1[0x196] != 0xf1) || (param_1[0x3bf] < 5)) {
      puVar7 = (uint *)ssl3_read_n(param_1,5,param_1[0x19b],0,uVar24 == 0,auStack_ac);
      if ((int)puVar7 < 1) {
        return puVar7;
      }
      uVar15 = param_1[0x3bf];
      param_1[0x196] = 0xf1;
      pbVar23 = (byte *)param_1[0x3be];
      if (-1 < (int)uVar15) {
        if (uVar15 < 3) {
          uVar19 = 0xe1;
          uVar18 = 0x44;
        }
        else {
          if ((param_1[7] != 0) && (param_1[0x3cc] != 0)) {
            bVar11 = *pbVar23 >> 7;
            if (pbVar23[2] != 1) {
              bVar11 = 0;
            }
            if (bVar11 != 0) {
              uVar15 = CONCAT11(*pbVar23,pbVar23[1]) & 0x7fff;
              puVar20[-0xc] = uVar15;
              puVar20[-0xd] = 0x16;
              puVar20[-0xe] = 2;
              if (param_1[0x19b] - 2 < uVar15) {
                ossl_statem_fatal(param_1,0x16,0x8f,0xc6,"ssl/record/ssl3_record.c",0xfb);
                return (uint *)0xffffffff;
              }
              if (8 < uVar15) goto LAB_000e1b70;
              uVar19 = 0x101;
              goto LAB_000e21f6;
            }
          }
          if ((code *)param_1[0x21] != (code *)0x0) {
            (*(code *)param_1[0x21])(0,0,0x100,pbVar23,5,param_1,param_1[0x22]);
          }
          if ((uVar15 != 0) && (uVar26 = (uint)*pbVar23, 1 < uVar15 - 1)) {
            bVar11 = pbVar23[1];
            uVar13 = (uint)CONCAT11(bVar11,pbVar23[2]);
            if (1 < uVar15 - 3) {
              bVar1 = pbVar23[3];
              bVar2 = pbVar23[4];
              puVar20[-0xd] = uVar26;
              puVar20[-0xe] = uVar13;
              HintPreloadData(puVar20);
              uVar15 = (uint)CONCAT11(bVar1,bVar2);
              HintPreloadData(puVar20 + -1);
              HintPreloadData(puVar20 + -2);
              puVar20[-0xc] = uVar15;
              if (param_1[0x140] == 0) {
                if (*(int *)(((int *)param_1[1])[0x19] + 0x30) << 0x1c < 0) {
LAB_000e1ddc:
                  if ((param_1[0x113] != 1) && (*param_1 != uVar13)) {
                    if (((((*param_1 ^ uVar13) & 0xff00) == 0) && (param_1[0xfb] == 0)) &&
                       (param_1[0x100] == 0)) {
                      if (uVar26 == 0x15) {
                        uVar19 = 299;
                        uVar18 = 0x10b;
                        goto LAB_000e1f56;
                      }
                      *param_1 = uVar13;
                    }
                    uVar18 = 0x134;
                    goto LAB_000e22ba;
                  }
                  goto LAB_000e1dec;
                }
                iVar12 = *(int *)param_1[1];
                bVar30 = SBORROW4(iVar12,0x10000);
                iVar16 = iVar12 + -0x10000;
                if (iVar12 != 0x10000) {
                  bVar30 = SBORROW4(iVar12,0x303);
                  iVar16 = iVar12 + -0x303;
                }
                if ((iVar12 == 0x10000 || iVar12 == 0x303) || iVar16 < 0 != bVar30)
                goto LAB_000e1ddc;
                if (bVar11 == 3) goto LAB_000e1e7a;
              }
              else {
LAB_000e1dec:
                if (bVar11 == 3) {
                  if (*(int *)(((int *)param_1[1])[0x19] + 0x30) << 0x1c < 0) {
LAB_000e1dfc:
                    if (uVar15 <= param_1[0x19b] - 5) goto LAB_000e1e06;
                  }
                  else {
                    iVar12 = *(int *)param_1[1];
LAB_000e1e7a:
                    bVar30 = SBORROW4(iVar12,0x10000);
                    iVar16 = iVar12 + -0x10000;
                    if (iVar12 != 0x10000) {
                      bVar30 = SBORROW4(iVar12,0x303);
                      iVar16 = iVar12 + -0x303;
                    }
                    if ((iVar12 == 0x10000 || iVar12 == 0x303) || iVar16 < 0 != bVar30)
                    goto LAB_000e1dfc;
                    puVar7 = (uint *)param_1[0xf3];
                    if (puVar7 != (uint *)0x0) {
                      if (uVar26 != 0x17) {
                        if (uVar26 == 0x14) {
                          puVar7 = *(uint **)(param_1[0x1f] + 0x180);
                          if ((puVar7 != (uint *)0x0) && (*(int *)(param_1[0x1f] + 0x204) != 0))
                          goto LAB_000e213c;
                        }
                        else if ((uVar26 != 0x15) || (param_1[0x19] != 1)) {
LAB_000e213c:
                          uVar19 = 0x15e;
                          uVar18 = 0x1bb;
                          goto LAB_000e214e;
                        }
                      }
                      if (uVar13 != 0x303) {
                        uVar19 = 0x163;
                        uVar18 = 0x10b;
                        goto LAB_000e1d72;
                      }
                    }
                    if (uVar15 <= param_1[0x19b] - 5) goto LAB_000e1b8e;
                  }
                  uVar18 = 0x16b;
                  uVar19 = 0xc6;
                  goto LAB_000e1e2e;
                }
              }
              if (param_1[0x3cc] != 0) {
                __s1 = (char *)param_1[0x3be];
                iVar16 = strncmp(__s1,"GET ",4);
                if ((((iVar16 == 0) || (iVar16 = strncmp(__s1,"POST ",5), iVar16 == 0)) ||
                    (iVar16 = strncmp(__s1,"HEAD ",5), iVar16 == 0)) ||
                   (iVar16 = strncmp(__s1,"PUT ",4), iVar16 == 0)) {
                  uVar19 = 0x142;
                  uVar18 = 0x9c;
                }
                else {
                  iVar16 = strncmp(__s1,"CONNE",5);
                  if (iVar16 == 0) {
                    uVar19 = 0x146;
                    uVar18 = 0x9b;
                  }
                  else {
                    uVar19 = 0x14c;
                    uVar18 = 0x10b;
                  }
                }
LAB_000e1f56:
                ossl_statem_fatal(param_1,0xffffffff,0x8f,uVar18,"ssl/record/ssl3_record.c",uVar19);
                return (uint *)0xffffffff;
              }
              uVar18 = 0x151;
LAB_000e22ba:
              ossl_statem_fatal(param_1,0x46,0x8f,0x10b,"ssl/record/ssl3_record.c",uVar18);
              return (uint *)0xffffffff;
            }
          }
          uVar19 = 0x10f;
          uVar18 = 0x44;
        }
        goto LAB_000e1d72;
      }
      uVar18 = 0xda;
      goto LAB_000e210c;
    }
    HintPreloadData(puVar20);
    uVar15 = puVar20[-0xc];
LAB_000e1b70:
    if (*(int *)(((int *)param_1[1])[0x19] + 0x30) << 0x1c < 0) {
LAB_000e1e06:
      uVar26 = 0x4140;
      puVar7 = (uint *)0x4540;
      if (param_1[0xfa] != 0) {
        uVar26 = 0x4540;
      }
      if (uVar26 < uVar15) {
        uVar18 = 0x187;
        uVar19 = 0x96;
        goto LAB_000e1e2e;
      }
    }
    else {
      iVar12 = *(int *)param_1[1];
      bVar30 = SBORROW4(iVar12,0x10000);
      iVar16 = iVar12 + -0x10000;
      if (iVar12 != 0x10000) {
        bVar30 = SBORROW4(iVar12,0x303);
        iVar16 = iVar12 + -0x303;
      }
      if ((iVar12 == 0x10000 || iVar12 == 0x303) || iVar16 < 0 != bVar30) goto LAB_000e1e06;
LAB_000e1b8e:
      if (0x4100 < uVar15) {
        uVar18 = 0x176;
        uVar19 = 0x96;
        goto LAB_000e1e2e;
      }
    }
    if (puVar20[-0xe] == 2) {
      uVar15 = uVar15 - 3;
      if (uVar15 != 0) goto LAB_000e1e48;
      param_1[0x196] = 0xf0;
LAB_000e1e70:
      uVar15 = param_1[0x3be] + 2;
    }
    else {
      if (uVar15 == 0) {
        param_1[0x196] = 0xf0;
      }
      else {
LAB_000e1e48:
        puVar7 = (uint *)ssl3_read_n(param_1,uVar15,uVar15,1,0,auStack_ac);
        if ((int)puVar7 < 1) {
          return puVar7;
        }
        uVar15 = puVar20[-0xe];
        param_1[0x196] = 0xf0;
        if (uVar15 == 2) goto LAB_000e1e70;
      }
      uVar15 = param_1[0x3be] + 5;
    }
    uVar24 = uVar24 + 1;
    puVar20[-8] = uVar15;
    puVar20[-9] = uVar15;
    puVar20[-0xb] = puVar20[-0xc];
    puVar20[-6] = 0;
    param_1[0x3bf] = 0;
    param_1[0x3cc] = 0;
    if ((uVar25 <= uVar24) || (puVar20[-0xd] != 0x17)) break;
    if ((-1 < *(int *)(*(int *)(param_1[1] + 100) + 0x30) << 0x1f) ||
       ((EVP_CIPHER_CTX *)param_1[0xf3] == (EVP_CIPHER_CTX *)0x0)) goto LAB_000e1c32;
    pEVar6 = EVP_CIPHER_CTX_cipher((EVP_CIPHER_CTX *)param_1[0xf3]);
    puVar7 = (uint *)EVP_CIPHER_flags(pEVar6);
    if (((-1 < (int)puVar7 << 8) || (uVar15 = param_1[0x199], uVar15 == 0)) || (param_1[0x19d] < 5))
    break;
    puVar7 = (uint *)(uint)*(byte *)(uVar15 + param_1[0x19c]);
    iVar16 = param_1[0x19c] + uVar15;
    if ((puVar7 != (uint *)0x17) ||
       (puVar5 = puVar20 + 0xc,
       param_1[0x19d] < CONCAT11(*(undefined1 *)(iVar16 + 3),*(undefined1 *)(iVar16 + 4)) + 5))
    break;
  } while( true );
  if ((uVar24 == 1) && (puVar20[-0xd] == 0x14)) {
    if (*(int *)(((int *)param_1[1])[0x19] + 0x30) << 0x1c < 0) {
LAB_000e2428:
      if (param_1[0x113] == 0) goto LAB_000e1c32;
    }
    else {
      iVar12 = *(int *)param_1[1];
      iVar16 = iVar12 + -0x10000;
      if (iVar16 != 0) {
        iVar16 = 1;
      }
      if (iVar12 < 0x304) {
        iVar16 = 0;
      }
      if (iVar16 == 0) goto LAB_000e2428;
    }
    piVar17 = (int *)param_1[0x1f];
    if ((piVar17[0x60] == 0) || (piVar17[0x81] == 0)) {
      if ((puVar20[-0xc] != 1) || (*(char *)puVar20[-9] != '\x01')) {
        ossl_statem_fatal(param_1,0x2f,0x8f,0x104,"ssl/record/ssl3_record.c",0x1d9);
        return (uint *)0xffffffff;
      }
      uVar14 = param_1[0x3c3];
      puVar20[-0xd] = 0x16;
      uVar14 = uVar14 + 1;
      param_1[0x3c3] = uVar14;
      if (uVar14 < 0x21) {
        puVar7 = (uint *)0x1;
      }
      if (uVar14 < 0x21) {
        puVar20[-6] = 1;
      }
      if (uVar14 < 0x21) {
        param_1[0x197] = 1;
        return puVar7;
      }
      uVar19 = 0x1e5;
      uVar18 = 0x106;
LAB_000e214e:
      ossl_statem_fatal(param_1,10,0x8f,uVar18,"ssl/record/ssl3_record.c",uVar19);
      return (uint *)0xffffffff;
    }
  }
  else {
LAB_000e1c32:
    piVar17 = (int *)param_1[0x1f];
  }
  if ((*piVar17 << 0x17 < 0) && ((EVP_MD_CTX *)param_1[0xf8] != (EVP_MD_CTX *)0x0)) {
    pEVar8 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0xf8]);
    uVar25 = EVP_MD_size(pEVar8);
    if (0x40 < uVar25) {
      uVar18 = 0x1f8;
      uVar19 = 6;
      goto LAB_000e2112;
    }
    if (uVar24 != 0) {
      uVar15 = param_1[0x240];
      if (uVar25 <= uVar15) {
        uVar26 = 0;
        puVar7 = puVar21;
        do {
          uVar13 = param_1[1];
          uVar27 = puVar7[5];
          puVar7[2] = uVar15 - uVar25;
          HintPreloadData(puVar7 + 0x35);
          uVar26 = uVar26 + 1;
          iVar16 = (**(code **)(*(int *)(uVar13 + 100) + 4))(param_1,puVar7,auStack_a8,0);
          if ((iVar16 == 0) ||
             (iVar16 = CRYPTO_memcmp(auStack_a8,(void *)((uVar15 - uVar25) + uVar27),uVar25),
             iVar16 != 0)) {
            uVar18 = 0x209;
            goto LAB_000e1cc4;
          }
          if (uVar26 == uVar24) goto LAB_000e1f68;
          uVar15 = puVar7[0xe];
          puVar7 = puVar7 + 0xc;
        } while (uVar25 <= uVar15);
      }
      uVar19 = 0x201;
LAB_000e21f6:
      uVar18 = 0xa0;
LAB_000e1d72:
      ossl_statem_fatal(param_1,0x32,0x8f,uVar18,"ssl/record/ssl3_record.c",uVar19);
      return (uint *)0xffffffff;
    }
  }
LAB_000e1f68:
  uVar25 = param_1[0x240];
  local_c8 = (*(code *)**(undefined4 **)(param_1[1] + 100))(param_1,puVar21,uVar24,0);
  if (local_c8 == 0) {
    iVar16 = ossl_statem_in_error(param_1);
    if (iVar16 != 0) {
      return (uint *)0xffffffff;
    }
    if ((uVar24 == 1) && (iVar16 = ossl_statem_skip_early_data(param_1), iVar16 != 0)) {
      iVar16 = early_data_count_ok(param_1,param_1[0x240],0x68,0);
      goto joined_r0x000e218e;
    }
    uVar18 = 0x233;
    uVar19 = 0x81;
  }
  else {
    if ((((uVar14 != 0) && (param_1[0xf3] != 0)) && ((*(uint *)param_1[0x1f] & 0x100) == 0)) &&
       (pEVar8 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0xf8]), pEVar8 != (EVP_MD *)0x0)) {
      pEVar8 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[0xf8]);
      uVar14 = EVP_MD_size(pEVar8);
      if (0x40 < uVar14) {
        uVar18 = 0x24b;
LAB_000e210c:
        uVar19 = 0x44;
LAB_000e2112:
        ossl_statem_fatal(param_1,0x50,0x8f,uVar19,"ssl/record/ssl3_record.c",uVar18);
        return (uint *)0xffffffff;
      }
      if (uVar24 != 0) {
        if (uVar14 <= param_1[0x241]) {
          uVar15 = 0;
          puVar7 = puVar21;
          do {
            pEVar6 = EVP_CIPHER_CTX_cipher((EVP_CIPHER_CTX *)param_1[0xf3]);
            uVar10 = EVP_CIPHER_flags(pEVar6);
            if (((uVar10 & 0xf0007) == 2) && (puVar7[3] < uVar14 + 1)) break;
            pEVar6 = EVP_CIPHER_CTX_cipher((EVP_CIPHER_CTX *)param_1[0xf3]);
            uVar10 = EVP_CIPHER_flags(pEVar6);
            if ((uVar10 & 0xf0007) == 2) {
              iVar16 = ssl3_cbc_copy_mac(auStack_68,puVar7,uVar14);
              if (iVar16 == 0) {
                uVar18 = 0x26a;
                goto LAB_000e210c;
              }
              bVar30 = false;
              puVar7[2] = puVar7[2] - uVar14;
              local_c4 = auStack_68;
            }
            else {
              HintPreloadData(puVar7 + 0x1a);
              local_c4 = (undefined1 *)(puVar7[5] + (puVar7[2] - uVar14));
              bVar30 = local_c4 == (undefined1 *)0x0;
              puVar7[2] = puVar7[2] - uVar14;
            }
            iVar16 = (**(code **)(*(int *)(param_1[1] + 100) + 4))(param_1,puVar7,auStack_a8,0);
            if (iVar16 == 0) {
              bVar30 = true;
            }
            if ((bVar30) || (iVar16 = CRYPTO_memcmp(auStack_a8,local_c4,uVar14), iVar16 != 0)) {
              local_c8 = -1;
            }
            uVar15 = uVar15 + 1;
            if (uVar14 + 0x4400 < puVar7[2]) {
              local_c8 = -1;
            }
            if (uVar15 == uVar24) goto LAB_000e1f9c;
            puVar5 = puVar7 + 0xf;
            HintPreloadData(puVar7 + 0x27);
            puVar7 = puVar7 + 0xc;
          } while (uVar14 <= *puVar5);
        }
        ossl_statem_fatal(param_1,0x32,0x8f,0xa0,"ssl/record/ssl3_record.c",0x25c);
        return (uint *)0xffffffff;
      }
    }
LAB_000e1f9c:
    if (-1 < local_c8) {
      if (uVar24 != 0) {
        uVar14 = 0;
        do {
          if (param_1[0xfa] != 0) {
            HintPreloadData(puVar21 + 0x1a);
            if (0x4400 < puVar21[2]) {
              uVar18 = 0x2b0;
              uVar19 = 0x8c;
              goto LAB_000e1e2e;
            }
            iVar16 = ssl3_do_uncompress(param_1,puVar21);
            if (iVar16 == 0) {
              ossl_statem_fatal(param_1,0x1e,0x8f,0x6b,"ssl/record/ssl3_record.c",0x2b5);
              return (uint *)0xffffffff;
            }
          }
          piVar17 = (int *)param_1[1];
          if (*(int *)(piVar17[0x19] + 0x30) << 0x1c < 0) {
LAB_000e21ac:
            uVar15 = puVar21[2];
          }
          else {
            iVar12 = *piVar17;
            bVar30 = SBORROW4(iVar12,0x10000);
            iVar16 = iVar12 + -0x10000;
            if (iVar12 != 0x10000) {
              bVar30 = SBORROW4(iVar12,0x303);
              iVar16 = iVar12 + -0x303;
            }
            if ((iVar12 == 0x10000 || iVar12 == 0x303) || iVar16 < 0 != bVar30) goto LAB_000e21ac;
            if (param_1[0xf3] == 0) {
              uVar15 = puVar21[2];
              uVar25 = puVar21[1];
LAB_000e209e:
              HintPreloadData(puVar21 + 0x19);
              if ((uVar25 - 0x15 < 2) && (uVar15 == 0)) {
                uVar19 = 0x2e2;
                uVar18 = 0x10f;
                goto LAB_000e214e;
              }
            }
            else {
              if (puVar21[1] == 0x15) {
                uVar15 = puVar21[2];
                uVar25 = 0x15;
                goto LAB_000e209e;
              }
              uVar25 = puVar21[2];
              uVar15 = puVar21[1] - 0x17;
              if (uVar15 != 0) {
                uVar15 = 1;
              }
              if (uVar25 == 0) {
                uVar15 = uVar15 | 1;
              }
              if (uVar15 != 0) {
                uVar19 = 0x2c2;
                uVar18 = 0x1bb;
                goto LAB_000e214e;
              }
              uVar15 = uVar25 - 1;
              if (uVar15 == 0) {
                pbVar23 = (byte *)puVar21[5];
              }
              else {
                pbVar22 = (byte *)puVar21[5];
                pbVar23 = pbVar22 + uVar15;
                if (pbVar22[uVar15] == 0) {
                  pbVar4 = pbVar22 + (uVar25 - 2);
                  do {
                    pbVar9 = pbVar4;
                    uVar15 = uVar15 - 1;
                    pbVar23 = pbVar22;
                    if (uVar15 == 0) break;
                    pbVar4 = pbVar9 + -1;
                    pbVar23 = pbVar9;
                  } while (*pbVar9 == 0);
                }
              }
              puVar21[2] = uVar15;
              bVar11 = *pbVar23;
              puVar21[1] = (uint)bVar11;
              if (2 < bVar11 - 0x15) {
                uVar19 = 0x2d1;
                uVar18 = 0x1bb;
                goto LAB_000e214e;
              }
              if ((code *)param_1[0x21] == (code *)0x0) {
                iVar12 = *piVar17;
                bVar30 = SBORROW4(iVar12,0x10000);
                iVar16 = iVar12 + -0x10000;
                bVar28 = iVar12 != 0x10000;
                if (bVar28) {
                  bVar30 = SBORROW4(iVar12,0x303);
                  iVar16 = iVar12 + -0x303;
                }
                bVar29 = iVar12 != 0x303;
                if ((bVar28 && bVar29) && iVar16 < 0 == bVar30) {
                  iVar12 = 1;
                }
                if ((!bVar28 || !bVar29) || iVar16 < 0 != bVar30) {
                  iVar12 = 0;
                }
              }
              else {
                (*(code *)param_1[0x21])(0,*param_1,0x101,pbVar23,1,param_1,param_1[0x22]);
                if (*(int *)(((int *)param_1[1])[0x19] + 0x30) << 0x1c < 0) goto LAB_000e21ac;
                iVar12 = *(int *)param_1[1];
                uVar15 = puVar21[2];
                bVar30 = SBORROW4(iVar12,0x10000);
                iVar16 = iVar12 + -0x10000;
                bVar28 = iVar12 != 0x10000;
                if (bVar28) {
                  bVar30 = SBORROW4(iVar12,0x303);
                  iVar16 = iVar12 + -0x303;
                }
                bVar29 = iVar12 != 0x303;
                if ((bVar28 && bVar29) && iVar16 < 0 == bVar30) {
                  iVar12 = 1;
                }
                if ((!bVar28 || !bVar29) || iVar16 < 0 != bVar30) {
                  iVar12 = 0;
                }
              }
              if (iVar12 != 0) {
                uVar25 = puVar21[1];
                goto LAB_000e209e;
              }
            }
          }
          if (0x4000 < uVar15) {
            uVar18 = 0x2e8;
LAB_000e2420:
            uVar19 = 0x92;
LAB_000e1e2e:
            ossl_statem_fatal(param_1,0x16,0x8f,uVar19,"ssl/record/ssl3_record.c",uVar18);
            return (uint *)0xffffffff;
          }
          if (((param_1[0x11d] != 0) &&
              (cVar3 = *(char *)(param_1[0x11d] + 0x1ec), (byte)(cVar3 - 1U) < 4)) &&
             ((uint)(0x200 << (uint)(byte)(cVar3 - 1)) < uVar15)) {
            uVar18 = 0x2f0;
            goto LAB_000e2420;
          }
          puVar21[4] = 0;
          if (uVar15 == 0) {
            uVar25 = param_1[0x3c3];
            param_1[0x3c3] = uVar25 + 1;
            if (0x20 < uVar25 + 1) {
              uVar19 = 0x303;
              uVar18 = 0x12a;
              goto LAB_000e214e;
            }
          }
          else {
            param_1[0x3c3] = 0;
          }
          uVar14 = uVar14 + 1;
          puVar21 = puVar21 + 0xc;
        } while (uVar14 != uVar24);
      }
      if (((param_1[0x1a] == 0xb) && (param_1[0x23f] == 0x17)) &&
         (iVar16 = early_data_count_ok(param_1,param_1[0x240],0), iVar16 == 0)) {
        return (uint *)0xffffffff;
      }
      param_1[0x197] = uVar24;
      return (uint *)0x1;
    }
    iVar16 = ossl_statem_in_error(param_1);
    if (iVar16 != 0) {
      return (uint *)0xffffffff;
    }
    if ((uVar24 == 1) && (iVar16 = ossl_statem_skip_early_data(param_1), iVar16 != 0)) {
      iVar16 = early_data_count_ok(param_1,uVar25,0x68,0);
joined_r0x000e218e:
      if (iVar16 != 0) {
        param_1[0x240] = 0;
        param_1[0x246] = 1;
        param_1[0x197] = 1;
        RECORD_LAYER_reset_read_sequence(param_1 + 0x194);
        return (uint *)0x1;
      }
      return (uint *)0xffffffff;
    }
    uVar18 = 0x2a5;
LAB_000e1cc4:
    uVar19 = 0x119;
  }
  ossl_statem_fatal(param_1,0x14,0x8f,uVar19,"ssl/record/ssl3_record.c",uVar18);
  return (uint *)0xffffffff;
}

