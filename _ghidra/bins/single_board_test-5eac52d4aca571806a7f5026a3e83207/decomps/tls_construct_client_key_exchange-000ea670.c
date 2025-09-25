
undefined4 tls_construct_client_key_exchange(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  EVP_PKEY *pEVar3;
  char *pcVar4;
  undefined4 uVar5;
  uint uVar6;
  uchar *puVar7;
  EVP_PKEY_CTX *ctx;
  uchar *puVar8;
  undefined4 uVar9;
  BIGNUM *local_28;
  uchar *local_24 [2];
  
  uVar6 = *(uint *)(*(int *)(param_1[0x1f] + 0x210) + 0x10);
  if (((uVar6 & 0x1c8) != 0) && (iVar1 = tls_construct_cke_psk_preamble(), iVar1 == 0))
  goto LAB_000ea6c2;
  puVar7 = (uchar *)(uVar6 & 0x41);
  if (puVar7 != (uchar *)0x0) {
    ctx = (EVP_PKEY_CTX *)0x0;
    local_28 = (BIGNUM *)0x0;
    if (*(int *)(param_1[0x11d] + 0x19c) == 0) {
      uVar5 = 0xba9;
    }
    else {
      pEVar3 = (EVP_PKEY *)X509_get0_pubkey();
      iVar1 = EVP_PKEY_get0_RSA();
      if (iVar1 != 0) {
        puVar7 = (uchar *)CRYPTO_malloc(0x30,"ssl/statem/statem_clnt.c",0xbb5);
        if (puVar7 == (uchar *)0x0) {
          ossl_statem_fatal(param_1,0x50,0x199,0x41,"ssl/statem/statem_clnt.c",3000);
          goto LAB_000ea6c2;
        }
        *puVar7 = (uchar)((uint)param_1[0x141] >> 8);
        puVar7[1] = (uchar)param_1[0x141];
        iVar1 = RAND_bytes(puVar7 + 2,0x2e);
        if (iVar1 < 1) {
          ossl_statem_fatal(param_1,0x50,0x199,0x41,"ssl/statem/statem_clnt.c",0xbc1);
        }
        else if ((*param_1 < 0x301) ||
                (iVar1 = WPACKET_start_sub_packet_len__(param_2,2), iVar1 != 0)) {
          ctx = EVP_PKEY_CTX_new(pEVar3,(ENGINE *)0x0);
          if ((ctx == (EVP_PKEY_CTX *)0x0) || (iVar1 = EVP_PKEY_encrypt_init(ctx), iVar1 < 1)) {
LAB_000ea89e:
            uVar9 = 0xbcf;
            uVar5 = 6;
          }
          else {
            iVar1 = EVP_PKEY_encrypt(ctx,(uchar *)0x0,(size_t *)local_24,puVar7,0x30);
            if (iVar1 < 1) goto LAB_000ea89e;
            iVar1 = WPACKET_allocate_bytes(param_2,local_24[0],&local_28);
            if ((iVar1 == 0) ||
               (iVar1 = EVP_PKEY_encrypt(ctx,(uchar *)local_28,(size_t *)local_24,puVar7,0x30),
               iVar1 < 1)) {
              uVar9 = 0xbd5;
              uVar5 = 0x77;
            }
            else {
              EVP_PKEY_CTX_free(ctx);
              if ((*param_1 < 0x301) || (iVar1 = WPACKET_close(param_2), iVar1 != 0)) {
                ctx = (EVP_PKEY_CTX *)
                      ssl_log_rsa_client_key_exchange(param_1,local_28,local_24[0],puVar7,0x30);
                if (ctx != (EVP_PKEY_CTX *)0x0) {
                  iVar1 = param_1[0x1f];
                  *(uchar **)(iVar1 + 0x250) = puVar7;
                  *(undefined4 *)(iVar1 + 0x254) = 0x30;
                  return 1;
                }
                goto LAB_000ea8b8;
              }
              uVar9 = 0xbde;
              uVar5 = 0x44;
              ctx = (EVP_PKEY_CTX *)0x0;
            }
          }
          ossl_statem_fatal(param_1,0x50,0x199,uVar5,"ssl/statem/statem_clnt.c",uVar9);
        }
        else {
          ossl_statem_fatal(param_1,0x50,0x199,0x44,"ssl/statem/statem_clnt.c",0xbc8);
          ctx = (EVP_PKEY_CTX *)0x0;
        }
LAB_000ea8b8:
        CRYPTO_clear_free(puVar7,0x30,"ssl/statem/statem_clnt.c",0xbed);
        EVP_PKEY_CTX_free(ctx);
        goto LAB_000ea6c2;
      }
      uVar5 = 0xbb0;
    }
    ossl_statem_fatal(param_1,0x50,0x199,0x44,"ssl/statem/statem_clnt.c",uVar5);
    goto LAB_000ea6c2;
  }
  puVar8 = (uchar *)(uVar6 & 0x102);
  if (puVar8 != (uchar *)0x0) {
    iVar1 = *(int *)(param_1[0x1f] + 0x358);
    local_24[0] = puVar7;
    if (iVar1 == 0) {
      ossl_statem_fatal(param_1,0x50,0x194,0x44,"ssl/statem/statem_clnt.c",0xc03);
      pEVar3 = (EVP_PKEY *)0x0;
    }
    else {
      pEVar3 = (EVP_PKEY *)ssl_generate_pkey(iVar1);
      if (pEVar3 == (EVP_PKEY *)0x0) {
        uVar5 = 0xc0a;
      }
      else {
        iVar2 = EVP_PKEY_get0_DH();
        if (iVar2 == 0) {
          uVar5 = 0xc12;
        }
        else {
          iVar1 = ssl_derive(param_1,pEVar3,iVar1,0);
          if (iVar1 == 0) goto LAB_000ea852;
          DH_get0_key(iVar2,&local_28,0);
          iVar2 = BN_num_bits(local_28);
          iVar1 = iVar2 + 0xe;
          if (-1 < iVar2 + 7) {
            iVar1 = iVar2 + 7;
          }
          iVar1 = WPACKET_sub_allocate_bytes__(param_2,iVar1 >> 3,local_24,2);
          if (iVar1 != 0) {
            BN_bn2bin(local_28,local_24[0]);
            EVP_PKEY_free(pEVar3);
            return 1;
          }
          uVar5 = 0xc20;
        }
      }
      ossl_statem_fatal(param_1,0x50,0x194,0x44,"ssl/statem/statem_clnt.c",uVar5);
    }
LAB_000ea852:
    EVP_PKEY_free(pEVar3);
    goto LAB_000ea6c2;
  }
  if ((uVar6 & 0x84) == 0) {
    puVar7 = (uchar *)(uVar6 & 0x10);
    if (puVar7 == (uchar *)0x0) {
      if ((int)(uVar6 << 0x1a) < 0) {
        local_24[0] = puVar7;
        if ((BIGNUM *)param_1[0x18c] != (BIGNUM *)0x0) {
          iVar2 = BN_num_bits((BIGNUM *)param_1[0x18c]);
          iVar1 = iVar2 + 0xe;
          if (-1 < iVar2 + 7) {
            iVar1 = iVar2 + 7;
          }
          iVar1 = WPACKET_sub_allocate_bytes__(param_2,iVar1 >> 3,local_24,2);
          if (iVar1 != 0) {
            BN_bn2bin((BIGNUM *)param_1[0x18c],local_24[0]);
            CRYPTO_free(*(void **)(param_1[0x11d] + 0x1f0));
            iVar2 = param_1[0x11d];
            pcVar4 = CRYPTO_strdup((char *)param_1[0x187],"ssl/statem/statem_clnt.c",0xcec);
            iVar1 = param_1[0x11d];
            *(char **)(iVar2 + 0x1f0) = pcVar4;
            if (*(int *)(iVar1 + 0x1f0) != 0) {
              return 1;
            }
            ossl_statem_fatal(param_1,0x50,0x19a,0x41,"ssl/statem/statem_clnt.c",0xcef);
            goto LAB_000ea6c2;
          }
        }
        ossl_statem_fatal(param_1,0x50,0x19a,0x44,"ssl/statem/statem_clnt.c",0xce6);
      }
      else {
        if ((int)(uVar6 << 0x1c) < 0) {
          return 1;
        }
        ossl_statem_fatal(param_1,0x50,0x1e8,0x44,"ssl/statem/statem_clnt.c",0xd1a);
      }
    }
    else {
      iVar1 = tls_construct_cke_gost(param_1,param_2);
      if (iVar1 != 0) {
        return 1;
      }
    }
    goto LAB_000ea6c2;
  }
  iVar1 = *(int *)(param_1[0x1f] + 0x358);
  local_24[0] = puVar8;
  if (iVar1 == 0) {
    ossl_statem_fatal(param_1,0x50,0x195,0x44,"ssl/statem/statem_clnt.c",0xc3d);
    goto LAB_000ea6c2;
  }
  pEVar3 = (EVP_PKEY *)ssl_generate_pkey(iVar1);
  if (pEVar3 == (EVP_PKEY *)0x0) {
    uVar9 = 0xc44;
    uVar5 = 0x41;
LAB_000eaa1a:
    ossl_statem_fatal(param_1,0x50,0x195,uVar5,"ssl/statem/statem_clnt.c",uVar9);
  }
  else {
    iVar1 = ssl_derive(param_1,pEVar3,iVar1,0);
    if (iVar1 != 0) {
      iVar1 = EVP_PKEY_get1_tls_encodedpoint(pEVar3,local_24);
      if (iVar1 == 0) {
        uVar9 = 0xc52;
        uVar5 = 0x10;
      }
      else {
        iVar1 = WPACKET_sub_memcpy__(param_2,local_24[0],iVar1,1);
        if (iVar1 != 0) {
          CRYPTO_free(local_24[0]);
          EVP_PKEY_free(pEVar3);
          return 1;
        }
        uVar9 = 0xc58;
        uVar5 = 0x44;
      }
      goto LAB_000eaa1a;
    }
  }
  CRYPTO_free(local_24[0]);
  EVP_PKEY_free(pEVar3);
LAB_000ea6c2:
  CRYPTO_clear_free(*(undefined4 *)(param_1[0x1f] + 0x250),*(undefined4 *)(param_1[0x1f] + 0x254),
                    "ssl/statem/statem_clnt.c",0xd20);
  iVar1 = param_1[0x1f];
  *(undefined4 *)(iVar1 + 0x250) = 0;
  *(undefined4 *)(iVar1 + 0x254) = 0;
  CRYPTO_clear_free(*(undefined4 *)(iVar1 + 600),*(undefined4 *)(iVar1 + 0x25c),
                    "ssl/statem/statem_clnt.c",0xd24);
  iVar1 = param_1[0x1f];
  *(undefined4 *)(iVar1 + 600) = 0;
  *(undefined4 *)(iVar1 + 0x25c) = 0;
  return 0;
}

