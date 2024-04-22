
/* WARNING: Type propagation algorithm not settling */

int OBJ_obj2txt(char *buf,int buf_len,ASN1_OBJECT *a,int no_name)

{
  byte bVar1;
  char *pcVar2;
  int iVar3;
  size_t sVar4;
  void *pvVar5;
  char *pcVar6;
  int *piVar7;
  char cVar8;
  bool bVar9;
  uint uVar10;
  char *pcVar11;
  int iVar12;
  bool bVar13;
  BIGNUM *a_00;
  byte *pbVar14;
  byte *pbVar15;
  bool bVar16;
  char *local_64;
  char *local_60;
  char *local_5c;
  ASN1_OBJECT *local_50;
  int local_4c;
  ASN1_OBJECT *local_48;
  ASN1_OBJECT AStack_44;
  
  pcVar11 = buf;
  if (buf != (char *)0x0) {
    pcVar11 = (char *)0x1;
  }
  bVar16 = (int)buf < 0;
  if (buf != (char *)0x0) {
    bVar16 = buf_len < 0;
  }
  if ((buf != (char *)0x0 && buf_len != 0) && !bVar16) {
    *buf = '\0';
  }
  if (a == (ASN1_OBJECT *)0x0) {
    return 0;
  }
  pbVar14 = a->data;
  if (pbVar14 == (byte *)0x0) {
    return 0;
  }
  if (no_name != 0) {
    iVar12 = a->length;
    goto LAB_0008c782;
  }
  uVar10 = a->nid;
  local_50 = a;
  if (uVar10 == 0) {
    if (a->length == 0) {
      return 0;
    }
    if ((*(_LHASH **)(DAT_0008cac0 + 4) == (_LHASH *)0x0) ||
       (local_4c = no_name, local_48 = a,
       pvVar5 = lh_retrieve(*(_LHASH **)(DAT_0008cac0 + 4),&local_4c), pvVar5 == (void *)0x0)) {
      piVar7 = (int *)OBJ_bsearch_ex__constprop_9(&local_50);
      if (piVar7 == (int *)0x0) {
        iVar12 = a->length;
        pbVar14 = a->data;
        goto LAB_0008c782;
      }
      uVar10 = *(uint *)(DAT_0008cac8 + *piVar7 * 0x18 + 8);
    }
    else {
      uVar10 = *(uint *)(*(int *)((int)pvVar5 + 4) + 8);
    }
    if (uVar10 != 0) goto LAB_0008c980;
  }
  else {
LAB_0008c980:
    if (uVar10 < 0x3be) {
      iVar12 = DAT_0008cac8 + uVar10 * 0x18;
      if (*(int *)(iVar12 + 8) == 0) {
        iVar12 = 0x176;
        goto LAB_0008c99c;
      }
LAB_0008ca0e:
      pcVar6 = *(char **)(iVar12 + 4);
      if (pcVar6 != (char *)0x0) goto LAB_0008c9c8;
    }
    else if (*(_LHASH **)(DAT_0008cac0 + 4) != (_LHASH *)0x0) {
      local_48 = &AStack_44;
      local_4c = 3;
      AStack_44.nid = uVar10;
      pvVar5 = lh_retrieve(*(_LHASH **)(DAT_0008cac0 + 4),&local_4c);
      if (pvVar5 != (void *)0x0) {
        iVar12 = *(int *)((int)pvVar5 + 4);
        goto LAB_0008ca0e;
      }
      iVar12 = 0x184;
LAB_0008c99c:
      ERR_put_error(8,0x66,0x65,DAT_0008cacc,iVar12);
    }
    if (uVar10 < 0x3be) {
      if (*(int *)(DAT_0008cac8 + uVar10 * 0x18 + 8) == 0) {
        iVar12 = 0x15b;
LAB_0008caa8:
        ERR_put_error(8,0x68,0x65,DAT_0008cacc,iVar12);
      }
      else {
        pcVar6 = *(char **)(DAT_0008cac8 + uVar10 * 0x18);
joined_r0x0008ca98:
        if (pcVar6 != (char *)0x0) {
LAB_0008c9c8:
          if (pcVar11 != (char *)0x0) {
            BUF_strlcpy(buf,pcVar6,buf_len);
          }
          pcVar11 = (char *)strlen(pcVar6);
          return (int)pcVar11;
        }
      }
    }
    else if (*(_LHASH **)(DAT_0008cac0 + 4) != (_LHASH *)0x0) {
      local_48 = &AStack_44;
      local_4c = 3;
      AStack_44.nid = uVar10;
      pvVar5 = lh_retrieve(*(_LHASH **)(DAT_0008cac0 + 4),&local_4c);
      if (pvVar5 == (void *)0x0) {
        iVar12 = 0x169;
        goto LAB_0008caa8;
      }
      pcVar6 = **(char ***)((int)pvVar5 + 4);
      goto joined_r0x0008ca98;
    }
  }
  pbVar14 = a->data;
  iVar12 = a->length;
LAB_0008c782:
  if (iVar12 < 1) {
    return (int)(char *)0x0;
  }
  a_00 = (BIGNUM *)0x0;
  local_64 = (char *)0x0;
  bVar16 = true;
  local_60 = buf;
  local_5c = (char *)buf_len;
  do {
    uVar10 = 0;
    bVar13 = false;
    pbVar15 = pbVar14;
    while( true ) {
      pbVar14 = pbVar15 + 1;
      bVar1 = *pbVar15;
      iVar12 = iVar12 + -1;
      pcVar11 = (char *)(uint)(iVar12 == 0 & bVar1 >> 7);
      if (pcVar11 != (char *)0x0) goto joined_r0x0008ca68;
      if (bVar13) {
        iVar3 = BN_add_word(a_00,bVar1 & 0x7f);
        if (iVar3 == 0) goto joined_r0x0008ca68;
      }
      else {
        uVar10 = uVar10 | bVar1 & 0x7f;
      }
      if ((bVar1 & 0x80) == 0) break;
      bVar9 = (bool)(bVar13 ^ 1);
      if (uVar10 < 0x2000000) {
        bVar9 = false;
      }
      pbVar15 = pbVar14;
      if (bVar9) {
        if ((a_00 == (BIGNUM *)0x0) && (a_00 = BN_new(), a_00 == (BIGNUM *)0x0)) {
          return 0xffffffff;
        }
        iVar3 = BN_set_word(a_00,uVar10);
        if (iVar3 == 0) goto LAB_0008c806;
        bVar13 = true;
LAB_0008c7f4:
        iVar3 = BN_lshift(a_00,a_00,7);
        if (iVar3 == 0) goto joined_r0x0008ca68;
      }
      else {
        if (bVar13) goto LAB_0008c7f4;
        uVar10 = uVar10 << 7;
      }
    }
    if (bVar16) {
      if (uVar10 < 0x50) {
        cVar8 = (char)(uVar10 / 0x28);
        uVar10 = uVar10 % 0x28;
      }
      else {
        if (bVar13) {
          iVar3 = BN_sub_word(a_00,0x50);
          if (iVar3 == 0) goto joined_r0x0008ca68;
        }
        else {
          uVar10 = uVar10 - 0x50;
        }
        cVar8 = '\x02';
      }
      bVar16 = local_60 != (char *)0x0;
      pcVar11 = local_60;
      if (bVar16) {
        pcVar11 = local_5c + -1;
      }
      if ((bVar16 && local_5c != (char *)0x1) &&
          (int)pcVar11 < 0 == (bVar16 && SBORROW4((int)local_5c,1))) {
        *local_60 = cVar8 + '0';
        local_5c = local_5c + -1;
        local_60[1] = '\0';
        local_60 = local_60 + 1;
      }
      pcVar11 = local_64 + 1;
      local_64 = pcVar11;
    }
    cVar8 = (char)pcVar11;
    if (bVar13) {
      pcVar11 = BN_bn2dec(a_00);
      if (pcVar11 == (char *)0x0) {
joined_r0x0008ca68:
        if (a_00 == (BIGNUM *)0x0) {
          return (int)(char *)0xffffffff;
        }
LAB_0008c806:
        BN_free(a_00);
        return (int)(char *)0xffffffff;
      }
      sVar4 = strlen(pcVar11);
      if (local_60 != (char *)0x0) {
        pcVar6 = local_5c;
        pcVar2 = local_60;
        if (1 < (int)local_5c) {
          *local_60 = '.';
          cVar8 = '\0';
          pcVar6 = local_5c + -1;
          pcVar2 = local_60 + 1;
        }
        if (1 < (int)local_5c) {
          local_60[1] = cVar8;
          local_5c = pcVar6;
        }
        BUF_strlcpy(pcVar2,pcVar11,(size_t)local_5c);
        if ((int)local_5c < (int)sVar4) {
          local_60 = pcVar2 + (int)local_5c;
          local_5c = (char *)0x0;
        }
        else {
          local_60 = pcVar2 + sVar4;
          local_5c = local_5c + -sVar4;
        }
      }
      pcVar6 = (char *)(sVar4 + 1);
      CRYPTO_free(pcVar11);
    }
    else {
      BIO_snprintf((char *)&AStack_44,0x1a,DAT_0008cac4,uVar10);
      pcVar6 = (char *)strlen((char *)&AStack_44);
      pcVar11 = local_60;
      if (local_60 != (char *)0x0) {
        pcVar11 = local_5c;
      }
      if ((local_60 != (char *)0x0 && local_5c != (char *)0x0) && -1 < (int)pcVar11) {
        BUF_strlcpy(local_60,(char *)&AStack_44,(size_t)local_5c);
        if ((int)local_5c < (int)pcVar6) {
          pcVar2 = (char *)0x0;
          pcVar11 = local_5c;
        }
        else {
          pcVar2 = local_5c + -(int)pcVar6;
          pcVar11 = pcVar6;
        }
        local_5c = pcVar2;
        local_60 = local_60 + (int)pcVar11;
      }
    }
    local_64 = local_64 + (int)pcVar6;
    bVar16 = false;
    if (iVar12 < 1) {
      if (a_00 != (BIGNUM *)0x0) {
        BN_free(a_00);
        return (int)local_64;
      }
      return (int)local_64;
    }
  } while( true );
}

