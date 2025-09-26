
char * tls13_change_cipher_state(int param_1,uint param_2)

{
  EVP_MD *type;
  int iVar1;
  size_t sVar2;
  EVP_MD_CTX *ctx;
  ulong uVar3;
  undefined4 uVar4;
  int iVar5;
  void *__dest;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  EVP_MD *pEVar9;
  bool bVar10;
  bool bVar11;
  int local_118;
  uchar *local_114;
  int local_110;
  char *local_10c;
  undefined4 local_108;
  int local_104;
  EVP_CIPHER_CTX *local_100;
  int local_fc;
  int local_f8;
  int local_f4;
  size_t local_ec;
  void *local_e8 [16];
  uchar auStack_a8 [64];
  size_t local_68 [17];
  
  local_ec = 0;
  if (-1 < (int)(param_2 << 0x1f)) {
    *(undefined4 *)(param_1 + 0x60) = 1;
    if (*(int *)(param_1 + 0x3ec) == 0) {
      local_100 = EVP_CIPHER_CTX_new();
      *(EVP_CIPHER_CTX **)(param_1 + 0x3ec) = local_100;
      if (local_100 == (EVP_CIPHER_CTX *)0x0) {
        uVar4 = 0x1f1;
        goto LAB_00107a0c;
      }
    }
    else {
      EVP_CIPHER_CTX_reset();
      local_100 = *(EVP_CIPHER_CTX **)(param_1 + 0x3ec);
    }
    local_104 = param_1 + 0x3f0;
    RECORD_LAYER_reset_write_sequence(param_1 + 0x650);
    if ((param_2 & 0x12) != 0x12) goto LAB_001074a6;
LAB_0010742e:
    if ((int)(param_2 << 0x19) < 0) {
      iVar5 = SSL_SESSION_get0_cipher(*(undefined4 *)(param_1 + 0x474));
      sVar2 = BIO_ctrl(*(BIO **)(*(int *)(param_1 + 0x7c) + 0xd4),3,0,local_e8);
      if ((int)sVar2 < 1) {
        ossl_statem_fatal(param_1,0x50,0x1b8,0x14c,"ssl/tls13_enc.c",0x20d);
      }
      else if (((*(int *)(param_1 + 0x68) == 2) && (*(int *)(param_1 + 0xf50) != 0)) &&
              (*(int *)(*(int *)(param_1 + 0x474) + 0x1e0) == 0)) {
        if ((*(int *)(param_1 + 0x478) != 0) &&
           (*(int *)(param_1 + 0xf50) == *(int *)(*(int *)(param_1 + 0x478) + 0x1e0))) {
          iVar5 = SSL_SESSION_get0_cipher();
          goto LAB_0010760e;
        }
        uVar4 = 0x21e;
LAB_00107844:
        ossl_statem_fatal(param_1,0x50,0x1b8,0x44,"ssl/tls13_enc.c",uVar4);
      }
      else {
LAB_0010760e:
        if (iVar5 == 0) {
          ossl_statem_fatal(param_1,0x50,0x1b8,0xdb,"ssl/tls13_enc.c",0x225);
        }
        else {
          ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
          if (ctx == (EVP_MD_CTX *)0x0) {
            ossl_statem_fatal(param_1,0x50,0x1b8,0x41,"ssl/tls13_enc.c",0x231);
          }
          else {
            iVar1 = SSL_CIPHER_get_cipher_nid(iVar5);
            pcVar8 = OBJ_nid2sn(iVar1);
            pEVar9 = (EVP_MD *)EVP_get_cipherbyname(pcVar8);
            type = (EVP_MD *)ssl_md(*(undefined4 *)(iVar5 + 0x34));
            if (((type != (EVP_MD *)0x0) &&
                (iVar5 = EVP_DigestInit_ex(ctx,type,(ENGINE *)0x0), iVar5 != 0)) &&
               (iVar5 = EVP_DigestUpdate(ctx,local_e8[0],sVar2), iVar5 != 0)) {
              local_114 = auStack_a8;
              iVar5 = EVP_DigestFinal_ex(ctx,local_114,local_68);
              if (iVar5 != 0) {
                local_118 = param_1 + 0xcc;
                local_ec = local_68[0];
                EVP_MD_CTX_free(ctx);
                iVar5 = tls13_hkdf_expand(param_1,type,local_118,"e exp master",0xc,local_114,
                                          local_ec,param_1 + 0x38c,local_ec,1);
                if (iVar5 == 0) {
                  uVar4 = 0x248;
                  goto LAB_00107844;
                }
                iVar5 = ssl_log_secret(param_1,"EARLY_EXPORTER_SECRET",param_1 + 0x38c,local_ec);
                if (iVar5 != 0) {
                  local_108 = 0xb;
                  iVar5 = 0;
                  pcVar7 = "c e traffic";
                  local_110 = 0;
                  local_10c = "CLIENT_EARLY_TRAFFIC_SECRET";
                  goto LAB_00107512;
                }
                goto LAB_0010754c;
              }
            }
            ossl_statem_fatal(param_1,0x50,0x1b8,0x44,"ssl/tls13_enc.c",0x23a);
            EVP_MD_CTX_free(ctx);
          }
        }
      }
    }
    else {
      if ((param_2 & 0x80) == 0) {
        local_118 = param_1 + 0x14c;
        local_114 = (uchar *)(param_1 + 0x24c);
        pcVar7 = "c ap traffic";
        local_10c = "CLIENT_TRAFFIC_SECRET_0";
        iVar5 = 0;
        local_110 = 0;
      }
      else {
        local_118 = param_1 + 0x10c;
        pEVar9 = (EVP_MD *)ssl_handshake_md(param_1);
        iVar5 = EVP_MD_size(pEVar9);
        local_110 = param_1 + 0x1cc;
        local_114 = (uchar *)(param_1 + 0x28c);
        pcVar7 = "c hs traffic";
        local_10c = "CLIENT_HANDSHAKE_TRAFFIC_SECRET";
      }
LAB_0010745c:
      type = (EVP_MD *)ssl_handshake_md(param_1);
      pEVar9 = *(EVP_MD **)(*(int *)(param_1 + 0x7c) + 0x230);
      iVar1 = ssl3_digest_cached_records(param_1,1);
      if ((iVar1 != 0) &&
         (iVar1 = ssl_handshake_hash(param_1,auStack_a8,0x40,&local_ec), iVar1 != 0))
      goto LAB_001074e4;
    }
    goto LAB_0010754c;
  }
  if (*(int *)(param_1 + 0x3cc) == 0) {
    local_100 = EVP_CIPHER_CTX_new();
    *(EVP_CIPHER_CTX **)(param_1 + 0x3cc) = local_100;
    if (local_100 == (EVP_CIPHER_CTX *)0x0) {
      uVar4 = 0x1e1;
LAB_00107a0c:
      pcVar8 = (char *)0x0;
      ossl_statem_fatal(param_1,0x50,0x1b8,0x41,"ssl/tls13_enc.c",uVar4);
      goto LAB_0010754e;
    }
  }
  else {
    EVP_CIPHER_CTX_reset();
    local_100 = *(EVP_CIPHER_CTX **)(param_1 + 0x3cc);
  }
  local_104 = param_1 + 0x3d0;
  RECORD_LAYER_reset_read_sequence(param_1 + 0x650);
  if ((param_2 & 0x12) == 0x12) goto LAB_0010742e;
LAB_001074a6:
  if ((param_2 & 0x21) == 0x21) goto LAB_0010742e;
  if ((param_2 & 0x80) == 0) {
    pcVar7 = "s ap traffic";
    local_10c = "SERVER_TRAFFIC_SECRET_0";
    local_118 = param_1 + 0x14c;
    iVar5 = 0;
    local_110 = 0;
  }
  else {
    local_118 = param_1 + 0x10c;
    pEVar9 = (EVP_MD *)ssl_handshake_md(param_1);
    iVar5 = EVP_MD_size(pEVar9);
    local_110 = param_1 + 0x20c;
    pcVar7 = "s hs traffic";
    local_10c = "SERVER_HANDSHAKE_TRAFFIC_SECRET";
  }
  local_114 = auStack_a8;
  if (-1 < (int)(param_2 << 0x19)) {
    local_114 = auStack_a8;
    goto LAB_0010745c;
  }
  type = (EVP_MD *)0x0;
  pEVar9 = type;
LAB_001074e4:
  if (pcVar7 == "s ap traffic") {
    __dest = (void *)(param_1 + 0x24c);
LAB_0010786c:
    local_108 = 0xc;
    memcpy(__dest,auStack_a8,local_ec);
  }
  else {
    if (pcVar7 == "s hs traffic") {
      __dest = (void *)(param_1 + 0x28c);
      goto LAB_0010786c;
    }
    if (pcVar7 == "c ap traffic") {
      uVar4 = ssl_handshake_md(param_1);
      iVar1 = tls13_hkdf_expand(param_1,uVar4,local_118,"res master",10,auStack_a8,local_ec,
                                param_1 + 0x18c,local_ec,1);
      if (iVar1 == 0) goto LAB_0010754c;
    }
    local_108 = 0xc;
  }
LAB_00107512:
  iVar1 = EVP_MD_size(type);
  if (iVar1 < 0) {
    uVar4 = 0x179;
LAB_001075a4:
    ossl_statem_fatal(param_1,0x50,0x202,6,"ssl/tls13_enc.c",uVar4);
LAB_00107544:
    OPENSSL_cleanse(local_68,0x40);
  }
  else {
    iVar1 = tls13_hkdf_expand(param_1,type,local_118,pcVar7,local_108,local_114,iVar1,local_e8,iVar1
                              ,1);
    if (iVar1 == 0) goto LAB_00107544;
    iVar1 = EVP_CIPHER_key_length((EVP_CIPHER *)pEVar9);
    uVar3 = EVP_CIPHER_flags((EVP_CIPHER *)pEVar9);
    if ((uVar3 & 0xf0007) == 7) {
      iVar6 = *(int *)(*(int *)(param_1 + 0x7c) + 0x210);
      if (((iVar6 == 0) && (iVar6 = *(int *)(*(int *)(param_1 + 0x474) + 0x1b8), iVar6 == 0)) &&
         ((*(int *)(param_1 + 0x478) == 0 ||
          (iVar6 = *(int *)(*(int *)(param_1 + 0x478) + 0x1b8), iVar6 == 0)))) {
        uVar4 = 0x194;
        goto LAB_001075a4;
      }
      if ((*(uint *)(iVar6 + 0x18) & 0x30000) == 0) {
        local_fc = 0x10;
        local_f8 = 0xc;
        local_f4 = 0x10;
      }
      else {
        local_fc = 8;
        local_f8 = 0xc;
        local_f4 = 8;
      }
    }
    else {
      local_fc = 0;
      local_f8 = EVP_CIPHER_iv_length((EVP_CIPHER *)pEVar9);
      local_f4 = 0;
    }
    iVar1 = tls13_derive_key(param_1,type,local_e8,local_68,iVar1);
    if ((iVar1 == 0) ||
       (iVar1 = tls13_derive_iv(param_1,type,local_e8,local_104,local_f8), iVar1 == 0))
    goto LAB_00107544;
    iVar1 = EVP_CipherInit_ex(local_100,(EVP_CIPHER *)pEVar9,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0
                              ,param_2 & 2);
    if (((iVar1 < 1) || (iVar1 = EVP_CIPHER_CTX_ctrl(local_100,9,local_f8,(void *)0x0), iVar1 == 0))
       || (((local_f4 != 0 &&
            (iVar1 = EVP_CIPHER_CTX_ctrl(local_100,0x11,local_fc,(void *)0x0), iVar1 == 0)) ||
           (iVar1 = EVP_CipherInit_ex(local_100,(EVP_CIPHER *)0x0,(ENGINE *)0x0,(uchar *)local_68,
                                      (uchar *)0x0,-1), sVar2 = local_ec, iVar1 < 1)))) {
      uVar4 = 0x1ac;
      goto LAB_001075a4;
    }
    pcVar8 = "tls13 ";
    if (pcVar7 == "s ap traffic") {
      memcpy((void *)(param_1 + 0x30c),local_e8,local_ec);
      uVar4 = ssl_handshake_md(param_1);
      iVar1 = tls13_hkdf_expand(param_1,uVar4,local_118,"exp master",10,local_114,local_ec,
                                param_1 + 0x34c,local_ec,1);
      if ((iVar1 == 0) ||
         (iVar1 = ssl_log_secret(param_1,"EXPORTER_SECRET",param_1 + 0x34c,local_ec),
         sVar2 = local_ec, iVar1 == 0)) goto LAB_0010754c;
    }
    else {
      pcVar8 = "c ap traffic";
      if (pcVar7 == "c ap traffic") {
        memcpy((void *)(param_1 + 0x2cc),local_e8,local_ec);
      }
    }
    iVar1 = ssl_log_secret(param_1,local_10c,local_e8,sVar2);
    if (iVar1 != 0) {
      if (local_110 != 0) {
        uVar4 = ssl_handshake_md(param_1);
        iVar5 = tls13_derive_finishedkey(param_1,uVar4,local_e8,local_110,iVar5);
        if (iVar5 == 0) goto LAB_0010754c;
      }
      bVar10 = *(int *)(param_1 + 0x1c) != 0;
      bVar11 = pcVar7 != "c e traffic";
      if (bVar10 || bVar11) {
        pcVar8 = (char *)0x1;
      }
      if (bVar10 || bVar11) {
        *(uint *)(param_1 + 0x60) = (uint)(!bVar10 && !bVar11);
      }
      else {
        pcVar8 = (char *)0x1;
        *(undefined4 *)(param_1 + 0x60) = 2;
      }
      goto LAB_0010754e;
    }
  }
LAB_0010754c:
  pcVar8 = (char *)0x0;
LAB_0010754e:
  OPENSSL_cleanse(local_e8,0x40);
  return pcVar8;
}

