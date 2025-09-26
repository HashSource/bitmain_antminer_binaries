
/* WARNING: Type propagation algorithm not settling */

int ssl3_read_bytes(SSL *param_1,int param_2,int *param_3,void *param_4,uint param_5,int param_6,
                   uint *param_7)

{
  size_t *psVar1;
  byte bVar2;
  char cVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  uchar *puVar8;
  BIO *b;
  SSL_CTX *pSVar9;
  int iVar10;
  uchar *puVar11;
  SSL_SESSION *c;
  int iVar12;
  uchar *puVar13;
  int iVar15;
  uint uVar16;
  void *pvVar17;
  uint uVar18;
  undefined4 uVar19;
  KSSL_CTX *pKVar20;
  SRTP_PROTECTION_PROFILE *pSVar21;
  undefined4 uVar22;
  void *pvVar23;
  void *pvVar24;
  int *piVar25;
  int *piVar26;
  void *local_58;
  SRTP_PROTECTION_PROFILE *local_4c;
  char acStack_38 [20];
  uchar *puVar14;
  
  if (*(int *)(((int *)param_1->type)[0x19] + 0x30) << 0x1c < 0) {
    bVar5 = true;
    bVar7 = false;
    bVar6 = false;
  }
  else {
    iVar15 = *(int *)param_1->type;
    bVar7 = iVar15 != 0x10000 && 0x303 < iVar15;
    bVar6 = iVar15 == 0x10000;
    bVar4 = 0x303 >= iVar15;
    bVar5 = bVar6 || bVar4;
    bVar6 = !bVar6 && !bVar4;
  }
  if ((param_1[4].type == 0) && (iVar15 = ssl3_setup_read_buffer(param_1), iVar15 == 0)) {
    return -1;
  }
  uVar16 = param_2 - 0x17;
  if (uVar16 != 0) {
    uVar16 = 1;
  }
  if (param_2 == 0x16 || (param_2 == 0 || param_2 == 0x17)) {
    if (param_6 == 0) {
      uVar16 = 0;
    }
    else {
      uVar16 = uVar16 & 1;
    }
    if (uVar16 == 0) {
      if ((param_2 == 0x16) && (uVar16 = *(uint *)(param_1[9].sid_ctx + 0x10), uVar16 != 0)) {
        puVar8 = param_1[9].sid_ctx + 0xc;
        if (param_5 == 0) {
          uVar18 = 0;
LAB_000e0346:
          param_1[9].sid_ctx[0xc] = *puVar8;
          if (((1 < uVar16) && (param_1[9].sid_ctx[0xd] = puVar8[1], uVar16 != 2)) &&
             (param_1[9].sid_ctx[0xe] = puVar8[2], uVar16 != 3)) {
            param_1[9].sid_ctx[0xf] = puVar8[3];
          }
        }
        else {
          puVar11 = (uchar *)((int)param_4 + -1);
          puVar14 = puVar8;
          do {
            puVar13 = puVar14 + 1;
            puVar11 = puVar11 + 1;
            *puVar11 = *puVar14;
            uVar18 = (int)puVar13 - (int)puVar8;
            uVar16 = *(int *)(param_1[9].sid_ctx + 0x10) - 1;
            *(uint *)(param_1[9].sid_ctx + 0x10) = uVar16;
            if (puVar13 == puVar8 + param_5) {
              puVar8 = puVar8 + param_5;
              if (uVar16 != 0) goto LAB_000e0346;
              break;
            }
            puVar14 = puVar13;
          } while (uVar16 != 0);
        }
        if (param_3 != (int *)0x0) {
          *param_3 = 0x16;
        }
        *param_7 = uVar18;
        return 1;
      }
      iVar15 = ossl_statem_get_in_handshake(param_1);
      if ((iVar15 == 0) && (iVar15 = SSL_in_init(param_1), iVar15 != 0)) {
        iVar15 = (*(code *)param_1->rwstate)(param_1);
        if (iVar15 < 0) {
          return iVar15;
        }
        if (iVar15 == 0) {
          return -1;
        }
      }
      local_4c = (SRTP_PROTECTION_PROFILE *)0x0;
      local_58 = param_4;
LAB_000e011c:
      do {
        pvVar24 = (void *)param_1[3].renegotiate;
        param_1->bbio = (BIO *)0x1;
        if (pvVar24 == (void *)0x0) goto LAB_000e02c0;
        while (pvVar17 = param_1[5].tlsext_debug_arg, pvVar23 = pvVar17, pvVar17 != (void *)0x0) {
          pvVar23 = (void *)0x0;
          piVar25 = &param_1[5].references;
          do {
            pvVar23 = (void *)((int)pvVar23 + 1);
            if (pvVar24 <= pvVar23) break;
            psVar1 = (size_t *)(piVar25 + 0x14);
            piVar25 = piVar25 + 0xc;
          } while (*psVar1 != 0);
          if (pvVar24 != pvVar23) {
            pvVar17 = (void *)((int)pvVar23 * 0x30);
            break;
          }
          param_1[3].renegotiate = 0;
LAB_000e02c0:
          iVar15 = ssl3_get_record(param_1);
          if (iVar15 < 1) {
            return iVar15;
          }
          pvVar24 = (void *)param_1[3].renegotiate;
          if (pvVar24 == (void *)0x0) {
            uVar22 = 0x52a;
            goto LAB_000e02e0;
          }
        }
        uVar16 = *(uint *)(param_1[9].sid_ctx + 0x10);
        piVar25 = (int *)((int)&param_1[5].references + (int)pvVar17);
        iVar15 = piVar25[1];
        if (uVar16 == 0) {
LAB_000e018e:
          if ((iVar15 != 0x15) && (piVar25[2] != 0)) {
LAB_000e0198:
            param_1[9].kssl_ctx = (KSSL_CTX *)0x0;
          }
          if (*(int *)(param_1->mac_flags + 0xdc) != 0 && iVar15 != 0x16) {
            uVar22 = 0x550;
            uVar19 = 0x91;
            goto LAB_000e054c;
          }
        }
        else {
          if (iVar15 != 0x16) {
            if (-1 < *(int *)(((int *)param_1->type)[0x19] + 0x30) << 0x1c) {
              iVar12 = *(int *)param_1->type;
              iVar10 = iVar12 + -0x10000;
              if (iVar10 != 0) {
                iVar10 = 1;
              }
              if (iVar12 < 0x304) {
                iVar10 = 0;
              }
              if (iVar10 != 0) {
                uVar22 = 0x53e;
                uVar19 = 0x125;
                goto LAB_000e054c;
              }
            }
            goto LAB_000e018e;
          }
          if (piVar25[2] != 0) goto LAB_000e0198;
        }
        if ((param_1->new_session & 2U) != 0) {
          piVar25[2] = 0;
          param_1->bbio = (BIO *)0x1;
          return 0;
        }
        if ((param_2 != iVar15) &&
           ((iVar15 != 0x14 || (!(bool)((param_3 != (int *)0x0 && param_2 == 0x16) & bVar5))))) {
          if (*piVar25 == 2) {
            uVar22 = 0x5c3;
            goto LAB_000e02e0;
          }
          iVar10 = *(int *)param_1->type;
          if (iVar10 == 0x10000) {
            if (iVar15 != 0x15 || param_1->in_handshake != 0) {
              param_1->version = *piVar25;
              ossl_statem_fatal(param_1,10,0x94,0xf4,"ssl/record/rec_layer_s3.c",0x5d1);
              return -1;
            }
          }
          else if (iVar15 != 0x15) {
            if (param_1->new_session << 0x1f < 0) {
              if (iVar15 != 0x16) {
                piVar25[2] = 0;
                piVar25[8] = 1;
                ossl_statem_fatal(param_1,0xffffffff,0x94,0x123,"ssl/record/rec_layer_s3.c",0x654);
                return -1;
              }
              uVar18 = (uint)(*(int *)(((int *)param_1->type)[0x19] + 0x30) << 0x1c) >> 0x1f;
              if (iVar10 < 0x304) {
                uVar18 = 1;
              }
              if (uVar18 != 0) {
                iVar15 = param_1[3].new_session;
                piVar25[8] = 1;
                piVar25[2] = 0;
                if (-1 < iVar15 << 0x1d) goto LAB_000e04ee;
                goto LAB_000e011c;
              }
LAB_000e0206:
              uVar18 = 4 - uVar16;
              if ((uint)piVar25[2] <= 4 - uVar16) {
                uVar18 = piVar25[2];
              }
              memcpy(param_1[9].sid_ctx + uVar16 + 0xc,(void *)(piVar25[5] + piVar25[4]),uVar18);
              piVar25[4] = piVar25[4] + uVar18;
              piVar25[2] = piVar25[2] - uVar18;
              uVar18 = *(int *)(param_1[9].sid_ctx + 0x10) + uVar18;
              *(uint *)(param_1[9].sid_ctx + 0x10) = uVar18;
              if (piVar25[2] == 0) {
                piVar25[8] = 1;
                uVar18 = *(uint *)(param_1[9].sid_ctx + 0x10);
              }
              if (uVar18 < 4) goto LAB_000e011c;
              if (piVar25[1] != 0x14) {
LAB_000e0268:
                iVar15 = ossl_statem_get_in_handshake(param_1);
                if (iVar15 == 0) {
                  pvVar24 = param_1->msg_callback_arg;
                  ossl_statem_set_in_init(param_1,1);
                  iVar15 = (*(code *)param_1->rwstate)(param_1);
                  if (iVar15 < 0) {
                    return iVar15;
                  }
                  if (pvVar24 == (void *)0xb || iVar15 == 0) {
                    return -1;
                  }
                  if ((-1 < param_1[3].new_session << 0x1d) && (param_1[4].bbio == (BIO *)0x0)) {
LAB_000e04ee:
                    param_1->bbio = (BIO *)0x3;
                    b = SSL_get_rbio(param_1);
                    BIO_clear_flags(b,0xf);
                    BIO_set_flags(b,9);
                    return -1;
                  }
                  goto LAB_000e011c;
                }
                iVar15 = piVar25[1];
                if (iVar15 < 0x14) {
LAB_000e053e:
                  uVar22 = 0x6b4;
                }
                else {
LAB_000e027e:
                  if (iVar15 < 0x17) {
                    uVar22 = 0x6bf;
                    uVar19 = 0x44;
                    goto LAB_000e054c;
                  }
                  if (iVar15 != 0x17) goto LAB_000e053e;
                  iVar15 = ossl_statem_app_data_allowed(param_1);
                  if (iVar15 != 0) {
                    *(undefined4 *)(param_1->mac_flags + 0xfc) = 2;
                    return -1;
                  }
                  iVar15 = ossl_statem_skip_early_data(param_1);
                  if (iVar15 != 0) {
                    iVar15 = early_data_count_ok(param_1,piVar25[2],0x68,0);
                    if (iVar15 == 0) {
                      return -1;
                    }
                    piVar25[8] = 1;
                    goto LAB_000e011c;
                  }
                  uVar22 = 0x6df;
                }
                uVar19 = 0xf5;
                goto LAB_000e054c;
              }
            }
            else {
              if (iVar15 == 0x16) goto LAB_000e0206;
              if (iVar15 != 0x14) {
                if (3 < uVar16) goto LAB_000e0268;
                if (0x13 < iVar15) goto LAB_000e027e;
                goto LAB_000e053e;
              }
            }
            uVar22 = 0x677;
            uVar19 = 0x85;
            goto LAB_000e054c;
          }
          iVar15 = piVar25[2];
          iVar10 = piVar25[5] + piVar25[4];
          if ((0 < iVar15) && (cVar3 = *(char *)(piVar25[5] + piVar25[4]), iVar15 != 1)) {
            bVar2 = *(byte *)(iVar10 + 1);
            uVar16 = (uint)bVar2;
            if (iVar15 == 2) {
              if (param_1->read_hash != (EVP_MD_CTX *)0x0) {
                (*(code *)param_1->read_hash)
                          (0,param_1->version,0x15,iVar10,2,param_1,param_1->expand);
              }
              pSVar21 = param_1[2].srtp_profile;
              if (((param_1[2].srtp_profile != (SRTP_PROTECTION_PROFILE *)0x0) ||
                  (pSVar21 = (SRTP_PROTECTION_PROFILE *)param_1[3].method[1].ssl_renegotiate_check,
                  pSVar21 != (SRTP_PROTECTION_PROFILE *)0x0)) ||
                 (pSVar21 = local_4c, local_4c != (SRTP_PROTECTION_PROFILE *)0x0)) {
                (*(code *)pSVar21)(param_1,0x4004,CONCAT11(cVar3,bVar2));
                local_4c = pSVar21;
              }
              if (cVar3 == '\x01') {
                pKVar20 = (KSSL_CTX *)((int)&(param_1[9].kssl_ctx)->service_name + 1);
                *(uint *)(param_1->mac_flags + 0xe0) = uVar16;
                piVar25[8] = 1;
                param_1[9].kssl_ctx = pKVar20;
                if (pKVar20 == (KSSL_CTX *)&DAT_00000005) goto LAB_000e0608;
                if (bVar6) {
                  if (uVar16 != 0x5a) goto LAB_000e05ac;
                  goto LAB_000e011c;
                }
                if (uVar16 == 0) goto LAB_000e0846;
LAB_000e06a8:
                bVar4 = bVar7;
                if (cVar3 == '\x02') {
                  bVar4 = true;
                }
                if (bVar4) {
LAB_000e0852:
                  param_1->bbio = (BIO *)0x1;
                  *(uint *)(param_1->mac_flags + 0xe4) = uVar16;
                  ossl_statem_fatal(param_1,0xffffffff,0x94,uVar16 + 1000,
                                    "ssl/record/rec_layer_s3.c",0x614);
                  BIO_snprintf(acStack_38,0x10,"%d",uVar16);
                  ERR_add_error_data(2,"SSL alert number ",acStack_38);
                  c = (SSL_SESSION *)param_1[2].tlsext_ticket_expected;
                  pSVar9 = (SSL_CTX *)param_1[3].max_send_fragment;
                  param_1->new_session = param_1->new_session | 2;
                  piVar25[8] = 1;
                  SSL_CTX_remove_session(pSVar9,c);
                  return 0;
                }
                if (uVar16 == 100) {
                  ossl_statem_fatal(param_1,0x28,0x94,0x153,"ssl/record/rec_layer_s3.c",0x625);
                  return -1;
                }
              }
              else {
                if ((bVar6) && (uVar16 == 0x5a)) {
                  pKVar20 = (KSSL_CTX *)((int)&(param_1[9].kssl_ctx)->service_name + 1);
                  *(undefined4 *)(param_1->mac_flags + 0xe0) = 0x5a;
                  piVar25[8] = 1;
                  param_1[9].kssl_ctx = pKVar20;
                  if (pKVar20 == (KSSL_CTX *)&DAT_00000005) {
LAB_000e0608:
                    uVar22 = 0x5ff;
                    uVar19 = 0x199;
                    goto LAB_000e054c;
                  }
                  goto LAB_000e011c;
                }
LAB_000e05ac:
                if (uVar16 != 0) goto LAB_000e06a8;
                bVar4 = bVar7;
                if (cVar3 == '\x01') {
                  bVar4 = true;
                }
                if (bVar4) {
LAB_000e0846:
                  param_1->new_session = param_1->new_session | 2;
                  return 0;
                }
                if (cVar3 == '\x02') goto LAB_000e0852;
              }
              if (cVar3 != '\x01') {
                ossl_statem_fatal(param_1,0x2f,0x94,0xf6,"ssl/record/rec_layer_s3.c",0x62d);
                return -1;
              }
              goto LAB_000e011c;
            }
          }
          uVar22 = 0x5e5;
          uVar19 = 0xcd;
LAB_000e054c:
          ossl_statem_fatal(param_1,10,0x94,uVar19,"ssl/record/rec_layer_s3.c",uVar22);
          return -1;
        }
        bVar4 = param_2 == 0x17;
        iVar15 = SSL_in_init(param_1);
        if (iVar15 != 0 && bVar4) {
          if (param_1[2].sid_ctx_length == 0) {
            uVar22 = 0x56e;
            uVar19 = 100;
            goto LAB_000e054c;
          }
        }
        else if (((param_2 == 0x16) && (piVar25[1] == 0x14)) &&
                (*(int *)(param_1[9].sid_ctx + 0x10) != 0)) {
          uVar22 = 0x576;
          uVar19 = 0x85;
          goto LAB_000e054c;
        }
        if (param_3 != (int *)0x0) {
          *param_3 = piVar25[1];
        }
        if (param_5 == 0) {
          if (piVar25[2] != 0) {
            return 0;
          }
          piVar25[8] = 1;
          return 0;
        }
        if (param_6 == 0) {
          uVar16 = 0;
          do {
            uVar18 = param_5 - uVar16;
            if ((uint)piVar25[2] <= param_5 - uVar16) {
              uVar18 = piVar25[2];
            }
            memcpy(local_58,(void *)(piVar25[5] + piVar25[4]),uVar18);
            uVar16 = uVar16 + uVar18;
            local_58 = (void *)((int)local_58 + uVar18);
            iVar15 = piVar25[2];
            piVar25[2] = iVar15 - uVar18;
            piVar25[4] = piVar25[4] + uVar18;
            piVar26 = piVar25;
            if (iVar15 - uVar18 == 0) {
              pvVar23 = (void *)((int)pvVar23 + 1);
              param_1[3].tlsext_hb_seq = 0xf0;
              piVar26 = piVar25 + 0xc;
              piVar25[4] = 0;
              piVar25[8] = 1;
            }
            piVar25 = piVar26;
          } while (pvVar23 < pvVar24 && (uVar16 < param_5 && bVar4));
        }
        else {
          uVar16 = 0;
          do {
            uVar18 = param_5 - uVar16;
            if ((uint)piVar25[2] <= param_5 - uVar16) {
              uVar18 = piVar25[2];
            }
            memcpy(local_58,(void *)(piVar25[5] + piVar25[4]),uVar18);
            local_58 = (void *)((int)local_58 + uVar18);
            if (piVar25[2] == 0) {
              piVar25[8] = 1;
LAB_000e0634:
              pvVar23 = (void *)((int)pvVar23 + 1);
              piVar25 = piVar25 + 0xc;
            }
            else if (piVar25[2] == uVar18) goto LAB_000e0634;
            uVar16 = uVar16 + uVar18;
          } while (pvVar23 < pvVar24 && (uVar16 < param_5 && bVar4));
        }
        if (uVar16 != 0) {
          if (((param_6 == 0 && pvVar24 == pvVar23) && (param_1[3].new_session << 0x1b < 0)) &&
             (param_1[4].bbio == (BIO *)0x0)) {
            ssl3_release_read_buffer(param_1);
          }
          *param_7 = uVar16;
          return 1;
        }
      } while( true );
    }
  }
  uVar22 = 0x4e6;
LAB_000e02e0:
  ossl_statem_fatal(param_1,0x50,0x94,0x44,"ssl/record/rec_layer_s3.c",uVar22);
  return -1;
}

