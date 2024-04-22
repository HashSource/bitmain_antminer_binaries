
undefined4 oid_module_init(CONF_IMODULE *param_1,CONF *param_2)

{
  ushort uVar1;
  char *pcVar2;
  _STACK *p_Var3;
  int iVar4;
  void *pvVar5;
  byte *pbVar6;
  ushort **ppuVar7;
  undefined4 uVar8;
  char **__dest;
  ASN1_OBJECT *pAVar9;
  byte *pbVar10;
  ushort *puVar11;
  byte *pbVar12;
  int iVar13;
  
  pcVar2 = CONF_imodule_get_value(param_1);
  p_Var3 = &NCONF_get_section(param_2,pcVar2)->stack;
  if (p_Var3 == (_STACK *)0x0) {
    ERR_put_error(0xd,0xae,0xac,DAT_0010a944,0x50);
    uVar8 = 0;
  }
  else {
    for (iVar13 = 0; iVar4 = sk_num(p_Var3), iVar13 < iVar4; iVar13 = iVar13 + 1) {
      pvVar5 = sk_value(p_Var3,iVar13);
      pbVar12 = *(byte **)((int)pvVar5 + 8);
      pcVar2 = *(char **)((int)pvVar5 + 4);
      pbVar6 = (byte *)strrchr((char *)pbVar12,0x2c);
      if (pbVar6 == (byte *)0x0) {
        iVar4 = OBJ_create((char *)pbVar12,pcVar2,pcVar2);
        if (iVar4 == 0) goto LAB_0010a8d0;
      }
      else {
        if (pbVar6[1] == 0) {
LAB_0010a8d0:
          ERR_put_error(0xd,0xae,0xab,DAT_0010a944,0x56);
          return 0;
        }
        ppuVar7 = __ctype_b_loc();
        pbVar10 = pbVar6;
        do {
          pbVar10 = pbVar10 + 1;
        } while (((*ppuVar7)[*pbVar10] & 0x2000) != 0);
        iVar4 = OBJ_create((char *)pbVar10,pcVar2,(char *)0x0);
        if (iVar4 == 0) goto LAB_0010a8d0;
        puVar11 = *ppuVar7;
        do {
          pbVar10 = pbVar12;
          pbVar12 = pbVar10 + 1;
        } while ((int)((uint)puVar11[*pbVar10] << 0x12) < 0);
        pbVar12 = pbVar6 + -1;
        uVar1 = puVar11[pbVar6[-1]];
        while ((int)((uint)uVar1 << 0x12) < 0) {
          if (pbVar10 == pbVar12) goto LAB_0010a8d0;
          pbVar12 = pbVar12 + -1;
          uVar1 = puVar11[*pbVar12];
        }
        pbVar12 = pbVar12 + (1 - (int)pbVar10);
        __dest = (char **)CRYPTO_malloc((int)(pbVar12 + 1),DAT_0010a944,0x8f);
        if (__dest == (char **)0x0) goto LAB_0010a8d0;
        memcpy(__dest,pbVar10,(size_t)pbVar12);
        *(byte *)((int)__dest + (int)pbVar12) = 0;
        pAVar9 = OBJ_nid2obj(iVar4);
        pAVar9->ln = __dest;
      }
    }
    uVar8 = 1;
  }
  return uVar8;
}

