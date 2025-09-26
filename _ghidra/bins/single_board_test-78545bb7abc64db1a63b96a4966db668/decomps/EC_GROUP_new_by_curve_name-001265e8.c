
EC_GROUP * EC_GROUP_new_by_curve_name(int nid)

{
  BN_CTX *ctx;
  BIGNUM *p;
  BIGNUM *a;
  BIGNUM *b;
  BIGNUM *group;
  BIGNUM *generator;
  BIGNUM *order;
  ASN1_OBJECT *a_00;
  int iVar1;
  size_t sVar2;
  uchar *s;
  EC_METHOD *pEVar3;
  int *piVar4;
  int iVar5;
  uchar *puVar6;
  BIGNUM *local_40;
  BIGNUM *local_3c;
  
  if (nid < 1) {
    return (EC_GROUP *)0x0;
  }
  iVar5 = 0;
  do {
    iVar1 = iVar5 + 1;
    if (nid == (&curve_list)[iVar5 * 4]) {
      piVar4 = (int *)(&DAT_0026af90)[iVar5 * 4];
      pEVar3 = (EC_METHOD *)(&DAT_0026af94)[iVar5 * 4];
      if (piVar4 == (int *)0x0) {
        if (pEVar3 != (EC_METHOD *)0x0) {
          pEVar3 = (EC_METHOD *)(*(code *)pEVar3)();
        }
        group = (BIGNUM *)EC_GROUP_new(pEVar3);
      }
      else {
        ctx = BN_CTX_new();
        if (ctx == (BN_CTX *)0x0) {
          ERR_put_error(0x10,0xaf,0x41,"crypto/ec/ec_curve.c",0xbd5);
          group = (BIGNUM *)0x0;
          order = (BIGNUM *)0x0;
          b = (BIGNUM *)0x0;
          a = (BIGNUM *)0x0;
          p = (BIGNUM *)0x0;
          generator = (BIGNUM *)0x0;
          local_40 = (BIGNUM *)0x0;
          local_3c = (BIGNUM *)0x0;
          goto LAB_001266e6;
        }
        sVar2 = piVar4[1];
        iVar5 = piVar4[2];
        s = (uchar *)((int)piVar4 + sVar2 + 0x10);
        p = BN_bin2bn(s,iVar5,(BIGNUM *)0x0);
        if (p == (BIGNUM *)0x0) {
LAB_001266c2:
          a = (BIGNUM *)0x0;
LAB_001266c6:
          order = (BIGNUM *)0x0;
          b = (BIGNUM *)0x0;
          generator = (BIGNUM *)0x0;
          group = (BIGNUM *)0x0;
          ERR_put_error(0x10,0xaf,3,"crypto/ec/ec_curve.c",0xbe2);
          local_3c = (BIGNUM *)0x0;
          local_40 = (BIGNUM *)0x0;
LAB_001266e6:
          EC_GROUP_free((EC_GROUP *)group);
          group = (BIGNUM *)0x0;
        }
        else {
          puVar6 = s + iVar5;
          a = BN_bin2bn(puVar6,iVar5,(BIGNUM *)0x0);
          if (a == (BIGNUM *)0x0) goto LAB_001266c2;
          puVar6 = puVar6 + iVar5;
          b = BN_bin2bn(puVar6,iVar5,(BIGNUM *)0x0);
          if (b == (BIGNUM *)0x0) goto LAB_001266c6;
          if (pEVar3 != (EC_METHOD *)0x0) {
            pEVar3 = (EC_METHOD *)(*(code *)pEVar3)();
            group = (BIGNUM *)EC_GROUP_new(pEVar3);
            if (group != (BIGNUM *)0x0) {
              iVar1 = (*(code *)group->d[6])(group,p,a,b,ctx);
              if (iVar1 != 0) goto LAB_0012677e;
            }
            ERR_put_error(0x10,0xaf,0x10,"crypto/ec/ec_curve.c",0xbea);
            local_3c = (BIGNUM *)0x0;
            local_40 = (BIGNUM *)0x0;
            order = (BIGNUM *)0x0;
            generator = (BIGNUM *)0x0;
            goto LAB_001266e6;
          }
          if (*piVar4 == 0x196) {
            group = (BIGNUM *)EC_GROUP_new_curve_GFp(p,a,b,ctx);
            if (group == (BIGNUM *)0x0) {
              iVar5 = 0xbef;
              goto LAB_0012682a;
            }
          }
          else {
            group = (BIGNUM *)EC_GROUP_new_curve_GF2m();
            if (group == (BIGNUM *)0x0) {
              iVar5 = 0xbf8;
LAB_0012682a:
              ERR_put_error(0x10,0xaf,0x10,"crypto/ec/ec_curve.c",iVar5);
              order = group;
              generator = group;
              local_40 = group;
              local_3c = group;
              goto LAB_001266e6;
            }
          }
LAB_0012677e:
          EC_GROUP_set_curve_name((EC_GROUP *)group,nid);
          generator = (BIGNUM *)EC_POINT_new((EC_GROUP *)group);
          if (generator == (BIGNUM *)0x0) {
            ERR_put_error(0x10,0xaf,0x10,"crypto/ec/ec_curve.c",0xc01);
            order = (BIGNUM *)0x0;
            local_40 = (BIGNUM *)0x0;
            local_3c = (BIGNUM *)0x0;
            goto LAB_001266e6;
          }
          puVar6 = puVar6 + iVar5;
          local_40 = BN_bin2bn(puVar6,iVar5,(BIGNUM *)0x0);
          if (local_40 == (BIGNUM *)0x0) {
LAB_0012683a:
            ERR_put_error(0x10,0xaf,3,"crypto/ec/ec_curve.c",0xc07);
            local_3c = (BIGNUM *)0x0;
            order = (BIGNUM *)0x0;
            goto LAB_001266e6;
          }
          local_3c = BN_bin2bn(puVar6 + iVar5,iVar5,(BIGNUM *)0x0);
          if (local_3c == (BIGNUM *)0x0) goto LAB_0012683a;
          iVar1 = EC_POINT_set_affine_coordinates(group,generator,local_40,local_3c,ctx);
          if (iVar1 == 0) {
            ERR_put_error(0x10,0xaf,0x10,"crypto/ec/ec_curve.c",0xc0b);
            order = (BIGNUM *)0x0;
            goto LAB_001266e6;
          }
          order = BN_bin2bn(puVar6 + iVar5 + iVar5,iVar5,(BIGNUM *)0x0);
          if ((order == (BIGNUM *)0x0) || (iVar5 = BN_set_word(local_40,piVar4[3]), iVar5 == 0)) {
            ERR_put_error(0x10,0xaf,3,"crypto/ec/ec_curve.c",0xc10);
            goto LAB_001266e6;
          }
          iVar5 = EC_GROUP_set_generator((EC_GROUP *)group,(EC_POINT *)generator,order,local_40);
          if (iVar5 == 0) {
            ERR_put_error(0x10,0xaf,0x10,"crypto/ec/ec_curve.c",0xc14);
            goto LAB_001266e6;
          }
          if ((sVar2 != 0) &&
             (sVar2 = EC_GROUP_set_seed((EC_GROUP *)group,s + -sVar2,sVar2), sVar2 == 0)) {
            ERR_put_error(0x10,0xaf,0x10,"crypto/ec/ec_curve.c",0xc19);
            goto LAB_001266e6;
          }
          iVar5 = EC_GROUP_get_asn1_flag((EC_GROUP *)group);
          if (iVar5 == 1) {
            a_00 = OBJ_nid2obj(nid);
            if (a_00 == (ASN1_OBJECT *)0x0) {
              ERR_put_error(0x10,0xaf,8,"crypto/ec/ec_curve.c",0xc2e);
              goto LAB_001266e6;
            }
            iVar5 = OBJ_length();
            if (iVar5 == 0) {
              EC_GROUP_set_asn1_flag((EC_GROUP *)group,0);
            }
            ASN1_OBJECT_free(a_00);
          }
        }
        EC_POINT_free((EC_POINT *)generator);
        BN_CTX_free(ctx);
        BN_free(p);
        BN_free(a);
        BN_free(b);
        BN_free(order);
        BN_free(local_40);
        BN_free(local_3c);
      }
      if (group != (BIGNUM *)0x0) {
        return (EC_GROUP *)group;
      }
      break;
    }
    iVar5 = iVar1;
  } while (iVar1 != 0x52);
  ERR_put_error(0x10,0xae,0x81,"crypto/ec/ec_curve.c",0xc57);
  return (EC_GROUP *)0x0;
}

