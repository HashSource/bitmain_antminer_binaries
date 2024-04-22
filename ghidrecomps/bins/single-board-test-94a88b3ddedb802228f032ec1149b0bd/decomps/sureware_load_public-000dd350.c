
EVP_PKEY *
sureware_load_public(ENGINE *param_1,undefined4 param_2,void *param_3,uint param_4,char param_5)

{
  int iVar1;
  DSA *d;
  BIGNUM *pBVar2;
  RSA *r;
  int iVar3;
  int *piVar4;
  EVP_PKEY *pEVar5;
  BIGNUM *pBVar6;
  ulong *puVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined local_54;
  undefined auStack_53 [47];
  
  iVar3 = DAT_000dd5bc;
  local_68 = *DAT_000dd5b8;
  uStack_64 = DAT_000dd5b8[1];
  uStack_60 = DAT_000dd5b8[2];
  uStack_5c = DAT_000dd5b8[3];
  uStack_58 = DAT_000dd5b8[4];
  local_54 = (undefined)DAT_000dd5b8[5];
  memset(auStack_53,0,0x2b);
  iVar1 = DAT_000dd5bc;
  if ((*(int *)(iVar3 + 0x14) == 0) || (*(int *)(iVar3 + 0x18) == 0)) {
    iVar3 = *(int *)(iVar3 + 4);
    if (iVar3 == 0) {
      iVar3 = ERR_get_next_error_library();
      *(int *)(iVar1 + 4) = iVar3;
    }
    ERR_put_error(iVar3,0x6a,0x75,DAT_000dd5c0,700);
  }
  else {
    if (param_5 == '\x01') {
      r = RSA_new_method(param_1);
      RSA_set_ex_data(r,*(int *)(DAT_000dd5c4 + 0xd4),param_3);
      *(uint *)&r->field_0x3c = *(uint *)&r->field_0x3c | 0x20;
      pBVar2 = BN_new();
      *(BIGNUM **)&r->field_0x14 = pBVar2;
      pBVar2 = BN_new();
      *(BIGNUM **)&r->field_0x10 = pBVar2;
      if ((*(BIGNUM **)&r->field_0x14 != (BIGNUM *)0x0) && (pBVar2 != (BIGNUM *)0x0)) {
        uVar9 = param_4 >> 2;
        bn_expand2(*(BIGNUM **)&r->field_0x14,uVar9);
        bn_expand2(*(BIGNUM **)&r->field_0x10,uVar9);
        if ((uVar9 == (*(undefined4 **)&r->field_0x14)[2]) &&
           (uVar9 == (*(undefined4 **)&r->field_0x10)[2])) {
          iVar1 = (**(code **)(iVar3 + 0x14))
                            (&local_68,param_2,param_4,**(undefined4 **)&r->field_0x10,
                             **(undefined4 **)&r->field_0x14);
          surewarehk_error_handling(&local_68,0x6a,iVar1);
          if (iVar1 == 1) {
            piVar10 = *(int **)&r->field_0x14;
            piVar10[1] = uVar9;
            if (uVar9 == 0) {
              *(undefined4 *)(*(int *)&r->field_0x10 + 4) = 0;
            }
            else {
              iVar3 = (uVar9 - 1) * 4;
              uVar8 = uVar9;
              piVar4 = (int *)(*piVar10 + iVar3);
              do {
                if (*piVar4 != 0) break;
                uVar8 = uVar8 - 1;
                piVar4 = piVar4 + -1;
              } while (uVar8 != 0);
              piVar4 = *(int **)&r->field_0x10;
              piVar10[1] = uVar8;
              piVar4[1] = uVar9;
              piVar10 = (int *)(*piVar4 + iVar3);
              do {
                if (*piVar10 != 0) break;
                uVar9 = uVar9 - 1;
                piVar10 = piVar10 + -1;
              } while (uVar9 != 0);
              piVar4[1] = uVar9;
            }
            pEVar5 = EVP_PKEY_new();
            EVP_PKEY_assign(pEVar5,6,r);
            return pEVar5;
          }
          iVar1 = *(int *)(iVar3 + 4);
          if (iVar1 == 0) {
            iVar1 = ERR_get_next_error_library();
            *(int *)(iVar3 + 4) = iVar1;
          }
          ERR_put_error(iVar1,0x6a,0x81,DAT_000dd5c0,0x2d8);
        }
      }
      RSA_free(r);
      return (EVP_PKEY *)0x0;
    }
    if (param_5 == '\x02') {
      d = DSA_new_method(param_1);
      DSA_set_ex_data(d,*(int *)(DAT_000dd5c4 + 0xd8),param_3);
      pBVar2 = BN_new();
      d->pub_key = pBVar2;
      pBVar2 = BN_new();
      d->p = pBVar2;
      pBVar2 = BN_new();
      d->q = pBVar2;
      pBVar2 = BN_new();
      d->g = pBVar2;
      if ((((d->pub_key != (BIGNUM *)0x0) && (d->p != (BIGNUM *)0x0)) && (d->q != (BIGNUM *)0x0)) &&
         (pBVar2 != (BIGNUM *)0x0)) {
        uVar9 = param_4 >> 2;
        bn_expand2(d->pub_key,uVar9);
        bn_expand2(d->p,uVar9);
        bn_expand2(d->q,5);
        bn_expand2(d->g,uVar9);
        if (((uVar9 == d->pub_key->dmax) && (uVar9 == d->p->dmax)) &&
           ((d->q->dmax == 5 && (uVar9 == d->g->dmax)))) {
          iVar3 = (**(code **)(iVar3 + 0x18))
                            (&local_68,param_2,param_4,d->pub_key->d,d->p->d,d->q->d,d->g->d);
          surewarehk_error_handling(&local_68,0x6a,iVar3);
          if (iVar3 == 1) {
            pBVar2 = d->pub_key;
            pBVar2->top = uVar9;
            if (uVar9 == 0) {
              d->p->top = 0;
            }
            else {
              uVar8 = uVar9;
              puVar7 = pBVar2->d + (uVar9 - 1);
              do {
                if (*puVar7 != 0) break;
                uVar8 = uVar8 - 1;
                puVar7 = puVar7 + -1;
              } while (uVar8 != 0);
              pBVar6 = d->p;
              pBVar2->top = uVar8;
              pBVar6->top = uVar9;
              puVar7 = pBVar6->d + (uVar9 - 1);
              uVar8 = uVar9;
              do {
                if (*puVar7 != 0) break;
                uVar8 = uVar8 - 1;
                puVar7 = puVar7 + -1;
              } while (uVar8 != 0);
              pBVar6->top = uVar8;
            }
            pBVar2 = d->q;
            iVar3 = 5;
            pBVar2->top = 5;
            do {
              if (pBVar2->d[iVar3 + -1] != 0) break;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
            pBVar6 = d->g;
            pBVar2->top = iVar3;
            pBVar6->top = uVar9;
            if (uVar9 != 0) {
              puVar7 = pBVar6->d + (uVar9 - 1);
              do {
                if (*puVar7 != 0) break;
                uVar9 = uVar9 - 1;
                puVar7 = puVar7 + -1;
              } while (uVar9 != 0);
              pBVar6->top = uVar9;
            }
            pEVar5 = EVP_PKEY_new();
            EVP_PKEY_assign(pEVar5,0x74,d);
            return pEVar5;
          }
          ERR_SUREWARE_error_constprop_5(0x6a,0x81,0x30a);
        }
      }
      DSA_free(d);
      return (EVP_PKEY *)0x0;
    }
    iVar1 = *(int *)(iVar3 + 4);
    if (iVar1 == 0) {
      iVar1 = ERR_get_next_error_library();
      *(int *)(iVar3 + 4) = iVar1;
    }
    ERR_put_error(iVar1,0x6a,0x80,DAT_000dd5c0,800);
  }
  return (EVP_PKEY *)0x0;
}

