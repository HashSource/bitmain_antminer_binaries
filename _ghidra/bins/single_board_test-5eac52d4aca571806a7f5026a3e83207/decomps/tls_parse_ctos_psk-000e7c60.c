
undefined4 tls_parse_ctos_psk(int param_1,int *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  SSL_SESSION *pSVar6;
  EVP_MD *pEVar7;
  time_t tVar8;
  void *ptr;
  undefined1 *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined4 uVar13;
  uint uVar14;
  uint uVar15;
  undefined1 *puVar16;
  int iVar17;
  byte *pbVar18;
  uint uVar19;
  byte *pbVar20;
  EVP_MD *local_160;
  undefined4 local_14c;
  undefined2 local_130 [2];
  SSL_SESSION *local_12c;
  undefined1 auStack_128 [260];
  
  local_12c = (SSL_SESSION *)0x0;
  if ((*(uint *)(param_1 + 0x5a4) & 3) == 0) {
    return 1;
  }
  if (1 < (uint)param_2[1]) {
    puVar9 = (undefined1 *)*param_2;
    uVar12 = param_2[1] - 2;
    puVar16 = puVar9 + 2;
    uVar14 = (uint)CONCAT11(*puVar9,puVar9[1]);
    if (uVar14 <= uVar12) {
      *param_2 = (int)(puVar16 + uVar14);
      param_2[1] = uVar12 - uVar14;
      *(undefined4 *)(param_1 + 0x55c) = 0;
      if (uVar14 == 0) {
        return 1;
      }
      if (uVar14 != 1) {
        uVar12 = 0;
        local_160 = (EVP_MD *)0x0;
        local_14c = 0;
        do {
          puVar9 = puVar16 + 2;
          uVar15 = (uint)CONCAT11(*puVar16,puVar16[1]);
          if ((uVar14 - 2 < uVar15) || (uVar14 = (uVar14 - 2) - uVar15, uVar14 < 4)) break;
          bVar4 = puVar9[uVar15];
          puVar16 = puVar9 + uVar15 + 4;
          bVar1 = puVar9[uVar15 + 1];
          bVar2 = puVar9[uVar15 + 2];
          bVar3 = puVar9[uVar15 + 3];
          if ((*(code **)(param_1 + 0x4c8) != (code *)0x0) &&
             (iVar5 = (**(code **)(param_1 + 0x4c8))(param_1,puVar9,uVar15,&local_12c), iVar5 == 0))
          {
            ossl_statem_fatal(param_1,0x50,0x1f9,0x6e,"ssl/statem/extensions_srvr.c",0x442);
            return 0;
          }
          if (local_12c != (SSL_SESSION *)0x0) {
LAB_000e7d14:
            pSVar6 = (SSL_SESSION *)ssl_session_dup(local_12c,0);
            if (pSVar6 == (SSL_SESSION *)0x0) {
              uVar13 = 0x481;
LAB_000e8058:
              ossl_statem_fatal(param_1,0x50,0x1f9,0x44,"ssl/statem/extensions_srvr.c",uVar13);
              goto LAB_000e7e22;
            }
            SSL_SESSION_free(local_12c);
            local_12c = pSVar6;
            memcpy(pSVar6->krb5_client_princ + 0xe0,(void *)(param_1 + 0x454),
                   *(size_t *)(param_1 + 0x450));
            *(undefined4 *)(pSVar6->krb5_client_princ + 0xdc) = *(undefined4 *)(param_1 + 0x450);
            if (uVar12 == 0) {
              *(undefined4 *)(param_1 + 0x5b0) = 1;
            }
            *(undefined4 *)(param_1 + 0x55c) = 1;
            local_14c = 1;
LAB_000e7d5a:
            pEVar7 = (EVP_MD *)ssl_md(pSVar6->cipher[1].name);
            local_160 = (EVP_MD *)
                        ssl_md(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x7c) + 0x210) + 0x34));
            if (pEVar7 != local_160) {
              SSL_SESSION_free(local_12c);
              local_12c = (SSL_SESSION *)0x0;
              *(undefined4 *)(param_1 + 0x5b0) = 0;
              *(undefined4 *)(param_1 + 0x55c) = 0;
              local_160 = pEVar7;
              goto LAB_000e7d90;
            }
LAB_000e7dd2:
            if (local_12c == (SSL_SESSION *)0x0) {
              return 1;
            }
            iVar17 = *param_2;
            iVar5 = *(int *)(*(int *)(param_1 + 0x6c) + 4);
            uVar14 = EVP_MD_size(local_160);
            if (1 < (uint)param_2[1]) {
              puVar9 = (undefined1 *)*param_2;
              uVar15 = param_2[1] - 2;
              pbVar20 = puVar9 + 2;
              uVar10 = (uint)CONCAT11(*puVar9,puVar9[1]);
              if (uVar10 <= uVar15) {
                param_2[1] = uVar15 - uVar10;
                uVar15 = 0;
                *param_2 = (int)(pbVar20 + uVar10);
                goto LAB_000e7f34;
              }
            }
            uVar13 = 0x4e9;
            goto LAB_000e7e10;
          }
          iVar5 = *(int *)(param_1 + 0x4c4);
          if (iVar5 != 0) {
            iVar5 = 1;
          }
          if (0x80 < uVar15) {
            iVar5 = 0;
          }
          if (iVar5 != 0) {
            CRYPTO_free((void *)0x0);
            ptr = (void *)CRYPTO_strndup(puVar9,uVar15,"ssl/statem/../packet_local.h",0x1e5);
            if (ptr == (void *)0x0) {
              uVar13 = 0x450;
              goto LAB_000e80d0;
            }
            uVar10 = (**(code **)(param_1 + 0x4c4))(param_1,ptr,auStack_128,0x100);
            CRYPTO_free(ptr);
            if (0x100 < uVar10) {
              uVar13 = 0x458;
LAB_000e80fa:
              ossl_statem_fatal(param_1,0x50,0x1f9,0x44,"ssl/statem/extensions_srvr.c",uVar13);
              return 0;
            }
            if (uVar10 != 0) {
              local_130[0] = 0x113;
              iVar5 = SSL_CIPHER_find(param_1,local_130);
              if (iVar5 == 0) {
                OPENSSL_cleanse(auStack_128,uVar10);
                uVar13 = 0x466;
                goto LAB_000e80fa;
              }
              local_12c = SSL_SESSION_new();
              if ((((local_12c != (SSL_SESSION *)0x0) &&
                   (iVar17 = SSL_SESSION_set1_master_key(local_12c,auStack_128,uVar10), iVar17 != 0)
                   ) && (iVar5 = SSL_SESSION_set_cipher(local_12c,iVar5), iVar5 != 0)) &&
                 (iVar5 = SSL_SESSION_set_protocol_version(local_12c,0x304), iVar5 != 0)) {
                OPENSSL_cleanse(auStack_128,uVar10);
                goto LAB_000e8000;
              }
              OPENSSL_cleanse(auStack_128,uVar10);
              uVar13 = 0x473;
              goto LAB_000e8058;
            }
LAB_000e8000:
            if (local_12c != (SSL_SESSION *)0x0) goto LAB_000e7d14;
          }
          if ((*(int *)(param_1 + 0x4ec) << 0x11 < 0) ||
             ((*(int *)(param_1 + 0xf50) != 0 && (-1 < *(int *)(param_1 + 0x4ec) << 7)))) {
            *(undefined4 *)(param_1 + 0x55c) = 1;
            if (uVar15 == 0) goto LAB_000e80be;
            if ((uVar15 == 0x20) &&
               (pSVar6 = (SSL_SESSION *)lookup_sess_in_cache(param_1,puVar9,0x20),
               pSVar6 != (SSL_SESSION *)0x0)) {
              uVar15 = 5;
              local_12c = pSVar6;
            }
            else {
              uVar15 = 4;
            }
          }
          else {
            uVar15 = tls_decrypt_ticket(param_1,puVar9,uVar15,0,0,&local_12c);
            if (uVar15 == 3) {
LAB_000e80be:
              uVar13 = 0x4a5;
              goto LAB_000e7da8;
            }
            if (uVar15 < 2) {
              uVar13 = 0x4ac;
LAB_000e80d0:
              ossl_statem_fatal(param_1,0x50,0x1f9,0x44,"ssl/statem/extensions_srvr.c",uVar13);
              return 0;
            }
          }
          if ((uVar15 - 2 & 0xfffffffd) != 0) {
            if (((*(int *)(param_1 + 0xf50) == 0) || (*(int *)(param_1 + 0x4ec) << 7 < 0)) ||
               (iVar5 = SSL_CTX_remove_session(*(SSL_CTX **)(param_1 + 0x5e0),local_12c), iVar5 != 0
               )) {
              tVar8 = time((time_t *)0x0);
              pSVar6 = local_12c;
              if (((uVar12 == 0) &&
                  (uVar15 = tVar8 - local_12c->time, (int)uVar15 <= local_12c->timeout)) &&
                 (uVar15 == (uVar15 * 1000) / 1000)) {
                uVar15 = uVar15 * 1000 + 1000;
                uVar10 = ((uint)bVar1 << 0x10 | (uint)bVar4 << 0x18 | (uint)bVar3 | (uint)bVar2 << 8
                         ) - (int)local_12c->tlsext_ecpointformatlist;
                if (uVar10 <= uVar15) {
                  uVar10 = uVar10 + 10000;
                  uVar19 = uVar10;
                  if (uVar15 <= uVar10) {
                    uVar19 = 1;
                  }
                  if (uVar15 <= uVar10) {
                    *(uint *)(param_1 + 0x5b0) = uVar19;
                  }
                }
              }
              goto LAB_000e7d5a;
            }
            SSL_SESSION_free(local_12c);
            local_12c = (SSL_SESSION *)0x0;
          }
LAB_000e7d90:
          uVar14 = uVar14 - 4;
          uVar12 = uVar12 + 1;
          if (uVar14 == 0) goto LAB_000e7dd2;
        } while (uVar14 != 1);
      }
      uVar13 = 0x439;
      goto LAB_000e7da8;
    }
  }
  uVar13 = 0x42c;
