
uchar * asn1_d2i_read_bio(BIO *param_1,BUF_MEM **param_2)

{
  BUF_MEM *str;
  int iVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  uchar *puVar5;
  uchar *puVar6;
  uint omax;
  uchar *puVar7;
  int iVar8;
  char *pcVar9;
  bool bVar10;
  uchar *local_54 [3];
  int local_48;
  int local_44;
  int iStack_40;
  uint local_3c [6];
  
  str = BUF_MEM_new();
  if (str == (BUF_MEM *)0x0) {
    ERR_put_error(0xd,0x6b,0x41,DAT_001061cc,0x9d);
    puVar7 = (uchar *)0xffffffff;
  }
  else {
    puVar6 = (uchar *)0x0;
    puVar7 = (uchar *)0x0;
    iVar8 = 0;
    ERR_clear_error();
LAB_00106074:
    omax = (int)puVar6 - (int)puVar7;
    if (omax < 9) {
      puVar5 = puVar7 + 8;
      if ((puVar5 < puVar6) || (iVar1 = BUF_MEM_grow_clean(str,(size_t)puVar5), iVar1 == 0)) {
        iVar8 = 0xa7;
LAB_00106182:
        ERR_put_error(0xd,0x6b,0x41,DAT_001061cc,iVar8);
        goto LAB_0010614c;
      }
      uVar2 = BIO_read(param_1,str->data + (int)puVar6,(int)puVar5 - (int)puVar6);
      if (((uint)(puVar6 == puVar7) & uVar2 >> 0x1f) != 0) {
        iVar8 = 0xac;
LAB_0010613e:
        ERR_put_error(0xd,0x6b,0x8e,DAT_001061cc,iVar8);
        goto LAB_0010614c;
      }
      if (0 < (int)uVar2) {
        bVar10 = CARRY4(uVar2,(uint)puVar6);
        puVar6 = puVar6 + uVar2;
        if (bVar10 == false) {
          omax = (int)puVar6 - (int)puVar7;
          goto LAB_001060b2;
        }
        iVar8 = 0xb1;
        goto LAB_00106198;
      }
    }
LAB_001060b2:
    pcVar9 = str->data;
    local_54[0] = (uchar *)(pcVar9 + (int)puVar7);
    local_48 = ASN1_get_object(local_54,(long *)local_3c,&local_44,&iStack_40,omax);
    if (local_48 << 0x18 < 0) {
      uVar4 = ERR_peek_error();
      if ((uVar4 & 0xfff) != 0x9b) goto LAB_0010614c;
      ERR_clear_error();
    }
    puVar7 = local_54[0] + ((int)puVar7 - (int)(pcVar9 + (int)puVar7));
    if (local_48 << 0x1f < 0) {
      iVar8 = iVar8 + 1;
      goto LAB_00106074;
    }
    if ((iVar8 != 0) && (local_3c[0] == 0)) {
      if ((local_44 == 0) && (iVar8 = iVar8 + -1, iVar8 == 0)) goto LAB_001060f6;
      goto LAB_00106074;
    }
    if ((uint)((int)puVar6 - (int)puVar7) < local_3c[0]) {
      puVar5 = puVar7 + local_3c[0];
      iVar1 = (int)puVar5 - (int)puVar6;
      if ((iVar1 < 0) || (puVar5 < puVar6)) {
        iVar8 = 0xdf;
        goto LAB_00106198;
      }
      iVar3 = BUF_MEM_grow_clean(str,(size_t)puVar5);
      if (iVar3 == 0) {
        iVar8 = 0xe3;
        goto LAB_00106182;
      }
      for (; iVar1 != 0; iVar1 = iVar1 - iVar3) {
        iVar3 = BIO_read(param_1,str->data + (int)puVar6,iVar1);
        puVar6 = puVar6 + iVar3;
        if (iVar3 < 1) {
          iVar8 = 0xea;
          goto LAB_0010613e;
        }
      }
    }
    bVar10 = CARRY4(local_3c[0],(uint)puVar7);
    puVar7 = puVar7 + local_3c[0];
    if (bVar10 != false) {
      iVar8 = 0xf6;
      goto LAB_00106198;
    }
    if (iVar8 != 0) goto LAB_00106074;
LAB_001060f6:
    if ((int)puVar7 < 0) {
      iVar8 = 0x102;
LAB_00106198:
      ERR_put_error(0xd,0x6b,0x9b,DAT_001061cc,iVar8);
LAB_0010614c:
      BUF_MEM_free(str);
      puVar7 = (uchar *)0xffffffff;
    }
    else {
      *param_2 = str;
    }
  }
  return puVar7;
}

