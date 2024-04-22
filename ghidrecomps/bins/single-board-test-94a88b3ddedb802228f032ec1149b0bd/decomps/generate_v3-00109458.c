
ASN1_TYPE * generate_v3(char *param_1,X509V3_CTX *param_2,int param_3,undefined4 *param_4)

{
  int *piVar1;
  uchar *puVar2;
  ASN1_TYPE *pAVar3;
  uint uVar4;
  _STACK *st;
  _STACK *section;
  void *pvVar5;
  int iVar6;
  ASN1_STRING *pAVar7;
  int *piVar8;
  uchar *ptr;
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
  puVar2 = (uchar *)CONF_parse_list(param_1,0x2c,1,DAT_00109704,local_1d0);
  if (puVar2 != (uchar *)0x0) {
    *param_4 = 0xc2;
    return (ASN1_TYPE *)0x0;
  }
  if (local_1d0[2] - 0x10U < 2) {
    if (param_2 == (X509V3_CTX *)0x0) {
      *param_4 = 0xc0;
      return (ASN1_TYPE *)0x0;
    }
    if (0x31 < param_3) {
      *param_4 = 0xb5;
      return (ASN1_TYPE *)0x0;
    }
    local_1d4 = puVar2;
    st = sk_new_null();
    if (st == (_STACK *)0x0) {
LAB_0010971c:
      section = (_STACK *)0x0;
      pAVar3 = (ASN1_TYPE *)0x0;
LAB_001096e2:
      if (local_1d4 != (uchar *)0x0) {
        CRYPTO_free(local_1d4);
      }
      if (st != (_STACK *)0x0) goto LAB_001095c0;
    }
    else {
      section = local_1c0;
      if (local_1c0 != (_STACK *)0x0) {
        section = &X509V3_get_section(param_2,(char *)local_1c0)->stack;
        if (section == (_STACK *)0x0) goto LAB_0010971c;
        param_3 = param_3 + 1;
        iVar9 = 0;
        do {
          iVar6 = sk_num(section);
          if (iVar6 <= iVar9) goto LAB_0010957c;
          pvVar5 = sk_value(section,iVar9);
          pvVar5 = (void *)generate_v3(*(undefined4 *)((int)pvVar5 + 8),param_2,param_3,param_4);
          if (pvVar5 == (void *)0x0) {
            pAVar3 = (ASN1_TYPE *)0x0;
            goto LAB_001096e2;
          }
          iVar6 = sk_push(st,pvVar5);
          iVar9 = iVar9 + 1;
        } while (iVar6 != 0);
        pAVar3 = (ASN1_TYPE *)0x0;
        goto LAB_001096e2;
      }
LAB_0010957c:
      if (local_1d0[2] == 0x11) {
        iVar9 = i2d_ASN1_SET_ANY((ASN1_SEQUENCE_ANY *)st,&local_1d4);
      }
      else {
        iVar9 = i2d_ASN1_SEQUENCE_ANY((ASN1_SEQUENCE_ANY *)st,&local_1d4);
      }
      if (iVar9 < 0) {
        pAVar3 = (ASN1_TYPE *)0x0;
        goto LAB_001096e2;
      }
      pAVar3 = ASN1_TYPE_new();
      if (pAVar3 == (ASN1_TYPE *)0x0) goto LAB_001096e2;
      pAVar7 = ASN1_STRING_type_new(local_1d0[2]);
      (pAVar3->value).asn1_string = pAVar7;
      if (pAVar7 == (ASN1_STRING *)0x0) goto LAB_001096e2;
      pAVar3->type = local_1d0[2];
      pAVar7->length = iVar9;
      pAVar7->data = local_1d4;
      local_1d4 = (uchar *)0x0;
LAB_001095c0:
      sk_pop_free(st,DAT_00109708);
    }
    if (section != (_STACK *)0x0) {
      X509V3_section_free(param_2,(stack_st_CONF_VALUE *)section);
    }
  }
  else {
    pAVar3 = (ASN1_TYPE *)asn1_str2type(local_1c0,local_1d0[3],local_1d0[2]);
  }
  if (pAVar3 == (ASN1_TYPE *)0x0) {
    return (ASN1_TYPE *)0x0;
  }
  if ((local_1d0[0] == -1) && (local_2c == 0)) {
    return pAVar3;
  }
  puVar2 = (uchar *)i2d_ASN1_TYPE(pAVar3,&local_1ec);
  ASN1_TYPE_free(pAVar3);
  local_1e8 = local_1ec;
  if (local_1d0[0] == -1) {
    uVar4 = 0;
    local_1f4 = puVar2;
LAB_001095e0:
    if (0 < local_2c) {
      piVar8 = local_1d0 + (local_2c + -1) * 5;
      iVar9 = 0;
      do {
        iVar9 = iVar9 + 1;
        piVar8[9] = (int)(puVar2 + piVar8[8]);
        puVar2 = (uchar *)ASN1_object_size(0,(int)(puVar2 + piVar8[8]),piVar8[5]);
        piVar8 = piVar8 + -5;
      } while (iVar9 < local_2c);
    }
    ptr = (uchar *)CRYPTO_malloc((int)puVar2,DAT_0010970c,0xf5);
    if (ptr != (uchar *)0x0) {
      if (0 < local_2c) {
        param_3 = 0;
      }
      piVar8 = aiStack_1bc;
      iVar9 = param_3;
      local_1e4 = ptr;
      if (0 < local_2c) {
        do {
          HintPreloadData(piVar8 + 0x24);
          iVar9 = iVar9 + 1;
          ASN1_put_object(&local_1e4,piVar8[2],piVar8[4],*piVar8,piVar8[1]);
          piVar1 = piVar8 + 3;
          piVar8 = piVar8 + 5;
          if (*piVar1 != 0) {
            *local_1e4 = (uchar)param_3;
            local_1e4 = local_1e4 + 1;
          }
        } while (iVar9 < local_2c);
      }
      if (local_1d0[0] != -1) {
        if ((local_1d0[1] == 0) && (local_1d0[0] - 0x10U < 2)) {
          uVar4 = 0x20;
        }
        ASN1_put_object(&local_1e4,uVar4,local_1e0,local_1d0[0],local_1d0[1]);
      }
      memcpy(local_1e4,local_1e8,(size_t)local_1f4);
      local_1d4 = ptr;
      pAVar3 = d2i_ASN1_TYPE((ASN1_TYPE **)0x0,&local_1d4,(long)puVar2);
      goto LAB_001094f0;
    }
  }
  else {
    uVar4 = ASN1_get_object(&local_1e8,&local_1e0,&iStack_1dc,&iStack_1d8,(long)puVar2);
    if ((uVar4 & 0x80) == 0) {
      bVar10 = -1 < (int)(uVar4 << 0x1f);
      if (bVar10) {
        uVar4 = uVar4 & 0x20;
        iVar9 = local_1e0;
      }
      else {
        uVar4 = 2;
        iVar9 = 0;
      }
      local_1f4 = local_1ec + ((int)puVar2 - (int)local_1e8);
      if (!bVar10) {
        local_1e0 = iVar9;
      }
      puVar2 = (uchar *)ASN1_object_size(0,iVar9,local_1d0[0]);
      goto LAB_001095e0;
    }
  }
  ptr = (uchar *)0x0;
  pAVar3 = (ASN1_TYPE *)0x0;
LAB_001094f0:
  if (local_1ec != (uchar *)0x0) {
    CRYPTO_free(local_1ec);
  }
  if (ptr != (uchar *)0x0) {
    CRYPTO_free(ptr);
  }
  return pAVar3;
}

