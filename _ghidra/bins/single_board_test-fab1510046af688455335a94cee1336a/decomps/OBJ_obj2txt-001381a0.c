
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
  char extraout_r2;
  char cVar8;
  bool bVar9;
  undefined1 *puVar10;
  uint uVar11;
  char *pcVar12;
  int iVar13;
  bool bVar14;
  BIGNUM *a_00;
  byte *pbVar15;
  byte *pbVar16;
  bool bVar17;
  char *local_64;
  char *local_60;
  char *local_5c;
  ASN1_OBJECT *local_50;
  int local_4c;
  ASN1_OBJECT *local_48;
  ASN1_OBJECT AStack_44;
  
  pcVar12 = buf;
  if (buf != (char *)0x0) {
    pcVar12 = (char *)0x1;
  }
  bVar17 = (int)buf < 0;
  if (buf != (char *)0x0) {
    bVar17 = buf_len < 0;
  }
  if ((buf != (char *)0x0 && buf_len != 0) && !bVar17) {
    *buf = '\0';
  }
  if (a == (ASN1_OBJECT *)0x0) {
    return (int)(char *)0x0;
  }
  pbVar15 = a->data;
  if (pbVar15 == (byte *)0x0) {
    return (int)(char *)0x0;
  }
  if (no_name != 0) {
    iVar13 = a->length;
    goto LAB_001381da;
  }
  uVar11 = a->nid;
  local_50 = a;
  if (uVar11 == 0) {
    if (a->length == 0) {
      return (int)(char *)0x0;
    }
    if ((added == (_LHASH *)0x0) ||
       (local_4c = no_name, local_48 = a, pvVar5 = lh_retrieve(added,&local_4c),
       pvVar5 == (void *)0x0)) {
      piVar7 = (int *)OBJ_bsearch_ex__constprop_9(&local_50);
      if (piVar7 == (int *)0x0) {
        iVar13 = a->length;
        pbVar15 = a->data;
        goto LAB_001381da;
      }
      uVar11 = *(uint *)(&DAT_001fc1c8 + *piVar7 * 0x18);
    }
    else {
      uVar11 = *(uint *)(*(int *)((int)pvVar5 + 4) + 8);
    }
    if (uVar11 != 0) goto LAB_001383d8;
  }
  else {
LAB_001383d8:
    if (uVar11 < 0x3be) {
      puVar10 = &nid_objs + uVar11 * 0x18;
      if (*(int *)(&DAT_001fc1c8 + uVar11 * 0x18) == 0) {
        iVar13 = 0x176;
        goto LAB_001383f4;
      }
LAB_00138466:
      pcVar6 = *(char **)(puVar10 + 4);
      if (pcVar6 != (char *)0x0) goto LAB_00138420;
    }
    else if (added != (_LHASH *)0x0) {
      local_48 = &AStack_44;
      local_4c = 3;
      AStack_44.nid = uVar11;
      pvVar5 = lh_retrieve(added,&local_4c);
      if (pvVar5 != (void *)0x0) {
        puVar10 = *(undefined1 **)((int)pvVar5 + 4);
        goto LAB_00138466;
      }
      iVar13 = 0x184;
LAB_001383f4:
      ERR_put_error(8,0x66,0x65,"obj_dat.c",iVar13);
    }
    if (uVar11 < 0x3be) {
      if (*(int *)(&DAT_001fc1c8 + uVar11 * 0x18) == 0) {
        iVar13 = 0x15b;
LAB_00138500:
        ERR_put_error(8,0x68,0x65,"obj_dat.c",iVar13);
      }
      else {
        pcVar6 = *(char **)(&nid_objs + uVar11 * 0x18);
joined_r0x001384f0:
        if (pcVar6 != (char *)0x0) {
LAB_00138420:
          if (pcVar12 != (char *)0x0) {
            BUF_strlcpy(buf,pcVar6,buf_len);
          }
          pcVar12 = (char *)strlen(pcVar6);
          return (int)pcVar12;
        }
      }
    }
    else if (added != (_LHASH *)0x0) {
      local_48 = &AStack_44;
      local_4c = 3;
      AStack_44.nid = uVar11;
      pvVar5 = lh_retrieve(added,&local_4c);
      if (pvVar5 == (void *)0x0) {
        iVar13 = 0x169;
        goto LAB_00138500;
      }
      pcVar6 = (char *)**(int **)((int)pvVar5 + 4);
      goto joined_r0x001384f0;
    }
  }
  pbVar15 = a->data;
  iVar13 = a->length;
