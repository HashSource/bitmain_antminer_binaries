
void SCT_print(int *param_1,BIO *param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  ASN1_GENERALIZEDTIME *s;
  long offset_sec;
  int offset_day;
  char *pcVar3;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r3;
  int iVar4;
  int iVar5;
  char acStack_3c [24];
  
  if (param_4 == 0) {
    BIO_printf(param_2,"%*sSigned Certificate Timestamp:",param_3,"");
    BIO_printf(param_2,"\n%*sVersion   : ",param_3 + 4,"");
    if (*param_1 != 0) goto LAB_001ce8bc;
    BIO_printf(param_2,"v1 (0x0)");
  }
  else {
    iVar1 = CTLOG_STORE_get0_log_by_id(param_4,param_1[3],param_1[4]);
    BIO_printf(param_2,"%*sSigned Certificate Timestamp:",param_3,"");
    BIO_printf(param_2,"\n%*sVersion   : ",param_3 + 4,"");
    if (*param_1 != 0) {
LAB_001ce8bc:
      BIO_printf(param_2,"unknown\n%*s",param_3 + 0x10,"");
      BIO_hex_string(param_2,param_3 + 0x10,0x10,param_1[1],param_1[2]);
      return;
    }
    BIO_printf(param_2,"v1 (0x0)");
    if (iVar1 != 0) {
      uVar2 = CTLOG_get0_name(iVar1);
      BIO_printf(param_2,"\n%*sLog       : %s",param_3 + 4,"",uVar2);
    }
  }
  iVar1 = param_3 + 4;
  param_3 = param_3 + 0x10;
  BIO_printf(param_2,"\n%*sLog ID    : ",iVar1,"");
  BIO_hex_string(param_2,param_3,0x10,param_1[3],param_1[4]);
  BIO_printf(param_2,"\n%*sTimestamp : ",iVar1,"");
  iVar4 = param_1[6];
  iVar5 = param_1[7];
  s = ASN1_GENERALIZEDTIME_new();
  if (s != (ASN1_GENERALIZEDTIME *)0x0) {
    __aeabi_uldivmod(iVar4,iVar5,86400000,0);
    offset_sec = __aeabi_uldivmod(extraout_r2,extraout_r3,1000,0);
    offset_day = __aeabi_uldivmod(iVar4,iVar5,86400000,0);
    ASN1_GENERALIZEDTIME_adj(s,0,offset_day,offset_sec);
    uVar2 = ASN1_STRING_get0_data(s);
    __aeabi_uldivmod(iVar4,iVar5,1000,0);
    BIO_snprintf(acStack_3c,0x14,"%.14s.%03dZ",uVar2,extraout_r2_00);
    iVar4 = ASN1_GENERALIZEDTIME_set_string(s,acStack_3c);
    if (iVar4 != 0) {
      ASN1_GENERALIZEDTIME_print(param_2,s);
    }
    ASN1_GENERALIZEDTIME_free(s);
  }
  BIO_printf(param_2,"\n%*sExtensions: ",iVar1,"");
  if (param_1[9] == 0) {
    BIO_printf(param_2,"none");
  }
  else {
    BIO_hex_string(param_2,param_3,0x10,param_1[8],param_1[9]);
  }
  BIO_printf(param_2,"\n%*sSignature : ",iVar1,"");
  iVar4 = SCT_get_signature_nid(param_1);
  if (iVar4 == 0) {
    BIO_printf(param_2,"%02X%02X",(uint)*(byte *)(param_1 + 10),(uint)*(byte *)((int)param_1 + 0x29)
              );
  }
  else {
    pcVar3 = OBJ_nid2ln(iVar4);
    BIO_printf(param_2,"%s",pcVar3);
  }
  BIO_printf(param_2,"\n%*s            ",iVar1,"");
  BIO_hex_string(param_2,param_3,0x10,param_1[0xb],param_1[0xc]);
  return;
}

