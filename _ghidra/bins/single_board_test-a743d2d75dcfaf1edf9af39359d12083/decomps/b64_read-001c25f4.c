
size_t b64_read(BIO *param_1,void *param_2,size_t param_3)

{
  BIO *pBVar1;
  BIO *pBVar2;
  uint uVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined1 *puVar6;
  BIO *pBVar7;
  BIO *pBVar8;
  undefined1 *puVar9;
  size_t sVar10;
  _func_745 *p_Var11;
  uint extraout_r3;
  undefined1 *puVar12;
  undefined1 *puVar13;
  uint extraout_r3_00;
  CRYPTO_EX_DATA *pCVar14;
  size_t sVar15;
  undefined1 *puVar16;
  EVP_ENCODE_CTX *ctx;
  undefined1 *puVar17;
  BIO *in;
  BIO *out;
  BIO *pBVar18;
  BIO *pBVar19;
  bio_st *pbVar20;
  int iVar21;
  ulong uVar22;
  size_t *outl;
  uint uVar23;
  int iVar24;
  undefined1 *puVar25;
  undefined1 *puVar26;
  bool bVar27;
  uchar *local_54;
  void *local_4c;
  size_t local_44;
  size_t local_3c;
  undefined1 *local_2c [2];
  
  if (param_2 == (void *)0x0) {
    local_44 = 0;
  }
  else {
    outl = (size_t *)param_1->ptr;
    if (outl == (size_t *)0x0) {
      local_44 = 0;
    }
    else if (param_1->next_bio == (bio_st *)0x0) {
      local_44 = 0;
    }
    else {
      BIO_clear_flags(param_1,0xf);
      if (outl[4] != 2) {
        outl[4] = 2;
        *outl = 0;
        outl[1] = 0;
        outl[2] = 0;
        EVP_DecodeInit((EVP_ENCODE_CTX *)(outl + 7));
      }
      local_44 = *outl;
      if ((int)local_44 < 1) {
        local_44 = 0;
        local_4c = param_2;
      }
      else {
        sVar10 = outl[1];
        if ((int)local_44 < (int)sVar10) {
          OpenSSLDie("bio_b64.c",0xad,"ctx->buf_len >= ctx->buf_off");
          local_44 = *outl;
          sVar10 = outl[1];
        }
        local_44 = local_44 - sVar10;
        if ((int)param_3 <= (int)local_44) {
          local_44 = param_3;
        }
        if (0x5dd < (int)(local_44 + sVar10)) {
          OpenSSLDie("bio_b64.c",0xb1,"ctx->buf_off + i < (int)sizeof(ctx->buf)");
          sVar10 = outl[1];
        }
        memcpy(param_2,(void *)((int)outl + sVar10 + 0x7c),local_44);
        sVar10 = outl[1];
        param_3 = param_3 - local_44;
        outl[1] = local_44 + sVar10;
        local_4c = (void *)((int)param_2 + local_44);
        if (local_44 + sVar10 == *outl) {
          *outl = 0;
          outl[1] = 0;
        }
      }
      if ((int)param_3 < 1) {
        local_3c = 0;
      }
      else {
        local_3c = 0;
        if (0 < (int)outl[6]) {
          ctx = (EVP_ENCODE_CTX *)(outl + 7);
          out = (BIO *)(outl + 0x1f);
          pBVar18 = out;
          do {
            sVar10 = BIO_read(param_1->next_bio,(void *)((int)outl + outl[2] + 0x65a),
                              0x400 - outl[2]);
            if ((int)sVar10 < 1) {
              iVar21 = BIO_test_flags(param_1->next_bio,8);
              local_3c = sVar10;
              if (iVar21 != 0) break;
              sVar15 = outl[2];
              outl[6] = sVar10;
              if (sVar15 == 0) break;
              sVar10 = 0;
              pBVar18 = param_1;
            }
            else {
              sVar15 = outl[2];
            }
            puVar16 = (undefined1 *)(sVar10 + sVar15);
            outl[2] = (size_t)puVar16;
            if (outl[5] == 0) {
LAB_001c270a:
              if (0x3ff < (int)puVar16) goto LAB_001c271a;
              if ((int)outl[6] < 1) {
                pBVar18 = (BIO *)((int)outl + 0x65a);
                goto LAB_001c271a;
              }
            }
            else {
              uVar3 = BIO_test_flags(param_1,-1);
              if ((uVar3 & 0x100) == 0) {
                uVar3 = outl[5];
                if (uVar3 == 0) goto LAB_001c270a;
                pBVar19 = (BIO *)((int)outl + 0x65a);
                puVar17 = (undefined1 *)0x0;
                in = pBVar19;
                pBVar18 = pBVar19;
                pBVar8 = pBVar19;
                local_2c[0] = puVar17;
                if (0 < (int)puVar16) {
LAB_001c2840:
                  do {
                    pBVar18 = (BIO *)((int)&pBVar8->method + 1);
                    uVar3 = (uint)*(byte *)&pBVar8->method;
                    pBVar8 = pBVar18;
                    if (uVar3 != 10) goto LAB_001c283a;
                    uVar3 = outl[3];
                    if (uVar3 == 0) {
                      iVar21 = EVP_DecodeUpdate(ctx,(uchar *)out,(int *)local_2c,(uchar *)in,
                                                (int)pBVar18 - (int)in);
                      if (((iVar21 < 1) && (local_2c[0] == (undefined1 *)0x0)) && (outl[5] != 0)) {
                        EVP_DecodeInit(ctx);
                        uVar3 = extraout_r3;
                        in = pBVar18;
                        goto LAB_001c283a;
                      }
                      if ((pBVar19 == in) ||
                         (puVar16 = (undefined1 *)((int)pBVar19 + ((int)puVar16 - (int)in)),
                         (int)puVar16 < 1)) goto LAB_001c2cb0;
                      uVar3 = (uint)puVar16 >> 3;
                      puVar12 = (undefined1 *)(uVar3 << 3);
                      if (uVar3 != 0 &&
                          ((((uint)in | (uint)pBVar19) & 7) == 0 &&
                          (&DAT_00000007 < puVar16 &&
                          ((BIO *)((int)outl + 0x662) <= in || &in->cb_arg <= pBVar19)))) {
                        if (uVar3 < 5) {
                          uVar5 = 0;
                          pBVar8 = pBVar19;
                          pBVar7 = in;
                        }
                        else {
                          uVar5 = 0;
                          pBVar1 = (BIO *)((int)outl + 0x67a);
                          pBVar2 = in;
                          do {
                            pBVar8 = pBVar1;
                            pBVar7 = (BIO *)&pBVar2->ptr;
                            pbVar20 = (bio_st *)pBVar2->callback;
                            uVar23 = uVar5 + 5;
                            uVar5 = uVar5 + 4;
                            HintPreloadData(&pBVar2[2].ex_data);
                            pBVar8[-1].ptr = pBVar2->method;
                            pBVar8[-1].next_bio = pbVar20;
                            iVar21 = pBVar2->init;
                            pBVar8[-1].prev_bio = (bio_st *)pBVar2->cb_arg;
                            pBVar8[-1].references = iVar21;
                            uVar22 = pBVar2->flags;
                            pBVar8[-1].num_read = pBVar2->shutdown;
                            pBVar8[-1].num_write = uVar22;
                            iVar21 = pBVar2->num;
                            pBVar8[-1].ex_data.sk = (stack_st_void *)pBVar2->retry_reason;
                            pBVar8[-1].ex_data.dummy = iVar21;
                            pBVar1 = (BIO *)&pBVar8->ptr;
                            pBVar2 = pBVar7;
                          } while (uVar23 < uVar3 - 3);
                        }
                        pCVar14 = &pBVar7[-1].ex_data;
                        do {
                          p_Var11 = *(_func_745 **)((int)(pCVar14 + 1) + 4);
                          uVar5 = uVar5 + 1;
                          pBVar8->method = (BIO_METHOD *)pCVar14[1].sk;
                          pBVar8->callback = p_Var11;
                          pBVar8 = (BIO *)&pBVar8->cb_arg;
                          pCVar14 = pCVar14 + 1;
                        } while (uVar5 < uVar3);
                        if (puVar16 != puVar12) {
LAB_001c2b46:
                          puVar13 = puVar12 + 1;
                          if ((int)puVar12 < (int)puVar16 &&
                              (int)(puVar12 + 1) < (int)(puVar16 + -0x1f)) {
                            puVar4 = (undefined1 *)((int)&in->method + (int)puVar12);
                            puVar6 = (undefined1 *)((int)outl + (int)(puVar12 + 0x65a));
                            puVar9 = puVar12;
                            puVar25 = puVar12 + 0x658;
                            do {
                              HintPreloadData((undefined1 *)((int)&in->ptr + (int)(puVar9 + 2)));
                              puVar12 = puVar9 + 0x20;
                              puVar26 = puVar9 + 0x678;
                              *(undefined1 *)((int)outl + (int)(puVar9 + 0x65a)) =
                                   *(undefined1 *)((int)&in->method + (int)puVar9);
                              puVar13 = puVar9 + 0x21;
                              HintPreloadData((undefined1 *)((int)outl + (int)(puVar25 + 0x24)));
                              puVar6[1] = puVar4[1];
                              puVar6[2] = puVar4[2];
                              puVar6[3] = puVar4[3];
                              puVar6[4] = puVar4[4];
                              puVar6[5] = puVar4[5];
                              puVar6[6] = puVar4[6];
                              puVar6[7] = puVar4[7];
                              puVar6[8] = puVar4[8];
                              puVar6[9] = puVar4[9];
                              puVar6[10] = puVar4[10];
                              puVar6[0xb] = puVar4[0xb];
                              puVar6[0xc] = puVar4[0xc];
                              puVar6[0xd] = puVar4[0xd];
                              puVar6[0xe] = puVar4[0xe];
                              puVar6[0xf] = puVar4[0xf];
                              puVar6[0x10] = puVar4[0x10];
                              puVar6[0x11] = puVar4[0x11];
                              puVar6[0x12] = puVar4[0x12];
                              puVar6[0x13] = puVar4[0x13];
                              puVar6[0x14] = puVar4[0x14];
                              puVar6[0x15] = puVar4[0x15];
                              puVar6[0x16] = puVar4[0x16];
                              puVar6[0x17] = puVar4[0x17];
                              puVar6[0x18] = puVar4[0x18];
                              puVar6[0x19] = puVar4[0x19];
                              puVar6[0x1a] = puVar4[0x1a];
                              puVar6[0x1b] = puVar4[0x1b];
                              puVar6[0x1c] = puVar4[0x1c];
                              puVar6[0x1d] = puVar4[0x1d];
                              puVar6[0x1e] = puVar4[0x1e];
                              puVar9 = puVar4 + 0x1f;
                              puVar4 = puVar4 + 0x20;
                              puVar6[0x1f] = *puVar9;
                              puVar6 = puVar6 + 0x20;
                              puVar9 = puVar12;
                              puVar25 = puVar26;
                            } while ((int)puVar13 < (int)(puVar16 + -0x1f));
                          }
                          do {
                            *(undefined1 *)((int)outl + (int)(puVar12 + 0x65a)) =
                                 *(undefined1 *)((int)&in->method + (int)puVar12);
                            bVar27 = (int)puVar13 < (int)puVar16;
                            puVar12 = puVar13;
                            puVar13 = puVar13 + 1;
                          } while (bVar27);
                        }
LAB_001c2cb0:
                        EVP_DecodeInit(ctx);
                        outl[5] = 0;
                        uVar3 = extraout_r3_00;
                        goto LAB_001c2cbc;
                      }
                      puVar12 = (undefined1 *)0x0;
                      goto LAB_001c2b46;
                    }
                    puVar17 = puVar17 + 1;
                    outl[3] = 0;
                    in = pBVar18;
                  } while (puVar17 != puVar16);
                  goto LAB_001c2862;
                }
LAB_001c2cbc:
                if (puVar17 == puVar16) {
LAB_001c2862:
                  if (local_2c[0] == (undefined1 *)0x0) {
                    if (in == pBVar19) {
                      bVar27 = puVar17 == (undefined1 *)0x400;
                      if (bVar27) {
                        uVar3 = 1;
                      }
                      if (bVar27) {
                        outl[2] = 0;
                      }
                      if (bVar27) {
                        outl[3] = uVar3;
                      }
                    }
                    else if (in != pBVar18) {
                      pBVar18 = (BIO *)((int)pBVar18 - (int)in);
                      if (0 < (int)pBVar18) {
                        uVar3 = (uint)pBVar18 >> 3;
                        pBVar8 = (BIO *)0x0;
                        if (uVar3 != 0 &&
                            ((((uint)in | (uint)pBVar19) & 7) == 0 &&
                            ((BIO *)&DAT_00000007 < pBVar18 &&
                            ((BIO *)((int)outl + 0x662) <= in || &in->cb_arg <= pBVar19)))) {
                          if (uVar3 < 5) {
                            uVar5 = 0;
                            pBVar8 = in;
                          }
                          else {
                            uVar5 = 0;
                            pBVar2 = (BIO *)((int)outl + 0x67a);
                            pBVar7 = in;
                            do {
                              pBVar19 = pBVar2;
                              pBVar8 = (BIO *)&pBVar7->ptr;
                              pbVar20 = (bio_st *)pBVar7->callback;
                              uVar23 = uVar5 + 5;
                              uVar5 = uVar5 + 4;
                              HintPreloadData(&pBVar7[2].ex_data);
                              pBVar19[-1].ptr = pBVar7->method;
                              pBVar19[-1].next_bio = pbVar20;
                              iVar21 = pBVar7->init;
                              pBVar19[-1].prev_bio = (bio_st *)pBVar7->cb_arg;
                              pBVar19[-1].references = iVar21;
                              uVar22 = pBVar7->flags;
                              pBVar19[-1].num_read = pBVar7->shutdown;
                              pBVar19[-1].num_write = uVar22;
                              iVar21 = pBVar7->num;
                              pBVar19[-1].ex_data.sk = (stack_st_void *)pBVar7->retry_reason;
                              pBVar19[-1].ex_data.dummy = iVar21;
                              pBVar2 = (BIO *)&pBVar19->ptr;
                              pBVar7 = pBVar8;
                            } while (uVar23 < uVar3 - 3);
                          }
                          pCVar14 = &pBVar8[-1].ex_data;
                          do {
                            p_Var11 = *(_func_745 **)((int)(pCVar14 + 1) + 4);
                            uVar5 = uVar5 + 1;
                            pBVar19->method = (BIO_METHOD *)pCVar14[1].sk;
                            pBVar19->callback = p_Var11;
                            pBVar19 = (BIO *)&pBVar19->cb_arg;
                            pCVar14 = pCVar14 + 1;
                          } while (uVar5 < uVar3);
                          pBVar8 = (BIO *)(uVar3 * 8);
                          if (pBVar18 == (BIO *)(uVar3 * 8)) goto LAB_001c2a18;
                        }
                        puVar16 = (undefined1 *)((int)&pBVar18[-1].ptr + 1);
                        pBVar19 = (BIO *)((int)&pBVar8->method + 1);
                        if ((int)pBVar8 < (int)pBVar18 && (int)pBVar19 < (int)puVar16) {
                          pCVar14 = (CRYPTO_EX_DATA *)&pBVar8[0x19].retry_reason;
                          puVar17 = (undefined1 *)((int)&pBVar8->method + (int)&in->method);
                          iVar21 = (int)outl + (int)pCVar14 + 2;
                          pBVar7 = pBVar8;
                          do {
                            HintPreloadData((undefined1 *)((int)&in->ptr + 2) + (int)pBVar7);
                            iVar24 = (int)outl + (int)pCVar14;
                            pCVar14 = &pBVar7[0x19].ex_data;
                            ((undefined1 *)((int)outl + (int)pBVar7))[0x65a] =
                                 *(undefined1 *)((int)&pBVar7->method + (int)&in->method);
                            pBVar19 = (BIO *)((int)&pBVar7->ptr + 1);
                            HintPreloadData(iVar24 + 0x24);
                            *(undefined1 *)(iVar21 + 1) = puVar17[1];
                            *(undefined1 *)(iVar21 + 2) = puVar17[2];
                            *(undefined1 *)(iVar21 + 3) = puVar17[3];
                            *(undefined1 *)(iVar21 + 4) = puVar17[4];
                            *(undefined1 *)(iVar21 + 5) = puVar17[5];
                            *(undefined1 *)(iVar21 + 6) = puVar17[6];
                            *(undefined1 *)(iVar21 + 7) = puVar17[7];
                            *(undefined1 *)(iVar21 + 8) = puVar17[8];
                            *(undefined1 *)(iVar21 + 9) = puVar17[9];
                            *(undefined1 *)(iVar21 + 10) = puVar17[10];
                            *(undefined1 *)(iVar21 + 0xb) = puVar17[0xb];
                            *(undefined1 *)(iVar21 + 0xc) = puVar17[0xc];
                            *(undefined1 *)(iVar21 + 0xd) = puVar17[0xd];
                            *(undefined1 *)(iVar21 + 0xe) = puVar17[0xe];
                            *(undefined1 *)(iVar21 + 0xf) = puVar17[0xf];
                            *(undefined1 *)(iVar21 + 0x10) = puVar17[0x10];
                            *(undefined1 *)(iVar21 + 0x11) = puVar17[0x11];
                            *(undefined1 *)(iVar21 + 0x12) = puVar17[0x12];
                            *(undefined1 *)(iVar21 + 0x13) = puVar17[0x13];
                            *(undefined1 *)(iVar21 + 0x14) = puVar17[0x14];
                            *(undefined1 *)(iVar21 + 0x15) = puVar17[0x15];
                            *(undefined1 *)(iVar21 + 0x16) = puVar17[0x16];
                            *(undefined1 *)(iVar21 + 0x17) = puVar17[0x17];
                            *(undefined1 *)(iVar21 + 0x18) = puVar17[0x18];
                            *(undefined1 *)(iVar21 + 0x19) = puVar17[0x19];
                            *(undefined1 *)(iVar21 + 0x1a) = puVar17[0x1a];
                            *(undefined1 *)(iVar21 + 0x1b) = puVar17[0x1b];
                            *(undefined1 *)(iVar21 + 0x1c) = puVar17[0x1c];
                            *(undefined1 *)(iVar21 + 0x1d) = puVar17[0x1d];
                            *(undefined1 *)(iVar21 + 0x1e) = puVar17[0x1e];
                            puVar12 = puVar17 + 0x1f;
                            puVar17 = puVar17 + 0x20;
                            *(undefined1 *)(iVar21 + 0x1f) = *puVar12;
                            iVar21 = iVar21 + 0x20;
                            pBVar8 = (BIO *)&pBVar7->ptr;
                            pBVar7 = (BIO *)&pBVar7->ptr;
                          } while ((int)pBVar19 < (int)puVar16);
                        }
                        do {
                          ((undefined1 *)((int)outl + (int)pBVar8))[0x65a] =
                               *(undefined1 *)((int)&pBVar8->method + (int)&in->method);
                          bVar27 = (int)pBVar19 < (int)pBVar18;
                          pBVar8 = pBVar19;
                          pBVar19 = (BIO *)((int)&pBVar19->method + 1);
                        } while (bVar27);
                      }
LAB_001c2a18:
                      outl[2] = (size_t)pBVar18;
                    }
                    goto joined_r0x001c26d0;
                  }
                }
                pBVar18 = (BIO *)0x0;
                outl[2] = 0;
              }
              else {
                outl[2] = 0;
              }
LAB_001c271a:
              local_54 = (uchar *)((int)outl + 0x65a);
              uVar3 = BIO_test_flags(param_1,-1);
              if ((uVar3 & 0x100) == 0) {
                sVar10 = EVP_DecodeUpdate(ctx,(uchar *)out,(int *)outl,local_54,(int)puVar16);
                outl[2] = 0;
LAB_001c27e6:
                outl[1] = 0;
                if ((int)sVar10 < 0) {
                  *outl = 0;
                  local_3c = 0;
                  break;
                }
                sVar10 = *outl;
              }
              else {
                puVar17 = (undefined1 *)((uint)puVar16 & 0xfffffffc);
                sVar15 = EVP_DecodeBlock((uchar *)out,local_54,(int)puVar17);
                sVar10 = sVar15;
                if (((2 < (int)puVar17) && (*(char *)((int)outl + (int)(puVar17 + 0x659)) == '='))
                   && (sVar10 = sVar15 - 1, *(char *)((int)outl + (int)(puVar17 + 0x658)) == '=')) {
                  sVar10 = sVar15 - 2;
                }
                if (puVar17 != puVar16) {
                  memmove(local_54,(undefined1 *)((int)outl + (int)(puVar17 + 0x65a)),
                          (int)puVar16 - (int)puVar17);
                  outl[2] = (int)puVar16 - (int)puVar17;
                }
                if ((int)sVar10 < 1) {
                  *outl = 0;
                  goto LAB_001c27e6;
                }
                *outl = sVar10;
                outl[1] = 0;
              }
              if ((int)param_3 <= (int)sVar10) {
                sVar10 = param_3;
              }
              memcpy(local_4c,out,sVar10);
              param_3 = param_3 - sVar10;
              sVar15 = *outl;
              outl[1] = sVar10;
              local_44 = local_44 + sVar10;
              if (sVar15 == sVar10) {
                pBVar18 = (BIO *)0x0;
                *outl = 0;
              }
              if (sVar15 == sVar10) {
                outl[1] = (size_t)pBVar18;
              }
              local_4c = (void *)((int)local_4c + sVar10);
            }
joined_r0x001c26d0:
            if (((int)param_3 < 1) || ((int)outl[6] < 1)) break;
          } while( true );
        }
      }
      if (local_44 == 0) {
        local_44 = local_3c;
      }
      BIO_copy_next_retry(param_1);
    }
  }
  return local_44;
LAB_001c283a:
  puVar17 = puVar17 + 1;
  if (puVar17 == puVar16) goto LAB_001c2862;
  goto LAB_001c2840;
}

