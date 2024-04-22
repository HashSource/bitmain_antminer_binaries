
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
  ulong **ppuVar8;
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
    ppuVar8 = *(ulong ***)(param_3 + 0x1c);
    local_50.top = (int)ppuVar8[1];
    local_50.d = *ppuVar8;
    local_50.dmax = (int)ppuVar8[2];
    local_50.neg = (int)ppuVar8[3];
    local_50.flags = local_50.flags & 1U | (uint)ppuVar8[4] & 0xfffffffe | 6;
    BN_init(&local_3c);
    ppuVar8 = *(ulong ***)(param_3 + 0x20);
    pBVar5 = &local_50;
    uVar2 = *(uint *)(param_3 + 0x3c);
    local_3c.top = (int)ppuVar8[1];
    local_3c.d = *ppuVar8;
    local_3c.dmax = (int)ppuVar8[2];
    local_3c.neg = (int)ppuVar8[3];
    local_3c.flags = local_3c.flags & 1U | (uint)ppuVar8[4] & 0xfffffffe | 6;
  }
  if ((int)(uVar2 << 0x1d) < 0) {
    pBVar4 = BN_MONT_CTX_set_locked((BN_MONT_CTX **)(param_3 + 0x44),9,pBVar5,param_4);
    if ((pBVar4 != (BN_MONT_CTX *)0x0) &&
       (pBVar4 = BN_MONT_CTX_set_locked((BN_MONT_CTX **)(param_3 + 0x48),9,mod,param_4),
       pBVar4 != (BN_MONT_CTX *)0x0)) {
      uVar2 = *(uint *)(param_3 + 0x3c);
      goto joined_r0x000fa6c6;
    }
  }
  else {
joined_r0x000fa6c6:
    if ((int)(uVar2 << 0x1e) < 0) {
      pBVar4 = BN_MONT_CTX_set_locked
                         ((BN_MONT_CTX **)(param_3 + 0x40),9,*(BIGNUM **)(param_3 + 0x10),param_4);
      if (pBVar4 == (BN_MONT_CTX *)0x0) goto LAB_000fa690;
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
        puVar6 = *(undefined4 **)(param_3 + 0x28);
      }
      else {
        puVar7 = *(undefined4 **)(param_3 + 0x28);
        puVar6 = &local_78;
        local_78 = *puVar7;
        local_70 = puVar7[2];
        local_74 = puVar7[1];
        local_6c = puVar7[3];
        local_68 = local_68 & 1 | puVar7[4] & 0xfffffffe | 6;
      }
      iVar3 = (**(code **)(*(int *)(param_3 + 8) + 0x18))
                        (b,pBVar1,puVar6,*(undefined4 *)(param_3 + 0x20),param_4,
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
            if (*(int *)(param_3 + 0x3c) << 0x17 < 0) goto LAB_000fa78a;
LAB_000fa4b0:
            puVar7 = *(undefined4 **)(param_3 + 0x24);
            puVar6 = &local_8c;
            local_8c = *puVar7;
            local_84 = puVar7[2];
            local_88 = puVar7[1];
            local_80 = puVar7[3];
            local_7c = local_7c & 1 | puVar7[4] & 0xfffffffe | 6;
            goto LAB_000fa4da;
          }
        }
        else {
          iVar3 = BN_div((BIGNUM *)0x0,pBVar1,param_2,*(BIGNUM **)(param_3 + 0x1c),param_4);
          if (iVar3 != 0) {
            if (-1 < *(int *)(param_3 + 0x3c) << 0x17) goto LAB_000fa4b0;
LAB_000fa78a:
            puVar6 = *(undefined4 **)(param_3 + 0x24);
LAB_000fa4da:
            iVar3 = (**(code **)(*(int *)(param_3 + 8) + 0x18))
                              (param_1,pBVar1,puVar6,*(undefined4 *)(param_3 + 0x1c),param_4,
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
                  goto LAB_000fa690;
                  if (r->top != 0) {
                    if (*(int *)(param_3 + 0x3c) << 0x17 < 0) {
                      pBVar1 = *(BIGNUM **)(param_3 + 0x18);
                    }
                    else {
                      ppuVar8 = *(ulong ***)(param_3 + 0x18);
                      pBVar1 = &local_3c;
                      local_3c.d = *ppuVar8;
                      local_3c.top = (int)ppuVar8[1];
                      local_3c.dmax = (int)ppuVar8[2];
                      local_3c.neg = (int)ppuVar8[3];
                      local_3c.flags = local_3c.flags & 1U | (uint)ppuVar8[4] & 0xfffffffe | 6;
                    }
                    iVar3 = (**(code **)(*(int *)(param_3 + 8) + 0x18))
                                      (param_1,param_2,pBVar1,*(undefined4 *)(param_3 + 0x10),
                                       param_4,*(undefined4 *)(param_3 + 0x40));
                    if (iVar3 != 0) {
                      iVar3 = 1;
                    }
                    goto LAB_000fa692;
                  }
                }
                iVar3 = 1;
                goto LAB_000fa692;
              }
            }
          }
        }
      }
    }
  }
LAB_000fa690:
  iVar3 = 0;
LAB_000fa692:
  BN_CTX_end(param_4);
  return iVar3;
}

