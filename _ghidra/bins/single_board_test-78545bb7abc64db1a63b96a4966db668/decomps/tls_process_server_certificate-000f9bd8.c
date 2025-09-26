
X509 * tls_process_server_certificate(int param_1,undefined4 *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  X509 *pXVar5;
  X509 *a;
  EVP_PKEY *pkey;
  byte *pbVar6;
  int iVar7;
  undefined1 *puVar8;
  byte *pbVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  void *pvVar14;
  int *piVar15;
  X509 *pXVar16;
  uint uVar17;
  undefined4 uVar18;
  byte *local_38;
  void *local_34;
  undefined1 *local_30;
  uint local_2c;
  
  pXVar5 = (X509 *)OPENSSL_sk_new_null();
  if (pXVar5 == (X509 *)0x0) {
    ossl_statem_fatal(param_1,0x50,0x16f,0x41,"ssl/statem/statem_clnt.c",0x72b);
    pXVar16 = (X509 *)0x0;
    a = (X509 *)0x0;
    goto LAB_000f9c36;
  }
  if ((*(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c < 0) ||
     (iVar12 = **(int **)(param_1 + 4), iVar12 == 0x10000 || iVar12 < 0x304)) {
LAB_000f9c60:
    if ((uint)param_2[1] < 3) goto LAB_000f9c18;
    pbVar9 = (byte *)*param_2;
    uVar17 = param_2[1] - 3;
    bVar1 = pbVar9[1];
    pbVar6 = pbVar9 + 3;
    bVar2 = *pbVar9;
    bVar3 = pbVar9[2];
    *param_2 = pbVar6;
    param_2[1] = uVar17;
    if (((uint)bVar1 << 8 | (uint)bVar2 << 0x10 | (uint)bVar3) != uVar17 || uVar17 == 0)
    goto LAB_000f9c18;
    if (2 < uVar17) {
      iVar12 = 0;
      while( true ) {
        bVar1 = pbVar6[1];
        uVar17 = uVar17 - 3;
        bVar2 = *pbVar6;
        pbVar9 = pbVar6 + 3;
        bVar3 = pbVar6[2];
        param_2[1] = uVar17;
        *param_2 = pbVar9;
        uVar10 = (uint)bVar1 << 8 | (uint)bVar2 << 0x10 | (uint)bVar3;
        if (uVar17 < uVar10) break;
        param_2[1] = uVar17 - uVar10;
        *param_2 = pbVar9 + uVar10;
        local_38 = pbVar9;
        a = d2i_X509((X509 **)0x0,&local_38,uVar10);
        if (a == (X509 *)0x0) {
          ossl_statem_fatal(param_1,0x2a,0x16f,0xd,"ssl/statem/statem_clnt.c",0x745);
          pXVar16 = (X509 *)0x0;
          goto LAB_000f9c36;
        }
        if (local_38 != pbVar9 + uVar10) {
          pXVar16 = (X509 *)0x0;
          ossl_statem_fatal(param_1,0x32,0x16f,0x87,"ssl/statem/statem_clnt.c",0x74b);
          goto LAB_000f9c36;
        }
        pvVar14 = (void *)(*(uint *)((*(int **)(param_1 + 4))[0x19] + 0x30) & 8);
        if (pvVar14 == (void *)0x0) {
          iVar11 = **(int **)(param_1 + 4);
          iVar7 = iVar11 + -0x10000;
          if (iVar7 != 0) {
            iVar7 = 1;
          }
          if (iVar11 < 0x304) {
            iVar7 = 0;
          }
          if (iVar7 != 0) {
            local_34 = pvVar14;
            if ((uint)param_2[1] < 2) {
LAB_000f9db8:
              ossl_statem_fatal(param_1,0x32,0x16f,0x10f,"ssl/statem/statem_clnt.c",0x756);
            }
            else {
              puVar8 = (undefined1 *)*param_2;
              uVar17 = param_2[1] - 2;
              uVar10 = (uint)CONCAT11(*puVar8,puVar8[1]);
              if (uVar17 < uVar10) goto LAB_000f9db8;
              param_2[1] = uVar17 - uVar10;
              *param_2 = puVar8 + 2 + uVar10;
              local_30 = puVar8 + 2;
              local_2c = uVar10;
              iVar7 = tls_collect_extensions(param_1,&local_30,0x1000,&local_34,0,iVar12 == 0);
              if ((iVar7 != 0) &&
                 (iVar7 = tls_parse_all_extensions(param_1,0x1000,local_34,a,iVar12,param_2[1] == 0)
                 , iVar7 != 0)) {
                CRYPTO_free(local_34);
                goto LAB_000f9d8a;
              }
              CRYPTO_free(local_34);
            }
            pXVar16 = (X509 *)0x0;
            goto LAB_000f9c36;
          }
        }
LAB_000f9d8a:
        iVar7 = OPENSSL_sk_push(pXVar5,a);
        if (iVar7 == 0) {
          ossl_statem_fatal(param_1,0x50,0x16f,0x41,"ssl/statem/statem_clnt.c",0x769);
          pXVar16 = (X509 *)0x0;
          goto LAB_000f9c36;
        }
        uVar17 = param_2[1];
        if (uVar17 == 0) {
          iVar12 = ssl_verify_cert_chain(param_1,pXVar5);
          iVar7 = *(int *)(param_1 + 0x4ac);
          if (iVar7 != 0) {
            iVar7 = 1;
          }
          if (0 < iVar12) {
            iVar7 = 0;
          }
          if (iVar7 != 0) {
            uVar13 = ssl_x509err2alert(*(undefined4 *)(param_1 + 0x4d8));
            ossl_statem_fatal(param_1,uVar13,0x16f,0x86,"ssl/statem/statem_clnt.c",0x781);
            pXVar16 = (X509 *)0x0;
            a = (X509 *)0x0;
            goto LAB_000f9c36;
          }
          ERR_clear_error();
          if (1 < iVar12) {
            ossl_statem_fatal(param_1,0x28,0x16f,iVar12,"ssl/statem/statem_clnt.c",0x787);
            pXVar16 = (X509 *)0x0;
            a = (X509 *)0x0;
            goto LAB_000f9c36;
          }
          *(X509 **)(*(int *)(param_1 + 0x474) + 0x1a0) = pXVar5;
          uVar13 = OPENSSL_sk_value(pXVar5,0);
          pkey = (EVP_PKEY *)X509_get0_pubkey();
          if ((pkey == (EVP_PKEY *)0x0) || (iVar12 = EVP_PKEY_missing_parameters(pkey), iVar12 != 0)
             ) {
            pXVar16 = (X509 *)0x0;
            ossl_statem_fatal(param_1,0x50,0x16f,0xef,"ssl/statem/statem_clnt.c",0x798);
            a = (X509 *)0x0;
            pXVar5 = pXVar16;
            goto LAB_000f9c36;
          }
          iVar12 = ssl_cert_lookup_by_pkey(pkey,&local_30);
          if (iVar12 == 0) {
            uVar18 = 0x7a0;
            uVar13 = 0xf7;
          }
          else {
            if ((((-1 < *(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c) &&
                 (iVar7 = **(int **)(param_1 + 4), 0x303 < iVar7)) && (iVar7 != 0x10000)) ||
               ((*(uint *)(*(int *)(*(int *)(param_1 + 0x7c) + 0x210) + 0x14) &
                *(uint *)(iVar12 + 4)) != 0)) {
              X509_free(*(X509 **)(*(int *)(param_1 + 0x474) + 0x19c));
              X509_up_ref(uVar13);
              piVar15 = *(int **)(param_1 + 4);
              iVar7 = *(int *)(param_1 + 0x474);
              uVar18 = *(undefined4 *)(param_1 + 0x4d8);
              iVar12 = piVar15[0x19];
              *(undefined4 *)(iVar7 + 0x19c) = uVar13;
              *(undefined4 *)(iVar7 + 0x1a4) = uVar18;
              if (((*(int *)(iVar12 + 0x30) << 0x1c < 0) || (iVar12 = *piVar15, iVar12 == 0x10000))
                 || ((iVar12 < 0x304 ||
                     (iVar12 = ssl_handshake_hash(param_1,param_1 + 0x408,0x40,param_1 + 0x448),
                     iVar12 != 0)))) {
                pXVar16 = (X509 *)0x3;
                a = (X509 *)0x0;
                pXVar5 = (X509 *)0x0;
              }
              else {
                pXVar16 = (X509 *)0x0;
                a = (X509 *)0x0;
                pXVar5 = (X509 *)0x0;
              }
              goto LAB_000f9c36;
            }
            uVar13 = 0x17f;
            uVar18 = 0x7ad;
          }
          pXVar16 = (X509 *)0x0;
          ossl_statem_fatal(param_1,0x2f,0x16f,uVar13,"ssl/statem/statem_clnt.c",uVar18);
          a = pXVar16;
          pXVar5 = pXVar16;
          goto LAB_000f9c36;
        }
        if (uVar17 < 3) break;
        pbVar6 = (byte *)*param_2;
        iVar12 = iVar12 + 1;
      }
    }
    uVar18 = 0x73d;
    uVar13 = 0x87;
  }
  else {
    if (param_2[1] != 0) {
      cVar4 = *(char *)*param_2;
      *param_2 = (char *)*param_2 + 1;
      param_2[1] = param_2[1] + -1;
      if (cVar4 == '\0') goto LAB_000f9c60;
    }
LAB_000f9c18:
    uVar18 = 0x735;
    uVar13 = 0x9f;
  }
  pXVar16 = (X509 *)0x0;
  ossl_statem_fatal(param_1,0x32,0x16f,uVar13,"ssl/statem/statem_clnt.c",uVar18);
  a = (X509 *)0x0;
LAB_000f9c36:
  X509_free(a);
  OPENSSL_sk_pop_free(pXVar5,(undefined *)0x178169);
  return pXVar16;
}

