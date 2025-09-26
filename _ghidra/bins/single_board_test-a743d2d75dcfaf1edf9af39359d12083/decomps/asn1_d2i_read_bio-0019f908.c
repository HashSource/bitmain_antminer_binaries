
uchar * asn1_d2i_read_bio(BIO *param_1,undefined4 *param_2)

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
    ERR_put_error(0xd,0x6b,0x41,"a_d2i_fp.c",0x9d);
    puVar7 = (uchar *)0xffffffff;
  }
  else {
    puVar6 = (uchar *)0x0;
    puVar7 = (uchar *)0x0;
    iVar8 = 0;
    ERR_clear_error();
LAB_0019f928:
    omax = (int)puVar6 - (int)puVar7;
    if (omax < 9) {
      puVar5 = puVar7 + 8;
      if ((puVar5 < puVar6) || (iVar1 = BUF_MEM_grow_clean(str,(size_t)puVar5), iVar1 == 0)) {
        iVar8 = 0xa7;
LAB_0019fa36:
        ERR_put_error(0xd,0x6b,0x41,"a_d2i_fp.c",iVar8);
        goto LAB_0019fa00;
      }
      uVar2 = BIO_read(param_1,str->data + (int)puVar6,(int)puVar5 - (int)puVar6);
      if (((uint)(puVar6 == puVar7) & uVar2 >> 0x1f) != 0) {
        iVar8 = 0xac;
LAB_0019f9f2:
        ERR_put_error(0xd,0x6b,0x8e,"a_d2i_fp.c",iVar8);
        goto LAB_0019fa00;
      }
      if (0 < (int)uVar2) {
        bVar10 = CARRY4(uVar2,(uint)puVar6);
        puVar6 = puVar6 + uVar2;
        if (!bVar10) {
          omax = (int)puVar6 - (int)puVar7;
          goto LAB_0019f966;
        }
        iVar8 = 0xb1;
        goto LAB_0019fa4c;
      }
    }
LAB_0019f966:
    pcVar9 = str->data;
    local_54[0] = (uchar *)(pcVar9 + (int)puVar7);
    local_48 = ASN1_get_object(local_54,(long *)local_3c,&local_44,&iStack_40,omax);
    if (local_48 << 0x18 < 0) {
      uVar4 = ERR_peek_error();
      if ((uVar4 & 0xfff) != 0x9b) goto LAB_0019fa00;
      ERR_clear_error();
    }
    puVar7 = local_54[0] + ((int)puVar7 - (int)(pcVar9 + (int)puVar7));
    if (local_48 << 0x1f < 0) {
      iVar8 = iVar8 + 1;
      goto LAB_0019f928;
    }
    if ((iVar8 != 0) && (local_3c[0] == 0)) {
      if ((local_44 == 0) && (iVar8 = iVar8 + -1, iVar8 == 0)) goto LAB_0019f9aa;
      goto LAB_0019f928;
    }
    if ((uint)((int)puVar6 - (int)puVar7) < local_3c[0]) {
      puVar5 = puVar7 + local_3c[0];
      iVar1 = (int)puVar5 - (int)puVar6;
      if ((iVar1 < 0) || (puVar5 < puVar6)) {
        iVar8 = 0xdf;
        goto LAB_0019fa4c;
      }
      iVar3 = BUF_MEM_grow_clean(str,(size_t)puVar5);
      if (iVar3 == 0) {
        iVar8 = 0xe3;
        goto LAB_0019fa36;
      }
      for (; iVar1 != 0; iVar1 = iVar1 - iVar3) {
        iVar3 = BIO_read(param_1,str->data + (int)puVar6,iVar1);
        puVar6 = puVar6 + iVar3;
        if (iVar3 < 1) {
          iVar8 = 0xea;
          goto LAB_0019f9f2;
        }
      }
    }
    bVar10 = CARRY4(local_3c[0],(uint)puVar7);
    puVar7 = puVar7 + local_3c[0];
    if (bVar10) {
      iVar8 = 0xf6;
      goto LAB_0019fa4c;
    }
    if (iVar8 != 0) goto LAB_0019f928;
LAB_0019f9aa:
    if ((int)puVar7 < 0) {
      iVar8 = 0x102;
LAB_0019fa4c:
      ERR_put_error(0xd,0x6b,0x9b,"a_d2i_fp.c",iVar8);
LAB_0019fa00:
      BUF_MEM_free(str);
      puVar7 = (uchar *)0xffffffff;
    }
    else {
      *param_2 = str;
    }
  }
  return puVar7;
}

