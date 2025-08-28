
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
  undefined *puVar7;
  uint uVar8;
  int iVar9;
  undefined1 *puVar10;
  uint *local_2ac;
  char acStack_2a8 [128];
  undefined1 auStack_228 [512];
  undefined1 auStack_28 [4];
  
  iVar2 = sk_num(param_3);
  if (iVar2 < 1) {
LAB_00057df0:
    uVar3 = 1;
  }
  else {
    iVar9 = 0;
    iVar2 = sk_num(param_3);
    if (0 < iVar2) {
      do {
        ex = (X509_EXTENSION *)sk_value(param_3,iVar9);
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
          uVar8 = 0;
          puVar10 = auStack_228;
          do {
            while( true ) {
              uVar5 = local_2ac[1];
              if (*(char *)(uVar5 + uVar8) == '\n') {
                uVar8 = uVar8 + 1;
                puVar7 = &DAT_0013677c;
              }
              else {
                puVar7 = &DAT_0013a6fc;
              }
              if (uVar4 <= uVar8) break;
              pcVar6 = (char *)(uVar5 + uVar8);
              cVar1 = *(char *)(uVar5 + uVar8);
              while (cVar1 == ' ') {
                uVar8 = uVar8 + 1;
                if (uVar4 <= uVar8) goto LAB_00057d92;
                pcVar6 = pcVar6 + 1;
                cVar1 = *pcVar6;
              }
              uVar8 = uVar8 + 1;
              iVar2 = curl_msnprintf(puVar10,auStack_28 + -(int)puVar10,&DAT_001386d8,puVar7,cVar1);
              puVar10 = puVar10 + iVar2;
              uVar4 = *local_2ac;
              if (uVar4 <= uVar8) goto LAB_00057d9c;
            }
LAB_00057d92:
            uVar8 = uVar8 + 1;
            uVar4 = *local_2ac;
          } while (uVar8 < uVar4);
        }
LAB_00057d9c:
        Curl_ssl_push_certinfo(param_1,param_2,acStack_2a8,auStack_228);
        iVar9 = iVar9 + 1;
        BIO_free(out);
        iVar2 = sk_num(param_3);
      } while (iVar9 < iVar2);
    }
    uVar3 = 0;
  }
  return uVar3;
}

