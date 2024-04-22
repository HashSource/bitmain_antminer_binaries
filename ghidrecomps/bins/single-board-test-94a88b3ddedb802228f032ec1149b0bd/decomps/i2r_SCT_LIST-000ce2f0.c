
undefined4 i2r_SCT_LIST(undefined4 param_1,_STACK *param_2,BIO *param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  ASN1_GENERALIZEDTIME *s;
  int iVar3;
  long offset_sec;
  uchar *puVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  char acStack_3c [24];
  
  iVar11 = 0;
LAB_000ce300:
  iVar1 = sk_num(param_2);
  if (iVar1 <= iVar11) {
    return 1;
  }
  do {
    puVar2 = (undefined4 *)sk_value(param_2,iVar11);
    iVar1 = param_4 + 4;
    BIO_printf(param_3,DAT_000ce4e0,param_4,DAT_000ce4e4);
    BIO_printf(param_3,DAT_000ce4e8,iVar1,DAT_000ce4e4);
    if (*(char *)((int)puVar2 + 6) == '\0') {
      iVar10 = param_4 + 0x10;
      BIO_printf(param_3,DAT_000ce4ec);
      BIO_printf(param_3,DAT_000ce4f0,iVar1,DAT_000ce4e4);
      BIO_hex_string(param_3,iVar10,0x10,puVar2[2],*(undefined2 *)(puVar2 + 3));
      BIO_printf(param_3,DAT_000ce4f4,iVar1,DAT_000ce4e4);
      uVar6 = puVar2[4];
      uVar8 = puVar2[5];
      s = ASN1_GENERALIZEDTIME_new();
      iVar3 = __aeabi_uldivmod(uVar6,uVar8,DAT_000ce4d8,DAT_000ce4dc);
      uVar7 = DAT_000ce4d8;
      uVar9 = DAT_000ce4dc;
      __aeabi_uldivmod(uVar6,uVar8,DAT_000ce4d8,DAT_000ce4dc);
      offset_sec = __aeabi_uldivmod(uVar7,uVar9,1000,0);
      ASN1_GENERALIZEDTIME_adj(s,0,iVar3,offset_sec);
      puVar4 = ASN1_STRING_data(s);
      uVar7 = 1000;
      __aeabi_uldivmod(uVar6,uVar8,1000,0);
      BIO_snprintf(acStack_3c,0x14,DAT_000ce4f8,puVar4,uVar7);
      ASN1_GENERALIZEDTIME_set_string(s,acStack_3c);
      ASN1_GENERALIZEDTIME_print(param_3,s);
      ASN1_GENERALIZEDTIME_free(s);
      BIO_printf(param_3,DAT_000ce4fc,iVar1,DAT_000ce4e4);
      if (*(short *)(puVar2 + 7) == 0) {
        BIO_printf(param_3,DAT_000ce500);
      }
      else {
        BIO_hex_string(param_3,iVar10,0x10,puVar2[6],*(short *)(puVar2 + 7));
      }
      BIO_printf(param_3,DAT_000ce504,iVar1,DAT_000ce4e4);
      if (*(char *)((int)puVar2 + 0x1e) == '\x04') {
        if (*(char *)((int)puVar2 + 0x1f) == '\x01') {
          iVar3 = 0x29c;
        }
        else {
          if (*(char *)((int)puVar2 + 0x1f) != '\x03') goto LAB_000ce432;
          iVar3 = 0x31a;
        }
        pcVar5 = OBJ_nid2ln(iVar3);
        BIO_printf(param_3,DAT_000ce518,pcVar5);
      }
      else {
LAB_000ce432:
        BIO_printf(param_3,DAT_000ce508);
      }
      BIO_printf(param_3,DAT_000ce50c,iVar1,DAT_000ce4e4);
      BIO_hex_string(param_3,iVar10,0x10,puVar2[8],*(undefined2 *)(puVar2 + 9));
    }
    else {
      BIO_printf(param_3,DAT_000ce514,param_4 + 0x10,DAT_000ce4e4);
      BIO_hex_string(param_3,param_4 + 0x10,0x10,*puVar2,*(undefined2 *)(puVar2 + 1));
    }
    iVar11 = iVar11 + 1;
    iVar1 = sk_num(param_2);
    if (iVar1 <= iVar11) goto LAB_000ce300;
    BIO_printf(param_3,DAT_000ce510);
    iVar1 = sk_num(param_2);
    if (iVar1 <= iVar11) {
      return 1;
    }
  } while( true );
}

