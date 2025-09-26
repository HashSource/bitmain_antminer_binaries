
int ec_GF2m_simple_ladder_post
              (EC_GROUP *param_1,EC_POINT *param_2,int param_3,EC_POINT *param_4,BN_CTX *param_5)

{
  int iVar1;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  
  iVar1 = BN_is_zero(*(undefined4 *)(param_2 + 0x10));
  if (iVar1 != 0) {
    iVar1 = EC_POINT_set_to_infinity(param_1,param_2);
    return iVar1;
  }
  iVar1 = BN_is_zero(*(undefined4 *)(param_3 + 0x10));
  if (iVar1 == 0) {
    BN_CTX_start(param_5);
    pBVar2 = BN_CTX_get(param_5);
    pBVar3 = BN_CTX_get(param_5);
    pBVar4 = BN_CTX_get(param_5);
    if (pBVar4 == (BIGNUM *)0x0) {
      ERR_put_error(0x10,0x11d,0x41,"crypto/ec/ec2_smpl.c",0x31c);
      iVar1 = 0;
    }
    else {
      iVar1 = (**(code **)(*(int *)param_1 + 0x88))
                        (param_1,pBVar2,*(undefined4 *)(param_2 + 0x10),
                         *(undefined4 *)(param_3 + 0x10),param_5);
      if (((((((iVar1 == 0) ||
              (iVar1 = (**(code **)(*(int *)param_1 + 0x88))
                                 (param_1,pBVar3,*(undefined4 *)(param_4 + 8),
                                  *(undefined4 *)(param_2 + 0x10),param_5), iVar1 == 0)) ||
             (iVar1 = BN_GF2m_add(pBVar3,*(undefined4 *)(param_2 + 8)), iVar1 == 0)) ||
            ((iVar1 = (**(code **)(*(int *)param_1 + 0x88))
                                (param_1,pBVar4,*(undefined4 *)(param_4 + 8),
                                 *(undefined4 *)(param_3 + 0x10),param_5), iVar1 == 0 ||
             (iVar1 = (**(code **)(*(int *)param_1 + 0x88))
                                (param_1,*(undefined4 *)(param_2 + 0x10),
                                 *(undefined4 *)(param_2 + 8),pBVar4,param_5), iVar1 == 0)))) ||
           ((iVar1 = BN_GF2m_add(pBVar4,pBVar4,*(undefined4 *)(param_3 + 8)), iVar1 == 0 ||
            ((iVar1 = (**(code **)(*(int *)param_1 + 0x88))(param_1,pBVar3,pBVar3,pBVar4,param_5),
             iVar1 == 0 ||
             (iVar1 = (**(code **)(*(int *)param_1 + 0x8c))
                                (param_1,pBVar4,*(undefined4 *)(param_4 + 8),param_5), iVar1 == 0)))
            ))) || (iVar1 = BN_GF2m_add(pBVar4,*(undefined4 *)(param_4 + 0xc),pBVar4), iVar1 == 0))
         || (((((iVar1 = (**(code **)(*(int *)param_1 + 0x88))(param_1,pBVar4,pBVar4,pBVar2,param_5)
                , iVar1 == 0 || (iVar1 = BN_GF2m_add(pBVar3,pBVar4), iVar1 == 0)) ||
               (iVar1 = (**(code **)(*(int *)param_1 + 0x88))
                                  (param_1,pBVar4,*(undefined4 *)(param_4 + 8),pBVar2,param_5),
               iVar1 == 0)) ||
              (((iVar1 = (**(code **)(*(int *)param_1 + 0x94))(param_1,pBVar4,pBVar4,param_5),
                iVar1 == 0 ||
                (iVar1 = (**(code **)(*(int *)param_1 + 0x88))(param_1,pBVar3,pBVar3,pBVar4,param_5)
                , iVar1 == 0)) ||
               ((iVar1 = (**(code **)(*(int *)param_1 + 0x88))
                                   (param_1,*(undefined4 *)(param_2 + 8),
                                    *(undefined4 *)(param_2 + 0x10),pBVar4,param_5), iVar1 == 0 ||
                ((iVar1 = BN_GF2m_add(pBVar4,*(undefined4 *)(param_4 + 8),
                                      *(undefined4 *)(param_2 + 8)), iVar1 == 0 ||
                 (iVar1 = (**(code **)(*(int *)param_1 + 0x88))
                                    (param_1,pBVar4,pBVar4,pBVar3,param_5), iVar1 == 0)))))))) ||
             ((iVar1 = BN_GF2m_add(*(undefined4 *)(param_2 + 0xc),*(undefined4 *)(param_4 + 0xc),
                                   pBVar4), iVar1 == 0 ||
              (iVar1 = BN_set_word(*(BIGNUM **)(param_2 + 0x10),1), iVar1 == 0)))))) {
        iVar1 = 0;
      }
      else {
        iVar1 = 1;
        *(undefined4 *)(param_2 + 0x14) = 1;
        BN_set_negative(*(BIGNUM **)(param_2 + 8),0);
        BN_set_negative(*(BIGNUM **)(param_2 + 0xc),0);
      }
    }
    BN_CTX_end(param_5);
    return iVar1;
  }
  iVar1 = EC_POINT_copy(param_2,param_4);
  if ((iVar1 != 0) && (iVar1 = EC_POINT_invert(param_1,param_2,param_5), iVar1 != 0)) {
    return 1;
  }
  ERR_put_error(0x10,0x11d,0x10,"crypto/ec/ec2_smpl.c",0x311);
  return 0;
}

