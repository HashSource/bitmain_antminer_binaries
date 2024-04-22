
int ssl2_accept(SSL *param_1)

{
  char cVar1;
  char cVar2;
  byte *pbVar3;
  byte bVar4;
  _func_3291 *p_Var5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  uint __n;
  char *pcVar9;
  long lVar10;
  BIO *pBVar11;
  _STACK *st;
  void *data;
  undefined4 uVar12;
  _STACK *st_00;
  BUF_MEM *pBVar13;
  undefined4 *d;
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
  uchar *buf;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 in_stack_ffffff80;
  int iVar25;
  undefined4 in_stack_ffffff84;
  char *local_70;
  time_t local_64;
  EVP_CIPHER *local_60;
  undefined4 *local_5c;
  EVP_MD_CTX local_58 [2];
  
  local_64 = time((time_t *)0x0);
  RAND_add(&local_64,4,(double)CONCAT44(in_stack_ffffff84,in_stack_ffffff80));
  ERR_clear_error();
  piVar6 = __errno_location();
  p_Var19 = param_1->info_callback;
  *piVar6 = 0;
  if (p_Var19 == (_func_3294 *)0x0) {
    p_Var19 = *(_func_3294 **)(param_1->psk_server_callback + 0x9c);
  }
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar7 = SSL_state(param_1);
  if (((uVar7 & 0x3000) == 0) || (iVar8 = SSL_state(param_1), iVar8 << 0x11 < 0)) {
    SSL_clear(param_1);
  }
  if (param_1->cert == (cert_st *)0x0) {
    ERR_put_error(0x14,0x7a,0xb3,DAT_000854a4,0xa9);
    return -1;
  }
  *piVar6 = 0;
  p_Var5 = DAT_000846f4;
  uVar7 = param_1->state;
  if (0x2041 < (int)uVar7) goto LAB_000844ec;
LAB_000844a4:
  if (0x203f < (int)uVar7) {
    if (uVar7 == 0x2040) {
      pcVar9 = param_1->init_buf->data;
      *pcVar9 = '\x05';
      sVar14 = param_1->s2->challenge_length;
      if (0x20 < sVar14) {
        ERR_put_error(0x14,0xf0,0x44,DAT_000854a4,0x37f);
        iVar8 = -1;
        goto LAB_000846ca;
      }
      memcpy(pcVar9 + 1,param_1->s2->challenge,sVar14);
      param_1->state = 0x2041;
      uVar20 = param_1->s2->challenge_length;
      param_1->init_off = 0;
      param_1->init_num = uVar20 + 1;
    }
    iVar8 = ssl2_do_write(param_1);
    if (0 < iVar8) {
      param_1->init_num = 0;
      if (param_1->hit == 0) {
        uVar20 = 0x2050;
        param_1->state = 0x2050;
      }
      else {
        uVar20 = 0x2042;
        param_1->state = 0x2042;
      }
      goto LAB_000844ce;
    }
    goto LAB_000846ca;
  }
  if ((int)uVar7 < 0x2013) {
    if (0x200f < (int)uVar7) {
      param_1->shutdown = 0;
      if (uVar7 == 0x2010) {
        param_1->max_cert_list = 1;
        param_1->state = 0x2011;
        pcVar9 = param_1->init_buf->data;
LAB_00084c3c:
        iVar8 = ssl2_read(param_1,pcVar9 + param_1->init_num,9 - param_1->init_num);
        if (9 - param_1->init_num <= iVar8) {
          param_1->init_num = 9;
          if (*pcVar9 == '\x01') {
            if ((int)(uint)CONCAT11(pcVar9[1],pcVar9[2]) < param_1->version) {
              param_1->version = (uint)CONCAT11(pcVar9[1],pcVar9[2]);
            }
            psVar15 = param_1->s2;
            (psVar15->tmp).cipher_spec_length = (uint)CONCAT11(pcVar9[3],pcVar9[4]);
            (psVar15->tmp).session_id_length = (uint)CONCAT11(pcVar9[5],pcVar9[6]);
            cVar1 = pcVar9[7];
            cVar2 = pcVar9[8];
            psVar15->challenge_length = (uint)CONCAT11(cVar1,cVar2);
            if (CONCAT11(cVar1,cVar2) - 0x10 < 0x11) {
              pBVar13 = param_1->init_buf;
              param_1->state = 0x2012;
              goto LAB_00084554;
            }
            ssl2_return_error(param_1,0);
            ERR_put_error(0x14,0x6a,0x9e,DAT_00085610,0x25e);
            iVar8 = -1;
          }
          else if (*pcVar9 == '\0') {
            ERR_put_error(0x14,0x6a,200,DAT_00085168,0x24f);
            iVar8 = -1;
          }
          else {
            ssl2_return_error(param_1,0);
            ERR_put_error(0x14,0x6a,0xd4,DAT_00084e4c,0x24d);
            iVar8 = -1;
          }
          goto LAB_000846ca;
        }
LAB_00084b66:
        iVar8 = ssl2_part_read(param_1,0x6a,iVar8);
        if (iVar8 < 1) goto LAB_000846ca;
      }
      else {
        pBVar13 = param_1->init_buf;
        pcVar9 = pBVar13->data;
        if (uVar7 == 0x2011) goto LAB_00084c3c;
        psVar15 = param_1->s2;
LAB_00084554:
        pcVar9 = pBVar13->data;
        uVar20 = (psVar15->tmp).cipher_spec_length + psVar15->challenge_length + 9 +
                 (psVar15->tmp).session_id_length;
        if (0x3fff < uVar20) {
          ssl2_return_error(param_1,0);
          ERR_put_error(0x14,0x6a,0x128,DAT_00085168,0x26c);
          iVar8 = -1;
          goto LAB_000846ca;
        }
        iVar22 = uVar20 - param_1->init_num;
        iVar8 = ssl2_read(param_1,pcVar9 + param_1->init_num,iVar22);
        if (iVar22 != iVar8) goto LAB_00084b66;
        if (param_1->msg_callback != (_func_3292 *)0x0) {
          (*param_1->msg_callback)
                    (0,param_1->version,0,pcVar9,uVar20,param_1,param_1->msg_callback_arg);
        }
        pcVar9 = pcVar9 + 9;
        uVar20 = (param_1->s2->tmp).session_id_length;
        if ((uVar20 & 0xffffffef) != 0) {
          ssl2_return_error(param_1,0);
          ERR_put_error(0x14,0x6a,0x7d,DAT_000854a4,0x282);
          iVar8 = -1;
          goto LAB_000846ca;
        }
        if (uVar20 == 0) {
LAB_000845c0:
          iVar8 = ssl_get_new_session(param_1,1);
          if (iVar8 == 0) {
LAB_000853b0:
            ssl2_return_error(param_1,0);
            iVar8 = -1;
            goto LAB_000846ca;
          }
          if (param_1->hit == 0) {
            p_Var21 = (_STACK *)
                      ssl_bytes_to_cipher_list
                                (param_1,pcVar9,(param_1->s2->tmp).cipher_spec_length,
                                 param_1->session->krb5_client_princ + 0x2c);
            if ((p_Var21 == (_STACK *)0x0) ||
               ((st = &SSL_get_ciphers(param_1)->stack, st_00 = p_Var21,
                param_1->references << 9 < 0 &&
                (st_00 = sk_dup(st), st = p_Var21, st_00 == (_STACK *)0x0)))) {
              ERR_put_error(0x14,0x6a,0x41,DAT_00085168,0x2d2);
              iVar8 = 0;
              goto LAB_000846ca;
            }
            iVar8 = 0;
            while (iVar22 = sk_num(st_00), iVar8 < iVar22) {
              data = sk_value(st_00,iVar8);
              iVar25 = sk_find(st,data);
              iVar22 = iVar8;
              if (iVar25 < 0) {
                iVar22 = iVar8 + -1;
                sk_delete(st_00,iVar8);
              }
              iVar8 = iVar22 + 1;
            }
            if (param_1->references << 9 < 0) {
              sk_free(*(_STACK **)(param_1->session->krb5_client_princ + 0x2c));
              *(_STACK **)(param_1->session->krb5_client_princ + 0x2c) = st_00;
            }
          }
        }
        else {
          iVar8 = ssl_get_prev_session(param_1,pcVar9 + (param_1->s2->tmp).cipher_spec_length);
          if (iVar8 != 1) {
            if (iVar8 == -1) goto LAB_000853b0;
            if (param_1->cert != (cert_st *)0x0) goto LAB_000845c0;
            ssl2_return_error(param_1,2);
            ERR_put_error(0x14,0x6a,0xb3,DAT_00084e4c,0x296);
            iVar8 = -1;
            goto LAB_000846ca;
          }
          param_1->hit = 1;
        }
        psVar15 = param_1->s2;
        if (0x20 < psVar15->challenge_length) {
          ssl2_return_error(param_1,0);
          ERR_put_error(0x14,0x6a,0x44,DAT_000854a4,0x2cc);
          iVar8 = -1;
          goto LAB_000846ca;
        }
        memcpy(psVar15->challenge,
               pcVar9 + (psVar15->tmp).session_id_length + (psVar15->tmp).cipher_spec_length,
               psVar15->challenge_length);
      }
      param_1->init_num = 0;
      uVar20 = 0x2020;
      param_1->state = 0x2020;
LAB_000844ce:
      if (p_Var19 == (_func_3294 *)0x0) goto LAB_000844e2;
      if (uVar20 == uVar7) goto LAB_000844e2;
      do {
        param_1->state = uVar7;
        (*p_Var19)(param_1,0x2001,1);
        param_1->state = uVar20;
LAB_000844e2:
        do {
          uVar7 = uVar20;
          if (uVar7 < 0x2042) goto LAB_000844a4;
LAB_000844ec:
          if ((int)uVar7 < 0x2062) {
            if (0x205f < (int)uVar7) {
              if (uVar7 == 0x2060) {
                pcVar9 = param_1->init_buf->data;
                *pcVar9 = '\x06';
                sVar14 = param_1->session->session_id_length;
                if (0x20 < sVar14) {
                  ERR_put_error(0x14,0xef,0x44,DAT_000854a4,0x395);
                  iVar8 = -1;
                  goto LAB_000846ca;
                }
                memcpy(pcVar9 + 1,param_1->session->session_id,sVar14);
                param_1->state = 0x2061;
                uVar20 = param_1->session->session_id_length;
                param_1->init_off = 0;
                param_1->init_num = uVar20 + 1;
              }
              iVar8 = ssl2_do_write(param_1);
              if (iVar8 < 1) goto LAB_000846ca;
              uVar20 = 3;
              param_1->init_num = 0;
              param_1->state = 3;
              goto LAB_000844ce;
            }
            if (uVar7 == 0x2042) {
              lVar10 = BIO_ctrl(param_1->wbio,3,0,(void *)0x0);
              if (0 < lVar10) {
                param_1->rwstate = 2;
                lVar10 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0);
                if (lVar10 < 1) goto LAB_00084e6a;
                param_1->rwstate = 1;
              }
              uVar20 = 0x2050;
              pBVar11 = BIO_pop(param_1->wbio);
              param_1->state = 0x2050;
              param_1->wbio = pBVar11;
              goto LAB_00084a2c;
            }
            if (1 < uVar7 - 0x2050) goto LAB_000846b4;
            pcVar9 = param_1->init_buf->data;
            if (uVar7 == 0x2050) {
              iVar8 = ssl2_read(param_1,pcVar9 + param_1->init_num,1 - param_1->init_num);
              if (iVar8 < 1 - param_1->init_num) {
LAB_00084c86:
                iVar8 = ssl2_part_read(param_1,0x69,iVar8);
              }
              else {
                param_1->init_num = iVar8 + param_1->init_num;
                if (*pcVar9 == '\x03') {
                  param_1->state = 0x2051;
                  goto LAB_00084aa6;
                }
                if (*pcVar9 != '\0') {
                  ssl2_return_error(param_1,0);
                  ERR_put_error(0x14,0x69,0xd4,DAT_000854a4,0x352);
                  goto LAB_00084e6a;
                }
                ERR_put_error(0x14,0x69,200,DAT_00084e4c,0x354);
                uVar12 = ssl2_read(param_1,pcVar9 + param_1->init_num,3 - param_1->init_num);
                iVar8 = ssl2_part_read(param_1,0x6e,uVar12);
              }
              if (iVar8 < 1) goto LAB_000846ca;
            }
            else {
LAB_00084aa6:
              uVar20 = param_1->s2->conn_id_length;
              if (0x10 < uVar20) {
                ssl2_return_error(param_1,0);
                ERR_put_error(0x14,0x69,0x44,DAT_00085168,0x361);
                goto LAB_00084e6a;
              }
              sVar14 = uVar20 + 1;
              iVar22 = sVar14 - param_1->init_num;
              iVar8 = ssl2_read(param_1,pcVar9 + param_1->init_num,iVar22);
              if (iVar8 < iVar22) goto LAB_00084c86;
              if (param_1->msg_callback != (_func_3292 *)0x0) {
                (*param_1->msg_callback)
                          (0,param_1->version,0,pcVar9,sVar14,param_1,param_1->msg_callback_arg);
              }
              iVar8 = memcmp(pcVar9 + 1,param_1->s2->conn_id,param_1->s2->conn_id_length);
              if (iVar8 != 0) {
                ssl2_return_error(param_1,0);
                ERR_put_error(0x14,0x69,0x8f,DAT_000854a4,0x371);
                goto LAB_00084e6a;
              }
            }
            param_1->init_num = 0;
            uVar20 = 0x2070;
            param_1->state = 0x2070;
            goto LAB_000844ce;
          }
          if (uVar7 != 0x2080) {
            if (0x2080 < (int)uVar7) {
              if ((uVar7 == 0x4000) || (uVar7 == 0x6000)) goto LAB_00084912;
              goto LAB_000846b4;
            }
            if (3 < uVar7 - 0x2070) goto LAB_000846b4;
            if ((-1 < param_1->verify_mode << 0x1f) ||
               ((*(int *)(param_1->session->krb5_client_princ + 0xc) != 0 &&
                (param_1->verify_mode << 0x1d < 0)))) {
              uVar20 = 0x2060;
              param_1->state = 0x2060;
              goto LAB_000844ce;
            }
            psVar15 = param_1->s2;
            buf = (psVar15->tmp).ccl;
            if (uVar7 == 0x2070) {
              pcVar9 = param_1->init_buf->data;
              *pcVar9 = '\a';
              pcVar9[1] = '\x01';
              iVar8 = RAND_pseudo_bytes(buf,0x10);
              if (iVar8 < 1) goto LAB_00084e6a;
              uVar23 = *(undefined4 *)((psVar15->tmp).ccl + 4);
              uVar24 = *(undefined4 *)((psVar15->tmp).ccl + 8);
              uVar12 = *(undefined4 *)((psVar15->tmp).ccl + 0xc);
              *(undefined4 *)(pcVar9 + 2) = *(undefined4 *)buf;
              *(undefined4 *)(pcVar9 + 6) = uVar23;
              *(undefined4 *)(pcVar9 + 10) = uVar24;
              *(undefined4 *)(pcVar9 + 0xe) = uVar12;
              param_1->state = 0x2071;
              param_1->init_num = 0x12;
              param_1->init_off = 0;
LAB_000850cc:
              iVar8 = ssl2_do_write(param_1);
              if (iVar8 < 1) {
                p_Var21 = (_STACK *)0x0;
                x = (X509 *)0x0;
              }
              else {
                iVar22 = 6;
                iVar8 = 0;
                param_1->init_num = 0;
                param_1->state = 0x2072;
LAB_000850e6:
                pcVar9 = param_1->init_buf->data;
                iVar8 = ssl2_read(param_1,pcVar9 + iVar8,iVar22);
                if (iVar8 < 3 - param_1->init_num) goto LAB_00084f28;
                iVar8 = iVar8 + param_1->init_num;
                param_1->init_num = iVar8;
                if ((iVar8 < 3) || (*pcVar9 != '\0')) {
                  if ((*pcVar9 == '\b') && (5 < iVar8)) {
                    if (iVar8 == 6) {
                      if (pcVar9[1] == '\x01') {
                        psVar15 = param_1->s2;
                        (psVar15->tmp).clen = (uint)CONCAT11(pcVar9[2],pcVar9[3]);
                        (psVar15->tmp).rlen = (uint)CONCAT11(pcVar9[4],pcVar9[5]);
                        param_1->state = 0x2073;
                        goto LAB_00084656;
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
                  if (pcVar9[1] != '\x02') {
                    param_1->init_num = iVar8 + -3;
                    iVar8 = ssl2_part_read(param_1,0x71,3);
                    p_Var21 = (_STACK *)0x0;
                    x = (X509 *)0x0;
                    goto LAB_00084f38;
                  }
                  if (param_1->msg_callback != (_func_3292 *)0x0) {
                    (*param_1->msg_callback)
                              (0,param_1->version,0,pcVar9 + 2,3,param_1,param_1->msg_callback_arg);
                  }
                  if ((param_1->verify_mode & 2U) == 0) {
                    sk_free((_STACK *)0x0);
                    X509_free((X509 *)0x0);
LAB_00084f4c:
                    param_1->init_num = 0;
                    uVar20 = 0x2060;
                    param_1->state = 0x2060;
                    goto LAB_000844ce;
                  }
                  ssl2_return_error(param_1,4);
                  iVar25 = 0x3f1;
                  iVar22 = 199;
                }
LAB_00084682:
                p_Var21 = (_STACK *)0x0;
                iVar8 = -1;
                x = (X509 *)0x0;
                ERR_put_error(0x14,0x71,iVar22,DAT_000846f0,iVar25);
              }
            }
            else {
              if (uVar7 == 0x2071) goto LAB_000850cc;
              if (uVar7 == 0x2072) {
                iVar8 = param_1->init_num;
                iVar22 = 6 - iVar8;
                goto LAB_000850e6;
              }
LAB_00084656:
              uVar20 = (psVar15->tmp).clen + (psVar15->tmp).rlen + 6;
              pcVar9 = param_1->init_buf->data;
              if (0x3fff < uVar20) {
                iVar22 = 0x128;
                iVar25 = 0x414;
                goto LAB_00084682;
              }
              iVar22 = uVar20 - param_1->init_num;
              iVar8 = ssl2_read(param_1,pcVar9 + param_1->init_num,iVar22);
              if (iVar8 < iVar22) {
LAB_00084f28:
                p_Var21 = (_STACK *)0x0;
                iVar8 = ssl2_part_read(param_1,0x71,iVar8);
                x = (X509 *)0x0;
                goto LAB_00084f38;
              }
              if (param_1->msg_callback != (_func_3292 *)0x0) {
                (*param_1->msg_callback)
                          (0,param_1->version,0,pcVar9,uVar20,param_1,param_1->msg_callback_arg);
              }
              local_60 = (EVP_CIPHER *)(pcVar9 + 6);
              x = d2i_X509((X509 **)0x0,(uchar **)&local_60,(param_1->s2->tmp).clen);
              if (x == (X509 *)0x0) {
                ERR_put_error(0x14,0x71,0xb,DAT_000854a4,0x426);
                p_Var21 = (_STACK *)0x0;
              }
              else {
                p_Var21 = sk_new_null();
                if ((p_Var21 == (_STACK *)0x0) || (iVar8 = sk_push(p_Var21,x), iVar8 == 0)) {
                  iVar8 = 0x42b;
LAB_00084efa:
                  ERR_put_error(0x14,0x71,0x41,DAT_00085168,iVar8);
                }
                else {
                  iVar8 = ssl_verify_cert_chain(param_1,p_Var21);
                  if (0 < iVar8) {
                    EVP_MD_CTX_init(local_58);
                    iVar8 = EVP_DigestInit_ex(local_58,*(EVP_MD **)
                                                        (param_1->psk_server_callback + 0x88),
                                              (ENGINE *)0x0);
                    if (((iVar8 != 0) &&
                        (iVar8 = EVP_DigestUpdate(local_58,param_1->s2->key_material,
                                                  param_1->s2->key_material_length), iVar8 != 0)) &&
                       (iVar8 = EVP_DigestUpdate(local_58,buf,0x10), iVar8 != 0)) {
                      iVar8 = i2d_X509(*(X509 **)(param_1->cert + 0x3c),(uchar **)0x0);
                      d = (undefined4 *)CRYPTO_malloc(iVar8,DAT_000854a4,0x43d);
                      if (d == (undefined4 *)0x0) {
                        iVar8 = 0x43f;
                        goto LAB_00084efa;
                      }
                      local_5c = d;
                      sVar14 = i2d_X509(*(X509 **)(param_1->cert + 0x3c),(uchar **)&local_5c);
                      iVar8 = EVP_DigestUpdate(local_58,d,sVar14);
                      if (iVar8 != 0) {
                        CRYPTO_free(d);
                        pkey = X509_get_pubkey(x);
                        if (pkey == (EVP_PKEY *)0x0) {
                          iVar8 = -1;
                        }
                        else {
                          iVar8 = EVP_VerifyFinal(local_58,(uchar *)local_60,(param_1->s2->tmp).rlen
                                                  ,pkey);
                          EVP_PKEY_free(pkey);
                          EVP_MD_CTX_cleanup(local_58);
                          if (iVar8 < 1) {
                            ERR_put_error(0x14,0x71,0x68,DAT_00085610,0x45a);
                            goto LAB_00084f08;
                          }
                          pSVar18 = param_1->session;
                          if (*(X509 **)(pSVar18->krb5_client_princ + 0xc) != (X509 *)0x0) {
                            X509_free(*(X509 **)(pSVar18->krb5_client_princ + 0xc));
                            pSVar18 = param_1->session;
                          }
                          *(X509 **)(pSVar18->krb5_client_princ + 0xc) = x;
                          iVar8 = 1;
                          CRYPTO_add_lock(&x->references,1,3,DAT_00085610,0x455);
                          *(int *)(param_1->session->krb5_client_princ + 0x10) = param_1->debug;
                        }
LAB_00084f38:
                        sk_free(p_Var21);
                        X509_free(x);
                        if (0 < iVar8) goto LAB_00084f4c;
                        goto LAB_000846ca;
                      }
                      CRYPTO_free(d);
                    }
                  }
                }
              }
LAB_00084f08:
              ssl2_return_error(param_1,4);
              iVar8 = -1;
            }
            sk_free(p_Var21);
            X509_free(x);
            goto LAB_000846ca;
          }
          iVar8 = ssl2_enc_init(param_1,0);
          if (iVar8 == 0) goto LAB_00084e6a;
          uVar20 = 0x2040;
          param_1->s2->clear_text = 0;
          param_1->state = 0x2040;
LAB_00084a2c:
        } while (p_Var19 == (_func_3294 *)0x0);
      } while( true );
    }
    if (uVar7 == 0x2000) goto LAB_00084912;
    if (uVar7 == 0x2003) goto LAB_00084912;
    if (uVar7 != 3) goto LAB_000846b4;
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
    iVar8 = 1;
    (*p_Var19)(param_1,0x20,1);
    param_1->in_handshake = param_1->in_handshake + -1;
    goto LAB_000846d2;
  }
  if ((int)uVar7 < 0x2020) {
LAB_000846b4:
    iVar8 = -1;
    ERR_put_error(0x14,0x7a,0xff,DAT_000846f0,0x161);
    goto LAB_000846ca;
  }
  if (0x2021 < (int)uVar7) {
    if (1 < uVar7 - 0x2030) goto LAB_000846b4;
    pBVar13 = param_1->init_buf;
    local_70 = pBVar13->data;
    if (uVar7 == 0x2030) {
      iVar8 = ssl2_read(param_1,local_70 + param_1->init_num,10 - param_1->init_num);
      if (10 - param_1->init_num <= iVar8) {
        param_1->init_num = 10;
        if (*local_70 == '\x02') {
          iVar8 = ssl2_get_cipher_by_char(local_70 + 1);
          if (iVar8 == 0) {
            ssl2_return_error(param_1,1);
            ERR_put_error(0x14,0x6b,0xb9,DAT_00085610,0x197);
            iVar8 = -1;
          }
          else {
            pSVar18 = param_1->session;
            psVar15 = param_1->s2;
            *(int *)(pSVar18->krb5_client_princ + 0x24) = iVar8;
            (psVar15->tmp).clear = (uint)CONCAT11(local_70[4],local_70[5]);
            (psVar15->tmp).enc = (uint)CONCAT11(local_70[6],local_70[7]);
            if (CONCAT11(local_70[8],local_70[9]) < 9) {
              pBVar13 = param_1->init_buf;
              pSVar18->key_arg_length = (uint)CONCAT11(local_70[8],local_70[9]);
              param_1->state = 0x2031;
              local_70 = pBVar13->data;
              goto LAB_00084724;
            }
            ssl2_return_error(param_1,0);
            ERR_put_error(0x14,0x6b,0x11c,DAT_00085610,0x1a4);
            iVar8 = -1;
          }
        }
        else if (*local_70 == '\0') {
          ERR_put_error(0x14,0x6b,200,DAT_00085168,400);
          iVar8 = -1;
        }
        else {
          ssl2_return_error(param_1,0);
          ERR_put_error(0x14,0x6b,0xd4,DAT_00084e4c,0x18e);
          iVar8 = -1;
        }
        goto LAB_000846ca;
      }
LAB_00084b7a:
      iVar8 = ssl2_part_read(param_1,0x6b,iVar8);
      if (iVar8 < 1) goto LAB_000846ca;
    }
    else {
LAB_00084724:
      if (pBVar13->length < 0x3fff) {
        ssl2_return_error(param_1,0);
        iVar22 = 0x1af;
LAB_000852e0:
        iVar8 = -1;
        ERR_put_error(0x14,0x6b,0x44,DAT_000854a4,iVar22);
        goto LAB_000846ca;
      }
      sVar14 = param_1->session->key_arg_length;
      uVar20 = sVar14 + (param_1->s2->tmp).clear + 10 + (param_1->s2->tmp).enc;
      if (0x3fff < uVar20) {
        ssl2_return_error(param_1,0);
        ERR_put_error(0x14,0x6b,0x128,DAT_00085168,0x1b8);
        iVar8 = -1;
        goto LAB_000846ca;
      }
      iVar22 = uVar20 - param_1->init_num;
      iVar8 = ssl2_read(param_1,local_70 + param_1->init_num,iVar22);
      if (iVar22 != iVar8) goto LAB_00084b7a;
      if (param_1->msg_callback != (_func_3292 *)0x0) {
        (*param_1->msg_callback)
                  (0,param_1->version,0,local_70,uVar20,param_1,param_1->msg_callback_arg);
      }
      local_70 = local_70 + 10;
      memcpy(param_1->session->key_arg,local_70 + (param_1->s2->tmp).enc + (param_1->s2->tmp).clear,
             sVar14);
      if (*(int *)(param_1->cert + 0x40) == 0) {
        iVar8 = -1;
        ssl2_return_error(param_1);
        ERR_put_error(0x14,0x6b,0xbd,DAT_000854a4,0x1cb);
        goto LAB_000846ca;
      }
      uVar20 = *(uint *)(*(int *)(param_1->session->krb5_client_princ + 0x24) + 0x20);
      iVar8 = ssl_cipher_get_evp(param_1->session,&local_60,&local_5c,0,0,0);
      if (iVar8 == 0) {
        ssl2_return_error(param_1,1);
        ERR_put_error(0x14,0x6b,0xce,DAT_00084e4c,0x1d4);
        iVar8 = 0;
        goto LAB_000846ca;
      }
      __n = EVP_CIPHER_key_length(local_60);
      if (0x30 < __n) {
        ssl2_return_error(param_1,0);
        iVar22 = 0x1ec;
        goto LAB_000852e0;
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
        ERR_put_error(0x14,0x6b,0x10f,DAT_000854a4,0x1fb);
        iVar8 = -1;
        goto LAB_000846ca;
      }
      if ((param_1->s2->tmp).enc < num) {
        ssl2_return_error(param_1,0);
        ERR_put_error(0x14,0x6b,0xa0,DAT_000854a4,0x205);
        iVar8 = -1;
        goto LAB_000846ca;
      }
      iVar8 = RAND_pseudo_bytes((uchar *)local_58,num);
      if (iVar8 < 1) {
        iVar8 = 0;
        goto LAB_000846ca;
      }
      psVar15 = param_1->s2;
      if (psVar15->ssl2_rollback == 0) {
        iVar8 = 1;
      }
      else {
        iVar8 = 2;
      }
      if ((param_1->cert == (cert_st *)0x0) ||
         (piVar6 = *(int **)(param_1->cert + 0x40), piVar6 == (int *)0x0)) {
        iVar22 = 0x46e;
        iVar8 = 0xbd;
LAB_00085192:
        uVar20 = 0xffffffff;
        ERR_put_error(0x14,0xbb,iVar8,DAT_000854a4,iVar22);
      }
      else {
        if (*piVar6 != 6) {
          iVar8 = 0xd1;
          iVar22 = 0x472;
          goto LAB_00085192;
        }
        uVar20 = RSA_private_decrypt((psVar15->tmp).enc,(uchar *)(local_70 + (psVar15->tmp).clear),
                                     (uchar *)(local_70 + (psVar15->tmp).clear),(RSA *)piVar6[5],
                                     iVar8);
        if ((int)uVar20 < 0) {
          ERR_put_error(0x14,0xbb,4,DAT_000854a4,0x47a);
        }
      }
      ERR_clear_error();
      uVar16 = 0;
      bVar4 = (char)((byte)((uVar20 ^ num) - 1 >> 0x18) & ~(byte)((uVar20 ^ num) >> 0x18)) >> 7;
      if (num != 0) {
        do {
          pbVar3 = (byte *)((int)&local_58[0].digest + uVar16);
          iVar8 = uVar16 + (param_1->s2->tmp).clear;
          uVar16 = uVar16 + 1;
          local_70[iVar8] = bVar4 & local_70[iVar8] | *pbVar3 & ~bVar4;
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
    goto LAB_000844ce;
  }
  pcVar9 = param_1->init_buf->data;
  if (uVar7 == 0x2020) {
    local_5c = (undefined4 *)(pcVar9 + 0xb);
    *pcVar9 = '\x04';
    iVar8 = param_1->hit;
    pcVar9[1] = (char)iVar8;
    if (iVar8 == 0) {
      pSVar18 = param_1->session;
      if (*(int *)(pSVar18->krb5_client_princ + 8) != 0) {
        ssl_sess_cert_free();
        pSVar18 = param_1->session;
      }
      uVar12 = ssl_sess_cert_new();
      pSVar17 = param_1->session;
      *(undefined4 *)(pSVar18->krb5_client_princ + 8) = uVar12;
      if (*(int *)(pSVar17->krb5_client_princ + 8) == 0) {
        ERR_put_error(0x14,0x72,0x41,DAT_00085610,0x2eb);
        goto LAB_00084e6a;
      }
      if (param_1->cert == (cert_st *)0x0) goto LAB_000854da;
      pcVar9[2] = '\x01';
      pcVar9[3] = (char)((uint)param_1->version >> 8);
      pcVar9[4] = (char)param_1->version;
      iVar8 = i2d_X509(*(X509 **)(param_1->cert + 0x3c),(uchar **)0x0);
      pcVar9[6] = (char)iVar8;
      pcVar9[5] = (char)((uint)iVar8 >> 8);
      i2d_X509(*(X509 **)(param_1->cert + 0x3c),(uchar **)&local_5c);
      iVar8 = ssl_cipher_list_to_bytes
                        (param_1,*(undefined4 *)(param_1->session->krb5_client_princ + 0x2c),
                         local_5c,0);
      local_5c = (undefined4 *)((int)local_5c + iVar8);
      pcVar9[8] = (char)iVar8;
      pcVar9[7] = (char)((uint)iVar8 >> 8);
    }
    else {
      if (param_1->cert == (cert_st *)0x0) {
LAB_000854da:
        ssl2_return_error(param_1,2);
        ERR_put_error(0x14,0x72,0xb4,DAT_00085610,0x30b);
        goto LAB_00084e6a;
      }
      pcVar9[2] = '\0';
      pcVar9[3] = (char)((uint)param_1->version >> 8);
      iVar8 = param_1->version;
      pcVar9[5] = '\0';
      pcVar9[6] = '\0';
      pcVar9[4] = (char)iVar8;
      pcVar9[7] = '\0';
      pcVar9[8] = '\0';
    }
    pcVar9[9] = '\0';
    pcVar9[10] = '\x10';
    psVar15 = param_1->s2;
    psVar15->conn_id_length = 0x10;
    iVar8 = RAND_pseudo_bytes(psVar15->conn_id,0x10);
    if (iVar8 < 1) goto LAB_00084e6a;
    psVar15 = param_1->s2;
    uVar24 = *(undefined4 *)psVar15->conn_id;
    uVar12 = *(undefined4 *)(psVar15->conn_id + 8);
    uVar23 = *(undefined4 *)(psVar15->conn_id + 0xc);
    local_5c[1] = *(undefined4 *)(psVar15->conn_id + 4);
    *local_5c = uVar24;
    local_5c[2] = uVar12;
    local_5c[3] = uVar23;
    param_1->state = 0x2021;
    local_5c = local_5c + 4;
    pcVar9 = param_1->init_buf->data;
    param_1->init_off = 0;
    param_1->init_num = (int)local_5c - (int)pcVar9;
  }
  if ((param_1->hit == 0) || (iVar8 = ssl_init_wbio_buffer(param_1,1), iVar8 != 0)) {
    iVar8 = ssl2_do_write(param_1);
    if (0 < iVar8) {
      param_1->init_num = 0;
      if (param_1->hit == 0) {
        uVar20 = 0x2030;
        param_1->state = 0x2030;
      }
      else {
        uVar20 = 0x2080;
        param_1->state = 0x2080;
      }
      goto LAB_000844ce;
    }
    goto LAB_000846ca;
  }
LAB_00084e6a:
  iVar8 = -1;
LAB_000846ca:
  param_1->in_handshake = param_1->in_handshake + -1;
  if (p_Var19 != (_func_3294 *)0x0) {
LAB_000846d2:
    (*p_Var19)(param_1,0x2002,iVar8);
  }
  return iVar8;
LAB_00084912:
  param_1->server = 1;
  if (p_Var19 != (_func_3294 *)0x0) {
    (*p_Var19)(param_1,0x10,1);
  }
  param_1->version = 2;
  param_1->type = 0x2000;
  if (param_1->init_buf == (BUF_MEM *)0x0) {
    pBVar13 = BUF_MEM_new();
    if (pBVar13 == (BUF_MEM *)0x0) goto LAB_00084e6a;
    iVar8 = BUF_MEM_grow(pBVar13,0x3fff);
    if (iVar8 == 0) {
      iVar8 = -1;
      BUF_MEM_free(pBVar13);
      goto LAB_000846ca;
    }
    param_1->init_buf = pBVar13;
  }
  param_1->init_num = 0;
  uVar20 = 0x2010;
  *(int *)(param_1->psk_server_callback + 0x40) = *(int *)(param_1->psk_server_callback + 0x40) + 1;
  param_1->handshake_func = p_Var5;
  param_1->state = 0x2010;
  goto LAB_000844ce;
}

