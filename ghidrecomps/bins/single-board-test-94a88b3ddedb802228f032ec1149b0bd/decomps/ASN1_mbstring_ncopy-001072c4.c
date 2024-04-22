
int ASN1_mbstring_ncopy(ASN1_STRING **out,uchar *in,int len,int inform,ulong mask,long minsize,
                       long maxsize)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  bool bVar4;
  uint uVar5;
  char *pcVar6;
  int line;
  int iVar7;
  uchar *puVar8;
  uint uVar9;
  int iVar10;
  code *pcVar11;
  byte *pbVar12;
  byte *pbVar13;
  ASN1_STRING *str;
  uint local_64;
  uchar *local_54;
  uint local_50 [2];
  char acStack_48 [36];
  
  if (len == -1) {
    len = strlen((char *)in);
  }
  if (mask == 0) {
    mask = 0x2806;
  }
  local_64 = len;
  switch(inform) {
  case 0x1000:
    if (len != 0) {
      local_64 = 0;
      puVar8 = in;
      uVar9 = len;
      do {
        local_64 = local_64 + 1;
        iVar7 = UTF8_getc(puVar8,uVar9,local_50);
        puVar8 = puVar8 + iVar7;
        if (iVar7 < 0) {
          ERR_put_error(0xd,0x7a,0x86,DAT_00107624,0x88);
          return -1;
        }
        uVar9 = uVar9 - iVar7;
      } while (uVar9 != 0);
    }
    break;
  case 0x1001:
    break;
  case 0x1002:
    if ((len & 1U) != 0) {
      ERR_put_error(0xd,0x7a,0x81,DAT_00107624,0x74);
      return -1;
    }
    local_64 = len >> 1;
    break;
  default:
    ERR_put_error(0xd,0x7a,0xa0,DAT_00107624,0x92);
    return -1;
  case 0x1004:
    if ((len & 3U) != 0) {
      ERR_put_error(0xd,0x7a,0x85,DAT_00107624,0x7d);
      return -1;
    }
    local_64 = len >> 2;
  }
  if ((0 < minsize) && ((int)local_64 < minsize)) {
    ERR_put_error(0xd,0x7a,0x98,DAT_00107824,0x97);
    BIO_snprintf(acStack_48,0x20,DAT_00107828,minsize);
    ERR_add_error_data(2,DAT_00107830,acStack_48);
    return -1;
  }
  pbVar12 = in;
  uVar9 = len;
  if ((0 < maxsize) && (maxsize < (int)local_64)) {
    ERR_put_error(0xd,0x7a,0x97,DAT_00107824,0x9e);
    BIO_snprintf(acStack_48,0x20,DAT_00107828,maxsize);
    ERR_add_error_data(2,DAT_0010782c,acStack_48);
    return -1;
  }
