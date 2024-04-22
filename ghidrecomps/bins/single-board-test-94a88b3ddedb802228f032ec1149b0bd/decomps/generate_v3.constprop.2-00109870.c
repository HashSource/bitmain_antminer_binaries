
_STACK * generate_v3_constprop_2(char *param_1,X509V3_CTX *param_2,undefined4 *param_3)

{
  int *piVar1;
  uchar *puVar2;
  _STACK *a;
  uint uVar3;
  _STACK *section;
  void *pvVar4;
  ASN1_STRING *pAVar5;
  _STACK *p_Var6;
  int *piVar7;
  uchar *ptr;
  int iVar8;
  int iVar9;
  bool bVar10;
  uchar *local_1f4;
  uchar *local_1ec;
  uchar *local_1e8;
  uchar *local_1e4;
  int local_1e0;
  int iStack_1dc;
  int iStack_1d8;
  uchar *local_1d4;
  int local_1d0 [4];
  _STACK *local_1c0;
  int aiStack_1bc [100];
  int local_2c;
  
  local_1d0[3] = 1;
  local_1d0[0] = -1;
  local_1d0[1] = -1;
  local_2c = 0;
  local_1ec = (uchar *)0x0;
  puVar2 = (uchar *)CONF_parse_list(param_1,0x2c,1,DAT_00109b14,local_1d0);
  if (puVar2 != (uchar *)0x0) {
    *param_3 = 0xc2;
    return (_STACK *)0x0;
  }
  if (local_1d0[2] - 0x10U < 2) {
    if (param_2 == (X509V3_CTX *)0x0) {
      *param_3 = 0xc0;
      return (_STACK *)0x0;
    }
    local_1d4 = puVar2;
    p_Var6 = sk_new_null();
    if (p_Var6 == (_STACK *)0x0) {
LAB_00109b0c:
      a = (_STACK *)0x0;
      section = a;
LAB_00109ae0:
      if (local_1d4 != (uchar *)0x0) {
        CRYPTO_free(local_1d4);
      }
      if (p_Var6 != (_STACK *)0x0) goto LAB_001099be;
    }
    else {
      section = local_1c0;
      if (local_1c0 != (_STACK *)0x0) {
        section = &X509V3_get_section(param_2,(char *)local_1c0)->stack;
        iVar8 = 0;
        if (section == (_STACK *)0x0) goto LAB_00109b0c;
        do {
          iVar9 = sk_num(section);
          if (iVar9 <= iVar8) goto LAB_0010997a;
          pvVar4 = sk_value(section,iVar8);
          pvVar4 = (void *)generate_v3(*(undefined4 *)((int)pvVar4 + 8),param_2,1,param_3);
          if (pvVar4 == (void *)0x0) {
            a = (_STACK *)0x0;
            goto LAB_00109ae0;
          }
          iVar9 = sk_push(p_Var6,pvVar4);
          iVar8 = iVar8 + 1;
        } while (iVar9 != 0);
        a = (_STACK *)0x0;
        goto LAB_00109ae0;
      }
LAB_0010997a:
      if (local_1d0[2] == 0x11) {
        iVar8 = i2d_ASN1_SET_ANY((ASN1_SEQUENCE_ANY *)p_Var6,&local_1d4);
      }
      else {
        iVar8 = i2d_ASN1_SEQUENCE_ANY((ASN1_SEQUENCE_ANY *)p_Var6,&local_1d4);
      }
      if (iVar8 < 0) {
        a = (_STACK *)0x0;
        goto LAB_00109ae0;
      }
      a = (_STACK *)ASN1_TYPE_new();
      if (a == (_STACK *)0x0) goto LAB_00109ae0;
      pAVar5 = ASN1_STRING_type_new(local_1d0[2]);
      a->data = (char **)pAVar5;
      if (pAVar5 == (ASN1_STRING *)0x0) goto LAB_00109ae0;
      a->num = local_1d0[2];
      pAVar5->length = iVar8;
      pAVar5->data = local_1d4;
      local_1d4 = (uchar *)0x0;
LAB_001099be:
      sk_pop_free(p_Var6,DAT_00109b18);
    }
    if (section != (_STACK *)0x0) {
      X509V3_section_free(param_2,(stack_st_CONF_VALUE *)section);
    }
  }
  else {
    a = (_STACK *)asn1_str2type(local_1c0,local_1d0[3],local_1d0[2]);
  }
  if (a == (_STACK *)0x0) {
    return (_STACK *)0x0;
  }
  if ((local_1d0[0] == -1) && (local_2c == 0)) {
    return a;
  }
  puVar2 = (uchar *)i2d_ASN1_TYPE((ASN1_TYPE *)a,&local_1ec);
  ASN1_TYPE_free((ASN1_TYPE *)a);
  local_1e8 = local_1ec;
  if (local_1d0[0] == -1) {
    uVar3 = 0;
    local_1f4 = puVar2;
LAB_001099de:
    if (0 < local_2c) {
      piVar7 = local_1d0 + (local_2c + -1) * 5;
      iVar8 = 0;
      do {
        iVar8 = iVar8 + 1;
        piVar7[9] = (int)(puVar2 + piVar7[8]);
        puVar2 = (uchar *)ASN1_object_size(0,(int)(puVar2 + piVar7[8]),piVar7[5]);
        piVar7 = piVar7 + -5;
      } while (iVar8 < local_2c);
    }
    ptr = (uchar *)CRYPTO_malloc((int)puVar2,DAT_00109b1c,0xf5);
    if (ptr != (uchar *)0x0) {
      iVar8 = local_1d0[2];
      if (0 < local_2c) {
        iVar8 = 0;
      }
      piVar7 = aiStack_1bc;
      iVar9 = iVar8;
      local_1e4 = ptr;
      if (0 < local_2c) {
        do {
          HintPreloadData(piVar7 + 0x24);
          iVar9 = iVar9 + 1;
          ASN1_put_object(&local_1e4,piVar7[2],piVar7[4],*piVar7,piVar7[1]);
          piVar1 = piVar7 + 3;
          piVar7 = piVar7 + 5;
          if (*piVar1 != 0) {
            *local_1e4 = (uchar)iVar8;
            local_1e4 = local_1e4 + 1;
          }
        } while (iVar9 < local_2c);
      }
      if (local_1d0[0] != -1) {
        if ((local_1d0[1] == 0) && (local_1d0[0] - 0x10U < 2)) {
          uVar3 = 0x20;
        }
        ASN1_put_object(&local_1e4,uVar3,local_1e0,local_1d0[0],local_1d0[1]);
      }
      memcpy(local_1e4,local_1e8,(size_t)local_1f4);
      local_1d4 = ptr;
      p_Var6 = (_STACK *)d2i_ASN1_TYPE((ASN1_TYPE **)0x0,&local_1d4,(long)puVar2);
      goto LAB_00109904;
    }
  }
  else {
    uVar3 = ASN1_get_object(&local_1e8,&local_1e0,&iStack_1dc,&iStack_1d8,(long)puVar2);
    if ((uVar3 & 0x80) == 0) {
      bVar10 = -1 < (int)(uVar3 << 0x1f);
      if (bVar10) {
        uVar3 = uVar3 & 0x20;
        iVar8 = local_1e0;
      }
      else {
        uVar3 = 2;
        iVar8 = 0;
      }
      local_1f4 = local_1ec + ((int)puVar2 - (int)local_1e8);
      if (!bVar10) {
        local_1e0 = iVar8;
      }
      puVar2 = (uchar *)ASN1_object_size(0,iVar8,local_1d0[0]);
      goto LAB_001099de;
    }
  }
  ptr = (uchar *)0x0;
  p_Var6 = (_STACK *)0x0;
LAB_00109904:
  if (local_1ec != (uchar *)0x0) {
    CRYPTO_free(local_1ec);
  }
  if (ptr != (uchar *)0x0) {
    CRYPTO_free(ptr);
  }
  return p_Var6;
}

