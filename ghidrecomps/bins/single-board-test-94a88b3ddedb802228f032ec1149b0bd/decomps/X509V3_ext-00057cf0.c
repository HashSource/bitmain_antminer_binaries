
undefined4 X509V3_ext(undefined4 param_1,undefined4 param_2,_STACK *param_3)

{
  char cVar1;
  int iVar2;
  X509_EXTENSION *ex;
  BIO_METHOD *type;
  BIO *out;
  ASN1_OBJECT *a;
  undefined4 uVar3;
  ASN1_OCTET_STRING *v;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  int iVar8;
  undefined *puVar9;
  uint *local_2ac;
  char acStack_2a8 [128];
  undefined auStack_228 [512];
  undefined auStack_28 [4];
  
  iVar2 = sk_num(param_3);
  if (iVar2 < 1) {
LAB_00057df0:
    uVar3 = 1;
  }
  else {
    iVar8 = 0;
    iVar2 = sk_num(param_3);
    if (0 < iVar2) {
      do {
        ex = (X509_EXTENSION *)sk_value(param_3,iVar8);
        type = BIO_s_mem();
        out = BIO_new(type);
        if (out == (BIO *)0x0) goto LAB_00057df0;
        a = X509_EXTENSION_get_object(ex);
        i2t_ASN1_OBJECT(acStack_2a8,0x80,a);
        iVar2 = X509V3_EXT_print(out,ex,0,0);
        if (iVar2 == 0) {
          v = X509_EXTENSION_get_data(ex);
          ASN1_STRING_print(out,v);
        }
        BIO_ctrl(out,0x73,0,&local_2ac);
        uVar4 = *local_2ac;
        if (uVar4 != 0) {
          uVar7 = 0;
          puVar9 = auStack_228;
          do {
            while( true ) {
              uVar5 = local_2ac[1];
              uVar3 = DAT_00057e00;
              if (*(char *)(uVar5 + uVar7) == '\n') {
                uVar7 = uVar7 + 1;
                uVar3 = DAT_00057dfc;
              }
              if (uVar4 <= uVar7) break;
              pcVar6 = (char *)(uVar5 + uVar7);
              cVar1 = *(char *)(uVar5 + uVar7);
              while (cVar1 == ' ') {
                uVar7 = uVar7 + 1;
                if (uVar4 <= uVar7) goto LAB_00057d92;
                pcVar6 = pcVar6 + 1;
                cVar1 = *pcVar6;
              }
              uVar7 = uVar7 + 1;
              iVar2 = curl_msnprintf(puVar9,auStack_28 + -(int)puVar9,DAT_00057e04,uVar3,cVar1);
              puVar9 = puVar9 + iVar2;
              uVar4 = *local_2ac;
              if (uVar4 <= uVar7) goto LAB_00057d9c;
            }
LAB_00057d92:
            uVar7 = uVar7 + 1;
            uVar4 = *local_2ac;
          } while (uVar7 < uVar4);
        }
LAB_00057d9c:
        Curl_ssl_push_certinfo(param_1,param_2,acStack_2a8,auStack_228);
        iVar8 = iVar8 + 1;
        BIO_free(out);
        iVar2 = sk_num(param_3);
      } while (iVar8 < iVar2);
    }
    uVar3 = 0;
  }
  return uVar3;
}

