
undefined4 tls_process_client_key_exchange(uint *param_1,uint *param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  EVP_PKEY *pEVar3;
  EVP_PKEY_CTX *ctx;
  int *piVar4;
  int iVar5;
  RSA *rsa;
  byte *pbVar6;
  uchar *puVar7;
  BIGNUM *pBVar8;
  char *pcVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  undefined1 *puVar13;
  uint uVar14;
  byte *pbVar15;
  byte *pbVar16;
  byte *pbVar17;
  EVP_PKEY *pEVar18;
  undefined4 uVar19;
  size_t local_58;
  undefined4 local_54;
  byte local_50 [48];
  
  uVar12 = *(uint *)(*(int *)(param_1[0x1f] + 0x210) + 0x10);
  if (((uVar12 & 0x1c8) != 0) && (iVar5 = tls_process_cke_psk_preamble(), iVar5 == 0))
  goto LAB_000f4ed6;
  if ((int)(uVar12 << 0x1c) < 0) {
    if (param_2[1] != 0) {
      ossl_statem_fatal(param_1,0x32,0x17e,0x9f,"ssl/statem/statem_srvr.c",0xd93);
      goto LAB_000f4ed6;
    }
    iVar5 = ssl_generate_master_secret(param_1,0,0);
joined_r0x000f5546:
    if (iVar5 != 0) {
      return 2;
    }
    goto LAB_000f4ed6;
  }
  if ((uVar12 & 0x41) != 0) {
    rsa = (RSA *)EVP_PKEY_get0_RSA(*(undefined4 *)(param_1[0x101] + 0x18));
    if (rsa == (RSA *)0x0) {
      uVar19 = 0xbc4;
      uVar10 = 0xa8;
    }
    else {
      if ((*param_1 & 0xfffffdff) != 0x100) {
        if (1 < param_2[1]) {
          puVar13 = (undefined1 *)*param_2;
          uVar12 = param_2[1] - 2;
          puVar7 = puVar13 + 2;
          uVar11 = (uint)CONCAT11(*puVar13,puVar13[1]);
          if (uVar11 <= uVar12) {
            uVar12 = uVar12 - uVar11;
            *param_2 = (uint)(puVar7 + uVar11);
            param_2[1] = uVar12;
            if (uVar12 == 0) goto LAB_000f5088;
          }
        }
        ossl_statem_fatal(param_1,0x32,0x19f,0x9f,"ssl/statem/statem_srvr.c",0xbcf);
        goto LAB_000f4ed6;
      }
      puVar7 = (uchar *)*param_2;
      uVar11 = param_2[1];
LAB_000f5088:
      iVar5 = RSA_size(rsa);
      if (0x2f < iVar5) {
        iVar5 = RSA_size(rsa);
        pbVar16 = (byte *)CRYPTO_malloc(iVar5,"ssl/statem/statem_srvr.c",0xbe0);
        if (pbVar16 == (byte *)0x0) {
          ossl_statem_fatal(param_1,0x50,0x19f,0x41,"ssl/statem/statem_srvr.c",0xbe3);
          goto LAB_000f4ed6;
        }
        iVar5 = RAND_priv_bytes(local_50,0x30);
        if (iVar5 < 1) {
          ossl_statem_fatal(param_1,0x50,0x19f,0x44,"ssl/statem/statem_srvr.c",0xbf2);
        }
        else {
          iVar5 = RSA_private_decrypt(uVar11,puVar7,pbVar16,rsa,3);
          if (iVar5 < 0) {
            ossl_statem_fatal(param_1,0x33,0x19f,0x44,"ssl/statem/statem_srvr.c",0xc00);
          }
          else {
            if (0x3a < iVar5) {
              pbVar17 = pbVar16 + 1;
              uVar12 = (uint)(byte)((char)((byte)((*pbVar17 ^ 2) - 1 >> 0x18) &
                                          (byte)(*pbVar16 - 1 >> 0x18)) >> 7);
              do {
                pbVar17 = pbVar17 + 1;
                uVar12 = uVar12 & ~((int)(*pbVar17 - 1 & ~(uint)*pbVar17) >> 0x1f);
              } while (pbVar17 != pbVar16 + iVar5 + -0x32);
              uVar11 = param_1[0x141];
              pbVar17 = pbVar16 + iVar5 + -0x30;
              local_58 = (size_t)(byte)((char)((byte)((uVar11 & 0xff ^ (uint)pbVar17[1]) - 1 >> 0x18
                                                     ) &
                                              (byte)(((uint)pbVar16[iVar5 + -0x30] ^
                                                     (int)uVar11 >> 8) - 1 >> 0x18) &
                                              ~(byte)((int)uVar11 >> 0x1f)) >> 7);
              if ((int)(param_1[0x13b] << 8) < 0) {
                uVar14 = (uint)pbVar16[iVar5 + -0x30] ^ (int)*param_1 >> 8;
                uVar11 = (uint)pbVar17[1] ^ *param_1 & 0xff;
                local_58 = local_58 |
                           (int)(uVar11 - 1 & ~uVar11 & uVar14 - 1 & ~uVar14) >> 0x1f & 0xffU;
              }
              local_58 = local_58 &
                         uVar12 & (int)(pbVar16[iVar5 + -0x31] - 1 & ~(uint)pbVar16[iVar5 + -0x31])
                                  >> 0x1f;
              local_54 = ~local_58;
              pbVar6 = (byte *)((int)&local_54 + 3);
              pbVar15 = pbVar17;
              do {
                pbVar6 = pbVar6 + 1;
                *pbVar15 = (byte)local_54 & *pbVar6 | *pbVar15 & (byte)local_58;
                pbVar15 = pbVar15 + 1;
              } while (local_50 + 0x2f != pbVar6);
              iVar5 = ssl_generate_master_secret(param_1,pbVar17,0x30,0);
              CRYPTO_free(pbVar16);
              goto joined_r0x000f5546;
            }
            ossl_statem_fatal(param_1,0x33,0x19f,0x93,"ssl/statem/statem_srvr.c",0xc0d);
          }
        }
        CRYPTO_free(pbVar16);
        goto LAB_000f4ed6;
      }
      uVar19 = 0xbdc;
      uVar10 = 0x78;
    }
    ossl_statem_fatal(param_1,0x50,0x19f,uVar10,"ssl/statem/statem_srvr.c",uVar19);
    goto LAB_000f4ed6;
  }
  if ((uVar12 & 0x102) == 0) {
    if ((uVar12 & 0x84) == 0) {
      if ((int)(uVar12 << 0x1a) < 0) {
        if (1 < param_2[1]) {
          puVar13 = (undefined1 *)*param_2;
          uVar11 = param_2[1] - 2;
          uVar1 = *puVar13;
          puVar7 = puVar13 + 2;
          uVar2 = puVar13[1];
          *param_2 = (uint)puVar7;
          param_2[1] = uVar11;
          uVar12 = (uint)CONCAT11(uVar1,uVar2);
          if (uVar12 <= uVar11) {
            param_2[1] = uVar11 - uVar12;
            *param_2 = (uint)(puVar7 + uVar12);
            pBVar8 = BN_bin2bn(puVar7,uVar12,(BIGNUM *)0x0);
            param_1[0x18c] = (uint)pBVar8;
            if (pBVar8 == (BIGNUM *)0x0) {
              ossl_statem_fatal(param_1,0x50,0x1a0,3,"ssl/statem/statem_srvr.c",0xcf6);
              goto LAB_000f4ed6;
            }
            iVar5 = BN_ucmp(pBVar8,(BIGNUM *)param_1[0x188]);
            if ((-1 < iVar5) || (iVar5 = BN_is_zero(param_1[0x18c]), iVar5 != 0)) {
              ossl_statem_fatal(param_1,0x2f,0x1a0,0x173,"ssl/statem/statem_srvr.c",0xcfb);
              goto LAB_000f4ed6;
            }
            CRYPTO_free(*(void **)(param_1[0x11d] + 0x1f0));
            uVar11 = param_1[0x11d];
            pcVar9 = CRYPTO_strdup((char *)param_1[0x187],"ssl/statem/statem_srvr.c",0xcff);
            uVar12 = param_1[0x11d];
            *(char **)(uVar11 + 0x1f0) = pcVar9;
            if (*(int *)(uVar12 + 0x1f0) == 0) {
              ossl_statem_fatal(param_1,0x50,0x1a0,0x41,"ssl/statem/statem_srvr.c",0xd02);
              goto LAB_000f4ed6;
            }
            iVar5 = srp_generate_server_master_secret(param_1);
            goto joined_r0x000f5546;
          }
        }
        ossl_statem_fatal(param_1,0x32,0x1a0,0x15b,"ssl/statem/statem_srvr.c",0xcf1);
        goto LAB_000f4ed6;
      }
      if (-1 < (int)(uVar12 << 0x1b)) {
        ossl_statem_fatal(param_1,0x50,0x17e,0xf9,"ssl/statem/statem_srvr.c",0xdb7);
        goto LAB_000f4ed6;
      }
      local_58 = 0x20;
      uVar12 = *(uint *)(*(int *)(param_1[0x1f] + 0x210) + 0x14);
      if ((int)(uVar12 << 0x18) < 0) {
        uVar12 = param_1[0x101];
        pEVar3 = *(EVP_PKEY **)(uVar12 + 0x90);
        if ((pEVar3 == (EVP_PKEY *)0x0) &&
           (pEVar3 = *(EVP_PKEY **)(uVar12 + 0x7c), pEVar3 == (EVP_PKEY *)0x0)) goto LAB_000f4f40;
      }
      else {
        pEVar3 = (EVP_PKEY *)(uVar12 & 0x20);
        if (pEVar3 != (EVP_PKEY *)0x0) {
          uVar12 = param_1[0x101];
LAB_000f4f40:
          pEVar3 = *(EVP_PKEY **)(uVar12 + 0x68);
        }
      }
      ctx = EVP_PKEY_CTX_new(pEVar3,(ENGINE *)0x0);
      if (ctx == (EVP_PKEY_CTX *)0x0) {
        uVar19 = 0xd35;
        uVar10 = 0x41;
      }
      else {
        iVar5 = EVP_PKEY_decrypt_init(ctx);
        if (0 < iVar5) {
          pEVar3 = (EVP_PKEY *)X509_get0_pubkey(*(undefined4 *)(param_1[0x11d] + 0x19c));
          if ((pEVar3 != (EVP_PKEY *)0x0) &&
             (iVar5 = EVP_PKEY_derive_set_peer(ctx,pEVar3), iVar5 < 1)) {
            ERR_clear_error();
          }
          local_54 = *param_2;
          piVar4 = (int *)d2i_GOST_KX_MESSAGE(0,&local_54,param_2[1]);
          if (((piVar4 == (int *)0x0) || ((ASN1_TYPE *)*piVar4 == (ASN1_TYPE *)0x0)) ||
             (iVar5 = ASN1_TYPE_get((ASN1_TYPE *)*piVar4), iVar5 != 0x10)) {
            uVar10 = 0xd51;
LAB_000f4fa2:
            ossl_statem_fatal(param_1,0x32,0x19d,0x93,"ssl/statem/statem_srvr.c",uVar10);
          }
          else {
            if (param_2[1] < local_54 - *param_2) {
              uVar10 = 0xd57;
            }
            else {
              uVar12 = param_2[1] - (local_54 - *param_2);
              *param_2 = local_54;
              param_2[1] = uVar12;
              if (uVar12 == 0) {
                iVar5 = EVP_PKEY_decrypt(ctx,local_50,&local_58,
                                         (uchar *)(*(size_t **)(*piVar4 + 4))[2],
                                         **(size_t **)(*piVar4 + 4));
                if (iVar5 < 1) {
                  uVar10 = 0xd67;
                  goto LAB_000f4fa2;
                }
                iVar5 = ssl_generate_master_secret(param_1,local_50,0x20,0);
                if (iVar5 != 0) {
                  iVar5 = EVP_PKEY_CTX_ctrl(ctx,-1,-1,2,2,(void *)0x0);
                  if (0 < iVar5) {
                    param_1[0x16] = 1;
                  }
                  EVP_PKEY_CTX_free(ctx);
                  GOST_KX_MESSAGE_free(piVar4);
                  return 2;
                }
                goto LAB_000f4fb4;
              }
              uVar10 = 0xd5d;
            }
            ossl_statem_fatal(param_1,0x50,0x19d,0x93,"ssl/statem/statem_srvr.c",uVar10);
          }
LAB_000f4fb4:
          EVP_PKEY_CTX_free(ctx);
          GOST_KX_MESSAGE_free(piVar4);
          goto LAB_000f4ed6;
        }
        uVar19 = 0xd3a;
        uVar10 = 0x44;
      }
      ossl_statem_fatal(param_1,0x50,0x19d,uVar10,"ssl/statem/statem_srvr.c",uVar19);
      goto LAB_000f4ed6;
    }
    if (param_2[1] == 0) {
      ossl_statem_fatal(param_1,0x28,0x19c,0x137,"ssl/statem/statem_srvr.c",0xcaf);
      pEVar3 = (EVP_PKEY *)0x0;
      goto LAB_000f505a;
    }
    uVar12 = param_2[1] - 1;
    pbVar16 = (byte *)*param_2 + 1;
    uVar11 = (uint)*(byte *)*param_2;
    pEVar18 = *(EVP_PKEY **)(param_1[0x1f] + 0x214);
    param_2[1] = uVar12;
    *param_2 = (uint)pbVar16;
    if (uVar12 < uVar11) {
LAB_000f5374:
      pEVar3 = (EVP_PKEY *)0x0;
      ossl_statem_fatal(param_1,0x32,0x19c,0x9f,"ssl/statem/statem_srvr.c",0xcbe);
    }
    else {
      *param_2 = (uint)(pbVar16 + uVar11);
      param_2[1] = uVar12 - uVar11;
      if (uVar12 - uVar11 != 0) goto LAB_000f5374;
      if (pEVar18 == (EVP_PKEY *)0x0) {
        ossl_statem_fatal(param_1,0x50,0x19c,0x137,"ssl/statem/statem_srvr.c",0xcc3);
        pEVar3 = (EVP_PKEY *)0x0;
      }
      else {
        pEVar3 = EVP_PKEY_new();
        if ((pEVar3 == (EVP_PKEY *)0x0) ||
           (iVar5 = EVP_PKEY_copy_parameters(pEVar3,pEVar18), iVar5 < 1)) {
          uVar19 = 0xcca;
          uVar10 = 6;
        }
        else {
          iVar5 = EVP_PKEY_set1_tls_encodedpoint(pEVar3,pbVar16,uVar11);
          if (iVar5 != 0) {
            iVar5 = ssl_derive(param_1,pEVar18,pEVar3,1);
            if (iVar5 != 0) {
              EVP_PKEY_free(*(EVP_PKEY **)(param_1[0x1f] + 0x214));
              *(undefined4 *)(param_1[0x1f] + 0x214) = 0;
              EVP_PKEY_free(pEVar3);
              return 2;
            }
            goto LAB_000f505a;
          }
          uVar19 = 0xccf;
          uVar10 = 0x10;
        }
        ossl_statem_fatal(param_1,0x50,0x19c,uVar10,"ssl/statem/statem_srvr.c",uVar19);
      }
    }
LAB_000f505a:
    EVP_PKEY_free(pEVar3);
    goto LAB_000f4ed6;
  }
  if (param_2[1] < 2) {
LAB_000f5206:
    pEVar3 = (EVP_PKEY *)0x0;
    ossl_statem_fatal(param_1,0x32,0x19b,0x94,"ssl/statem/statem_srvr.c",0xc6d);
  }
  else {
    puVar13 = (undefined1 *)*param_2;
    uVar12 = param_2[1] - 2;
    uVar1 = *puVar13;
    puVar7 = puVar13 + 2;
    uVar2 = puVar13[1];
    *param_2 = (uint)puVar7;
    param_2[1] = uVar12;
    uVar11 = (uint)CONCAT11(uVar1,uVar2);
    if (uVar11 != uVar12) goto LAB_000f5206;
    pEVar18 = *(EVP_PKEY **)(param_1[0x1f] + 0x214);
    if (pEVar18 == (EVP_PKEY *)0x0) {
      ossl_statem_fatal(param_1,0x50,0x19b,0xab,"ssl/statem/statem_srvr.c",0xc73);
      pEVar3 = (EVP_PKEY *)0x0;
    }
    else if (uVar11 == 0) {
      ossl_statem_fatal(param_1,0x32,0x19b,0xab,"ssl/statem/statem_srvr.c",0xc79);
      pEVar3 = (EVP_PKEY *)0x0;
    }
    else {
      *param_2 = (uint)(puVar7 + uVar11);
      param_2[1] = 0;
      pEVar3 = EVP_PKEY_new();
      if ((pEVar3 == (EVP_PKEY *)0x0) ||
         (iVar5 = EVP_PKEY_copy_parameters(pEVar3,pEVar18), iVar5 == 0)) {
        ossl_statem_fatal(param_1,0x50,0x19b,0x82,"ssl/statem/statem_srvr.c",0xc85);
      }
      else {
        iVar5 = EVP_PKEY_get0_DH(pEVar3);
        pBVar8 = BN_bin2bn(puVar7,uVar11,(BIGNUM *)0x0);
        if ((iVar5 == 0 || pBVar8 == (BIGNUM *)0x0) ||
           (iVar5 = DH_set0_key(iVar5,pBVar8,0), iVar5 == 0)) {
          ossl_statem_fatal(param_1,0x50,0x19b,0x44,"ssl/statem/statem_srvr.c",0xc8d);
          BN_free(pBVar8);
        }
        else {
          iVar5 = ssl_derive(param_1,pEVar18,pEVar3,1);
          if (iVar5 != 0) {
            EVP_PKEY_free(*(EVP_PKEY **)(param_1[0x1f] + 0x214));
            *(undefined4 *)(param_1[0x1f] + 0x214) = 0;
            EVP_PKEY_free(pEVar3);
            return 2;
          }
        }
      }
    }
  }
  EVP_PKEY_free(pEVar3);
LAB_000f4ed6:
  CRYPTO_clear_free(*(undefined4 *)(param_1[0x1f] + 600),*(undefined4 *)(param_1[0x1f] + 0x25c),
                    "ssl/statem/statem_srvr.c",0xdbe);
  uVar12 = param_1[0x1f];
  *(undefined4 *)(uVar12 + 600) = 0;
  *(undefined4 *)(uVar12 + 0x25c) = 0;
  return 0;
}

