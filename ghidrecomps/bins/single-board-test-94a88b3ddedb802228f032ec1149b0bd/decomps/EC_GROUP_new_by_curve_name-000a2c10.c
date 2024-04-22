
EC_GROUP * EC_GROUP_new_by_curve_name(int nid)

{
  BN_CTX *ctx;
  BIGNUM *a;
  BIGNUM *b;
  EC_METHOD *meth;
  BIGNUM *group;
  EC_POINT *p;
  BIGNUM *y;
  BIGNUM *order;
  size_t sVar1;
  int iVar2;
  int iVar3;
  uchar *s;
  code *pcVar4;
  int *piVar5;
  BIGNUM *local_40;
  BIGNUM *local_38;
  
  if (0 < nid) {
    iVar3 = 0;
    do {
      iVar2 = iVar3 * 0x10;
      iVar3 = iVar3 + 1;
      if (*(int *)(DAT_000a2e80 + iVar2) == nid) {
        iVar2 = DAT_000a2e80 + iVar2;
        piVar5 = *(int **)(iVar2 + 4);
        pcVar4 = *(code **)(iVar2 + 8);
        ctx = BN_CTX_new();
        if (ctx == (BN_CTX *)0x0) {
          ERR_put_error(0x10,0xaf,0x41,DAT_000a2e84,0xbf9);
          group = (BIGNUM *)0x0;
          a = (BIGNUM *)0x0;
          b = (BIGNUM *)0x0;
          local_40 = (BIGNUM *)0x0;
LAB_000a2ce4:
          EC_GROUP_free((EC_GROUP *)group);
          if (ctx != (BN_CTX *)0x0) {
            group = (BIGNUM *)0x0;
            local_38 = (BIGNUM *)0x0;
            order = group;
            y = group;
            goto LAB_000a2e46;
          }
          group = (BIGNUM *)0x0;
          order = (BIGNUM *)0x0;
          y = (BIGNUM *)0x0;
          local_38 = (BIGNUM *)0x0;
        }
        else {
          sVar1 = piVar5[1];
          iVar3 = piVar5[2];
          s = (uchar *)((int)piVar5 + sVar1 + 0x10);
          local_40 = BN_bin2bn(s,iVar3,(BIGNUM *)0x0);
          if ((local_40 == (BIGNUM *)0x0) ||
             (a = BN_bin2bn(s + iVar3,iVar3,(BIGNUM *)0x0), a == (BIGNUM *)0x0)) {
            a = (BIGNUM *)0x0;
LAB_000a2ccc:
            b = (BIGNUM *)0x0;
            group = (BIGNUM *)0x0;
            ERR_put_error(0x10,0xaf,3,DAT_000a2e84,0xc06);
            goto LAB_000a2ce4;
          }
          b = BN_bin2bn(s + iVar3 * 2,iVar3,(BIGNUM *)0x0);
          if (b == (BIGNUM *)0x0) goto LAB_000a2ccc;
          if (pcVar4 != (code *)0x0) {
            meth = (EC_METHOD *)(*pcVar4)();
            group = (BIGNUM *)EC_GROUP_new(meth);
            if ((group != (BIGNUM *)0x0) &&
               (iVar2 = (*(code *)group->d[6])(group,local_40,a,b,ctx), iVar2 != 0))
            goto LAB_000a2d7c;
            iVar2 = 0xc0e;
LAB_000a2cba:
            ERR_put_error(0x10,0xaf,0x10,DAT_000a2e84,iVar2);
            goto LAB_000a2ce4;
          }
          if (*piVar5 == 0x196) {
            group = (BIGNUM *)EC_GROUP_new_curve_GFp(local_40,a,b,ctx);
            iVar2 = 0xc13;
            if (group != (BIGNUM *)0x0) goto LAB_000a2d7c;
            goto LAB_000a2cba;
          }
          group = (BIGNUM *)EC_GROUP_new_curve_GF2m();
          iVar2 = 0xc1c;
          if (group == (BIGNUM *)0x0) goto LAB_000a2cba;
LAB_000a2d7c:
          p = EC_POINT_new((EC_GROUP *)group);
          if (p == (EC_POINT *)0x0) {
            iVar2 = 0xc23;
            goto LAB_000a2cba;
          }
          local_38 = BN_bin2bn(s + iVar3 * 3,iVar3,(BIGNUM *)0x0);
          if ((local_38 == (BIGNUM *)0x0) ||
             (y = BN_bin2bn(s + iVar3 * 4,iVar3,(BIGNUM *)0x0), y == (BIGNUM *)0x0)) {
            order = (BIGNUM *)0x0;
            y = (BIGNUM *)0x0;
            ERR_put_error(0x10,0xaf,3,DAT_000a2e84,0xc29);
LAB_000a2e38:
            EC_GROUP_free((EC_GROUP *)group);
            group = (BIGNUM *)0x0;
          }
          else {
            iVar2 = EC_POINT_set_affine_coordinates_GFp((EC_GROUP *)group,p,local_38,y,ctx);
            if (iVar2 == 0) {
              ERR_put_error(0x10,0xaf,0x10,DAT_000a2e84,0xc2d);
              order = (BIGNUM *)0x0;
              goto LAB_000a2e38;
            }
            order = BN_bin2bn(s + iVar3 * 5,iVar3,(BIGNUM *)0x0);
            if ((order == (BIGNUM *)0x0) || (iVar3 = BN_set_word(local_38,piVar5[3]), iVar3 == 0)) {
              ERR_put_error(0x10,0xaf,3,DAT_000a2e84,0xc32);
              goto LAB_000a2e38;
            }
            iVar3 = EC_GROUP_set_generator((EC_GROUP *)group,p,order,local_38);
            iVar2 = 0xc36;
            if (iVar3 == 0) {
LAB_000a2eb8:
              ERR_put_error(0x10,0xaf,0x10,DAT_000a2ed4,iVar2);
              goto LAB_000a2e38;
            }
            if ((sVar1 != 0) &&
               (sVar1 = EC_GROUP_set_seed((EC_GROUP *)group,s + -sVar1,sVar1), sVar1 == 0)) {
              iVar2 = 0xc3b;
              goto LAB_000a2eb8;
            }
          }
          EC_POINT_free(p);
LAB_000a2e46:
          BN_CTX_free(ctx);
        }
        if (local_40 != (BIGNUM *)0x0) {
          BN_free(local_40);
        }
        if (a != (BIGNUM *)0x0) {
          BN_free(a);
        }
        if (b != (BIGNUM *)0x0) {
          BN_free(b);
        }
        if (order != (BIGNUM *)0x0) {
          BN_free(order);
        }
        if (local_38 != (BIGNUM *)0x0) {
          BN_free(local_38);
        }
        if (y != (BIGNUM *)0x0) {
          BN_free(y);
        }
        if (group != (BIGNUM *)0x0) {
          EC_GROUP_set_curve_name((EC_GROUP *)group,nid);
          return (EC_GROUP *)group;
        }
        break;
      }
    } while (iVar3 != 0x51);
    ERR_put_error(0x10,0xae,0x81,DAT_000a2e84,0xc6b);
  }
  return (EC_GROUP *)0x0;
}

