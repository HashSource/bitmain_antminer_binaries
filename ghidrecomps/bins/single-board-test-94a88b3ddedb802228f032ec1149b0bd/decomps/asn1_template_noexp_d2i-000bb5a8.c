
undefined4
asn1_template_noexp_d2i
          (_STACK **param_1,uchar **param_2,uchar *param_3,ASN1_TEMPLATE *param_4,char param_5,
          ASN1_TLC *param_6)

{
  uchar *puVar1;
  int iVar2;
  long lVar3;
  uint uVar4;
  int line;
  uint aclass;
  _STACK *p_Var5;
  uchar *local_3c;
  char local_38 [8];
  uchar *local_30;
  ASN1_VALUE *local_2c [2];
  
  if (param_1 != (_STACK **)0x0) {
    uVar4 = param_4->flags;
    local_30 = *param_2;
    aclass = uVar4 & 0xc0;
    local_3c = param_3;
    if ((uVar4 & 6) == 0) {
      if ((uVar4 & 8) == 0) {
        iVar2 = ASN1_item_ex_d2i((ASN1_VALUE **)param_1,&local_30,(long)param_3,param_4->item,-1,0,
                                 param_5,param_6);
        if (iVar2 != 0) goto LAB_000bb6a8;
        line = 0x2b6;
      }
      else {
        iVar2 = ASN1_item_ex_d2i((ASN1_VALUE **)param_1,&local_30,(long)param_3,param_4->item,
                                 param_4->tag,aclass,param_5,param_6);
        line = 0x2ad;
        if (iVar2 != 0) {
LAB_000bb6a8:
          if (iVar2 == -1) {
            return 0xffffffff;
          }
LAB_000bb676:
          *param_2 = local_30;
          return 1;
        }
      }
LAB_000bb724:
      ERR_put_error(0xd,0x83,0x3a,DAT_000bb7a0,line);
    }
    else {
      if ((uVar4 & 8) == 0) {
        if ((uVar4 & 2) == 0) {
          lVar3 = 0x10;
        }
        else {
          lVar3 = 0x11;
        }
        aclass = 0;
      }
      else {
        lVar3 = param_4->tag;
      }
      iVar2 = asn1_check_tlen(&local_3c,0,0,local_38,0,&local_30,param_3,lVar3,aclass,param_5,
                              param_6);
      if (iVar2 == 0) {
        ERR_put_error(0xd,0x83,0x3a,DAT_000bb7a0,0x270);
        return 0;
      }
      if (iVar2 == -1) {
        return 0xffffffff;
      }
      p_Var5 = *param_1;
      if (p_Var5 == (_STACK *)0x0) {
        p_Var5 = sk_new_null();
        *param_1 = p_Var5;
      }
      else {
        while (iVar2 = sk_num(p_Var5), 0 < iVar2) {
          local_2c[0] = (ASN1_VALUE *)sk_pop(p_Var5);
          ASN1_item_ex_free(local_2c,param_4->item);
        }
        p_Var5 = *param_1;
      }
      puVar1 = local_30;
      if (p_Var5 == (_STACK *)0x0) {
        iVar2 = 0x283;
      }
      else {
        do {
          local_30 = puVar1;
          if ((int)local_3c < 1) {
            if (local_38[0] == '\0') goto LAB_000bb676;
            ERR_put_error(0xd,0x83,0x89,DAT_000bb7a0,0x2a4);
            goto LAB_000bb732;
          }
          if (((local_3c != (uchar *)0x1) && (*puVar1 == '\0')) && (puVar1[1] == '\0')) {
            local_30 = puVar1 + 2;
            if (local_38[0] != '\0') goto LAB_000bb676;
            ERR_put_error(0xd,0x83,0x9f,DAT_000bb7a0,0x28f);
            goto LAB_000bb732;
          }
          local_2c[0] = (ASN1_VALUE *)0x0;
          iVar2 = ASN1_item_ex_d2i(local_2c,&local_30,(long)local_3c,param_4->item,-1,0,'\0',param_6
                                  );
          if (iVar2 == 0) {
            line = 0x29a;
            goto LAB_000bb724;
          }
          local_3c = puVar1 + ((int)local_3c - (int)local_30);
          iVar2 = sk_push(*param_1,local_2c[0]);
          puVar1 = local_30;
        } while (iVar2 != 0);
        iVar2 = 0x29f;
      }
      ERR_put_error(0xd,0x83,0x41,DAT_000bb7a0,iVar2);
    }
LAB_000bb732:
    ASN1_template_free((ASN1_VALUE **)param_1,param_4);
  }
  return 0;
}

