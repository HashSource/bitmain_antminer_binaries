
int ec_scalar_mul_ladder
              (EC_GROUP *param_1,EC_POINT *param_2,BIGNUM *param_3,EC_POINT *param_4,BN_CTX *param_5
              )

{
  int iVar1;
  EC_POINT *dst;
  EC_POINT *dst_00;
  BIGNUM *r;
  BIGNUM *r_00;
  BIGNUM *a;
  int iVar2;
  int iVar3;
  BIGNUM *pBVar4;
  undefined4 uVar5;
  uint uVar6;
  code *pcVar7;
  uint local_34;
  
  if ((param_4 != (EC_POINT *)0x0) && (iVar1 = EC_POINT_is_at_infinity(param_1,param_4), iVar1 != 0)
     ) {
    iVar1 = EC_POINT_set_to_infinity(param_1,param_2);
    return iVar1;
  }
  iVar1 = BN_is_zero(*(undefined4 *)(param_1 + 8));
  if (iVar1 != 0) {
    ERR_put_error(0x10,0x11c,0x72,"crypto/ec/ec_mult.c",0x9c);
    return 0;
  }
  iVar1 = BN_is_zero(*(undefined4 *)(param_1 + 0xc));
  if (iVar1 != 0) {
    ERR_put_error(0x10,0x11c,0xa4,"crypto/ec/ec_mult.c",0xa0);
    return 0;
  }
  BN_CTX_start(param_5);
  dst = EC_POINT_new(param_1);
  if ((dst == (EC_POINT *)0x0) || (dst_00 = EC_POINT_new(param_1), dst_00 == (EC_POINT *)0x0)) {
    iVar1 = 0;
    ERR_put_error(0x10,0x11c,0x41,"crypto/ec/ec_mult.c",0xa8);
    dst_00 = (EC_POINT *)0x0;
    goto LAB_00128fe0;
  }
  if (param_4 == (EC_POINT *)0x0) {
    iVar1 = EC_POINT_copy(dst,*(EC_POINT **)(param_1 + 4));
    if (iVar1 == 0) {
      ERR_put_error(0x10,0x11c,0x10,"crypto/ec/ec_mult.c",0xae);
      iVar1 = 0;
      goto LAB_00128fe0;
    }
  }
  else {
    iVar1 = EC_POINT_copy(dst,param_4);
    if (iVar1 == 0) {
      ERR_put_error(0x10,0x11c,0x10,"crypto/ec/ec_mult.c",0xb3);
      iVar1 = 0;
      goto LAB_00128fe0;
    }
  }
  BN_set_flags(*(undefined4 *)(dst + 8),4);
  BN_set_flags(*(undefined4 *)(dst + 0xc),4);
  BN_set_flags(*(undefined4 *)(dst + 0x10),4);
  BN_set_flags(*(undefined4 *)(param_2 + 8),4);
  BN_set_flags(*(undefined4 *)(param_2 + 0xc),4);
  BN_set_flags(*(undefined4 *)(param_2 + 0x10),4);
  BN_set_flags(*(undefined4 *)(dst_00 + 8),4);
  BN_set_flags(*(undefined4 *)(dst_00 + 0xc),4);
  BN_set_flags(*(undefined4 *)(dst_00 + 0x10),4);
  r = BN_CTX_get(param_5);
  r_00 = BN_CTX_get(param_5);
  a = BN_CTX_get(param_5);
  if (a == (BIGNUM *)0x0) {
    ERR_put_error(0x10,0x11c,0x41,"crypto/ec/ec_mult.c",0xc0);
    iVar1 = 0;
    goto LAB_00128fe0;
  }
  iVar1 = BN_mul(r,*(BIGNUM **)(param_1 + 8),*(BIGNUM **)(param_1 + 0xc),param_5);
  if (iVar1 == 0) {
    ERR_put_error(0x10,0x11c,3,"crypto/ec/ec_mult.c",0xc5);
    iVar1 = 0;
    goto LAB_00128fe0;
  }
  iVar1 = BN_num_bits(r);
  iVar2 = bn_get_top(r);
  iVar2 = iVar2 + 2;
  iVar3 = bn_wexpand(a,iVar2);
  if ((iVar3 == 0) || (iVar3 = bn_wexpand(r_00,iVar2), iVar3 == 0)) {
    iVar1 = 0xd3;
LAB_00129134:
    ERR_put_error(0x10,0x11c,3,"crypto/ec/ec_mult.c",iVar1);
    iVar1 = 0;
    goto LAB_00128fe0;
  }
  pBVar4 = BN_copy(a,param_3);
  if (pBVar4 == (BIGNUM *)0x0) {
    iVar2 = 0xd8;
  }
  else {
    BN_set_flags(a,4);
    iVar3 = BN_num_bits(a);
    if (((iVar1 < iVar3) || (iVar3 = BN_is_negative(a), iVar3 != 0)) &&
       (iVar3 = BN_nnmod(a,a,r,param_5), iVar3 == 0)) {
      iVar2 = 0xe4;
    }
    else {
      iVar3 = BN_add(r_00,a,r);
      if (iVar3 != 0) {
        BN_set_flags(r_00,4);
        iVar3 = BN_add(a,r_00,r);
        if (iVar3 == 0) {
          ERR_put_error(0x10,0x11c,3,"crypto/ec/ec_mult.c",0xef);
          iVar1 = 0;
          goto LAB_00128fe0;
        }
        iVar3 = BN_is_bit_set(r_00,iVar1);
        BN_consttime_swap(iVar3,a,r_00,iVar2);
        uVar5 = bn_get_top(*(undefined4 *)(param_1 + 0x28));
        iVar2 = bn_wexpand(*(undefined4 *)(dst_00 + 8),uVar5);
        if (((((iVar2 == 0) || (iVar2 = bn_wexpand(*(undefined4 *)(dst_00 + 0xc),uVar5), iVar2 == 0)
              ) || ((iVar2 = bn_wexpand(*(undefined4 *)(dst_00 + 0x10),uVar5), iVar2 == 0 ||
                    ((iVar2 = bn_wexpand(*(undefined4 *)(param_2 + 8),uVar5), iVar2 == 0 ||
                     (iVar2 = bn_wexpand(*(undefined4 *)(param_2 + 0xc),uVar5), iVar2 == 0)))))) ||
            (iVar2 = bn_wexpand(*(undefined4 *)(param_2 + 0x10),uVar5), iVar2 == 0)) ||
           (((iVar2 = bn_wexpand(*(undefined4 *)(dst + 8),uVar5), iVar2 == 0 ||
             (iVar2 = bn_wexpand(*(undefined4 *)(dst + 0xc),uVar5), iVar2 == 0)) ||
            (iVar2 = bn_wexpand(*(undefined4 *)(dst + 0x10),uVar5), iVar2 == 0)))) {
          iVar1 = 0x103;
          goto LAB_00129134;
        }
        if ((*(int *)(dst + 0x14) == 0) &&
           (iVar2 = EC_POINT_make_affine(param_1,dst,param_5), iVar2 == 0)) {
          ERR_put_error(0x10,0x11c,0x10,"crypto/ec/ec_mult.c",0x109);
          iVar1 = 0;
          goto LAB_00128fe0;
        }
        if (*(code **)(*(int *)param_1 + 0xd0) == (code *)0x0) {
          iVar2 = EC_POINT_copy(dst_00,dst);
          if (iVar2 != 0) {
            iVar2 = EC_POINT_dbl(param_1,param_2,dst_00,param_5);
            goto joined_r0x0012943c;
          }
        }
        else {
          iVar2 = (**(code **)(*(int *)param_1 + 0xd0))(param_1,param_2,dst_00,dst,param_5);
joined_r0x0012943c:
          if (iVar2 != 0) {
            iVar1 = iVar1 + -1;
            if (iVar1 < 0) {
              local_34 = 1;
            }
            else {
              local_34 = 1;
              do {
                uVar6 = BN_is_bit_set(a,iVar1);
                iVar1 = iVar1 + -1;
                local_34 = uVar6 ^ local_34;
                BN_consttime_swap(local_34,*(undefined4 *)(param_2 + 8),*(undefined4 *)(dst_00 + 8),
                                  uVar5);
                BN_consttime_swap(local_34,*(undefined4 *)(param_2 + 0xc),
                                  *(undefined4 *)(dst_00 + 0xc),uVar5);
                BN_consttime_swap(local_34,*(undefined4 *)(param_2 + 0x10),
                                  *(undefined4 *)(dst_00 + 0x10),uVar5);
                local_34 = (*(uint *)(param_2 + 0x14) ^ *(uint *)(dst_00 + 0x14)) & local_34;
                pcVar7 = *(code **)(*(int *)param_1 + 0xd4);
                *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) ^ local_34;
                *(uint *)(dst_00 + 0x14) = *(uint *)(dst_00 + 0x14) ^ local_34;
                if (pcVar7 == (code *)0x0) {
                  iVar2 = EC_POINT_add(param_1,dst_00,param_2,dst_00,param_5);
                  if (iVar2 != 0) {
                    iVar2 = EC_POINT_dbl(param_1,param_2,param_2,param_5);
                    goto joined_r0x00129292;
                  }
LAB_00129328:
                  iVar1 = 0;
                  ERR_put_error(0x10,0x11c,0xa2,"crypto/ec/ec_mult.c",0x15f);
                  goto LAB_00128fe0;
                }
                iVar2 = (*pcVar7)(param_1,param_2,dst_00,dst);
joined_r0x00129292:
                if (iVar2 == 0) goto LAB_00129328;
                local_34 = uVar6;
              } while (iVar1 != -1);
            }
            BN_consttime_swap(local_34,*(undefined4 *)(param_2 + 8),*(undefined4 *)(dst_00 + 8),
                              uVar5);
            BN_consttime_swap(local_34,*(undefined4 *)(param_2 + 0xc),*(undefined4 *)(dst_00 + 0xc),
                              uVar5);
            BN_consttime_swap(local_34,*(undefined4 *)(param_2 + 0x10),
                              *(undefined4 *)(dst_00 + 0x10),uVar5);
            local_34 = (*(uint *)(dst_00 + 0x14) ^ *(uint *)(param_2 + 0x14)) & local_34;
            pcVar7 = *(code **)(*(int *)param_1 + 0xd8);
            *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) ^ local_34;
            *(uint *)(dst_00 + 0x14) = local_34 ^ *(uint *)(dst_00 + 0x14);
            if ((pcVar7 == (code *)0x0) ||
               (iVar1 = (*pcVar7)(param_1,param_2,dst_00,dst,param_5), iVar1 != 0)) {
              iVar1 = 1;
            }
            else {
              ERR_put_error(0x10,0x11c,0x88,"crypto/ec/ec_mult.c",0x16e);
              iVar1 = 0;
            }
            goto LAB_00128fe0;
          }
        }
        iVar1 = 0;
        ERR_put_error(0x10,0x11c,0x99,"crypto/ec/ec_mult.c",0x10f);
        goto LAB_00128fe0;
      }
      iVar2 = 0xea;
    }
  }
  iVar1 = 0;
  ERR_put_error(0x10,0x11c,3,"crypto/ec/ec_mult.c",iVar2);
LAB_00128fe0:
  EC_POINT_free(dst);
  EC_POINT_clear_free(dst_00);
  BN_CTX_end(param_5);
  return iVar1;
}

