
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int do_ssl3_write(SSL *param_1,int param_2,GEN_SESSION_CB param_3,int param_4,SSL_SESSION *param_5,
                 int param_6,int *param_7)

{
  int iVar1;
  EVP_MD *pEVar2;
  uint uVar3;
  EVP_CIPHER *cipher;
  ulong uVar4;
  GEN_SESSION_CB pGVar5;
  uint uVar6;
  uint extraout_r1;
  int *piVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  SSL_SESSION *pSVar12;
  SSL_SESSION *pSVar13;
  EVP_MD_CTX **ppEVar14;
  EVP_CIPHER_CTX *ctx;
  undefined1 *puVar15;
  undefined1 *puVar16;
  uint uVar17;
  BUF_MEM **ppBVar18;
  int iVar19;
  bool bVar20;
  undefined8 uVar21;
  undefined1 local_964;
  SSL_SESSION *local_95c;
  SSL_SESSION *local_958;
  uint local_94c;
  uint local_948;
  int *local_940;
  uint local_938;
  int local_934;
  uint local_930;
  undefined4 local_92c;
  undefined1 auStack_928 [768];
  int local_628 [13];
  undefined1 auStack_5f4 [4];
  undefined1 auStack_5f0 [1484];
  
  local_958 = param_5;
  pSVar12 = (SSL_SESSION *)0x0;
  local_938 = 0;
  if (param_5 == (SSL_SESSION *)0x0) {
    pSVar12 = (SSL_SESSION *)0x0;
  }
  else {
    pSVar13 = pSVar12;
    if ((SSL_SESSION *)&DAT_00000009 <= param_5) {
      iVar19 = 0;
      pSVar12 = (SSL_SESSION *)0x0;
      pSVar13 = (SSL_SESSION *)(((uint)((int)&param_5[-1].tlsext_tick + 3) & 0xfffffff8) + 8);
      iVar1 = param_4 + 0x74;
      do {
        iVar19 = iVar19 + 8;
        HintPreloadData(iVar1);
        pSVar12 = (SSL_SESSION *)
                  (pSVar12->key_arg +
                  *(int *)(iVar1 + -0x58) +
                  *(int *)(iVar1 + -0x60) +
                  *(int *)(iVar1 + -100) +
                  *(int *)(iVar1 + -0x68) +
                  *(int *)(iVar1 + -0x74) + *(int *)(iVar1 + -0x70) + *(int *)(iVar1 + -0x6c) +
                  *(int *)(iVar1 + -0x5c) + -8);
        iVar1 = iVar1 + 0x20;
      } while ((SSL_SESSION *)iVar19 != pSVar13);
    }
    piVar7 = (int *)(param_4 + (int)pSVar13 * 4);
    do {
      pSVar13 = (SSL_SESSION *)((int)&pSVar13->ssl_version + 1);
      pSVar12 = (SSL_SESSION *)(pSVar12->key_arg + *piVar7 + -8);
      piVar7 = piVar7 + 1;
    } while (pSVar13 < param_5);
  }
  iVar1 = RECORD_LAYER_write_pending(&param_1[3].tlsext_heartbeat);
  if (iVar1 != 0) {
    iVar1 = ssl3_write_pending(param_1,param_2,param_3,pSVar12,param_7);
    return iVar1;
  }
  if ((*(int *)(param_1->mac_flags + 0xe8) != 0) &&
     (iVar1 = (**(code **)(param_1->type + 0x40))(param_1), iVar1 < 1)) {
    return iVar1;
  }
  if (((SSL_SESSION *)param_1[4].version < param_5) &&
     (iVar1 = ssl3_setup_write_buffer(param_1,param_5,0), iVar1 == 0)) {
    return -1;
  }
  if (pSVar12 == (SSL_SESSION *)0x0 && param_6 == 0) {
    return 0;
  }
  bVar20 = false;
  if (param_1[2].tlsext_ticket_expected == 0) {
LAB_000df44a:
    iVar1 = *(int *)(param_1[2].sid_ctx + 0x1c);
LAB_000df44e:
    bVar20 = iVar1 == 0;
    local_94c = 0;
  }
  else {
    iVar1 = *(int *)(param_1[2].sid_ctx + 0x1c);
    if (iVar1 == 0) goto LAB_000df44e;
    pEVar2 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[2].info_callback);
    if (pEVar2 == (EVP_MD *)0x0) goto LAB_000df44a;
    pEVar2 = EVP_MD_CTX_md((EVP_MD_CTX *)param_1[2].info_callback);
    local_94c = EVP_MD_size(pEVar2);
    if ((int)local_94c < 0) {
      uVar9 = 0x2d4;
      goto LAB_000df58e;
    }
  }
  if (param_6 != 0 || bVar20) {
    if (param_6 == 0) goto LAB_000df48e;
    uVar10 = 6U - param_1[4].rwstate & 7;
    param_1[4].server = uVar10;
    iVar1 = WPACKET_init_static_len(auStack_928,param_1[4].rwstate,param_1[4].handshake_func,0);
    if ((iVar1 == 0) || (iVar1 = WPACKET_allocate_bytes(auStack_928,uVar10,0), iVar1 == 0)) {
      uVar9 = 0x30e;
      goto LAB_000df58e;
    }
LAB_000df5f2:
    ctx = *(EVP_CIPHER_CTX **)(param_1[2].sid_ctx + 0x1c);
    if (ctx == (EVP_CIPHER_CTX *)0x0) {
      pSVar12 = (SSL_SESSION *)0x1;
      local_948 = 0;
    }
    else {
      piVar7 = (int *)param_1->type;
      uVar10 = *(uint *)(piVar7[0x19] + 0x30);
      if ((uVar10 & 1) == 0) {
        pSVar12 = (SSL_SESSION *)0x1;
        local_948 = 0;
      }
      else {
        pSVar12 = (SSL_SESSION *)0x1;
LAB_000df60e:
        if (-1 < (int)(uVar10 << 0x1c)) {
          local_948 = (uint)(*piVar7 == 0x10000);
          if (*piVar7 < 0x304) {
            local_948 = 1;
          }
          if (local_948 == 0) goto LAB_000df632;
        }
        if (((int)param_1->msg_callback_arg - 1U < 4) ||
           (param_1[2].tlsext_debug_cb == (_func_3297 *)0x1)) {
          local_948 = 0;
        }
        else {
          cipher = EVP_CIPHER_CTX_cipher(ctx);
          uVar4 = EVP_CIPHER_flags(cipher);
          if ((uVar4 & 0xf0007) == 2) {
            local_948 = EVP_CIPHER_CTX_iv_length(*(EVP_CIPHER_CTX **)(param_1[2].sid_ctx + 0x1c));
            if ((int)local_948 < 2) {
              local_948 = 0;
            }
          }
          else if ((uVar4 & 0xf0007) - 6 < 2) {
            local_948 = 8;
          }
          else {
            local_948 = 0;
          }
        }
      }
    }
LAB_000df632:
    memset(local_628,0,0x600);
    if (param_5 != (SSL_SESSION *)0x0) {
LAB_000df690:
      piVar7 = (int *)(param_4 + -4);
      local_95c = (SSL_SESSION *)0x0;
      local_958 = (SSL_SESSION *)0x0;
      puVar15 = auStack_928;
      puVar16 = auStack_5f0;
      do {
        local_930 = 0;
        iVar1 = param_1->version;
        if (iVar1 == 0x304) {
          iVar1 = 0x303;
        }
        iVar19 = param_2;
        if (*(int *)(((int *)param_1->type)[0x19] + 0x30) << 0x1c < 0) {
LAB_000dfab0:
          if (((int)param_1->msg_callback_arg - 1U < 4) ||
             (param_1[2].tlsext_debug_cb == (_func_3297 *)0x1)) goto LAB_000df6e2;
        }
        else {
          iVar8 = *(int *)param_1->type;
          bVar20 = SBORROW4(iVar8,0x10000);
          iVar11 = iVar8 + -0x10000;
          if (iVar8 != 0x10000) {
            bVar20 = SBORROW4(iVar8,0x303);
            iVar11 = iVar8 + -0x303;
          }
          if ((iVar8 == 0x10000 || iVar8 == 0x303) || iVar11 < 0 != bVar20) goto LAB_000dfab0;
LAB_000df6e2:
          if ((*(int *)(param_1[2].sid_ctx + 0x1c) != 0) &&
             (param_2 != 0x15 || param_1->read_ahead != 2)) {
            iVar19 = 0x17;
          }
        }
        *(int *)(puVar16 + -0x34) = iVar19;
        HintPreloadData(puVar16 + -4);
        iVar19 = SSL_get_state(param_1);
        if ((((iVar19 == 0xc) && (param_1[3].tlsext_hostname == (char *)0x0)) &&
            (iVar19 = SSL_version(param_1), iVar19 >> 8 == 3)) &&
           ((iVar19 = SSL_version(param_1), 0x301 < iVar19 &&
            (param_1[2].tlsext_debug_cb == (_func_3297 *)0x0)))) {
          iVar1 = 0x301;
        }
        iVar19 = *(int *)(param_1[2].sid_ctx + 0x14);
        *(int *)(puVar16 + -0x38) = iVar1;
        HintPreloadData(puVar16 + -8);
        piVar7 = piVar7 + 1;
        iVar11 = *piVar7;
        if (iVar19 != 0) {
          iVar11 = iVar11 + 0x400;
        }
        uVar21 = WPACKET_put_bytes__(puVar15);
        if (((((int)uVar21 == 0) ||
             (iVar1 = WPACKET_put_bytes__(puVar15,(int)((ulonglong)uVar21 >> 0x20),iVar1,0,2),
             iVar1 == 0)) ||
            ((iVar1 = WPACKET_start_sub_packet_len__(puVar15,2), iVar1 == 0 ||
             ((local_948 != 0 && (iVar1 = WPACKET_allocate_bytes(puVar15,local_948,0), iVar1 == 0)))
             ))) || ((iVar11 != 0 &&
                     (iVar1 = WPACKET_reserve_bytes(puVar15,iVar11,&local_930), iVar1 == 0)))) {
          uVar9 = 0x376;
          goto LAB_000df4f2;
        }
        iVar1 = *piVar7;
        iVar19 = *(int *)(param_1[2].sid_ctx + 0x14);
        *(uint *)(puVar16 + -0x24) = local_930;
        pGVar5 = param_3 + (int)local_958;
        local_958 = (SSL_SESSION *)(local_958->key_arg + iVar1 + -8);
        *(GEN_SESSION_CB *)(puVar16 + -0x20) = pGVar5;
        *(int *)(puVar16 + -0x30) = iVar1;
        if (iVar19 != 0) {
          iVar1 = ssl3_do_compress(param_1,puVar16 + -0x38);
          if (iVar1 != 0) {
            HintPreloadData(puVar16);
            iVar1 = WPACKET_allocate_bytes(puVar15,*(undefined4 *)(puVar16 + -0x30),0);
            if (iVar1 != 0) goto LAB_000df7cc;
          }
          ossl_statem_fatal(param_1,0x50,0x68,0x8d,"ssl/record/rec_layer_s3.c",0x38a);
          goto LAB_000df502;
        }
        iVar1 = WPACKET_memcpy(puVar15);
        if (iVar1 == 0) {
          uVar9 = 0x390;
          goto LAB_000df4f2;
        }
        HintPreloadData(puVar16 + 0xc);
        *(undefined4 *)(puVar16 + -0x20) = *(undefined4 *)(puVar16 + -0x24);
LAB_000df7cc:
        if (((((-1 < *(int *)(((int *)param_1->type)[0x19] + 0x30) << 0x1c) &&
              (iVar1 = *(int *)param_1->type, iVar1 != 0x10000 && 0x303 < iVar1)) ||
             ((int)param_1->msg_callback_arg - 1U < 4)) ||
            (param_1[2].tlsext_debug_cb == (_func_3297 *)0x1)) &&
           ((*(int *)(param_1[2].sid_ctx + 0x1c) != 0 &&
            (param_2 != 0x15 || param_1->read_ahead != 2)))) {
          iVar1 = WPACKET_put_bytes__(puVar15,1,param_2,param_2 >> 0x1f,1);
          if (iVar1 == 0) {
            uVar9 = 0x39e;
            goto LAB_000df4f2;
          }
          *(int *)(puVar16 + -0x30) = *(int *)(puVar16 + -0x30) + 1;
          uVar10 = ssl_get_max_send_fragment(param_1);
          uVar17 = *(uint *)(puVar16 + -0x30);
          if (uVar17 < uVar10) {
            if ((code *)param_1[9].options == (code *)0x0) {
              uVar3 = param_1[9].max_cert_list;
              if (uVar3 != 0) {
                if ((uVar3 & uVar3 - 1) == 0) {
                  uVar6 = uVar17 & uVar3 - 1;
                }
                else {
                  __aeabi_uidivmod(uVar17,uVar3);
                  uVar6 = extraout_r1;
                }
                if (uVar6 != 0) {
                  uVar3 = uVar3 - uVar6;
                  goto LAB_000df850;
                }
              }
            }
            else {
              uVar3 = (*(code *)param_1[9].options)(param_1,param_2,uVar17,param_1[9].mode);
LAB_000df850:
              if (uVar3 != 0) {
                uVar6 = uVar10 - uVar17;
                if (uVar3 <= uVar10 - uVar17) {
                  uVar6 = uVar3;
                }
                iVar1 = WPACKET_memset(puVar15,0,uVar6);
                if (iVar1 == 0) {
                  uVar9 = 0x3c0;
                  goto LAB_000df4f2;
                }
                *(uint *)(puVar16 + -0x30) = uVar6 + *(int *)(puVar16 + -0x30);
              }
            }
          }
        }
        uVar10 = local_94c;
        if (local_94c != 0) {
          uVar10 = 1;
        }
        if (((uVar10 & (*(uint *)param_1->mac_flags ^ 0x400) >> 10) != 0) &&
           ((iVar1 = WPACKET_allocate_bytes(puVar15,local_94c,&local_92c), iVar1 == 0 ||
            (iVar1 = (**(code **)(*(int *)(param_1->type + 100) + 4))
                               (param_1,puVar16 + -0x38,local_92c,1), iVar1 == 0)))) {
          uVar9 = 0x3d4;
          goto LAB_000df4f2;
        }
        iVar1 = WPACKET_reserve_bytes(puVar15,0x10,0);
        if ((iVar1 == 0) || (iVar1 = WPACKET_get_length(puVar15,&local_934), iVar1 == 0)) {
          uVar9 = 0x3e6;
          goto LAB_000df4f2;
        }
        local_95c = (SSL_SESSION *)((int)&local_95c->ssl_version + 1);
        iVar1 = WPACKET_get_curr(puVar15);
        *(int *)(puVar16 + -0x30) = local_934;
        *(int *)(puVar16 + -0x24) = iVar1 - local_934;
        *(int *)(puVar16 + -0x20) = iVar1 - local_934;
        puVar15 = puVar15 + 0x18;
        puVar16 = puVar16 + 0x30;
      } while (local_95c < param_5);
    }
  }
  else {
    iVar1 = param_1->mac_flags;
    if (*(int *)(iVar1 + 0xd0) == 0) {
      iVar19 = *(int *)(iVar1 + 0xcc);
      if (iVar19 != 0) {
        iVar19 = 1;
      }
      if (param_2 != 0x17) {
        iVar19 = 0;
      }
      if (iVar19 != 0) {
        local_628[0] = *(int *)(iVar1 + 0xd0);
        iVar1 = do_ssl3_write(param_1,0x17,param_3,local_628,1,1,&local_938);
        if (iVar1 < 1) {
          return -1;
        }
        if (0x55 < local_938) {
          uVar9 = 0x2f6;
          goto LAB_000df58e;
        }
        iVar1 = param_1->mac_flags;
      }
      *(undefined4 *)(iVar1 + 0xd0) = 1;
    }
LAB_000df48e:
    if (local_938 != 0) {
      iVar1 = WPACKET_init_static_len(auStack_928,param_1[4].rwstate,param_1[4].handshake_func,0);
      if ((iVar1 == 0) ||
         (iVar1 = WPACKET_allocate_bytes(auStack_928,param_1[4].server + local_938,0), iVar1 == 0))
      {
        uVar9 = 0x31a;
LAB_000df58e:
        ossl_statem_fatal(param_1,0x50,0x68,0x44,"ssl/record/rec_layer_s3.c",uVar9);
        return -1;
      }
      goto LAB_000df5f2;
    }
    pSVar12 = param_5;
    if (param_5 != (SSL_SESSION *)0x0) {
      pSVar12 = (SSL_SESSION *)0x0;
      ppEVar14 = (EVP_MD_CTX **)&param_1[4].mac_flags;
      puVar15 = auStack_928;
      do {
        HintPreloadData(ppEVar14);
        uVar10 = 3U - (int)ppEVar14[-0x19] & 7;
        ppEVar14[-0x16] = (EVP_MD_CTX *)uVar10;
        iVar1 = WPACKET_init_static_len(puVar15,ppEVar14[-0x19],ppEVar14[-0x17],0);
        if (iVar1 == 0) {
LAB_000df4e8:
          uVar9 = 0x32c;
          goto LAB_000df4f2;
        }
        iVar1 = WPACKET_allocate_bytes(puVar15,uVar10,0);
        if (iVar1 == 0) goto LAB_000df4e8;
        pSVar12 = (SSL_SESSION *)((int)&pSVar12->ssl_version + 1);
        ppEVar14 = ppEVar14 + 5;
        puVar15 = puVar15 + 0x18;
      } while (param_5 != pSVar12);
      ctx = *(EVP_CIPHER_CTX **)(param_1[2].sid_ctx + 0x1c);
      if (ctx == (EVP_CIPHER_CTX *)0x0) {
        memset(local_628,0,0x600);
        local_948 = 0;
        pSVar12 = param_5;
      }
      else {
        piVar7 = (int *)param_1->type;
        uVar10 = *(uint *)(piVar7[0x19] + 0x30);
        pSVar12 = param_5;
        if ((uVar10 & 1) != 0) goto LAB_000df60e;
        memset(local_628,0,0x600);
        local_948 = 0;
      }
      goto LAB_000df690;
    }
    ctx = *(EVP_CIPHER_CTX **)(param_1[2].sid_ctx + 0x1c);
    if (ctx != (EVP_CIPHER_CTX *)0x0) {
      piVar7 = (int *)param_1->type;
      uVar10 = *(uint *)(piVar7[0x19] + 0x30);
      if (-1 < (int)(uVar10 << 0x1f)) goto LAB_000dfca8;
      goto LAB_000df60e;
    }
LAB_000dfca8:
    memset(local_628,0,0x600);
  }
  local_940 = local_628;
  if (param_1->read_ahead == 2) {
    iVar1 = tls13_enc(param_1,local_940,param_5,1);
    if (0 < iVar1) goto LAB_000df900;
    iVar1 = ossl_statem_in_error(param_1);
    if (iVar1 != 0) goto LAB_000df502;
    uVar9 = 0x3fa;
  }
  else {
    iVar1 = (*(code *)**(undefined4 **)(param_1->type + 100))(param_1,local_940,param_5,1);
    if (0 < iVar1) {
LAB_000df900:
      if (param_5 != (SSL_SESSION *)0x0) {
        puVar16 = auStack_928;
        puVar15 = auStack_5f4;
        pSVar13 = (SSL_SESSION *)0x0;
        ppBVar18 = &param_1[4].init_buf;
        do {
          iVar1 = WPACKET_get_length(puVar16,&local_930);
          if (iVar1 == 0) {
LAB_000dfbe8:
            uVar9 = 0x416;
            goto LAB_000df4f2;
          }
          uVar10 = *(uint *)(puVar15 + -0x2c);
          HintPreloadData(puVar15 + 4);
          if ((uVar10 < local_930) ||
             ((local_930 < uVar10 &&
              (iVar1 = WPACKET_allocate_bytes(puVar16,uVar10 - local_930,0), iVar1 == 0))))
          goto LAB_000dfbe8;
          uVar10 = local_94c;
          if (local_94c != 0) {
            uVar10 = 1;
          }
          if ((uVar10 & *(uint *)param_1->mac_flags >> 10) != 0) {
            iVar1 = WPACKET_allocate_bytes(puVar16,local_94c,&local_92c);
            if ((iVar1 == 0) ||
               (iVar1 = (**(code **)(*(int *)(param_1->type + 100) + 4))
                                  (param_1,puVar15 + -0x34,local_92c,1), iVar1 == 0)) {
              uVar9 = 0x41f;
              goto LAB_000df4f2;
            }
            *(uint *)(puVar15 + -0x2c) = *(int *)(puVar15 + -0x2c) + local_94c;
          }
          iVar1 = WPACKET_get_length(puVar16,&local_934);
          if ((iVar1 == 0) || (iVar1 = WPACKET_close(puVar16), iVar1 == 0)) {
            uVar9 = 0x428;
            goto LAB_000df4f2;
          }
          if (param_1->read_hash != (EVP_MD_CTX *)0x0) {
            iVar1 = WPACKET_get_curr(puVar16);
            (*(code *)param_1->read_hash)
                      (1,0,0x100,(iVar1 - local_934) + -5,5,param_1,param_1->expand);
            if (((((-1 < *(int *)(((int *)param_1->type)[0x19] + 0x30) << 0x1c) &&
                  (iVar1 = *(int *)param_1->type, iVar1 != 0x10000 && 0x303 < iVar1)) ||
                 ((int)param_1->msg_callback_arg - 1U < 4)) ||
                (param_1[2].tlsext_debug_cb == (_func_3297 *)0x1)) &&
               (*(int *)(param_1[2].sid_ctx + 0x1c) != 0)) {
              local_964 = (undefined1)param_2;
                    /* WARNING: Ignoring partial resolution of indirect */
              local_92c._0_1_ = local_964;
              (*(code *)param_1->read_hash)
                        (1,param_1->version,0x101,&local_92c,1,param_1,param_1->expand);
            }
          }
          iVar1 = WPACKET_finish(puVar16);
          if (iVar1 == 0) {
            uVar9 = 0x43d;
            goto LAB_000df4f2;
          }
          HintPreloadData(puVar15);
          *(int *)(puVar15 + -0x30) = param_2;
          iVar1 = *(int *)(puVar15 + -0x2c) + 5;
          *(int *)(puVar15 + -0x2c) = iVar1;
          if (param_6 != 0) {
            if (pSVar13 == (SSL_SESSION *)0x0) {
              *param_7 = iVar1;
              return 1;
            }
            uVar9 = 0x451;
            goto LAB_000df4f2;
          }
          pSVar13 = (SSL_SESSION *)((int)&pSVar13->ssl_version + 1);
          HintPreloadData(ppBVar18);
          puVar16 = puVar16 + 0x18;
          puVar15 = puVar15 + 0x30;
          ppBVar18[-5] = (BUF_MEM *)(iVar1 + local_938);
          ppBVar18 = ppBVar18 + 5;
        } while (param_5 != pSVar13);
      }
      *(SSL_SESSION **)(param_1[9].sid_ctx + 0x18) = local_958;
      param_1[9].session = local_958;
      param_1[9].generate_session_id = param_3;
      *(int *)(param_1[9].sid_ctx + 0x1c) = param_2;
      iVar1 = ssl3_write_pending(param_1,param_2,param_3,local_958,param_7);
      return iVar1;
    }
    iVar1 = ossl_statem_in_error(param_1);
    if (iVar1 != 0) goto LAB_000df502;
    uVar9 = 0x402;
  }
LAB_000df4f2:
  ossl_statem_fatal(param_1,0x50,0x68,0x44,"ssl/record/rec_layer_s3.c",uVar9);
LAB_000df502:
  if (pSVar12 != (SSL_SESSION *)0x0) {
    iVar1 = 0;
    do {
      puVar15 = auStack_928 + iVar1;
      iVar1 = iVar1 + 0x18;
      WPACKET_cleanup(puVar15);
    } while (iVar1 != (int)pSVar12 * 0x18);
  }
  return -1;
}

