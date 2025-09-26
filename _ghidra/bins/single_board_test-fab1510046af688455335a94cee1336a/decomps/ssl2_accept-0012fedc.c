
int ssl2_accept(SSL *param_1)

{
  char cVar1;
  char cVar2;
  byte *pbVar3;
  byte bVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  uint __n;
  char *pcVar8;
  long lVar9;
  BIO *pBVar10;
  _STACK *st;
  void *data;
  undefined4 uVar11;
  _STACK *st_00;
  BUF_MEM *pBVar12;
  uchar *puVar13;
  EVP_PKEY *pkey;
  size_t sVar14;
  ssl2_state_st *psVar15;
  uint uVar16;
  SSL_SESSION *pSVar17;
  SSL_SESSION *pSVar18;
  _func_3294 *p_Var19;
  uint uVar20;
  _STACK *p_Var21;
  int iVar22;
  X509 *x;
  uint num;
  undefined4 uVar23;
  undefined4 uVar24;
  int iVar25;
  char *local_70;
  time_t local_64;
  EVP_CIPHER *local_60;
  uchar *local_5c;
  EVP_MD_CTX local_58 [2];
  
  local_64 = time((time_t *)0x0);
  RAND_add(&local_64,4,0.0);
  ERR_clear_error();
  piVar5 = __errno_location();
  p_Var19 = param_1->info_callback;
  *piVar5 = 0;
  if (p_Var19 == (_func_3294 *)0x0) {
    p_Var19 = *(_func_3294 **)(param_1->psk_server_callback + 0x9c);
  }
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar6 = SSL_state(param_1);
  if (((uVar6 & 0x3000) == 0) || (iVar7 = SSL_state(param_1), iVar7 << 0x11 < 0)) {
    SSL_clear(param_1);
  }
  if (param_1->cert == (cert_st *)0x0) {
    ERR_put_error(0x14,0x7a,0xb3,"s2_srvr.c",0xa9);
    return -1;
  }
  *piVar5 = 0;
  uVar6 = param_1->state;
  if (0x2041 < (int)uVar6) goto LAB_0012ff94;
LAB_0012ff4c:
  if (0x203f < (int)uVar6) {
    if (uVar6 == 0x2040) {
      pcVar8 = param_1->init_buf->data;
      *pcVar8 = '\x05';
      sVar14 = param_1->s2->challenge_length;
      if (0x20 < sVar14) {
        ERR_put_error(0x14,0xf0,0x44,"s2_srvr.c",0x37f);
        iVar7 = -1;
        goto LAB_00130172;
      }
      memcpy(pcVar8 + 1,param_1->s2->challenge,sVar14);
      param_1->state = 0x2041;
      uVar20 = param_1->s2->challenge_length;
      param_1->init_off = 0;
      param_1->init_num = uVar20 + 1;
    }
    iVar7 = ssl2_do_write(param_1);
    if (0 < iVar7) {
      param_1->init_num = 0;
      if (param_1->hit == 0) {
        uVar20 = 0x2050;
        param_1->state = 0x2050;
      }
      else {
        uVar20 = 0x2042;
        param_1->state = 0x2042;
      }
      goto LAB_0012ff76;
    }
    goto LAB_00130172;
  }
  if ((int)uVar6 < 0x2013) {
    if (0x200f < (int)uVar6) {
      param_1->shutdown = 0;
      if (uVar6 == 0x2010) {
        param_1->max_cert_list = 1;
        param_1->state = 0x2011;
        pcVar8 = param_1->init_buf->data;
LAB_001306e4:
        iVar7 = ssl2_read(param_1,pcVar8 + param_1->init_num,9 - param_1->init_num);
        if (9 - param_1->init_num <= iVar7) {
          param_1->init_num = 9;
          if (*pcVar8 == '\x01') {
            if ((int)(uint)CONCAT11(pcVar8[1],pcVar8[2]) < param_1->version) {
              param_1->version = (uint)CONCAT11(pcVar8[1],pcVar8[2]);
            }
            psVar15 = param_1->s2;
            (psVar15->tmp).cipher_spec_length = (uint)CONCAT11(pcVar8[3],pcVar8[4]);
            (psVar15->tmp).session_id_length = (uint)CONCAT11(pcVar8[5],pcVar8[6]);
            cVar1 = pcVar8[7];
            cVar2 = pcVar8[8];
            psVar15->challenge_length = (uint)CONCAT11(cVar1,cVar2);
            if (CONCAT11(cVar1,cVar2) - 0x10 < 0x11) {
              pBVar12 = param_1->init_buf;
              param_1->state = 0x2012;
              goto LAB_0012fffc;
            }
            ssl2_return_error(param_1,0);
            ERR_put_error(0x14,0x6a,0x9e,"s2_srvr.c",0x25e);
            iVar7 = -1;
          }
          else if (*pcVar8 == '\0') {
            ERR_put_error(0x14,0x6a,200,"s2_srvr.c",0x24f);
            iVar7 = -1;
          }
          else {
            ssl2_return_error(param_1,0);
            ERR_put_error(0x14,0x6a,0xd4,"s2_srvr.c",0x24d);
            iVar7 = -1;
          }
          goto LAB_00130172;
        }
LAB_0013060e:
        iVar7 = ssl2_part_read(param_1,0x6a,iVar7);
        if (iVar7 < 1) goto LAB_00130172;
      }
      else {
        pBVar12 = param_1->init_buf;
        pcVar8 = pBVar12->data;
        if (uVar6 == 0x2011) goto LAB_001306e4;
        psVar15 = param_1->s2;
LAB_0012fffc:
        pcVar8 = pBVar12->data;
        uVar20 = (psVar15->tmp).cipher_spec_length + psVar15->challenge_length + 9 +
                 (psVar15->tmp).session_id_length;
        if (0x3fff < uVar20) {
          ssl2_return_error(param_1,0);
          ERR_put_error(0x14,0x6a,0x128,"s2_srvr.c",0x26c);
          iVar7 = -1;
          goto LAB_00130172;
        }
        iVar22 = uVar20 - param_1->init_num;
        iVar7 = ssl2_read(param_1,pcVar8 + param_1->init_num,iVar22);
        if (iVar22 != iVar7) goto LAB_0013060e;
        if (param_1->msg_callback != (_func_3292 *)0x0) {
          (*param_1->msg_callback)
                    (0,param_1->version,0,pcVar8,uVar20,param_1,param_1->msg_callback_arg);
        }
        pcVar8 = pcVar8 + 9;
        uVar20 = (param_1->s2->tmp).session_id_length;
        if ((uVar20 & 0xffffffef) != 0) {
          ssl2_return_error(param_1,0);
          ERR_put_error(0x14,0x6a,0x7d,"s2_srvr.c",0x282);
          iVar7 = -1;
          goto LAB_00130172;
        }
        if (uVar20 == 0) {
LAB_00130068:
          iVar7 = ssl_get_new_session(param_1,1);
          if (iVar7 == 0) {
LAB_00130e58:
            ssl2_return_error(param_1,0);
            iVar7 = -1;
            goto LAB_00130172;
          }
          if (param_1->hit == 0) {
            p_Var21 = (_STACK *)
                      ssl_bytes_to_cipher_list
                                (param_1,pcVar8,(param_1->s2->tmp).cipher_spec_length,
                                 param_1->session->krb5_client_princ + 0x2c);
            if ((p_Var21 == (_STACK *)0x0) ||
               ((st = &SSL_get_ciphers(param_1)->stack, st_00 = p_Var21,
                param_1->references << 9 < 0 &&
                (st_00 = sk_dup(st), st = p_Var21, st_00 == (_STACK *)0x0)))) {
              ERR_put_error(0x14,0x6a,0x41,"s2_srvr.c",0x2d2);
              iVar7 = 0;
              goto LAB_00130172;
            }
            iVar7 = 0;
            while (iVar22 = sk_num(st_00), iVar7 < iVar22) {
              data = sk_value(st_00,iVar7);
              iVar25 = sk_find(st,data);
              iVar22 = iVar7;
              if (iVar25 < 0) {
                iVar22 = iVar7 + -1;
                sk_delete(st_00,iVar7);
              }
              iVar7 = iVar22 + 1;
            }
            if (param_1->references << 9 < 0) {
              sk_free(*(_STACK **)(param_1->session->krb5_client_princ + 0x2c));
              *(_STACK **)(param_1->session->krb5_client_princ + 0x2c) = st_00;
            }
          }
        }
        else {
          iVar7 = ssl_get_prev_session(param_1,pcVar8 + (param_1->s2->tmp).cipher_spec_length);
          if (iVar7 != 1) {
            if (iVar7 == -1) goto LAB_00130e58;
            if (param_1->cert != (cert_st *)0x0) goto LAB_00130068;
            ssl2_return_error(param_1,2);
            ERR_put_error(0x14,0x6a,0xb3,"s2_srvr.c",0x296);
            iVar7 = -1;
            goto LAB_00130172;
          }
          param_1->hit = 1;
        }
        psVar15 = param_1->s2;
        if (0x20 < psVar15->challenge_length) {
          ssl2_return_error(param_1,0);
          ERR_put_error(0x14,0x6a,0x44,"s2_srvr.c",0x2cc);
          iVar7 = -1;
          goto LAB_00130172;
        }
        memcpy(psVar15->challenge,
               pcVar8 + (psVar15->tmp).session_id_length + (psVar15->tmp).cipher_spec_length,
               psVar15->challenge_length);
      }
      param_1->init_num = 0;
      uVar20 = 0x2020;
      param_1->state = 0x2020;
LAB_0012ff76:
      if (p_Var19 == (_func_3294 *)0x0) goto LAB_0012ff8a;
      if (uVar20 == uVar6) goto LAB_0012ff8a;
      do {
        param_1->state = uVar6;
        (*p_Var19)(param_1,0x2001,1);
        param_1->state = uVar20;
LAB_0012ff8a:
        do {
          uVar6 = uVar20;
          if (uVar6 < 0x2042) goto LAB_0012ff4c;
LAB_0012ff94:
          if ((int)uVar6 < 0x2062) {
            if (0x205f < (int)uVar6) {
              if (uVar6 == 0x2060) {
                pcVar8 = param_1->init_buf->data;
                *pcVar8 = '\x06';
                sVar14 = param_1->session->session_id_length;
                if (0x20 < sVar14) {
                  ERR_put_error(0x14,0xef,0x44,"s2_srvr.c",0x395);
                  iVar7 = -1;
                  goto LAB_00130172;
                }
                memcpy(pcVar8 + 1,param_1->session->session_id,sVar14);
                param_1->state = 0x2061;
                uVar20 = param_1->session->session_id_length;
                param_1->init_off = 0;
                param_1->init_num = uVar20 + 1;
              }
              iVar7 = ssl2_do_write(param_1);
              if (iVar7 < 1) goto LAB_00130172;
              uVar20 = 3;
              param_1->init_num = 0;
              param_1->state = 3;
              goto LAB_0012ff76;
            }
            if (uVar6 == 0x2042) {
              lVar9 = BIO_ctrl(param_1->wbio,3,0,(void *)0x0);
              if (0 < lVar9) {
                param_1->rwstate = 2;
                lVar9 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0);
                if (lVar9 < 1) goto LAB_00130912;
                param_1->rwstate = 1;
              }
              uVar20 = 0x2050;
              pBVar10 = BIO_pop(param_1->wbio);
              param_1->state = 0x2050;
              param_1->wbio = pBVar10;
              goto LAB_001304d4;
            }
            if (1 < uVar6 - 0x2050) goto LAB_0013015c;
            pcVar8 = param_1->init_buf->data;
            if (uVar6 == 0x2050) {
              iVar7 = ssl2_read(param_1,pcVar8 + param_1->init_num,1 - param_1->init_num);
              if (iVar7 < 1 - param_1->init_num) {
LAB_0013072e:
                iVar7 = ssl2_part_read(param_1,0x69,iVar7);
              }
              else {
                param_1->init_num = iVar7 + param_1->init_num;
                if (*pcVar8 == '\x03') {
                  param_1->state = 0x2051;
                  goto LAB_0013054e;
                }
                if (*pcVar8 != '\0') {
                  ssl2_return_error(param_1,0);
                  ERR_put_error(0x14,0x69,0xd4,"s2_srvr.c",0x352);
                  goto LAB_00130912;
                }
                ERR_put_error(0x14,0x69,200,"s2_srvr.c",0x354);
                uVar11 = ssl2_read(param_1,pcVar8 + param_1->init_num,3 - param_1->init_num);
                iVar7 = ssl2_part_read(param_1,0x6e,uVar11);
              }
              if (iVar7 < 1) goto LAB_00130172;
            }
            else {
LAB_0013054e:
              uVar20 = param_1->s2->conn_id_length;
              if (0x10 < uVar20) {
                ssl2_return_error(param_1,0);
                ERR_put_error(0x14,0x69,0x44,"s2_srvr.c",0x361);
                goto LAB_00130912;
              }
              sVar14 = uVar20 + 1;
              iVar22 = sVar14 - param_1->init_num;
              iVar7 = ssl2_read(param_1,pcVar8 + param_1->init_num,iVar22);
              if (iVar7 < iVar22) goto LAB_0013072e;
              if (param_1->msg_callback != (_func_3292 *)0x0) {
                (*param_1->msg_callback)
                          (0,param_1->version,0,pcVar8,sVar14,param_1,param_1->msg_callback_arg);
              }
              iVar7 = memcmp(pcVar8 + 1,param_1->s2->conn_id,param_1->s2->conn_id_length);
              if (iVar7 != 0) {
                ssl2_return_error(param_1,0);
                ERR_put_error(0x14,0x69,0x8f,"s2_srvr.c",0x371);
                goto LAB_00130912;
              }
            }
            param_1->init_num = 0;
            uVar20 = 0x2070;
            param_1->state = 0x2070;
            goto LAB_0012ff76;
          }
          if (uVar6 != 0x2080) {
            if (0x2080 < (int)uVar6) {
              if ((uVar6 == 0x4000) || (uVar6 == 0x6000)) goto LAB_001303ba;
              goto LAB_0013015c;
            }
            if (3 < uVar6 - 0x2070) goto LAB_0013015c;
            if ((-1 < param_1->verify_mode << 0x1f) ||
               ((*(int *)(param_1->session->krb5_client_princ + 0xc) != 0 &&
                (param_1->verify_mode << 0x1d < 0)))) {
              uVar20 = 0x2060;
              param_1->state = 0x2060;
              goto LAB_0012ff76;
            }
            psVar15 = param_1->s2;
            puVar13 = (psVar15->tmp).ccl;
            if (uVar6 == 0x2070) {
              pcVar8 = param_1->init_buf->data;
              *pcVar8 = '\a';
              pcVar8[1] = '\x01';
              iVar7 = RAND_pseudo_bytes(puVar13,0x10);
              if (iVar7 < 1) goto LAB_00130912;
              uVar23 = *(undefined4 *)((psVar15->tmp).ccl + 4);
              uVar24 = *(undefined4 *)((psVar15->tmp).ccl + 8);
              uVar11 = *(undefined4 *)((psVar15->tmp).ccl + 0xc);
              *(undefined4 *)(pcVar8 + 2) = *(undefined4 *)puVar13;
              *(undefined4 *)(pcVar8 + 6) = uVar23;
              *(undefined4 *)(pcVar8 + 10) = uVar24;
              *(undefined4 *)(pcVar8 + 0xe) = uVar11;
              param_1->state = 0x2071;
              param_1->init_num = 0x12;
              param_1->init_off = 0;
LAB_00130b74:
              iVar7 = ssl2_do_write(param_1);
              if (iVar7 < 1) {
                p_Var21 = (_STACK *)0x0;
                x = (X509 *)0x0;
              }
              else {
                iVar22 = 6;
                iVar7 = 0;
                param_1->init_num = 0;
                param_1->state = 0x2072;
LAB_00130b8e:
                pcVar8 = param_1->init_buf->data;
                iVar7 = ssl2_read(param_1,pcVar8 + iVar7,iVar22);
                if (iVar7 < 3 - param_1->init_num) goto LAB_001309d0;
                iVar7 = iVar7 + param_1->init_num;
                param_1->init_num = iVar7;
                if ((iVar7 < 3) || (*pcVar8 != '\0')) {
                  if ((*pcVar8 == '\b') && (5 < iVar7)) {
                    if (iVar7 == 6) {
                      if (pcVar8[1] == '\x01') {
                        psVar15 = param_1->s2;
                        (psVar15->tmp).clen = (uint)CONCAT11(pcVar8[2],pcVar8[3]);
                        (psVar15->tmp).rlen = (uint)CONCAT11(pcVar8[4],pcVar8[5]);
                        param_1->state = 0x2073;
                        goto LAB_001300fe;
                      }
                      ssl2_return_error(param_1);
                      iVar25 = 0x406;
                      iVar22 = 0x75;
                    }
                    else {
                      iVar25 = 0x3fd;
                      iVar22 = 0x44;
                    }
                  }
                  else {
                    ssl2_return_error(param_1,0);
                    iVar25 = 0x3f9;
                    iVar22 = 0xdb;
                  }
                }
                else {
                  if (pcVar8[1] != '\x02') {
                    param_1->init_num = iVar7 + -3;
                    iVar7 = ssl2_part_read(param_1,0x71,3);
                    p_Var21 = (_STACK *)0x0;
                    x = (X509 *)0x0;
                    goto LAB_001309e0;
                  }
                  if (param_1->msg_callback != (_func_3292 *)0x0) {
                    (*param_1->msg_callback)
                              (0,param_1->version,0,pcVar8 + 2,3,param_1,param_1->msg_callback_arg);
                  }
                  if ((param_1->verify_mode & 2U) == 0) {
                    sk_free((_STACK *)0x0);
                    X509_free((X509 *)0x0);
LAB_001309f4:
                    param_1->init_num = 0;
                    uVar20 = 0x2060;
                    param_1->state = 0x2060;
                    goto LAB_0012ff76;
                  }
                  ssl2_return_error(param_1,4);
                  iVar25 = 0x3f1;
                  iVar22 = 199;
                }
LAB_0013012a:
                p_Var21 = (_STACK *)0x0;
                iVar7 = -1;
                x = (X509 *)0x0;
                ERR_put_error(0x14,0x71,iVar22,"s2_srvr.c",iVar25);
              }
            }
            else {
              if (uVar6 == 0x2071) goto LAB_00130b74;
              if (uVar6 == 0x2072) {
                iVar7 = param_1->init_num;
                iVar22 = 6 - iVar7;
                goto LAB_00130b8e;
              }
LAB_001300fe:
              uVar20 = (psVar15->tmp).clen + (psVar15->tmp).rlen + 6;
              pcVar8 = param_1->init_buf->data;
              if (0x3fff < uVar20) {
                iVar22 = 0x128;
                iVar25 = 0x414;
                goto LAB_0013012a;
              }
              iVar22 = uVar20 - param_1->init_num;
              iVar7 = ssl2_read(param_1,pcVar8 + param_1->init_num,iVar22);
              if (iVar7 < iVar22) {
LAB_001309d0:
                p_Var21 = (_STACK *)0x0;
                iVar7 = ssl2_part_read(param_1,0x71,iVar7);
                x = (X509 *)0x0;
                goto LAB_001309e0;
              }
              if (param_1->msg_callback != (_func_3292 *)0x0) {
                (*param_1->msg_callback)
                          (0,param_1->version,0,pcVar8,uVar20,param_1,param_1->msg_callback_arg);
              }
              local_60 = (EVP_CIPHER *)(pcVar8 + 6);
              x = d2i_X509((X509 **)0x0,(uchar **)&local_60,(param_1->s2->tmp).clen);
              if (x == (X509 *)0x0) {
                ERR_put_error(0x14,0x71,0xb,"s2_srvr.c",0x426);
                p_Var21 = (_STACK *)0x0;
              }
              else {
                p_Var21 = sk_new_null();
                if ((p_Var21 == (_STACK *)0x0) || (iVar7 = sk_push(p_Var21,x), iVar7 == 0)) {
                  iVar7 = 0x42b;
LAB_001309a2:
                  ERR_put_error(0x14,0x71,0x41,"s2_srvr.c",iVar7);
                }
                else {
                  iVar7 = ssl_verify_cert_chain(param_1,p_Var21);
                  if (0 < iVar7) {
                    EVP_MD_CTX_init(local_58);
                    iVar7 = EVP_DigestInit_ex(local_58,*(EVP_MD **)
                                                        (param_1->psk_server_callback + 0x88),
                                              (ENGINE *)0x0);
                    if (((iVar7 != 0) &&
                        (iVar7 = EVP_DigestUpdate(local_58,param_1->s2->key_material,
                                                  param_1->s2->key_material_length), iVar7 != 0)) &&
                       (iVar7 = EVP_DigestUpdate(local_58,puVar13,0x10), iVar7 != 0)) {
                      iVar7 = i2d_X509(*(X509 **)(param_1->cert + 0x3c),(uchar **)0x0);
                      puVar13 = (uchar *)CRYPTO_malloc(iVar7,"s2_srvr.c",0x43d);
                      if (puVar13 == (uchar *)0x0) {
                        iVar7 = 0x43f;
                        goto LAB_001309a2;
                      }
                      local_5c = puVar13;
                      sVar14 = i2d_X509(*(X509 **)(param_1->cert + 0x3c),&local_5c);
                      iVar7 = EVP_DigestUpdate(local_58,puVar13,sVar14);
                      if (iVar7 != 0) {
                        CRYPTO_free(puVar13);
                        pkey = X509_get_pubkey(x);
                        if (pkey == (EVP_PKEY *)0x0) {
                          iVar7 = -1;
                        }
                        else {
                          iVar7 = EVP_VerifyFinal(local_58,(uchar *)local_60,(param_1->s2->tmp).rlen
                                                  ,pkey);
                          EVP_PKEY_free(pkey);
                          EVP_MD_CTX_cleanup(local_58);
                          if (iVar7 < 1) {
                            ERR_put_error(0x14,0x71,0x68,"s2_srvr.c",0x45a);
                            goto LAB_001309b0;
                          }
                          pSVar18 = param_1->session;
                          if (*(X509 **)(pSVar18->krb5_client_princ + 0xc) != (X509 *)0x0) {
                            X509_free(*(X509 **)(pSVar18->krb5_client_princ + 0xc));
                            pSVar18 = param_1->session;
                          }
                          *(X509 **)(pSVar18->krb5_client_princ + 0xc) = x;
                          iVar7 = 1;
                          CRYPTO_add_lock(&x->references,1,3,"s2_srvr.c",0x455);
                          *(int *)(param_1->session->krb5_client_princ + 0x10) = param_1->debug;
                        }
LAB_001309e0:
                        sk_free(p_Var21);
                        X509_free(x);
                        if (0 < iVar7) goto LAB_001309f4;
                        goto LAB_00130172;
                      }
                      CRYPTO_free(puVar13);
                    }
                  }
                }
              }
LAB_001309b0:
              ssl2_return_error(param_1,4);
              iVar7 = -1;
            }
            sk_free(p_Var21);
            X509_free(x);
            goto LAB_00130172;
          }
          iVar7 = ssl2_enc_init(param_1,0);
          if (iVar7 == 0) goto LAB_00130912;
          uVar20 = 0x2040;
          param_1->s2->clear_text = 0;
          param_1->state = 0x2040;
LAB_001304d4:
        } while (p_Var19 == (_func_3294 *)0x0);
      } while( true );
    }
    if (uVar6 == 0x2000) goto LAB_001303ba;
    if (uVar6 == 0x2003) goto LAB_001303ba;
    if (uVar6 != 3) goto LAB_0013015c;
    BUF_MEM_free(param_1->init_buf);
    ssl_free_wbio_buffer(param_1);
    param_1->init_buf = (BUF_MEM *)0x0;
    param_1->init_num = 0;
    ssl_update_cache(param_1,2);
    *(int *)(param_1->psk_server_callback + 0x48) =
         *(int *)(param_1->psk_server_callback + 0x48) + 1;
    if (p_Var19 == (_func_3294 *)0x0) {
      param_1->in_handshake = param_1->in_handshake + -1;
      return 1;
    }
    iVar7 = 1;
    (*p_Var19)(param_1,0x20,1);
    param_1->in_handshake = param_1->in_handshake + -1;
    goto LAB_0013017a;
  }
  if ((int)uVar6 < 0x2020) {
LAB_0013015c:
    iVar7 = -1;
    ERR_put_error(0x14,0x7a,0xff,"s2_srvr.c",0x161);
    goto LAB_00130172;
  }
  if (0x2021 < (int)uVar6) {
    if (1 < uVar6 - 0x2030) goto LAB_0013015c;
    pBVar12 = param_1->init_buf;
    local_70 = pBVar12->data;
    if (uVar6 == 0x2030) {
      iVar7 = ssl2_read(param_1,local_70 + param_1->init_num,10 - param_1->init_num);
      if (10 - param_1->init_num <= iVar7) {
        param_1->init_num = 10;
        if (*local_70 == '\x02') {
          iVar7 = ssl2_get_cipher_by_char(local_70 + 1);
          if (iVar7 == 0) {
            ssl2_return_error(param_1,1);
            ERR_put_error(0x14,0x6b,0xb9,"s2_srvr.c",0x197);
            iVar7 = -1;
          }
          else {
            pSVar18 = param_1->session;
            psVar15 = param_1->s2;
            *(int *)(pSVar18->krb5_client_princ + 0x24) = iVar7;
            (psVar15->tmp).clear = (uint)CONCAT11(local_70[4],local_70[5]);
            (psVar15->tmp).enc = (uint)CONCAT11(local_70[6],local_70[7]);
            if (CONCAT11(local_70[8],local_70[9]) < 9) {
              pBVar12 = param_1->init_buf;
              pSVar18->key_arg_length = (uint)CONCAT11(local_70[8],local_70[9]);
              param_1->state = 0x2031;
              local_70 = pBVar12->data;
              goto LAB_001301cc;
            }
            ssl2_return_error(param_1,0);
            ERR_put_error(0x14,0x6b,0x11c,"s2_srvr.c",0x1a4);
            iVar7 = -1;
          }
        }
        else if (*local_70 == '\0') {
          ERR_put_error(0x14,0x6b,200,"s2_srvr.c",400);
          iVar7 = -1;
        }
        else {
          ssl2_return_error(param_1,0);
          ERR_put_error(0x14,0x6b,0xd4,"s2_srvr.c",0x18e);
          iVar7 = -1;
        }
        goto LAB_00130172;
      }
LAB_00130622:
      iVar7 = ssl2_part_read(param_1,0x6b,iVar7);
      if (iVar7 < 1) goto LAB_00130172;
    }
    else {
LAB_001301cc:
      if (pBVar12->length < 0x3fff) {
        ssl2_return_error(param_1,0);
        iVar22 = 0x1af;
LAB_00130d88:
        iVar7 = -1;
        ERR_put_error(0x14,0x6b,0x44,"s2_srvr.c",iVar22);
        goto LAB_00130172;
      }
      sVar14 = param_1->session->key_arg_length;
      uVar20 = sVar14 + (param_1->s2->tmp).clear + 10 + (param_1->s2->tmp).enc;
      if (0x3fff < uVar20) {
        ssl2_return_error(param_1,0);
        ERR_put_error(0x14,0x6b,0x128,"s2_srvr.c",0x1b8);
        iVar7 = -1;
        goto LAB_00130172;
      }
      iVar22 = uVar20 - param_1->init_num;
      iVar7 = ssl2_read(param_1,local_70 + param_1->init_num,iVar22);
      if (iVar22 != iVar7) goto LAB_00130622;
      if (param_1->msg_callback != (_func_3292 *)0x0) {
        (*param_1->msg_callback)
                  (0,param_1->version,0,local_70,uVar20,param_1,param_1->msg_callback_arg);
      }
      local_70 = local_70 + 10;
      memcpy(param_1->session->key_arg,local_70 + (param_1->s2->tmp).enc + (param_1->s2->tmp).clear,
             sVar14);
      if (*(int *)(param_1->cert + 0x40) == 0) {
        iVar7 = -1;
        ssl2_return_error(param_1);
        ERR_put_error(0x14,0x6b,0xbd,"s2_srvr.c",0x1cb);
        goto LAB_00130172;
      }
      uVar20 = *(uint *)(*(int *)(param_1->session->krb5_client_princ + 0x24) + 0x20);
      iVar7 = ssl_cipher_get_evp(param_1->session,&local_60,&local_5c,0,0,0);
      if (iVar7 == 0) {
        ssl2_return_error(param_1,1);
        ERR_put_error(0x14,0x6b,0xce,"s2_srvr.c",0x1d4);
        iVar7 = 0;
        goto LAB_00130172;
      }
      __n = EVP_CIPHER_key_length(local_60);
      if (0x30 < __n) {
        ssl2_return_error(param_1,0);
        iVar22 = 0x1ec;
        goto LAB_00130d88;
      }
      if (*(int *)(*(int *)(param_1->session->krb5_client_princ + 0x24) + 0x24) << 0x1e < 0) {
        num = 8;
      }
      else {
        num = __n;
        if ((uVar20 & 2) != 0) {
          num = 5;
        }
      }
      if (__n != (param_1->s2->tmp).clear + num) {
        ssl2_return_error(param_1,0);
        ERR_put_error(0x14,0x6b,0x10f,"s2_srvr.c",0x1fb);
        iVar7 = -1;
        goto LAB_00130172;
      }
      if ((param_1->s2->tmp).enc < num) {
        ssl2_return_error(param_1,0);
        ERR_put_error(0x14,0x6b,0xa0,"s2_srvr.c",0x205);
        iVar7 = -1;
        goto LAB_00130172;
      }
      iVar7 = RAND_pseudo_bytes((uchar *)local_58,num);
      if (iVar7 < 1) {
        iVar7 = 0;
        goto LAB_00130172;
      }
      psVar15 = param_1->s2;
      if (psVar15->ssl2_rollback == 0) {
        iVar7 = 1;
      }
      else {
        iVar7 = 2;
      }
      if ((param_1->cert == (cert_st *)0x0) ||
         (piVar5 = *(int **)(param_1->cert + 0x40), piVar5 == (int *)0x0)) {
        iVar22 = 0x46e;
        iVar7 = 0xbd;
LAB_00130c3a:
        uVar20 = 0xffffffff;
        ERR_put_error(0x14,0xbb,iVar7,"s2_srvr.c",iVar22);
      }
      else {
        if (*piVar5 != 6) {
          iVar7 = 0xd1;
          iVar22 = 0x472;
          goto LAB_00130c3a;
        }
        uVar20 = RSA_private_decrypt((psVar15->tmp).enc,(uchar *)(local_70 + (psVar15->tmp).clear),
                                     (uchar *)(local_70 + (psVar15->tmp).clear),(RSA *)piVar5[5],
                                     iVar7);
        if ((int)uVar20 < 0) {
          ERR_put_error(0x14,0xbb,4,"s2_srvr.c",0x47a);
        }
      }
      ERR_clear_error();
      uVar16 = 0;
      bVar4 = (char)((byte)((uVar20 ^ num) - 1 >> 0x18) & ~(byte)((uVar20 ^ num) >> 0x18)) >> 7;
      if (num != 0) {
        do {
          pbVar3 = (byte *)((int)&local_58[0].digest + uVar16);
          iVar7 = uVar16 + (param_1->s2->tmp).clear;
          uVar16 = uVar16 + 1;
          local_70[iVar7] = bVar4 & local_70[iVar7] | *pbVar3 & ~bVar4;
        } while (uVar16 != num);
      }
      pSVar18 = param_1->session;
      pSVar18->master_key_length = __n;
      memcpy(pSVar18->master_key,local_70,__n);
      OPENSSL_cleanse(local_70,__n);
    }
    param_1->init_num = 0;
    uVar20 = 0x2080;
    param_1->state = 0x2080;
    goto LAB_0012ff76;
  }
  pcVar8 = param_1->init_buf->data;
  if (uVar6 == 0x2020) {
    local_5c = (uchar *)(pcVar8 + 0xb);
    *pcVar8 = '\x04';
    iVar7 = param_1->hit;
    pcVar8[1] = (char)iVar7;
    if (iVar7 == 0) {
      pSVar18 = param_1->session;
      if (*(int *)(pSVar18->krb5_client_princ + 8) != 0) {
        ssl_sess_cert_free();
        pSVar18 = param_1->session;
      }
      uVar11 = ssl_sess_cert_new();
      pSVar17 = param_1->session;
      *(undefined4 *)(pSVar18->krb5_client_princ + 8) = uVar11;
      if (*(int *)(pSVar17->krb5_client_princ + 8) == 0) {
        ERR_put_error(0x14,0x72,0x41,"s2_srvr.c",0x2eb);
        goto LAB_00130912;
      }
      if (param_1->cert == (cert_st *)0x0) goto LAB_00130f82;
      pcVar8[2] = '\x01';
      pcVar8[3] = (char)((uint)param_1->version >> 8);
      pcVar8[4] = (char)param_1->version;
      iVar7 = i2d_X509(*(X509 **)(param_1->cert + 0x3c),(uchar **)0x0);
      pcVar8[6] = (char)iVar7;
      pcVar8[5] = (char)((uint)iVar7 >> 8);
      i2d_X509(*(X509 **)(param_1->cert + 0x3c),&local_5c);
      iVar7 = ssl_cipher_list_to_bytes
                        (param_1,*(undefined4 *)(param_1->session->krb5_client_princ + 0x2c),
                         local_5c,0);
      local_5c = local_5c + iVar7;
      pcVar8[8] = (char)iVar7;
      pcVar8[7] = (char)((uint)iVar7 >> 8);
    }
    else {
      if (param_1->cert == (cert_st *)0x0) {
LAB_00130f82:
        ssl2_return_error(param_1,2);
        ERR_put_error(0x14,0x72,0xb4,"s2_srvr.c",0x30b);
        goto LAB_00130912;
      }
      pcVar8[2] = '\0';
      pcVar8[3] = (char)((uint)param_1->version >> 8);
      iVar7 = param_1->version;
      pcVar8[5] = '\0';
      pcVar8[6] = '\0';
      pcVar8[4] = (char)iVar7;
      pcVar8[7] = '\0';
      pcVar8[8] = '\0';
    }
    pcVar8[9] = '\0';
    pcVar8[10] = '\x10';
    psVar15 = param_1->s2;
    psVar15->conn_id_length = 0x10;
    iVar7 = RAND_pseudo_bytes(psVar15->conn_id,0x10);
    if (iVar7 < 1) goto LAB_00130912;
    psVar15 = param_1->s2;
    uVar24 = *(undefined4 *)psVar15->conn_id;
    uVar11 = *(undefined4 *)(psVar15->conn_id + 8);
    uVar23 = *(undefined4 *)(psVar15->conn_id + 0xc);
    *(undefined4 *)(local_5c + 4) = *(undefined4 *)(psVar15->conn_id + 4);
    *(undefined4 *)local_5c = uVar24;
    *(undefined4 *)(local_5c + 8) = uVar11;
    *(undefined4 *)(local_5c + 0xc) = uVar23;
    param_1->state = 0x2021;
    local_5c = local_5c + 0x10;
    pcVar8 = param_1->init_buf->data;
    param_1->init_off = 0;
    param_1->init_num = (int)local_5c - (int)pcVar8;
  }
  if ((param_1->hit == 0) || (iVar7 = ssl_init_wbio_buffer(param_1,1), iVar7 != 0)) {
    iVar7 = ssl2_do_write(param_1);
    if (0 < iVar7) {
      param_1->init_num = 0;
      if (param_1->hit == 0) {
        uVar20 = 0x2030;
        param_1->state = 0x2030;
      }
      else {
        uVar20 = 0x2080;
        param_1->state = 0x2080;
      }
      goto LAB_0012ff76;
    }
    goto LAB_00130172;
  }
