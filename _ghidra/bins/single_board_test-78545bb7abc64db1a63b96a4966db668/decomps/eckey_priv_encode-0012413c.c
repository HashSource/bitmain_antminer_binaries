
undefined4 eckey_priv_encode(PKCS8_PRIV_KEY_INFO *param_1,int param_2)

{
  EC_GROUP *group;
  int iVar1;
  ASN1_OBJECT *a;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  uchar *penc;
  int iVar5;
  ASN1_OBJECT *aobj;
  undefined4 *puVar6;
  uchar *local_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  puVar6 = *(undefined4 **)(param_2 + 0x18);
  local_58 = *puVar6;
  uStack_54 = puVar6[1];
  uStack_50 = puVar6[2];
  uStack_4c = puVar6[3];
  local_48 = puVar6[4];
  uStack_44 = puVar6[5];
  uStack_40 = puVar6[6];
  uStack_3c = puVar6[7];
  local_38 = puVar6[8];
  uStack_34 = puVar6[9];
  uStack_30 = puVar6[10];
  uStack_2c = puVar6[0xb];
  group = EC_KEY_get0_group((EC_KEY *)&local_58);
  if (group == (EC_GROUP *)0x0) {
    ERR_put_error(0x10,0xdf,0x7c,"crypto/ec/ec_ameth.c",0x1f);
  }
  else {
    iVar1 = EC_GROUP_get_asn1_flag(group);
    if ((iVar1 == 0) || (iVar1 = EC_GROUP_get_curve_name(group), iVar1 == 0)) {
      a = (ASN1_OBJECT *)ASN1_STRING_new();
      if (a != (ASN1_OBJECT *)0x0) {
        pcVar2 = (char *)i2d_ECParameters((EC_KEY *)&local_58,(uchar **)&a->nid);
        a->sn = pcVar2;
        if (0 < (int)pcVar2) {
          iVar1 = 0x10;
          goto LAB_00124192;
        }
        ASN1_STRING_free((ASN1_STRING *)a);
        ERR_put_error(0x10,0xdf,0x10,"crypto/ec/ec_ameth.c",0x42);
      }
    }
    else {
      a = OBJ_nid2obj(iVar1);
      if (a != (ASN1_OBJECT *)0x0) {
        iVar4 = OBJ_length();
        iVar1 = 6;
        if (iVar4 != 0) {
LAB_00124192:
          uVar3 = EC_KEY_get_enc_flags((EC_KEY *)&local_58);
          EC_KEY_set_enc_flags((EC_KEY *)&local_58,uVar3 | 1);
          iVar4 = i2d_ECPrivateKey((EC_KEY *)&local_58,(uchar **)0x0);
          if (iVar4 == 0) {
            ERR_put_error(0x10,0xd6,0x10,"crypto/ec/ec_ameth.c",0x103);
          }
          else {
            penc = (uchar *)CRYPTO_malloc(iVar4,"crypto/ec/ec_ameth.c",0x106);
            if (penc == (uchar *)0x0) {
              ERR_put_error(0x10,0xd6,0x41,"crypto/ec/ec_ameth.c",0x108);
            }
            else {
              local_5c = penc;
              iVar5 = i2d_ECPrivateKey((EC_KEY *)&local_58,&local_5c);
              if (iVar5 == 0) {
                CRYPTO_free(penc);
                ERR_put_error(0x10,0xd6,0x10,"crypto/ec/ec_ameth.c",0x10e);
                return 0;
              }
              aobj = OBJ_nid2obj(0x198);
              iVar1 = PKCS8_pkey_set0(param_1,aobj,0,iVar1,a,penc,iVar4);
              if (iVar1 != 0) {
                return 1;
              }
              CRYPTO_free(penc);
            }
          }
          return 0;
        }
      }
      ASN1_OBJECT_free(a);
      ERR_put_error(0x10,0xdf,0xa7,"crypto/ec/ec_ameth.c",0x2a);
    }
  }
  ERR_put_error(0x10,0xd6,0x8e,"crypto/ec/ec_ameth.c",0xf4);
  return 0;
}

