
int OBJ_obj2txt(char *buf,int buf_len,ASN1_OBJECT *a,int no_name)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  size_t sVar4;
  char cVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  uint w;
  int iVar9;
  byte *pbVar10;
  byte *pbVar11;
  BIGNUM *a_00;
  uint uVar12;
  bool bVar13;
  char *local_5c;
  char *local_58;
  char acStack_44 [32];
  
  bVar13 = (int)buf < 0;
  if (buf != (char *)0x0) {
    bVar13 = buf_len < 0;
  }
  if ((buf != (char *)0x0 && buf_len != 0) && !bVar13) {
    *buf = '\0';
  }
  if (a == (ASN1_OBJECT *)0x0) {
    return 0;
  }
  pbVar10 = a->data;
  if (pbVar10 == (byte *)0x0) {
    local_58 = (char *)0x0;
  }
  else {
    if (no_name == 0) {
      iVar9 = OBJ_obj2nid(a);
      if ((iVar9 != 0) &&
         ((pcVar8 = OBJ_nid2ln(iVar9), pcVar8 != (char *)0x0 ||
          (pcVar8 = OBJ_nid2sn(iVar9), pcVar8 != (char *)0x0)))) {
        if (buf != (char *)0x0) {
          OPENSSL_strlcpy(buf,pcVar8,buf_len);
        }
        sVar4 = strlen(pcVar8);
        return sVar4;
      }
      pbVar10 = a->data;
    }
    iVar9 = a->length;
    if (iVar9 < 1) {
      a_00 = (BIGNUM *)0x0;
      local_58 = (char *)0x0;
    }
    else {
      bVar13 = true;
      a_00 = (BIGNUM *)0x0;
      local_58 = (char *)0x0;
      local_5c = (char *)buf_len;
      do {
        w = 0;
        bVar1 = false;
        pbVar11 = pbVar10;
        while( true ) {
          while( true ) {
            pbVar10 = pbVar11 + 1;
            iVar9 = iVar9 + -1;
            uVar12 = (uint)(char)*pbVar11;
            uVar6 = uVar12 >> 0x1f;
            if (iVar9 != 0) {
              uVar6 = 0;
            }
            if (uVar6 != 0) goto LAB_0013e98a;
            uVar6 = *pbVar11 & 0x7f;
            pbVar11 = pbVar10;
            if (bVar1) break;
            w = w | uVar6;
            if (-1 < (int)uVar12) {
              if (!bVar13) goto LAB_0013ea72;
              if (w < 0x50) goto LAB_0013ea36;
              w = w - 0x50;
              goto LAB_0013eb24;
            }
            if (0x1ffffff < w) {
              if (((a_00 != (BIGNUM *)0x0) || (a_00 = BN_new(), a_00 != (BIGNUM *)0x0)) &&
                 (iVar2 = BN_set_word(a_00,w), iVar2 != 0)) {
                bVar1 = true;
                goto LAB_0013e97c;
              }
              goto LAB_0013e98a;
            }
            w = w << 7;
          }
          iVar2 = BN_add_word(a_00,uVar6);
          if (iVar2 == 0) goto LAB_0013e98a;
          if (-1 < (int)uVar12) break;
LAB_0013e97c:
          iVar2 = BN_lshift(a_00,a_00,7);
          if (iVar2 == 0) goto LAB_0013e98a;
        }
        if (bVar13) {
          if (w < 0x50) {
LAB_0013ea36:
            cVar5 = (char)(w / 0x28);
            w = w % 0x28;
          }
          else {
            iVar2 = BN_sub_word(a_00,0x50);
            if (iVar2 == 0) goto LAB_0013e98a;
LAB_0013eb24:
            cVar5 = '\x02';
          }
          bVar13 = buf != (char *)0x0;
          pcVar8 = buf;
          if (bVar13) {
            pcVar8 = local_5c + -1;
          }
          if ((bVar13 && local_5c != (char *)0x1) &&
              (int)pcVar8 < 0 == (bVar13 && SBORROW4((int)local_5c,1))) {
            *buf = cVar5 + '0';
            buf = buf + 1;
            *buf = '\0';
            local_5c = local_5c + -1;
          }
          local_58 = local_58 + 1;
          if (bVar1) goto LAB_0013e9b4;
LAB_0013ea72:
          BIO_snprintf(acStack_44,0x1a,".%lu",w);
          pcVar3 = (char *)strlen(acStack_44);
          pcVar8 = buf;
          if (buf != (char *)0x0) {
            pcVar8 = local_5c;
          }
          if ((buf != (char *)0x0 && local_5c != (char *)0x0) && -1 < (int)pcVar8) {
            OPENSSL_strlcpy(buf,acStack_44,local_5c);
            if ((int)local_5c < (int)pcVar3) {
              pcVar8 = (char *)0x0;
            }
            else {
              pcVar8 = local_5c + -(int)pcVar3;
              local_5c = pcVar3;
            }
            buf = buf + (int)local_5c;
            local_5c = pcVar8;
          }
          local_58 = local_58 + (int)pcVar3;
        }
        else {
LAB_0013e9b4:
          pcVar8 = BN_bn2dec(a_00);
          if (pcVar8 == (char *)0x0) {
LAB_0013e98a:
            BN_free(a_00);
            return -1;
          }
          pcVar3 = (char *)strlen(pcVar8);
          if (buf != (char *)0x0) {
            if (1 < (int)local_5c) {
              *buf = '.';
              buf = buf + 1;
              *buf = '\0';
              local_5c = local_5c + -1;
            }
            OPENSSL_strlcpy(buf,pcVar8,local_5c);
            if ((int)local_5c < (int)pcVar3) {
              pcVar7 = (char *)0x0;
            }
            else {
              pcVar7 = local_5c + -(int)pcVar3;
              local_5c = pcVar3;
            }
            buf = buf + (int)local_5c;
            local_5c = pcVar7;
          }
          local_58 = pcVar3 + (int)(local_58 + 1);
          CRYPTO_free(pcVar8);
        }
        bVar13 = false;
      } while (0 < iVar9);
    }
    BN_free(a_00);
  }
  return (int)local_58;
}

