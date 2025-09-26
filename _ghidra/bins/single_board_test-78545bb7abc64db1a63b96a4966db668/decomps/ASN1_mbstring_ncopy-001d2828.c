
int ASN1_mbstring_ncopy(ASN1_STRING **out,uchar *in,int len,int inform,ulong mask,long minsize,
                       long maxsize)

{
  uchar *puVar1;
  uchar *puVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  ASN1_STRING *str;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  uint uVar9;
  uchar *puVar10;
  uint uVar11;
  byte *pbVar12;
  code *pcVar13;
  bool bVar14;
  uint local_5c;
  uchar *local_4c;
  uint local_48 [9];
  
  if (len == -1) {
    len = strlen((char *)in);
  }
  if (mask == 0) {
    mask = 0x2806;
  }
  switch(inform) {
  case 0x1000:
    if (len != 0) {
      local_5c = 0;
      uVar9 = len;
      puVar10 = in;
      do {
        local_5c = local_5c + 1;
        iVar6 = UTF8_getc(puVar10,uVar9,local_48);
        puVar10 = puVar10 + iVar6;
        if (iVar6 < 0) {
          ERR_put_error(0xd,0x7a,0x86,"crypto/asn1/a_mbstr.c",0x55);
          return -1;
        }
        uVar9 = uVar9 - iVar6;
      } while (uVar9 != 0);
      break;
    }
  case 0x1001:
    local_5c = len;
    break;
  case 0x1002:
    if (len << 0x1f < 0) {
      ERR_put_error(0xd,0x7a,0x81,"crypto/asn1/a_mbstr.c",0x41);
      return -1;
    }
    local_5c = len >> 1;
    break;
  default:
    ERR_put_error(0xd,0x7a,0xa0,"crypto/asn1/a_mbstr.c",0x5f);
    return -1;
  case 0x1004:
    if ((len & 3U) != 0) {
      ERR_put_error(0xd,0x7a,0x85,"crypto/asn1/a_mbstr.c",0x4a);
      return -1;
    }
    local_5c = len >> 2;
  }
  bVar14 = minsize == 0;
  iVar6 = minsize;
  if (0 < minsize) {
    iVar6 = minsize - local_5c;
    bVar14 = minsize == local_5c;
  }
  if (!bVar14 && iVar6 < 0 == (0 < minsize && SBORROW4(minsize,local_5c))) {
    ERR_put_error(0xd,0x7a,0x98,"crypto/asn1/a_mbstr.c",100);
    BIO_snprintf((char *)local_48,0x20,"%ld",minsize);
    ERR_add_error_data(2,"minsize=",local_48);
    return -1;
  }
  pbVar12 = in;
  uVar9 = len;
  if (maxsize < (int)local_5c && 0 < maxsize) {
    ERR_put_error(0xd,0x7a,0x97,"crypto/asn1/a_mbstr.c",0x6b);
    BIO_snprintf((char *)local_48,0x20,"%ld",maxsize);
    ERR_add_error_data(2,"maxsize=",local_48);
    return -1;
  }
joined_r0x001d2894:
  do {
    if (uVar9 == 0) {
      if ((int)(mask << 0x1f) < 0) {
        iVar8 = 0x1001;
        iVar6 = 0x12;
      }
      else if ((int)(mask << 0x1e) < 0) {
        iVar8 = 0x1001;
        iVar6 = 0x13;
      }
      else if ((int)(mask << 0x1b) < 0) {
        iVar8 = 0x1001;
        iVar6 = 0x16;
      }
      else if ((int)(mask << 0x1d) < 0) {
        iVar8 = 0x1001;
        iVar6 = 0x14;
      }
      else if ((int)(mask << 0x14) < 0) {
        iVar8 = 0x1002;
        iVar6 = 0x1e;
      }
      else {
        iVar8 = 0x1004;
        if ((mask & 0x100) == 0) {
          iVar8 = 0x1000;
          iVar6 = 0xc;
        }
        else {
          iVar6 = 0x1c;
        }
      }
      if (out == (ASN1_STRING **)0x0) {
        return iVar6;
      }
      str = *out;
      if (str == (ASN1_STRING *)0x0) {
        str = ASN1_STRING_type_new(iVar6);
        if (str == (ASN1_STRING *)0x0) {
          iVar6 = 0x98;
          goto LAB_001d2cd4;
        }
        bVar14 = true;
        *out = str;
      }
      else {
        CRYPTO_free(str->data);
        str->type = iVar6;
        str->data = (uchar *)0x0;
        bVar14 = false;
        str->length = 0;
      }
      if (iVar8 == inform) {
        iVar8 = ASN1_STRING_set(str,in,len);
        if (iVar8 != 0) {
          return iVar6;
        }
        iVar6 = 0xa0;
        goto LAB_001d2cd4;
      }
      switch(iVar8) {
      case 0x1000:
        goto switchD_001d2978_caseD_1000;
      case 0x1001:
        iVar8 = local_5c + 1;
        pcVar13 = (code *)0x1d2721;
        goto LAB_001d2a6a;
      case 0x1002:
        local_5c = local_5c * 2;
        pcVar13 = (code *)0x1d2731;
        iVar8 = local_5c + 1;
        goto LAB_001d2a6a;
      default:
        local_5c = 0;
        pcVar13 = (code *)0x0;
        iVar8 = 1;
        goto LAB_001d2a6a;
      case 0x1004:
        local_5c = local_5c * 4;
        pcVar13 = (code *)0x1d274d;
        iVar8 = local_5c + 1;
        goto LAB_001d2a6a;
      }
    }
    if (inform == 0x1001) {
      local_48[0] = (uint)*pbVar12;
      uVar9 = uVar9 - 1;
      pbVar7 = pbVar12 + 1;
    }
    else if (inform == 0x1002) {
      uVar9 = uVar9 - 2;
      pbVar7 = pbVar12 + 2;
      local_48[0] = (uint)CONCAT11(*pbVar12,pbVar12[1]);
    }
    else if (inform == 0x1004) {
      uVar9 = uVar9 - 4;
      pbVar7 = pbVar12 + 4;
      local_48[0] = (uint)pbVar12[1] << 0x10 | (uint)*pbVar12 << 0x18 | (uint)pbVar12[3] |
                    (uint)pbVar12[2] << 8;
    }
    else {
      iVar6 = UTF8_getc(pbVar12,uVar9,local_48);
      if (iVar6 < 0) goto LAB_001d2d20;
      uVar9 = uVar9 - iVar6;
      pbVar7 = pbVar12 + iVar6;
    }
    uVar5 = local_48[0];
    uVar11 = local_48[0];
    if ((int)local_48[0] < 0) {
      uVar11 = 0x7fffffff;
    }
    if ((int)(mask << 0x1f) < 0) {
      iVar6 = ossl_ctype_check(uVar11,4);
      iVar8 = uVar11 - 0x20;
      if (iVar8 != 0) {
        iVar8 = 1;
      }
      if (iVar6 != 0) {
        iVar8 = 0;
      }
      if (iVar8 != 0) {
        mask = mask & 0xfffffffe;
      }
    }
    if (((int)(mask << 0x1e) < 0) && (iVar6 = ossl_ctype_check(uVar11,0x800), iVar6 == 0)) {
      mask = mask & 0xfffffffd;
    }
    if (((int)(mask << 0x1b) < 0) && ((uVar11 & 0xffffff80) != 0)) {
      mask = mask & 0xffffffef;
    }
    if (((uint)(0xff < uVar5) & mask >> 2) != 0) {
      mask = mask & 0xfffffffb;
    }
    pbVar12 = pbVar7;
    if ((int)(mask << 0x14) < 0) {
      if (uVar5 < 0x10000) goto joined_r0x001d2894;
      mask = mask & 0xfffff7ff;
    }
    if (mask == 0) {
LAB_001d2d20:
      ERR_put_error(0xd,0x7a,0x7c,"crypto/asn1/a_mbstr.c",0x73);
      return -1;
    }
  } while( true );
switchD_001d2978_caseD_1000:
  iVar8 = 1;
  local_5c = len;
  if (len == 0) goto LAB_001d2bf6;
  if (inform == 0x1001) {
    local_5c = 0;
    uVar9 = len;
    pbVar12 = in;
    do {
      local_48[0] = (uint)*pbVar12;
      uVar9 = uVar9 - 1;
      iVar8 = UTF8_putc((uchar *)0x0,-1,local_48[0]);
      local_5c = local_5c + iVar8;
      pbVar12 = pbVar12 + 1;
    } while (uVar9 != 0);
  }
  else {
    if (inform == 0x1002) {
      puVar10 = in + 2;
      local_5c = 0;
      uVar9 = len;
      do {
        puVar1 = puVar10 + -2;
        uVar9 = uVar9 - 2;
        puVar2 = puVar10 + -1;
        puVar10 = puVar10 + 2;
        local_48[0] = (uint)CONCAT11(*puVar1,*puVar2);
        iVar8 = UTF8_putc((uchar *)0x0,-1,local_48[0]);
        local_5c = local_5c + iVar8;
      } while (uVar9 != 0);
      goto LAB_001d2d7a;
    }
    if (inform != 0x1004) {
      local_5c = 0;
      uVar9 = len;
      puVar10 = in;
      goto LAB_001d2bd4;
    }
    puVar10 = in + 4;
    local_5c = 0;
    uVar9 = len;
    do {
      pbVar12 = puVar10 + -4;
      uVar9 = uVar9 - 4;
      pbVar7 = puVar10 + -3;
      pbVar3 = puVar10 + -1;
      pbVar4 = puVar10 + -2;
      puVar10 = puVar10 + 4;
      local_48[0] = (uint)*pbVar3 | (uint)*pbVar12 << 0x18 | (uint)*pbVar7 << 0x10 |
                    (uint)*pbVar4 << 8;
      iVar8 = UTF8_putc((uchar *)0x0,-1,local_48[0]);
      local_5c = local_5c + iVar8;
    } while (uVar9 != 0);
  }
  goto LAB_001d2d7a;
  while( true ) {
    puVar10 = puVar10 + iVar8;
    iVar8 = UTF8_putc((uchar *)0x0,-1,local_48[0]);
    local_5c = local_5c + iVar8;
    if (uVar9 == 0) break;
LAB_001d2bd4:
    iVar8 = UTF8_getc(puVar10,uVar9,local_48);
    uVar9 = uVar9 - iVar8;
    if (iVar8 < 0) {
      iVar8 = local_5c + 1;
      goto LAB_001d2bf6;
    }
  }
LAB_001d2d7a:
  iVar8 = local_5c + 1;
LAB_001d2bf6:
  pcVar13 = (code *)0x1d276d;
LAB_001d2a6a:
  local_4c = (uchar *)CRYPTO_malloc(iVar8,"crypto/asn1/a_mbstr.c",0xbd);
  if (local_4c != (uchar *)0x0) {
    str->length = local_5c;
    str->data = local_4c;
    local_4c[local_5c] = '\0';
    if (len != 0) {
      if (inform == 0x1001) {
        if (pcVar13 != (code *)0x0) {
          do {
            local_48[0] = (uint)*in;
            len = len - 1;
            iVar8 = (*pcVar13)(local_48[0],&local_4c);
            if (iVar8 < 1) {
              return iVar6;
            }
            in = in + 1;
          } while (len != 0);
        }
      }
      else if (pcVar13 == (code *)0x0) {
        if ((inform != 0x1004) && (inform != 0x1002)) {
          do {
            iVar8 = UTF8_getc(in,len,local_48);
            in = in + iVar8;
            if (iVar8 < 0) {
              return iVar6;
            }
            len = len - iVar8;
          } while (len != 0);
        }
      }
      else if (inform == 0x1002) {
        puVar10 = in + 2;
        do {
          puVar1 = puVar10 + -2;
          puVar2 = puVar10 + -1;
          len = len - 2;
          puVar10 = puVar10 + 2;
          local_48[0] = (uint)CONCAT11(*puVar1,*puVar2);
          iVar8 = (*pcVar13)(local_48[0],&local_4c);
          if (iVar8 < 1) {
            return iVar6;
          }
        } while (len != 0);
      }
      else if (inform == 0x1004) {
        puVar10 = in + 4;
        do {
          len = len - 4;
          local_48[0] = (uint)puVar10[-1] | (uint)puVar10[-3] << 0x10 | (uint)puVar10[-4] << 0x18 |
                        (uint)puVar10[-2] << 8;
          iVar8 = (*pcVar13)(local_48[0],&local_4c);
          if (iVar8 < 1) {
            return iVar6;
          }
          puVar10 = puVar10 + 4;
        } while (len != 0);
      }
      else {
        do {
          iVar8 = UTF8_getc(in,len,local_48);
          len = len - iVar8;
          in = in + iVar8;
          if (iVar8 < 0) {
            return iVar6;
          }
          iVar8 = (*pcVar13)(local_48[0],&local_4c);
          if (iVar8 < 1) {
            return iVar6;
          }
        } while (len != 0);
      }
    }
    return iVar6;
  }
  if (bVar14) {
    ASN1_STRING_free(str);
  }
  iVar6 = 0xc0;
LAB_001d2cd4:
  ERR_put_error(0xd,0x7a,0x41,"crypto/asn1/a_mbstr.c",iVar6);
  return -1;
}

