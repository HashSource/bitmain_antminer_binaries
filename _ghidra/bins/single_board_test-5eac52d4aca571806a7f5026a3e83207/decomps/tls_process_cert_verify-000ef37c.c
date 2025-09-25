
uchar * tls_process_cert_verify(int *param_1,int *param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  EVP_MD_CTX *ctx;
  EVP_PKEY *pkey;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  uchar *out;
  uchar *puVar10;
  bool bVar11;
  undefined4 uVar12;
  EVP_MD *local_d4;
  size_t local_d0;
  void *local_cc;
  EVP_PKEY_CTX *local_c8;
  undefined1 auStack_c4 [164];
  
  local_d4 = (EVP_MD *)0x0;
  local_d0 = 0;
  ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
  local_c8 = (EVP_PKEY_CTX *)0x0;
  if (ctx == (EVP_MD_CTX *)0x0) {
    ossl_statem_fatal(param_1,0x50,0x17b,0x41,"ssl/statem/statem_lib.c",0x16d);
    iVar3 = param_1[0x1f];
    puVar10 = (uchar *)0x0;
    out = (uchar *)0x0;
    goto LAB_000ef49e;
  }
  pkey = (EVP_PKEY *)X509_get0_pubkey(*(undefined4 *)(param_1[0x11d] + 0x19c));
  if (pkey == (EVP_PKEY *)0x0) {
    uVar7 = 0x175;
    goto LAB_000ef5b8;
  }
  iVar3 = ssl_cert_lookup_by_pkey(pkey,0);
  if (iVar3 == 0) {
    ossl_statem_fatal(param_1,0x2f,0x17b,0xdc,"ssl/statem/statem_lib.c",0x17b);
    iVar3 = param_1[0x1f];
    puVar10 = (uchar *)0x0;
    out = (uchar *)0x0;
    goto LAB_000ef49e;
  }
  if (*(int *)(*(int *)(param_1[1] + 100) + 0x30) << 0x1e < 0) {
    if (1 < (uint)param_2[1]) {
      puVar4 = (undefined1 *)*param_2;
      uVar1 = *puVar4;
      uVar2 = puVar4[1];
      *param_2 = (int)(puVar4 + 2);
      param_2[1] = param_2[1] - 2;
      iVar3 = tls12_check_peer_sigalg(param_1,CONCAT11(uVar1,uVar2),pkey);
      if (0 < iVar3) goto LAB_000ef3d2;
LAB_000ef474:
      puVar10 = (uchar *)0x0;
      iVar3 = param_1[0x1f];
      out = (uchar *)0x0;
      goto LAB_000ef49e;
    }
    uVar12 = 0x184;
    uVar7 = 0xf0;
LAB_000ef56a:
    puVar10 = (uchar *)0x0;
    ossl_statem_fatal(param_1,0x32,0x17b,uVar7,"ssl/statem/statem_lib.c",uVar12);
    iVar3 = param_1[0x1f];
    out = puVar10;
    goto LAB_000ef49e;
  }
  iVar3 = tls1_set_peer_legacy_sigalg(param_1,pkey);
  if (iVar3 == 0) {
    uVar7 = 0x18d;
LAB_000ef5b8:
    uVar12 = 0x44;
  }
  else {
LAB_000ef3d2:
    iVar3 = tls1_lookup_md(*(undefined4 *)(param_1[0x1f] + 0x278),&local_d4);
    if (iVar3 == 0) {
      uVar7 = 0x193;
      goto LAB_000ef5b8;
    }
    uVar5 = param_2[1];
    if ((*(uint *)(*(int *)(param_1[1] + 100) + 0x30) & 2) != 0) {
LAB_000ef3fe:
      if (1 < uVar5) {
        puVar4 = (undefined1 *)*param_2;
        uVar1 = *puVar4;
        uVar2 = puVar4[1];
        *param_2 = (int)(puVar4 + 2);
        param_2[1] = uVar5 - 2;
        uVar5 = (uint)CONCAT11(uVar1,uVar2);
        goto LAB_000ef418;
      }
      uVar12 = 0x1ae;
      uVar7 = 0x9f;
LAB_000ef48a:
      ossl_statem_fatal(param_1,0x32,0x17b,uVar7,"ssl/statem/statem_lib.c",uVar12);
      iVar3 = param_1[0x1f];
      puVar10 = (uchar *)0x0;
      out = (uchar *)0x0;
      goto LAB_000ef49e;
    }
    if (uVar5 != 0x40) {
LAB_000ef3f8:
      if (uVar5 == 0x80) {
        iVar3 = EVP_PKEY_id(pkey);
        if (iVar3 == 0x3d4) goto LAB_000ef634;
        uVar5 = param_2[1];
      }
      goto LAB_000ef3fe;
    }
    iVar3 = EVP_PKEY_id(pkey);
    if ((iVar3 != 0x32b) && (iVar3 = EVP_PKEY_id(pkey), iVar3 != 0x3d3)) {
      uVar5 = param_2[1];
      goto LAB_000ef3f8;
    }
LAB_000ef634:
    uVar5 = param_2[1];
LAB_000ef418:
    iVar3 = EVP_PKEY_size(pkey);
    if ((iVar3 < (int)uVar5) || (uVar6 = param_2[1], uVar6 == 0 || iVar3 < (int)uVar6)) {
      uVar12 = 0x1b6;
      uVar7 = 0x109;
      goto LAB_000ef48a;
    }
    if (uVar6 < uVar5) {
      uVar12 = 0x1bb;
      uVar7 = 0x9f;
      goto LAB_000ef56a;
    }
    puVar10 = (uchar *)*param_2;
    param_2[1] = uVar6 - uVar5;
    *param_2 = (int)(puVar10 + uVar5);
    iVar3 = get_cert_verify_tbs_data(param_1,auStack_c4,&local_cc,&local_d0);
    if (iVar3 == 0) goto LAB_000ef474;
    iVar3 = EVP_DigestVerifyInit(ctx,&local_c8,local_d4,(ENGINE *)0x0,pkey);
    if (0 < iVar3) {
      uVar6 = EVP_PKEY_id(pkey);
      bVar11 = 0x32a < uVar6;
      if (uVar6 != 0x32b) {
        bVar11 = uVar6 != 0x3d3;
      }
      if (bVar11 && (uVar6 != 0x32b && uVar6 != 0x3d4)) {
        out = (uchar *)0x0;
      }
      else {
        out = (uchar *)CRYPTO_malloc(uVar5,"ssl/statem/statem_lib.c",0x1d3);
        if (out == (uchar *)0x0) {
          ossl_statem_fatal(param_1,0x50,0x17b,0x41,"ssl/statem/statem_lib.c",0x1d5);
          iVar3 = param_1[0x1f];
          puVar10 = (uchar *)0x0;
          goto LAB_000ef49e;
        }
        BUF_reverse(out,puVar10,uVar5);
        puVar10 = out;
      }
      if (((*(int *)(param_1[0x1f] + 0x278) == 0) ||
          (*(int *)(*(int *)(param_1[0x1f] + 0x278) + 0x10) != 0x390)) ||
         ((iVar3 = RSA_pkey_ctx_ctrl(local_c8,0xffffffff,0x1001,6,0), 0 < iVar3 &&
          (iVar3 = RSA_pkey_ctx_ctrl(local_c8,0x18,0x1002,0xffffffff,0), 0 < iVar3)))) {
        if (*param_1 == 0x300) {
          iVar3 = EVP_DigestUpdate(ctx,local_cc,local_d0);
          if ((iVar3 < 1) ||
             (iVar3 = EVP_MD_CTX_ctrl(ctx,0x1d,*(undefined4 *)(param_1[0x11d] + 4),
                                      param_1[0x11d] + 0x48), iVar3 == 0)) {
            uVar9 = 0x1ed;
            uVar12 = 6;
            uVar7 = 0x50;
            goto LAB_000ef694;
          }
          iVar3 = EVP_DigestVerifyFinal(ctx,puVar10,uVar5);
          if (0 < iVar3) goto LAB_000ef550;
          uVar9 = 0x1f2;
        }
        else {
          iVar3 = EVP_DigestVerify(ctx,puVar10,uVar5,local_cc,local_d0);
          if (0 < iVar3) {
LAB_000ef550:
            if ((param_1[7] == 0) && (-1 < *(int *)(((int *)param_1[1])[0x19] + 0x30) << 0x1c)) {
              iVar8 = *(int *)param_1[1];
              iVar3 = param_1[0x1f];
              if (iVar8 == 0x10000 || iVar8 < 0x304) {
                puVar10 = (uchar *)0x3;
              }
              else if (*(int *)(iVar3 + 0x218) == 1) {
                puVar10 = (uchar *)0x2;
              }
              else {
                puVar10 = (uchar *)0x3;
              }
            }
            else {
              puVar10 = (uchar *)0x3;
              iVar3 = param_1[0x1f];
            }
            goto LAB_000ef49e;
          }
          uVar9 = 0x1f9;
        }
        uVar12 = 0x7b;
        uVar7 = 0x33;
      }
      else {
        uVar9 = 0x1e3;
        uVar12 = 6;
        uVar7 = 0x50;
      }
LAB_000ef694:
      ossl_statem_fatal(param_1,uVar7,0x17b,uVar12,"ssl/statem/statem_lib.c",uVar9);
      puVar10 = (uchar *)0x0;
      iVar3 = param_1[0x1f];
      goto LAB_000ef49e;
    }
    uVar7 = 0x1ca;
    uVar12 = 6;
  }
  puVar10 = (uchar *)0x0;
  ossl_statem_fatal(param_1,0x50,0x17b,uVar12,"ssl/statem/statem_lib.c",uVar7);
  iVar3 = param_1[0x1f];
  out = puVar10;
LAB_000ef49e:
  BIO_free(*(BIO **)(iVar3 + 0xd4));
  *(undefined4 *)(param_1[0x1f] + 0xd4) = 0;
  EVP_MD_CTX_free(ctx);
  CRYPTO_free(out);
  return puVar10;
}

