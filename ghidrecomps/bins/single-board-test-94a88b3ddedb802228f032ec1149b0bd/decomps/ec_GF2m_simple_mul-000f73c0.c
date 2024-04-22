
int ec_GF2m_simple_mul(int *param_1,EC_POINT *param_2,int param_3,uint param_4,EC_POINT **param_5,
                      int *param_6,BN_CTX *param_7)

{
  int *piVar1;
  int iVar2;
  EC_POINT *point;
  EC_POINT *point_00;
  int iVar3;
  EC_POINT *pEVar4;
  int *piVar5;
  BN_CTX *c;
  
  c = (BN_CTX *)0x0;
  if ((param_7 == (BN_CTX *)0x0) && (param_7 = BN_CTX_new(), c = param_7, param_7 == (BN_CTX *)0x0))
  {
    return 0;
  }
  iVar3 = param_3;
  if (param_3 != 0) {
    iVar3 = 1;
  }
  if ((((param_3 == 0 || param_4 != 0) && (param_3 != 0 && param_4 != 1)) || (2 < param_4)) ||
     ((param_4 == 0 && (iVar2 = EC_GROUP_have_precompute_mult((EC_GROUP *)param_1), iVar2 != 0)))) {
    iVar2 = ec_wNAF_mul(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    goto LAB_000f7406;
  }
  point = EC_POINT_new((EC_GROUP *)param_1);
  if (point == (EC_POINT *)0x0) {
    iVar2 = 0;
    goto LAB_000f7406;
  }
  point_00 = EC_POINT_new((EC_GROUP *)param_1);
  if (point_00 == (EC_POINT *)0x0) {
    EC_POINT_free(point);
    iVar2 = 0;
    goto LAB_000f7406;
  }
  iVar2 = EC_POINT_set_to_infinity((EC_GROUP *)param_1,point_00);
  if (iVar2 != 0) {
    if (iVar3 == 0) {
LAB_000f74e8:
      if (param_4 == 0) {
LAB_000f75aa:
        iVar2 = EC_POINT_copy(param_2,point_00);
        if (iVar2 != 0) {
          iVar2 = 1;
        }
        goto LAB_000f7482;
      }
      pEVar4 = *param_5;
      iVar3 = *param_6;
      if (point != pEVar4) {
        piVar1 = param_6;
        do {
          piVar5 = piVar1 + 1;
          if (((iVar3 == 0) || (*(int *)(iVar3 + 4) == 0)) ||
             ((pEVar4 == (EC_POINT *)0x0 ||
              (iVar2 = EC_POINT_is_at_infinity((EC_GROUP *)param_1,pEVar4), iVar2 != 0)))) {
            iVar2 = EC_POINT_set_to_infinity((EC_GROUP *)param_1,point);
          }
          else {
            if (*(int *)(pEVar4 + 0x40) == 0) goto LAB_000f7476;
            iVar2 = ec_GF2m_montgomery_point_multiply_part_0(param_1,point,iVar3,pEVar4,param_7);
          }
          if ((iVar2 == 0) ||
             (((*(int *)(*piVar1 + 0xc) != 0 &&
               (iVar2 = (**(code **)(*param_1 + 0x60))(param_1,point,param_7), iVar2 == 0)) ||
              (iVar2 = (**(code **)(*param_1 + 0x58))(param_1,point_00,point_00,point,param_7),
              iVar2 == 0)))) goto LAB_000f7482;
          if (piVar5 == param_6 + param_4) goto LAB_000f75aa;
          param_5 = param_5 + 1;
          pEVar4 = *param_5;
          iVar3 = *piVar5;
          piVar1 = piVar5;
        } while (point != pEVar4);
      }
LAB_000f757a:
      ERR_put_error(0x10,0xd0,0x70,DAT_000f75c0,0x112);
    }
    else {
      pEVar4 = (EC_POINT *)param_1[1];
      if (point == pEVar4) goto LAB_000f757a;
      if (((*(int *)(param_3 + 4) == 0) || (pEVar4 == (EC_POINT *)0x0)) ||
         (iVar3 = EC_POINT_is_at_infinity((EC_GROUP *)param_1,pEVar4), iVar3 != 0)) {
        iVar2 = EC_POINT_set_to_infinity((EC_GROUP *)param_1,point);
LAB_000f74b6:
        if (((iVar2 == 0) ||
            ((*(int *)(param_3 + 0xc) != 0 &&
             (iVar2 = (**(code **)(*param_1 + 0x60))(param_1,point,param_7), iVar2 == 0)))) ||
           (iVar2 = (**(code **)(*param_1 + 0x58))(param_1,point_00,point_00,point,param_7),
           iVar2 == 0)) goto LAB_000f7482;
        goto LAB_000f74e8;
      }
      if (*(int *)(pEVar4 + 0x40) != 0) {
        iVar2 = ec_GF2m_montgomery_point_multiply_part_0(param_1,point,param_3,pEVar4,param_7);
        goto LAB_000f74b6;
      }
    }
LAB_000f7476:
    iVar2 = 0;
  }
LAB_000f7482:
  EC_POINT_free(point);
  EC_POINT_free(point_00);
LAB_000f7406:
  if (c != (BN_CTX *)0x0) {
    BN_CTX_free(c);
  }
  return iVar2;
}

