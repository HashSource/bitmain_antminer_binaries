
/* WARNING: Heritage AFTER dead removal. Example location: r0 : 0x001022b0 */
/* WARNING: Restarted to delay deadcode elimination for space: register */
/* WARNING: Exceeded maximum restarts with more pending */

SSL * tls_post_process_client_hello(SSL *param_1,int param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  SSL *ptr;
  stack_st_SSL_CIPHER *psVar3;
  int iVar4;
  long lVar5;
  SSL_CIPHER *c;
  ulong uVar6;
  void *pvVar7;
  SSL_SESSION *pSVar8;
  _func_3220 *p_Var9;
  _func_3219 *p_Var10;
  BUF_MEM *pBVar11;
  uint uVar12;
  size_t len;
  byte *pbVar13;
  code *pcVar14;
  int iVar15;
  SSL_METHOD *pSVar16;
  undefined4 uVar17;
  _func_3197 *p_Var18;
  undefined4 uVar19;
  int iVar20;
  EVP_CIPHER_CTX *__s2;
  int *piVar21;
  uint *puVar22;
  int *piVar23;
  _func_3210 *p_Var24;
  int iVar25;
  bool bVar26;
  undefined4 local_40;
  int local_3c;
  int local_38;
  undefined4 local_34;
  int local_30 [2];
  void *local_28;
  uint local_24;
  
  if (param_2 == 3) {
    local_3c = 0;
    local_40 = 0x50;
    p_Var24 = param_1[3].method[2].ssl_ctrl;
    local_38 = 0;
    local_34 = 0;
    piVar23 = (int *)param_1[3].references;
    if (p_Var24 != (_func_3210 *)0x0) {
      lVar5 = (*p_Var24)(param_1,(int)&local_40,(long)param_1[3].method[2].ssl_ctx_ctrl,(void *)0x0)
      ;
      if (lVar5 == -1) {
        param_1->bbio = (BIO *)&DAT_00000007;
        return (SSL *)0x3;
      }
      if (lVar5 != 1) {
        ossl_statem_fatal(param_1,local_40,0x209,0xea,"ssl/statem/statem_srvr.c",0x669);
        goto LAB_00102394;
      }
    }
    iVar25 = param_1->mac_flags;
    iVar20 = piVar23[3];
    iVar4 = piVar23[4];
    iVar15 = piVar23[5];
    *(int *)(iVar25 + 0xac) = piVar23[2];
    *(int *)(iVar25 + 0xb0) = iVar20;
    *(int *)(iVar25 + 0xb4) = iVar4;
    *(int *)(iVar25 + 0xb8) = iVar15;
    iVar20 = piVar23[7];
    iVar4 = piVar23[8];
    iVar15 = piVar23[9];
    *(int *)(iVar25 + 0xbc) = piVar23[6];
    *(int *)(iVar25 + 0xc0) = iVar20;
    *(int *)(iVar25 + 0xc4) = iVar4;
    *(int *)(iVar25 + 200) = iVar15;
    if (*piVar23 != 0) {
      pBVar11 = (BUF_MEM *)piVar23[1];
      if ((pBVar11 == (BUF_MEM *)0x2) || (((uint)pBVar11 & 0xff00) != 0x300)) {
        ossl_statem_fatal(param_1,0x46,0x209,0xfc,"ssl/statem/statem_srvr.c",0x67d);
        goto LAB_00102394;
      }
      param_1[3].init_buf = pBVar11;
    }
    if (*(int *)(((int *)param_1->type)[0x19] + 0x30) << 0x1c < 0) {
      if (*(int *)param_1->type != 0x1ffff) {
        iVar15 = piVar23[1];
        iVar4 = param_1->version;
        if (iVar15 == 0x100) {
          iVar15 = 0xff00;
        }
        if (iVar4 == 0x100) {
          iVar4 = 0xff00;
        }
        if (iVar4 < iVar15) {
          iVar4 = 0x18c;
          goto LAB_00102446;
        }
      }
LAB_0010261c:
      iVar4 = SSL_get_options(param_1);
      if (-1 < iVar4 << 0x12) {
LAB_0010264e:
        iVar4 = 0x1ffff;
        if ((*(int *)param_1->type == 0x1ffff) &&
           (iVar4 = ssl_choose_server_version(param_1,piVar23,&local_34), iVar4 != 0)) {
          uVar17 = 0x6be;
          param_1->version = (int)param_1[3].init_buf;
          goto LAB_0010246c;
        }
        goto LAB_00102562;
      }
      p_Var18 = param_1[3].method[1].ssl_free;
      if (p_Var18 == (_func_3197 *)0x0) {
        __s2 = param_1->enc_read_ctx;
        if ((*(size_t *)(__s2[1].final + 8) == piVar23[0x13]) &&
           (iVar4 = memcmp(piVar23 + 0x14,__s2,*(size_t *)(__s2[1].final + 8)), iVar4 == 0))
        goto LAB_00102648;
        uVar17 = 0x6b4;
      }
      else {
        iVar4 = (*p_Var18)(param_1);
        if (iVar4 != 0) {
          __s2 = param_1->enc_read_ctx;
LAB_00102648:
          __s2[1].final[0xc] = '\x01';
          __s2[1].final[0xd] = '\0';
          __s2[1].final[0xe] = '\0';
          __s2[1].final[0xf] = '\0';
          goto LAB_0010264e;
        }
        uVar17 = 0x6aa;
      }
      uVar19 = 0x134;
      goto LAB_00102804;
    }
    iVar4 = ssl_choose_server_version(param_1,piVar23,&local_34);
    if (iVar4 != 0) {
LAB_00102446:
      if ((*(int *)(param_1->mac_flags + 0x180) == 0) || (*(int *)(param_1->mac_flags + 0x204) == 0)
         ) {
        pBVar11 = (BUF_MEM *)piVar23[1];
        param_1[3].init_buf = pBVar11;
        param_1->version = (int)pBVar11;
      }
      uVar17 = 0x696;
LAB_0010246c:
      ossl_statem_fatal(param_1,0x46,0x209,iVar4,"ssl/statem/statem_srvr.c",uVar17);
      goto LAB_00102394;
    }
    if (*(int *)(((int *)param_1->type)[0x19] + 0x30) << 0x1c < 0) goto LAB_0010261c;
    iVar4 = *(int *)param_1->type;
    iVar15 = iVar4 + -0x10000;
    if (iVar15 != 0) {
      iVar15 = 1;
    }
    if (iVar4 < 0x304) {
      iVar15 = 0;
    }
    if (iVar15 != 0) {
      iVar4 = RECORD_LAYER_processed_read_pending(&param_1[3].tlsext_heartbeat);
      if (iVar4 != 0) {
        ossl_statem_fatal(param_1,10,0x209,0xb6,"ssl/statem/statem_srvr.c",0x69e);
        goto LAB_00102394;
      }
      iVar4 = *(int *)(*(int *)(param_1->type + 100) + 0x30);
      if (iVar4 << 0x1c < 0) goto LAB_0010261c;
    }
LAB_00102562:
    iVar15 = 0;
    param_1->enc_write_ctx = (EVP_CIPHER_CTX *)0x0;
    iVar4 = ssl_cache_cipherlist(param_1,piVar23 + 0x54,*piVar23,iVar4);
    if ((iVar4 == 0) ||
       (iVar4 = bytes_to_cipher_list(param_1,piVar23 + 0x54,&local_3c,&local_38,*piVar23,1),
       iVar4 == 0)) goto LAB_00102394;
    *(undefined4 *)(param_1->mac_flags + 0x338) = 0;
    if (local_38 != 0) {
      for (; iVar4 = OPENSSL_sk_num(local_38), iVar15 < iVar4; iVar15 = iVar15 + 1) {
        c = (SSL_CIPHER *)OPENSSL_sk_value(local_38,iVar15);
        uVar6 = SSL_CIPHER_get_id(c);
        if (uVar6 == 0x30000ff) {
          if (param_1[3].tlsext_hostname != (char *)0x0) {
            uVar17 = 0x6d8;
            uVar19 = 0x159;
            goto LAB_00102804;
          }
          *(undefined4 *)(param_1->mac_flags + 0x338) = 1;
        }
        else {
          uVar6 = SSL_CIPHER_get_id(c);
          if ((uVar6 == 0x3005600) && (iVar4 = ssl_check_version_downgrade(param_1), iVar4 == 0)) {
            ossl_statem_fatal(param_1,0x56,0x209,0x175,"ssl/statem/statem_srvr.c",0x6e7);
            goto LAB_00102394;
          }
        }
      }
    }
    iVar4 = local_3c;
    if ((-1 < *(int *)(((int *)param_1->type)[0x19] + 0x30) << 0x1c) &&
       (iVar15 = *(int *)param_1->type, iVar15 != 0x10000 && 0x303 < iVar15)) {
      psVar3 = SSL_get_ciphers(param_1);
      iVar4 = ssl3_choose_cipher(param_1,iVar4,psVar3);
      if (iVar4 == 0) {
        uVar17 = 0x6f5;
        uVar19 = 0xc1;
        goto LAB_00102804;
      }
      if ((param_1[2].tlsext_debug_cb != (_func_3297 *)0x1) ||
         ((iVar15 = *(int *)(param_1->mac_flags + 0x210), iVar15 != 0 &&
          (*(int *)(iVar15 + 0xc) == *(int *)(iVar4 + 0xc))))) {
        *(int *)(param_1->mac_flags + 0x210) = iVar4;
        goto LAB_001026f6;
      }
      uVar19 = 0x701;
      uVar17 = 0xba;
LAB_00102918:
      ossl_statem_fatal(param_1,0x2f,0x209,uVar17,"ssl/statem/statem_srvr.c",uVar19);
      goto LAB_00102394;
    }
LAB_001026f6:
    iVar4 = tls_parse_extension(param_1,0xd,0x80,piVar23[0x9a],0,0);
    if (iVar4 == 0) goto LAB_00102394;
    if ((*piVar23 == 0) &&
       ((param_1->handshake_func == (_func_3291 *)0x0 || (-1 < param_1[3].server << 0xf)))) {
      iVar4 = ssl_get_prev_session(param_1,piVar23);
      if (iVar4 != 1) {
        if (iVar4 == -1) goto LAB_00102394;
        goto LAB_00102734;
      }
      piVar21 = (int *)param_1->type;
      param_1->enc_write_ctx = (EVP_CIPHER_CTX *)0x1;
      if (*(int *)(piVar21[0x19] + 0x30) << 0x1c < 0) goto LAB_00102932;
LAB_0010274e:
      iVar4 = *piVar21;
      if ((0x303 < iVar4) && (iVar4 != 0x10000)) {
        memcpy(&param_1[2].tlsext_opaque_prf_input,(void *)(param_1[3].references + 0x2c),
               *(size_t *)(param_1[3].references + 0x28));
        iVar4 = *(int *)(piVar21[0x19] + 0x30);
        param_1[2].next_proto_negotiated = *(uchar **)(param_1[3].references + 0x28);
        if (iVar4 << 0x1c < 0) goto LAB_00102928;
        iVar4 = *piVar21;
      }
      if ((iVar4 == 0x10000) || (iVar4 < 0x304)) goto LAB_00102928;
    }
    else {
LAB_00102734:
      iVar4 = ssl_get_new_session(param_1,1);
      if (iVar4 == 0) goto LAB_00102394;
      piVar21 = (int *)param_1->type;
      if (-1 < *(int *)(piVar21[0x19] + 0x30) << 0x1c) goto LAB_0010274e;
LAB_00102928:
      if (param_1->enc_write_ctx != (EVP_CIPHER_CTX *)0x0) {
LAB_00102932:
        iVar15 = *(int *)(*(int *)(param_1[2].tlsext_ticket_expected + 0x1b8) + 0xc);
        iVar4 = 0;
        do {
          iVar20 = OPENSSL_sk_num(local_3c);
          if (iVar20 <= iVar4) {
            uVar19 = 0x75a;
            uVar17 = 0xd7;
            goto LAB_00102918;
          }
          iVar20 = OPENSSL_sk_value(local_3c,iVar4);
          iVar4 = iVar4 + 1;
        } while (iVar15 != *(int *)(iVar20 + 0xc));
      }
    }
    if (piVar23[0x56] == 0) {
LAB_001027b8:
      ossl_statem_fatal(param_1,0x32,0x209,0xbb,"ssl/statem/statem_srvr.c",0x768);
      goto LAB_00102394;
    }
    if ((char)piVar23[0x57] != '\0') {
      piVar21 = piVar23 + 0x57;
      do {
        if (piVar21 == (int *)(piVar23[0x56] + 0x15b + (int)piVar23)) goto LAB_001027b8;
        piVar21 = (int *)((int)piVar21 + 1);
      } while (*(char *)piVar21 != '\0');
    }
    if (param_1[3].server << 0x19 < 0) {
      pvVar7 = (void *)piVar23[0x97];
      uVar12 = piVar23[0x98];
      local_28 = pvVar7;
      local_24 = uVar12;
      if (1 < uVar12) {
        local_24 = uVar12 - 2;
        local_28 = (void *)((int)pvVar7 + 2);
        if (1 < local_24) {
          uVar1 = *(undefined1 *)((int)pvVar7 + 2);
          local_24 = uVar12 - 4;
          uVar2 = *(undefined1 *)((int)pvVar7 + 3);
          local_28 = (void *)((int)pvVar7 + 4);
          iVar4 = PACKET_get_length_prefixed_2(&local_28,local_30);
          if ((CONCAT11(uVar1,uVar2) == 0) && (iVar4 != 0)) {
            iVar4 = SSL_client_version(param_1);
            if ((iVar4 >> 8 == 3) && (iVar4 = SSL_client_version(param_1), 0x302 < iVar4)) {
              len = 0x22;
            }
            else {
              len = 0x12;
            }
            iVar4 = param_1->mac_flags;
            if (local_24 == len) {
              iVar15 = CRYPTO_memcmp(local_28,kSafariExtensionsBlock_26964,len);
              uVar2 = (undefined1)iVar15;
            }
            else {
              uVar2 = 0;
            }
            *(undefined1 *)(iVar4 + 0x354) = uVar2;
          }
        }
      }
    }
    iVar4 = tls_parse_all_extensions(param_1,0x80,piVar23[0x9a],0,0,1);
    if (iVar4 == 0) goto LAB_00102394;
    iVar4 = ssl_fill_hello_random(param_1,1,param_1->mac_flags + 0x8c,0x20,local_34);
    if (iVar4 < 1) {
      uVar17 = 0x784;
LAB_00102a22:
      ossl_statem_fatal(param_1,0x50,0x209,0x44,"ssl/statem/statem_srvr.c",uVar17);
LAB_00102394:
      OPENSSL_sk_free(local_3c);
      OPENSSL_sk_free(local_38);
      CRYPTO_free((void *)piVar23[0x9a]);
      CRYPTO_free((void *)param_1[3].references);
      param_1[3].references = 0;
      return (SSL *)0x0;
    }
    if (param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) {
      piVar21 = (int *)param_1->type;
      if ((((0x300 < param_1->version) && (-1 < *(int *)(piVar21[0x19] + 0x30) << 0x1c)) &&
          ((*piVar21 == 0x10000 || (*piVar21 < 0x304)))) &&
         (param_1[3].generate_session_id != (GEN_SESSION_CB)0x0)) {
        local_28 = (void *)0x100;
        local_30[0] = 0;
        iVar15 = (*param_1[3].generate_session_id)
                           (param_1,(uchar *)(param_1[2].tlsext_ticket_expected + 0x48),
                            (uint *)&local_28);
        iVar4 = local_3c;
        if ((iVar15 == 0) || ((int)local_28 < 1)) goto LAB_0010297e;
        iVar15 = param_1[2].tlsext_ticket_expected;
        local_3c = 0;
        *(void **)(iVar15 + 4) = local_28;
        *(int *)(param_1->sid_ctx + 0x18) = iVar4;
        param_1->enc_write_ctx = (EVP_CIPHER_CTX *)0x1;
        *(undefined4 *)(iVar15 + 0x1a4) = 0;
        if (local_30[0] == 0) {
          psVar3 = SSL_get_ciphers(param_1);
          local_30[0] = ssl3_choose_cipher(param_1,iVar4,psVar3);
          if (local_30[0] == 0) {
            uVar17 = 0x7a9;
            uVar19 = 0xc1;
            goto LAB_00102804;
          }
          iVar15 = param_1[2].tlsext_ticket_expected;
        }
        *(int *)(iVar15 + 0x1b8) = local_30[0];
        OPENSSL_sk_free(*(undefined4 *)(param_1->sid_ctx + 0x1c));
        uVar17 = OPENSSL_sk_dup(*(undefined4 *)(param_1->sid_ctx + 0x18));
        *(undefined4 *)(param_1->sid_ctx + 0x1c) = uVar17;
        OPENSSL_sk_free(param_1->session);
        pSVar8 = (SSL_SESSION *)OPENSSL_sk_dup(*(undefined4 *)(param_1->sid_ctx + 0x18));
        piVar21 = (int *)param_1->type;
        param_1->session = pSVar8;
      }
    }
    else {
LAB_0010297e:
      piVar21 = (int *)param_1->type;
    }
    uVar12 = *(uint *)(piVar21[0x19] + 0x30);
    *(undefined4 *)(param_1->mac_flags + 0x240) = 0;
    if ((((uVar12 & 8) == 0) && (*piVar21 != 0x10000)) && (0x303 < *piVar21)) {
      if (piVar23[0x56] != 1) {
        uVar19 = 0x7c4;
        uVar17 = 0x155;
        goto LAB_00102918;
      }
      puVar22 = (uint *)0x0;
LAB_00102128:
      OPENSSL_sk_free(*(undefined4 *)(param_1->sid_ctx + 0x18));
      *(int *)(param_1->sid_ctx + 0x18) = local_3c;
      if (local_3c == 0) {
        uVar17 = 0x81e;
        goto LAB_00102a22;
      }
      local_3c = 0;
      if (param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) {
        uVar12 = 0;
        if (puVar22 != (uint *)0x0) {
          uVar12 = *puVar22;
        }
        *(uint *)(param_1[2].tlsext_ticket_expected + 0x1b4) = uVar12;
        iVar4 = tls1_set_server_sigalgs(param_1);
        if (iVar4 == 0) goto LAB_00102394;
      }
    }
    else {
      uVar12 = *(uint *)(param_1[2].tlsext_ticket_expected + 0x1b4);
      if (uVar12 != 0) {
        iVar4 = ssl_allow_compression(param_1);
        if (iVar4 == 0) {
          uVar17 = 0x7d2;
          uVar19 = 0x154;
        }
        else {
          puVar22 = (uint *)0x0;
          iVar4 = 0;
          do {
            iVar15 = OPENSSL_sk_num(param_1[3].method[1].ssl_renegotiate);
            if (iVar15 <= iVar4) {
              iVar4 = param_1->mac_flags;
              goto LAB_00102bf0;
            }
            puVar22 = (uint *)OPENSSL_sk_value(param_1[3].method[1].ssl_renegotiate,iVar4);
            iVar4 = iVar4 + 1;
          } while (uVar12 != *puVar22);
          iVar4 = param_1->mac_flags;
          *(uint **)(iVar4 + 0x240) = puVar22;
LAB_00102bf0:
          if (*(int *)(iVar4 + 0x240) != 0) {
            pbVar13 = (byte *)((int)piVar23 + 0x15b);
            do {
              if (pbVar13 == (byte *)(piVar23[0x56] + 0x15b + (int)piVar23)) {
                uVar19 = 0x7eb;
                uVar17 = 0x156;
                goto LAB_00102918;
              }
              pbVar13 = pbVar13 + 1;
            } while (uVar12 != *pbVar13);
            goto LAB_00102b44;
          }
          uVar17 = 0x7e0;
          uVar19 = 0x155;
        }
LAB_00102804:
        ossl_statem_fatal(param_1,0x28,0x209,uVar19,"ssl/statem/statem_srvr.c",uVar17);
        goto LAB_00102394;
      }
      if (param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) {
        iVar4 = ssl_allow_compression(param_1);
        if ((iVar4 != 0) && (param_1[3].method[1].ssl_renegotiate != (_func_3204 *)0x0)) {
          iVar15 = OPENSSL_sk_num();
          for (iVar4 = 0; iVar4 < iVar15; iVar4 = iVar4 + 1) {
            puVar22 = (uint *)OPENSSL_sk_value(param_1[3].method[1].ssl_renegotiate,iVar4);
            pbVar13 = (byte *)((int)piVar23 + 0x15b);
            while (pbVar13 != (byte *)(piVar23[0x56] + 0x15b + (int)piVar23)) {
              pbVar13 = pbVar13 + 1;
              if (*puVar22 == (uint)*pbVar13) {
                *(uint **)(param_1->mac_flags + 0x240) = puVar22;
                goto LAB_00102b44;
              }
            }
          }
        }
        puVar22 = (uint *)0x0;
LAB_00102b44:
        if (param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) goto LAB_00102128;
        piVar21 = (int *)param_1->type;
      }
      else {
        puVar22 = (uint *)0x0;
      }
      if (((-1 < *(int *)(piVar21[0x19] + 0x30) << 0x1c) && (0x303 < *piVar21)) &&
         (*piVar21 != 0x10000)) goto LAB_00102128;
    }
    OPENSSL_sk_free(local_3c);
    OPENSSL_sk_free(local_38);
    CRYPTO_free((void *)piVar23[0x9a]);
    ptr = (SSL *)param_1[3].references;
    CRYPTO_free(ptr);
    param_1[3].references = 0;
  }
  else {
    ptr = param_1;
    if (param_2 != 4) {
      if (param_2 != 5) {
        return (SSL *)0x1;
      }
      goto LAB_001022ec;
    }
  }
  if (param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) {
    pcVar14 = *(code **)(param_1[2].error + 0xe0);
    if (pcVar14 != (code *)0x0) {
      ptr = (SSL *)(*pcVar14)(param_1,*(undefined4 *)(param_1[2].error + 0xe4));
      bVar26 = (int)ptr < 0;
      if (ptr == (SSL *)0x0) {
        ossl_statem_fatal(param_1,0x50,0x17a,0x179,"ssl/statem/statem_srvr.c",0x8db);
        return (SSL *)0x0;
      }
      if (bVar26) {
        ptr = (SSL *)&DAT_00000004;
      }
      if (bVar26) {
        param_1->bbio = (BIO *)ptr;
        return ptr;
      }
      param_1->bbio = (BIO *)0x1;
    }
    if ((*(int *)(((int *)param_1->type)[0x19] + 0x30) << 0x1c < 0) ||
       (iVar4 = *(int *)param_1->type, iVar4 == 0x10000 || iVar4 < 0x304)) {
LAB_001021e0:
      uVar17 = *(undefined4 *)(param_1->sid_ctx + 0x18);
      psVar3 = SSL_get_ciphers(param_1);
      ptr = (SSL *)ssl3_choose_cipher(param_1,uVar17,psVar3);
      if (ptr == (SSL *)0x0) {
        ossl_statem_fatal(param_1,0x28,0x17a,0xc1,"ssl/statem/statem_srvr.c",0x8ed);
        return (SSL *)0x0;
      }
      *(SSL **)(param_1->mac_flags + 0x210) = ptr;
    }
    if (param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) {
      ptr = (SSL *)tls_choose_sigalg(param_1,1);
      if (ptr == (SSL *)0x0) {
        return (SSL *)0x0;
      }
      if (param_1[3].srtp_profile != (SRTP_PROTECTION_PROFILE *)0x0) {
        iVar4 = param_1[2].tlsext_ticket_expected;
        ptr = (SSL *)(*(code *)param_1[3].srtp_profile)
                               (param_1,(*(uint *)(*(int *)(param_1->mac_flags + 0x210) + 0x10) & 6)
                                        != 0);
        *(SSL **)(iVar4 + 0x198) = ptr;
      }
      if (*(int *)(param_1[2].tlsext_ticket_expected + 0x198) != 0) {
        param_1[3].compress = (COMP_CTX *)0x0;
      }
    }
  }
  else {
    ptr = (SSL *)(*(int *)(((int *)param_1->type)[0x19] + 0x30) << 0x1c);
    if (-1 < (int)ptr) {
      iVar15 = *(int *)param_1->type;
      iVar4 = iVar15 + -0x10000;
      if (iVar4 != 0) {
        iVar4 = 1;
      }
      if (iVar15 < 0x304) {
        iVar4 = 0;
      }
      if (iVar4 != 0) {
        if (iVar15 == 0x10000) goto LAB_001021e0;
        goto LAB_00102282;
      }
    }
    *(undefined4 *)(param_1->mac_flags + 0x210) =
         *(undefined4 *)(param_1[2].tlsext_ticket_expected + 0x1b8);
  }
LAB_00102282:
  param_1[3].enc_read_ctx = (EVP_CIPHER_CTX *)0x0;
  if ((((param_1[3].cipher_list != (stack_st_SSL_CIPHER *)0xffffffff) &&
       (pSVar16 = param_1[3].method, pSVar16 != (SSL_METHOD *)0x0)) &&
      (p_Var10 = pSVar16[2].ssl_version, p_Var10 != (_func_3219 *)0x0)) &&
     (iVar4 = *(int *)(param_1->mac_flags + 0x264), iVar4 != 0)) {
    p_Var9 = pSVar16[2].ssl_callback_ctrl;
    *(int *)param_1[2].error = iVar4;
    iVar4 = (*p_Var10)(ptr,p_Var9);
    if (iVar4 == 0) {
      if (param_1[3].enc_write_ctx != (EVP_CIPHER_CTX *)0x0) {
        param_1[3].enc_read_ctx = (EVP_CIPHER_CTX *)0x1;
      }
    }
    else {
      if (iVar4 != 3) {
        ossl_statem_fatal(param_1,0x50,0x233,0xe2,"ssl/statem/statem_srvr.c",0x869);
        return (SSL *)0x0;
      }
      param_1[3].enc_read_ctx = (EVP_CIPHER_CTX *)0x0;
    }
  }
  if (((*(int *)(((int *)param_1->type)[0x19] + 0x30) << 0x1c < 0) ||
      (iVar4 = *(int *)param_1->type, iVar4 == 0x10000 || iVar4 < 0x304)) &&
     (iVar4 = tls_handle_alpn(param_1), iVar4 == 0)) {
    return (SSL *)0x0;
  }
LAB_001022ec:
  local_28 = (void *)0x70;
  if ((*(int *)(*(int *)(param_1->mac_flags + 0x210) + 0x10) << 0x1a < 0) &&
     (param_1[3].tlsext_ecpointformatlist_length != 0)) {
    if (param_1[3].tlsext_ellipticcurvelist == (uchar *)0x0) {
      ossl_statem_fatal(param_1,0x73,0x25e,0xdf,"ssl/statem/statem_srvr.c",0x4f2);
      return (SSL *)0x0;
    }
    iVar4 = SSL_srp_server_param_with_username(param_1,&local_28);
    if (iVar4 < 0) {
      param_1->bbio = (BIO *)&DAT_00000004;
      return (SSL *)&DAT_00000005;
    }
    if (iVar4 == 2) {
      if (local_28 == (void *)0x73) {
        uVar17 = 0xdf;
      }
      else {
        uVar17 = 0xe2;
      }
      ossl_statem_fatal(param_1,local_28,0x25e,uVar17,"ssl/statem/statem_srvr.c",0x4fc);
      return (SSL *)0x0;
    }
  }
  return (SSL *)0x1;
}

