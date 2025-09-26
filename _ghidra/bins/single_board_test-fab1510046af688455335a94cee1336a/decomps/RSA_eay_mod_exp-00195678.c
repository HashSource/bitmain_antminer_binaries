
int RSA_eay_mod_exp(BIGNUM *param_1,BIGNUM *param_2,int param_3,BN_CTX *param_4)

{
  BIGNUM *pBVar1;
  BIGNUM *b;
  BIGNUM *r;
  uint uVar2;
  int iVar3;
  BN_MONT_CTX *pBVar4;
  BIGNUM *pBVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  BIGNUM *mod;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  uint local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  uint local_68;
  BIGNUM local_64;
  BIGNUM local_50;
  BIGNUM local_3c;
  
  BN_CTX_start(param_4);
  pBVar1 = BN_CTX_get(param_4);
  b = BN_CTX_get(param_4);
  r = BN_CTX_get(param_4);
  uVar2 = *(uint *)(param_3 + 0x3c);
  if ((int)(uVar2 << 0x17) < 0) {
    pBVar5 = *(BIGNUM **)(param_3 + 0x1c);
    mod = *(BIGNUM **)(param_3 + 0x20);
  }
  else {
    mod = &local_3c;
    BN_init(&local_50);
    puVar7 = *(undefined4 **)(param_3 + 0x1c);
    local_50.top = puVar7[1];
    local_50.d = (ulong *)*puVar7;
    local_50.dmax = puVar7[2];
    local_50.neg = puVar7[3];
    local_50.flags = local_50.flags & 1U | puVar7[4] & 0xfffffffe | 6;
    BN_init(&local_3c);
    puVar7 = *(undefined4 **)(param_3 + 0x20);
    pBVar5 = &local_50;
    uVar2 = *(uint *)(param_3 + 0x3c);
    local_3c.top = puVar7[1];
    local_3c.d = (ulong *)*puVar7;
    local_3c.dmax = puVar7[2];
    local_3c.neg = puVar7[3];
    local_3c.flags = local_3c.flags & 1U | puVar7[4] & 0xfffffffe | 6;
  }
  if ((int)(uVar2 << 0x1d) < 0) {
    pBVar4 = BN_MONT_CTX_set_locked((BN_MONT_CTX **)(param_3 + 0x44),9,pBVar5,param_4);
    if ((pBVar4 != (BN_MONT_CTX *)0x0) &&
       (pBVar4 = BN_MONT_CTX_set_locked((BN_MONT_CTX **)(param_3 + 0x48),9,mod,param_4),
       pBVar4 != (BN_MONT_CTX *)0x0)) {
      uVar2 = *(uint *)(param_3 + 0x3c);
      goto joined_r0x00195966;
    }
  }
  else {
joined_r0x00195966:
    if ((int)(uVar2 << 0x1e) < 0) {
      pBVar4 = BN_MONT_CTX_set_locked
                         ((BN_MONT_CTX **)(param_3 + 0x40),9,*(BIGNUM **)(param_3 + 0x10),param_4);
      if (pBVar4 == (BN_MONT_CTX *)0x0) goto LAB_00195930;
      uVar2 = *(uint *)(param_3 + 0x3c);
    }
    if ((uVar2 & 0x100) == 0) {
      local_64.d = param_2->d;
      local_64.flags = local_64.flags & 1U | param_2->flags & 0xfffffffeU | 6;
      local_64.top = param_2->top;
      local_64.dmax = param_2->dmax;
      local_64.neg = param_2->neg;
      iVar3 = BN_div((BIGNUM *)0x0,pBVar1,&local_64,*(BIGNUM **)(param_3 + 0x20),param_4);
    }
    else {
      iVar3 = BN_div((BIGNUM *)0x0,pBVar1,param_2,*(BIGNUM **)(param_3 + 0x20),param_4);
    }
    if (iVar3 != 0) {
      if (*(int *)(param_3 + 0x3c) << 0x17 < 0) {
        puVar7 = *(undefined4 **)(param_3 + 0x28);
      }
      else {
        puVar6 = *(undefined4 **)(param_3 + 0x28);
        puVar7 = &local_78;
        local_78 = *puVar6;
        local_70 = puVar6[2];
        local_74 = puVar6[1];
        local_6c = puVar6[3];
        local_68 = local_68 & 1 | puVar6[4] & 0xfffffffe | 6;
      }
      iVar3 = (**(code **)(*(int *)(param_3 + 8) + 0x18))
                        (b,pBVar1,puVar7,*(undefined4 *)(param_3 + 0x20),param_4,
                         *(undefined4 *)(param_3 + 0x48));
      if (iVar3 != 0) {
        if ((*(uint *)(param_3 + 0x3c) & 0x100) == 0) {
          local_64.d = param_2->d;
          local_64.top = param_2->top;
          local_64.flags = local_64.flags & 1U | param_2->flags & 0xfffffffeU | 6;
          local_64.dmax = param_2->dmax;
          local_64.neg = param_2->neg;
          iVar3 = BN_div((BIGNUM *)0x0,pBVar1,&local_64,*(BIGNUM **)(param_3 + 0x1c),param_4);
          if (iVar3 != 0) {
            if (*(int *)(param_3 + 0x3c) << 0x17 < 0) goto LAB_00195a2a;
LAB_00195750:
            puVar6 = *(undefined4 **)(param_3 + 0x24);
            puVar7 = &local_8c;
            local_8c = *puVar6;
            local_84 = puVar6[2];
            local_88 = puVar6[1];
            local_80 = puVar6[3];
            local_7c = local_7c & 1 | puVar6[4] & 0xfffffffe | 6;
            goto LAB_0019577a;
          }
        }
        else {
          iVar3 = BN_div((BIGNUM *)0x0,pBVar1,param_2,*(BIGNUM **)(param_3 + 0x1c),param_4);
          if (iVar3 != 0) {
            if (-1 < *(int *)(param_3 + 0x3c) << 0x17) goto LAB_00195750;
LAB_00195a2a:
            puVar7 = *(undefined4 **)(param_3 + 0x24);
LAB_0019577a:
            iVar3 = (**(code **)(*(int *)(param_3 + 8) + 0x18))
                              (param_1,pBVar1,puVar7,*(undefined4 *)(param_3 + 0x1c),param_4,
                               *(undefined4 *)(param_3 + 0x44));
            if ((((iVar3 != 0) && (iVar3 = BN_sub(param_1,param_1,b), iVar3 != 0)) &&
                ((param_1->neg == 0 ||
                 (iVar3 = BN_add(param_1,param_1,*(BIGNUM **)(param_3 + 0x1c)), iVar3 != 0)))) &&
               (iVar3 = BN_mul(pBVar1,param_1,*(BIGNUM **)(param_3 + 0x2c),param_4), iVar3 != 0)) {
              pBVar5 = pBVar1;
              if (-1 < *(int *)(param_3 + 0x3c) << 0x17) {
                local_50.d = pBVar1->d;
                local_50.dmax = pBVar1->dmax;
                local_50.neg = pBVar1->neg;
                local_50.top = pBVar1->top;
                local_50.flags = local_50.flags & 1U | pBVar1->flags & 0xfffffffeU | 6;
                pBVar5 = &local_50;
              }
              iVar3 = BN_div((BIGNUM *)0x0,param_1,pBVar5,*(BIGNUM **)(param_3 + 0x1c),param_4);
              if ((iVar3 != 0) &&
                 ((((param_1->neg == 0 ||
                    (iVar3 = BN_add(param_1,param_1,*(BIGNUM **)(param_3 + 0x1c)), iVar3 != 0)) &&
                   (iVar3 = BN_mul(pBVar1,param_1,*(BIGNUM **)(param_3 + 0x20),param_4), iVar3 != 0)
                   ) && (iVar3 = BN_add(param_1,pBVar1,b), iVar3 != 0)))) {
                if ((*(int *)(param_3 + 0x14) != 0) && (*(int *)(param_3 + 0x10) != 0)) {
                  iVar3 = (**(code **)(*(int *)(param_3 + 8) + 0x18))
                                    (r,param_1,*(int *)(param_3 + 0x14),*(int *)(param_3 + 0x10),
                                     param_4,*(undefined4 *)(param_3 + 0x40));
                  if ((iVar3 == 0) ||
                     (((iVar3 = BN_sub(r,r,param_2), iVar3 == 0 ||
                       (iVar3 = BN_div((BIGNUM *)0x0,r,r,*(BIGNUM **)(param_3 + 0x10),param_4),
                       iVar3 == 0)) ||
                      ((r->neg != 0 &&
                       (iVar3 = BN_add(r,r,*(BIGNUM **)(param_3 + 0x10)), iVar3 == 0))))))
                  goto LAB_00195930;
                  if (r->top != 0) {
                    if (*(int *)(param_3 + 0x3c) << 0x17 < 0) {
                      pBVar1 = *(BIGNUM **)(param_3 + 0x18);
                    }
                    else {
                      puVar7 = *(undefined4 **)(param_3 + 0x18);
                      pBVar1 = &local_3c;
                      local_3c.d = (ulong *)*puVar7;
                      local_3c.top = puVar7[1];
                      local_3c.dmax = puVar7[2];
                      local_3c.neg = puVar7[3];
                      local_3c.flags = local_3c.flags & 1U | puVar7[4] & 0xfffffffe | 6;
                    }
                    iVar3 = (**(code **)(*(int *)(param_3 + 8) + 0x18))
                                      (param_1,param_2,pBVar1,*(undefined4 *)(param_3 + 0x10),
                                       param_4,*(undefined4 *)(param_3 + 0x40));
                    if (iVar3 != 0) {
                      iVar3 = 1;
                    }
                    goto LAB_00195932;
                  }
                }
                iVar3 = 1;
                goto LAB_00195932;
              }
            }
          }
        }
      }
    }
  }
LAB_00195930:
  iVar3 = 0;
LAB_00195932:
  BN_CTX_end(param_4);
  return iVar3;
}

