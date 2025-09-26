
BIGNUM * EC_GROUP_new_from_ecparameters(int param_1)

{
  int iVar1;
  BIGNUM *a;
  BIGNUM *b;
  int iVar2;
  ASN1_INTEGER *ai;
  BIGNUM *a_00;
  long n;
  void *__dest;
  BIGNUM *p;
  BIGNUM *group;
  size_t sVar3;
  BIGNUM *pBVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  size_t *psVar8;
  BIGNUM *pBVar9;
  int *piVar10;
  bool bVar11;
  int iVar12;
  BIGNUM *local_2c;
  
  piVar5 = *(int **)(param_1 + 4);
  if (((piVar5 == (int *)0x0) || (*piVar5 == 0)) || (piVar5[1] == 0)) {
    iVar2 = 0x255;
LAB_0012560a:
    pBVar9 = (BIGNUM *)0x0;
    b = (BIGNUM *)0x0;
    a = (BIGNUM *)0x0;
    a_00 = (BIGNUM *)0x0;
    ERR_put_error(0x10,0x107,0x73,"crypto/ec/ec_asn1.c",iVar2);
    pBVar4 = (BIGNUM *)0x0;
    group = (BIGNUM *)0x0;
    p = (BIGNUM *)0x0;
  }
  else {
    puVar6 = *(undefined4 **)(param_1 + 8);
    if (((puVar6 == (undefined4 *)0x0) || (piVar5 = (int *)*puVar6, piVar5 == (int *)0x0)) ||
       (((uchar *)piVar5[2] == (uchar *)0x0 || ((puVar6[1] == 0 || (*(int *)(puVar6[1] + 8) == 0))))
       )) {
      iVar2 = 0x262;
      goto LAB_0012560a;
    }
    a = BN_bin2bn((uchar *)piVar5[2],*piVar5,(BIGNUM *)0x0);
    if (a == (BIGNUM *)0x0) {
      ERR_put_error(0x10,0x107,3,"crypto/ec/ec_asn1.c",0x267);
      pBVar9 = (BIGNUM *)0x0;
      b = (BIGNUM *)0x0;
      a_00 = (BIGNUM *)0x0;
      pBVar4 = (BIGNUM *)0x0;
      group = (BIGNUM *)0x0;
      p = (BIGNUM *)0x0;
      goto LAB_00125626;
    }
    piVar5 = *(int **)(*(int *)(param_1 + 8) + 4);
    b = BN_bin2bn((uchar *)piVar5[2],*piVar5,(BIGNUM *)0x0);
    if (b == (BIGNUM *)0x0) {
      iVar12 = 0x26c;
      iVar2 = 3;
LAB_00125676:
      pBVar9 = (BIGNUM *)0x0;
      ERR_put_error(0x10,0x107,iVar2,"crypto/ec/ec_asn1.c",iVar12);
      a_00 = (BIGNUM *)0x0;
      pBVar4 = (BIGNUM *)0x0;
      group = (BIGNUM *)0x0;
      p = (BIGNUM *)0x0;
    }
    else {
      iVar2 = OBJ_obj2nid((ASN1_OBJECT *)**(undefined4 **)(param_1 + 4));
      if (iVar2 != 0x197) {
        if (iVar2 == 0x196) {
          ai = *(ASN1_INTEGER **)(*(int *)(param_1 + 4) + 4);
          if (ai == (ASN1_INTEGER *)0x0) {
            ERR_put_error(0x10,0x107,0x73,"crypto/ec/ec_asn1.c",0x2d0);
            pBVar9 = (BIGNUM *)0x0;
            a_00 = (BIGNUM *)0x0;
            pBVar4 = (BIGNUM *)0x0;
            group = (BIGNUM *)0x0;
            p = (BIGNUM *)0x0;
            goto LAB_00125626;
          }
          a_00 = ASN1_INTEGER_to_BN(ai,(BIGNUM *)0x0);
          if (a_00 == (BIGNUM *)0x0) {
            iVar12 = 0x2d5;
            iVar2 = 0xd;
            pBVar9 = a_00;
            goto LAB_00125708;
          }
          iVar2 = BN_is_negative();
          if ((iVar2 != 0) || (iVar2 = BN_is_zero(a_00), iVar2 != 0)) {
            iVar12 = 0x2da;
            iVar2 = 0x67;
            goto LAB_001255ec;
          }
          iVar2 = BN_num_bits(a_00);
          if (0x295 < iVar2) {
            iVar2 = 0x8f;
            iVar12 = 0x2e0;
            goto LAB_00125784;
          }
          local_2c = (BIGNUM *)EC_GROUP_new_curve_GFp(a_00,a,b,(BN_CTX *)0x0);
LAB_0012583a:
          pBVar4 = local_2c;
          if (local_2c == (BIGNUM *)0x0) {
            ERR_put_error(0x10,0x107,0x10,"crypto/ec/ec_asn1.c",0x2ec);
            pBVar9 = (BIGNUM *)0x0;
            group = (BIGNUM *)0x0;
            p = (BIGNUM *)0x0;
            goto LAB_00125626;
          }
          piVar5 = *(int **)(*(int *)(param_1 + 8) + 8);
          if (piVar5 == (int *)0x0) {
LAB_001258ca:
            if (((*(int *)(param_1 + 0x10) == 0) ||
                (piVar5 = *(int **)(param_1 + 0xc), piVar5 == (int *)0x0)) ||
               ((piVar5[2] == 0 || (*piVar5 == 0)))) {
              pBVar9 = (BIGNUM *)0x0;
              ERR_put_error(0x10,0x107,0x73,"crypto/ec/ec_asn1.c",0x30a);
              group = (BIGNUM *)0x0;
              p = (BIGNUM *)0x0;
            }
            else {
              p = (BIGNUM *)EC_POINT_new((EC_GROUP *)local_2c);
              if (p == (BIGNUM *)0x0) {
                pBVar9 = (BIGNUM *)0x0;
                group = (BIGNUM *)0x0;
              }
              else {
                EC_GROUP_set_point_conversion_form
                          ((EC_GROUP *)local_2c,**(byte **)(*(int *)(param_1 + 0xc) + 8) & 0xfe);
                iVar12 = EC_POINT_oct2point((EC_GROUP *)local_2c,(EC_POINT *)p,
                                            (uchar *)(*(size_t **)(param_1 + 0xc))[2],
                                            **(size_t **)(param_1 + 0xc),(BN_CTX *)0x0);
                if (iVar12 == 0) {
                  ERR_put_error(0x10,0x107,0x10,"crypto/ec/ec_asn1.c",0x318);
                  pBVar9 = (BIGNUM *)0x0;
                  group = (BIGNUM *)0x0;
                }
                else {
                  pBVar9 = ASN1_INTEGER_to_BN(*(ASN1_INTEGER **)(param_1 + 0x10),a);
                  if (pBVar9 == (BIGNUM *)0x0) {
                    ERR_put_error(0x10,0x107,0xd,"crypto/ec/ec_asn1.c",0x31e);
                    pBVar9 = (BIGNUM *)0x0;
                    group = (BIGNUM *)0x0;
                  }
                  else {
                    iVar12 = BN_is_negative(a);
                    if ((iVar12 == 0) && (iVar12 = BN_is_zero(a), iVar12 == 0)) {
                      iVar12 = BN_num_bits(a);
                      if (iVar12 <= iVar2 + 1) {
                        if (*(ASN1_INTEGER **)(param_1 + 0x14) == (ASN1_INTEGER *)0x0) {
                          BN_free(b);
                          b = (BIGNUM *)0x0;
                        }
                        else {
                          pBVar9 = ASN1_INTEGER_to_BN(*(ASN1_INTEGER **)(param_1 + 0x14),b);
                          if (pBVar9 == (BIGNUM *)0x0) {
                            ERR_put_error(0x10,0x107,0xd,"crypto/ec/ec_asn1.c",0x32f);
                            pBVar9 = (BIGNUM *)0x0;
                            group = (BIGNUM *)0x0;
                            goto LAB_00125626;
                          }
                        }
                        iVar2 = EC_GROUP_set_generator((EC_GROUP *)local_2c,(EC_POINT *)p,a,b);
                        if (iVar2 == 0) {
                          ERR_put_error(0x10,0x107,0x10,"crypto/ec/ec_asn1.c",0x334);
                          pBVar9 = (BIGNUM *)0x0;
                          group = (BIGNUM *)0x0;
                        }
                        else {
                          pBVar9 = (BIGNUM *)BN_CTX_new();
                          if (pBVar9 == (BIGNUM *)0x0) {
                            ERR_put_error(0x10,0x107,3,"crypto/ec/ec_asn1.c",0x345);
                            group = (BIGNUM *)0x0;
                          }
                          else {
                            group = (BIGNUM *)EC_GROUP_dup((EC_GROUP *)local_2c);
                            if (((group == (BIGNUM *)0x0) ||
                                (sVar3 = EC_GROUP_set_seed((EC_GROUP *)group,(uchar *)0x0,0),
                                sVar3 != 1)) ||
                               (iVar2 = EC_GROUP_set_generator
                                                  ((EC_GROUP *)group,(EC_POINT *)p,a,(BIGNUM *)0x0),
                               iVar2 == 0)) {
                              ERR_put_error(0x10,0x107,0x10,"crypto/ec/ec_asn1.c",0x34b);
                            }
                            else {
                              iVar2 = ec_curve_nid_from_params(group,pBVar9);
                              if (iVar2 == 0) goto LAB_00125630;
                              pBVar4 = (BIGNUM *)EC_GROUP_new_by_curve_name(iVar2);
                              if (pBVar4 == (BIGNUM *)0x0) {
                                ERR_put_error(0x10,0x107,0x10,"crypto/ec/ec_asn1.c",0x364);
                                pBVar4 = local_2c;
                              }
                              else {
                                EC_GROUP_free((EC_GROUP *)local_2c);
                                EC_GROUP_set_asn1_flag((EC_GROUP *)pBVar4,0);
                                local_2c = pBVar4;
                                if ((*(int *)(*(int *)(param_1 + 8) + 8) != 0) ||
                                   (sVar3 = EC_GROUP_set_seed((EC_GROUP *)pBVar4,(uchar *)0x0,0),
                                   sVar3 == 1)) goto LAB_00125630;
                              }
                            }
                          }
                        }
                        goto LAB_00125626;
                      }
                      iVar2 = 0x326;
                    }
                    else {
                      iVar2 = 0x322;
                    }
                    pBVar9 = (BIGNUM *)0x0;
                    ERR_put_error(0x10,0x107,0x7a,"crypto/ec/ec_asn1.c",iVar2);
                    group = (BIGNUM *)0x0;
                  }
                }
              }
            }
          }
          else {
            if (*piVar5 == 0) {
              iVar2 = 0x73;
              iVar12 = 0x2f9;
            }
            else {
              CRYPTO_free((void *)local_2c[1].neg);
              __dest = CRYPTO_malloc(**(int **)(*(int *)(param_1 + 8) + 8),"crypto/ec/ec_asn1.c",
                                     0x2fd);
              local_2c[1].neg = (int)__dest;
              if (__dest != (void *)0x0) {
                psVar8 = *(size_t **)(*(int *)(param_1 + 8) + 8);
                memcpy(__dest,(void *)psVar8[2],*psVar8);
                local_2c[1].flags = **(int **)(*(int *)(param_1 + 8) + 8);
                goto LAB_001258ca;
              }
              iVar12 = 0x2fe;
              iVar2 = 0x41;
            }
LAB_0012585a:
            pBVar9 = (BIGNUM *)0x0;
            ERR_put_error(0x10,0x107,iVar2,"crypto/ec/ec_asn1.c",iVar12);
            pBVar4 = local_2c;
            group = pBVar9;
            p = pBVar9;
          }
          goto LAB_00125626;
        }
        iVar12 = 0x2e7;
        iVar2 = 0x67;
        goto LAB_00125676;
      }
      piVar5 = *(int **)(*(int *)(param_1 + 4) + 4);
      iVar2 = *piVar5;
      if (0x295 < iVar2) {
        iVar12 = 0x280;
        iVar2 = 0x8f;
        goto LAB_00125676;
      }
      a_00 = BN_new();
      if (a_00 == (BIGNUM *)0x0) {
        iVar12 = 0x285;
        iVar2 = 0x41;
        pBVar9 = a_00;
LAB_00125708:
        ERR_put_error(0x10,0x107,iVar2,"crypto/ec/ec_asn1.c",iVar12);
        a_00 = pBVar9;
        pBVar4 = pBVar9;
        group = pBVar9;
        p = pBVar9;
      }
      else {
        iVar12 = OBJ_obj2nid((ASN1_OBJECT *)piVar5[1]);
        if (iVar12 == 0x2aa) {
          if ((ASN1_INTEGER *)piVar5[2] == (ASN1_INTEGER *)0x0) {
            iVar12 = 0x290;
            iVar2 = 0x73;
LAB_00125784:
            pBVar9 = (BIGNUM *)0x0;
            ERR_put_error(0x10,0x107,iVar2,"crypto/ec/ec_asn1.c",iVar12);
            pBVar4 = pBVar9;
            group = pBVar9;
            p = pBVar9;
          }
          else {
            n = ASN1_INTEGER_get((ASN1_INTEGER *)piVar5[2]);
            if (*piVar5 <= n || n < 1) {
              iVar12 = 0x298;
              iVar2 = 0x89;
              goto LAB_001255ec;
            }
            pBVar9 = (BIGNUM *)BN_set_bit(a_00,*piVar5);
            pBVar4 = pBVar9;
            group = pBVar9;
            p = pBVar9;
            if ((pBVar9 != (BIGNUM *)0x0) &&
               (pBVar9 = (BIGNUM *)BN_set_bit(a_00,n), pBVar4 = pBVar9, group = pBVar9, p = pBVar9,
               pBVar9 != (BIGNUM *)0x0)) {
              pBVar9 = (BIGNUM *)BN_set_bit(a_00,0);
joined_r0x00125920:
              pBVar4 = pBVar9;
              group = pBVar9;
              p = pBVar9;
              if (pBVar9 != (BIGNUM *)0x0) {
                local_2c = (BIGNUM *)EC_GROUP_new_curve_GF2m(a_00,a,b,0);
                goto LAB_0012583a;
              }
            }
          }
        }
        else {
          if (iVar12 == 0x2ab) {
            piVar10 = (int *)piVar5[2];
            if (piVar10 == (int *)0x0) {
              iVar12 = 0x2a8;
              iVar2 = 0x73;
              local_2c = (BIGNUM *)0x0;
              goto LAB_0012585a;
            }
            if ((piVar10[2] < *piVar5) && (iVar12 = piVar10[1], iVar12 < piVar10[2])) {
              iVar7 = *piVar10;
              bVar11 = iVar12 == iVar7;
              iVar1 = iVar12 - iVar7;
              if (iVar12 > iVar7) {
                bVar11 = iVar7 == 0;
                iVar1 = iVar7;
              }
              if (!bVar11 && iVar1 < 0 == (iVar12 <= iVar7 && SBORROW4(iVar12,iVar7))) {
                iVar12 = BN_set_bit(a_00,*piVar5);
                if (iVar12 == 0) {
                  pBVar9 = (BIGNUM *)0x0;
                  pBVar4 = (BIGNUM *)0x0;
                  group = (BIGNUM *)0x0;
                  p = (BIGNUM *)0x0;
                }
                else {
                  pBVar9 = (BIGNUM *)BN_set_bit(a_00,*piVar10);
                  pBVar4 = pBVar9;
                  group = pBVar9;
                  p = pBVar9;
                  if (((pBVar9 != (BIGNUM *)0x0) &&
                      (pBVar9 = (BIGNUM *)BN_set_bit(a_00,piVar10[1]), pBVar4 = pBVar9,
                      group = pBVar9, p = pBVar9, pBVar9 != (BIGNUM *)0x0)) &&
                     (pBVar9 = (BIGNUM *)BN_set_bit(a_00,piVar10[2]), pBVar4 = pBVar9,
                     group = pBVar9, p = pBVar9, pBVar9 != (BIGNUM *)0x0)) {
                    pBVar9 = (BIGNUM *)BN_set_bit(a_00,0);
                    goto joined_r0x00125920;
                  }
                }
                goto LAB_00125626;
              }
            }
            iVar12 = 0x2b0;
            iVar2 = 0x84;
          }
          else if (iVar12 == 0x2a9) {
            iVar12 = 0x2c0;
            iVar2 = 0x7e;
          }
          else {
            iVar12 = 0x2c4;
            iVar2 = 0x73;
          }
LAB_001255ec:
          pBVar9 = (BIGNUM *)0x0;
          ERR_put_error(0x10,0x107,iVar2,"crypto/ec/ec_asn1.c",iVar12);
          pBVar4 = (BIGNUM *)0x0;
          group = (BIGNUM *)0x0;
          p = (BIGNUM *)0x0;
        }
      }
    }
  }
LAB_00125626:
  local_2c = (BIGNUM *)0x0;
  EC_GROUP_free((EC_GROUP *)pBVar4);
LAB_00125630:
  EC_GROUP_free((EC_GROUP *)group);
  BN_free(a_00);
  BN_free(a);
  BN_free(b);
  EC_POINT_free((EC_POINT *)p);
  BN_CTX_free((BN_CTX *)pBVar9);
  return local_2c;
}

