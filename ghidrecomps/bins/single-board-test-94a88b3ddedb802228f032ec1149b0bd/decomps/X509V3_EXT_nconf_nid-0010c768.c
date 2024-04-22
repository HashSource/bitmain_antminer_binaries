
X509_EXTENSION * X509V3_EXT_nconf_nid(CONF *conf,X509V3_CTX *ctx,int ext_nid,char *value)

{
  size_t sVar1;
  int iVar2;
  ushort **ppuVar3;
  X509_EXTENSION *pXVar4;
  char *pcVar5;
  byte *pbVar6;
  byte *pbVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  sVar1 = strlen(value);
  if (sVar1 < 9) {
    uVar8 = 0;
LAB_0010c7b2:
    if (3 < sVar1) goto LAB_0010c7ce;
LAB_0010c7b6:
    pXVar4 = (X509_EXTENSION *)do_ext_nconf(conf,ctx,ext_nid,uVar8,value);
  }
  else {
    iVar2 = strncmp(value,DAT_0010c828,9);
    if (iVar2 == 0) {
      ppuVar3 = __ctype_b_loc();
      pbVar6 = (byte *)(value + 9);
      do {
        value = (char *)pbVar6;
        pbVar6 = (byte *)value + 1;
      } while ((int)((uint)(*ppuVar3)[(byte)*value] << 0x12) < 0);
      uVar8 = 1;
      sVar1 = strlen(value);
      goto LAB_0010c7b2;
    }
    uVar8 = 0;
LAB_0010c7ce:
    iVar2 = strncmp(value,DAT_0010c82c,4);
    if (iVar2 == 0) {
      pbVar6 = (byte *)value + 4;
      uVar9 = 1;
    }
    else {
      if ((sVar1 == 4) || (iVar2 = strncmp(value,DAT_0010c830,5), iVar2 != 0)) goto LAB_0010c7b6;
      pbVar6 = (byte *)value + 5;
      uVar9 = 2;
    }
    ppuVar3 = __ctype_b_loc();
    do {
      pbVar7 = pbVar6;
      pbVar6 = pbVar7 + 1;
    } while ((int)((uint)(*ppuVar3)[*pbVar7] << 0x12) < 0);
    pcVar5 = OBJ_nid2sn(ext_nid);
    pXVar4 = (X509_EXTENSION *)v3_generic_extension(pcVar5,pbVar7,uVar8,uVar9,ctx);
  }
  return pXVar4;
}

