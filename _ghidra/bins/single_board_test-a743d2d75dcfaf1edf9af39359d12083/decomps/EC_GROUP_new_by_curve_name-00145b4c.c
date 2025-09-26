
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
  uchar *s;
  code *pcVar3;
  int iVar4;
  int *piVar5;
  BIGNUM *local_40;
  BIGNUM *local_38;
  
  if (0 < nid) {
    iVar4 = 0;
    do {
      iVar2 = iVar4 + 1;
      if ((&curve_list)[iVar4 * 4] == nid) {
        piVar5 = (int *)(&DAT_00207628)[iVar4 * 4];
        pcVar3 = (code *)(&DAT_0020762c)[iVar4 * 4];
        ctx = BN_CTX_new();
        if (ctx == (BN_CTX *)0x0) {
          ERR_put_error(0x10,0xaf,0x41,"ec_curve.c",0xbf9);
          group = (BIGNUM *)0x0;
          a = (BIGNUM *)0x0;
          b = (BIGNUM *)0x0;
          local_40 = (BIGNUM *)0x0;
LAB_00145c20:
          EC_GROUP_free((EC_GROUP *)group);
          if (ctx != (BN_CTX *)0x0) {
            group = (BIGNUM *)0x0;
            local_38 = (BIGNUM *)0x0;
            order = group;
            y = group;
            goto LAB_00145d82;
          }
          group = (BIGNUM *)0x0;
          order = (BIGNUM *)0x0;
          y = (BIGNUM *)0x0;
          local_38 = (BIGNUM *)0x0;
        }
        else {
          sVar1 = piVar5[1];
          iVar4 = piVar5[2];
          s = (uchar *)((int)piVar5 + sVar1 + 0x10);
          local_40 = BN_bin2bn(s,iVar4,(BIGNUM *)0x0);
          if ((local_40 == (BIGNUM *)0x0) ||
             (a = BN_bin2bn(s + iVar4,iVar4,(BIGNUM *)0x0), a == (BIGNUM *)0x0)) {
            a = (BIGNUM *)0x0;
LAB_00145c08:
            b = (BIGNUM *)0x0;
            group = (BIGNUM *)0x0;
            ERR_put_error(0x10,0xaf,3,"ec_curve.c",0xc06);
            goto LAB_00145c20;
          }
          b = BN_bin2bn(s + iVar4 * 2,iVar4,(BIGNUM *)0x0);
          if (b == (BIGNUM *)0x0) goto LAB_00145c08;
          if (pcVar3 != (code *)0x0) {
            meth = (EC_METHOD *)(*pcVar3)();
            group = (BIGNUM *)EC_GROUP_new(meth);
            if ((group != (BIGNUM *)0x0) &&
               (iVar2 = (*(code *)group->d[6])(group,local_40,a,b,ctx), iVar2 != 0))
            goto LAB_00145cb8;
            iVar2 = 0xc0e;
LAB_00145bf6:
            ERR_put_error(0x10,0xaf,0x10,"ec_curve.c",iVar2);
            goto LAB_00145c20;
          }
          if (*piVar5 == 0x196) {
            group = (BIGNUM *)EC_GROUP_new_curve_GFp(local_40,a,b,ctx);
            iVar2 = 0xc13;
            if (group != (BIGNUM *)0x0) goto LAB_00145cb8;
            goto LAB_00145bf6;
          }
          group = (BIGNUM *)EC_GROUP_new_curve_GF2m();
          iVar2 = 0xc1c;
          if (group == (BIGNUM *)0x0) goto LAB_00145bf6;
LAB_00145cb8:
          p = EC_POINT_new((EC_GROUP *)group);
          if (p == (EC_POINT *)0x0) {
            iVar2 = 0xc23;
            goto LAB_00145bf6;
          }
          local_38 = BN_bin2bn(s + iVar4 * 3,iVar4,(BIGNUM *)0x0);
          if ((local_38 == (BIGNUM *)0x0) ||
             (y = BN_bin2bn(s + iVar4 * 4,iVar4,(BIGNUM *)0x0), y == (BIGNUM *)0x0)) {
            order = (BIGNUM *)0x0;
            y = (BIGNUM *)0x0;
            ERR_put_error(0x10,0xaf,3,"ec_curve.c",0xc29);
LAB_00145d74:
            EC_GROUP_free((EC_GROUP *)group);
            group = (BIGNUM *)0x0;
          }
          else {
            iVar2 = EC_POINT_set_affine_coordinates_GFp((EC_GROUP *)group,p,local_38,y,ctx);
            if (iVar2 == 0) {
              ERR_put_error(0x10,0xaf,0x10,"ec_curve.c",0xc2d);
              order = (BIGNUM *)0x0;
              goto LAB_00145d74;
            }
            order = BN_bin2bn(s + iVar4 * 5,iVar4,(BIGNUM *)0x0);
            if ((order == (BIGNUM *)0x0) || (iVar4 = BN_set_word(local_38,piVar5[3]), iVar4 == 0)) {
              ERR_put_error(0x10,0xaf,3,"ec_curve.c",0xc32);
              goto LAB_00145d74;
            }
            iVar4 = EC_GROUP_set_generator((EC_GROUP *)group,p,order,local_38);
            iVar2 = 0xc36;
            if (iVar4 == 0) {
LAB_00145df4:
              ERR_put_error(0x10,0xaf,0x10,"ec_curve.c",iVar2);
              goto LAB_00145d74;
            }
            if ((sVar1 != 0) &&
               (sVar1 = EC_GROUP_set_seed((EC_GROUP *)group,s + -sVar1,sVar1), sVar1 == 0)) {
              iVar2 = 0xc3b;
              goto LAB_00145df4;
            }
          }
          EC_POINT_free(p);
LAB_00145d82:
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
      iVar4 = iVar2;
    } while (iVar2 != 0x51);
    ERR_put_error(0x10,0xae,0x81,"ec_curve.c",0xc6b);
  }
  return (EC_GROUP *)0x0;
}

