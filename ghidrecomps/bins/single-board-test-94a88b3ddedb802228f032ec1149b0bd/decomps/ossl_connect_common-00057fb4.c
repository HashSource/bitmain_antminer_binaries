
/* WARNING: Type propagation algorithm not settling */

int ossl_connect_common(int *param_1,int param_2,int param_3,undefined *param_4)

{
  byte *pbVar1;
  char cVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  SSL_METHOD *meth;
  SSL_CTX *ctx;
  int *piVar7;
  BIO_METHOD *pBVar8;
  BIO *fp;
  X509 *pXVar9;
  X509_NAME *pXVar10;
  long lVar11;
  _STACK *p_Var12;
  uchar *puVar13;
  size_t sVar14;
  int iVar15;
  ulong uVar16;
  PKCS12 *p12;
  BIO *out;
  ASN1_INTEGER *pAVar17;
  EVP_PKEY *pEVar18;
  _STACK *p_Var19;
  FILE *pFVar20;
  OCSP_RESPONSE *resp;
  char *pcVar21;
  size_t sVar22;
  SSL *pSVar23;
  evp_pkey_st *from;
  UI_METHOD *method;
  UI_METHOD *pUVar24;
  opener *opener;
  closer *closer;
  X509_LOOKUP_METHOD *m;
  X509_LOOKUP *ctx_00;
  OCSP_BASICRESP *bs;
  stack_st_X509 *certs;
  X509_STORE *pXVar25;
  OCSP_SINGLERESP *single;
  char *pcVar26;
  X509_NAME_ENTRY *ne;
  ASN1_STRING *x;
  uint uVar27;
  SSL_SESSION *pSVar28;
  X509_CINF *pXVar29;
  ASN1_BIT_STRING *pAVar30;
  int iVar31;
  int iVar32;
  rsa_st *prVar33;
  int iVar34;
  int iVar35;
  int local_100;
  SSL_CTX *local_f8;
  char *local_f0;
  int local_e8;
  SSL_SESSION *local_dc;
  int local_d8;
  SSL_SESSION *local_d4;
  long local_d0;
  X509 *local_cc;
  EVP_PKEY *local_c8;
  _STACK *local_c4;
  char *local_c0;
  X509 *local_bc;
  undefined auStack_b8 [16];
  undefined local_a8;
  undefined4 local_a7;
  undefined4 local_a3;
  
  iVar34 = *param_1;
  iVar35 = param_1[param_2 + 0x55];
  if (param_1[param_2 * 6 + 0x5f] == 2) {
    *param_4 = 1;
    return 0;
  }
  pSVar28 = (SSL_SESSION *)param_1[param_2 * 6 + 0x60];
  if (pSVar28 == (SSL_SESSION *)0x0) {
    iVar5 = Curl_timeleft(iVar34,0,1);
    if (iVar5 < 0) {
LAB_00058078:
      Curl_failf(iVar34,DAT_000582a0);
      return 0x1c;
    }
    iVar31 = *param_1;
    iVar5 = param_1[param_2 + 0x55];
    local_d4 = pSVar28;
    Curl_ossl_seed(iVar31);
    *(undefined4 *)(iVar31 + 0x284) = 1;
    bVar4 = false;
    if (*(int *)(iVar31 + 0x280) == 2) {
      if (*(int *)(iVar31 + 0x2c0) == 1) {
        return 0x23;
      }
      meth = SSLv2_client_method();
    }
    else if (*(int *)(iVar31 + 0x280) == 3) {
      if (*(int *)(iVar31 + 0x2c0) == 1) {
        return 0x23;
      }
      meth = SSLv3_client_method();
    }
    else {
      bVar4 = true;
      meth = SSLv23_client_method();
    }
    if ((SSL_CTX *)param_1[param_2 * 6 + 0x61] != (SSL_CTX *)0x0) {
      SSL_CTX_free((SSL_CTX *)param_1[param_2 * 6 + 0x61]);
    }
    ctx = SSL_CTX_new(meth);
    param_1[param_2 * 6 + 0x61] = (int)ctx;
    if (ctx == (SSL_CTX *)0x0) {
      uVar16 = ERR_peek_error();
      pcVar21 = ERR_error_string(uVar16,(char *)0x0);
      Curl_failf(iVar31,DAT_000585cc,pcVar21);
      return 0x1b;
    }
    SSL_CTX_ctrl(ctx,0x21,0x10,(void *)0x0);
    if ((*(int *)(iVar31 + 0x1c8) != 0) && (*(char *)(iVar31 + 0x310) != '\0')) {
      SSL_CTX_set_msg_callback((SSL_CTX *)param_1[param_2 * 6 + 0x61],DAT_000582a4);
      SSL_CTX_ctrl((SSL_CTX *)param_1[param_2 * 6 + 0x61],0x10,0,param_1);
    }
    uVar27 = 0x800243f7;
    if (*(char *)(*param_1 + 0x32a) != '\0') {
      uVar27 = 0x80024bf7;
    }
    switch(*(undefined4 *)(iVar31 + 0x280)) {
    case 0:
    case 1:
      uVar27 = uVar27 | 0x3000000;
      break;
    case 2:
      uVar27 = uVar27 | 0x1e000000;
      break;
    case 3:
      if (*(int *)(iVar31 + 0x2c0) == 1) {
        Curl_infof(iVar31,DAT_00059658);
      }
      uVar27 = uVar27 | 0x1d000000;
      break;
    case 4:
      uVar27 = uVar27 | 0x1b000000;
      break;
    case 5:
      uVar27 = uVar27 | 0xf000000;
      break;
    case 6:
      uVar27 = uVar27 | 0x17000000;
      break;
    default:
      Curl_failf(iVar31,DAT_000582b4);
      return 0x23;
    }
    SSL_CTX_ctrl((SSL_CTX *)param_1[param_2 * 6 + 0x61],0x20,uVar27,(void *)0x0);
    if (*(char *)(iVar31 + 0x43c) != '\0') {
      SSL_CTX_set_next_proto_select_cb((SSL_CTX *)param_1[param_2 * 6 + 0x61],DAT_000585e0,param_1);
    }
    if (*(char *)(iVar31 + 0x43d) != '\0') {
      local_a8 = 8;
      local_a7 = *DAT_000585d8;
      local_a3 = DAT_000585d8[1];
      Curl_infof(iVar31,DAT_000585dc,DAT_000585d8);
      SSL_CTX_set_alpn_protos(param_1[param_2 * 6 + 0x61],&local_a8,9);
    }
    pcVar21 = *(char **)(iVar31 + 0x340);
    iVar6 = *(int *)(iVar31 + 0x344);
    if (pcVar21 == (char *)0x0) {
      if (iVar6 != 0) {
        local_f8 = (SSL_CTX *)param_1[param_2 * 6 + 0x61];
        local_f0 = *(char **)(iVar31 + 0x36c);
        local_e8 = *(int *)(iVar31 + 0x374);
        local_100 = *param_1;
        iVar32 = do_file_type(iVar6);
        if (iVar32 == 0x2a) goto LAB_000581b8;
      }
    }
    else {
      local_f8 = (SSL_CTX *)param_1[param_2 * 6 + 0x61];
      local_f0 = *(char **)(iVar31 + 0x36c);
      local_e8 = *(int *)(iVar31 + 0x374);
      local_100 = *param_1;
      iVar32 = do_file_type(iVar6);
LAB_000581b8:
      if (*(void **)(local_100 + 0x370) != (void *)0x0) {
        SSL_CTX_set_default_passwd_cb_userdata(local_f8,*(void **)(local_100 + 0x370));
        SSL_CTX_set_default_passwd_cb(local_f8,DAT_000582ac);
      }
      if (iVar32 == 2) {
        iVar6 = SSL_CTX_use_certificate_file(local_f8,pcVar21,2);
        if (iVar6 != 1) {
          uVar16 = ERR_get_error();
          pcVar21 = ERR_error_string(uVar16,(char *)0x0);
          Curl_failf(local_100,DAT_00058a28,pcVar21);
          return 0x3a;
        }
LAB_00058b1c:
        bVar3 = false;
      }
      else {
        if (iVar32 < 3) {
          if (iVar32 != 1) {
LAB_000581e2:
            Curl_failf(local_100,DAT_000582b0,iVar6);
            return 0x3a;
          }
          iVar6 = SSL_CTX_use_certificate_chain_file(local_f8,pcVar21);
          if (iVar6 != 1) {
            uVar16 = ERR_get_error();
            pcVar21 = ERR_error_string(uVar16,(char *)0x0);
            Curl_failf(local_100,DAT_00058ce8,pcVar21);
            return 0x3a;
          }
          goto LAB_00058b1c;
        }
        if (iVar32 == 0x2a) {
          if (*(ENGINE **)(local_100 + 0x8648) == (ENGINE *)0x0) {
            Curl_failf(local_100,DAT_00059650);
            return 0x3a;
          }
          bVar3 = false;
          local_bc = (X509 *)0x0;
          local_c0 = pcVar21;
          iVar6 = ENGINE_ctrl(*(ENGINE **)(local_100 + 0x8648),0xd,0,DAT_000586c4,(f *)0x0);
          if (iVar6 == 0) {
            Curl_failf(local_100,DAT_000586c8);
            return 0x3a;
          }
          iVar6 = ENGINE_ctrl_cmd(*(ENGINE **)(local_100 + 0x8648),DAT_00058ff8,0,&local_c0,(f *)0x0
                                  ,1);
          if (iVar6 == 0) {
            uVar16 = ERR_get_error();
            pcVar26 = ERR_error_string(uVar16,(char *)0x0);
            Curl_failf(local_100,DAT_00059654,pcVar21,pcVar26);
            return 0x3a;
          }
          if (local_bc == (X509 *)0x0) {
            Curl_failf(local_100,DAT_0005966c);
            return 0x3a;
          }
          iVar6 = SSL_CTX_use_certificate(local_f8,local_bc);
          if (iVar6 != 1) {
            Curl_failf(local_100,DAT_00058ffc);
            X509_free(local_bc);
            return 0x3a;
          }
          X509_free(local_bc);
        }
        else {
          if (iVar32 != 0x2b) goto LAB_000581e2;
          local_c4 = (_STACK *)0x0;
          pFVar20 = fopen64(pcVar21,DAT_000586b8);
          if (pFVar20 == (FILE *)0x0) {
            Curl_failf(local_100,DAT_0005964c,pcVar21);
            return 0x3a;
          }
          p12 = d2i_PKCS12_fp(pFVar20,(PKCS12 **)0x0);
          fclose(pFVar20);
          if (p12 == (PKCS12 *)0x0) {
            Curl_failf(local_100,DAT_0005962c,pcVar21);
            return 0x3a;
          }
          PKCS12_PBE_add();
          iVar6 = PKCS12_parse(p12,*(char **)(local_100 + 0x370),&local_c8,&local_cc,
                               (stack_st_X509 **)&local_c4);
          if (iVar6 == 0) {
            uVar16 = ERR_get_error();
            pcVar21 = ERR_error_string(uVar16,(char *)0x0);
            Curl_failf(local_100,DAT_000586bc,pcVar21);
            PKCS12_free(p12);
            return 0x3a;
          }
          PKCS12_free(p12);
          iVar6 = SSL_CTX_use_certificate(local_f8,local_cc);
          if (iVar6 != 1) {
            uVar16 = ERR_get_error();
            pcVar21 = ERR_error_string(uVar16,(char *)0x0);
            Curl_failf(local_100,DAT_00058fd4,pcVar21);
LAB_00058d50:
            EVP_PKEY_free(local_c8);
            X509_free(local_cc);
            sk_pop_free(local_c4,DAT_00058fd8);
            return 0x3a;
          }
          iVar6 = SSL_CTX_use_PrivateKey(local_f8,local_c8);
          if (iVar6 != 1) {
            Curl_failf(local_100,DAT_00059644,pcVar21);
            goto LAB_00058d50;
          }
          iVar6 = SSL_CTX_check_private_key(local_f8);
          if (iVar6 == 0) {
            Curl_failf(local_100,DAT_00059870,pcVar21);
            goto LAB_00058d50;
          }
          if (local_c4 != (_STACK *)0x0) {
            do {
              iVar6 = sk_num(local_c4);
              if (iVar6 == 0) goto LAB_0005974e;
              pXVar9 = (X509 *)sk_pop(local_c4);
              lVar11 = SSL_CTX_ctrl(local_f8,0xe,0,pXVar9);
              if (lVar11 == 0) {
                X509_free(pXVar9);
                Curl_failf(local_100,DAT_0005986c);
                goto LAB_00058d50;
              }
              iVar6 = SSL_CTX_add_client_CA(local_f8,pXVar9);
            } while (iVar6 != 0);
            Curl_failf(local_100,DAT_00059868);
            goto LAB_00058d50;
          }
LAB_0005974e:
          bVar3 = true;
          EVP_PKEY_free(local_c8);
          X509_free(local_cc);
          sk_pop_free(local_c4,DAT_00059858);
        }
      }
      iVar6 = do_file_type(local_e8);
      if (iVar6 == 2) {
LAB_000590aa:
        iVar6 = SSL_CTX_use_PrivateKey_file(local_f8,local_f0,iVar6);
        if (iVar6 != 1) {
          iVar34 = DAT_00059304;
          if (local_e8 != 0) {
            iVar34 = local_e8;
          }
          Curl_failf(local_100,DAT_00059308,local_f0,iVar34);
          return 0x3a;
        }
      }
      else if (iVar6 < 3) {
        if (iVar6 != 1) {
LAB_00058b38:
          Curl_failf(local_100,DAT_00058cf4);
          return 0x3a;
        }
        if (!bVar3) {
          if (local_f0 == (char *)0x0) {
            local_f0 = pcVar21;
          }
          goto LAB_000590aa;
        }
      }
      else if (iVar6 == 0x2a) {
        if (*(int *)(local_100 + 0x8648) == 0) {
          Curl_failf(local_100,DAT_0005987c);
          return 0x3a;
        }
        method = UI_create_method(DAT_0005930c);
        if (method == (UI_METHOD *)0x0) {
          Curl_failf(local_100,DAT_00059878);
          return 0x3a;
        }
        pUVar24 = UI_OpenSSL();
        opener = (opener *)UI_method_get_opener((UI *)pUVar24);
        UI_method_set_opener(method,opener);
        pUVar24 = UI_OpenSSL();
        closer = (closer *)UI_method_get_closer((UI *)pUVar24);
        UI_method_set_closer(method,closer);
        UI_method_set_reader(method,DAT_00059310);
        UI_method_set_writer(method,DAT_00059314);
        pEVar18 = ENGINE_load_private_key
                            (*(ENGINE **)(local_100 + 0x8648),local_f0,method,
                             *(void **)(local_100 + 0x370));
        UI_destroy_method(method);
        if (pEVar18 == (EVP_PKEY *)0x0) {
          Curl_failf(local_100,DAT_00059874);
          return 0x3a;
        }
        iVar6 = SSL_CTX_use_PrivateKey(local_f8,pEVar18);
        if (iVar6 != 1) {
          Curl_failf(local_100,DAT_00059318);
          EVP_PKEY_free(pEVar18);
          return 0x3a;
        }
        EVP_PKEY_free(pEVar18);
      }
      else {
        if (iVar6 != 0x2b) goto LAB_00058b38;
        if (!bVar3) {
          Curl_failf(local_100,DAT_00059648);
          return 0x3a;
        }
      }
      pSVar23 = SSL_new(local_f8);
      if (pSVar23 == (SSL *)0x0) {
        Curl_failf(local_100,DAT_00059854);
        return 0x3a;
      }
      local_cc = SSL_get_certificate(pSVar23);
      if (local_cc != (X509 *)0x0) {
        pEVar18 = X509_get_pubkey(local_cc);
        from = SSL_get_privatekey(pSVar23);
        EVP_PKEY_copy_parameters(pEVar18,from);
        EVP_PKEY_free(pEVar18);
      }
      SSL_free(pSVar23);
      iVar6 = SSL_CTX_check_private_key(local_f8);
      if (iVar6 == 0) {
        Curl_failf(local_100,DAT_00059300);
        return 0x3a;
      }
    }
    pcVar21 = *(char **)(iVar31 + 0x39c);
    if (*(char **)(iVar31 + 0x39c) == (char *)0x0) {
      pcVar21 = DAT_000585d0;
    }
    iVar6 = SSL_CTX_set_cipher_list((SSL_CTX *)param_1[param_2 * 6 + 0x61],pcVar21);
    if (iVar6 == 0) {
      Curl_failf(iVar31,DAT_000585d4,pcVar21);
      return 0x3b;
    }
    Curl_infof(iVar31,DAT_00058cdc,pcVar21);
    if (*(int *)(iVar31 + 0x2c0) == 1) {
      Curl_infof(iVar31,DAT_00059344,*(undefined4 *)(iVar31 + 0x2b8));
      iVar6 = SSL_CTX_set_srp_username(param_1[param_2 * 6 + 0x61],*(undefined4 *)(iVar31 + 0x2b8));
      if (iVar6 == 0) {
        Curl_failf(iVar31,DAT_00059348);
        return 0x2b;
      }
      iVar6 = SSL_CTX_set_srp_password(param_1[param_2 * 6 + 0x61],*(undefined4 *)(iVar31 + 700));
      if (iVar6 == 0) {
        Curl_failf(iVar31,DAT_00059670);
        return 0x2b;
      }
      if (*(int *)(iVar31 + 0x39c) == 0) {
        Curl_infof(iVar31,DAT_00059660);
        iVar6 = SSL_CTX_set_cipher_list((SSL_CTX *)param_1[param_2 * 6 + 0x61],DAT_00059664);
        if (iVar6 == 0) {
          Curl_failf(iVar31,DAT_00059668);
          return 0x3b;
        }
      }
    }
    if ((*(char **)(iVar31 + 0x394) != (char *)0x0) || (*(char **)(iVar31 + 0x390) != (char *)0x0))
    {
      iVar6 = SSL_CTX_load_verify_locations
                        ((SSL_CTX *)param_1[param_2 * 6 + 0x61],*(char **)(iVar31 + 0x394),
                         *(char **)(iVar31 + 0x390));
      if (iVar6 == 0) {
        if (*(char *)(iVar31 + 0x288) != '\0') {
          iVar34 = *(int *)(iVar31 + 0x394);
          if (*(int *)(iVar31 + 0x394) == 0) {
            iVar34 = DAT_00058ce0;
          }
          iVar35 = *(int *)(iVar31 + 0x390);
          if (*(int *)(iVar31 + 0x390) == 0) {
            iVar35 = DAT_00058ce0;
          }
          Curl_failf(iVar31,DAT_00058ce4,iVar34,iVar35);
          return 0x4d;
        }
        Curl_infof(iVar31,DAT_00059334);
      }
      else {
        Curl_infof(iVar31,DAT_00059324);
      }
      iVar6 = *(int *)(iVar31 + 0x394);
      if (*(int *)(iVar31 + 0x394) == 0) {
        iVar6 = DAT_00059328;
      }
      iVar32 = DAT_00059328;
      if (*(int *)(iVar31 + 0x390) != 0) {
        iVar32 = *(int *)(iVar31 + 0x390);
      }
      Curl_infof(iVar31,DAT_0005932c,iVar6,iVar32);
    }
    if (*(int *)(iVar31 + 0x3ac) != 0) {
      pXVar25 = SSL_CTX_get_cert_store((SSL_CTX *)param_1[param_2 * 6 + 0x61]);
      m = X509_LOOKUP_file();
      ctx_00 = X509_STORE_add_lookup(pXVar25,m);
      if ((ctx_00 == (X509_LOOKUP *)0x0) ||
         (iVar6 = X509_load_crl_file(ctx_00,*(char **)(iVar31 + 0x3ac),1), iVar6 == 0)) {
        Curl_failf(iVar31,DAT_00059330,*(undefined4 *)(iVar31 + 0x3ac));
        return 0x52;
      }
      Curl_infof(iVar31,DAT_00059338);
      pXVar25 = SSL_CTX_get_cert_store((SSL_CTX *)param_1[param_2 * 6 + 0x61]);
      X509_STORE_set_flags(pXVar25,0xc);
      iVar6 = *(int *)(iVar31 + 0x3ac);
      if (*(int *)(iVar31 + 0x3ac) == 0) {
        iVar6 = DAT_00059328;
      }
      Curl_infof(iVar31,DAT_0005933c,iVar6);
    }
    SSL_CTX_set_verify((SSL_CTX *)param_1[param_2 * 6 + 0x61],(uint)*(byte *)(iVar31 + 0x288),
                       (callback *)0x0);
    if ((*(code **)(iVar31 + 0x2ac) != (code *)0x0) &&
       (iVar6 = (**(code **)(iVar31 + 0x2ac))
                          (iVar31,param_1[param_2 * 6 + 0x61],*(undefined4 *)(iVar31 + 0x2b0)),
       iVar6 != 0)) {
      Curl_failf(iVar31,DAT_00059880);
      return iVar6;
    }
    if ((SSL *)param_1[param_2 * 6 + 0x62] != (SSL *)0x0) {
      SSL_free((SSL *)param_1[param_2 * 6 + 0x62]);
    }
    pSVar23 = SSL_new((SSL_CTX *)param_1[param_2 * 6 + 0x61]);
    param_1[param_2 * 6 + 0x62] = (int)pSVar23;
    if (pSVar23 == (SSL *)0x0) {
      Curl_failf(iVar31,DAT_00059680);
      return 0x1b;
    }
    if (*(char *)(iVar31 + 0x28a) != '\0') {
      SSL_ctrl(pSVar23,0x41,1,(void *)0x0);
      pSVar23 = (SSL *)param_1[param_2 * 6 + 0x62];
    }
    SSL_set_connect_state(pSVar23);
    param_1[param_2 * 6 + 99] = 0;
    iVar6 = inet_pton(2,(char *)param_1[0x26],auStack_b8);
    if ((((iVar6 == 0) && (iVar6 = inet_pton(10,(char *)param_1[0x26],auStack_b8), iVar6 == 0)) &&
        (bVar4)) &&
       (lVar11 = SSL_ctrl((SSL *)param_1[param_2 * 6 + 0x62],0x37,0,(void *)param_1[0x26]),
       lVar11 == 0)) {
      Curl_infof(iVar31,DAT_00059684);
    }
    iVar6 = Curl_ssl_getsessionid(param_1,&local_d4,0);
    if (iVar6 == 0) {
      iVar6 = SSL_set_session((SSL *)param_1[param_2 * 6 + 0x62],local_d4);
      if (iVar6 == 0) {
        uVar16 = ERR_get_error();
        pcVar21 = ERR_error_string(uVar16,(char *)0x0);
        Curl_failf(iVar31,DAT_00059340,pcVar21);
        return 0x23;
      }
      Curl_infof(iVar31,DAT_0005967c);
    }
    iVar5 = SSL_set_fd((SSL *)param_1[param_2 * 6 + 0x62],iVar5);
    if (iVar5 == 0) {
      uVar16 = ERR_get_error();
      pcVar21 = ERR_error_string(uVar16,(char *)0x0);
      Curl_failf(iVar31,DAT_0005984c,pcVar21);
      return 0x23;
    }
    pSVar28 = (SSL_SESSION *)0x1;
    param_1[param_2 * 6 + 0x60] = 1;
  }
  while ((undefined *)((int)&pSVar28[-1].tlsext_tick_lifetime_hint + 3U) < (undefined *)0x3) {
    iVar5 = Curl_timeleft(iVar34,0,1);
    if (iVar5 < 0) goto LAB_00058078;
    if (param_1[param_2 * 6 + 0x60] - 2U < 2) {
      if (param_1[param_2 * 6 + 0x60] == 3) {
        iVar6 = -1;
        iVar31 = iVar35;
      }
      else {
        iVar6 = iVar35;
        iVar31 = -1;
      }
      if (param_3 != 0) {
        iVar5 = 0;
      }
      iVar5 = Curl_socket_check(iVar6,0xffffffff,iVar31,iVar5);
      if (iVar5 < 0) {
        piVar7 = __errno_location();
        Curl_failf(iVar34,DAT_000582a8,*piVar7);
        return 0x23;
      }
      if (iVar5 == 0) {
        if (param_3 != 0) {
          *param_4 = 0;
          return 0;
        }
        goto LAB_00058078;
      }
    }
    iVar5 = ossl_connect_step2(param_1,param_2);
    if (iVar5 != 0) {
      return iVar5;
    }
    pSVar28 = (SSL_SESSION *)param_1[param_2 * 6 + 0x60];
    if ((param_3 != 0) &&
       ((undefined *)((int)&pSVar28[-1].tlsext_tick_lifetime_hint + 3U) < (undefined *)0x3)) {
      return 0;
    }
  }
  if (pSVar28 == (SSL_SESSION *)0x4) {
    local_dc = (SSL_SESSION *)0x0;
    iVar35 = *param_1;
    pSVar28 = SSL_get1_session((SSL *)param_1[param_2 * 6 + 0x62]);
    iVar34 = Curl_ssl_getsessionid(param_1,&local_dc,0);
    if (iVar34 == 0) {
      if (pSVar28 != local_dc) {
        Curl_infof(iVar35,DAT_000585b0);
        Curl_ssl_delsessionid(param_1,local_dc);
        goto LAB_000582f8;
      }
      SSL_SESSION_free(pSVar28);
    }
    else {
LAB_000582f8:
      iVar34 = Curl_ssl_addsessionid(param_1,pSVar28,0);
      if (iVar34 != 0) {
        Curl_failf(iVar35,DAT_000592fc);
        return iVar34;
      }
    }
    if (*(char *)(iVar35 + 0x288) == '\0') {
      cVar2 = *(char *)(iVar35 + 0x289);
    }
    else {
      cVar2 = '\x01';
    }
    iVar34 = *param_1;
    pBVar8 = BIO_s_mem();
    fp = BIO_new(pBVar8);
    if (*(char *)(iVar34 + 0x2b5) != '\0') {
      iVar35 = *param_1;
      p_Var19 = &SSL_get_peer_cert_chain((SSL *)param_1[param_2 * 6 + 0x62])->stack;
      if (p_Var19 != (_STACK *)0x0) {
        iVar5 = sk_num(p_Var19);
        iVar31 = Curl_ssl_init_certinfo(iVar35,iVar5);
        if (iVar31 == 0) {
          pBVar8 = BIO_s_mem();
          out = BIO_new(pBVar8);
          if (0 < iVar5) {
            iVar31 = 0;
            do {
              pXVar9 = (X509 *)sk_value(p_Var19,iVar31);
              pXVar10 = X509_get_subject_name(pXVar9);
              X509_NAME_print_ex(out,pXVar10,0,0x82031f);
              lVar11 = BIO_ctrl(out,3,0,&local_c4);
              Curl_ssl_push_certinfo_len(iVar35,iVar31,DAT_000589f4,local_c4,lVar11);
              BIO_ctrl(out,1,0,(void *)0x0);
              pXVar10 = X509_get_issuer_name(pXVar9);
              X509_NAME_print_ex(out,pXVar10,0,0x82031f);
              lVar11 = BIO_ctrl(out,3,0,&local_c4);
              Curl_ssl_push_certinfo_len(iVar35,iVar31,DAT_000589f8,local_c4,lVar11);
              BIO_ctrl(out,1,0,(void *)0x0);
              lVar11 = ASN1_INTEGER_get(pXVar9->cert_info->version);
              BIO_printf(out,DAT_000589fc,lVar11);
              lVar11 = BIO_ctrl(out,3,0,&local_c4);
              Curl_ssl_push_certinfo_len(iVar35,iVar31,DAT_00058a00,local_c4,lVar11);
              BIO_ctrl(out,1,0,(void *)0x0);
              pAVar17 = X509_get_serialNumber(pXVar9);
              if (pAVar17->type == 0x102) {
                BIO_puts(out,DAT_00059320);
              }
              if (0 < pAVar17->length) {
                iVar6 = 0;
                do {
                  pbVar1 = pAVar17->data + iVar6;
                  iVar6 = iVar6 + 1;
                  BIO_printf(out,DAT_00058a04,(uint)*pbVar1);
                } while (iVar6 < pAVar17->length);
              }
              lVar11 = BIO_ctrl(out,3,0,&local_c4);
              Curl_ssl_push_certinfo_len(iVar35,iVar31,DAT_00058a08,local_c4,lVar11);
              BIO_ctrl(out,1,0,(void *)0x0);
              pXVar29 = pXVar9->cert_info;
              i2a_ASN1_OBJECT(out,pXVar29->signature->algorithm);
              lVar11 = BIO_ctrl(out,3,0,&local_c4);
              Curl_ssl_push_certinfo_len(iVar35,iVar31,DAT_00058a0c,local_c4,lVar11);
              BIO_ctrl(out,1,0,(void *)0x0);
              i2a_ASN1_OBJECT(out,pXVar29->key->algor->algorithm);
              lVar11 = BIO_ctrl(out,3,0,&local_c4);
              Curl_ssl_push_certinfo_len(iVar35,iVar31,DAT_00058a10,local_c4,lVar11);
              BIO_ctrl(out,1,0,(void *)0x0);
              X509V3_ext(iVar35,iVar31,pXVar29->extensions);
              pAVar30 = pXVar9->signature;
              ASN1_TIME_print(out,pXVar9->cert_info->validity->notBefore);
              lVar11 = BIO_ctrl(out,3,0,&local_c4);
              Curl_ssl_push_certinfo_len(iVar35,iVar31,DAT_00058a14,local_c4,lVar11);
              BIO_ctrl(out,1,0,(void *)0x0);
              ASN1_TIME_print(out,pXVar9->cert_info->validity->notAfter);
              lVar11 = BIO_ctrl(out,3,0,&local_c4);
              Curl_ssl_push_certinfo_len(iVar35,iVar31,DAT_00058a18,local_c4,lVar11);
              BIO_ctrl(out,1,0,(void *)0x0);
              pEVar18 = X509_get_pubkey(pXVar9);
              if (pEVar18 == (EVP_PKEY *)0x0) {
                Curl_infof(iVar35,DAT_00059634);
              }
              else {
                iVar6 = pEVar18->type;
                if (iVar6 == 0x1c) {
                  prVar33 = (pEVar18->pkey).rsa;
                  if (prVar33->meth != (RSA_METHOD *)0x0) {
                    pubkey_show(iVar35,out,iVar31,DAT_00058fdc,DAT_00059004,prVar33->meth);
                  }
                  if (prVar33->engine != (ENGINE *)0x0) {
                    pubkey_show(iVar35,out,iVar31,DAT_00058fdc,DAT_00059008,prVar33->engine);
                  }
                  if (prVar33->d != (BIGNUM *)0x0) {
                    pubkey_show(iVar35,out,iVar31,DAT_00058fdc,DAT_0005900c,prVar33->d);
                  }
                  if (prVar33->e != (BIGNUM *)0x0) {
                    pubkey_show(iVar35,out,iVar31,DAT_00058fdc,DAT_00058fe0,prVar33->e);
                  }
                }
                else if (iVar6 == 0x74) {
                  prVar33 = (pEVar18->pkey).rsa;
                  if (prVar33->engine != (ENGINE *)0x0) {
                    pubkey_show(iVar35,out,iVar31,DAT_00058d10,DAT_00058d18,prVar33->engine);
                  }
                  if (prVar33->n != (BIGNUM *)0x0) {
                    pubkey_show(iVar35,out,iVar31,DAT_00058d10,DAT_00058d1c,prVar33->n);
                  }
                  if (prVar33->e != (BIGNUM *)0x0) {
                    pubkey_show(iVar35,out,iVar31,DAT_00058d10,DAT_00058d20,prVar33->e);
                  }
                  if (prVar33->p != (BIGNUM *)0x0) {
                    pubkey_show(iVar35,out,iVar31,DAT_00058d10,DAT_00058d24,prVar33->p);
                  }
                  if (prVar33->d != (BIGNUM *)0x0) {
                    pubkey_show(iVar35,out,iVar31,DAT_00058d10,DAT_00058d14,prVar33->d);
                  }
                }
                else if (iVar6 == 6) {
                  prVar33 = (pEVar18->pkey).rsa;
                  iVar6 = BN_num_bits(prVar33->n);
                  BIO_printf(out,DAT_00058fe8,iVar6);
                  lVar11 = BIO_ctrl(out,3,0,&local_c4);
                  Curl_ssl_push_certinfo_len(iVar35,iVar31,DAT_00058fec,local_c4,lVar11);
                  BIO_ctrl(out,1,0,(void *)0x0);
                  if (prVar33->n != (BIGNUM *)0x0) {
                    pubkey_show(iVar35,out,iVar31,DAT_00058ff0,DAT_00059010,prVar33->n);
                  }
                  if (prVar33->e != (BIGNUM *)0x0) {
                    pubkey_show(iVar35,out,iVar31,DAT_00058ff0,DAT_00059014,prVar33->e);
                  }
                  if (prVar33->d != (BIGNUM *)0x0) {
                    pubkey_show(iVar35,out,iVar31,DAT_00058ff0,DAT_00059018,prVar33->d);
                  }
                  if (prVar33->p != (BIGNUM *)0x0) {
                    pubkey_show(iVar35,out,iVar31,DAT_00058ff0,DAT_00059004,prVar33->p);
                  }
                  if (prVar33->q != (BIGNUM *)0x0) {
                    pubkey_show(iVar35,out,iVar31,DAT_00058ff0,DAT_0005901c,prVar33->q);
                  }
                  if (prVar33->dmp1 != (BIGNUM *)0x0) {
                    pubkey_show(iVar35,out,iVar31,DAT_00058ff0,DAT_00059020,prVar33->dmp1);
                  }
                  if (prVar33->dmq1 != (BIGNUM *)0x0) {
                    pubkey_show(iVar35,out,iVar31,DAT_00058ff0,DAT_00059024,prVar33->dmq1);
                  }
                  if (prVar33->iqmp != (BIGNUM *)0x0) {
                    pubkey_show(iVar35,out,iVar31,DAT_00058ff0,DAT_00058ff4,prVar33->iqmp);
                  }
                }
                EVP_PKEY_free(pEVar18);
              }
              if (0 < pAVar30->length) {
                iVar6 = 0;
                do {
                  pbVar1 = pAVar30->data + iVar6;
                  iVar6 = iVar6 + 1;
                  BIO_printf(out,DAT_00058a1c,(uint)*pbVar1);
                } while (iVar6 < pAVar30->length);
              }
              lVar11 = BIO_ctrl(out,3,0,&local_c4);
              Curl_ssl_push_certinfo_len(iVar35,iVar31,DAT_00058a20,local_c4,lVar11);
              BIO_ctrl(out,1,0,(void *)0x0);
              PEM_write_bio_X509(out,pXVar9);
              lVar11 = BIO_ctrl(out,3,0,&local_c4);
              iVar6 = iVar31 + 1;
              Curl_ssl_push_certinfo_len(iVar35,iVar31,DAT_00058a24,local_c4,lVar11);
              BIO_ctrl(out,1,0,(void *)0x0);
              iVar31 = iVar6;
            } while (iVar6 != iVar5);
          }
          BIO_free(out);
        }
      }
    }
    pXVar9 = SSL_get_peer_certificate((SSL *)param_1[param_2 * 6 + 0x62]);
    param_1[param_2 * 6 + 99] = (int)pXVar9;
    if (pXVar9 == (X509 *)0x0) {
      if (cVar2 != '\0') {
        Curl_failf(iVar34,DAT_000586c0);
        return 0x33;
      }
    }
    else {
      Curl_infof(iVar34,DAT_000585b4);
      iVar31 = iVar34 + 0x59c;
      pXVar10 = X509_get_subject_name((X509 *)param_1[param_2 * 6 + 99]);
      iVar5 = x509_name_oneline_constprop_5(pXVar10,iVar31);
      iVar35 = DAT_000585b8;
      if (iVar5 == 0) {
        iVar35 = iVar31;
      }
      Curl_infof(iVar34,DAT_000585bc,iVar35);
      ASN1_TIME_print(fp,**(ASN1_TIME ***)(*(int *)param_1[param_2 * 6 + 99] + 0x10));
      lVar11 = BIO_ctrl(fp,3,0,&local_d8);
      Curl_infof(iVar34,DAT_000585c0,lVar11,local_d8);
      BIO_ctrl(fp,1,0,(void *)0x0);
      ASN1_TIME_print(fp,*(ASN1_TIME **)(*(int *)(*(int *)param_1[param_2 * 6 + 99] + 0x10) + 4));
      lVar11 = BIO_ctrl(fp,3,0,&local_d8);
      Curl_infof(iVar34,DAT_000585c4,lVar11,local_d8);
      BIO_ctrl(fp,1,0,(void *)0x0);
      BIO_free(fp);
      if (*(char *)(iVar34 + 0x289) != '\0') {
        pXVar9 = (X509 *)param_1[param_2 * 6 + 99];
        iVar35 = *param_1;
        if ((*(char *)((int)param_1 + 499) == '\0') ||
           (iVar5 = inet_pton(10,(char *)param_1[0x26],&local_a8), iVar5 == 0)) {
          iVar5 = inet_pton(2,(char *)param_1[0x26],&local_a8);
          if (iVar5 == 0) {
            local_f0 = (char *)0x0;
            iVar5 = 2;
          }
          else {
            local_f0 = (char *)0x4;
            iVar5 = 7;
          }
        }
        else {
          iVar5 = 7;
          local_f0 = (char *)0x10;
        }
        p_Var12 = (_STACK *)X509_get_ext_d2i(pXVar9,0x55,(int *)0x0,(int *)0x0);
        p_Var19 = DAT_00059028;
        if (p_Var12 != (_STACK *)0x0) {
          iVar6 = sk_num(p_Var12);
          if (iVar6 < 1) {
            GENERAL_NAMES_free((GENERAL_NAMES *)p_Var12);
          }
          else {
            iVar32 = 0;
            do {
              piVar7 = (int *)sk_value(p_Var12,iVar32);
              if (*piVar7 == iVar5) {
                puVar13 = ASN1_STRING_data((ASN1_STRING *)piVar7[1]);
                sVar14 = ASN1_STRING_length((ASN1_STRING *)piVar7[1]);
                if (iVar5 == 2) {
                  sVar22 = strlen((char *)puVar13);
                  if ((sVar14 == sVar22) &&
                     (iVar15 = Curl_cert_hostcheck(puVar13,param_1[0x26]), iVar15 != 0)) {
                    Curl_infof(iVar35,DAT_00058fe4,param_1[0x27],puVar13);
                    goto LAB_0005849c;
                  }
                }
                else if (((iVar5 == 7) && ((char *)sVar14 == local_f0)) &&
                        (iVar15 = memcmp(puVar13,&local_a8,(size_t)local_f0), iVar15 == 0)) {
                  Curl_infof(iVar35,DAT_000585c8,param_1[0x27]);
LAB_0005849c:
                  GENERAL_NAMES_free((GENERAL_NAMES *)p_Var12);
                  goto LAB_000584a2;
                }
              }
              iVar32 = iVar32 + 1;
            } while (iVar32 != iVar6);
            GENERAL_NAMES_free((GENERAL_NAMES *)p_Var12);
          }
          iVar5 = 0x33;
          Curl_infof(iVar35,DAT_00058cf8,param_1[0x27]);
          Curl_failf(iVar35,DAT_00058cfc,param_1[0x27]);
          goto LAB_00058b68;
        }
        local_c4 = DAT_00059028;
        pXVar10 = X509_get_subject_name(pXVar9);
        if (pXVar10 == (X509_NAME *)0x0) {
LAB_00058f84:
          iVar5 = 0;
LAB_00058f88:
          if (local_c4 == p_Var19) {
            local_c4 = (_STACK *)0x0;
          }
          if (iVar5 == 0) {
LAB_00058f9a:
            if (local_c4 == (_STACK *)0x0) goto LAB_000596f0;
            iVar5 = Curl_cert_hostcheck(local_c4,param_1[0x26]);
            if (iVar5 == 0) {
              iVar5 = 0x33;
              Curl_failf(iVar35,DAT_00059000,local_c4,param_1[0x27]);
            }
            else {
              iVar5 = 0;
              Curl_infof(iVar35,DAT_00059848,local_c4);
            }
          }
        }
        else {
          iVar5 = -1;
          do {
            iVar6 = iVar5;
            iVar5 = X509_NAME_get_index_by_NID(pXVar10,0xd,iVar6);
          } while (-1 < iVar5);
          if (iVar6 < 0) goto LAB_00058f84;
          ne = X509_NAME_get_entry(pXVar10,iVar6);
          x = X509_NAME_ENTRY_get_data(ne);
          if (x == (ASN1_STRING *)0x0) goto LAB_00058f84;
          iVar5 = ASN1_STRING_type(x);
          if (iVar5 == 0xc) {
            sVar14 = ASN1_STRING_length(x);
            if ((int)sVar14 < 0) goto LAB_00059592;
            p_Var12 = (_STACK *)CRYPTO_malloc(sVar14 + 1,DAT_00059844,0x48a);
            local_c4 = p_Var12;
            if (p_Var12 != (_STACK *)0x0) {
              puVar13 = ASN1_STRING_data(x);
              memcpy(p_Var12,puVar13,sVar14);
              *(undefined *)((int)&local_c4->num + sVar14) = 0;
              goto LAB_00059592;
            }
            goto LAB_00058f9a;
          }
          sVar14 = ASN1_STRING_to_UTF8((uchar **)&local_c4,x);
LAB_00059592:
          if (local_c4 != (_STACK *)0x0) {
            strlen((char *)local_c4);
            sVar22 = curlx_uztosi();
            if (sVar22 == sVar14) goto LAB_00058f84;
            iVar5 = 0x33;
            Curl_failf(iVar35,DAT_00059678);
            goto LAB_00058f88;
          }
LAB_000596f0:
          Curl_failf(iVar35,DAT_00059850);
          iVar5 = 0x33;
        }
        if (local_c4 != (_STACK *)0x0) {
          CRYPTO_free(local_c4);
        }
        if (iVar5 != 0) {
LAB_00058b68:
          X509_free((X509 *)param_1[param_2 * 6 + 99]);
          param_1[param_2 * 6 + 99] = 0;
          return iVar5;
        }
      }
LAB_000584a2:
      pXVar10 = X509_get_issuer_name((X509 *)param_1[param_2 * 6 + 99]);
      iVar35 = x509_name_oneline_constprop_5(pXVar10,iVar31);
      if (iVar35 == 0) {
        Curl_infof(iVar34,DAT_00058d00,iVar31);
        if (*(char **)(iVar34 + 0x3b0) != (char *)0x0) {
          pFVar20 = fopen64(*(char **)(iVar34 + 0x3b0),DAT_00058d04);
          if (pFVar20 == (FILE *)0x0) {
            if (cVar2 != '\0') {
              Curl_failf(iVar34,DAT_0005931c,*(undefined4 *)(iVar34 + 0x3b0));
            }
            X509_free((X509 *)param_1[param_2 * 6 + 99]);
            param_1[param_2 * 6 + 99] = 0;
            return 0x53;
          }
          pXVar9 = PEM_read_X509(pFVar20,(X509 **)0x0,(undefined1 *)0x0,(void *)0x0);
          if (pXVar9 == (X509 *)0x0) {
            if (cVar2 != '\0') {
              Curl_failf(iVar34,DAT_00059674,*(undefined4 *)(iVar34 + 0x3b0));
            }
            X509_free((X509 *)param_1[param_2 * 6 + 99]);
            X509_free((X509 *)0x0);
            fclose(pFVar20);
            return 0x53;
          }
          fclose(pFVar20);
          iVar35 = X509_check_issued(pXVar9,(X509 *)param_1[param_2 * 6 + 99]);
          if (iVar35 != 0) {
            if (cVar2 != '\0') {
              Curl_failf(iVar34,DAT_0005965c,*(undefined4 *)(iVar34 + 0x3b0));
            }
            X509_free((X509 *)param_1[param_2 * 6 + 99]);
            X509_free(pXVar9);
            param_1[param_2 * 6 + 99] = 0;
            return 0x53;
          }
          Curl_infof(iVar34,DAT_00059630,*(undefined4 *)(iVar34 + 0x3b0));
          X509_free(pXVar9);
        }
        lVar11 = SSL_get_verify_result((SSL *)param_1[param_2 * 6 + 0x62]);
        *(long *)(iVar34 + 0x284) = lVar11;
        if (lVar11 == 0) {
          Curl_infof(iVar34,DAT_0005988c);
          iVar35 = 0;
        }
        else if (*(char *)(iVar34 + 0x288) == '\0') {
          pcVar21 = X509_verify_cert_error_string(lVar11);
          Curl_infof(iVar34,DAT_00059888,pcVar21,lVar11);
          iVar35 = 0;
        }
        else if (cVar2 == '\0') {
          iVar35 = 0x33;
        }
        else {
          pcVar21 = X509_verify_cert_error_string(lVar11);
          iVar35 = 0x33;
          Curl_failf(iVar34,DAT_00059884,pcVar21,lVar11);
        }
      }
      else {
        iVar35 = 0x23;
        if (cVar2 != '\0') {
          iVar35 = 0x23;
          Curl_failf(iVar34,DAT_00058d08);
        }
      }
      if (*(char *)(iVar34 + 0x28a) != '\0') {
        iVar35 = *param_1;
        lVar11 = SSL_ctrl((SSL *)param_1[param_2 * 6 + 0x62],0x46,0,&local_d4);
        if (local_d4 == (SSL_SESSION *)0x0) {
          Curl_failf(iVar35,DAT_0005963c);
          resp = (OCSP_RESPONSE *)0x0;
          goto LAB_00058c3c;
        }
        resp = d2i_OCSP_RESPONSE((OCSP_RESPONSE **)0x0,(uchar **)&local_d4,lVar11);
        if (resp != (OCSP_RESPONSE *)0x0) {
          iVar5 = OCSP_response_status(resp);
          if (iVar5 != 0) {
            pcVar21 = OCSP_response_status_str(iVar5);
            Curl_failf(iVar35,DAT_00058d0c,pcVar21,iVar5);
            goto LAB_00058c3c;
          }
          bs = OCSP_response_get1_basic(resp);
          if (bs != (OCSP_BASICRESP *)0x0) {
            certs = SSL_get_peer_cert_chain((SSL *)param_1[param_2 * 6 + 0x62]);
            pXVar25 = SSL_CTX_get_cert_store((SSL_CTX *)param_1[param_2 * 6 + 0x61]);
            iVar5 = OCSP_basic_verify(bs,certs,pXVar25,0);
            if (iVar5 < 1) {
              Curl_failf(iVar35,DAT_00059860);
            }
            else {
              iVar5 = 0;
              do {
                do {
                  iVar31 = OCSP_resp_count(bs);
                  iVar6 = iVar5 + 1;
                  if (iVar31 <= iVar5) {
                    iVar35 = 0;
                    OCSP_BASICRESP_free(bs);
                    OCSP_RESPONSE_free(resp);
                    goto LAB_000584ce;
                  }
                  single = OCSP_resp_get0(bs,iVar5);
                  iVar5 = iVar6;
                } while (single == (OCSP_SINGLERESP *)0x0);
                iVar31 = OCSP_single_get0_status
                                   (single,&local_d0,(ASN1_GENERALIZEDTIME **)&local_cc,
                                    (ASN1_GENERALIZEDTIME **)&local_c8,
                                    (ASN1_GENERALIZEDTIME **)&local_c4);
                iVar6 = OCSP_check_validity((ASN1_GENERALIZEDTIME *)local_c8,
                                            (ASN1_GENERALIZEDTIME *)local_c4,300,-1);
                if (iVar6 == 0) {
                  Curl_failf(iVar35,DAT_00059864);
                  break;
                }
                pcVar21 = OCSP_cert_status_str(iVar31);
                Curl_infof(iVar35,DAT_00059640,pcVar21,iVar31);
                if (iVar31 == 1) {
                  pcVar21 = OCSP_crl_reason_str(local_d0);
                  Curl_failf(iVar35,DAT_0005985c,pcVar21,local_d0);
                  break;
                }
              } while (iVar31 != 2);
            }
            OCSP_BASICRESP_free(bs);
            goto LAB_00058c3c;
          }
        }
        Curl_failf(iVar35,DAT_00059638);
LAB_00058c3c:
        OCSP_RESPONSE_free(resp);
        X509_free((X509 *)param_1[param_2 * 6 + 99]);
        param_1[param_2 * 6 + 99] = 0;
        return 0x5b;
      }
LAB_000584ce:
      if (cVar2 == '\0') {
        iVar5 = *(int *)(iVar34 + 0x398);
      }
      else {
        iVar5 = *(int *)(iVar34 + 0x398);
        local_d8 = iVar5;
        if (iVar35 != 0) goto LAB_000584e8;
      }
      local_d8 = iVar5;
      if (iVar5 != 0) {
        piVar7 = (int *)param_1[param_2 * 6 + 99];
        local_c4 = (_STACK *)0x0;
        if (((piVar7 == (int *)0x0) ||
            (iVar35 = i2d_X509_PUBKEY(*(X509_PUBKEY **)(*piVar7 + 0x18),(uchar **)0x0), iVar35 < 1))
           || (p_Var19 = (_STACK *)CRYPTO_malloc(iVar35,DAT_00058cec,0x9be), local_c4 = p_Var19,
              p_Var19 == (_STACK *)0x0)) {
          iVar35 = 0x5a;
        }
        else {
          iVar31 = i2d_X509_PUBKEY(*(X509_PUBKEY **)(*piVar7 + 0x18),(uchar **)&local_c4);
          if (((iVar35 == iVar31) && (local_c4 != (_STACK *)0x0)) &&
             (iVar35 == (int)local_c4 - (int)p_Var19)) {
            iVar35 = Curl_pin_peer_pubkey(iVar34,iVar5,p_Var19,iVar35);
            CRYPTO_free(p_Var19);
            if (iVar35 == 0) goto LAB_00058276;
          }
          else {
            iVar35 = 0x5a;
            CRYPTO_free(p_Var19);
          }
        }
        Curl_failf(iVar34,DAT_00058cf0);
LAB_000584e8:
        X509_free((X509 *)param_1[param_2 * 6 + 99]);
        param_1[param_2 * 6 + 99] = 0;
        param_1[param_2 * 6 + 0x60] = 5;
        return iVar35;
      }
LAB_00058276:
      X509_free((X509 *)param_1[param_2 * 6 + 99]);
      param_1[param_2 * 6 + 99] = 0;
    }
  }
  else if (pSVar28 != (SSL_SESSION *)0x5) {
    *param_4 = 0;
    goto LAB_0005814e;
  }
  iVar35 = DAT_000582bc;
  iVar34 = DAT_000582b8;
  param_1[param_2 * 6 + 0x5f] = 2;
  param_1[param_2 + 0x5a] = iVar34;
  param_1[param_2 + 0x5c] = iVar35;
  *param_4 = 1;
LAB_0005814e:
  param_1[param_2 * 6 + 0x60] = 0;
  return 0;
}

