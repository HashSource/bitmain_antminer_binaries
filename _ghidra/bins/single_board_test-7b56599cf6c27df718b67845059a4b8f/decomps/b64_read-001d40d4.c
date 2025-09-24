
size_t b64_read(BIO *param_1,void *param_2,size_t param_3)

{
  uchar *puVar1;
  uchar *puVar2;
  size_t *outl;
  BIO *b;
  uint uVar3;
  uchar *puVar4;
  size_t sVar5;
  uchar *puVar6;
  size_t *psVar7;
  uchar *puVar8;
  size_t sVar9;
  uchar *in;
  int iVar10;
  uchar *puVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  undefined4 uVar16;
  bool bVar17;
  void *local_50;
  size_t local_4c;
  size_t local_34;
  int local_2c [2];
  
  if (param_2 == (void *)0x0) {
    return 0;
  }
  outl = (size_t *)BIO_get_data();
  b = BIO_next(param_1);
  if (b == (BIO *)0x0 || outl == (size_t *)0x0) {
    return 0;
  }
  BIO_clear_flags(param_1,0xf);
  if (outl[4] != 2) {
    *outl = 0;
    outl[1] = 0;
    outl[2] = 0;
    outl[4] = 2;
    EVP_DecodeInit((EVP_ENCODE_CTX *)outl[7]);
  }
  sVar5 = *outl;
  if ((int)sVar5 < 1) {
    if (((int)param_3 < 1) || ((int)outl[6] < 1)) {
      BIO_copy_next_retry(param_1);
      return 0;
    }
    local_4c = 0;
    local_50 = param_2;
  }
  else {
    sVar9 = outl[1];
    if ((int)sVar5 < (int)sVar9) {
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: ctx->buf_len >= ctx->buf_off","crypto/evp/bio_b64.c",0x89);
    }
    local_4c = sVar5 - sVar9;
    if ((int)param_3 <= (int)(sVar5 - sVar9)) {
      local_4c = param_3;
    }
    if (0x5dd < (int)(sVar9 + local_4c)) {
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: ctx->buf_off + i < (int)sizeof(ctx->buf)",
                  "crypto/evp/bio_b64.c",0x8d);
    }
    param_3 = param_3 - local_4c;
    local_50 = (void *)((int)param_2 + local_4c);
    memcpy(param_2,(void *)(sVar9 + 0x20 + (int)outl),local_4c);
    sVar5 = outl[1] + local_4c;
    bVar17 = sVar5 == *outl;
    outl[1] = sVar5;
    if (bVar17) {
      sVar5 = 0;
      *outl = 0;
    }
    if (bVar17) {
      outl[1] = sVar5;
    }
    if (((int)param_3 < 1) || ((int)outl[6] < 1)) {
      local_34 = 0;
      goto LAB_001d42a2;
    }
  }
  local_34 = 0;
  in = (uchar *)((int)outl + 0x5fe);
