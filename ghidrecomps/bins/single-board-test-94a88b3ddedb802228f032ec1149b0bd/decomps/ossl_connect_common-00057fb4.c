
/* WARNING: Type propagation algorithm not settling */

int ossl_connect_common(int *param_1,int param_2,int param_3,undefined1 *param_4)

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
  int iVar13;
  uchar *puVar14;
  size_t sVar15;
  int iVar16;
  ulong uVar17;
  PKCS12 *p12;
  BIO *out;
  ASN1_INTEGER *pAVar18;
  EVP_PKEY *pEVar19;
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
  X509_NAME_ENTRY *ne;
  ASN1_STRING *x;
  uint uVar26;
  SSL_SESSION *pSVar27;
  undefined *puVar28;
  X509_CINF *pXVar29;
  ASN1_BIT_STRING *pAVar30;
  char *pcVar31;
  rsa_st *prVar32;
  int iVar33;
  int iVar34;
  int local_100;
  SSL_CTX *local_f8;
  char *local_f0;
  undefined *local_e8;
  SSL_SESSION *local_dc;
  int local_d8;
  SSL_SESSION *local_d4;
  long local_d0;
  X509 *local_cc;
  EVP_PKEY *local_c8;
  _STACK *local_c4;
  char *local_c0;
  X509 *local_bc;
  undefined1 auStack_b8 [16];
  undefined1 local_a8;
  undefined4 local_a7;
  undefined4 local_a3;
  
  iVar33 = *param_1;
  iVar34 = param_1[param_2 + 0x55];
  if (param_1[param_2 * 6 + 0x5f] == 2) {
    *param_4 = 1;
    return 0;
  }
  pSVar27 = (SSL_SESSION *)param_1[param_2 * 6 + 0x60];
  if (pSVar27 == (SSL_SESSION *)0x0) {
    iVar5 = Curl_timeleft(iVar33,0,1);
    if (iVar5 < 0) {
LAB_00058078:
      Curl_failf(iVar33,"SSL connection timeout");
      return 0x1c;
    }
    iVar13 = *param_1;
    iVar5 = param_1[param_2 + 0x55];
    local_d4 = pSVar27;
    Curl_ossl_seed(iVar13);
    *(undefined4 *)(iVar13 + 0x284) = 1;
    bVar4 = false;
    if (*(int *)(iVar13 + 0x280) == 2) {
      if (*(int *)(iVar13 + 0x2c0) == 1) {
        return 0x23;
      }
      meth = SSLv2_client_method();
    }
    else if (*(int *)(iVar13 + 0x280) == 3) {
      if (*(int *)(iVar13 + 0x2c0) == 1) {
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
      uVar17 = ERR_peek_error();
      pcVar21 = ERR_error_string(uVar17,(char *)0x0);
      Curl_failf(iVar13,"SSL: couldn\'t create a context: %s",pcVar21);
      return 0x1b;
    }
    SSL_CTX_ctrl(ctx,0x21,0x10,(void *)0x0);
    if ((*(int *)(iVar13 + 0x1c8) != 0) && (*(char *)(iVar13 + 0x310) != '\0')) {
      SSL_CTX_set_msg_callback((SSL_CTX *)param_1[param_2 * 6 + 0x61],(cb *)0x5766d);
      SSL_CTX_ctrl((SSL_CTX *)param_1[param_2 * 6 + 0x61],0x10,0,param_1);
    }
    uVar26 = 0x800243f7;
    if (*(char *)(*param_1 + 0x32a) != '\0') {
      uVar26 = 0x80024bf7;
    }
    switch(*(undefined4 *)(iVar13 + 0x280)) {
    case 0:
    case 1:
      uVar26 = uVar26 | 0x3000000;
      break;
    case 2:
      uVar26 = uVar26 | 0x1e000000;
      break;
    case 3:
      if (*(int *)(iVar13 + 0x2c0) == 1) {
        Curl_infof(iVar13,"Set version TLSv1.x for SRP authorisation\n");
      }
      uVar26 = uVar26 | 0x1d000000;
      break;
    case 4:
      uVar26 = uVar26 | 0x1b000000;
      break;
    case 5:
      uVar26 = uVar26 | 0xf000000;
      break;
    case 6:
      uVar26 = uVar26 | 0x17000000;
      break;
    default:
      Curl_failf(iVar13,"Unsupported SSL protocol version");
      return 0x23;
    }
    SSL_CTX_ctrl((SSL_CTX *)param_1[param_2 * 6 + 0x61],0x20,uVar26,(void *)0x0);
    if (*(char *)(iVar13 + 0x43c) != '\0') {
      SSL_CTX_set_next_proto_select_cb((SSL_CTX *)param_1[param_2 * 6 + 0x61],(cb *)0x57e09,param_1)
      ;
    }
    if (*(char *)(iVar13 + 0x43d) != '\0') {
      local_a8 = 8;
      local_a7 = 0x70747468;
      local_a3 = 0x312e312f;
      Curl_infof(iVar13,"ALPN, offering %s\n",&DAT_0013ad70);
      SSL_CTX_set_alpn_protos(param_1[param_2 * 6 + 0x61],&local_a8,9);
    }
    pcVar21 = *(char **)(iVar13 + 0x340);
    iVar6 = *(int *)(iVar13 + 0x344);
    if (pcVar21 == (char *)0x0) {
      if (iVar6 != 0) {
        local_f8 = (SSL_CTX *)param_1[param_2 * 6 + 0x61];
        local_f0 = *(char **)(iVar13 + 0x36c);
        local_e8 = *(undefined **)(iVar13 + 0x374);
        local_100 = *param_1;
        iVar16 = do_file_type(iVar6);
        if (iVar16 == 0x2a) goto LAB_000581b8;
      }
    }
    else {
      local_f8 = (SSL_CTX *)param_1[param_2 * 6 + 0x61];
      local_f0 = *(char **)(iVar13 + 0x36c);
      local_e8 = *(undefined **)(iVar13 + 0x374);
      local_100 = *param_1;
      iVar16 = do_file_type(iVar6);
LAB_000581b8:
      if (*(void **)(local_100 + 0x370) != (void *)0x0) {
        SSL_CTX_set_default_passwd_cb_userdata(local_f8,*(void **)(local_100 + 0x370));
        SSL_CTX_set_default_passwd_cb(local_f8,(undefined1 *)0x57cb5);
      }
      if (iVar16 == 2) {
        iVar6 = SSL_CTX_use_certificate_file(local_f8,pcVar21,2);
        if (iVar6 != 1) {
          uVar17 = ERR_get_error();
          pcVar21 = ERR_error_string(uVar17,(char *)0x0);
          Curl_failf(local_100,
                     "could not load ASN1 client certificate, OpenSSL error %s, (no key found, wrong pass phrase, or wrong file format?)"
                     ,pcVar21);
          return 0x3a;
        }
LAB_00058b1c:
        bVar3 = false;
      }
      else {
        if (iVar16 < 3) {
          if (iVar16 != 1) {
LAB_000581e2:
            Curl_failf(local_100,"not supported file type \'%s\' for certificate",iVar6);
            return 0x3a;
          }
          iVar6 = SSL_CTX_use_certificate_chain_file(local_f8,pcVar21);
          if (iVar6 != 1) {
            uVar17 = ERR_get_error();
            pcVar21 = ERR_error_string(uVar17,(char *)0x0);
            Curl_failf(local_100,
                       "could not load PEM client certificate, OpenSSL error %s, (no key found, wrong pass phrase, or wrong file format?)"
                       ,pcVar21);
            return 0x3a;
          }
          goto LAB_00058b1c;
        }
        if (iVar16 == 0x2a) {
          if (*(ENGINE **)(local_100 + 0x8648) == (ENGINE *)0x0) {
            Curl_failf(local_100,"crypto engine not set, can\'t load certificate");
            return 0x3a;
          }
          bVar3 = false;
          local_bc = (X509 *)0x0;
          local_c0 = pcVar21;
          iVar6 = ENGINE_ctrl(*(ENGINE **)(local_100 + 0x8648),0xd,0,"LOAD_CERT_CTRL",(f *)0x0);
          if (iVar6 == 0) {
            Curl_failf(local_100,"ssl engine does not support loading certificates");
            return 0x3a;
          }
          iVar6 = ENGINE_ctrl_cmd(*(ENGINE **)(local_100 + 0x8648),"LOAD_CERT_CTRL",0,&local_c0,
                                  (f *)0x0,1);
          if (iVar6 == 0) {
            uVar17 = ERR_get_error();
            pcVar31 = ERR_error_string(uVar17,(char *)0x0);
            Curl_failf(local_100,"ssl engine cannot load client cert with id \'%s\' [%s]",pcVar21,
                       pcVar31);
            return 0x3a;
          }
          if (local_bc == (X509 *)0x0) {
            Curl_failf(local_100,"ssl engine didn\'t initialized the certificate properly.");
            return 0x3a;
          }
          iVar6 = SSL_CTX_use_certificate(local_f8,local_bc);
          if (iVar6 != 1) {
            Curl_failf(local_100,"unable to set client certificate");
            X509_free(local_bc);
            return 0x3a;
          }
          X509_free(local_bc);
        }
        else {
          if (iVar16 != 0x2b) goto LAB_000581e2;
          local_c4 = (_STACK *)0x0;
          pFVar20 = fopen64(pcVar21,"rb");
          if (pFVar20 == (FILE *)0x0) {
            Curl_failf(local_100,"could not open PKCS12 file \'%s\'",pcVar21);
            return 0x3a;
          }
          p12 = d2i_PKCS12_fp(pFVar20,(PKCS12 **)0x0);
          fclose(pFVar20);
          if (p12 == (PKCS12 *)0x0) {
            Curl_failf(local_100,"error reading PKCS12 file \'%s\'",pcVar21);
            return 0x3a;
          }
          PKCS12_PBE_add();
          iVar6 = PKCS12_parse(p12,*(char **)(local_100 + 0x370),&local_c8,&local_cc,
                               (stack_st_X509 **)&local_c4);
          if (iVar6 == 0) {
            uVar17 = ERR_get_error();
            pcVar21 = ERR_error_string(uVar17,(char *)0x0);
            Curl_failf(local_100,"could not parse PKCS12 file, check password, OpenSSL error %s",
                       pcVar21);
            PKCS12_free(p12);
            return 0x3a;
          }
          PKCS12_free(p12);
          iVar6 = SSL_CTX_use_certificate(local_f8,local_cc);
          if (iVar6 != 1) {
            uVar17 = ERR_get_error();
            pcVar21 = ERR_error_string(uVar17,(char *)0x0);
            Curl_failf(local_100,"could not load PKCS12 client certificate, OpenSSL error %s",
                       pcVar21);
LAB_00058d50:
            EVP_PKEY_free(local_c8);
            X509_free(local_cc);
            sk_pop_free(local_c4,X509_free);
            return 0x3a;
          }
          iVar6 = SSL_CTX_use_PrivateKey(local_f8,local_c8);
          if (iVar6 != 1) {
            Curl_failf(local_100,"unable to use private key from PKCS12 file \'%s\'",pcVar21);
            goto LAB_00058d50;
          }
          iVar6 = SSL_CTX_check_private_key(local_f8);
          if (iVar6 == 0) {
            Curl_failf(local_100,
                       "private key from PKCS12 file \'%s\' does not match certificate in same file"
                       ,pcVar21);
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
                Curl_failf(local_100,"cannot add certificate to certificate chain");
                goto LAB_00058d50;
              }
              iVar6 = SSL_CTX_add_client_CA(local_f8,pXVar9);
            } while (iVar6 != 0);
            Curl_failf(local_100,"cannot add certificate to client CA list");
            goto LAB_00058d50;
          }
LAB_0005974e:
          bVar3 = true;
          EVP_PKEY_free(local_c8);
          X509_free(local_cc);
          sk_pop_free(local_c4,X509_free);
        }
      }
      iVar6 = do_file_type(local_e8);
      if (iVar6 == 2) {
LAB_000590aa:
        iVar6 = SSL_CTX_use_PrivateKey_file(local_f8,local_f0,iVar6);
        if (iVar6 != 1) {
          puVar28 = &DAT_0013ae10;
          if (local_e8 != (undefined *)0x0) {
            puVar28 = local_e8;
          }
          Curl_failf(local_100,"unable to set private key file: \'%s\' type %s",local_f0,puVar28);
          return 0x3a;
        }
      }
      else if (iVar6 < 3) {
        if (iVar6 != 1) {
LAB_00058b38:
          Curl_failf(local_100,"not supported file type for private key");
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
          Curl_failf(local_100,"crypto engine not set, can\'t load private key");
          return 0x3a;
        }
        method = UI_create_method("cURL user interface");
        if (method == (UI_METHOD *)0x0) {
          Curl_failf(local_100,"unable do create OpenSSL user-interface method");
          return 0x3a;
        }
        pUVar24 = UI_OpenSSL();
        opener = (opener *)UI_method_get_opener((UI *)pUVar24);
        UI_method_set_opener(method,opener);
        pUVar24 = UI_OpenSSL();
        closer = (closer *)UI_method_get_closer((UI *)pUVar24);
        UI_method_set_closer(method,closer);
        UI_method_set_reader(method,(reader *)0x57625);
        UI_method_set_writer(method,(writer *)0x575e9);
        pEVar19 = ENGINE_load_private_key
                            (*(ENGINE **)(local_100 + 0x8648),local_f0,method,
                             *(void **)(local_100 + 0x370));
        UI_destroy_method(method);
        if (pEVar19 == (EVP_PKEY *)0x0) {
          Curl_failf(local_100,"failed to load private key from crypto engine");
          return 0x3a;
        }
        iVar6 = SSL_CTX_use_PrivateKey(local_f8,pEVar19);
        if (iVar6 != 1) {
          Curl_failf(local_100,"unable to set private key");
          EVP_PKEY_free(pEVar19);
          return 0x3a;
        }
        EVP_PKEY_free(pEVar19);
      }
      else {
        if (iVar6 != 0x2b) goto LAB_00058b38;
        if (!bVar3) {
          Curl_failf(local_100,"file type P12 for private key not supported");
          return 0x3a;
        }
      }
      pSVar23 = SSL_new(local_f8);
      if (pSVar23 == (SSL *)0x0) {
        Curl_failf(local_100,"unable to create an SSL structure");
        return 0x3a;
      }
      local_cc = SSL_get_certificate(pSVar23);
      if (local_cc != (X509 *)0x0) {
        pEVar19 = X509_get_pubkey(local_cc);
        from = SSL_get_privatekey(pSVar23);
        EVP_PKEY_copy_parameters(pEVar19,from);
        EVP_PKEY_free(pEVar19);
      }
      SSL_free(pSVar23);
      iVar6 = SSL_CTX_check_private_key(local_f8);
      if (iVar6 == 0) {
        Curl_failf(local_100,"Private key does not match the certificate public key");
        return 0x3a;
      }
    }
    pcVar21 = *(char **)(iVar13 + 0x39c);
    if (pcVar21 == (char *)0x0) {
      pcVar21 = "ALL:!EXPORT:!EXPORT40:!EXPORT56:!aNULL:!LOW:!RC4:@STRENGTH";
    }
    iVar6 = SSL_CTX_set_cipher_list((SSL_CTX *)param_1[param_2 * 6 + 0x61],pcVar21);
    if (iVar6 == 0) {
      Curl_failf(iVar13,"failed setting cipher list: %s",pcVar21);
      return 0x3b;
    }
    Curl_infof(iVar13,"Cipher selection: %s\n",pcVar21);
    if (*(int *)(iVar13 + 0x2c0) == 1) {
      Curl_infof(iVar13,"Using TLS-SRP username: %s\n",*(undefined4 *)(iVar13 + 0x2b8));
      iVar6 = SSL_CTX_set_srp_username(param_1[param_2 * 6 + 0x61],*(undefined4 *)(iVar13 + 0x2b8));
      if (iVar6 == 0) {
        Curl_failf(iVar13,"Unable to set SRP user name");
        return 0x2b;
      }
      iVar6 = SSL_CTX_set_srp_password(param_1[param_2 * 6 + 0x61],*(undefined4 *)(iVar13 + 700));
      if (iVar6 == 0) {
        Curl_failf(iVar13,"failed setting SRP password");
        return 0x2b;
      }
      if (*(int *)(iVar13 + 0x39c) == 0) {
        Curl_infof(iVar13,"Setting cipher list SRP\n");
        iVar6 = SSL_CTX_set_cipher_list((SSL_CTX *)param_1[param_2 * 6 + 0x61],"SRP");
        if (iVar6 == 0) {
          Curl_failf(iVar13,"failed setting SRP cipher list");
          return 0x3b;
        }
      }
    }
    if ((*(char **)(iVar13 + 0x394) != (char *)0x0) || (*(char **)(iVar13 + 0x390) != (char *)0x0))
    {
      iVar6 = SSL_CTX_load_verify_locations
                        ((SSL_CTX *)param_1[param_2 * 6 + 0x61],*(char **)(iVar13 + 0x394),
                         *(char **)(iVar13 + 0x390));
      if (iVar6 == 0) {
        if (*(char *)(iVar13 + 0x288) != '\0') {
          pcVar21 = *(char **)(iVar13 + 0x394);
          pcVar31 = *(char **)(iVar13 + 0x390);
          if (pcVar21 == (char *)0x0) {
            pcVar21 = "none";
          }
          if (pcVar31 == (char *)0x0) {
            pcVar31 = "none";
          }
          Curl_failf(iVar13,
                     "error setting certificate verify locations:\n  CAfile: %s\n  CApath: %s",
                     pcVar21,pcVar31);
          return 0x4d;
        }
        Curl_infof(iVar13,"error setting certificate verify locations, continuing anyway:\n");
      }
      else {
        Curl_infof(iVar13,"successfully set certificate verify locations:\n");
      }
      pcVar21 = *(char **)(iVar13 + 0x394);
      if (pcVar21 == (char *)0x0) {
        pcVar21 = "none";
      }
      pcVar31 = "none";
      if (*(char **)(iVar13 + 0x390) != (char *)0x0) {
        pcVar31 = *(char **)(iVar13 + 0x390);
      }
      Curl_infof(iVar13,"  CAfile: %s\n  CApath: %s\n",pcVar21,pcVar31);
    }
    if (*(int *)(iVar13 + 0x3ac) != 0) {
      pXVar25 = SSL_CTX_get_cert_store((SSL_CTX *)param_1[param_2 * 6 + 0x61]);
      m = X509_LOOKUP_file();
      ctx_00 = X509_STORE_add_lookup(pXVar25,m);
      if ((ctx_00 == (X509_LOOKUP *)0x0) ||
         (iVar6 = X509_load_crl_file(ctx_00,*(char **)(iVar13 + 0x3ac),1), iVar6 == 0)) {
        Curl_failf(iVar13,"error loading CRL file: %s",*(undefined4 *)(iVar13 + 0x3ac));
        return 0x52;
      }
      Curl_infof(iVar13,"successfully load CRL file:\n");
      pXVar25 = SSL_CTX_get_cert_store((SSL_CTX *)param_1[param_2 * 6 + 0x61]);
      X509_STORE_set_flags(pXVar25,0xc);
      pcVar21 = *(char **)(iVar13 + 0x3ac);
      if (pcVar21 == (char *)0x0) {
        pcVar21 = "none";
      }
      Curl_infof(iVar13,"  CRLfile: %s\n",pcVar21);
    }
    SSL_CTX_set_verify((SSL_CTX *)param_1[param_2 * 6 + 0x61],(uint)*(byte *)(iVar13 + 0x288),
                       (callback *)0x0);
    if ((*(code **)(iVar13 + 0x2ac) != (code *)0x0) &&
       (iVar6 = (**(code **)(iVar13 + 0x2ac))
                          (iVar13,param_1[param_2 * 6 + 0x61],*(undefined4 *)(iVar13 + 0x2b0)),
       iVar6 != 0)) {
      Curl_failf(iVar13,"error signaled by ssl ctx callback");
      return iVar6;
    }
    if ((SSL *)param_1[param_2 * 6 + 0x62] != (SSL *)0x0) {
      SSL_free((SSL *)param_1[param_2 * 6 + 0x62]);
    }
    pSVar23 = SSL_new((SSL_CTX *)param_1[param_2 * 6 + 0x61]);
    param_1[param_2 * 6 + 0x62] = (int)pSVar23;
    if (pSVar23 == (SSL *)0x0) {
      Curl_failf(iVar13,"SSL: couldn\'t create a context (handle)!");
      return 0x1b;
    }
    if (*(char *)(iVar13 + 0x28a) != '\0') {
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
      Curl_infof(iVar13,"WARNING: failed to configure server name indication (SNI) TLS extension\n")
      ;
    }
    iVar6 = Curl_ssl_getsessionid(param_1,&local_d4,0);
    if (iVar6 == 0) {
      iVar6 = SSL_set_session((SSL *)param_1[param_2 * 6 + 0x62],local_d4);
      if (iVar6 == 0) {
        uVar17 = ERR_get_error();
        pcVar21 = ERR_error_string(uVar17,(char *)0x0);
        Curl_failf(iVar13,"SSL: SSL_set_session failed: %s",pcVar21);
        return 0x23;
      }
      Curl_infof(iVar13,"SSL re-using session ID\n");
    }
    iVar5 = SSL_set_fd((SSL *)param_1[param_2 * 6 + 0x62],iVar5);
    if (iVar5 == 0) {
      uVar17 = ERR_get_error();
      pcVar21 = ERR_error_string(uVar17,(char *)0x0);
      Curl_failf(iVar13,"SSL: SSL_set_fd failed: %s",pcVar21);
      return 0x23;
    }
    pSVar27 = (SSL_SESSION *)0x1;
    param_1[param_2 * 6 + 0x60] = 1;
  }
  while ((undefined1 *)((int)&pSVar27[-1].tlsext_tick_lifetime_hint + 3U) < (undefined1 *)0x3) {
    iVar5 = Curl_timeleft(iVar33,0,1);
    if (iVar5 < 0) goto LAB_00058078;
    if (param_1[param_2 * 6 + 0x60] - 2U < 2) {
      if (param_1[param_2 * 6 + 0x60] == 3) {
        iVar6 = -1;
        iVar13 = iVar34;
      }
      else {
        iVar6 = iVar34;
        iVar13 = -1;
      }
      if (param_3 != 0) {
        iVar5 = 0;
      }
      iVar5 = Curl_socket_check(iVar6,0xffffffff,iVar13,iVar5);
      if (iVar5 < 0) {
        piVar7 = __errno_location();
        Curl_failf(iVar33,"select/poll on SSL socket, errno: %d",*piVar7);
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
    pSVar27 = (SSL_SESSION *)param_1[param_2 * 6 + 0x60];
    if ((param_3 != 0) &&
       ((undefined1 *)((int)&pSVar27[-1].tlsext_tick_lifetime_hint + 3U) < (undefined1 *)0x3)) {
      return 0;
    }
  }
  if (pSVar27 == (SSL_SESSION *)0x4) {
    local_dc = (SSL_SESSION *)0x0;
    iVar34 = *param_1;
    pSVar27 = SSL_get1_session((SSL *)param_1[param_2 * 6 + 0x62]);
    iVar33 = Curl_ssl_getsessionid(param_1,&local_dc,0);
    if (iVar33 == 0) {
      if (pSVar27 != local_dc) {
        Curl_infof(iVar34,"old SSL session ID is stale, removing\n");
        Curl_ssl_delsessionid(param_1,local_dc);
        goto LAB_000582f8;
      }
      SSL_SESSION_free(pSVar27);
    }
    else {
LAB_000582f8:
      iVar33 = Curl_ssl_addsessionid(param_1,pSVar27,0);
      if (iVar33 != 0) {
        Curl_failf(iVar34,"failed to store ssl session");
        return iVar33;
      }
    }
    if (*(char *)(iVar34 + 0x288) == '\0') {
      cVar2 = *(char *)(iVar34 + 0x289);
    }
    else {
      cVar2 = '\x01';
    }
    iVar33 = *param_1;
    pBVar8 = BIO_s_mem();
    fp = BIO_new(pBVar8);
    if (*(char *)(iVar33 + 0x2b5) != '\0') {
      iVar34 = *param_1;
      p_Var12 = &SSL_get_peer_cert_chain((SSL *)param_1[param_2 * 6 + 0x62])->stack;
      if (p_Var12 != (_STACK *)0x0) {
        iVar5 = sk_num(p_Var12);
        iVar13 = Curl_ssl_init_certinfo(iVar34,iVar5);
        if (iVar13 == 0) {
          pBVar8 = BIO_s_mem();
          out = BIO_new(pBVar8);
          if (0 < iVar5) {
            iVar13 = 0;
            do {
              pXVar9 = (X509 *)sk_value(p_Var12,iVar13);
              pXVar10 = X509_get_subject_name(pXVar9);
              X509_NAME_print_ex(out,pXVar10,0,0x82031f);
              lVar11 = BIO_ctrl(out,3,0,&local_c4);
              Curl_ssl_push_certinfo_len(iVar34,iVar13,"Subject",local_c4,lVar11);
              BIO_ctrl(out,1,0,(void *)0x0);
              pXVar10 = X509_get_issuer_name(pXVar9);
              X509_NAME_print_ex(out,pXVar10,0,0x82031f);
              lVar11 = BIO_ctrl(out,3,0,&local_c4);
              Curl_ssl_push_certinfo_len(iVar34,iVar13,"Issuer",local_c4,lVar11);
              BIO_ctrl(out,1,0,(void *)0x0);
              lVar11 = ASN1_INTEGER_get(pXVar9->cert_info->version);
              BIO_printf(out,"%lx",lVar11);
              lVar11 = BIO_ctrl(out,3,0,&local_c4);
              Curl_ssl_push_certinfo_len(iVar34,iVar13,"Version",local_c4,lVar11);
              BIO_ctrl(out,1,0,(void *)0x0);
              pAVar18 = X509_get_serialNumber(pXVar9);
              if (pAVar18->type == 0x102) {
                BIO_puts(out,"-");
              }
              if (0 < pAVar18->length) {
                iVar6 = 0;
                do {
                  pbVar1 = pAVar18->data + iVar6;
                  iVar6 = iVar6 + 1;
                  BIO_printf(out,"%02x",(uint)*pbVar1);
                } while (iVar6 < pAVar18->length);
              }
              lVar11 = BIO_ctrl(out,3,0,&local_c4);
              Curl_ssl_push_certinfo_len(iVar34,iVar13,"Serial Number",local_c4,lVar11);
              BIO_ctrl(out,1,0,(void *)0x0);
              pXVar29 = pXVar9->cert_info;
              i2a_ASN1_OBJECT(out,pXVar29->signature->algorithm);
              lVar11 = BIO_ctrl(out,3,0,&local_c4);
              Curl_ssl_push_certinfo_len(iVar34,iVar13,"Signature Algorithm",local_c4,lVar11);
              BIO_ctrl(out,1,0,(void *)0x0);
              i2a_ASN1_OBJECT(out,pXVar29->key->algor->algorithm);
              lVar11 = BIO_ctrl(out,3,0,&local_c4);
              Curl_ssl_push_certinfo_len(iVar34,iVar13,"Public Key Algorithm",local_c4,lVar11);
              BIO_ctrl(out,1,0,(void *)0x0);
              X509V3_ext(iVar34,iVar13,pXVar29->extensions);
              pAVar30 = pXVar9->signature;
              ASN1_TIME_print(out,pXVar9->cert_info->validity->notBefore);
              lVar11 = BIO_ctrl(out,3,0,&local_c4);
              Curl_ssl_push_certinfo_len(iVar34,iVar13,"Start date",local_c4,lVar11);
              BIO_ctrl(out,1,0,(void *)0x0);
              ASN1_TIME_print(out,pXVar9->cert_info->validity->notAfter);
              lVar11 = BIO_ctrl(out,3,0,&local_c4);
              Curl_ssl_push_certinfo_len(iVar34,iVar13,"Expire date",local_c4,lVar11);
              BIO_ctrl(out,1,0,(void *)0x0);
              pEVar19 = X509_get_pubkey(pXVar9);
              if (pEVar19 == (EVP_PKEY *)0x0) {
                Curl_infof(iVar34,"   Unable to load public key\n");
              }
              else {
                iVar6 = pEVar19->type;
                if (iVar6 == 0x1c) {
                  prVar32 = (pEVar19->pkey).rsa;
                  if (prVar32->meth != (RSA_METHOD *)0x0) {
                    pubkey_show(iVar34,out,iVar13,&DAT_001357d0,"p",prVar32->meth);
                  }
                  if (prVar32->engine != (ENGINE *)0x0) {
                    pubkey_show(iVar34,out,iVar13,&DAT_001357d0,"g",prVar32->engine);
                  }
                  if (prVar32->d != (BIGNUM *)0x0) {
                    pubkey_show(iVar34,out,iVar13,&DAT_001357d0,"priv_key",prVar32->d);
                  }
                  if (prVar32->e != (BIGNUM *)0x0) {
                    pubkey_show(iVar34,out,iVar13,&DAT_001357d0,"pub_key",prVar32->e);
                  }
                }
                else if (iVar6 == 0x74) {
                  prVar32 = (pEVar19->pkey).rsa;
                  if (prVar32->engine != (ENGINE *)0x0) {
                    pubkey_show(iVar34,out,iVar13,&DAT_0013b8b4,"p",prVar32->engine);
                  }
                  if (prVar32->n != (BIGNUM *)0x0) {
                    pubkey_show(iVar34,out,iVar13,&DAT_0013b8b4,"q",prVar32->n);
                  }
                  if (prVar32->e != (BIGNUM *)0x0) {
                    pubkey_show(iVar34,out,iVar13,&DAT_0013b8b4,"g",prVar32->e);
                  }
                  if (prVar32->p != (BIGNUM *)0x0) {
                    pubkey_show(iVar34,out,iVar13,&DAT_0013b8b4,"priv_key",prVar32->p);
                  }
                  if (prVar32->d != (BIGNUM *)0x0) {
                    pubkey_show(iVar34,out,iVar13,&DAT_0013b8b4,"pub_key",prVar32->d);
                  }
                }
                else if (iVar6 == 6) {
                  prVar32 = (pEVar19->pkey).rsa;
                  iVar6 = BN_num_bits(prVar32->n);
                  BIO_printf(out,"%d",iVar6);
                  lVar11 = BIO_ctrl(out,3,0,&local_c4);
                  Curl_ssl_push_certinfo_len(iVar34,iVar13,"RSA Public Key",local_c4,lVar11);
                  BIO_ctrl(out,1,0,(void *)0x0);
                  if (prVar32->n != (BIGNUM *)0x0) {
                    pubkey_show(iVar34,out,iVar13,&DAT_0013b898,"n",prVar32->n);
                  }
                  if (prVar32->e != (BIGNUM *)0x0) {
                    pubkey_show(iVar34,out,iVar13,&DAT_0013b898,&DAT_0015175c,prVar32->e);
                  }
                  if (prVar32->d != (BIGNUM *)0x0) {
                    pubkey_show(iVar34,out,iVar13,&DAT_0013b898,"d",prVar32->d);
                  }
                  if (prVar32->p != (BIGNUM *)0x0) {
                    pubkey_show(iVar34,out,iVar13,&DAT_0013b898,"p",prVar32->p);
                  }
                  if (prVar32->q != (BIGNUM *)0x0) {
                    pubkey_show(iVar34,out,iVar13,&DAT_0013b898,"q",prVar32->q);
                  }
                  if (prVar32->dmp1 != (BIGNUM *)0x0) {
                    pubkey_show(iVar34,out,iVar13,&DAT_0013b898,&DAT_0013b89c,prVar32->dmp1);
                  }
                  if (prVar32->dmq1 != (BIGNUM *)0x0) {
                    pubkey_show(iVar34,out,iVar13,&DAT_0013b898,&DAT_0013b8a4,prVar32->dmq1);
                  }
                  if (prVar32->iqmp != (BIGNUM *)0x0) {
                    pubkey_show(iVar34,out,iVar13,&DAT_0013b898,&DAT_0013b8ac,prVar32->iqmp);
                  }
                }
                EVP_PKEY_free(pEVar19);
              }
              if (0 < pAVar30->length) {
                iVar6 = 0;
                do {
                  pbVar1 = pAVar30->data + iVar6;
                  iVar6 = iVar6 + 1;
                  BIO_printf(out,"%02x:",(uint)*pbVar1);
                } while (iVar6 < pAVar30->length);
              }
              lVar11 = BIO_ctrl(out,3,0,&local_c4);
              Curl_ssl_push_certinfo_len(iVar34,iVar13,"Signature",local_c4,lVar11);
              BIO_ctrl(out,1,0,(void *)0x0);
              PEM_write_bio_X509(out,pXVar9);
              lVar11 = BIO_ctrl(out,3,0,&local_c4);
              iVar6 = iVar13 + 1;
              Curl_ssl_push_certinfo_len(iVar34,iVar13,"Cert",local_c4,lVar11);
              BIO_ctrl(out,1,0,(void *)0x0);
              iVar13 = iVar6;
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
        Curl_failf(iVar33,"SSL: couldn\'t get peer certificate!");
        return 0x33;
      }
    }
    else {
      Curl_infof(iVar33,"Server certificate:\n");
      pcVar31 = (char *)(iVar33 + 0x59c);
      pXVar10 = X509_get_subject_name((X509 *)param_1[param_2 * 6 + 99]);
      iVar34 = x509_name_oneline_constprop_5(pXVar10,pcVar31);
      pcVar21 = "[NONE]";
      if (iVar34 == 0) {
        pcVar21 = pcVar31;
      }
      Curl_infof(iVar33," subject: %s\n",pcVar21);
      ASN1_TIME_print(fp,(ASN1_TIME *)**(undefined4 **)(*(int *)param_1[param_2 * 6 + 99] + 0x10));
      lVar11 = BIO_ctrl(fp,3,0,&local_d8);
      Curl_infof(iVar33," start date: %.*s\n",lVar11,local_d8);
      BIO_ctrl(fp,1,0,(void *)0x0);
      ASN1_TIME_print(fp,*(ASN1_TIME **)(*(int *)(*(int *)param_1[param_2 * 6 + 99] + 0x10) + 4));
      lVar11 = BIO_ctrl(fp,3,0,&local_d8);
      Curl_infof(iVar33," expire date: %.*s\n",lVar11,local_d8);
      BIO_ctrl(fp,1,0,(void *)0x0);
      BIO_free(fp);
      if (*(char *)(iVar33 + 0x289) != '\0') {
        pXVar9 = (X509 *)param_1[param_2 * 6 + 99];
        iVar34 = *param_1;
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
        if (p_Var12 != (_STACK *)0x0) {
          iVar13 = sk_num(p_Var12);
          if (iVar13 < 1) {
            GENERAL_NAMES_free((GENERAL_NAMES *)p_Var12);
          }
          else {
            iVar6 = 0;
            do {
              piVar7 = (int *)sk_value(p_Var12,iVar6);
              if (*piVar7 == iVar5) {
                puVar14 = ASN1_STRING_data((ASN1_STRING *)piVar7[1]);
                sVar15 = ASN1_STRING_length((ASN1_STRING *)piVar7[1]);
                if (iVar5 == 2) {
                  sVar22 = strlen((char *)puVar14);
                  if ((sVar15 == sVar22) &&
                     (iVar16 = Curl_cert_hostcheck(puVar14,param_1[0x26]), iVar16 != 0)) {
                    Curl_infof(iVar34," subjectAltName: host \"%s\" matched cert\'s \"%s\"\n",
                               param_1[0x27],puVar14);
                    goto LAB_0005849c;
                  }
                }
                else if (((iVar5 == 7) && ((char *)sVar15 == local_f0)) &&
                        (iVar16 = memcmp(puVar14,&local_a8,(size_t)local_f0), iVar16 == 0)) {
                  Curl_infof(iVar34," subjectAltName: host \"%s\" matched cert\'s IP address!\n",
                             param_1[0x27]);
LAB_0005849c:
                  GENERAL_NAMES_free((GENERAL_NAMES *)p_Var12);
                  goto LAB_000584a2;
                }
              }
              iVar6 = iVar6 + 1;
            } while (iVar6 != iVar13);
            GENERAL_NAMES_free((GENERAL_NAMES *)p_Var12);
          }
          iVar5 = 0x33;
          Curl_infof(iVar34," subjectAltName does not match %s\n",param_1[0x27]);
          Curl_failf(iVar34,
                     "SSL: no alternative certificate subject name matches target host name \'%s\'",
                     param_1[0x27]);
          goto LAB_00058b68;
        }
        local_c4 = (_STACK *)&DAT_0013a6fc;
        pXVar10 = X509_get_subject_name(pXVar9);
        if (pXVar10 == (X509_NAME *)0x0) {
LAB_00058f84:
          iVar5 = 0;
LAB_00058f88:
          if (local_c4 == (_STACK *)&DAT_0013a6fc) {
            local_c4 = (_STACK *)0x0;
          }
          if (iVar5 == 0) {
LAB_00058f9a:
            if (local_c4 == (_STACK *)0x0) goto LAB_000596f0;
            iVar5 = Curl_cert_hostcheck(local_c4,param_1[0x26]);
            if (iVar5 == 0) {
              iVar5 = 0x33;
              Curl_failf(iVar34,
                         "SSL: certificate subject name \'%s\' does not match target host name \'%s\'"
                         ,local_c4,param_1[0x27]);
            }
            else {
              iVar5 = 0;
              Curl_infof(iVar34," common name: %s (matched)\n",local_c4);
            }
          }
        }
        else {
          iVar5 = -1;
          do {
            iVar13 = iVar5;
            iVar5 = X509_NAME_get_index_by_NID(pXVar10,0xd,iVar13);
          } while (-1 < iVar5);
          if (iVar13 < 0) goto LAB_00058f84;
          ne = X509_NAME_get_entry(pXVar10,iVar13);
          x = X509_NAME_ENTRY_get_data(ne);
          if (x == (ASN1_STRING *)0x0) goto LAB_00058f84;
          iVar5 = ASN1_STRING_type(x);
          if (iVar5 == 0xc) {
            sVar15 = ASN1_STRING_length(x);
            if ((int)sVar15 < 0) goto LAB_00059592;
            p_Var12 = (_STACK *)CRYPTO_malloc(sVar15 + 1,"vtls/openssl.c",0x48a);
            local_c4 = p_Var12;
            if (p_Var12 != (_STACK *)0x0) {
              puVar14 = ASN1_STRING_data(x);
              memcpy(p_Var12,puVar14,sVar15);
              *(undefined1 *)((int)&local_c4->num + sVar15) = 0;
              goto LAB_00059592;
            }
            goto LAB_00058f9a;
          }
          sVar15 = ASN1_STRING_to_UTF8((uchar **)&local_c4,x);
LAB_00059592:
          if (local_c4 != (_STACK *)0x0) {
            strlen((char *)local_c4);
            sVar22 = curlx_uztosi();
            if (sVar22 == sVar15) goto LAB_00058f84;
            iVar5 = 0x33;
            Curl_failf(iVar34,"SSL: illegal cert name field");
            goto LAB_00058f88;
          }
LAB_000596f0:
          Curl_failf(iVar34,"SSL: unable to obtain common name from peer certificate");
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
      iVar34 = x509_name_oneline_constprop_5(pXVar10,pcVar31);
      if (iVar34 == 0) {
        Curl_infof(iVar33," issuer: %s\n",pcVar31);
        if (*(char **)(iVar33 + 0x3b0) != (char *)0x0) {
          pFVar20 = fopen64(*(char **)(iVar33 + 0x3b0),"r");
          if (pFVar20 == (FILE *)0x0) {
            if (cVar2 != '\0') {
              Curl_failf(iVar33,"SSL: Unable to open issuer cert (%s)",
                         *(undefined4 *)(iVar33 + 0x3b0));
            }
            X509_free((X509 *)param_1[param_2 * 6 + 99]);
            param_1[param_2 * 6 + 99] = 0;
            return 0x53;
          }
          pXVar9 = PEM_read_X509(pFVar20,(X509 **)0x0,(undefined1 *)0x0,(void *)0x0);
          if (pXVar9 == (X509 *)0x0) {
            if (cVar2 != '\0') {
              Curl_failf(iVar33,"SSL: Unable to read issuer cert (%s)",
                         *(undefined4 *)(iVar33 + 0x3b0));
            }
            X509_free((X509 *)param_1[param_2 * 6 + 99]);
            X509_free((X509 *)0x0);
            fclose(pFVar20);
            return 0x53;
          }
          fclose(pFVar20);
          iVar34 = X509_check_issued(pXVar9,(X509 *)param_1[param_2 * 6 + 99]);
          if (iVar34 != 0) {
            if (cVar2 != '\0') {
              Curl_failf(iVar33,"SSL: Certificate issuer check failed (%s)",
                         *(undefined4 *)(iVar33 + 0x3b0));
            }
            X509_free((X509 *)param_1[param_2 * 6 + 99]);
            X509_free(pXVar9);
            param_1[param_2 * 6 + 99] = 0;
            return 0x53;
          }
          Curl_infof(iVar33," SSL certificate issuer check ok (%s)\n",
                     *(undefined4 *)(iVar33 + 0x3b0));
          X509_free(pXVar9);
        }
        lVar11 = SSL_get_verify_result((SSL *)param_1[param_2 * 6 + 0x62]);
        *(long *)(iVar33 + 0x284) = lVar11;
        if (lVar11 == 0) {
          Curl_infof(iVar33," SSL certificate verify ok.\n");
          iVar34 = 0;
        }
        else if (*(char *)(iVar33 + 0x288) == '\0') {
          pcVar21 = X509_verify_cert_error_string(lVar11);
          Curl_infof(iVar33," SSL certificate verify result: %s (%ld), continuing anyway.\n",pcVar21
                     ,lVar11);
          iVar34 = 0;
        }
        else if (cVar2 == '\0') {
          iVar34 = 0x33;
        }
        else {
          pcVar21 = X509_verify_cert_error_string(lVar11);
          iVar34 = 0x33;
          Curl_failf(iVar33,"SSL certificate verify result: %s (%ld)",pcVar21,lVar11);
        }
      }
      else {
        iVar34 = 0x23;
        if (cVar2 != '\0') {
          iVar34 = 0x23;
          Curl_failf(iVar33,"SSL: couldn\'t get X509-issuer name!");
        }
      }
      if (*(char *)(iVar33 + 0x28a) != '\0') {
        iVar34 = *param_1;
        lVar11 = SSL_ctrl((SSL *)param_1[param_2 * 6 + 0x62],0x46,0,&local_d4);
        if (local_d4 == (SSL_SESSION *)0x0) {
          Curl_failf(iVar34,"No OCSP response received");
          resp = (OCSP_RESPONSE *)0x0;
          goto LAB_00058c3c;
        }
        resp = d2i_OCSP_RESPONSE((OCSP_RESPONSE **)0x0,(uchar **)&local_d4,lVar11);
        if (resp != (OCSP_RESPONSE *)0x0) {
          iVar5 = OCSP_response_status(resp);
          if (iVar5 != 0) {
            pcVar21 = OCSP_response_status_str(iVar5);
            Curl_failf(iVar34,"Invalid OCSP response status: %s (%d)",pcVar21,iVar5);
            goto LAB_00058c3c;
          }
          bs = OCSP_response_get1_basic(resp);
          if (bs != (OCSP_BASICRESP *)0x0) {
            certs = SSL_get_peer_cert_chain((SSL *)param_1[param_2 * 6 + 0x62]);
            pXVar25 = SSL_CTX_get_cert_store((SSL_CTX *)param_1[param_2 * 6 + 0x61]);
            iVar5 = OCSP_basic_verify(bs,certs,pXVar25,0);
            if (iVar5 < 1) {
              Curl_failf(iVar34,"OCSP response verification failed");
            }
            else {
              iVar5 = 0;
              do {
                do {
                  iVar13 = OCSP_resp_count(bs);
                  iVar6 = iVar5 + 1;
                  if (iVar13 <= iVar5) {
                    iVar34 = 0;
                    OCSP_BASICRESP_free(bs);
                    OCSP_RESPONSE_free(resp);
                    goto LAB_000584ce;
                  }
                  single = OCSP_resp_get0(bs,iVar5);
                  iVar5 = iVar6;
                } while (single == (OCSP_SINGLERESP *)0x0);
                iVar13 = OCSP_single_get0_status
                                   (single,&local_d0,(ASN1_GENERALIZEDTIME **)&local_cc,
                                    (ASN1_GENERALIZEDTIME **)&local_c8,
                                    (ASN1_GENERALIZEDTIME **)&local_c4);
                iVar6 = OCSP_check_validity((ASN1_GENERALIZEDTIME *)local_c8,
                                            (ASN1_GENERALIZEDTIME *)local_c4,300,-1);
                if (iVar6 == 0) {
                  Curl_failf(iVar34,"OCSP response has expired");
                  break;
                }
                pcVar21 = OCSP_cert_status_str(iVar13);
                Curl_infof(iVar34,"SSL certificate status: %s (%d)\n",pcVar21,iVar13);
                if (iVar13 == 1) {
                  pcVar21 = OCSP_crl_reason_str(local_d0);
                  Curl_failf(iVar34,"SSL certificate revocation reason: %s (%d)",pcVar21,local_d0);
                  break;
                }
              } while (iVar13 != 2);
            }
            OCSP_BASICRESP_free(bs);
            goto LAB_00058c3c;
          }
        }
        Curl_failf(iVar34,"Invalid OCSP response");
LAB_00058c3c:
        OCSP_RESPONSE_free(resp);
        X509_free((X509 *)param_1[param_2 * 6 + 99]);
        param_1[param_2 * 6 + 99] = 0;
        return 0x5b;
      }
LAB_000584ce:
      if (cVar2 == '\0') {
        iVar5 = *(int *)(iVar33 + 0x398);
      }
      else {
        iVar5 = *(int *)(iVar33 + 0x398);
        local_d8 = iVar5;
        if (iVar34 != 0) goto LAB_000584e8;
      }
      local_d8 = iVar5;
      if (iVar5 != 0) {
        piVar7 = (int *)param_1[param_2 * 6 + 99];
        local_c4 = (_STACK *)0x0;
        if (((piVar7 == (int *)0x0) ||
            (iVar34 = i2d_X509_PUBKEY(*(X509_PUBKEY **)(*piVar7 + 0x18),(uchar **)0x0), iVar34 < 1))
           || (p_Var12 = (_STACK *)CRYPTO_malloc(iVar34,"vtls/openssl.c",0x9be), local_c4 = p_Var12,
              p_Var12 == (_STACK *)0x0)) {
          iVar34 = 0x5a;
        }
        else {
          iVar13 = i2d_X509_PUBKEY(*(X509_PUBKEY **)(*piVar7 + 0x18),(uchar **)&local_c4);
          if (((iVar34 == iVar13) && (local_c4 != (_STACK *)0x0)) &&
             (iVar34 == (int)local_c4 - (int)p_Var12)) {
            iVar34 = Curl_pin_peer_pubkey(iVar33,iVar5,p_Var12,iVar34);
            CRYPTO_free(p_Var12);
            if (iVar34 == 0) goto LAB_00058276;
          }
          else {
            iVar34 = 0x5a;
            CRYPTO_free(p_Var12);
          }
        }
        Curl_failf(iVar33,"SSL: public key does not match pinned public key!");
LAB_000584e8:
        X509_free((X509 *)param_1[param_2 * 6 + 99]);
        param_1[param_2 * 6 + 99] = 0;
        param_1[param_2 * 6 + 0x60] = 5;
        return iVar34;
      }
LAB_00058276:
      X509_free((X509 *)param_1[param_2 * 6 + 99]);
      param_1[param_2 * 6 + 99] = 0;
    }
  }
  else if (pSVar27 != (SSL_SESSION *)&DAT_00000005) {
    *param_4 = 0;
    goto LAB_0005814e;
  }
  param_1[param_2 * 6 + 0x5f] = 2;
  param_1[param_2 + 0x5a] = 0x57ba9;
  param_1[param_2 + 0x5c] = 0x57b05;
  *param_4 = 1;
LAB_0005814e:
  param_1[param_2 * 6 + 0x60] = 0;
  return 0;
}