joined_r0x00107326:
  do {
    if (uVar9 == 0) {
      if ((int)(mask << 0x1e) < 0) {
        iVar10 = 0x1001;
        iVar7 = 0x13;
      }
      else if ((int)(mask << 0x1b) < 0) {
        iVar10 = 0x1001;
        iVar7 = 0x16;
      }
      else if ((int)(mask << 0x1d) < 0) {
        iVar10 = 0x1001;
        iVar7 = 0x14;
      }
      else if ((int)(mask << 0x14) < 0) {
        iVar10 = 0x1002;
        iVar7 = 0x1e;
      }
      else {
        iVar10 = 0x1004;
        if ((mask & 0x100) == 0) {
          iVar10 = 0x1000;
          iVar7 = 0xc;
        }
        else {
          iVar7 = 0x1c;
        }
      }
      if (out == (ASN1_STRING **)0x0) {
        return iVar7;
      }
      str = *out;
      if (str == (ASN1_STRING *)0x0) {
        str = ASN1_STRING_type_new(iVar7);
        line = 0xcb;
        if (str == (ASN1_STRING *)0x0) goto LAB_001076d2;
        bVar4 = true;
        *out = str;
      }
      else {
        if (str->data != (uchar *)0x0) {
          str->length = 0;
          CRYPTO_free(str->data);
          str->data = (uchar *)0x0;
        }
        str->type = iVar7;
        bVar4 = false;
      }
      if (inform == iVar10) {
        iVar10 = ASN1_STRING_set(str,in,len);
        if (iVar10 != 0) {
          return iVar7;
        }
        line = 0xd3;
        goto LAB_001076d2;
      }
      switch(iVar10) {
      case 0x1000:
        goto switchD_0010741e_caseD_1000;
      case 0x1001:
        iVar10 = local_64 + 1;
        pcVar11 = DAT_00107630;
        goto LAB_0010757c;
      case 0x1002:
        local_64 = local_64 * 2;
        iVar10 = local_64 + 1;
        pcVar11 = DAT_0010762c;
        goto LAB_0010757c;
      default:
        local_64 = 0;
        iVar10 = 1;
        pcVar11 = (code *)0x0;
        goto LAB_0010757c;
      case 0x1004:
        local_64 = local_64 * 4;
        iVar10 = local_64 + 1;
        pcVar11 = DAT_00107628;
        goto LAB_0010757c;
      }
    }
    if (inform == 0x1001) {
      pbVar13 = pbVar12 + 1;
      local_50[0] = (uint)*pbVar12;
      uVar9 = uVar9 - 1;
    }
    else if (inform == 0x1002) {
      uVar9 = uVar9 - 2;
      pbVar13 = pbVar12 + 2;
      local_50[0] = (uint)CONCAT11(*pbVar12,pbVar12[1]);
    }
    else if (inform == 0x1004) {
      uVar9 = uVar9 - 4;
      pbVar13 = pbVar12 + 4;
      local_50[0] = (uint)pbVar12[1] << 0x10 | (uint)*pbVar12 << 0x18 | (uint)pbVar12[3] |
                    (uint)pbVar12[2] << 8;
    }
    else {
      iVar7 = UTF8_getc(pbVar12,uVar9,local_50);
      if (iVar7 < 0) goto LAB_001076ec;
      uVar9 = uVar9 - iVar7;
      pbVar13 = pbVar12 + iVar7;
    }
    uVar5 = local_50[0];
    if ((int)(mask << 0x1e) < 0) {
      if ((0x7f < local_50[0]) ||
         ((((0x19 < local_50[0] - 0x61 && (0x19 < local_50[0] - 0x41)) && (9 < local_50[0] - 0x30))
          && ((local_50[0] != 0x20 &&
              (pcVar6 = strchr(DAT_00107620,local_50[0]), pcVar6 == (char *)0x0)))))) {
        mask = mask & 0xfffffffd;
        goto LAB_001074d4;
      }
    }
    else {
LAB_001074d4:
      if (((int)(mask << 0x1b) < 0) && (0x7f < uVar5)) {
        mask = mask & 0xffffffef;
      }
    }
    if (((int)(mask << 0x1d) < 0) && (0xff < uVar5)) {
      mask = mask & 0xfffffffb;
    }
    pbVar12 = pbVar13;
    if ((int)(mask << 0x14) < 0) {
      if (uVar5 < 0x10000) goto joined_r0x00107326;
      mask = mask & 0xfffff7ff;
    }
    if (mask == 0) {
LAB_001076ec:
      ERR_put_error(0xd,0x7a,0x7c,DAT_00107824,0xa6);
      return -1;
    }
  } while( true );
