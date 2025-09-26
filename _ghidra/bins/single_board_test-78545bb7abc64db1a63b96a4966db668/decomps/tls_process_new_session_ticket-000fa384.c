
undefined4 tls_process_new_session_ticket(int param_1,int *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  uint uVar9;
  time_t tVar10;
  void *pvVar11;
  EVP_MD *pEVar12;
  uint uVar13;
  int iVar14;
  byte *pbVar15;
  undefined1 *puVar16;
  byte *pbVar17;
  undefined4 uVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  uint __n;
  int *piVar22;
  int iVar23;
  void *local_34;
  undefined1 *local_30;
  uint local_2c;
  
  uVar20 = param_2[1];
  local_34 = (void *)0x0;
  if (uVar20 < 4) {
LAB_000fa410:
    uVar18 = 0xa26;
  }
  else {
    piVar22 = *(int **)(param_1 + 4);
    pbVar17 = (byte *)*param_2;
    uVar13 = uVar20 - 4;
    bVar1 = pbVar17[2];
    pbVar15 = pbVar17 + 4;
    bVar4 = *pbVar17;
    bVar5 = pbVar17[1];
    bVar6 = pbVar17[3];
    uVar9 = *(uint *)(piVar22[0x19] + 0x30) & 8;
    *param_2 = (int)pbVar15;
    param_2[1] = uVar13;
    if (uVar9 == 0) {
      if (*piVar22 != 0x10000 && 0x303 < *piVar22) {
        if (3 < uVar13) {
          bVar2 = pbVar17[5];
          bVar7 = pbVar17[4];
          bVar8 = pbVar17[6];
          bVar3 = pbVar17[7];
          param_2[1] = uVar20 - 8;
          *param_2 = (int)(pbVar17 + 8);
          if (uVar20 - 8 != 0) {
            uVar21 = (uint)pbVar17[8];
            if (uVar21 <= uVar20 - 9) {
              uVar13 = (uVar20 - 9) - uVar21;
              param_2[1] = uVar13;
              pbVar17 = pbVar17 + 9;
              pbVar15 = pbVar17 + uVar21;
              *param_2 = (int)pbVar15;
              uVar20 = (uint)bVar2 << 0x10 | (uint)bVar7 << 0x18 | (uint)bVar3 | (uint)bVar8 << 8;
              goto LAB_000fa448;
            }
          }
        }
        goto LAB_000fa410;
      }
      uVar20 = 0;
      pbVar17 = (byte *)0x0;
      uVar21 = 0;
    }
    else {
      uVar21 = 0;
      pbVar17 = (byte *)0x0;
      uVar20 = 0;
    }
LAB_000fa448:
    if (uVar13 < 2) goto LAB_000fa410;
    bVar2 = *pbVar15;
    uVar13 = uVar13 - 2;
    bVar3 = pbVar15[1];
    param_2[1] = uVar13;
    *param_2 = (int)(pbVar15 + 2);
    __n = (uint)CONCAT11(bVar2,bVar3);
    if ((uVar9 == 0) && (*piVar22 != 0x10000 && 0x303 < *piVar22)) {
      if ((__n == 0) || (uVar13 < __n)) goto LAB_000fa410;
LAB_000fa492:
      iVar14 = *(int *)(param_1 + 0x474);
LAB_000fa496:
      iVar14 = ssl_session_dup(iVar14,0);
      if (iVar14 == 0) {
        ossl_statem_fatal(param_1,0x50,0x16e,0x41,"ssl/statem/statem_clnt.c",0xa44);
        goto LAB_000fa42c;
      }
      if (((*(SSL_CTX **)(param_1 + 0x5e0))->session_timeout << 0x1f < 0) &&
         (((*(uint *)((*(int **)(param_1 + 4))[0x19] + 0x30) & 8) != 0 ||
          (iVar23 = **(int **)(param_1 + 4), iVar23 == 0x10000 || iVar23 < 0x304)))) {
        SSL_CTX_remove_session(*(SSL_CTX **)(param_1 + 0x5e0),*(SSL_SESSION **)(param_1 + 0x474));
      }
      SSL_SESSION_free(*(SSL_SESSION **)(param_1 + 0x474));
      *(int *)(param_1 + 0x474) = iVar14;
    }
    else {
      if (__n != uVar13) goto LAB_000fa410;
      if (__n == 0) {
        return 3;
      }
      if ((uVar9 == 0) && (*piVar22 != 0x10000 && 0x303 < *piVar22)) goto LAB_000fa492;
      iVar14 = *(int *)(param_1 + 0x474);
      if (*(int *)(iVar14 + 0x148) != 0) goto LAB_000fa496;
    }
    tVar10 = time((time_t *)0x0);
    iVar23 = *(int *)(param_1 + 0x474);
    *(time_t *)(iVar14 + 0x1b0) = tVar10;
    CRYPTO_free(*(void **)(iVar23 + 0x1d0));
    iVar23 = *(int *)(param_1 + 0x474);
    *(undefined4 *)(iVar23 + 0x1d0) = 0;
    *(undefined4 *)(iVar23 + 0x1d4) = 0;
    pvVar11 = CRYPTO_malloc(__n,"ssl/statem/statem_clnt.c",0xa60);
    iVar14 = *(int *)(param_1 + 0x474);
    *(void **)(iVar23 + 0x1d0) = pvVar11;
    pvVar11 = *(void **)(iVar14 + 0x1d0);
    if (pvVar11 == (void *)0x0) {
      ossl_statem_fatal(param_1,0x50,0x16e,0x41,"ssl/statem/statem_clnt.c",0xa63);
      goto LAB_000fa42c;
    }
    if ((uint)param_2[1] < __n) {
      ossl_statem_fatal(param_1,0x32,0x16e,0x9f,"ssl/statem/statem_clnt.c",0xa68);
      goto LAB_000fa42c;
    }
    memcpy(pvVar11,(void *)*param_2,__n);
    piVar22 = *(int **)(param_1 + 4);
    iVar14 = *(int *)(param_1 + 0x474);
    uVar9 = *(uint *)(piVar22[0x19] + 0x30);
    *param_2 = *param_2 + __n;
    param_2[1] = param_2[1] - __n;
    *(uint *)(iVar14 + 0x1d8) =
         (uint)bVar5 << 0x10 | (uint)bVar4 << 0x18 | (uint)bVar6 | (uint)bVar1 << 8;
    *(uint *)(iVar14 + 0x1dc) = uVar20;
    *(uint *)(iVar14 + 0x1d4) = __n;
    if ((uVar9 & 8) != 0) {
LAB_000fa6a4:
      pvVar11 = *(void **)(iVar14 + 0x1d0);
      pEVar12 = EVP_sha256();
      iVar14 = EVP_Digest(pvVar11,__n,(uchar *)(iVar14 + 0x14c),(uint *)&local_30,pEVar12,
                          (ENGINE *)0x0);
      if (iVar14 != 0) {
        piVar22 = *(int **)(param_1 + 4);
        iVar23 = *(int *)(param_1 + 0x474);
        iVar14 = piVar22[0x19];
        *(undefined4 *)(iVar23 + 0x198) = 0;
        *(undefined1 **)(iVar23 + 0x148) = local_30;
        if (-1 < *(int *)(iVar14 + 0x30) << 0x1c) {
          iVar23 = *piVar22;
          iVar14 = iVar23 + -0x10000;
          if (iVar14 != 0) {
            iVar14 = 1;
          }
          if (iVar23 < 0x304) {
            iVar14 = 0;
          }
          if (iVar14 != 0) {
            pEVar12 = (EVP_MD *)ssl_handshake_md(param_1);
            iVar14 = EVP_MD_size(pEVar12);
            if (iVar14 < 0) {
              ossl_statem_fatal(param_1,0x50,0x16e,0x44,"ssl/statem/statem_clnt.c",0xaaa);
            }
            else {
              iVar23 = tls13_hkdf_expand(param_1,pEVar12,param_1 + 0x18c,"resumption",10,pbVar17,
                                         uVar21,*(int *)(param_1 + 0x474) + 0x48,iVar14,1);
              if (iVar23 != 0) {
                *(int *)(*(int *)(param_1 + 0x474) + 4) = iVar14;
                CRYPTO_free(local_34);
                ssl_update_cache(param_1,1);
                return 1;
              }
            }
            goto LAB_000fa42c;
          }
        }
        return 3;
      }
      ossl_statem_fatal(param_1,0x50,0x16e,6,"ssl/statem/statem_clnt.c",0xa99);
      goto LAB_000fa42c;
    }
    iVar19 = *piVar22;
    iVar23 = iVar19 + -0x10000;
    if (iVar23 != 0) {
      iVar23 = 1;
    }
    if (iVar19 < 0x304) {
      iVar23 = 0;
    }
    if (iVar23 == 0) goto LAB_000fa6a4;
    if (1 < (uint)param_2[1]) {
      puVar16 = (undefined1 *)*param_2;
      uVar20 = param_2[1] - 2;
      uVar9 = (uint)CONCAT11(*puVar16,puVar16[1]);
      if (uVar9 <= uVar20) {
        if (uVar9 == uVar20) {
          *param_2 = (int)(puVar16 + 2 + uVar9);
          param_2[1] = 0;
          local_30 = puVar16 + 2;
          local_2c = uVar9;
          iVar14 = tls_collect_extensions(param_1,&local_30,0x2000,&local_34,0,1);
          if ((iVar14 == 0) ||
             (iVar14 = tls_parse_all_extensions(param_1,0x2000,local_34,0,0,1), iVar14 == 0))
          goto LAB_000fa42c;
          iVar14 = *(int *)(param_1 + 0x474);
          goto LAB_000fa6a4;
        }
      }
    }
    uVar18 = 0xa77;
  }
  ossl_statem_fatal(param_1,0x32,0x16e,0x9f,"ssl/statem/statem_clnt.c",uVar18);
LAB_000fa42c:
  CRYPTO_free(local_34);
  return 0;
}

