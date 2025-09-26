
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
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar7;
  undefined4 extraout_r3;
  int iVar8;
  int iVar9;
  char acStack_3c [24];
  
  iVar9 = 0;
LAB_0016ec00:
  iVar1 = sk_num(param_2);
  if (iVar1 <= iVar9) {
    return 1;
  }
  do {
    puVar2 = (undefined4 *)sk_value(param_2,iVar9);
    iVar1 = param_4 + 4;
    BIO_printf(param_3,"%*sSigned Certificate Timestamp:",param_4,"");
    BIO_printf(param_3,"\n%*sVersion   : ",iVar1,"");
    if (*(char *)((int)puVar2 + 6) == '\0') {
      iVar8 = param_4 + 0x10;
      BIO_printf(param_3,"v1(0)");
      BIO_printf(param_3,"\n%*sLog ID    : ",iVar1,"");
      BIO_hex_string(param_3,iVar8,0x10,puVar2[2],*(undefined2 *)(puVar2 + 3));
      BIO_printf(param_3,"\n%*sTimestamp : ",iVar1,"");
      uVar6 = puVar2[4];
      uVar7 = puVar2[5];
      s = ASN1_GENERALIZEDTIME_new();
      iVar3 = __aeabi_uldivmod(uVar6,uVar7,86400000,0);
      __aeabi_uldivmod(uVar6,uVar7,86400000,0);
      offset_sec = __aeabi_uldivmod(extraout_r2,extraout_r3,1000,0);
      ASN1_GENERALIZEDTIME_adj(s,0,iVar3,offset_sec);
      puVar4 = ASN1_STRING_data(s);
      __aeabi_uldivmod(uVar6,uVar7,1000,0);
      BIO_snprintf(acStack_3c,0x14,"%.14s.%03dZ",puVar4,extraout_r2_00);
      ASN1_GENERALIZEDTIME_set_string(s,acStack_3c);
      ASN1_GENERALIZEDTIME_print(param_3,s);
      ASN1_GENERALIZEDTIME_free(s);
      BIO_printf(param_3,"\n%*sExtensions: ",iVar1,"");
      if (*(short *)(puVar2 + 7) == 0) {
        BIO_printf(param_3,"none");
      }
      else {
        BIO_hex_string(param_3,iVar8,0x10,puVar2[6],*(short *)(puVar2 + 7));
      }
      BIO_printf(param_3,"\n%*sSignature : ",iVar1,"");
      if (*(char *)((int)puVar2 + 0x1e) == '\x04') {
        if (*(char *)((int)puVar2 + 0x1f) == '\x01') {
          iVar3 = 0x29c;
        }
        else {
          if (*(char *)((int)puVar2 + 0x1f) != '\x03') goto LAB_0016ed32;
          iVar3 = 0x31a;
        }
        pcVar5 = OBJ_nid2ln(iVar3);
        BIO_printf(param_3,"%s",pcVar5);
      }
      else {
LAB_0016ed32:
        BIO_printf(param_3,"%02X%02X");
      }
      BIO_printf(param_3,"\n%*s            ",iVar1,"");
      BIO_hex_string(param_3,iVar8,0x10,puVar2[8],*(undefined2 *)(puVar2 + 9));
    }
    else {
      BIO_printf(param_3,"unknown\n%*s",param_4 + 0x10,"");
      BIO_hex_string(param_3,param_4 + 0x10,0x10,*puVar2,*(undefined2 *)(puVar2 + 1));
    }
    iVar9 = iVar9 + 1;
    iVar1 = sk_num(param_2);
    if (iVar1 <= iVar9) goto LAB_0016ec00;
    BIO_printf(param_3,"\n");
    iVar1 = sk_num(param_2);
    if (iVar1 <= iVar9) {
      return 1;
    }
  } while( true );
}

