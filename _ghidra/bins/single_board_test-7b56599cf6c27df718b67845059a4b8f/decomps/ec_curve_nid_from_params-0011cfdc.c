
int ec_curve_nid_from_params(EC_GROUP *param_1,BN_CTX *param_2)

{
  EC_METHOD *meth;
  int iVar1;
  int iVar2;
  size_t __n;
  uchar *__s2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  void *__s1;
  BIGNUM *pBVar6;
  int iVar7;
  EC_POINT *pEVar8;
  int iVar9;
  int *piVar10;
  BIGNUM **ppBVar11;
  undefined4 *puVar12;
  void *pvVar13;
  BIGNUM **ppBVar14;
  BIGNUM **ppBVar15;
  bool bVar16;
  BIGNUM *local_40 [7];
  
  ppBVar11 = local_40;
  local_40[1] = (BIGNUM *)0x0;
  local_40[0] = (BIGNUM *)0x0;
  local_40[2] = (BIGNUM *)0x0;
  local_40[3] = (BIGNUM *)0x0;
  local_40[4] = (BIGNUM *)0x0;
  local_40[5] = (BIGNUM *)0x0;
  meth = EC_GROUP_method_of(param_1);
  if (meth == (EC_METHOD *)0x0) {
    return -1;
  }
  iVar1 = EC_GROUP_get_curve_name(param_1);
  iVar2 = EC_METHOD_get_field_type(meth);
  __n = EC_GROUP_get_seed_len(param_1);
  __s2 = EC_GROUP_get0_seed(param_1);
  uVar3 = EC_GROUP_get0_cofactor(param_1);
  BN_CTX_start(param_2);
  iVar4 = BN_num_bits(*(BIGNUM **)(param_1 + 8));
  iVar7 = iVar4 + 7;
  if (iVar4 + 7 < 0) {
    iVar7 = iVar4 + 0xe;
  }
  iVar5 = BN_num_bits(*(BIGNUM **)(param_1 + 0x28));
  iVar4 = iVar5 + 0xe;
  if (-1 < iVar5 + 7) {
    iVar4 = iVar5 + 7;
  }
  iVar5 = iVar4 >> 3;
  if (iVar4 >> 3 < iVar7 >> 3) {
    iVar5 = iVar7 >> 3;
  }
  __s1 = CRYPTO_malloc(iVar5 * 6,"crypto/ec/ec_curve.c",0xcca);
  ppBVar14 = ppBVar11;
  if (__s1 != (void *)0x0) {
    do {
      pBVar6 = BN_CTX_get(param_2);
      ppBVar15 = ppBVar14 + 1;
      *ppBVar14 = pBVar6;
      if (pBVar6 == (BIGNUM *)0x0) goto LAB_0011d09e;
      ppBVar14 = ppBVar15;
    } while (local_40 + 6 != ppBVar15);
    iVar7 = EC_GROUP_get_curve(param_1,local_40[0],local_40[1],local_40[2],param_2);
    if ((((iVar7 != 0) && (pEVar8 = EC_GROUP_get0_generator(param_1), pEVar8 != (EC_POINT *)0x0)) &&
        (iVar7 = EC_POINT_get_affine_coordinates(param_1,pEVar8,local_40[3],local_40[4],param_2),
        iVar7 != 0)) &&
       (iVar7 = EC_GROUP_get_order(param_1,local_40[5],param_2), pvVar13 = __s1, iVar7 != 0)) {
      do {
        ppBVar14 = ppBVar11 + 1;
        iVar7 = BN_bn2binpad(*ppBVar11,pvVar13,iVar5);
        if (iVar7 < 1) goto LAB_0011d09e;
        ppBVar11 = ppBVar14;
        pvVar13 = (void *)((int)pvVar13 + iVar5);
      } while (ppBVar14 != local_40 + 6);
      puVar12 = &DAT_0025f4e0;
      do {
        piVar10 = (int *)puVar12[-0xc];
        HintPreloadData(puVar12);
        if ((iVar2 == *piVar10) && (piVar10[2] == iVar5)) {
          iVar7 = puVar12[-0xd];
          bVar16 = iVar7 == iVar1;
          iVar4 = iVar7 - iVar1;
          if (!bVar16) {
            iVar4 = iVar1;
          }
          if ((bVar16 || iVar1 == 0) || iVar4 < 0 != (bVar16 && SBORROW4(iVar7,iVar1))) {
            iVar9 = piVar10[1];
            iVar4 = BN_is_zero(uVar3);
            if ((iVar4 != 0) || (iVar4 = BN_is_word(uVar3,piVar10[3]), iVar4 != 0)) {
              if (((__n == 0 || piVar10[1] == 0) ||
                  ((__n == piVar10[1] && (iVar4 = memcmp(piVar10 + 4,__s2,__n), iVar4 == 0)))) &&
                 (iVar4 = memcmp(__s1,(void *)(iVar9 + (int)(piVar10 + 4)),iVar5 * 6), iVar4 == 0))
              goto LAB_0011d0a2;
            }
          }
        }
        puVar12 = puVar12 + 4;
      } while (puVar12 != (undefined4 *)0x25fa00);
      iVar7 = 0;
      goto LAB_0011d0a2;
    }
  }
LAB_0011d09e:
  iVar7 = -1;
LAB_0011d0a2:
  CRYPTO_free(__s1);
  BN_CTX_end(param_2);
  return iVar7;
}

