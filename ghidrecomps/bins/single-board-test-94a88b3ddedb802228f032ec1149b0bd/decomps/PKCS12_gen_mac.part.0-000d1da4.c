
undefined4 PKCS12_gen_mac_part_0(int param_1,char *param_2,int param_3,uchar *param_4,uint *param_5)

{
  int iVar1;
  char *name;
  EVP_MD *md;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  size_t *psVar5;
  uchar *salt;
  long iter;
  uchar auStack_138 [64];
  HMAC_CTX HStack_f8;
  
  puVar3 = *(undefined4 **)(param_1 + 4);
  iter = 1;
  salt = (uchar *)((int *)puVar3[1])[2];
  iVar4 = *(int *)puVar3[1];
  if ((ASN1_INTEGER *)puVar3[2] != (ASN1_INTEGER *)0x0) {
    iter = ASN1_INTEGER_get((ASN1_INTEGER *)puVar3[2]);
    puVar3 = *(undefined4 **)(param_1 + 4);
  }
  iVar1 = OBJ_obj2nid(**(ASN1_OBJECT ***)*puVar3);
  name = OBJ_nid2sn(iVar1);
  md = EVP_get_digestbyname(name);
  if (md == (EVP_MD *)0x0) {
    ERR_put_error(0x23,0x6b,0x76,DAT_000d1e90,0x5a);
    uVar2 = 0;
  }
  else {
    iVar1 = EVP_MD_size(md);
    if (iVar1 < 0) {
      uVar2 = 0;
    }
    else {
      iVar4 = PKCS12_key_gen_asc(param_2,param_3,salt,iVar4,3,iter,iVar1,auStack_138,md);
      if (iVar4 == 0) {
        ERR_put_error(0x23,0x6b,0x6b,DAT_000d1e90,0x62);
        uVar2 = 0;
      }
      else {
        HMAC_CTX_init(&HStack_f8);
        iVar4 = HMAC_Init_ex(&HStack_f8,auStack_138,iVar1,md,(ENGINE *)0x0);
        if (((iVar4 == 0) ||
            (psVar5 = *(size_t **)(*(int *)(param_1 + 8) + 0x14),
            iVar4 = HMAC_Update(&HStack_f8,(uchar *)psVar5[2],*psVar5), iVar4 == 0)) ||
           (iVar4 = HMAC_Final(&HStack_f8,param_4,param_5), iVar4 == 0)) {
          HMAC_CTX_cleanup(&HStack_f8);
          uVar2 = 0;
        }
        else {
          HMAC_CTX_cleanup(&HStack_f8);
          uVar2 = 1;
        }
      }
    }
  }
  return uVar2;
}

