
int X509V3_EXT_add_nconf_sk(CONF *conf,X509V3_CTX *ctx,char *section,stack_st_X509_EXTENSION **sk)

{
  _STACK *p_Var1;
  int iVar2;
  void *pvVar3;
  size_t sVar4;
  ushort **ppuVar5;
  X509_EXTENSION *ex;
  int iVar6;
  char *s;
  undefined4 uVar7;
  byte *pbVar8;
  byte *pbVar9;
  undefined4 uVar10;
  
  p_Var1 = &NCONF_get_section(conf,section)->stack;
  if (p_Var1 != (_STACK *)0x0) {
    iVar6 = 0;
    iVar2 = sk_num(p_Var1);
    if (0 < iVar2) {
      do {
        pvVar3 = sk_value(p_Var1,iVar6);
        pbVar8 = *(byte **)((int)pvVar3 + 8);
        s = *(char **)((int)pvVar3 + 4);
        sVar4 = strlen((char *)pbVar8);
        if (sVar4 < 9) {
          uVar7 = 0;
LAB_0010c8e0:
          if (3 < sVar4) goto LAB_0010c92c;
LAB_0010c8e6:
          iVar2 = OBJ_sn2nid(s);
          ex = (X509_EXTENSION *)do_ext_nconf(conf,ctx,iVar2,uVar7,pbVar8);
          if (ex == (X509_EXTENSION *)0x0) {
            ERR_put_error(0x22,0x98,0x80,DAT_0010c9c0,0x5f);
            ERR_add_error_data(4,DAT_0010c9c4,s,DAT_0010c9c8,pbVar8);
            return 0;
          }
        }
        else {
          iVar2 = strncmp((char *)pbVar8,DAT_0010c9b4,9);
          if (iVar2 == 0) {
            ppuVar5 = __ctype_b_loc();
            pbVar9 = pbVar8 + 9;
            do {
              pbVar8 = pbVar9;
              pbVar9 = pbVar8 + 1;
            } while ((int)((uint)(*ppuVar5)[*pbVar8] << 0x12) < 0);
            uVar7 = 1;
            sVar4 = strlen((char *)pbVar8);
            goto LAB_0010c8e0;
          }
          uVar7 = 0;
LAB_0010c92c:
          iVar2 = strncmp((char *)pbVar8,DAT_0010c9b8,4);
          if (iVar2 == 0) {
            pbVar8 = pbVar8 + 4;
            uVar10 = 1;
          }
          else {
            if ((sVar4 == 4) || (iVar2 = strncmp((char *)pbVar8,DAT_0010c9bc,5), iVar2 != 0))
            goto LAB_0010c8e6;
            pbVar8 = pbVar8 + 5;
            uVar10 = 2;
          }
          ppuVar5 = __ctype_b_loc();
          do {
            pbVar9 = pbVar8;
            pbVar8 = pbVar9 + 1;
          } while ((int)((uint)(*ppuVar5)[*pbVar9] << 0x12) < 0);
          ex = (X509_EXTENSION *)v3_generic_extension(s,pbVar9,uVar7,uVar10,ctx);
          if (ex == (X509_EXTENSION *)0x0) {
            return 0;
          }
        }
        if (sk != (stack_st_X509_EXTENSION **)0x0) {
          X509v3_add_ext(sk,ex,-1);
        }
        iVar6 = iVar6 + 1;
        X509_EXTENSION_free(ex);
        iVar2 = sk_num(p_Var1);
      } while (iVar6 < iVar2);
    }
    p_Var1 = (_STACK *)0x1;
  }
  return (int)p_Var1;
}

