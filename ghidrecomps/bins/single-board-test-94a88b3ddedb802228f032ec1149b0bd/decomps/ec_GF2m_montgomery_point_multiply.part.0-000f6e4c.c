
undefined4
ec_GF2m_montgomery_point_multiply_part_0
          (int *param_1,EC_POINT *param_2,int *param_3,int param_4,BN_CTX *param_5)

{
  BIGNUM *pBVar1;
  BIGNUM *a;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  int iVar5;
  BIGNUM *a_00;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  BIGNUM *b;
  BIGNUM *a_01;
  uint local_48;
  int local_3c;
  int local_34;
  
  BN_CTX_start(param_5);
  pBVar1 = BN_CTX_get(param_5);
  a = BN_CTX_get(param_5);
  if (a != (BIGNUM *)0x0) {
    iVar5 = param_1[0x13];
    a_00 = (BIGNUM *)(param_2 + 4);
    a_01 = (BIGNUM *)(param_2 + 0x18);
    if (pBVar1->dmax < iVar5) {
      bn_expand2(pBVar1,iVar5);
      iVar5 = param_1[0x13];
      if (iVar5 <= a->dmax) goto LAB_000f6e8e;
LAB_000f6ecc:
      bn_expand2(a,iVar5);
      iVar5 = param_1[0x13];
      if (iVar5 <= *(int *)(param_2 + 0xc)) goto LAB_000f6e94;
LAB_000f6eda:
      bn_expand2(a_00,iVar5);
      iVar5 = param_1[0x13];
      if (*(int *)(param_2 + 0x20) < iVar5) goto LAB_000f6ee8;
    }
    else {
      if (a->dmax < iVar5) goto LAB_000f6ecc;
LAB_000f6e8e:
      if (*(int *)(param_2 + 0xc) < iVar5) goto LAB_000f6eda;
LAB_000f6e94:
      if (*(int *)(param_2 + 0x20) < iVar5) {
LAB_000f6ee8:
        bn_expand2(a_01,iVar5);
      }
    }
    b = (BIGNUM *)(param_4 + 4);
    iVar5 = BN_GF2m_mod_arr(pBVar1,b,param_1 + 0x17);
    if ((((iVar5 != 0) && (iVar5 = BN_set_word(a,1), iVar5 != 0)) &&
        (iVar5 = (**(code **)(*param_1 + 0x88))(param_1,a_01,pBVar1,param_5), iVar5 != 0)) &&
       (iVar5 = (**(code **)(*param_1 + 0x88))(param_1,a_00,a_01,param_5), iVar5 != 0)) {
      iVar5 = BN_GF2m_add(a_00,a_00);
      if (iVar5 != 0) {
        iVar5 = *param_3;
        local_3c = param_3[1] + -1;
        uVar6 = *(uint *)(iVar5 + local_3c * 4);
        if ((int)uVar6 < 0) {
          local_48 = 0x40000000;
        }
        else {
          uVar7 = 0x80000000;
          do {
            local_48 = uVar7;
            uVar7 = local_48 >> 1;
          } while ((uVar6 & uVar7) == 0);
          local_48 = local_48 >> 2;
          if (local_48 == 0) {
            local_3c = param_3[1] + -2;
            local_48 = 0x80000000;
          }
        }
        if (-1 < local_3c) {
          local_34 = local_3c << 2;
          while( true ) {
            uVar6 = *(uint *)(iVar5 + local_34);
            do {
              uVar7 = local_48 & uVar6;
              BN_consttime_swap(uVar7,pBVar1,a_00,param_1[0x13]);
              BN_consttime_swap(uVar7,a,a_01,param_1[0x13]);
              BN_CTX_start(param_5);
              pBVar2 = BN_CTX_get(param_5);
              pBVar3 = BN_CTX_get(param_5);
              if (((((pBVar3 == (BIGNUM *)0x0) ||
                    (pBVar4 = BN_copy(pBVar2,b), pBVar4 == (BIGNUM *)0x0)) ||
                   ((iVar5 = (**(code **)(*param_1 + 0x84))(param_1,a_00,a_00,a,param_5), iVar5 == 0
                    || ((iVar5 = (**(code **)(*param_1 + 0x84))(param_1,a_01,a_01,pBVar1,param_5),
                        iVar5 == 0 ||
                        (iVar5 = (**(code **)(*param_1 + 0x84))(param_1,pBVar3,a_00,a_01,param_5),
                        iVar5 == 0)))))) || (iVar5 = BN_GF2m_add(a_01,a_01,a_00), iVar5 == 0)) ||
                 (((iVar5 = (**(code **)(*param_1 + 0x88))(param_1,a_01,a_01,param_5), iVar5 == 0 ||
                   (iVar5 = (**(code **)(*param_1 + 0x84))(param_1,a_00,a_01,pBVar2,param_5),
                   iVar5 == 0)) || (iVar5 = BN_GF2m_add(a_00,a_00,pBVar3), iVar5 == 0))))
              goto LAB_000f6fe8;
              BN_CTX_end(param_5);
              BN_CTX_start(param_5);
              pBVar2 = BN_CTX_get(param_5);
              if ((((pBVar2 == (BIGNUM *)0x0) ||
                   (iVar5 = (**(code **)(*param_1 + 0x88))(param_1,pBVar1,pBVar1,param_5),
                   iVar5 == 0)) ||
                  ((iVar5 = (**(code **)(*param_1 + 0x88))(param_1,pBVar2,a,param_5), iVar5 == 0 ||
                   ((iVar5 = (**(code **)(*param_1 + 0x84))(param_1,a,pBVar1,pBVar2,param_5),
                    iVar5 == 0 ||
                    (iVar5 = (**(code **)(*param_1 + 0x88))(param_1,pBVar1,pBVar1,param_5),
                    iVar5 == 0)))))) ||
                 ((iVar5 = (**(code **)(*param_1 + 0x88))(param_1,pBVar2,pBVar2,param_5), iVar5 == 0
                  || ((iVar5 = (**(code **)(*param_1 + 0x84))
                                         (param_1,pBVar2,param_1 + 0x22,pBVar2,param_5), iVar5 == 0
                      || (iVar5 = BN_GF2m_add(pBVar1,pBVar1,pBVar2), iVar5 == 0))))))
              goto LAB_000f6fe8;
              BN_CTX_end(param_5);
              BN_consttime_swap(uVar7,pBVar1,a_00,param_1[0x13]);
              BN_consttime_swap(uVar7,a,a_01,param_1[0x13]);
              local_48 = local_48 >> 1;
            } while (local_48 != 0);
            local_3c = local_3c + -1;
            local_34 = local_34 + -4;
            if (local_3c == -1) break;
            local_48 = 0x80000000;
            iVar5 = *param_3;
          }
        }
        param_4 = param_4 + 0x18;
        if (a->top == 0) {
          BN_set_word(a_00,0);
          BN_set_word(a_01,0);
          iVar5 = EC_POINT_set_to_infinity((EC_GROUP *)param_1,param_2);
          if (iVar5 != 0) goto LAB_000f71bc;
        }
        else {
          if (*(int *)(param_2 + 0x1c) == 0) {
            pBVar1 = BN_copy(a_00,b);
            if ((pBVar1 == (BIGNUM *)0x0) || (iVar5 = BN_GF2m_add(a_01,b,param_4), iVar5 == 0))
            goto LAB_000f6eac;
          }
          else {
            BN_CTX_start(param_5);
            pBVar2 = BN_CTX_get(param_5);
            pBVar3 = BN_CTX_get(param_5);
            pBVar4 = BN_CTX_get(param_5);
            if ((((((pBVar4 == (BIGNUM *)0x0) || (iVar5 = BN_set_word(pBVar4,1), iVar5 == 0)) ||
                  (iVar5 = (**(code **)(*param_1 + 0x84))(param_1,pBVar2,a,a_01,param_5), iVar5 == 0
                  )) || (((iVar5 = (**(code **)(*param_1 + 0x84))(param_1,a,a,b,param_5), iVar5 == 0
                          || (iVar5 = BN_GF2m_add(a,a,pBVar1), iVar5 == 0)) ||
                         ((iVar5 = (**(code **)(*param_1 + 0x84))(param_1,a_01,a_01,b,param_5),
                          iVar5 == 0 ||
                          ((iVar5 = (**(code **)(*param_1 + 0x84))
                                              (param_1,pBVar1,a_01,pBVar1,param_5), iVar5 == 0 ||
                           (iVar5 = BN_GF2m_add(a_01,a_01,a_00), iVar5 == 0)))))))) ||
                ((iVar5 = (**(code **)(*param_1 + 0x84))(param_1,a_01,a_01,a,param_5), iVar5 == 0 ||
                 (((((iVar5 = (**(code **)(*param_1 + 0x88))(param_1,pBVar3,b,param_5), iVar5 == 0
                     || (iVar5 = BN_GF2m_add(pBVar3,pBVar3,param_4), iVar5 == 0)) ||
                    (iVar5 = (**(code **)(*param_1 + 0x84))(param_1,pBVar3,pBVar3,pBVar2,param_5),
                    iVar5 == 0)) ||
                   ((iVar5 = BN_GF2m_add(pBVar3,pBVar3,a_01), iVar5 == 0 ||
                    (iVar5 = (**(code **)(*param_1 + 0x84))(param_1,pBVar2,pBVar2,b,param_5),
                    iVar5 == 0)))) ||
                  ((iVar5 = (**(code **)(*param_1 + 0x8c))(param_1,pBVar2,pBVar4,pBVar2,param_5),
                   iVar5 == 0 ||
                   ((iVar5 = (**(code **)(*param_1 + 0x84))(param_1,pBVar3,pBVar2,pBVar3,param_5),
                    iVar5 == 0 ||
                    (iVar5 = (**(code **)(*param_1 + 0x84))(param_1,a_00,pBVar1,pBVar2,param_5),
                    iVar5 == 0)))))))))) ||
               ((iVar5 = BN_GF2m_add(a_01,a_00,b), iVar5 == 0 ||
                ((iVar5 = (**(code **)(*param_1 + 0x84))(param_1,a_01,a_01,pBVar3,param_5),
                 iVar5 == 0 || (iVar5 = BN_GF2m_add(a_01,a_01,param_4), iVar5 == 0)))))) {
LAB_000f6fe8:
              uVar8 = 0;
              BN_CTX_end(param_5);
              goto LAB_000f6eae;
            }
            BN_CTX_end(param_5);
          }
          iVar5 = BN_set_word((BIGNUM *)(param_2 + 0x2c),1);
          if (iVar5 != 0) {
            *(undefined4 *)(param_2 + 0x40) = 1;
LAB_000f71bc:
            BN_set_negative(a_00,0);
            uVar8 = 1;
            BN_set_negative(a_01,0);
            goto LAB_000f6eae;
          }
        }
      }
    }
  }
LAB_000f6eac:
  uVar8 = 0;
LAB_000f6eae:
  BN_CTX_end(param_5);
  return uVar8;
}

