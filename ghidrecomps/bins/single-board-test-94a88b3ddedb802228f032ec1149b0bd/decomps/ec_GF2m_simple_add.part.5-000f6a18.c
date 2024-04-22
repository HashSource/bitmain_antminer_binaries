
int ec_GF2m_simple_add_part_5
              (int *param_1,EC_POINT *param_2,int param_3,int param_4,BN_CTX *param_5)

{
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *b;
  BIGNUM *a_01;
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  int iVar5;
  BIGNUM *pBVar6;
  BN_CTX *c;
  
  if (param_5 == (BN_CTX *)0x0) {
    param_5 = BN_CTX_new();
    c = param_5;
    if (param_5 == (BN_CTX *)0x0) {
      return 0;
    }
  }
  else {
    c = (BN_CTX *)0x0;
  }
  BN_CTX_start(param_5);
  a = BN_CTX_get(param_5);
  a_00 = BN_CTX_get(param_5);
  b = BN_CTX_get(param_5);
  a_01 = BN_CTX_get(param_5);
  pBVar1 = BN_CTX_get(param_5);
  pBVar2 = BN_CTX_get(param_5);
  pBVar3 = BN_CTX_get(param_5);
  pBVar4 = BN_CTX_get(param_5);
  if (pBVar4 != (BIGNUM *)0x0) {
    if (*(int *)(param_3 + 0x40) == 0) {
      iVar5 = EC_POINT_get_affine_coordinates_GF2m(param_1,param_3,a,a_00,param_5);
      if (iVar5 != 0) {
        if (*(int *)(param_4 + 0x40) == 0) goto LAB_000f6b2a;
LAB_000f6a9a:
        pBVar6 = BN_copy(b,(BIGNUM *)(param_4 + 4));
        if ((pBVar6 != (BIGNUM *)0x0) &&
           (pBVar6 = BN_copy(a_01,(BIGNUM *)(param_4 + 0x18)), pBVar6 != (BIGNUM *)0x0)) {
          iVar5 = BN_ucmp(a,b);
joined_r0x000f6b46:
          if (iVar5 == 0) {
            iVar5 = BN_ucmp(a_00,a_01);
            if ((iVar5 != 0) || (b->top == 0)) {
              iVar5 = EC_POINT_set_to_infinity((EC_GROUP *)param_1,param_2);
              if (iVar5 != 0) {
                iVar5 = 1;
              }
              goto LAB_000f6af0;
            }
            iVar5 = (**(code **)(*param_1 + 0x8c))(param_1,pBVar3,a_01,b,param_5);
            if ((iVar5 != 0) &&
               (((iVar5 = BN_GF2m_add(pBVar3,pBVar3,b), iVar5 != 0 &&
                 (iVar5 = (**(code **)(*param_1 + 0x88))(param_1,pBVar1,pBVar3,param_5), iVar5 != 0)
                 ) && (iVar5 = BN_GF2m_add(pBVar1,pBVar1,pBVar3), iVar5 != 0)))) {
              iVar5 = BN_GF2m_add(pBVar1,pBVar1,param_1 + 0x1d);
              goto joined_r0x000f6bc2;
            }
          }
          else {
            iVar5 = BN_GF2m_add(pBVar4,a,b);
            if (((((iVar5 != 0) && (iVar5 = BN_GF2m_add(pBVar3,a_00,a_01), iVar5 != 0)) &&
                 (iVar5 = (**(code **)(*param_1 + 0x8c))(param_1,pBVar3,pBVar3,pBVar4,param_5),
                 iVar5 != 0)) &&
                ((iVar5 = (**(code **)(*param_1 + 0x88))(param_1,pBVar1,pBVar3,param_5), iVar5 != 0
                 && (iVar5 = BN_GF2m_add(pBVar1,pBVar1,param_1 + 0x1d), iVar5 != 0)))) &&
               (iVar5 = BN_GF2m_add(pBVar1,pBVar1,pBVar3), iVar5 != 0)) {
              iVar5 = BN_GF2m_add(pBVar1,pBVar1,pBVar4);
joined_r0x000f6bc2:
              if (((iVar5 != 0) && (iVar5 = BN_GF2m_add(pBVar2,b,pBVar1), iVar5 != 0)) &&
                 ((iVar5 = (**(code **)(*param_1 + 0x84))(param_1,pBVar2,pBVar2,pBVar3,param_5),
                  iVar5 != 0 &&
                  ((iVar5 = BN_GF2m_add(pBVar2,pBVar2,pBVar1), iVar5 != 0 &&
                   (iVar5 = BN_GF2m_add(pBVar2,pBVar2,a_01), iVar5 != 0)))))) {
                iVar5 = EC_POINT_set_affine_coordinates_GF2m(param_1,param_2,pBVar1,pBVar2,param_5);
                if (iVar5 != 0) {
                  iVar5 = 1;
                }
                goto LAB_000f6af0;
              }
            }
          }
        }
      }
    }
    else {
      pBVar6 = BN_copy(a,(BIGNUM *)(param_3 + 4));
      if ((pBVar6 != (BIGNUM *)0x0) &&
         (pBVar6 = BN_copy(a_00,(BIGNUM *)(param_3 + 0x18)), pBVar6 != (BIGNUM *)0x0)) {
        if (*(int *)(param_4 + 0x40) != 0) goto LAB_000f6a9a;
LAB_000f6b2a:
        iVar5 = EC_POINT_get_affine_coordinates_GF2m(param_1,param_4,b,a_01,param_5);
        if (iVar5 != 0) {
          iVar5 = BN_ucmp(a,b);
          goto joined_r0x000f6b46;
        }
      }
    }
  }
  iVar5 = 0;
LAB_000f6af0:
  BN_CTX_end(param_5);
  if (c != (BN_CTX *)0x0) {
    BN_CTX_free(c);
  }
  return iVar5;
}

