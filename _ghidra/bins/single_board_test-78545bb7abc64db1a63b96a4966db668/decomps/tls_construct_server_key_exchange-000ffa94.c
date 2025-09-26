
/* WARNING: Type propagation algorithm not settling */

undefined4 tls_construct_server_key_exchange(int param_1,undefined4 param_2)

{
  EVP_MD_CTX *ctx;
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  DH *dh;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  size_t __n;
  char *__s;
  BIGNUM *pBVar8;
  BIGNUM **ppBVar9;
  uint uVar10;
  EVP_PKEY *pkey;
  int iVar11;
  EVP_PKEY *pEVar12;
  undefined8 uVar13;
  int local_74;
  int local_70;
  void *local_5c;
  EVP_PKEY_CTX *local_58;
  undefined4 local_54;
  int local_50;
  EVP_MD *local_4c;
  int local_48;
  int local_44;
  void *local_40;
  uchar *local_3c;
  BIGNUM *local_38 [5];
  
  local_5c = (void *)0x0;
  iVar11 = *(int *)(*(int *)(param_1 + 0x7c) + 0x260);
  ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
  local_58 = (EVP_PKEY_CTX *)0x0;
  iVar1 = WPACKET_get_total_written(param_2,&local_50);
  if (iVar1 == 0) {
    ossl_statem_fatal(param_1,0x50,0x1ec,0x44,"ssl/statem/statem_srvr.c",0x9cc);
    pEVar12 = (EVP_PKEY *)0x0;
    goto LAB_000ffbb8;
  }
  if (ctx == (EVP_MD_CTX *)0x0) {
    ossl_statem_fatal(param_1,0x50,0x1ec,0x41,"ssl/statem/statem_srvr.c",0x9d2);
    pEVar12 = (EVP_PKEY *)0x0;
    goto LAB_000ffbb8;
  }
  local_38[0] = (BIGNUM *)0x0;
  iVar1 = *(int *)(*(int *)(param_1 + 0x7c) + 0x210);
  uVar10 = *(uint *)(iVar1 + 0x10);
  local_38[3] = (BIGNUM *)0x0;
  local_38[2] = (BIGNUM *)0x0;
  local_38[1] = (BIGNUM *)0x0;
  if ((uVar10 & 0x48) == 0) {
    if ((uVar10 & 0x102) == 0) {
      if ((uVar10 & 0x84) == 0) {
        if ((uVar10 & 0x20) == 0) {
          ossl_statem_fatal(param_1,0x50,0x1ec,0xfa,"ssl/statem/statem_srvr.c",0xa67);
          pEVar12 = (EVP_PKEY *)0x0;
          goto LAB_000ffbb8;
        }
        if ((((*(BIGNUM **)(param_1 + 0x620) != (BIGNUM *)0x0) &&
             (*(BIGNUM **)(param_1 + 0x624) != (BIGNUM *)0x0)) &&
            (*(BIGNUM **)(param_1 + 0x628) != (BIGNUM *)0x0)) &&
           (*(BIGNUM **)(param_1 + 0x62c) != (BIGNUM *)0x0)) {
          local_38[0] = *(BIGNUM **)(param_1 + 0x620);
          local_74 = 0;
          local_38[1] = *(BIGNUM **)(param_1 + 0x624);
          local_70 = 0;
          local_38[2] = *(BIGNUM **)(param_1 + 0x628);
          local_38[3] = *(BIGNUM **)(param_1 + 0x62c);
          goto LAB_000ffade;
        }
        uVar5 = 0xa5b;
        uVar6 = 0x166;
LAB_000ffb1c:
        ossl_statem_fatal(param_1,0x50,0x1ec,uVar6,"ssl/statem/statem_srvr.c",uVar5);
        goto LAB_000ffb28;
      }
      pBVar8 = *(BIGNUM **)(*(int *)(param_1 + 0x7c) + 0x214);
      if (pBVar8 == (BIGNUM *)0x0) {
        local_74 = tls1_shared_group(param_1,0xfffffffe);
        if (local_74 == 0) {
          ossl_statem_fatal(param_1,0x28,0x1ec,0x13b,"ssl/statem/statem_srvr.c",0xa37);
          pEVar12 = (EVP_PKEY *)0x0;
          goto LAB_000ffbb8;
        }
        iVar3 = *(int *)(param_1 + 0x7c);
        uVar5 = ssl_generate_pkey_group(param_1,local_74);
        iVar1 = *(int *)(param_1 + 0x7c);
        *(undefined4 *)(iVar3 + 0x214) = uVar5;
        iVar1 = *(int *)(iVar1 + 0x214);
        if (iVar1 == 0) {
          pEVar12 = (EVP_PKEY *)0x0;
          goto LAB_000ffbb8;
        }
        local_70 = EVP_PKEY_get1_tls_encodedpoint(iVar1,&local_5c);
        if (local_70 == 0) {
          ossl_statem_fatal(param_1,0x50,0x1ec,0x10,"ssl/statem/statem_srvr.c",0xa46);
          pEVar12 = (EVP_PKEY *)0x0;
          goto LAB_000ffbb8;
        }
        local_38[0] = pBVar8;
        local_38[1] = pBVar8;
        local_38[2] = pBVar8;
        local_38[3] = pBVar8;
        iVar1 = *(int *)(*(int *)(param_1 + 0x7c) + 0x210);
        goto LAB_000ffade;
      }
      uVar5 = 0xa2e;
      pEVar12 = (EVP_PKEY *)0x0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x404);
      if (*(int *)(iVar1 + 0xc) == 0) {
        pkey = *(EVP_PKEY **)(iVar1 + 4);
        pEVar12 = (EVP_PKEY *)0x0;
        if (pkey == (EVP_PKEY *)0x0) {
          if (*(code **)(iVar1 + 8) == (code *)0x0) {
            ossl_statem_fatal(param_1,0x50,0x1ec,0xab,"ssl/statem/statem_srvr.c",0xa02);
            pEVar12 = (EVP_PKEY *)0x0;
            goto LAB_000ffbb8;
          }
          (**(code **)(iVar1 + 8))(param_1,0,0x400);
          pkey = (EVP_PKEY *)ssl_dh_to_pkey();
          pEVar12 = pkey;
          if (pkey == (EVP_PKEY *)0x0) {
            uVar5 = 0x9fa;
            goto LAB_000ffb84;
          }
        }
      }
      else {
        dh = (DH *)ssl_get_auto_dh(param_1);
        pkey = EVP_PKEY_new();
        pEVar12 = pkey;
        if (dh == (DH *)0x0 || pkey == (EVP_PKEY *)0x0) {
          DH_free(dh);
          uVar5 = 0x9ec;
          goto LAB_000ffb84;
        }
        EVP_PKEY_assign(pkey,0x1c,dh);
      }
      uVar5 = EVP_PKEY_security_bits(pkey);
      iVar1 = ssl_security(param_1,0x40007,uVar5,0,pkey);
      if (iVar1 == 0) {
        ossl_statem_fatal(param_1,0x28,0x1ec,0x18a,"ssl/statem/statem_srvr.c",0xa09);
        goto LAB_000ffbb8;
      }
      iVar1 = *(int *)(param_1 + 0x7c);
      if (*(int *)(iVar1 + 0x214) == 0) {
        uVar5 = ssl_generate_pkey(pkey);
        iVar3 = *(int *)(param_1 + 0x7c);
        *(undefined4 *)(iVar1 + 0x214) = uVar5;
        if (*(int *)(iVar3 + 0x214) == 0) {
          ossl_statem_fatal(param_1,0x50,0,0x44,"ssl/statem/statem_srvr.c",0xa15);
          goto LAB_000ffbb8;
        }
        iVar1 = EVP_PKEY_get0_DH();
        if (iVar1 != 0) {
          EVP_PKEY_free(pEVar12);
          DH_get0_pqg(iVar1,local_38,0,local_38 + 1);
          DH_get0_key(iVar1,local_38 + 2,0);
          iVar1 = *(int *)(*(int *)(param_1 + 0x7c) + 0x210);
          local_74 = 0;
          local_70 = 0;
          goto LAB_000ffade;
        }
        uVar5 = 0xa1d;
      }
      else {
        uVar5 = 0xa0f;
      }
    }
LAB_000ffb84:
    ossl_statem_fatal(param_1,0x50,0x1ec,0x44,"ssl/statem/statem_srvr.c",uVar5);
  }
  else {
    local_74 = 0;
    local_70 = 0;
LAB_000ffade:
    if ((*(uint *)(iVar1 + 0x14) & 0x44) == 0) {
      if ((*(uint *)(iVar1 + 0x10) & 0x1c8) == 0) {
        if (iVar11 == 0) {
          ossl_statem_fatal(param_1,0x32,0x1ec,0x44,"ssl/statem/statem_srvr.c",0xa70);
          pEVar12 = (EVP_PKEY *)0x0;
          goto LAB_000ffbb8;
        }
      }
      else {
        iVar11 = 0;
      }
    }
    else {
      iVar11 = 0;
    }
    if (((uVar10 & 0x1c8) != 0) &&
       (((__s = *(char **)(*(int *)(param_1 + 0x404) + 0x104), pcVar2 = __s, __s != (char *)0x0 &&
         (pcVar2 = (char *)strlen(__s), (char *)0x80 < pcVar2)) ||
        (iVar1 = WPACKET_sub_memcpy__(param_2,__s,pcVar2,2), iVar1 == 0)))) {
      uVar5 = 0xa82;
      goto LAB_000ffb16;
    }
    iVar1 = 0;
    ppBVar9 = local_38;
    do {
      if (*ppBVar9 == (BIGNUM *)0x0) break;
      if (iVar1 == 2) {
        if ((uVar10 & 0x20) == 0) {
          iVar3 = WPACKET_start_sub_packet_len__(param_2,2);
        }
        else {
          iVar3 = WPACKET_start_sub_packet_len__(param_2,1);
        }
        if (iVar3 == 0) {
LAB_000fff4a:
          uVar5 = 0xa96;
          goto LAB_000ffb16;
        }
        if ((uVar10 & 0x102) != 0) {
          iVar3 = BN_num_bits(local_38[0]);
          iVar4 = BN_num_bits(local_38[2]);
          iVar7 = iVar3 + 7;
          if (iVar7 < 0) {
            iVar7 = iVar3 + 0xe;
          }
          iVar3 = iVar4 + 7;
          if (iVar3 < 0) {
            iVar3 = iVar4 + 0xe;
          }
          __n = (iVar7 >> 3) - (iVar3 >> 3);
          if (__n != 0) {
            iVar3 = WPACKET_allocate_bytes(param_2,__n,&local_3c);
            if (iVar3 == 0) {
              uVar5 = 0xaa7;
              goto LAB_000ffb16;
            }
            memset(local_3c,0,__n);
          }
        }
      }
      else {
        iVar3 = WPACKET_start_sub_packet_len__(param_2,2);
        if (iVar3 == 0) goto LAB_000fff4a;
      }
      iVar4 = BN_num_bits(*ppBVar9);
      iVar3 = iVar4 + 0xe;
      if (-1 < iVar4 + 7) {
        iVar3 = iVar4 + 7;
      }
      iVar3 = WPACKET_allocate_bytes(param_2,iVar3 >> 3,&local_3c);
      if ((iVar3 == 0) || (iVar3 = WPACKET_close(param_2), iVar3 == 0)) {
        uVar5 = 0xab2;
        goto LAB_000ffb16;
      }
      iVar1 = iVar1 + 1;
      BN_bn2bin(*ppBVar9,local_3c);
      ppBVar9 = ppBVar9 + 1;
    } while (iVar1 != 4);
    if ((uVar10 & 0x84) != 0) {
      uVar13 = WPACKET_put_bytes__(param_2);
      if (((((int)uVar13 == 0) ||
           (iVar1 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar13 >> 0x20),0,0,1), iVar1 == 0)
           ) || (iVar1 = WPACKET_put_bytes__(param_2,local_74,local_74,local_74 >> 0x1f,1),
                iVar1 == 0)) ||
         (iVar1 = WPACKET_sub_memcpy__(param_2,local_5c,local_70,1), iVar1 == 0)) {
        uVar5 = 0xac7;
        goto LAB_000ffb16;
      }
      CRYPTO_free(local_5c);
      local_5c = (void *)0x0;
    }
    if (iVar11 == 0) {
LAB_0010001a:
      EVP_MD_CTX_free(ctx);
      return 1;
    }
    pEVar12 = *(EVP_PKEY **)(*(int *)(*(int *)(param_1 + 0x7c) + 0x264) + 4);
    if ((pEVar12 == (EVP_PKEY *)0x0) || (iVar1 = tls1_lookup_md(iVar11,&local_4c), iVar1 == 0)) {
      uVar5 = 0xadb;
LAB_000ffb16:
      uVar6 = 0x44;
      goto LAB_000ffb1c;
    }
    iVar1 = WPACKET_get_length(param_2,&local_54);
    if (iVar1 == 0) {
      uVar5 = 0xae2;
      goto LAB_000ffb16;
    }
    if ((*(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1e < 0) &&
       (iVar1 = WPACKET_put_bytes__(param_2,2,*(undefined2 *)(iVar11 + 4),0,2), iVar1 == 0)) {
      uVar5 = 0xae9;
      goto LAB_000ffb16;
    }
    local_3c = (uchar *)EVP_PKEY_size(pEVar12);
    iVar1 = WPACKET_sub_reserve_bytes__(param_2,local_3c,&local_48,2);
    if ((iVar1 == 0) ||
       (iVar1 = EVP_DigestSignInit(ctx,&local_58,local_4c,(ENGINE *)0x0,pEVar12), iVar1 < 1)) {
      uVar5 = 0xaf7;
      goto LAB_000ffb16;
    }
    if ((*(int *)(iVar11 + 0x10) == 0x390) &&
       ((iVar11 = RSA_pkey_ctx_ctrl(local_58,0xffffffff,0x1001,6,0), iVar11 < 1 ||
        (iVar11 = RSA_pkey_ctx_ctrl(local_58,0x18,0x1002,0xffffffff,0), iVar11 < 1)))) {
      ossl_statem_fatal(param_1,0x50,0x1ec,6,"ssl/statem/statem_srvr.c",0xaff);
    }
    else {
      iVar11 = construct_key_exchange_tbs
                         (param_1,&local_40,local_50 + *(int *)(*(int *)(param_1 + 0x6c) + 4),
                          local_54);
      if (iVar11 != 0) {
        iVar11 = EVP_DigestSign(ctx,local_48,&local_3c,local_40,iVar11);
        CRYPTO_free(local_40);
        if (((0 < iVar11) &&
            (iVar11 = WPACKET_sub_allocate_bytes__(param_2,local_3c,&local_44,2), iVar11 != 0)) &&
           (local_48 == local_44)) goto LAB_0010001a;
        uVar5 = 0xb10;
        goto LAB_000ffb16;
      }
    }
LAB_000ffb28:
    pEVar12 = (EVP_PKEY *)0x0;
  }
LAB_000ffbb8:
  EVP_PKEY_free(pEVar12);
  CRYPTO_free(local_5c);
  EVP_MD_CTX_free(ctx);
  return 0;
}

