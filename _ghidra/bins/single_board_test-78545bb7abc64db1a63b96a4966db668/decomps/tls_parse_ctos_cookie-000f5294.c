
undefined4 tls_parse_ctos_cookie(int *param_1,undefined4 *param_2)

{
  char cVar1;
  char *pcVar2;
  EVP_MD_CTX *ctx;
  EVP_PKEY *pkey;
  EVP_MD *type;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  undefined1 *puVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  char *pcVar16;
  bool bVar17;
  undefined8 uVar18;
  int local_1148;
  uint local_1144;
  int local_1140;
  undefined4 local_113c;
  undefined1 auStack_1138 [4];
  char *local_1134;
  uint local_1130;
  undefined1 auStack_112c [24];
  undefined1 auStack_1114 [32];
  undefined1 auStack_10f4 [4304];
  
  if (*(int *)(param_1[0x134] + 0x88) == 0) {
    return 1;
  }
  if (-1 < *(int *)param_1[0x1f] << 0x14) {
    return 1;
  }
  uVar13 = param_2[1];
  if (1 < uVar13) {
    puVar7 = (undefined1 *)*param_2;
    uVar12 = (uint)CONCAT11(*puVar7,puVar7[1]);
    if (uVar12 <= uVar13 - 2) {
      pcVar16 = puVar7 + 2;
      if (uVar12 == uVar13 - 2) {
        *param_2 = pcVar16 + uVar12;
        param_2[1] = 0;
        local_1134 = pcVar16;
        local_1130 = uVar12;
        if ((uVar12 < 0x20) || (uVar13 = uVar13 - 0x22, uVar12 < uVar13)) {
          uVar11 = 0x2fb;
          goto LAB_000f53b4;
        }
        ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
        pkey = (EVP_PKEY *)EVP_PKEY_new_raw_private_key(0x357,0,param_1[0x178] + 400,0x20);
        if (pkey == (EVP_PKEY *)0x0 || ctx == (EVP_MD_CTX *)0x0) {
          EVP_MD_CTX_free(ctx);
          EVP_PKEY_free(pkey);
          ossl_statem_fatal(param_1,0x50,0x266,0x41,"ssl/statem/extensions_srvr.c",0x30a);
          return 0;
        }
        local_1140 = 0x20;
        type = EVP_sha256();
        iVar3 = EVP_DigestSignInit(ctx,(EVP_PKEY_CTX **)0x0,type,(ENGINE *)0x0,pkey);
        if (0 < iVar3) {
          iVar3 = EVP_DigestSign(ctx,auStack_1114,&local_1140,pcVar16,uVar13);
          if ((0 < iVar3) && (local_1140 == 0x20)) {
            EVP_MD_CTX_free(ctx);
            EVP_PKEY_free(pkey);
            iVar3 = CRYPTO_memcmp(auStack_1114,pcVar16 + uVar13,0x20);
            if (iVar3 != 0) {
              uVar11 = 799;
LAB_000f548c:
              ossl_statem_fatal(param_1,0x2f,0x266,0x134,"ssl/statem/extensions_srvr.c",uVar11);
              return 0;
            }
            if (local_1130 < 2) {
              uVar11 = 0x325;
              goto LAB_000f54b0;
            }
            local_1130 = local_1130 - 2;
            if (CONCAT11(*local_1134,local_1134[1]) != 1) {
              return 1;
            }
            local_1134 = local_1134 + 2;
            iVar3 = PACKET_get_net_2(&local_1134,&local_1148);
            if (iVar3 == 0) {
              uVar11 = 0x334;
              goto LAB_000f54b0;
            }
            if (local_1148 != 0x304) {
              ossl_statem_fatal(param_1,0x2f,0x266,0x74,"ssl/statem/extensions_srvr.c",0x339);
              return 0;
            }
            iVar3 = PACKET_get_net_2(&local_1134,&local_1144);
            pcVar2 = local_1134;
            if (iVar3 == 0) {
              uVar11 = 0x33f;
              goto LAB_000f54b0;
            }
            if (local_1130 < 2) {
              uVar11 = 0x346;
              goto LAB_000f54b0;
            }
            local_1130 = local_1130 - 2;
            local_1134 = local_1134 + 2;
            if ((*(ushort *)(param_1[0x1f] + 0x356) != local_1144) ||
               (iVar14 = *(int *)(param_1[0x1f] + 0x210),
               iVar3 = ssl_get_cipher_by_char(param_1,pcVar2,0), iVar14 != iVar3)) {
              ossl_statem_fatal(param_1,0x2f,0x266,0xba,"ssl/statem/extensions_srvr.c",0x351);
              return 0;
            }
            pcVar2 = local_1134;
            uVar13 = local_1130;
            if (local_1130 != 0) {
              cVar1 = *local_1134;
              pcVar2 = local_1134 + 1;
              uVar13 = local_1130 - 1;
              if (7 < local_1130 - 1) {
                uVar13 = local_1130 - 9;
                uVar5 = (uint)(byte)local_1134[4] |
                        (uint)(byte)local_1134[3] << 8 |
                        (uint)(byte)local_1134[1] << 0x18 | (uint)(byte)local_1134[2] << 0x10;
                uVar8 = (uint)(byte)local_1134[7] << 8 |
                        (uint)(byte)local_1134[6] << 0x10 |
                        (uint)(byte)local_1134[5] << 0x18 | (uint)(byte)local_1134[8];
                pcVar2 = local_1134 + 9;
                if (1 < uVar13) {
                  pcVar4 = local_1134 + 0xb;
                  uVar9 = (uint)CONCAT11(local_1134[9],local_1134[10]);
                  if (uVar9 <= local_1130 - 0xb) {
                    uVar13 = (local_1130 - 0xb) - uVar9;
                    pcVar10 = pcVar4 + uVar9;
                    pcVar2 = pcVar10;
                    if (uVar13 != 0) {
                      uVar15 = (uint)(byte)pcVar4[uVar9];
                      if (uVar15 <= uVar13 - 1) {
                        local_1130 = (uVar13 - 1) - uVar15;
                        local_1134 = pcVar10 + 1 + uVar15;
                        pcVar2 = local_1134;
                        uVar13 = local_1130;
                        if (local_1130 == 0x20) {
                          uVar13 = time((time_t *)0x0);
                          uVar6 = (int)uVar13 >> 0x1f;
                          bVar17 = uVar5 <= uVar6;
                          if (uVar6 == uVar5) {
                            bVar17 = uVar8 <= uVar13;
                          }
                          if (!bVar17) {
                            return 1;
                          }
                          bVar17 = uVar6 - uVar5 == (uint)(uVar13 < uVar8);
                          if (uVar6 - uVar5 == (uint)(uVar13 < uVar8)) {
                            bVar17 = uVar13 - uVar8 < 0x259;
                          }
                          if (!bVar17) {
                            return 1;
                          }
                          iVar3 = (**(code **)(param_1[0x134] + 0x88))(param_1,pcVar10 + 1,uVar15);
                          if (iVar3 == 0) {
                            uVar11 = 0x36a;
                            goto LAB_000f548c;
                          }
                          uVar18 = WPACKET_init_static_len(auStack_112c,auStack_10f4,0x10cc,0);
                          if ((int)uVar18 == 0) {
                            ossl_statem_fatal(param_1,0x50,0x266,0x44,"ssl/statem/extensions_srvr.c"
                                              ,0x375);
                            return 0;
                          }
                          iVar3 = WPACKET_put_bytes__(auStack_112c,(int)((ulonglong)uVar18 >> 0x20),
                                                      2,0,1);
                          if ((((iVar3 != 0) &&
                               (iVar3 = WPACKET_start_sub_packet_len__(auStack_112c,3), iVar3 != 0))
                              && (iVar3 = WPACKET_put_bytes__(auStack_112c,2,0x303,0,2), iVar3 != 0)
                              ) && ((iVar3 = WPACKET_memcpy(auStack_112c,hrrrandom,0x20), iVar3 != 0
                                    && (iVar3 = WPACKET_sub_memcpy__
                                                          (auStack_112c,param_1 + 0x122,
                                                           param_1[0x12a],1), iVar3 != 0)))) {
                            uVar18 = (**(code **)(param_1[1] + 0x50))
                                               (*(undefined4 *)(param_1[0x1f] + 0x210),auStack_112c,
                                                auStack_1138);
                            if (((int)uVar18 != 0) &&
                               (iVar3 = WPACKET_put_bytes__(auStack_112c,
                                                            (int)((ulonglong)uVar18 >> 0x20),0,0,1),
                               iVar3 != 0)) {
                              uVar18 = WPACKET_start_sub_packet_len__(auStack_112c,2);
                              if ((int)uVar18 != 0) {
                                iVar3 = WPACKET_put_bytes__(auStack_112c,
                                                            (int)((ulonglong)uVar18 >> 0x20),0x2b,0,
                                                            2);
                                if (iVar3 != 0) {
                                  uVar18 = WPACKET_start_sub_packet_len__(auStack_112c,2);
                                  if (((int)uVar18 != 0) &&
                                     (iVar3 = WPACKET_put_bytes__(auStack_112c,
                                                                  (int)((ulonglong)uVar18 >> 0x20),
                                                                  *param_1,*param_1 >> 0x1f,2),
                                     iVar3 != 0)) {
                                    uVar18 = WPACKET_close(auStack_112c);
                                    uVar11 = (undefined4)((ulonglong)uVar18 >> 0x20);
                                    if ((int)uVar18 != 0) {
                                      if (cVar1 == '\0') {
LAB_000f583a:
                                        iVar3 = WPACKET_put_bytes__(auStack_112c,uVar11,0x2c,0,2);
                                        if ((((iVar3 != 0) &&
                                             (iVar3 = WPACKET_start_sub_packet_len__(auStack_112c,2)
                                             , iVar3 != 0)) &&
                                            (iVar3 = WPACKET_sub_memcpy__
                                                               (auStack_112c,pcVar16,uVar12,2),
                                            iVar3 != 0)) &&
                                           (((iVar3 = WPACKET_close(auStack_112c), iVar3 != 0 &&
                                             (iVar3 = WPACKET_close(auStack_112c), iVar3 != 0)) &&
                                            ((iVar3 = WPACKET_close(auStack_112c), iVar3 != 0 &&
                                             ((iVar3 = WPACKET_get_total_written
                                                                 (auStack_112c,&local_113c),
                                              iVar3 != 0 &&
                                              (iVar3 = WPACKET_finish(auStack_112c), iVar3 != 0)))))
                                            ))) {
                                          iVar3 = create_synthetic_message_hash
                                                            (param_1,pcVar4,uVar9,auStack_10f4,
                                                             local_113c);
                                          if (iVar3 != 0) {
                                            param_1[0x113] = 1;
                                            param_1[0x16f] = 1;
                                            return 1;
                                          }
                                          return 0;
                                        }
                                        WPACKET_cleanup(auStack_112c);
                                        uVar11 = 0x3a5;
                                      }
                                      else {
                                        iVar3 = WPACKET_put_bytes__(auStack_112c,uVar11,0x33,0,2);
                                        if (iVar3 != 0) {
                                          uVar18 = WPACKET_start_sub_packet_len__(auStack_112c,2);
                                          if (((int)uVar18 != 0) &&
                                             (iVar3 = WPACKET_put_bytes__(auStack_112c,
                                                                          (int)((ulonglong)uVar18 >>
                                                                               0x20),
                                                                          *(undefined2 *)
                                                                           (param_1[0x1f] + 0x356),0
                                                                          ,2), iVar3 != 0)) {
                                            uVar18 = WPACKET_close(auStack_112c);
                                            uVar11 = (undefined4)((ulonglong)uVar18 >> 0x20);
                                            if ((int)uVar18 != 0) goto LAB_000f583a;
                                          }
                                        }
                                        WPACKET_cleanup(auStack_112c);
                                        uVar11 = 0x397;
                                      }
                                      goto LAB_000f5396;
                                    }
                                  }
                                }
                                WPACKET_cleanup(auStack_112c);
                                uVar11 = 0x38d;
                                goto LAB_000f5396;
                              }
                            }
                          }
                          WPACKET_cleanup(auStack_112c);
                          uVar11 = 900;
                          goto LAB_000f5396;
                        }
                      }
                    }
                  }
                }
              }
            }
            local_1130 = uVar13;
            local_1134 = pcVar2;
            uVar11 = 0x35b;
LAB_000f54b0:
            ossl_statem_fatal(param_1,0x32,0x266,0x9f,"ssl/statem/extensions_srvr.c",uVar11);
            return 0;
          }
        }
        EVP_MD_CTX_free(ctx);
        EVP_PKEY_free(pkey);
        uVar11 = 0x316;
LAB_000f5396:
        ossl_statem_fatal(param_1,0x50,0x266,0x44,"ssl/statem/extensions_srvr.c",uVar11);
        return 0;
      }
    }
  }
  uVar11 = 0x2f1;
LAB_000f53b4:
  ossl_statem_fatal(param_1,0x32,0x266,0x9f,"ssl/statem/extensions_srvr.c",uVar11);
  return 0;
}

