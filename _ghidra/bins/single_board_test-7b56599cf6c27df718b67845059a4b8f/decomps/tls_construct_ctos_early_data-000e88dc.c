
undefined4 tls_construct_ctos_early_data(int param_1,undefined4 param_2)

{
  int iVar1;
  uint len;
  byte *a;
  int iVar2;
  undefined4 uVar3;
  ssl_session_st *__s2;
  uchar *puVar4;
  size_t sVar5;
  uchar *puVar6;
  byte *pbVar7;
  SSL_SESSION *pSVar8;
  code *pcVar9;
  undefined4 uVar10;
  undefined2 local_1bc [2];
  char *local_1b8;
  size_t local_1b4;
  SSL_SESSION *local_1b0;
  char acStack_1ac [132];
  undefined1 auStack_128 [260];
  
  local_1b8 = (char *)0x0;
  local_1b4 = 0;
  local_1b0 = (SSL_SESSION *)0x0;
  if (*(int *)(param_1 + 0x44c) == 1) {
    uVar3 = ssl_handshake_md();
    pcVar9 = *(code **)(param_1 + 0x4cc);
    if (pcVar9 != (code *)0x0) goto LAB_000e8908;
    if (local_1b0 == (SSL_SESSION *)0x0) goto LAB_000e895c;
    goto LAB_000e899a;
  }
  pcVar9 = *(code **)(param_1 + 0x4cc);
  uVar3 = 0;
  if (pcVar9 != (code *)0x0) {
LAB_000e8908:
    iVar1 = (*pcVar9)(param_1,uVar3,&local_1b8,&local_1b4,&local_1b0);
    if (iVar1 != 0) {
      if (local_1b0 == (SSL_SESSION *)0x0) goto LAB_000e895c;
      if (local_1b0->ssl_version == 0x304) goto LAB_000e899a;
    }
    SSL_SESSION_free(local_1b0);
    uVar10 = 0x301;
    uVar3 = 0xdb;
    goto LAB_000e8934;
  }
LAB_000e895c:
  pcVar9 = *(code **)(param_1 + 0x4c0);
  if (pcVar9 == (code *)0x0) {
LAB_000e899a:
    SSL_SESSION_free(*(SSL_SESSION **)(param_1 + 0x478));
    *(SSL_SESSION **)(param_1 + 0x478) = local_1b0;
    if (local_1b0 != (SSL_SESSION *)0x0) {
      CRYPTO_free(*(void **)(param_1 + 0x47c));
      iVar1 = CRYPTO_memdup(local_1b8,local_1b4,"ssl/statem/extensions_clnt.c",0x33f);
      *(int *)(param_1 + 0x47c) = iVar1;
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0x480) = 0;
        ossl_statem_fatal(param_1,0x50,0x212,0x44,"ssl/statem/extensions_clnt.c",0x343);
        return 0;
      }
      *(size_t *)(param_1 + 0x480) = local_1b4;
    }
    if (*(int *)(param_1 + 0x68) != 2) {
LAB_000e89e4:
      *(undefined4 *)(param_1 + 0xf50) = 0;
      return 2;
    }
    sVar5 = (*(SSL_SESSION **)(param_1 + 0x474))->tlsext_ellipticcurvelist_length;
    pSVar8 = *(SSL_SESSION **)(param_1 + 0x474);
    if ((sVar5 == 0) &&
       ((local_1b0 == (SSL_SESSION *)0x0 ||
        (sVar5 = local_1b0->tlsext_ellipticcurvelist_length, pSVar8 = local_1b0, sVar5 == 0))))
    goto LAB_000e89e4;
    __s2 = pSVar8->prev;
    *(size_t *)(param_1 + 0xf50) = sVar5;
    if ((__s2 != (ssl_session_st *)0x0) &&
       ((*(char **)(param_1 + 0x538) == (char *)0x0 ||
        (iVar1 = strcmp(*(char **)(param_1 + 0x538),(char *)__s2), iVar1 != 0)))) {
      uVar10 = 0x358;
      uVar3 = 0xe7;
      goto LAB_000e8934;
    }
    pbVar7 = *(byte **)(param_1 + 0x594);
    if (pbVar7 == (byte *)0x0) {
      if (pSVar8->tlsext_ellipticcurvelist != (uchar *)0x0) {
        ossl_statem_fatal(param_1,0x50,0x212,0xde,"ssl/statem/extensions_clnt.c",0x35f);
        return 0;
      }
    }
    else if (pSVar8->tlsext_ellipticcurvelist != (uchar *)0x0) {
      iVar1 = *(int *)(param_1 + 0x598);
      if (iVar1 < 0) {
        uVar10 = 0x36d;
        goto LAB_000e8a92;
      }
      do {
        puVar4 = (uchar *)(iVar1 + -1);
        if (iVar1 == 0) {
LAB_000e8a52:
          ossl_statem_fatal(param_1,0x50,0x212,0xde,"ssl/statem/extensions_clnt.c",0x37a);
          return 0;
        }
        a = pbVar7 + 1;
        puVar6 = (uchar *)(uint)*pbVar7;
        pbVar7 = a + (int)puVar6;
        iVar1 = (int)puVar4 - (int)puVar6;
        if (puVar4 < puVar6) goto LAB_000e8a52;
      } while ((pSVar8->tlsext_tick != puVar6) ||
              (iVar2 = CRYPTO_memcmp(a,pSVar8->tlsext_ellipticcurvelist,(size_t)pSVar8->tlsext_tick)
              , iVar2 != 0));
    }
    iVar1 = WPACKET_put_bytes__(param_2);
    if ((iVar1 != 0) &&
       ((iVar1 = WPACKET_start_sub_packet_len__(param_2,2), iVar1 != 0 &&
        (iVar1 = WPACKET_close(param_2), iVar1 != 0)))) {
      *(undefined4 *)(param_1 + 0x5ac) = 1;
      *(undefined4 *)(param_1 + 0x5b0) = 1;
      return 1;
    }
    uVar10 = 899;
  }
  else {
    memset(acStack_1ac,0,0x81);
    len = (*pcVar9)(param_1,0,acStack_1ac,0x80,auStack_128,0x100);
    if (0x100 < len) {
      ossl_statem_fatal(param_1,0x28,0x212,0x44,"ssl/statem/extensions_clnt.c",0x310);
      return 0;
    }
    if (len == 0) goto LAB_000e899a;
    local_1bc[0] = 0x113;
    local_1b4 = strlen(acStack_1ac);
    if (local_1b4 < 0x81) {
      local_1b8 = acStack_1ac;
      iVar1 = SSL_CIPHER_find(param_1,local_1bc);
      if (iVar1 != 0) {
        local_1b0 = SSL_SESSION_new();
        if ((((local_1b0 == (SSL_SESSION *)0x0) ||
             (iVar2 = SSL_SESSION_set1_master_key(local_1b0,auStack_128,len), iVar2 == 0)) ||
            (iVar1 = SSL_SESSION_set_cipher(local_1b0,iVar1), iVar1 == 0)) ||
           (iVar1 = SSL_SESSION_set_protocol_version(local_1b0,0x304), iVar1 == 0)) {
          ossl_statem_fatal(param_1,0x50,0x212,0x44,"ssl/statem/extensions_clnt.c",0x332);
          OPENSSL_cleanse(auStack_128,len);
          return 0;
        }
        OPENSSL_cleanse(auStack_128,len);
        goto LAB_000e899a;
      }
      uVar10 = 0x327;
    }
    else {
      uVar10 = 0x31a;
    }
  }
LAB_000e8a92:
  uVar3 = 0x44;
LAB_000e8934:
  ossl_statem_fatal(param_1,0x50,0x212,uVar3,"ssl/statem/extensions_clnt.c",uVar10);
  return 0;
}

