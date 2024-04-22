
size_t b64_read(BIO *param_1,void *param_2,size_t param_3)

{
  undefined *puVar1;
  BIO *pBVar2;
  BIO *pBVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  BIO *pBVar7;
  size_t sVar8;
  _func_745 *p_Var9;
  BIO *pBVar10;
  BIO *pBVar11;
  CRYPTO_EX_DATA *pCVar12;
  size_t sVar13;
  BIO *pBVar14;
  EVP_ENCODE_CTX *ctx;
  BIO *pBVar15;
  BIO *in;
  BIO *out;
  BIO *pBVar16;
  BIO *pBVar17;
  bio_st *pbVar18;
  int iVar19;
  ulong uVar20;
  size_t *outl;
  undefined *puVar21;
  uint uVar22;
  int iVar23;
  bool bVar24;
  uchar *local_54;
  void *local_4c;
  size_t local_44;
  size_t local_3c;
  BIO *local_2c [2];
  
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
        sVar8 = outl[1];
        if ((int)local_44 < (int)sVar8) {
          OpenSSLDie(DAT_0012ba58,0xad,DAT_0012ba60);
          local_44 = *outl;
          sVar8 = outl[1];
        }
        local_44 = local_44 - sVar8;
        if ((int)param_3 <= (int)local_44) {
          local_44 = param_3;
        }
        if (0x5dd < (int)(local_44 + sVar8)) {
          OpenSSLDie(DAT_0012ba58,0xb1,DAT_0012ba5c);
          sVar8 = outl[1];
        }
        memcpy(param_2,(void *)((int)outl + sVar8 + 0x7c),local_44);
        sVar8 = outl[1];
        param_3 = param_3 - local_44;
        outl[1] = local_44 + sVar8;
        local_4c = (void *)((int)param_2 + local_44);
        if (local_44 + sVar8 == *outl) {
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
          pBVar16 = out;
          do {
            sVar8 = BIO_read(param_1->next_bio,(void *)((int)outl + outl[2] + 0x65a),0x400 - outl[2]
                            );
            if ((int)sVar8 < 1) {
              iVar19 = BIO_test_flags(param_1->next_bio,8);
              local_3c = sVar8;
              if (iVar19 != 0) break;
              sVar13 = outl[2];
              outl[6] = sVar8;
              if (sVar13 == 0) break;
              sVar8 = 0;
              pBVar16 = param_1;
            }
            else {
              sVar13 = outl[2];
            }
            pBVar14 = (BIO *)(sVar8 + sVar13);
            outl[2] = (size_t)pBVar14;
            if (outl[5] == 0) {
LAB_0012b402:
              if (0x3ff < (int)pBVar14) goto LAB_0012b412;
              if ((int)outl[6] < 1) {
                pBVar16 = (BIO *)((int)outl + 0x65a);
                goto LAB_0012b412;
              }
            }
            else {
              uVar4 = BIO_test_flags(param_1,-1);
              if ((uVar4 & 0x100) == 0) {
                pBVar15 = (BIO *)outl[5];
                if (pBVar15 == (BIO *)0x0) goto LAB_0012b402;
                pBVar17 = (BIO *)((int)outl + 0x65a);
                pBVar7 = (BIO *)0x0;
                in = pBVar17;
                pBVar16 = pBVar17;
                pBVar10 = pBVar17;
                local_2c[0] = pBVar7;
                if (0 < (int)pBVar14) {
LAB_0012b538:
                  do {
                    pBVar16 = (BIO *)((int)&pBVar10->method + 1);
                    pBVar15 = (BIO *)(uint)*(byte *)&pBVar10->method;
                    pBVar10 = pBVar16;
                    if (pBVar15 != (BIO *)0xa) goto LAB_0012b532;
                    pBVar15 = (BIO *)outl[3];
                    if (pBVar15 == (BIO *)0x0) {
                      pBVar15 = in;
                      iVar19 = EVP_DecodeUpdate(ctx,(uchar *)out,(int *)local_2c,(uchar *)in,
                                                (int)pBVar16 - (int)in);
                      if (((iVar19 < 1) && (pBVar15 = local_2c[0], local_2c[0] == (BIO *)0x0)) &&
                         (pBVar15 = (BIO *)outl[5], pBVar15 != (BIO *)0x0)) {
                        EVP_DecodeInit(ctx);
                        in = pBVar16;
                        goto LAB_0012b532;
                      }
                      if (pBVar17 == in) goto LAB_0012b9a8;
                      pBVar15 = (BIO *)((int)pBVar17 - (int)in);
                      pBVar14 = (BIO *)((int)pBVar14 + (int)pBVar15);
                      if ((int)pBVar14 < 1) goto LAB_0012b9a8;
                      uVar4 = (uint)pBVar14 >> 3;
                      pBVar10 = (BIO *)((uint)pBVar14 & 0xfffffff8);
                      if (uVar4 != 0 &&
                          ((((uint)in | (uint)pBVar17) & 7) == 0 &&
                          ((BIO *)0x7 < pBVar14 &&
                          ((BIO *)((int)outl + 0x662) <= in || &in->cb_arg <= pBVar17)))) {
                        if (uVar4 < 5) {
                          uVar5 = 0;
                          pBVar11 = pBVar17;
                          pBVar15 = in;
                        }
                        else {
                          uVar5 = 0;
                          pBVar3 = (BIO *)((int)outl + 0x67a);
                          pBVar2 = in;
                          do {
                            pBVar11 = pBVar3;
                            pBVar15 = (BIO *)&pBVar2->ptr;
                            pbVar18 = (bio_st *)pBVar2->callback;
                            uVar22 = uVar5 + 5;
                            uVar5 = uVar5 + 4;
                            HintPreloadData(&pBVar2[2].ex_data);
                            pBVar11[-1].ptr = pBVar2->method;
                            pBVar11[-1].next_bio = pbVar18;
                            iVar19 = pBVar2->init;
                            pBVar11[-1].prev_bio = (bio_st *)pBVar2->cb_arg;
                            pBVar11[-1].references = iVar19;
                            uVar20 = pBVar2->flags;
                            pBVar11[-1].num_read = pBVar2->shutdown;
                            pBVar11[-1].num_write = uVar20;
                            iVar19 = pBVar2->num;
                            pBVar11[-1].ex_data.sk = (stack_st_void *)pBVar2->retry_reason;
                            pBVar11[-1].ex_data.dummy = iVar19;
                            pBVar3 = (BIO *)&pBVar11->ptr;
                            pBVar2 = pBVar15;
                          } while (uVar22 < uVar4 - 3);
                        }
                        pCVar12 = &pBVar15[-1].ex_data;
                        do {
                          p_Var9 = *(_func_745 **)((int)(pCVar12 + 1) + 4);
                          uVar5 = uVar5 + 1;
                          pBVar15 = (BIO *)&pBVar11->cb_arg;
                          pBVar11->method = (BIO_METHOD *)pCVar12[1].sk;
                          pBVar11->callback = p_Var9;
                          pBVar11 = pBVar15;
                          pCVar12 = pCVar12 + 1;
                        } while (uVar5 < uVar4);
                        if (pBVar14 != pBVar10) {
LAB_0012b83e:
                          puVar21 = (undefined *)((int)&pBVar14[-1].ptr + 1);
                          pBVar11 = (BIO *)((int)&pBVar10->method + 1);
                          if ((int)pBVar10 < (int)pBVar14 && (int)pBVar11 < (int)puVar21) {
                            pCVar12 = (CRYPTO_EX_DATA *)&pBVar10[0x19].retry_reason;
                            iVar19 = (int)&pBVar10->method + (int)&in->method;
                            iVar6 = (int)outl + (int)pCVar12 + 2;
                            pBVar15 = pBVar10;
                            do {
                              HintPreloadData((undefined *)((int)&in->ptr + 2) + (int)pBVar15);
                              pBVar10 = (BIO *)&pBVar15->ptr;
                              iVar23 = (int)outl + (int)pCVar12;
                              pCVar12 = &pBVar15[0x19].ex_data;
                              *(undefined *)((int)outl + (int)pBVar15 + 0x65a) =
                                   *(undefined *)((int)&pBVar15->method + (int)&in->method);
                              pBVar11 = (BIO *)((int)&pBVar15->ptr + 1);
                              HintPreloadData(iVar23 + 0x24);
                              *(undefined *)(iVar6 + 1) = *(undefined *)(iVar19 + 1);
                              *(undefined *)(iVar6 + 2) = *(undefined *)(iVar19 + 2);
                              *(undefined *)(iVar6 + 3) = *(undefined *)(iVar19 + 3);
                              *(undefined *)(iVar6 + 4) = *(undefined *)(iVar19 + 4);
                              *(undefined *)(iVar6 + 5) = *(undefined *)(iVar19 + 5);
                              *(undefined *)(iVar6 + 6) = *(undefined *)(iVar19 + 6);
                              *(undefined *)(iVar6 + 7) = *(undefined *)(iVar19 + 7);
                              *(undefined *)(iVar6 + 8) = *(undefined *)(iVar19 + 8);
                              *(undefined *)(iVar6 + 9) = *(undefined *)(iVar19 + 9);
                              *(undefined *)(iVar6 + 10) = *(undefined *)(iVar19 + 10);
                              *(undefined *)(iVar6 + 0xb) = *(undefined *)(iVar19 + 0xb);
                              *(undefined *)(iVar6 + 0xc) = *(undefined *)(iVar19 + 0xc);
                              *(undefined *)(iVar6 + 0xd) = *(undefined *)(iVar19 + 0xd);
                              *(undefined *)(iVar6 + 0xe) = *(undefined *)(iVar19 + 0xe);
                              *(undefined *)(iVar6 + 0xf) = *(undefined *)(iVar19 + 0xf);
                              *(undefined *)(iVar6 + 0x10) = *(undefined *)(iVar19 + 0x10);
                              *(undefined *)(iVar6 + 0x11) = *(undefined *)(iVar19 + 0x11);
                              *(undefined *)(iVar6 + 0x12) = *(undefined *)(iVar19 + 0x12);
                              *(undefined *)(iVar6 + 0x13) = *(undefined *)(iVar19 + 0x13);
                              *(undefined *)(iVar6 + 0x14) = *(undefined *)(iVar19 + 0x14);
                              *(undefined *)(iVar6 + 0x15) = *(undefined *)(iVar19 + 0x15);
                              *(undefined *)(iVar6 + 0x16) = *(undefined *)(iVar19 + 0x16);
                              *(undefined *)(iVar6 + 0x17) = *(undefined *)(iVar19 + 0x17);
                              *(undefined *)(iVar6 + 0x18) = *(undefined *)(iVar19 + 0x18);
                              *(undefined *)(iVar6 + 0x19) = *(undefined *)(iVar19 + 0x19);
                              *(undefined *)(iVar6 + 0x1a) = *(undefined *)(iVar19 + 0x1a);
                              *(undefined *)(iVar6 + 0x1b) = *(undefined *)(iVar19 + 0x1b);
                              *(undefined *)(iVar6 + 0x1c) = *(undefined *)(iVar19 + 0x1c);
                              *(undefined *)(iVar6 + 0x1d) = *(undefined *)(iVar19 + 0x1d);
                              *(undefined *)(iVar6 + 0x1e) = *(undefined *)(iVar19 + 0x1e);
                              puVar1 = (undefined *)(iVar19 + 0x1f);
                              iVar19 = iVar19 + 0x20;
                              *(undefined *)(iVar6 + 0x1f) = *puVar1;
                              iVar6 = iVar6 + 0x20;
                              pBVar15 = pBVar10;
                            } while ((int)pBVar11 < (int)puVar21);
                          }
                          do {
                            pBVar15 = (BIO *)((int)&pBVar11->method + 1);
                            *(undefined *)((int)outl + (int)pBVar10 + 0x65a) =
                                 *(undefined *)((int)&pBVar10->method + (int)&in->method);
                            bVar24 = (int)pBVar11 < (int)pBVar14;
                            pBVar10 = pBVar11;
                            pBVar11 = pBVar15;
                          } while (bVar24);
                        }
LAB_0012b9a8:
                        EVP_DecodeInit(ctx);
                        outl[5] = 0;
                        goto LAB_0012b9b4;
                      }
                      pBVar10 = (BIO *)0x0;
                      goto LAB_0012b83e;
                    }
                    pBVar7 = (BIO *)((int)&pBVar7->method + 1);
                    outl[3] = 0;
                    in = pBVar16;
                  } while (pBVar7 != pBVar14);
                  goto LAB_0012b55a;
                }
LAB_0012b9b4:
                if (pBVar7 == pBVar14) {
LAB_0012b55a:
                  if (local_2c[0] == (BIO *)0x0) {
                    if (in == pBVar17) {
                      bVar24 = pBVar7 == (BIO *)0x400;
                      if (bVar24) {
                        pBVar15 = (BIO *)0x1;
                      }
                      if (bVar24) {
                        outl[2] = 0;
                      }
                      if (bVar24) {
                        outl[3] = (size_t)pBVar15;
                      }
                    }
                    else if (in != pBVar16) {
                      pBVar16 = (BIO *)((int)pBVar16 - (int)in);
                      if (0 < (int)pBVar16) {
                        uVar4 = (uint)pBVar16 >> 3;
                        pBVar14 = (BIO *)0x0;
                        if (uVar4 != 0 &&
                            ((((uint)in | (uint)pBVar17) & 7) == 0 &&
                            ((BIO *)0x7 < pBVar16 &&
                            ((BIO *)((int)outl + 0x662) <= in || &in->cb_arg <= pBVar17)))) {
                          if (uVar4 < 5) {
                            uVar5 = 0;
                            pBVar14 = in;
                          }
                          else {
                            uVar5 = 0;
                            pBVar7 = (BIO *)((int)outl + 0x67a);
                            pBVar15 = in;
                            do {
                              pBVar17 = pBVar7;
                              pBVar14 = (BIO *)&pBVar15->ptr;
                              pbVar18 = (bio_st *)pBVar15->callback;
                              uVar22 = uVar5 + 5;
                              uVar5 = uVar5 + 4;
                              HintPreloadData(&pBVar15[2].ex_data);
                              pBVar17[-1].ptr = pBVar15->method;
                              pBVar17[-1].next_bio = pbVar18;
                              iVar19 = pBVar15->init;
                              pBVar17[-1].prev_bio = (bio_st *)pBVar15->cb_arg;
                              pBVar17[-1].references = iVar19;
                              uVar20 = pBVar15->flags;
                              pBVar17[-1].num_read = pBVar15->shutdown;
                              pBVar17[-1].num_write = uVar20;
                              iVar19 = pBVar15->num;
                              pBVar17[-1].ex_data.sk = (stack_st_void *)pBVar15->retry_reason;
                              pBVar17[-1].ex_data.dummy = iVar19;
                              pBVar7 = (BIO *)&pBVar17->ptr;
                              pBVar15 = pBVar14;
                            } while (uVar22 < uVar4 - 3);
                          }
                          pCVar12 = &pBVar14[-1].ex_data;
                          do {
                            p_Var9 = *(_func_745 **)((int)(pCVar12 + 1) + 4);
                            uVar5 = uVar5 + 1;
                            pBVar17->method = (BIO_METHOD *)pCVar12[1].sk;
                            pBVar17->callback = p_Var9;
                            pBVar17 = (BIO *)&pBVar17->cb_arg;
                            pCVar12 = pCVar12 + 1;
                          } while (uVar5 < uVar4);
                          pBVar14 = (BIO *)((uint)pBVar16 & 0xfffffff8);
                          if (pBVar16 == (BIO *)((uint)pBVar16 & 0xfffffff8)) goto LAB_0012b710;
                        }
                        puVar21 = (undefined *)((int)&pBVar16[-1].ptr + 1);
                        pBVar15 = (BIO *)((int)&pBVar14->method + 1);
                        if ((int)pBVar14 < (int)pBVar16 && (int)pBVar15 < (int)puVar21) {
                          pCVar12 = (CRYPTO_EX_DATA *)&pBVar14[0x19].retry_reason;
                          iVar19 = (int)&pBVar14->method + (int)&in->method;
                          iVar6 = (int)outl + (int)pCVar12 + 2;
                          pBVar7 = pBVar14;
                          do {
                            HintPreloadData((undefined *)((int)&in->ptr + 2) + (int)pBVar7);
                            iVar23 = (int)outl + (int)pCVar12;
                            pCVar12 = &pBVar7[0x19].ex_data;
                            *(undefined *)((int)outl + (int)pBVar7 + 0x65a) =
                                 *(undefined *)((int)&pBVar7->method + (int)&in->method);
                            pBVar15 = (BIO *)((int)&pBVar7->ptr + 1);
                            HintPreloadData(iVar23 + 0x24);
                            *(undefined *)(iVar6 + 1) = *(undefined *)(iVar19 + 1);
                            *(undefined *)(iVar6 + 2) = *(undefined *)(iVar19 + 2);
                            *(undefined *)(iVar6 + 3) = *(undefined *)(iVar19 + 3);
                            *(undefined *)(iVar6 + 4) = *(undefined *)(iVar19 + 4);
                            *(undefined *)(iVar6 + 5) = *(undefined *)(iVar19 + 5);
                            *(undefined *)(iVar6 + 6) = *(undefined *)(iVar19 + 6);
                            *(undefined *)(iVar6 + 7) = *(undefined *)(iVar19 + 7);
                            *(undefined *)(iVar6 + 8) = *(undefined *)(iVar19 + 8);
                            *(undefined *)(iVar6 + 9) = *(undefined *)(iVar19 + 9);
                            *(undefined *)(iVar6 + 10) = *(undefined *)(iVar19 + 10);
                            *(undefined *)(iVar6 + 0xb) = *(undefined *)(iVar19 + 0xb);
                            *(undefined *)(iVar6 + 0xc) = *(undefined *)(iVar19 + 0xc);
                            *(undefined *)(iVar6 + 0xd) = *(undefined *)(iVar19 + 0xd);
                            *(undefined *)(iVar6 + 0xe) = *(undefined *)(iVar19 + 0xe);
                            *(undefined *)(iVar6 + 0xf) = *(undefined *)(iVar19 + 0xf);
                            *(undefined *)(iVar6 + 0x10) = *(undefined *)(iVar19 + 0x10);
                            *(undefined *)(iVar6 + 0x11) = *(undefined *)(iVar19 + 0x11);
                            *(undefined *)(iVar6 + 0x12) = *(undefined *)(iVar19 + 0x12);
                            *(undefined *)(iVar6 + 0x13) = *(undefined *)(iVar19 + 0x13);
                            *(undefined *)(iVar6 + 0x14) = *(undefined *)(iVar19 + 0x14);
                            *(undefined *)(iVar6 + 0x15) = *(undefined *)(iVar19 + 0x15);
                            *(undefined *)(iVar6 + 0x16) = *(undefined *)(iVar19 + 0x16);
                            *(undefined *)(iVar6 + 0x17) = *(undefined *)(iVar19 + 0x17);
                            *(undefined *)(iVar6 + 0x18) = *(undefined *)(iVar19 + 0x18);
                            *(undefined *)(iVar6 + 0x19) = *(undefined *)(iVar19 + 0x19);
                            *(undefined *)(iVar6 + 0x1a) = *(undefined *)(iVar19 + 0x1a);
                            *(undefined *)(iVar6 + 0x1b) = *(undefined *)(iVar19 + 0x1b);
                            *(undefined *)(iVar6 + 0x1c) = *(undefined *)(iVar19 + 0x1c);
                            *(undefined *)(iVar6 + 0x1d) = *(undefined *)(iVar19 + 0x1d);
                            *(undefined *)(iVar6 + 0x1e) = *(undefined *)(iVar19 + 0x1e);
                            puVar1 = (undefined *)(iVar19 + 0x1f);
                            iVar19 = iVar19 + 0x20;
                            *(undefined *)(iVar6 + 0x1f) = *puVar1;
                            iVar6 = iVar6 + 0x20;
                            pBVar14 = (BIO *)&pBVar7->ptr;
                            pBVar7 = (BIO *)&pBVar7->ptr;
                          } while ((int)pBVar15 < (int)puVar21);
                        }
                        do {
                          *(undefined *)((int)outl + (int)pBVar14 + 0x65a) =
                               *(undefined *)((int)&pBVar14->method + (int)&in->method);
                          bVar24 = (int)pBVar15 < (int)pBVar16;
                          pBVar14 = pBVar15;
                          pBVar15 = (BIO *)((int)&pBVar15->method + 1);
                        } while (bVar24);
                      }
LAB_0012b710:
                      outl[2] = (size_t)pBVar16;
                    }
                    goto joined_r0x0012b3c8;
                  }
                }
                pBVar16 = (BIO *)0x0;
                outl[2] = 0;
              }
              else {
                outl[2] = 0;
              }
LAB_0012b412:
              local_54 = (uchar *)((int)outl + 0x65a);
              uVar4 = BIO_test_flags(param_1,-1);
              if ((uVar4 & 0x100) == 0) {
                sVar8 = EVP_DecodeUpdate(ctx,(uchar *)out,(int *)outl,local_54,(int)pBVar14);
                outl[2] = 0;
LAB_0012b4de:
                outl[1] = 0;
                if ((int)sVar8 < 0) {
                  *outl = 0;
                  local_3c = 0;
                  break;
                }
                sVar8 = *outl;
              }
              else {
                pBVar15 = (BIO *)((uint)pBVar14 & 0xfffffffc);
                sVar13 = EVP_DecodeBlock((uchar *)out,local_54,(int)pBVar15);
                sVar8 = sVar13;
                if (((2 < (int)pBVar15) && (*(char *)((int)outl + (int)pBVar15 + 0x659) == '=')) &&
                   (sVar8 = sVar13 - 1, *(char *)((int)outl + (int)pBVar15 + 0x658) == '=')) {
                  sVar8 = sVar13 - 2;
                }
                if (pBVar15 != pBVar14) {
                  memmove(local_54,(void *)((int)outl + (int)pBVar15 + 0x65a),
                          (int)pBVar14 - (int)pBVar15);
                  outl[2] = (int)pBVar14 - (int)pBVar15;
                }
                if ((int)sVar8 < 1) {
                  *outl = 0;
                  goto LAB_0012b4de;
                }
                *outl = sVar8;
                outl[1] = 0;
              }
              if ((int)param_3 <= (int)sVar8) {
                sVar8 = param_3;
              }
              memcpy(local_4c,out,sVar8);
              param_3 = param_3 - sVar8;
              sVar13 = *outl;
              outl[1] = sVar8;
              local_44 = local_44 + sVar8;
              if (sVar13 == sVar8) {
                pBVar16 = (BIO *)0x0;
                *outl = 0;
              }
              if (sVar13 == sVar8) {
                outl[1] = (size_t)pBVar16;
              }
              local_4c = (void *)((int)local_4c + sVar8);
            }
joined_r0x0012b3c8:
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
LAB_0012b532:
  pBVar7 = (BIO *)((int)&pBVar7->method + 1);
  if (pBVar7 == pBVar14) goto LAB_0012b55a;
  goto LAB_0012b538;
}

