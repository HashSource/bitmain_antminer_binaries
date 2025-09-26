
EC_GROUP * ec_asn1_pkparameters2group(int *param_1)

{
  BIGNUM *a;
  BIGNUM *b;
  int iVar1;
  ASN1_INTEGER *ai;
  BIGNUM *a_00;
  long n;
  void *__dest;
  BIGNUM *pBVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  size_t *psVar7;
  EC_POINT *p;
  EC_GROUP *pEVar8;
  int *piVar9;
  
  if (param_1 == (int *)0x0) {
    ERR_put_error(0x10,0x9e,0x7c,"ec_asn1.c",0x3a9);
    return (EC_GROUP *)0x0;
  }
  iVar3 = *param_1;
  if (iVar3 == 0) {
    iVar3 = OBJ_obj2nid((ASN1_OBJECT *)param_1[1]);
    pEVar8 = EC_GROUP_new_by_curve_name(iVar3);
    if (pEVar8 != (EC_GROUP *)0x0) {
      EC_GROUP_set_asn1_flag(pEVar8,1);
      return pEVar8;
    }
    ERR_put_error(0x10,0x9e,0x77,"ec_asn1.c",0x3b1);
    return (EC_GROUP *)0x0;
  }
  if (iVar3 != 1) {
    if (iVar3 != 2) {
      ERR_put_error(0x10,0x9e,0x73,"ec_asn1.c",0x3c0);
      return (EC_GROUP *)0x0;
    }
    return (EC_GROUP *)0x0;
  }
  iVar3 = param_1[1];
  piVar4 = *(int **)(iVar3 + 4);
  if (((piVar4 == (int *)0x0) || (*piVar4 == 0)) || (piVar4[1] == 0)) {
    iVar3 = 700;
LAB_0018d60e:
    pBVar2 = (BIGNUM *)0x0;
    a = (BIGNUM *)0x0;
    ERR_put_error(0x10,0x9d,0x73,"ec_asn1.c",iVar3);
  }
  else {
    puVar5 = *(undefined4 **)(iVar3 + 8);
    if (((puVar5 == (undefined4 *)0x0) || (piVar4 = (int *)*puVar5, piVar4 == (int *)0x0)) ||
       (((uchar *)piVar4[2] == (uchar *)0x0 || ((puVar5[1] == 0 || (*(int *)(puVar5[1] + 8) == 0))))
       )) {
      iVar3 = 0x2c4;
      goto LAB_0018d60e;
    }
    a = BN_bin2bn((uchar *)piVar4[2],*piVar4,(BIGNUM *)0x0);
    if (a == (BIGNUM *)0x0) {
      ERR_put_error(0x10,0x9d,3,"ec_asn1.c",0x2c9);
      pBVar2 = (BIGNUM *)0x0;
    }
    else {
      piVar4 = *(int **)(*(int *)(iVar3 + 8) + 4);
      b = BN_bin2bn((uchar *)piVar4[2],*piVar4,(BIGNUM *)0x0);
      pBVar2 = b;
      if (b == (BIGNUM *)0x0) {
        ERR_put_error(0x10,0x9d,3,"ec_asn1.c",0x2ce);
      }
      else {
        iVar1 = OBJ_obj2nid((ASN1_OBJECT *)**(undefined4 **)(iVar3 + 4));
        if (iVar1 == 0x197) {
          piVar4 = *(int **)(*(int *)(iVar3 + 4) + 4);
          iVar1 = *piVar4;
          if (iVar1 < 0x296) {
            a_00 = BN_new();
            if (a_00 != (BIGNUM *)0x0) {
              iVar6 = OBJ_obj2nid((ASN1_OBJECT *)piVar4[1]);
              if (iVar6 == 0x2aa) {
                if ((ASN1_INTEGER *)piVar4[2] == (ASN1_INTEGER *)0x0) {
                  iVar6 = 0x2f2;
                  goto LAB_0018d6ea;
                }
                n = ASN1_INTEGER_get((ASN1_INTEGER *)piVar4[2]);
                if ((n < *piVar4) && (0 < n)) {
                  iVar6 = BN_set_bit(a_00,*piVar4);
                  if (iVar6 != 0) {
                    iVar6 = BN_set_bit(a_00,n);
joined_r0x0018d77a:
                    if ((iVar6 != 0) && (iVar6 = BN_set_bit(a_00,0), iVar6 != 0)) {
                      pEVar8 = (EC_GROUP *)EC_GROUP_new_curve_GF2m(a_00,a,b,0);
                      goto LAB_0018d79a;
                    }
                  }
                }
                else {
                  ERR_put_error(0x10,0x9d,0x89,"ec_asn1.c",0x2fa);
                }
              }
              else if (iVar6 == 0x2ab) {
                piVar9 = (int *)piVar4[2];
                iVar6 = 0x30a;
                if (piVar9 == (int *)0x0) goto LAB_0018d6ea;
                if ((((piVar9[2] < *piVar4) && (piVar9[1] < piVar9[2])) && (*piVar9 < piVar9[1])) &&
                   (0 < *piVar9)) {
                  iVar6 = BN_set_bit(a_00,*piVar4);
                  if (((iVar6 != 0) && (iVar6 = BN_set_bit(a_00,*piVar9), iVar6 != 0)) &&
                     (iVar6 = BN_set_bit(a_00,piVar9[1]), iVar6 != 0)) {
                    iVar6 = BN_set_bit(a_00,piVar9[2]);
                    goto joined_r0x0018d77a;
                  }
                }
                else {
                  ERR_put_error(0x10,0x9d,0x84,"ec_asn1.c",0x312);
                }
              }
              else if (iVar6 == 0x2a9) {
                ERR_put_error(0x10,0x9d,0x7e,"ec_asn1.c",0x322);
              }
              else {
                iVar6 = 0x326;
LAB_0018d6ea:
                ERR_put_error(0x10,0x9d,0x73,"ec_asn1.c",iVar6);
              }
              goto LAB_0018d5d0;
            }
            ERR_put_error(0x10,0x9d,0x41,"ec_asn1.c",0x2e7);
          }
          else {
            ERR_put_error(0x10,0x9d,0x8f,"ec_asn1.c",0x2e2);
          }
        }
        else if (iVar1 == 0x196) {
          ai = *(ASN1_INTEGER **)(*(int *)(iVar3 + 4) + 4);
          if (ai == (ASN1_INTEGER *)0x0) {
            ERR_put_error(0x10,0x9d,0x73,"ec_asn1.c",0x332);
          }
          else {
            a_00 = ASN1_INTEGER_to_BN(ai,(BIGNUM *)0x0);
            if (a_00 != (BIGNUM *)0x0) {
              if ((a_00->neg == 0) && (a_00->top != 0)) {
                iVar1 = BN_num_bits(a_00);
                if (0x295 < iVar1) {
                  ERR_put_error(0x10,0x9d,0x8f,"ec_asn1.c",0x342);
                  goto LAB_0018d5d0;
                }
                pEVar8 = EC_GROUP_new_curve_GFp(a_00,a,b,(BN_CTX *)0x0);
LAB_0018d79a:
                if (pEVar8 == (EC_GROUP *)0x0) {
                  ERR_put_error(0x10,0x9d,0x10,"ec_asn1.c",0x34e);
                  goto LAB_0018d5d0;
                }
                iVar6 = *(int *)(iVar3 + 8);
                if (*(int *)(iVar6 + 8) == 0) {
LAB_0018d7dc:
                  if (((*(int *)(iVar3 + 0x10) == 0) || (*(int *)(iVar3 + 0xc) == 0)) ||
                     (*(int *)(*(int *)(iVar3 + 0xc) + 8) == 0)) {
                    ERR_put_error(0x10,0x9d,0x73,"ec_asn1.c",0x360);
                    p = (EC_POINT *)0x0;
                    goto LAB_0018d838;
                  }
                  p = EC_POINT_new(pEVar8);
                  if (p == (EC_POINT *)0x0) goto LAB_0018d838;
                  EC_GROUP_set_point_conversion_form
                            (pEVar8,**(byte **)(*(int *)(iVar3 + 0xc) + 8) & 0xfe);
                  iVar6 = EC_POINT_oct2point(pEVar8,p,(uchar *)(*(size_t **)(iVar3 + 0xc))[2],
                                             **(size_t **)(iVar3 + 0xc),(BN_CTX *)0x0);
                  if (iVar6 == 0) {
                    iVar3 = 0x36e;
LAB_0018d82a:
                    ERR_put_error(0x10,0x9d,0x10,"ec_asn1.c",iVar3);
                    goto LAB_0018d838;
                  }
                  a = ASN1_INTEGER_to_BN(*(ASN1_INTEGER **)(iVar3 + 0x10),a);
                  iVar6 = 0x374;
                  if (a == (BIGNUM *)0x0) {
LAB_0018d980:
                    ERR_put_error(0x10,0x9d,0xd,"ec_asn1.c",iVar6);
                    goto LAB_0018d838;
                  }
                  if ((a->neg != 0) || (a->top == 0)) {
                    iVar3 = 0x378;
LAB_0018d944:
                    ERR_put_error(0x10,0x9d,0x7a,"ec_asn1.c",iVar3);
                    goto LAB_0018d838;
                  }
                  iVar6 = BN_num_bits(a);
                  if (iVar1 + 1 < iVar6) {
                    iVar3 = 0x37c;
                    goto LAB_0018d944;
                  }
                  if (*(ASN1_INTEGER **)(iVar3 + 0x14) == (ASN1_INTEGER *)0x0) {
                    pBVar2 = (BIGNUM *)0x0;
                    BN_free(b);
                  }
                  else {
                    pBVar2 = ASN1_INTEGER_to_BN(*(ASN1_INTEGER **)(iVar3 + 0x14),b);
                    if (pBVar2 == (BIGNUM *)0x0) {
                      iVar6 = 0x387;
                      goto LAB_0018d980;
                    }
                  }
                  iVar3 = EC_GROUP_set_generator(pEVar8,p,a,pBVar2);
                  if (iVar3 == 0) {
                    iVar3 = 0x38c;
                    goto LAB_0018d82a;
                  }
                }
                else {
                  if (*(void **)(pEVar8 + 0x3c) != (void *)0x0) {
                    CRYPTO_free(*(void **)(pEVar8 + 0x3c));
                    iVar6 = *(int *)(iVar3 + 8);
                  }
                  __dest = CRYPTO_malloc(**(int **)(iVar6 + 8),"ec_asn1.c",0x356);
                  *(void **)(pEVar8 + 0x3c) = __dest;
                  if (__dest != (void *)0x0) {
                    psVar7 = *(size_t **)(*(int *)(iVar3 + 8) + 8);
                    memcpy(__dest,(void *)psVar7[2],*psVar7);
                    *(undefined4 *)(pEVar8 + 0x40) = **(undefined4 **)(*(int *)(iVar3 + 8) + 8);
                    goto LAB_0018d7dc;
                  }
                  ERR_put_error(0x10,0x9d,0x41,"ec_asn1.c",0x357);
                  p = (EC_POINT *)0x0;
LAB_0018d838:
                  EC_GROUP_clear_free(pEVar8);
                  pEVar8 = (EC_GROUP *)0x0;
                }
              }
              else {
                ERR_put_error(0x10,0x9d,0x67,"ec_asn1.c",0x33c);
LAB_0018d5d0:
                p = (EC_POINT *)0x0;
                pEVar8 = (EC_GROUP *)0x0;
                if (a_00 == (BIGNUM *)0x0) goto LAB_0018d620;
              }
              BN_free(a_00);
              goto LAB_0018d5e0;
            }
            ERR_put_error(0x10,0x9d,0xd,"ec_asn1.c",0x337);
          }
        }
        else {
          ERR_put_error(0x10,0x9d,0x67,"ec_asn1.c",0x349);
        }
      }
    }
  }
LAB_0018d620:
  pEVar8 = (EC_GROUP *)0x0;
  p = (EC_POINT *)pEVar8;
LAB_0018d5e0:
  if (a != (BIGNUM *)0x0) {
    BN_free(a);
  }
  if (pBVar2 != (BIGNUM *)0x0) {
    BN_free(pBVar2);
  }
  if (p != (EC_POINT *)0x0) {
    EC_POINT_free(p);
  }
  if (pEVar8 == (EC_GROUP *)0x0) {
    ERR_put_error(0x10,0x9e,0x10,"ec_asn1.c",0x3b9);
  }
  else {
    EC_GROUP_set_asn1_flag(pEVar8,0);
  }
  return pEVar8;
}

