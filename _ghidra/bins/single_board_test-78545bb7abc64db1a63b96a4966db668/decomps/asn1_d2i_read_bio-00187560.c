
char * asn1_d2i_read_bio(BIO *param_1,undefined4 *param_2)

{
  BUF_MEM *str;
  int iVar1;
  uint uVar2;
  ulong uVar3;
  uchar *puVar4;
  uchar *puVar5;
  uchar *puVar6;
  uint len;
  uint uVar7;
  uint uVar8;
  int iVar9;
  char *pcVar10;
  bool bVar11;
  uchar *local_38;
  uint local_34;
  int local_30;
  int aiStack_2c [2];
  
  str = BUF_MEM_new();
  if (str == (BUF_MEM *)0x0) {
    ERR_put_error(0xd,0x6b,0x41,"crypto/asn1/a_d2i_fp.c",0x6e);
    return (char *)0xffffffff;
  }
  puVar5 = (uchar *)0x0;
  ERR_clear_error();
  puVar6 = (uchar *)0x0;
  iVar9 = 0;
LAB_001875ae:
  uVar7 = (int)puVar5 - (int)puVar6;
  do {
    if (uVar7 < 9) {
      puVar4 = puVar6 + 8;
      if ((puVar4 < puVar5) || (iVar1 = BUF_MEM_grow_clean(str,(size_t)puVar4), iVar1 == 0)) {
        iVar9 = 0x78;
        goto LAB_0018773c;
      }
      uVar2 = BIO_read(param_1,str->data + (int)puVar5,(int)puVar4 - (int)puVar5);
      if (((uint)(puVar6 == puVar5) & uVar2 >> 0x1f) != 0) {
        iVar9 = 0x7d;
LAB_00187720:
        ERR_put_error(0xd,0x6b,0x8e,"crypto/asn1/a_d2i_fp.c",iVar9);
        goto LAB_0018770e;
      }
      if (0 < (int)uVar2) {
        bVar11 = CARRY4(uVar2,(uint)puVar5);
        puVar5 = puVar5 + uVar2;
        if (bVar11) {
          iVar9 = 0x82;
          goto LAB_00187702;
        }
        uVar7 = (int)puVar5 - (int)puVar6;
      }
    }
    pcVar10 = str->data;
    local_38 = (uchar *)(pcVar10 + (int)puVar6);
    uVar7 = ASN1_get_object(&local_38,(long *)&local_34,&local_30,aiStack_2c,uVar7);
    if ((uVar7 & 0x80) != 0) {
      uVar3 = ERR_peek_error();
      if ((uVar3 & 0xfff) != 0x9b) goto LAB_0018770e;
      ERR_clear_error();
    }
    puVar6 = local_38 + ((int)puVar6 - (int)(pcVar10 + (int)puVar6));
    if ((uVar7 & 1) == 0) break;
    if (iVar9 == -1) {
      ERR_put_error(0xd,0x6b,0x7b,"crypto/asn1/a_d2i_fp.c",0x9c);
      goto LAB_0018770e;
    }
    uVar7 = (int)puVar5 - (int)puVar6;
    iVar9 = iVar9 + 1;
  } while( true );
  if ((iVar9 == 0) || (local_34 != 0)) {
    puVar4 = puVar6 + local_34;
    if ((uint)((int)puVar5 - (int)puVar6) < local_34) {
      uVar7 = (int)puVar4 - (int)puVar5;
      if (((int)uVar7 < 0) || (puVar4 < puVar5)) {
        iVar9 = 0xb1;
        goto LAB_00187702;
      }
      if (uVar7 != 0) {
        uVar2 = 0x4000;
        do {
          uVar8 = uVar2;
          if (uVar7 <= uVar2) {
            uVar8 = uVar7;
          }
          iVar1 = BUF_MEM_grow_clean(str,(size_t)(puVar5 + uVar8));
          len = uVar8;
          if (iVar1 == 0) {
            iVar9 = 0xbe;
LAB_0018773c:
            ERR_put_error(0xd,0x6b,0x41,"crypto/asn1/a_d2i_fp.c",iVar9);
            goto LAB_0018770e;
          }
          do {
            iVar1 = BIO_read(param_1,str->data + (int)puVar5,len);
            puVar5 = puVar5 + iVar1;
            if (iVar1 < 1) {
              iVar9 = 0xc6;
              goto LAB_00187720;
            }
            len = len - iVar1;
          } while (len != 0);
          if (uVar2 < 0x3fffffff) {
            uVar2 = uVar2 << 1;
          }
          uVar7 = uVar7 - uVar8;
        } while (uVar7 != 0);
        puVar4 = puVar6 + local_34;
      }
    }
    bVar11 = puVar4 < puVar6;
    puVar6 = puVar4;
    if (bVar11) {
      iVar9 = 0xd5;
      goto LAB_00187702;
    }
  }
  else {
    if (local_30 != 0) goto LAB_001875ae;
    iVar9 = iVar9 + -1;
  }
  if (iVar9 == 0) {
    if (-1 < (int)puVar6) {
      *param_2 = str;
      return (char *)puVar6;
    }
    iVar9 = 0xe1;
LAB_00187702:
    ERR_put_error(0xd,0x6b,0x9b,"crypto/asn1/a_d2i_fp.c",iVar9);
LAB_0018770e:
    BUF_MEM_free(str);
    return (char *)0xffffffff;
  }
  goto LAB_001875ae;
}

