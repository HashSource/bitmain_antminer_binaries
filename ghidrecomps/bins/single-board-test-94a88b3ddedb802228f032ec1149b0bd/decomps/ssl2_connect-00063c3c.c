
int ssl2_connect(SSL *param_1)

{
  char cVar1;
  _STACK *p_Var2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  stack_st_SSL_CIPHER *psVar8;
  _STACK *st;
  _STACK *p_Var9;
  void *pvVar10;
  undefined4 uVar11;
  X509 *x;
  EVP_PKEY *pkey;
  int iVar12;
  undefined4 uVar13;
  char *pcVar14;
  uchar uVar15;
  uint uVar16;
  SSL_SESSION *pSVar17;
  uchar uVar18;
  size_t sVar19;
  ssl2_state_st *psVar20;
  _func_3296 *p_Var21;
  BUF_MEM *str;
  undefined4 uVar22;
  char *pcVar23;
  undefined4 *__dest;
  SSL_SESSION *pSVar24;
  undefined4 *puVar25;
  uchar *puVar26;
  _func_3294 *p_Var27;
  uchar *to;
  undefined4 in_stack_ffffff78;
  undefined4 in_stack_ffffff7c;
  int local_60;
  time_t local_54;
  uchar *local_50;
  uint local_4c;
  X509 *local_48;
  EVP_PKEY *local_44;
  EVP_MD_CTX EStack_40;
  
  local_54 = time((time_t *)0x0);
  RAND_add(&local_54,4,(double)CONCAT44(in_stack_ffffff7c,in_stack_ffffff78));
  ERR_clear_error();
  piVar3 = __errno_location();
  p_Var27 = param_1->info_callback;
  *piVar3 = 0;
  if (p_Var27 == (_func_3294 *)0x0) {
    p_Var27 = *(_func_3294 **)(param_1->psk_server_callback + 0x9c);
  }
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar4 = SSL_state(param_1);
  if (((uVar4 & 0x3000) == 0) || (iVar5 = SSL_state(param_1), iVar5 << 0x11 < 0)) {
    SSL_clear(param_1);
  }
  iVar5 = param_1->state;
  if (0x1041 < iVar5) goto LAB_00063cdc;
LAB_00063c9e:
  if (0x103f < iVar5) {
    if (iVar5 == 0x1040) {
      pcVar23 = param_1->init_buf->data;
      *pcVar23 = '\x03';
      sVar19 = param_1->s2->conn_id_length;
      if (0x10 < sVar19) {
        iVar6 = -1;
        ERR_put_error(0x14,0xa7,0x44,DAT_00064af4,0x2c8);
        goto LAB_00064096;
      }
      memcpy(pcVar23 + 1,param_1->s2->conn_id,sVar19);
      param_1->state = 0x1041;
      uVar4 = param_1->s2->conn_id_length;
      param_1->init_off = 0;
      param_1->init_num = uVar4 + 1;
    }
    iVar6 = ssl2_do_write(param_1);
    if (0 < iVar6) {
      iVar6 = 0x1060;
      param_1->init_num = 0;
      param_1->state = 0x1060;
      goto LAB_00063cc0;
    }
    goto LAB_00064096;
  }
  if (0x1011 < iVar5) {
    if (iVar5 < 0x1020) {
LAB_00063e6c:
      ERR_put_error(0x14,0x7b,0xff,DAT_00063ef8,0x139);
      return -1;
    }
    if (iVar5 < 0x1022) {
      pcVar23 = param_1->init_buf->data;
      if (iVar5 == 0x1020) {
        iVar6 = ssl2_read(param_1,pcVar23 + param_1->init_num,0xb - param_1->init_num);
        if (iVar6 < 0xb - param_1->init_num) {
LAB_00064364:
          iVar6 = ssl2_part_read(param_1,0x6d,iVar6);
          if (0 < iVar6) {
LAB_00063fcc:
            param_1->init_num = 0;
            if (param_1->hit == 0) {
              iVar6 = 0x1030;
              param_1->state = 0x1030;
            }
            else {
              iVar6 = 0x1080;
              param_1->state = 0x1080;
            }
LAB_00063cc0:
            if (p_Var27 == (_func_3294 *)0x0) goto LAB_00063cd6;
            if (iVar6 == iVar5) goto LAB_00063cd6;
            do {
              param_1->state = iVar5;
              (*p_Var27)(param_1,0x1001,1);
              param_1->state = iVar6;
LAB_00063cd6:
              do {
                iVar5 = iVar6;
                if (iVar6 < 0x1042) goto LAB_00063c9e;
LAB_00063cdc:
                iVar6 = 0x1071;
                if (iVar5 < 0x1072) {
                  if (iVar5 < 0x1070) {
                    if (iVar5 < 0x1050) goto LAB_00063e6c;
                    if (iVar5 < 0x1054) goto LAB_00063e9a;
                    if (1 < iVar5 - 0x1060U) goto LAB_00063e6c;
                    iVar6 = param_1->init_num;
                    pcVar23 = param_1->init_buf->data;
                    if (iVar5 == 0x1060) {
                      iVar6 = ssl2_read(param_1,pcVar23 + iVar6,1 - iVar6);
                      if (1 - param_1->init_num <= iVar6) {
                        iVar6 = iVar6 + param_1->init_num;
                        param_1->init_num = iVar6;
                        param_1->state = 0x1061;
                        if (*pcVar23 == '\x05') {
                          pcVar23 = param_1->init_buf->data;
                          goto LAB_00064150;
                        }
                        if (*pcVar23 != '\0') {
                          ssl2_return_error(param_1,0);
                          ERR_put_error(0x14,0x6e,0xd4,DAT_00064af4,0x37b);
                          goto LAB_00064520;
                        }
                        ERR_put_error(0x14,0x6e,200,DAT_000643e0,0x37d);
                        iVar6 = ssl2_read(param_1,pcVar23 + param_1->init_num,3 - param_1->init_num)
                        ;
                      }
LAB_000643c8:
                      iVar6 = ssl2_part_read(param_1,0x6e,iVar6);
                      goto LAB_00063eda;
                    }
LAB_00064150:
                    sVar19 = param_1->s2->challenge_length + 1;
                    iVar7 = sVar19 - iVar6;
                    iVar6 = ssl2_read(param_1,pcVar23 + iVar6,iVar7);
                    if (iVar6 < iVar7) goto LAB_000643c8;
                    if (param_1->msg_callback != (_func_3292 *)0x0) {
                      (*param_1->msg_callback)
                                (0,param_1->version,0,pcVar23,sVar19,param_1,
                                 param_1->msg_callback_arg);
                    }
                    iVar6 = CRYPTO_memcmp(pcVar23 + 1,param_1->s2->challenge,
                                          param_1->s2->challenge_length);
                    if (iVar6 == 0) goto LAB_00063ee0;
                    ssl2_return_error(param_1,0);
                    ERR_put_error(0x14,0x6e,0x88,DAT_000643e0,0x394);
                    goto LAB_00064520;
                  }
                  pcVar23 = param_1->init_buf->data;
                  if (iVar5 == 0x1070) {
                    iVar7 = ssl2_read(param_1,pcVar23 + param_1->init_num,1 - param_1->init_num);
                    if (iVar7 < 1 - param_1->init_num) goto LAB_0006456c;
                    iVar12 = iVar7 + param_1->init_num;
                    param_1->init_num = iVar12;
                    cVar1 = *pcVar23;
                    if (cVar1 == '\a') {
                      iVar6 = 0x1050;
                    }
                    if (cVar1 == '\a') {
                      param_1->state = iVar6;
                      goto LAB_00063cc0;
                    }
                    if (cVar1 == '\x06') {
                      param_1->state = iVar6;
                      goto LAB_00063cfa;
                    }
                    if (cVar1 != '\0') {
                      ssl2_return_error(param_1,0);
                      ERR_put_error(0x14,0x6c,0xd4,DAT_00064af4,0x3af);
                      goto LAB_00064520;
                    }
                    ERR_put_error(0x14,0x6c,200,DAT_000643e0,0x3b1);
                    uVar11 = ssl2_read(param_1,pcVar23 + param_1->init_num,3 - param_1->init_num);
                    iVar6 = ssl2_part_read(param_1,0x6e,uVar11);
                  }
                  else {
                    iVar12 = param_1->init_num;
LAB_00063cfa:
                    iVar7 = ssl2_read(param_1,pcVar23 + iVar12,0x11 - iVar12);
                    if (0x11 - iVar12 <= iVar7) {
                      sVar19 = iVar7 + param_1->init_num;
                      param_1->init_num = sVar19;
                      if (param_1->msg_callback != (_func_3292 *)0x0) {
                        (*param_1->msg_callback)
                                  (0,param_1->version,0,pcVar23,sVar19,param_1,
                                   param_1->msg_callback_arg);
                      }
                      if (param_1->hit == 0) {
                        pSVar17 = param_1->session;
                        pSVar17->session_id_length = 0x10;
                        uVar22 = *(undefined4 *)(pcVar23 + 5);
                        uVar11 = *(undefined4 *)(pcVar23 + 9);
                        uVar13 = *(undefined4 *)(pcVar23 + 0xd);
                        *(undefined4 *)pSVar17->session_id = *(undefined4 *)(pcVar23 + 1);
                        *(undefined4 *)(pSVar17->session_id + 4) = uVar22;
                        *(undefined4 *)(pSVar17->session_id + 8) = uVar11;
                        *(undefined4 *)(pSVar17->session_id + 0xc) = uVar13;
                      }
                      else if (-1 < param_1->references << 0x1f) {
                        sVar19 = param_1->session->session_id_length;
                        if ((0x20 < sVar19) ||
                           (iVar6 = memcmp(pcVar23 + 1,param_1->session->session_id,sVar19),
                           iVar6 != 0)) {
                          ssl2_return_error(param_1,0);
                          ERR_put_error(0x14,0x6c,0xe7,DAT_00064af4,0x3de);
                          goto LAB_00064520;
                        }
                      }
                      iVar6 = 3;
                      param_1->state = 3;
                      goto LAB_00063cc0;
                    }
LAB_0006456c:
                    iVar6 = ssl2_part_read(param_1,0x6c,iVar7);
                  }
                  if (iVar6 < 1) goto LAB_00064096;
                  iVar6 = param_1->state;
                  goto LAB_00063cc0;
                }
                if (iVar5 == 0x1090) {
LAB_00063e9a:
                  puVar26 = (uchar *)param_1->init_buf->data;
                  if (iVar5 == 0x1050) {
                    iVar6 = ssl2_read(param_1,puVar26 + param_1->init_num,0x22 - param_1->init_num);
                    if (0x12 - param_1->init_num <= iVar6) {
                      sVar19 = iVar6 + param_1->init_num;
                      param_1->init_num = sVar19;
                      if (param_1->msg_callback != (_func_3292 *)0x0) {
                        (*param_1->msg_callback)
                                  (0,param_1->version,0,puVar26,sVar19,param_1,
                                   param_1->msg_callback_arg);
                      }
                      if (puVar26[1] == '\x01') {
                        if ((((int **)param_1->cert == (int **)0x0) ||
                            (piVar3 = *(int **)param_1->cert, *piVar3 == 0)) || (piVar3[1] == 0)) {
                          param_1->state = 0x1090;
                          sVar19 = param_1->init_num - 2;
                          goto LAB_00064534;
                        }
                        param_1->state = 0x1052;
                        sVar19 = param_1->init_num - 2;
                        goto LAB_000645ec;
                      }
                      ssl2_return_error(param_1,6);
                      ERR_put_error(0x14,100,0x66,DAT_00064af4,0x2f5);
                      goto LAB_00064520;
                    }
                    iVar6 = ssl2_part_read(param_1,100,iVar6);
                  }
                  else {
                    iVar6 = 0x1090;
                    if (iVar5 != 0x1090) {
                      iVar6 = iVar5;
                    }
                    sVar19 = param_1->init_num - 2;
                    if (iVar5 == 0x1090) {
LAB_00064534:
                      local_48 = (X509 *)0x0;
                      local_44 = (EVP_PKEY *)0x0;
                      if (*(code **)(param_1->psk_server_callback + 0x74) == (code *)0x0) {
                        param_1->rwstate = 1;
                        goto LAB_00064728;
                      }
                      iVar6 = (**(code **)(param_1->psk_server_callback + 0x74))
                                        (param_1,&local_48,&local_44);
                      if (iVar6 < 0) {
                        param_1->rwstate = 4;
                        goto LAB_00064520;
                      }
                      param_1->rwstate = 1;
                      if (iVar6 == 1) {
                        if (local_44 == (EVP_PKEY *)0x0) {
                          if ((local_48 != (X509 *)0x0) &&
                             (X509_free(local_48), local_44 != (EVP_PKEY *)0x0)) goto LAB_00064712;
                        }
                        else {
                          if (local_48 != (X509 *)0x0) {
                            param_1->state = 0x1052;
                            iVar6 = SSL_use_certificate(param_1,local_48);
                            if ((iVar6 != 0) &&
                               (iVar6 = SSL_use_PrivateKey(param_1,local_44), iVar6 != 0)) {
                              iVar6 = 1;
                            }
                            X509_free(local_48);
                            EVP_PKEY_free(local_44);
                            goto LAB_00064560;
                          }
LAB_00064712:
                          EVP_PKEY_free(local_44);
                        }
                        ERR_put_error(0x14,100,0x6a,DAT_00064790,0x326);
LAB_00064728:
                        param_1->state = 0x1051;
                        *puVar26 = '\0';
                        puVar26[1] = '\0';
                        puVar26[2] = '\x02';
                        param_1->init_off = 0;
                        param_1->init_num = 3;
                        local_50 = puVar26 + 3;
                      }
                      else {
LAB_00064560:
                        if (iVar6 == 0) goto LAB_00064728;
                      }
                      iVar6 = param_1->state;
                    }
                    if ((iVar6 != 0x1051) && (iVar6 == 0x1052)) {
LAB_000645ec:
                      local_50 = puVar26;
                      EVP_MD_CTX_init(&EStack_40);
                      EVP_DigestInit_ex(&EStack_40,*(EVP_MD **)(param_1->psk_server_callback + 0x88)
                                        ,(ENGINE *)0x0);
                      EVP_DigestUpdate(&EStack_40,param_1->s2->key_material,
                                       param_1->s2->key_material_length);
                      EVP_DigestUpdate(&EStack_40,puVar26 + 2,sVar19);
                      sVar19 = i2d_X509(**(X509 ***)
                                          (*(int *)(param_1->session->krb5_client_princ + 8) + 8),
                                        &local_50);
                      if (0 < (int)sVar19) {
                        EVP_DigestUpdate(&EStack_40,puVar26,sVar19);
                      }
                      local_44 = (EVP_PKEY *)(puVar26 + 6);
                      puVar26[1] = '\x01';
                      *puVar26 = '\b';
                      local_50 = puVar26 + 2;
                      local_4c = i2d_X509(**(X509 ***)param_1->cert,(uchar **)&local_44);
                      *local_50 = (uchar)(local_4c >> 8);
                      local_50[1] = (uchar)local_4c;
                      local_50 = local_50 + 2;
                      EVP_SignFinal(&EStack_40,(uchar *)local_44,&local_4c,
                                    *(EVP_PKEY **)(*(int *)param_1->cert + 4));
                      EVP_MD_CTX_cleanup(&EStack_40);
                      *local_50 = (uchar)(local_4c >> 8);
                      local_50[1] = (uchar)local_4c;
                      param_1->state = 0x1053;
                      local_44 = (EVP_PKEY *)((int)&local_44->type + local_4c);
                      param_1->init_off = 0;
                      local_50 = local_50 + 2;
                      param_1->init_num = (int)local_44 - (int)puVar26;
                    }
                    iVar6 = ssl2_do_write(param_1);
                  }
LAB_00063eda:
                  if (iVar6 < 1) goto LAB_00064096;
LAB_00063ee0:
                  iVar6 = 0x1070;
                  param_1->init_num = 0;
                  param_1->state = 0x1070;
                  goto LAB_00063cc0;
                }
                if (0x1090 < iVar5) {
                  if ((iVar5 == 0x4000) || (iVar5 == 0x5000)) goto LAB_00063fee;
                  goto LAB_00063e6c;
                }
                if (iVar5 != 0x1080) goto LAB_00063e6c;
                iVar6 = ssl2_enc_init(param_1,1);
                if (iVar6 == 0) goto LAB_00064520;
                iVar6 = 0x1040;
                param_1->s2->clear_text = 0;
                param_1->state = 0x1040;
              } while (p_Var27 == (_func_3294 *)0x0);
            } while( true );
          }
          goto LAB_00064096;
        }
        param_1->init_num = 0xb;
        if (*pcVar23 == '\x04') {
          uVar4 = (uint)(byte)pcVar23[1];
          psVar20 = param_1->s2;
          iVar6 = param_1->version;
          if (uVar4 != 0) {
            uVar4 = 1;
          }
          param_1->hit = uVar4;
          (psVar20->tmp).cert_type = (uint)(byte)pcVar23[2];
          if ((int)(uint)CONCAT11(pcVar23[3],pcVar23[4]) < iVar6) {
            param_1->version = (uint)CONCAT11(pcVar23[3],pcVar23[4]);
          }
          (psVar20->tmp).cert_length = (uint)CONCAT11(pcVar23[5],pcVar23[6]);
          (psVar20->tmp).csl = (uint)CONCAT11(pcVar23[7],pcVar23[8]);
          (psVar20->tmp).conn_id_length = (uint)CONCAT11(pcVar23[9],pcVar23[10]);
          param_1->state = 0x1021;
          goto LAB_00063f1a;
        }
        if (*pcVar23 == '\0') {
          ERR_put_error(0x14,0x6d,200,DAT_00064af4,0x163);
        }
        else {
          ssl2_return_error(param_1,0);
          ERR_put_error(0x14,0x6d,0xd4,DAT_00064790,0x161);
        }
      }
      else {
        psVar20 = param_1->s2;
LAB_00063f1a:
        uVar4 = (psVar20->tmp).cert_length + (psVar20->tmp).csl + 0xb +
                (psVar20->tmp).conn_id_length;
        if (0x3fff < uVar4) {
          ERR_put_error(0x14,0x6d,0x128,DAT_00064af4,0x184);
          goto LAB_00064520;
        }
        iVar7 = uVar4 - param_1->init_num;
        iVar6 = ssl2_read(param_1,pcVar23 + param_1->init_num,iVar7);
        if (iVar7 != iVar6) goto LAB_00064364;
        if (param_1->msg_callback != (_func_3292 *)0x0) {
          (*param_1->msg_callback)
                    (0,param_1->version,0,pcVar23,uVar4,param_1,param_1->msg_callback_arg);
        }
        pcVar23 = pcVar23 + 0xb;
        if (param_1->hit == 0) {
          if ((param_1->session->session_id_length != 0) &&
             (iVar6 = ssl_get_new_session(param_1), iVar6 == 0)) goto LAB_000647e4;
          iVar6 = ssl2_set_certificate
                            (param_1,(param_1->s2->tmp).cert_type,(param_1->s2->tmp).cert_length,
                             pcVar23);
          if (iVar6 < 1) {
            ssl2_return_error(param_1,4);
            goto LAB_00064520;
          }
          uVar4 = (param_1->s2->tmp).cert_length;
          uVar16 = (param_1->s2->tmp).csl;
          if (uVar16 == 0) {
            ssl2_return_error(param_1,1);
            ERR_put_error(0x14,0x6d,0xb8,DAT_00064af4,0x1c1);
            goto LAB_00064520;
          }
          st = (_STACK *)
               ssl_bytes_to_cipher_list
                         (param_1,pcVar23 + uVar4,uVar16,param_1->session->krb5_client_princ + 0x2c)
          ;
          pcVar23 = pcVar23 + uVar4 + (param_1->s2->tmp).csl;
          if (st == (_STACK *)0x0) {
            ssl2_return_error(param_1,0);
            ERR_put_error(0x14,0x6d,0x41,DAT_00064b54,0x1d1);
            goto LAB_00064520;
          }
          iVar6 = 0;
          sk_set_cmp_func(st,DAT_000643e4);
          p_Var9 = &SSL_get_ciphers(param_1)->stack;
          sk_set_cmp_func(p_Var9,DAT_000643e4);
          p_Var2 = p_Var9;
          if (param_1->references << 9 < 0) {
            p_Var2 = st;
            st = p_Var9;
          }
          for (; iVar7 = sk_num(p_Var2), iVar6 < iVar7; iVar6 = iVar6 + 1) {
            pvVar10 = sk_value(p_Var2,iVar6);
            iVar7 = sk_find(st,pvVar10);
            if (-1 < iVar7) break;
          }
          iVar7 = sk_num(p_Var2);
          if (iVar7 <= iVar6) {
            ssl2_return_error(param_1,1);
            ERR_put_error(0x14,0x6d,0xb9,DAT_00064af4,500);
            goto LAB_00064520;
          }
          pSVar24 = param_1->session;
          pvVar10 = sk_value(p_Var2,iVar6);
          pSVar17 = param_1->session;
          *(void **)(pSVar24->krb5_client_princ + 0x24) = pvVar10;
          pcVar14 = DAT_000643e0;
          if (*(int *)(pSVar17->krb5_client_princ + 0xc) == 0) {
            iVar6 = **(int **)(*(int *)(pSVar17->krb5_client_princ + 8) + 8);
            *(int *)(pSVar17->krb5_client_princ + 0xc) = iVar6;
            CRYPTO_add_lock((int *)(iVar6 + 0x10),1,3,pcVar14,0x201);
            goto LAB_00063f98;
          }
          ssl2_return_error(param_1,0);
          iVar5 = 0x1fb;
        }
        else {
          psVar20 = param_1->s2;
          if ((psVar20->tmp).cert_length != 0) {
            ERR_put_error(0x14,0x6d,0xd8,DAT_00064b54,0x196);
            goto LAB_00064520;
          }
          if ((psVar20->tmp).cert_type != 0) {
            ERR_put_error(0x14,0x6d,0xd9,DAT_00064b54,0x19c);
            goto LAB_00064520;
          }
          if ((psVar20->tmp).csl != 0) {
            ERR_put_error(0x14,0x6d,0xda,DAT_00064af4,0x1a1);
            goto LAB_00064520;
          }
LAB_00063f98:
          iVar6 = *(int *)(param_1->session->krb5_client_princ + 8);
          if ((iVar6 != 0) &&
             (*(int *)(param_1->session->krb5_client_princ + 0xc) == **(int **)(iVar6 + 8))) {
            psVar20 = param_1->s2;
            sVar19 = (psVar20->tmp).conn_id_length;
            psVar20->conn_id_length = sVar19;
            if (sVar19 < 0x11) {
              memcpy(psVar20->conn_id,pcVar23,sVar19);
              goto LAB_00063fcc;
            }
            ssl2_return_error(param_1,0);
            ERR_put_error(0x14,0x6d,299,DAT_00064af4,0x210);
            goto LAB_00064520;
          }
          ssl2_return_error(param_1,0);
          iVar5 = 0x209;
        }
        ERR_put_error(0x14,0x6d,0x44,DAT_00064af4,iVar5);
      }
    }
    else {
      if (1 < iVar5 - 0x1030U) goto LAB_00063e6c;
      pcVar23 = param_1->init_buf->data;
      if (iVar5 != 0x1030) {
LAB_0006411e:
        iVar6 = ssl2_do_write(param_1);
        if (0 < iVar6) {
          param_1->init_num = 0;
          iVar6 = 0x1080;
          param_1->state = 0x1080;
          goto LAB_00063cc0;
        }
        goto LAB_00064096;
      }
      iVar6 = ssl_cipher_get_evp(param_1->session,&local_48,&local_44,0,0,0);
      if (iVar6 == 0) {
        ssl2_return_error(param_1,1);
        ERR_put_error(0x14,0x66,0xce,DAT_00064af4,0x264);
      }
      else {
        pSVar17 = param_1->session;
        pcVar14 = pcVar23 + 10;
        puVar26 = (uchar *)(pcVar23 + 1);
        *pcVar23 = '\x02';
        iVar6 = (*param_1->method->put_cipher_by_char)
                          (*(SSL_CIPHER **)(pSVar17->krb5_client_princ + 0x24),puVar26);
        uVar4 = EVP_CIPHER_iv_length((EVP_CIPHER *)local_48);
        pSVar17->key_arg_length = uVar4;
        if ((int)uVar4 < 9) {
          if ((0 < (int)uVar4) && (iVar7 = RAND_pseudo_bytes(pSVar17->key_arg,uVar4), iVar7 < 1))
          goto LAB_00064520;
          iVar7 = EVP_CIPHER_key_length((EVP_CIPHER *)local_48);
          pSVar17->master_key_length = iVar7;
          if (0 < iVar7) {
            if (0x30 < iVar7) {
              ssl2_return_error(param_1,0);
              iVar5 = 0x281;
              goto LAB_000649ce;
            }
            iVar12 = RAND_bytes(pSVar17->master_key,iVar7);
            if (iVar12 < 1) goto LAB_000647e4;
          }
          if (*(int *)(*(int *)(pSVar17->krb5_client_princ + 0x24) + 0x24) << 0x1e < 0) {
            iVar12 = 8;
            local_60 = 8;
LAB_00064490:
            if (iVar7 < iVar12) {
              ssl2_return_error(param_1,0);
              ERR_put_error(0x14,0x66,0x8b,DAT_00064af4,0x293);
              goto LAB_00064520;
            }
            sVar19 = iVar7 - iVar12;
            uVar18 = (uchar)sVar19;
            uVar15 = (uchar)(sVar19 * 0x10000 >> 0x18);
          }
          else {
            if ((*(uint *)(*(int *)(pSVar17->krb5_client_princ + 0x24) + 0x20) & 2) != 0) {
              iVar12 = 5;
              local_60 = 5;
              goto LAB_00064490;
            }
            uVar15 = '\0';
            uVar18 = '\0';
            sVar19 = 0;
            local_60 = iVar7;
          }
          puVar26[iVar6] = uVar15;
          puVar26[iVar6 + 1] = uVar18;
          memcpy(pcVar14,pSVar17->master_key,sVar19);
          if (param_1->s2->ssl2_rollback == 0) {
            iVar7 = 1;
          }
          else {
            iVar7 = 2;
          }
          if (((*(int *)(pSVar17->krb5_client_princ + 8) == 0) ||
              (x = **(X509 ***)(*(int *)(pSVar17->krb5_client_princ + 8) + 8), x == (X509 *)0x0)) ||
             (pkey = X509_get_pubkey(x), pkey == (EVP_PKEY *)0x0)) {
            ERR_put_error(0x14,0xbc,0xc0,DAT_00064af4,0x430);
          }
          else {
            if (pkey->type == 6) {
              to = (uchar *)(pcVar14 + sVar19);
              iVar7 = RSA_public_encrypt(local_60,pSVar17->master_key + sVar19,to,(pkey->pkey).rsa,
                                         iVar7);
              if (-1 < iVar7) {
                EVP_PKEY_free(pkey);
                if (iVar7 != 0) {
                  puVar26[iVar6 + 3] = (uchar)iVar7;
                  puVar26[iVar6 + 2] = (uchar)((uint)iVar7 >> 8);
                  sVar19 = pSVar17->key_arg_length;
                  puVar26[iVar6 + 5] = (uchar)sVar19;
                  puVar26[iVar6 + 4] = (uchar)(sVar19 >> 8);
                  if ((int)sVar19 < 9) {
                    memcpy(to + iVar7,pSVar17->key_arg,sVar19);
                    param_1->state = 0x1031;
                    param_1->init_num = (int)(to + iVar7 + (sVar19 - (int)pcVar23));
                    param_1->init_off = 0;
                    goto LAB_0006411e;
                  }
                  ssl2_return_error(param_1,0);
                  iVar5 = 0x2b1;
                  goto LAB_000649ce;
                }
                goto LAB_00064506;
              }
              ERR_put_error(0x14,0xbc,4,DAT_00064af4,0x43b);
            }
            else {
              ERR_put_error(0x14,0xbc,0xd1,DAT_00064790,0x434);
            }
            EVP_PKEY_free(pkey);
          }
LAB_00064506:
          ssl2_return_error(param_1,0);
          ERR_put_error(0x14,0x66,0xd0,DAT_00064790,0x2a2);
        }
        else {
          ssl2_return_error(param_1,0);
          iVar5 = 0x274;
LAB_000649ce:
          ERR_put_error(0x14,0x66,0x44,DAT_00064af4,iVar5);
        }
      }
    }
LAB_00064520:
    iVar6 = -1;
LAB_00064096:
    param_1->in_handshake = param_1->in_handshake + -1;
LAB_0006409c:
    if (p_Var27 != (_func_3294 *)0x0) {
      (*p_Var27)(param_1,0x1002,iVar6);
    }
    return iVar6;
  }
  if (iVar5 < 0x1010) {
    if (iVar5 == 0x1000) goto LAB_00063fee;
    if (iVar5 == 0x1003) goto LAB_00063fee;
    if (iVar5 != 3) goto LAB_00063e6c;
    if (param_1->init_buf != (BUF_MEM *)0x0) {
      BUF_MEM_free(param_1->init_buf);
      param_1->init_buf = (BUF_MEM *)0x0;
    }
    param_1->init_num = 0;
    ssl_update_cache(param_1,1);
    if (param_1->hit == 0) {
      p_Var21 = param_1->psk_server_callback;
    }
    else {
      p_Var21 = param_1->psk_server_callback;
      *(int *)(p_Var21 + 0x58) = *(int *)(p_Var21 + 0x58) + 1;
    }
    iVar6 = 1;
    *(int *)(p_Var21 + 0x3c) = *(int *)(p_Var21 + 0x3c) + 1;
    if (p_Var27 != (_func_3294 *)0x0) {
      iVar6 = 1;
      (*p_Var27)(param_1,0x20,1);
    }
    goto LAB_00064096;
  }
  param_1->shutdown = 0;
  pcVar23 = param_1->init_buf->data;
  if (iVar5 == 0x1010) {
    if (((param_1->session == (SSL_SESSION *)0x0) ||
        (param_1->session->ssl_version != param_1->version)) &&
       (iVar6 = ssl_get_new_session(param_1,0), iVar6 == 0)) {
LAB_000647e4:
      ssl2_return_error(param_1,0);
      goto LAB_00064520;
    }
    *pcVar23 = '\x01';
    pcVar23[2] = '\x02';
    pcVar23[1] = '\0';
    psVar8 = SSL_get_ciphers(param_1);
    iVar6 = ssl_cipher_list_to_bytes(param_1,psVar8,pcVar23 + 9,0);
    __dest = (undefined4 *)(pcVar23 + 9 + iVar6);
    if (iVar6 == 0) {
      ERR_put_error(0x14,0x65,0xb5,DAT_00064af4,0x232);
      goto LAB_00064520;
    }
    pcVar23[4] = (char)iVar6;
    pcVar23[3] = (char)((uint)iVar6 >> 8);
    sVar19 = param_1->session->session_id_length;
    if (sVar19 - 1 < 0x20) {
      pcVar23[5] = '\0';
      pcVar23[6] = (char)sVar19;
      puVar25 = (undefined4 *)((int)__dest + sVar19);
      memcpy(__dest,param_1->session->session_id,sVar19);
    }
    else {
      pcVar23[5] = '\0';
      pcVar23[6] = '\0';
      puVar25 = __dest;
    }
    param_1->s2->challenge_length = 0x10;
    pcVar23[8] = '\x10';
    pcVar23[7] = '\0';
    iVar6 = RAND_pseudo_bytes(param_1->s2->challenge,0x10);
    if (iVar6 < 1) goto LAB_00064520;
    psVar20 = param_1->s2;
    uVar11 = *(undefined4 *)(psVar20->challenge + 4);
    uVar13 = *(undefined4 *)(psVar20->challenge + 8);
    uVar22 = *(undefined4 *)(psVar20->challenge + 0xc);
    *puVar25 = *(undefined4 *)psVar20->challenge;
    puVar25[1] = uVar11;
    puVar25[2] = uVar13;
    puVar25[3] = uVar22;
    param_1->init_num = (int)((int)puVar25 + (0x10 - (int)pcVar23));
    param_1->init_off = 0;
    param_1->state = 0x1011;
  }
  iVar6 = ssl2_do_write(param_1);
  if (0 < iVar6) {
    param_1->init_num = 0;
    iVar6 = 0x1020;
    param_1->state = 0x1020;
    goto LAB_00063cc0;
  }
  goto LAB_00064096;
LAB_00063fee:
  param_1->server = 0;
  if (p_Var27 != (_func_3294 *)0x0) {
    (*p_Var27)(param_1,0x10,1);
  }
  str = param_1->init_buf;
  param_1->version = 2;
  param_1->type = 0x1000;
  if ((str == (BUF_MEM *)0x0) && (str = BUF_MEM_new(), str == (BUF_MEM *)0x0)) goto LAB_00064520;
  iVar6 = BUF_MEM_grow(str,0x3fff);
  if (iVar6 == 0) {
    if (str == param_1->init_buf) goto LAB_00064520;
    iVar6 = -1;
    param_1->in_handshake = param_1->in_handshake + -1;
    BUF_MEM_free(str);
    goto LAB_0006409c;
  }
  param_1->init_num = 0;
  param_1->init_buf = str;
  iVar6 = 0x1010;
  iVar7 = *(int *)(param_1->psk_server_callback + 0x34);
  param_1->state = 0x1010;
  *(int *)(param_1->psk_server_callback + 0x34) = iVar7 + 1;
  param_1->handshake_func = ssl2_connect;
  goto LAB_00063cc0;
}

