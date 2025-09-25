
undefined4 tls_construct_stoc_cookie(int param_1,undefined4 param_2)

{
  int iVar1;
  time_t tVar2;
  EVP_MD_CTX *ctx;
  EVP_PKEY *pkey;
  EVP_MD *type;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined1 auStack_34 [4];
  uint local_30;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24 [2];
  
  if (-1 < **(int **)(param_1 + 0x7c) << 0x14) {
    return 2;
  }
  if (*(int *)(*(int *)(param_1 + 0x4d0) + 0x84) == 0) {
    ossl_statem_fatal(param_1,0x50,0x265,0x11f,"ssl/statem/extensions_srvr.c",0x6fa);
    return 0;
  }
  iVar1 = WPACKET_put_bytes__(param_2,param_2,0x2c,0,2);
  if ((((iVar1 != 0) && (iVar1 = WPACKET_start_sub_packet_len__(param_2,2), iVar1 != 0)) &&
      (iVar1 = WPACKET_start_sub_packet_len__(param_2,2), iVar1 != 0)) &&
     (iVar1 = WPACKET_get_total_written(param_2,&local_38), iVar1 != 0)) {
    uVar6 = WPACKET_reserve_bytes(param_2,0x1076,&local_44);
    if ((int)uVar6 != 0) {
      uVar6 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar6 >> 0x20),1,0,2);
      if ((int)uVar6 != 0) {
        uVar6 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar6 >> 0x20),0x304,0,2);
        if ((((int)uVar6 != 0) &&
            (iVar1 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar6 >> 0x20),
                                         *(undefined2 *)(*(int *)(param_1 + 0x7c) + 0x356),0,2),
            iVar1 != 0)) &&
           ((iVar1 = (**(code **)(*(int *)(param_1 + 4) + 0x50))
                               (*(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x210),param_2,auStack_34
                               ), iVar1 != 0 &&
            (iVar1 = WPACKET_put_bytes__(param_2,1,*(int *)(*(int *)(param_1 + 0x7c) + 0x358) == 0,0
                                         ,1), iVar1 != 0)))) {
          tVar2 = time((time_t *)0x0);
          iVar1 = WPACKET_put_bytes__(param_2,8,tVar2,tVar2 >> 0x1f,8);
          if (((iVar1 != 0) && (iVar1 = WPACKET_start_sub_packet_len__(param_2,2), iVar1 != 0)) &&
             (iVar1 = WPACKET_reserve_bytes(param_2,0x40,&local_54), iVar1 != 0)) {
            iVar1 = ssl3_digest_cached_records(param_1,0);
            if (iVar1 == 0) {
              return 0;
            }
            iVar1 = ssl_handshake_hash(param_1,local_54,0x40,&local_2c);
            if (iVar1 == 0) {
              return 0;
            }
            iVar1 = WPACKET_allocate_bytes(param_2,local_2c,&local_50);
            if ((((iVar1 != 0) && (local_54 == local_50)) &&
                (iVar1 = WPACKET_close(param_2), iVar1 != 0)) &&
               ((iVar1 = WPACKET_start_sub_packet_len__(param_2,1), iVar1 != 0 &&
                (iVar1 = WPACKET_reserve_bytes(param_2,0x1000,&local_4c), iVar1 != 0)))) {
              iVar1 = (**(code **)(*(int *)(param_1 + 0x4d0) + 0x84))(param_1,local_4c,local_24);
              if (iVar1 == 0) {
                ossl_statem_fatal(param_1,0x50,0x265,400,"ssl/statem/extensions_srvr.c",0x72a);
                return 0;
              }
              iVar1 = WPACKET_allocate_bytes(param_2,local_24[0],&local_48);
              if (((iVar1 == 0) || (local_4c != local_48)) ||
                 ((iVar1 = WPACKET_close(param_2), iVar1 == 0 ||
                  ((iVar1 = WPACKET_get_total_written(param_2,&local_30), iVar1 == 0 ||
                   (iVar1 = WPACKET_reserve_bytes(param_2,0x20,&local_40), iVar1 == 0)))))) {
                uVar3 = 0x734;
                goto LAB_000e8b5c;
              }
              local_28 = 0x20;
              local_30 = local_30 - local_38;
              if (0x1056 < local_30) {
                uVar3 = 0x73c;
                goto LAB_000e8b5c;
              }
              ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
              pkey = (EVP_PKEY *)
                     EVP_PKEY_new_raw_private_key(0x357,0,*(int *)(param_1 + 0x5e0) + 400,0x20);
              if ((ctx == (EVP_MD_CTX *)0x0) || (pkey == (EVP_PKEY *)0x0)) {
                uVar3 = 0x748;
                uVar4 = 0x41;
              }
              else {
                type = EVP_sha256();
                iVar1 = EVP_DigestSignInit(ctx,(EVP_PKEY_CTX **)0x0,type,(ENGINE *)0x0,pkey);
                if ((iVar1 < 1) ||
                   (iVar1 = EVP_DigestSign(ctx,local_40,&local_28,local_44,local_30), iVar1 < 1)) {
                  uVar3 = 0x750;
                }
                else {
                  if (0x1076 < local_30 + local_28) {
                    ossl_statem_fatal(param_1,0x50,0x265,0x44,"ssl/statem/extensions_srvr.c",0x756);
                    uVar5 = 0;
                    goto LAB_000e8db2;
                  }
                  iVar1 = WPACKET_allocate_bytes(param_2,local_28,&local_3c);
                  if ((((iVar1 != 0) && (local_40 == local_3c)) && (local_44 == local_40 - local_30)
                      ) && ((iVar1 = WPACKET_close(param_2), iVar1 != 0 &&
                            (iVar1 = WPACKET_close(param_2), iVar1 != 0)))) {
                    uVar5 = 1;
                    goto LAB_000e8db2;
                  }
                  uVar3 = 0x760;
                }
                uVar4 = 0x44;
              }
              uVar5 = 0;
              ossl_statem_fatal(param_1,0x50,0x265,uVar4,"ssl/statem/extensions_srvr.c",uVar3);
LAB_000e8db2:
              EVP_MD_CTX_free(ctx);
              EVP_PKEY_free(pkey);
              return uVar5;
            }
            uVar3 = 0x723;
            goto LAB_000e8b5c;
          }
        }
      }
    }
  }
  uVar3 = 0x70e;
LAB_000e8b5c:
  ossl_statem_fatal(param_1,0x50,0x265,0x44,"ssl/statem/extensions_srvr.c",uVar3);
  return 0;
}

