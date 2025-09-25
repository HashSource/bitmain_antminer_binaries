
undefined4 tls_process_client_certificate(int *param_1,undefined4 *param_2)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  byte *pbVar6;
  void *pvVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  uint uVar11;
  X509 *a;
  bool bVar12;
  undefined4 uVar13;
  byte **in;
  char *pcVar14;
  byte *local_38;
  void *local_34;
  byte *local_30;
  uint local_2c;
  
  param_1[0x19] = 0;
  iVar1 = OPENSSL_sk_new_null();
  if (iVar1 == 0) {
    ossl_statem_fatal(param_1,0x50,0x17c,0x41,"ssl/statem/statem_srvr.c",0xe1c);
    a = (X509 *)0x0;
    uVar13 = 0;
    goto LAB_000f5890;
  }
  if ((*(int *)(((int *)param_1[1])[0x19] + 0x30) << 0x1c < 0) ||
     (iVar8 = *(int *)param_1[1], iVar8 == 0x10000 || iVar8 < 0x304)) {
LAB_000f5860:
    pbVar6 = (byte *)*param_2;
    uVar9 = param_2[1];
LAB_000f5864:
    if (uVar9 < 3) {
LAB_000f5868:
      uVar13 = 0xe2c;
      iVar8 = 0x9f;
      goto LAB_000f5878;
    }
    pbVar2 = pbVar6 + 3;
    uVar11 = (uint)pbVar6[1] << 8 | (uint)*pbVar6 << 0x10 | (uint)pbVar6[2];
    if (uVar9 - 3 < uVar11) goto LAB_000f5868;
    iVar8 = (uVar9 - 3) - uVar11;
    *param_2 = pbVar2 + uVar11;
    param_2[1] = iVar8;
    if (iVar8 != 0) goto LAB_000f5868;
    if (uVar11 != 0) {
      if (2 < uVar11) {
        in = &local_38;
        pcVar14 = "ssl/statem/statem_srvr.c";
        iVar8 = 0;
        do {
          uVar9 = (uint)pbVar2[1] << 8 | (uint)*pbVar2 << 0x10 | (uint)pbVar2[2];
          if (uVar11 - 3 < uVar9) break;
          uVar11 = (uVar11 - 3) - uVar9;
          local_38 = pbVar2 + 3;
          a = d2i_X509((X509 **)0x0,in,uVar9);
          if (a == (X509 *)0x0) {
            uVar4 = 0xe3d;
            uVar13 = 0xd;
LAB_000f5a44:
            ossl_statem_fatal(param_1,0x32,0x17c,uVar13,"ssl/statem/statem_srvr.c",uVar4,in,pcVar14)
            ;
LAB_000f597c:
            uVar13 = 0;
            goto LAB_000f5890;
          }
          if (local_38 != pbVar2 + 3 + uVar9) {
            uVar4 = 0xe43;
            uVar13 = 0x87;
            goto LAB_000f5a44;
          }
          pvVar7 = (void *)(*(uint *)(((int *)param_1[1])[0x19] + 0x30) & 8);
          pbVar2 = local_38;
          if (pvVar7 == (void *)0x0) {
            iVar5 = *(int *)param_1[1];
            iVar3 = iVar5 + -0x10000;
            if (iVar3 != 0) {
              iVar3 = 1;
            }
            if (iVar5 < 0x304) {
              iVar3 = 0;
            }
            if (iVar3 == 0) goto LAB_000f59dc;
            local_34 = pvVar7;
            if (uVar11 < 2) {
LAB_000f5960:
              ossl_statem_fatal(param_1,0x32,0x17c,0x10f,"ssl/statem/statem_srvr.c",0xe4e,in,pcVar14
                               );
            }
            else {
              uVar9 = (uint)CONCAT11(*local_38,local_38[1]);
              if (uVar11 - 2 < uVar9) goto LAB_000f5960;
              uVar11 = (uVar11 - 2) - uVar9;
              pbVar2 = local_38 + 2 + uVar9;
              local_30 = local_38 + 2;
              local_2c = uVar9;
              iVar3 = tls_collect_extensions(param_1,&local_30,0x1000,&local_34,0,iVar8 == 0);
              if ((iVar3 != 0) &&
                 (iVar3 = tls_parse_all_extensions(param_1,0x1000,local_34,a,iVar8,uVar11 == 0),
                 iVar3 != 0)) {
                CRYPTO_free(local_34);
                goto LAB_000f59dc;
              }
              CRYPTO_free(local_34);
            }
            goto LAB_000f597c;
          }
LAB_000f59dc:
          iVar3 = OPENSSL_sk_push(iVar1,a);
          if (iVar3 == 0) {
            ossl_statem_fatal(param_1,0x50,0x17c,0x41,"ssl/statem/statem_srvr.c",0xe60,in,pcVar14);
            uVar13 = 0;
            goto LAB_000f5890;
          }
          iVar8 = iVar8 + 1;
          if (uVar11 == 0) goto LAB_000f5a02;
        } while (2 < uVar11);
      }
      uVar13 = 0xe35;
      iVar8 = 0x87;
      goto LAB_000f5878;
    }
LAB_000f5a02:
    iVar8 = OPENSSL_sk_num(iVar1);
    if (0 < iVar8) {
      iVar8 = ssl_verify_cert_chain(param_1,iVar1);
      if (iVar8 < 1) {
        a = (X509 *)0x0;
        uVar4 = ssl_x509err2alert(param_1[0x136]);
        uVar13 = 0;
        ossl_statem_fatal(param_1,uVar4,0x17c,0x86,"ssl/statem/statem_srvr.c",0xe81);
        goto LAB_000f5890;
      }
      if (iVar8 != 1) {
        uVar13 = 0xe86;
        uVar4 = 0x28;
        goto LAB_000f5880;
      }
      OPENSSL_sk_value(iVar1,0);
      iVar8 = X509_get0_pubkey();
      if (iVar8 == 0) {
        ossl_statem_fatal(param_1,0x28,0x17c,0xf7,"ssl/statem/statem_srvr.c",0xe8d);
        a = (X509 *)0x0;
        uVar13 = 0;
        goto LAB_000f5890;
      }
LAB_000f5ab8:
      if (param_1[0x17d] == 4) {
        iVar8 = ssl_session_dup(param_1[0x11d],0);
        if (iVar8 == 0) {
          ossl_statem_fatal(param_1,0x50,0x17c,0x41,"ssl/statem/statem_srvr.c",0xe9e);
          a = (X509 *)0x0;
          uVar13 = 0;
          goto LAB_000f5890;
        }
        SSL_SESSION_free((SSL_SESSION *)param_1[0x11d]);
        param_1[0x11d] = iVar8;
      }
      else {
        iVar8 = param_1[0x11d];
      }
      X509_free(*(X509 **)(iVar8 + 0x19c));
      iVar5 = param_1[0x11d];
      uVar13 = OPENSSL_sk_shift(iVar1);
      iVar3 = param_1[0x11d];
      iVar8 = param_1[0x136];
      *(undefined4 *)(iVar5 + 0x19c) = uVar13;
      *(int *)(iVar3 + 0x1a4) = iVar8;
      OPENSSL_sk_pop_free(*(undefined4 *)(iVar3 + 0x1a0),(undefined *)0x16a341);
      piVar10 = (int *)param_1[1];
      iVar8 = piVar10[0x19];
      *(int *)(param_1[0x11d] + 0x1a0) = iVar1;
      if (-1 < *(int *)(iVar8 + 0x30) << 0x1c) {
        iVar8 = *piVar10;
        bVar12 = SBORROW4(iVar8,0x10000);
        iVar1 = iVar8 + -0x10000;
        if (iVar8 != 0x10000) {
          bVar12 = SBORROW4(iVar8,0x303);
          iVar1 = iVar8 + -0x303;
        }
        if ((iVar8 != 0x10000 && iVar8 != 0x303) && iVar1 < 0 == bVar12) {
          iVar1 = ssl3_digest_cached_records(param_1,1);
          if (iVar1 == 0) {
LAB_000f5c60:
            iVar1 = 0;
            a = (X509 *)0x0;
            uVar13 = 0;
            goto LAB_000f5890;
          }
          if ((*(uint *)(((int *)param_1[1])[0x19] + 0x30) & 8) == 0) {
            iVar8 = *(int *)param_1[1];
            bVar12 = SBORROW4(iVar8,0x10000);
            iVar1 = iVar8 + -0x10000;
            if (iVar8 != 0x10000) {
              bVar12 = SBORROW4(iVar8,0x303);
              iVar1 = iVar8 + -0x303;
            }
            if ((iVar8 != 0x10000 && iVar8 != 0x303) && iVar1 < 0 == bVar12) {
              iVar1 = ssl_handshake_hash(param_1,param_1 + 0x102,0x40,param_1 + 0x112);
              if (iVar1 != 0) {
                param_1[0x3dc] = 0;
                uVar13 = 3;
                a = (X509 *)0x0;
                iVar1 = 0;
                goto LAB_000f5890;
              }
              goto LAB_000f5c60;
            }
          }
        }
      }
      iVar1 = 0;
      uVar13 = 3;
      a = (X509 *)0x0;
      goto LAB_000f5890;
    }
    if (*param_1 == 0x300) {
      uVar13 = 0xe6b;
      iVar8 = 0xb0;
      uVar4 = 0x28;
      goto LAB_000f5880;
    }
    if ((param_1[299] & 3U) == 3) {
      uVar13 = 0xe73;
      iVar8 = 199;
      uVar4 = 0x74;
      goto LAB_000f5880;
    }
    if ((*(int *)(param_1[0x1f] + 0xd4) == 0) ||
       (iVar8 = ssl3_digest_cached_records(param_1,0), iVar8 != 0)) goto LAB_000f5ab8;
  }
  else {
    if (param_2[1] != 0) {
      uVar9 = param_2[1] - 1;
      pbVar2 = (byte *)*param_2 + 1;
      uVar11 = (uint)*(byte *)*param_2;
      if (uVar11 <= uVar9) {
        uVar9 = uVar9 - uVar11;
        pbVar6 = pbVar2 + uVar11;
        *param_2 = pbVar6;
        param_2[1] = uVar9;
        if ((void *)param_1[0x17f] == (void *)0x0) {
          if (uVar11 == 0) goto LAB_000f5864;
        }
        else if ((param_1[0x180] == uVar11) &&
                (iVar8 = CRYPTO_memcmp(pbVar2,(void *)param_1[0x17f],param_1[0x180]), iVar8 == 0))
        goto LAB_000f5860;
      }
    }
    uVar13 = 0xe25;
    iVar8 = 0x11a;
LAB_000f5878:
    uVar4 = 0x32;
LAB_000f5880:
    ossl_statem_fatal(param_1,uVar4,0x17c,iVar8,"ssl/statem/statem_srvr.c",uVar13);
  }
  a = (X509 *)0x0;
  uVar13 = 0;
LAB_000f5890:
  X509_free(a);
  OPENSSL_sk_pop_free(iVar1,(undefined *)0x16a341);
  return uVar13;
}

