
undefined4 ec_wNAF_precompute_mult(EC_GROUP *param_1,BN_CTX *param_2)

{
  size_t sVar1;
  uint uVar2;
  undefined4 *ptr;
  int iVar3;
  EC_POINT *pEVar4;
  BIGNUM *a;
  uint uVar5;
  EC_POINT **points;
  int iVar6;
  undefined4 uVar7;
  EC_POINT **ppEVar8;
  size_t num;
  EC_POINT **ppEVar9;
  EC_POINT **ppEVar10;
  EC_POINT *pEVar11;
  BN_CTX *local_4c;
  EC_POINT *local_48;
  uint local_44;
  undefined4 local_3c;
  
  EC_pre_comp_free();
  if (param_1 == (EC_GROUP *)0x0) {
    return 0;
  }
  ptr = (undefined4 *)CRYPTO_zalloc(0x20,"crypto/ec/ec_mult.c",0x34);
  if (ptr == (undefined4 *)0x0) {
    ERR_put_error(0x10,0xc4,0x41,"crypto/ec/ec_mult.c",0x36);
    return 0;
  }
  *ptr = param_1;
  ptr[1] = 8;
  ptr[3] = 4;
  DataMemoryBarrier(0x1b);
  ptr[6] = 1;
  DataMemoryBarrier(0x1b);
  iVar3 = CRYPTO_THREAD_lock_new();
  ptr[7] = iVar3;
  if (iVar3 == 0) {
    ERR_put_error(0x10,0xc4,0x41,"crypto/ec/ec_mult.c",0x41);
    CRYPTO_free(ptr);
    return 0;
  }
  pEVar4 = EC_GROUP_get0_generator(param_1);
  if (pEVar4 == (EC_POINT *)0x0) {
    ERR_put_error(0x10,0xbc,0x71,"crypto/ec/ec_mult.c",0x347);
    uVar7 = 0;
    pEVar11 = (EC_POINT *)0x0;
    local_4c = (BN_CTX *)0x0;
    local_48 = (EC_POINT *)0x0;
  }
  else {
    if (param_2 == (BN_CTX *)0x0) {
      param_2 = BN_CTX_new();
      local_4c = param_2;
      if (param_2 == (BN_CTX *)0x0) {
        uVar7 = 0;
        pEVar11 = (EC_POINT *)0x0;
        local_48 = (EC_POINT *)0x0;
        goto LAB_00129ebe;
      }
    }
    else {
      local_4c = (BN_CTX *)0x0;
    }
    BN_CTX_start(param_2);
    a = (BIGNUM *)EC_GROUP_get0_order(param_1);
    if (a == (BIGNUM *)0x0) {
      uVar7 = 0;
      pEVar11 = (EC_POINT *)0x0;
      local_48 = (EC_POINT *)0x0;
    }
    else {
      iVar3 = BN_is_zero();
      if (iVar3 == 0) {
        uVar5 = BN_num_bits(a);
        if (uVar5 < 800) {
          local_44 = 8;
          local_3c = 4;
        }
        else if (uVar5 < 2000) {
          local_44 = 0x10;
          local_3c = 5;
        }
        else {
          local_44 = 0x20;
          local_3c = 6;
        }
        uVar2 = local_44;
        uVar5 = uVar5 + 7 >> 3;
        num = local_44 * uVar5;
        points = (EC_POINT **)CRYPTO_malloc((num + 1) * 4,"crypto/ec/ec_mult.c",0x371);
        if (points != (EC_POINT **)0x0) {
          points[num] = (EC_POINT *)0x0;
          ppEVar8 = points + -1;
          iVar3 = 0;
          sVar1 = num;
          while (sVar1 != 0) {
            iVar3 = iVar3 + 1;
            pEVar11 = EC_POINT_new(param_1);
            ppEVar8 = ppEVar8 + 1;
            *ppEVar8 = pEVar11;
            if (pEVar11 == (EC_POINT *)0x0) {
              ERR_put_error(0x10,0xbc,0x41,"crypto/ec/ec_mult.c",0x37b);
              pEVar11 = (EC_POINT *)0x0;
              local_48 = (EC_POINT *)0x0;
              goto LAB_00129f7e;
            }
            sVar1 = num - iVar3;
          }
          pEVar11 = EC_POINT_new(param_1);
          if ((pEVar11 == (EC_POINT *)0x0) ||
             (local_48 = EC_POINT_new(param_1), local_48 == (EC_POINT *)0x0)) {
            ERR_put_error(0x10,0xbc,0x41,"crypto/ec/ec_mult.c",0x382);
            local_48 = (EC_POINT *)0x0;
          }
          else {
            iVar3 = EC_POINT_copy(local_48,pEVar4);
            if (iVar3 != 0) {
              if (uVar5 != 0) {
                local_44 = 0;
                ppEVar8 = points;
                do {
                  iVar3 = EC_POINT_dbl(param_1,pEVar11,local_48,param_2);
                  if (iVar3 == 0) goto LAB_00129f7e;
                  iVar3 = EC_POINT_copy(*ppEVar8,local_48);
                  if (iVar3 == 0) goto LAB_00129f7e;
                  ppEVar10 = ppEVar8 + uVar2;
                  ppEVar9 = ppEVar8 + 1;
                  do {
                    ppEVar8 = ppEVar9 + 1;
                    iVar3 = EC_POINT_add(param_1,*ppEVar9,pEVar11,ppEVar9[-1],param_2);
                    if (iVar3 == 0) goto LAB_00129f7e;
                    ppEVar9 = ppEVar8;
                  } while (ppEVar10 != ppEVar8);
                  if (local_44 < uVar5 - 1) {
                    iVar3 = EC_POINT_dbl(param_1,local_48,pEVar11,param_2);
                    if (iVar3 == 0) goto LAB_00129f7e;
                    iVar3 = 6;
                    do {
                      iVar6 = EC_POINT_dbl(param_1,local_48,local_48,param_2);
                      if (iVar6 == 0) goto LAB_00129f7e;
                      iVar3 = iVar3 + -1;
                    } while (iVar3 != 0);
                  }
                  local_44 = local_44 + 1;
                } while (uVar5 != local_44);
              }
              iVar3 = EC_POINTs_make_affine(param_1,num,points,param_2);
              if (iVar3 != 0) {
                uVar7 = 1;
                *ptr = param_1;
                ptr[2] = uVar5;
                ptr[3] = local_3c;
                ptr[4] = points;
                ptr[5] = num;
                ptr[1] = 8;
                *(undefined4 **)(param_1 + 100) = ptr;
                ptr = (undefined4 *)0x0;
                *(undefined4 *)(param_1 + 0x60) = 5;
                goto LAB_00129ebe;
              }
            }
          }
LAB_00129f7e:
          BN_CTX_end(param_2);
          BN_CTX_free(local_4c);
          EC_ec_pre_comp_free(ptr);
          pEVar4 = *points;
          ppEVar8 = points;
          while (pEVar4 != (EC_POINT *)0x0) {
            EC_POINT_free(pEVar4);
            ppEVar8 = ppEVar8 + 1;
            pEVar4 = *ppEVar8;
          }
          uVar7 = 0;
          CRYPTO_free(points);
          goto LAB_00129ed0;
        }
        ERR_put_error(0x10,0xbc,0x41,"crypto/ec/ec_mult.c",0x373);
        uVar7 = 0;
        pEVar11 = (EC_POINT *)0x0;
        local_48 = (EC_POINT *)0x0;
      }
      else {
        uVar7 = 0;
        pEVar11 = (EC_POINT *)0x0;
        ERR_put_error(0x10,0xbc,0x72,"crypto/ec/ec_mult.c",0x357);
        local_48 = (EC_POINT *)0x0;
      }
    }
  }
LAB_00129ebe:
  BN_CTX_end(param_2);
  BN_CTX_free(local_4c);
  EC_ec_pre_comp_free(ptr);
LAB_00129ed0:
  EC_POINT_free(pEVar11);
  EC_POINT_free(local_48);
  return uVar7;
}

