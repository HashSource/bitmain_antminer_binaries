
/* WARNING: Type propagation algorithm not settling */

int dtls1_read_bytes(SSL *param_1,ulong param_2,ulong *param_3,void *param_4,uint param_5,
                    int param_6,size_t *param_7)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  pitem *item;
  BIO *pBVar4;
  ulong uVar5;
  SSL_CTX *pSVar6;
  ulong uVar7;
  SSL_SESSION *c;
  uint uVar8;
  int *piVar9;
  int *piVar10;
  KSSL_CTX *pKVar11;
  SRTP_PROTECTION_PROFILE *pSVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  int *piVar15;
  SSL_METHOD *pSVar16;
  BIO *pBVar17;
  int *piVar18;
  SRTP_PROTECTION_PROFILE *local_64;
  char local_54 [48];
  
  if ((param_1[4].type == 0) && (iVar3 = ssl3_setup_buffers(), iVar3 == 0)) {
    return -1;
  }
  uVar8 = param_2 - 0x17;
  if (uVar8 != 0) {
    uVar8 = 1;
  }
  if (param_2 == 0x16 || (param_2 == 0 || param_2 == 0x17)) {
    if (param_6 == 0) {
      uVar8 = 0;
    }
    else {
      uVar8 = uVar8 & 1;
    }
    if (uVar8 == 0) {
      iVar3 = ossl_statem_get_in_handshake(param_1);
      if ((iVar3 == 0) && (iVar3 = SSL_in_init(param_1), iVar3 != 0)) {
        iVar3 = (*(code *)param_1->rwstate)(param_1);
        if (iVar3 < 0) {
          return iVar3;
        }
        if (iVar3 == 0) {
          return -1;
        }
      }
      local_64 = (SRTP_PROTECTION_PROFILE *)0x0;
LAB_000d46f8:
      do {
        do {
          while( true ) {
            param_1->bbio = (BIO *)0x1;
            iVar3 = SSL_is_init_finished(param_1);
            if (((iVar3 == 0) || (param_1[5].mode != 0)) ||
               (item = pqueue_pop(*(pqueue *)(param_1[9].psk_client_callback + 0x30)),
               item == (pitem *)0x0)) break;
            piVar15 = (int *)item->data;
            SSL3_BUFFER_release(&param_1[4].type);
            iVar3 = piVar15[1];
            *(int *)param_1[9].sid_ctx = *piVar15;
            *(int *)(param_1[9].sid_ctx + 4) = iVar3;
            pSVar16 = (SSL_METHOD *)piVar15[3];
            pBVar17 = (BIO *)piVar15[4];
            pBVar4 = (BIO *)piVar15[5];
            param_1[4].type = piVar15[2];
            param_1[4].method = pSVar16;
            param_1[4].rbio = pBVar17;
            param_1[4].wbio = pBVar4;
            param_1[4].bbio = (BIO *)piVar15[6];
            piVar9 = piVar15 + 7;
            piVar18 = &param_1[5].references;
            do {
              piVar10 = piVar9 + 4;
              uVar5 = piVar9[1];
              uVar7 = piVar9[2];
              iVar3 = piVar9[3];
              *piVar18 = *piVar9;
              piVar18[1] = uVar5;
              piVar18[2] = uVar7;
              piVar18[3] = iVar3;
              piVar9 = piVar10;
              piVar18 = piVar18 + 4;
            } while (piVar10 != piVar15 + 0x13);
            iVar3 = *piVar15;
            *(undefined4 *)((int)&param_1[9].verify_mode + 2) = *(undefined4 *)(iVar3 + 5);
            *(undefined2 *)((int)&param_1[9].verify_callback + 2) = *(undefined2 *)(iVar3 + 9);
            CRYPTO_free(item->data);
            pitem_free(item);
            iVar3 = dtls1_handle_timeout(param_1);
            if (iVar3 < 1) goto LAB_000d47ca;
          }
          iVar3 = dtls1_handle_timeout(param_1);
        } while (0 < iVar3);
LAB_000d47ca:
        iVar3 = ossl_statem_in_error(param_1);
        if (iVar3 != 0) {
          return -1;
        }
        if ((param_1[5].mode == 0) || (param_1[3].tlsext_hb_seq == 0xf1)) {
          param_1[3].renegotiate = 0;
          iVar3 = dtls1_get_record(param_1);
          if (iVar3 < 1) {
            iVar3 = dtls1_read_failed(param_1);
            if (iVar3 < 1) {
              return iVar3;
            }
            goto LAB_000d46f8;
          }
          uVar5 = param_1[5].options;
          param_1[3].renegotiate = 1;
          if ((uVar5 != 0x15) && (param_1[5].mode != 0)) {
LAB_000d47ee:
            param_1[9].kssl_ctx = (KSSL_CTX *)0x0;
          }
        }
        else {
          uVar5 = param_1[5].options;
          if (uVar5 != 0x15) goto LAB_000d47ee;
        }
        if (*(int *)(param_1->mac_flags + 0xdc) == 0 || uVar5 == 0x16) {
          uVar8 = param_1->new_session;
          if ((uVar8 & 2) != 0) {
            param_1[5].mode = 0;
            param_1[5].tlsext_debug_arg = (void *)0x1;
            param_1->bbio = (BIO *)0x1;
            return 0;
          }
          if (param_2 == uVar5) {
LAB_000d4a32:
            iVar3 = SSL_in_init(param_1);
            if ((iVar3 == 0 || param_2 != 0x17) || (param_1[2].sid_ctx_length != 0)) {
              if (param_3 != (ulong *)0x0) {
                *param_3 = param_1[5].options;
              }
              if (param_5 != 0) {
                uVar8 = param_1[5].mode;
                if (param_5 <= param_1[5].mode) {
                  uVar8 = param_5;
                }
                memcpy(param_4,(void *)(param_1[5].client_version + param_1[5].first_packet),uVar8);
                if (param_6 == 0) {
                  uVar5 = param_1[5].mode - uVar8;
                  param_1[5].mode = uVar5;
                  param_1[5].first_packet = param_1[5].first_packet + uVar8;
                  if (uVar5 == 0) {
                    param_1[3].tlsext_hb_seq = 0xf0;
                    param_1[5].tlsext_debug_arg = (void *)0x1;
                    param_1[5].first_packet = 0;
                  }
                }
                else if (param_1[5].mode == 0) {
                  param_1[5].tlsext_debug_arg = (void *)0x1;
                }
                *param_7 = uVar8;
                return 1;
              }
              if (param_1[5].mode == 0) {
                param_1[5].tlsext_debug_arg = (void *)0x1;
                return 0;
              }
              return 0;
            }
            uVar13 = 0x1ec;
            uVar14 = 100;
LAB_000d493e:
            ossl_statem_fatal(param_1,10,0x102,uVar14,"ssl/record/rec_layer_d1.c",uVar13);
            return -1;
          }
          if (uVar5 == 0x14) {
            if (param_3 != (ulong *)0x0 && param_2 == 0x16) goto LAB_000d4a32;
            if ((int)(uVar8 << 0x1f) < 0) {
LAB_000d4b40:
              param_1->bbio = (BIO *)0x1;
              param_1[5].tlsext_debug_arg = (void *)0x1;
              param_1[5].mode = 0;
              return 0;
            }
            param_1[5].mode = 0;
            param_1[5].tlsext_debug_arg = (void *)0x1;
          }
          else {
            if (uVar5 != 0x15) {
              if ((int)(uVar8 << 0x1f) < 0) goto LAB_000d4b40;
              if (uVar5 == 0x16) {
                iVar3 = ossl_statem_get_in_handshake(param_1);
                if (iVar3 == 0) {
                  if ((param_1[5].tlsext_hostname !=
                       (char *)(uint)*(ushort *)param_1[9].psk_client_callback) ||
                     (param_1[5].mode < 0xc)) goto LAB_000d481e;
                  dtls1_get_message_header(param_1[5].client_version,local_54);
                  if (local_54[0] == '\x14') {
                    iVar3 = dtls1_check_timeout_num(param_1);
                    if (iVar3 < 0) {
                      return -1;
                    }
                    iVar3 = dtls1_retransmit_buffered_messages(param_1);
                    if ((iVar3 < 1) && (iVar3 = ossl_statem_in_error(param_1), iVar3 != 0)) {
                      return -1;
                    }
                    iVar3 = param_1[3].new_session;
                    param_1[5].tlsext_debug_arg = (void *)0x1;
                    param_1[5].mode = 0;
                  }
                  else {
                    iVar3 = SSL_is_init_finished();
                    if (iVar3 == 0) {
                      uVar14 = 0x2c5;
                      goto LAB_000d4a7a;
                    }
                    ossl_statem_set_in_init(param_1,1);
                    iVar3 = (*(code *)param_1->rwstate)(param_1);
                    if (iVar3 < 0) {
                      return iVar3;
                    }
                    if (iVar3 == 0) {
                      return -1;
                    }
                    iVar3 = param_1[3].new_session;
                  }
                  if ((-1 < iVar3 << 0x1d) && (param_1[4].bbio == (BIO *)0x0)) {
                    param_1->bbio = (BIO *)0x3;
                    pBVar4 = SSL_get_rbio(param_1);
                    BIO_clear_flags(pBVar4,0xf);
                    BIO_set_flags(pBVar4,9);
                    return -1;
                  }
                  goto LAB_000d46f8;
                }
                uVar5 = param_1[5].options;
              }
              if ((int)uVar5 < 0x14) {
LAB_000d4b6c:
                uVar13 = 0x2ea;
              }
              else {
                if ((int)uVar5 < 0x17) {
                  uVar13 = 0x2f5;
                  uVar14 = 0x44;
                  goto LAB_000d493e;
                }
                if (uVar5 != 0x17) goto LAB_000d4b6c;
                if (((*(int *)(param_1->mac_flags + 0xfc) != 0) &&
                    (*(int *)(param_1->mac_flags + 0xf4) != 0)) &&
                   (iVar3 = ossl_statem_app_data_allowed(param_1), iVar3 != 0)) {
                  *(undefined4 *)(param_1->mac_flags + 0xfc) = 2;
                  return -1;
                }
                uVar13 = 0x306;
              }
              uVar14 = 0xf5;
              goto LAB_000d493e;
            }
            uVar5 = param_1[5].mode;
            iVar3 = param_1[5].client_version + param_1[5].first_packet;
            if (((int)uVar5 < 1) ||
               (cVar1 = *(char *)(param_1[5].client_version + param_1[5].first_packet), uVar5 == 1))
            {
LAB_000d4930:
              uVar13 = 0x231;
              uVar14 = 0xcd;
              goto LAB_000d493e;
            }
            bVar2 = *(byte *)(iVar3 + 1);
            uVar8 = (uint)bVar2;
            if (uVar5 != 2) goto LAB_000d4930;
            if (param_1->read_hash != (EVP_MD_CTX *)0x0) {
              (*(code *)param_1->read_hash)(0,param_1->version,0x15,iVar3,2,param_1,param_1->expand)
              ;
            }
            pSVar12 = param_1[2].srtp_profile;
            if (((param_1[2].srtp_profile != (SRTP_PROTECTION_PROFILE *)0x0) ||
                (pSVar12 = (SRTP_PROTECTION_PROFILE *)param_1[3].method[1].ssl_renegotiate_check,
                pSVar12 != (SRTP_PROTECTION_PROFILE *)0x0)) ||
               (pSVar12 = local_64, local_64 != (SRTP_PROTECTION_PROFILE *)0x0)) {
              (*(code *)pSVar12)(param_1,0x4004,CONCAT11(cVar1,bVar2));
              local_64 = pSVar12;
            }
            if (cVar1 != '\x01') {
              if (cVar1 == '\x02') {
                param_1->bbio = (BIO *)0x1;
                *(uint *)(param_1->mac_flags + 0xe4) = uVar8;
                ossl_statem_fatal(param_1,0xffffffff,0x102,uVar8 + 1000,"ssl/record/rec_layer_d1.c",
                                  0x267);
                BIO_snprintf(local_54,0x10,"%d",uVar8);
                ERR_add_error_data(2,"SSL alert number ",local_54);
                uVar8 = param_1->new_session;
                param_1[5].tlsext_debug_arg = (void *)0x1;
                c = (SSL_SESSION *)param_1[2].tlsext_ticket_expected;
                pSVar6 = (SSL_CTX *)param_1[3].max_send_fragment;
                param_1->new_session = uVar8 | 2;
                SSL_CTX_remove_session(pSVar6,c);
                return 0;
              }
              ossl_statem_fatal(param_1,0x2f,0x102,0xf6,"ssl/record/rec_layer_d1.c",0x270);
              return -1;
            }
            pKVar11 = (KSSL_CTX *)((int)&(param_1[9].kssl_ctx)->service_name + 1);
            *(uint *)(param_1->mac_flags + 0xe0) = uVar8;
            param_1[9].kssl_ctx = pKVar11;
            param_1[5].tlsext_debug_arg = (void *)0x1;
            if (pKVar11 == (KSSL_CTX *)&DAT_00000005) {
              uVar13 = 0x24a;
              uVar14 = 0x199;
              goto LAB_000d493e;
            }
            if (uVar8 == 0) {
              param_1->new_session = param_1->new_session | 2;
              return 0;
            }
          }
          goto LAB_000d46f8;
        }
        iVar3 = dtls1_buffer_record(param_1,param_1[9].psk_client_callback + 0x2c,
                                    &param_1[5].servername_done);
        if (iVar3 < 0) {
          return -1;
        }
LAB_000d481e:
        param_1[5].tlsext_debug_arg = (void *)0x1;
        param_1[5].mode = 0;
      } while( true );
    }
  }
  uVar14 = 0x16a;
LAB_000d4a7a:
  ossl_statem_fatal(param_1,0x50,0x102,0x44,"ssl/record/rec_layer_d1.c",uVar14);
  return -1;
}