LAB_001d41b0:
  do {
    sVar5 = BIO_read(b,(void *)((int)outl + outl[2] + 0x5fe),0x400 - outl[2]);
    if ((int)sVar5 < 1) {
      iVar10 = BIO_test_flags(b,8);
      local_34 = sVar5;
      if (iVar10 != 0) break;
      sVar9 = outl[2];
      outl[6] = sVar5;
      if (sVar9 == 0) break;
      sVar5 = 0;
    }
    else {
      sVar9 = outl[2];
    }
    uVar14 = sVar9 + sVar5;
    outl[2] = uVar14;
    if (outl[5] == 0) {
LAB_001d41e0:
      if (((int)uVar14 < 0x400) && (0 < (int)outl[6])) goto LAB_001d41b0;
LAB_001d41f0:
      uVar3 = BIO_test_flags(param_1,-1);
      if ((uVar3 & 0x100) == 0) {
        sVar5 = EVP_DecodeUpdate((EVP_ENCODE_CTX *)outl[7],(uchar *)(outl + 8),(int *)outl,in,uVar14
                                );
        outl[2] = 0;
LAB_001d42d6:
        outl[6] = sVar5;
        outl[1] = 0;
        if ((int)sVar5 < 0) {
          *outl = 0;
          local_34 = 0;
          break;
        }
        sVar5 = *outl;
      }
      else {
        uVar3 = uVar14 & 0xfffffffc;
        sVar5 = EVP_DecodeBlock((uchar *)(outl + 8),in,uVar3);
        if ((2 < (int)uVar3) && (*(char *)((int)outl + uVar3 + 0x5fd) == '=')) {
          if (*(char *)((int)outl + uVar3 + 0x5fc) == '=') {
            sVar5 = sVar5 - 2;
          }
          else {
            sVar5 = sVar5 - 1;
          }
        }
        if (uVar14 != uVar3) {
          memmove(in,(void *)((int)outl + uVar3 + 0x5fe),uVar14 - uVar3);
          outl[2] = uVar14 - uVar3;
        }
        if ((int)sVar5 < 1) {
          *outl = 0;
          goto LAB_001d42d6;
        }
        *outl = sVar5;
        outl[6] = sVar5;
      }
      if ((int)param_3 <= (int)sVar5) {
        sVar5 = param_3;
      }
      memcpy(local_50,outl + 8,sVar5);
      sVar9 = *outl;
      param_3 = param_3 - sVar5;
      outl[1] = sVar5;
      bVar17 = sVar9 == sVar5;
      if (bVar17) {
        sVar9 = 0;
      }
      local_4c = local_4c + sVar5;
      if (bVar17) {
        *outl = sVar9;
      }
      if (bVar17) {
        outl[1] = sVar9;
      }
      local_50 = (void *)((int)local_50 + sVar5);
      if ((int)param_3 < 1) break;
    }
    else {
      uVar3 = BIO_test_flags(param_1,-1);
      if ((uVar3 & 0x100) != 0) {
LAB_001d44cc:
        outl[2] = 0;
        goto LAB_001d41f0;
      }
      if (outl[5] == 0) goto LAB_001d41e0;
      local_2c[0] = 0;
      if (0 < (int)uVar14) {
        sVar5 = 0;
        puVar6 = in;
        puVar4 = in;
LAB_001d4330:
        puVar11 = puVar6 + 1;
        if (*puVar6 != '\n') goto joined_r0x001d432e;
        if (outl[3] != 0) {
          outl[3] = 0;
          puVar4 = puVar11;
          goto joined_r0x001d432e;
        }
        iVar10 = EVP_DecodeUpdate((EVP_ENCODE_CTX *)outl[7],(uchar *)(outl + 8),local_2c,puVar4,
                                  (int)puVar11 - (int)puVar4);
        if (((iVar10 < 1) && (local_2c[0] == 0)) && (outl[5] != 0)) {
          EVP_DecodeInit((EVP_ENCODE_CTX *)outl[7]);
          puVar4 = puVar11;
          goto joined_r0x001d432e;
        }
        if ((in != puVar4) && (uVar14 = uVar14 - ((int)puVar4 - (int)in), 0 < (int)uVar14)) {
          if ((((uint)in | (uint)puVar4) & 7) == 0 &&
              (10 < uVar14 && (puVar4 + 8 <= in || (uchar *)((int)outl + 0x606U) <= puVar4))) {
            uVar3 = uVar14 - 8 >> 3;
            uVar12 = uVar3 + 1;
            uVar3 = uVar3 - 4;
            uVar13 = uVar12 * 8;
            if (uVar3 < 0xfffffffb) {
              uVar3 = (uVar3 & 0xfffffffc) + 4;
              uVar15 = 0;
              puVar2 = (uchar *)((int)outl + 0x61e);
              puVar1 = puVar4;
              do {
                puVar8 = puVar2;
                puVar6 = puVar1 + 0x20;
                uVar16 = *(undefined4 *)(puVar1 + 4);
                uVar15 = uVar15 + 4;
                HintPreloadData(puVar1 + 0xb8);
                *(undefined4 *)(puVar8 + -0x20) = *(undefined4 *)puVar1;
                *(undefined4 *)(puVar8 + -0x1c) = uVar16;
                uVar16 = *(undefined4 *)(puVar1 + 0xc);
                *(undefined4 *)(puVar8 + -0x18) = *(undefined4 *)(puVar1 + 8);
                *(undefined4 *)(puVar8 + -0x14) = uVar16;
                uVar16 = *(undefined4 *)(puVar1 + 0x14);
                *(undefined4 *)(puVar8 + -0x10) = *(undefined4 *)(puVar1 + 0x10);
                *(undefined4 *)(puVar8 + -0xc) = uVar16;
                uVar16 = *(undefined4 *)(puVar1 + 0x1c);
                *(undefined4 *)(puVar8 + -8) = *(undefined4 *)(puVar1 + 0x18);
                *(undefined4 *)(puVar8 + -4) = uVar16;
                puVar2 = puVar8 + 0x20;
                puVar1 = puVar6;
              } while (uVar3 != uVar15);
            }
            else {
              uVar3 = 0;
              puVar6 = puVar4;
              puVar8 = in;
            }
            puVar6 = puVar6 + -8;
            do {
              uVar16 = *(undefined4 *)(puVar6 + 0xc);
              uVar3 = uVar3 + 1;
              *(undefined4 *)puVar8 = *(undefined4 *)(puVar6 + 8);
              *(undefined4 *)(puVar8 + 4) = uVar16;
              puVar6 = puVar6 + 8;
              puVar8 = puVar8 + 8;
            } while (uVar3 < uVar12);
            if (uVar14 != uVar13) {
              *(uchar *)((int)outl + uVar13 + 0x5fe) = puVar4[uVar12 * 8];
              if ((int)(uVar13 + 1) < (int)uVar14) {
                *(uchar *)((int)outl + uVar13 + 0x5ff) = puVar4[uVar13 + 1];
                if ((int)(uVar13 + 2) < (int)uVar14) {
                  *(uchar *)(outl + uVar12 * 2 + 0x180) = puVar4[uVar13 + 2];
                  if ((int)(uVar13 + 3) < (int)uVar14) {
                    *(uchar *)((int)outl + uVar13 + 0x601) = puVar4[uVar13 + 3];
                    if ((int)(uVar13 + 4) < (int)uVar14) {
                      *(uchar *)((int)outl + uVar13 + 0x602) = puVar4[uVar13 + 4];
                      if ((int)(uVar13 + 5) < (int)uVar14) {
                        *(uchar *)((int)outl + uVar13 + 0x603) = puVar4[uVar13 + 5];
                        if ((int)(uVar13 + 6) < (int)uVar14) {
                          *(uchar *)(outl + uVar12 * 2 + 0x181) = puVar4[uVar13 + 6];
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else {
            iVar10 = 0;
            if (0x20 < (int)uVar14) {
              iVar10 = 0;
              puVar6 = puVar4 + 0x22;
              psVar7 = outl + 0x188;
              do {
                iVar10 = iVar10 + 0x20;
                HintPreloadData(puVar6);
                HintPreloadData(psVar7);
                *(uchar *)((int)psVar7 + -0x22) = puVar6[-0x22];
                *(uchar *)((int)psVar7 + -0x21) = puVar6[-0x21];
                *(uchar *)(psVar7 + -8) = puVar6[-0x20];
                *(uchar *)((int)psVar7 + -0x1f) = puVar6[-0x1f];
                *(uchar *)((int)psVar7 + -0x1e) = puVar6[-0x1e];
                *(uchar *)((int)psVar7 + -0x1d) = puVar6[-0x1d];
                *(uchar *)(psVar7 + -7) = puVar6[-0x1c];
                *(uchar *)((int)psVar7 + -0x1b) = puVar6[-0x1b];
                *(uchar *)((int)psVar7 + -0x1a) = puVar6[-0x1a];
                *(uchar *)((int)psVar7 + -0x19) = puVar6[-0x19];
                *(uchar *)(psVar7 + -6) = puVar6[-0x18];
                *(uchar *)((int)psVar7 + -0x17) = puVar6[-0x17];
                *(uchar *)((int)psVar7 + -0x16) = puVar6[-0x16];
                *(uchar *)((int)psVar7 + -0x15) = puVar6[-0x15];
                *(uchar *)(psVar7 + -5) = puVar6[-0x14];
                *(uchar *)((int)psVar7 + -0x13) = puVar6[-0x13];
                *(uchar *)((int)psVar7 + -0x12) = puVar6[-0x12];
                *(uchar *)((int)psVar7 + -0x11) = puVar6[-0x11];
                *(uchar *)(psVar7 + -4) = puVar6[-0x10];
                *(uchar *)((int)psVar7 + -0xf) = puVar6[-0xf];
                *(uchar *)((int)psVar7 + -0xe) = puVar6[-0xe];
                *(uchar *)((int)psVar7 + -0xd) = puVar6[-0xd];
                *(uchar *)(psVar7 + -3) = puVar6[-0xc];
                *(uchar *)((int)psVar7 + -0xb) = puVar6[-0xb];
                *(uchar *)((int)psVar7 + -10) = puVar6[-10];
                *(uchar *)((int)psVar7 + -9) = puVar6[-9];
                *(uchar *)(psVar7 + -2) = puVar6[-8];
                *(uchar *)((int)psVar7 + -7) = puVar6[-7];
                *(uchar *)((int)psVar7 + -6) = puVar6[-6];
                *(uchar *)((int)psVar7 + -5) = puVar6[-5];
                *(uchar *)(psVar7 + -1) = puVar6[-4];
                *(uchar *)((int)psVar7 + -3) = puVar6[-3];
                puVar6 = puVar6 + 0x20;
                psVar7 = psVar7 + 8;
              } while (iVar10 != (uVar14 - 0x21 & 0xffffffe0) + 0x20);
            }
            puVar6 = puVar4 + iVar10 + -1;
            puVar8 = (uchar *)(iVar10 + 0x5fd + (int)outl);
            do {
              puVar6 = puVar6 + 1;
              iVar10 = iVar10 + 1;
              puVar8 = puVar8 + 1;
              *puVar8 = *puVar6;
            } while (iVar10 < (int)uVar14);
          }
        }
        EVP_DecodeInit((EVP_ENCODE_CTX *)outl[7]);
        outl[5] = 0;
LAB_001d4350:
        if ((uVar14 != sVar5) || (local_2c[0] != 0)) goto LAB_001d44cc;
        if (in == puVar4) {
          if (uVar14 == 0x400) {
            outl[2] = 0;
            outl[3] = 1;
          }
        }
        else if (puVar11 != puVar4) {
          uVar14 = (int)puVar11 - (int)puVar4;
          if (0 < (int)uVar14) {
            if ((((uint)in | (uint)puVar4) & 7) == 0 &&
                (10 < uVar14 && (puVar4 + 8 <= in || (uchar *)((int)outl + 0x606) <= puVar4))) {
              uVar3 = uVar14 - 8 >> 3;
              uVar12 = uVar3 + 1;
              uVar3 = uVar3 - 4;
              uVar13 = uVar12 * 8;
              if (uVar3 < 0xfffffffb) {
                uVar3 = (uVar3 & 0xfffffffc) + 4;
                uVar15 = 0;
                puVar1 = (uchar *)((int)outl + 0x61e);
                puVar8 = puVar4;
                do {
                  puVar11 = puVar1;
                  puVar6 = puVar8 + 0x20;
                  uVar16 = *(undefined4 *)(puVar8 + 4);
                  uVar15 = uVar15 + 4;
                  HintPreloadData(puVar8 + 0xb8);
                  *(undefined4 *)(puVar11 + -0x20) = *(undefined4 *)puVar8;
                  *(undefined4 *)(puVar11 + -0x1c) = uVar16;
                  uVar16 = *(undefined4 *)(puVar8 + 0xc);
                  *(undefined4 *)(puVar11 + -0x18) = *(undefined4 *)(puVar8 + 8);
                  *(undefined4 *)(puVar11 + -0x14) = uVar16;
                  uVar16 = *(undefined4 *)(puVar8 + 0x14);
                  *(undefined4 *)(puVar11 + -0x10) = *(undefined4 *)(puVar8 + 0x10);
                  *(undefined4 *)(puVar11 + -0xc) = uVar16;
                  uVar16 = *(undefined4 *)(puVar8 + 0x1c);
                  *(undefined4 *)(puVar11 + -8) = *(undefined4 *)(puVar8 + 0x18);
                  *(undefined4 *)(puVar11 + -4) = uVar16;
                  puVar1 = puVar11 + 0x20;
                  puVar8 = puVar6;
                } while (uVar3 != uVar15);
              }
              else {
                uVar3 = 0;
                puVar6 = puVar4;
                puVar11 = in;
              }
              puVar6 = puVar6 + -8;
              do {
                uVar16 = *(undefined4 *)(puVar6 + 0xc);
                uVar3 = uVar3 + 1;
                *(undefined4 *)puVar11 = *(undefined4 *)(puVar6 + 8);
                *(undefined4 *)(puVar11 + 4) = uVar16;
                puVar6 = puVar6 + 8;
                puVar11 = puVar11 + 8;
              } while (uVar3 < uVar12);
              if (uVar14 != uVar13) {
                *(uchar *)((int)outl + uVar13 + 0x5fe) = puVar4[uVar12 * 8];
                if ((int)(uVar13 + 1) < (int)uVar14) {
                  *(uchar *)((int)outl + uVar13 + 0x5ff) = puVar4[uVar13 + 1];
                  if ((int)(uVar13 + 2) < (int)uVar14) {
                    *(uchar *)(outl + uVar12 * 2 + 0x180) = puVar4[uVar13 + 2];
                    if ((int)(uVar13 + 3) < (int)uVar14) {
                      *(uchar *)((int)outl + uVar13 + 0x601) = puVar4[uVar13 + 3];
                      if ((int)(uVar13 + 4) < (int)uVar14) {
                        *(uchar *)((int)outl + uVar13 + 0x602) = puVar4[uVar13 + 4];
                        if ((int)(uVar13 + 5) < (int)uVar14) {
                          *(uchar *)((int)outl + uVar13 + 0x603) = puVar4[uVar13 + 5];
                          if ((int)(uVar13 + 6) < (int)uVar14) {
                            *(uchar *)(outl + uVar12 * 2 + 0x181) = puVar4[uVar13 + 6];
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else {
              iVar10 = 0;
              if (0x20 < (int)uVar14) {
                iVar10 = 0;
                puVar6 = puVar4 + 0x22;
                psVar7 = outl + 0x188;
                do {
                  iVar10 = iVar10 + 0x20;
                  HintPreloadData(puVar6);
                  HintPreloadData(psVar7);
                  *(uchar *)((int)psVar7 + -0x22) = puVar6[-0x22];
                  *(uchar *)((int)psVar7 + -0x21) = puVar6[-0x21];
                  *(uchar *)(psVar7 + -8) = puVar6[-0x20];
                  *(uchar *)((int)psVar7 + -0x1f) = puVar6[-0x1f];
                  *(uchar *)((int)psVar7 + -0x1e) = puVar6[-0x1e];
                  *(uchar *)((int)psVar7 + -0x1d) = puVar6[-0x1d];
                  *(uchar *)(psVar7 + -7) = puVar6[-0x1c];
                  *(uchar *)((int)psVar7 + -0x1b) = puVar6[-0x1b];
                  *(uchar *)((int)psVar7 + -0x1a) = puVar6[-0x1a];
                  *(uchar *)((int)psVar7 + -0x19) = puVar6[-0x19];
                  *(uchar *)(psVar7 + -6) = puVar6[-0x18];
                  *(uchar *)((int)psVar7 + -0x17) = puVar6[-0x17];
                  *(uchar *)((int)psVar7 + -0x16) = puVar6[-0x16];
                  *(uchar *)((int)psVar7 + -0x15) = puVar6[-0x15];
                  *(uchar *)(psVar7 + -5) = puVar6[-0x14];
                  *(uchar *)((int)psVar7 + -0x13) = puVar6[-0x13];
                  *(uchar *)((int)psVar7 + -0x12) = puVar6[-0x12];
                  *(uchar *)((int)psVar7 + -0x11) = puVar6[-0x11];
                  *(uchar *)(psVar7 + -4) = puVar6[-0x10];
                  *(uchar *)((int)psVar7 + -0xf) = puVar6[-0xf];
                  *(uchar *)((int)psVar7 + -0xe) = puVar6[-0xe];
                  *(uchar *)((int)psVar7 + -0xd) = puVar6[-0xd];
                  *(uchar *)(psVar7 + -3) = puVar6[-0xc];
                  *(uchar *)((int)psVar7 + -0xb) = puVar6[-0xb];
                  *(uchar *)((int)psVar7 + -10) = puVar6[-10];
                  *(uchar *)((int)psVar7 + -9) = puVar6[-9];
                  *(uchar *)(psVar7 + -2) = puVar6[-8];
                  *(uchar *)((int)psVar7 + -7) = puVar6[-7];
                  *(uchar *)((int)psVar7 + -6) = puVar6[-6];
                  *(uchar *)((int)psVar7 + -5) = puVar6[-5];
                  *(uchar *)(psVar7 + -1) = puVar6[-4];
                  *(uchar *)((int)psVar7 + -3) = puVar6[-3];
                  puVar6 = puVar6 + 0x20;
                  psVar7 = psVar7 + 8;
                } while (iVar10 != (uVar14 - 0x21 & 0xffffffe0) + 0x20);
              }
              puVar4 = puVar4 + iVar10 + -1;
              puVar6 = (uchar *)(iVar10 + 0x5fd + (int)outl);
              do {
                puVar4 = puVar4 + 1;
                iVar10 = iVar10 + 1;
                puVar6 = puVar6 + 1;
                *puVar6 = *puVar4;
              } while (iVar10 < (int)uVar14);
            }
          }
          outl[2] = uVar14;
        }
        goto LAB_001d429a;
      }
      if (uVar14 != 0) goto LAB_001d44cc;
    }
LAB_001d429a:
  } while (0 < (int)outl[6]);
LAB_001d42a2:
  BIO_copy_next_retry(param_1);
  if (local_4c == 0) {
    local_4c = local_34;
  }
  return local_4c;
joined_r0x001d432e:
  sVar5 = sVar5 + 1;
  bVar17 = puVar11 == in + uVar14;
  puVar6 = puVar11;
  puVar11 = in + uVar14;
  if (bVar17) goto LAB_001d4350;
  goto LAB_001d4330;
}