LAB_000e7da8:
  ossl_statem_fatal(param_1,0x32,0x1f9,0x6e,"ssl/statem/extensions_srvr.c",uVar13);
  return 0;
  while( true ) {
    pbVar18 = pbVar20 + 1;
    uVar11 = (uint)*pbVar20;
    uVar15 = uVar15 + 1;
    pbVar20 = pbVar18 + uVar11;
    uVar10 = uVar19 - uVar11;
    if (uVar19 < uVar11) goto LAB_000e7f4e;
    if (uVar12 < uVar15) break;
LAB_000e7f34:
    uVar19 = uVar10 - 1;
    if (uVar10 == 0) {
LAB_000e7f4e:
      uVar13 = 0x4f0;
      goto LAB_000e7e10;
    }
  }
  if (uVar14 == uVar11) {
    iVar5 = tls_psk_do_binder(param_1,local_160,*(undefined4 *)(*(int *)(param_1 + 0x6c) + 4),
                              iVar17 - iVar5,pbVar18,0,local_12c,0,local_14c);
    if (iVar5 == 1) {
      *(uint *)(param_1 + 0x5c4) = uVar12;
      SSL_SESSION_free(*(SSL_SESSION **)(param_1 + 0x474));
      *(SSL_SESSION **)(param_1 + 0x474) = local_12c;
      return 1;
    }
  }
  else {
    uVar13 = 0x4f7;
LAB_000e7e10:
    ossl_statem_fatal(param_1,0x32,0x1f9,0x6e,"ssl/statem/extensions_srvr.c",uVar13);
  }
LAB_000e7e22:
  SSL_SESSION_free(local_12c);
  return 0;
}