switchD_0010741e_caseD_1000:
  iVar10 = 1;
  pcVar11 = DAT_00107820;
  local_64 = len;
  if (len == 0) goto LAB_0010757c;
  if (inform == 0x1001) {
    local_64 = 0;
    uVar9 = len;
    pbVar12 = in;
    do {
      local_50[0] = (uint)*pbVar12;
      uVar9 = uVar9 - 1;
      iVar10 = UTF8_putc((uchar *)0x0,-1,local_50[0]);
      local_64 = local_64 + iVar10;
      pbVar12 = pbVar12 + 1;
    } while (uVar9 != 0);
  }
  else {
    if (inform == 0x1002) {
      local_64 = 0;
      uVar9 = len;
      puVar8 = in;
      do {
        uVar9 = uVar9 - 2;
        local_50[0] = (uint)CONCAT11(*puVar8,puVar8[1]);
        iVar10 = UTF8_putc((uchar *)0x0,-1,local_50[0]);
        local_64 = local_64 + iVar10;
        puVar8 = puVar8 + 2;
      } while (uVar9 != 0);
      goto LAB_00107692;
    }
    if (inform != 0x1004) {
      local_64 = 0;
      uVar9 = len;
      puVar8 = in;
      goto LAB_00107664;
    }
    local_64 = 0;
    uVar9 = len;
    pbVar12 = in;
    do {
      pbVar1 = pbVar12 + 1;
      bVar3 = *pbVar12;
      pbVar2 = pbVar12 + 2;
      uVar9 = uVar9 - 4;
      pbVar13 = pbVar12 + 3;
      pbVar12 = pbVar12 + 4;
      local_50[0] = (uint)*pbVar1 << 0x10 | (uint)bVar3 << 0x18 | (uint)*pbVar13 |
                    (uint)*pbVar2 << 8;
      iVar10 = UTF8_putc((uchar *)0x0,-1,local_50[0]);
      local_64 = local_64 + iVar10;
    } while (uVar9 != 0);
  }
  goto LAB_00107692;
  while( true ) {
    iVar10 = UTF8_putc((uchar *)0x0,-1,local_50[0]);
    local_64 = local_64 + iVar10;
    if (uVar9 == 0) break;
LAB_00107664:
    iVar10 = UTF8_getc(puVar8,uVar9,local_50);
    uVar9 = uVar9 - iVar10;
    puVar8 = puVar8 + iVar10;
    if (iVar10 < 0) {
      iVar10 = local_64 + 1;
      pcVar11 = DAT_00107820;
      goto LAB_0010757c;
    }
  }
LAB_00107692:
  iVar10 = local_64 + 1;
  pcVar11 = DAT_00107820;
LAB_0010757c:
  local_54 = (uchar *)CRYPTO_malloc(iVar10,DAT_00107624,0xf0);
  if (local_54 == (uchar *)0x0) {
    if (bVar4) {
      ASN1_STRING_free(str);
    }
    line = 0xf3;
LAB_001076d2:
    iVar7 = -1;
    ERR_put_error(0xd,0x7a,0x41,DAT_00107824,line);
  }
  else {
    str->length = local_64;
    str->data = local_54;
    local_54[local_64] = '\0';
    if (len != 0) {
      pbVar12 = in;
      if (inform == 0x1001) goto LAB_001075f2;
      do {
        if (inform == 0x1002) {
          bVar3 = *in;
          len = len - 2;
          pbVar12 = in + 1;
          in = in + 2;
          local_50[0] = (uint)CONCAT11(bVar3,*pbVar12);
        }
        else if (inform == 0x1004) {
          pbVar12 = in + 1;
          len = len - 4;
          bVar3 = *in;
          pbVar13 = in + 3;
          pbVar1 = in + 2;
          in = in + 4;
          local_50[0] = (uint)*pbVar12 << 0x10 | (uint)bVar3 << 0x18 | (uint)*pbVar13 |
                        (uint)*pbVar1 << 8;
        }
        else {
          iVar10 = UTF8_getc(in,len,local_50);
          if (iVar10 < 0) {
            return iVar7;
          }
          len = len - iVar10;
          in = in + iVar10;
        }
        while( true ) {
          if ((pcVar11 != (code *)0x0) && (iVar10 = (*pcVar11)(local_50[0],&local_54), iVar10 < 1))
          {
            return iVar7;
          }
          if (len == 0) {
            return iVar7;
          }
          pbVar12 = in;
          if (inform != 0x1001) break;
LAB_001075f2:
          in = pbVar12 + 1;
          local_50[0] = (uint)*pbVar12;
          len = len - 1;
        }
      } while( true );
    }
  }
  return iVar7;
}