LAB_00130912:
  iVar7 = -1;
LAB_00130172:
  param_1->in_handshake = param_1->in_handshake + -1;
  if (p_Var19 != (_func_3294 *)0x0) {
LAB_0013017a:
    (*p_Var19)(param_1,0x2002,iVar7);
  }
  return iVar7;
LAB_001303ba:
  param_1->server = 1;
  if (p_Var19 != (_func_3294 *)0x0) {
    (*p_Var19)(param_1,0x10,1);
  }
  param_1->version = 2;
  param_1->type = 0x2000;
  if (param_1->init_buf == (BUF_MEM *)0x0) {
    pBVar12 = BUF_MEM_new();
    if (pBVar12 == (BUF_MEM *)0x0) goto LAB_00130912;
    iVar7 = BUF_MEM_grow(pBVar12,0x3fff);
    if (iVar7 == 0) {
      iVar7 = -1;
      BUF_MEM_free(pBVar12);
      goto LAB_00130172;
    }
    param_1->init_buf = pBVar12;
  }
  param_1->init_num = 0;
  uVar20 = 0x2010;
  *(int *)(param_1->psk_server_callback + 0x40) = *(int *)(param_1->psk_server_callback + 0x40) + 1;
  param_1->handshake_func = ssl2_accept;
  param_1->state = 0x2010;
  goto LAB_0012ff76;
}