LAB_001381da:
  if (iVar13 < 1) {
    return (int)(char *)0x0;
  }
  a_00 = (BIGNUM *)0x0;
  local_64 = (char *)0x0;
  bVar17 = true;
  local_60 = buf;
  local_5c = (char *)buf_len;
  do {
    uVar11 = 0;
    bVar14 = false;
    pbVar16 = pbVar15;
    while( true ) {
      pbVar15 = pbVar16 + 1;
      bVar1 = *pbVar16;
      iVar13 = iVar13 + -1;
      if ((iVar13 == 0 & bVar1 >> 7) != 0) goto joined_r0x001384c0;
      if (bVar14) {
        iVar3 = BN_add_word(a_00,bVar1 & 0x7f);
        if (iVar3 == 0) goto joined_r0x001384c0;
      }
      else {
        uVar11 = uVar11 | bVar1 & 0x7f;
      }
      if ((bVar1 & 0x80) == 0) break;
      bVar9 = (bool)(bVar14 ^ 1);
      if (uVar11 < 0x2000000) {
        bVar9 = false;
      }
      pbVar16 = pbVar15;
      if (bVar9) {
        if ((a_00 == (BIGNUM *)0x0) && (a_00 = BN_new(), a_00 == (BIGNUM *)0x0)) {
          return (int)(char *)0xffffffff;
        }
        iVar3 = BN_set_word(a_00,uVar11);
        if (iVar3 == 0) goto LAB_0013825e;
        bVar14 = true;
LAB_0013824c:
        iVar3 = BN_lshift(a_00,a_00,7);
        if (iVar3 == 0) goto joined_r0x001384c0;
      }
      else {
        if (bVar14) goto LAB_0013824c;
        uVar11 = uVar11 << 7;
      }
    }
    if (bVar17) {
      if (uVar11 < 0x50) {
        cVar8 = (char)(uVar11 / 0x28);
        uVar11 = uVar11 % 0x28;
      }
      else {
        if (bVar14) {
          iVar3 = BN_sub_word(a_00,0x50);
          if (iVar3 == 0) goto joined_r0x001384c0;
        }
        else {
          uVar11 = uVar11 - 0x50;
        }
        cVar8 = '\x02';
      }
      bVar17 = local_60 != (char *)0x0;
      pcVar12 = local_60;
      if (bVar17) {
        pcVar12 = local_5c + -1;
      }
      if ((bVar17 && local_5c != (char *)0x1) &&
          (int)pcVar12 < 0 == (bVar17 && SBORROW4((int)local_5c,1))) {
        *local_60 = cVar8 + '0';
        local_5c = local_5c + -1;
        local_60[1] = '\0';
        local_60 = local_60 + 1;
      }
      local_64 = local_64 + 1;
    }
    if (bVar14) {
      pcVar12 = BN_bn2dec(a_00);
      if (pcVar12 == (char *)0x0) {
joined_r0x001384c0:
        if (a_00 == (BIGNUM *)0x0) {
          return (int)(char *)0xffffffff;
        }
LAB_0013825e:
        BN_free(a_00);
        return (int)(char *)0xffffffff;
      }
      sVar4 = strlen(pcVar12);
      if (local_60 != (char *)0x0) {
        pcVar6 = local_5c;
        pcVar2 = local_60;
        cVar8 = extraout_r2;
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
        BUF_strlcpy(pcVar2,pcVar12,(size_t)local_5c);
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
      CRYPTO_free(pcVar12);
    }
    else {
      BIO_snprintf((char *)&AStack_44,0x1a,".%lu",uVar11);
      pcVar6 = (char *)strlen((char *)&AStack_44);
      pcVar12 = local_60;
      if (local_60 != (char *)0x0) {
        pcVar12 = local_5c;
      }
      if ((local_60 != (char *)0x0 && local_5c != (char *)0x0) && -1 < (int)pcVar12) {
        BUF_strlcpy(local_60,(char *)&AStack_44,(size_t)local_5c);
        if ((int)local_5c < (int)pcVar6) {
          pcVar2 = (char *)0x0;
          pcVar12 = local_5c;
        }
        else {
          pcVar2 = local_5c + -(int)pcVar6;
          pcVar12 = pcVar6;
        }
        local_5c = pcVar2;
        local_60 = local_60 + (int)pcVar12;
      }
    }
    local_64 = local_64 + (int)pcVar6;
    bVar17 = false;
    if (iVar13 < 1) {
      if (a_00 != (BIGNUM *)0x0) {
        BN_free(a_00);
        return (int)local_64;
      }
      return (int)local_64;
    }
  } while( true );
}

