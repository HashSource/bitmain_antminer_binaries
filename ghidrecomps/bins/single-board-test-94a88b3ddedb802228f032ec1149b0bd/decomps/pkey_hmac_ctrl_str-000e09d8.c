
uchar * pkey_hmac_ctrl_str(int param_1,char *param_2,uchar *param_3)

{
  int iVar1;
  uchar *data;
  int local_1c [2];
  
  if (param_3 != (uchar *)0x0) {
    if ((((*param_2 == 'k') && (param_2[1] == 'e')) && (param_2[2] == 'y')) && (param_2[3] == '\0'))
    {
      param_3 = (uchar *)ASN1_OCTET_STRING_set
                                   ((ASN1_STRING *)(*(int *)(param_1 + 0x14) + 4),param_3,-1);
      if (param_3 != (uchar *)0x0) {
        param_3 = (uchar *)0x1;
      }
    }
    else {
      iVar1 = strcmp(param_2,DAT_000e0a58);
      if (iVar1 == 0) {
        data = string_to_hex((char *)param_3,local_1c);
        param_3 = data;
        if (data != (uchar *)0x0) {
          if (local_1c[0] + 1 < 0 == SCARRY4(local_1c[0],1)) {
            param_3 = (uchar *)ASN1_OCTET_STRING_set
                                         ((ASN1_STRING *)(*(int *)(param_1 + 0x14) + 4),data,
                                          local_1c[0]);
            if (param_3 != (uchar *)0x0) {
              param_3 = (uchar *)0x1;
            }
          }
          else {
            param_3 = (uchar *)0x0;
          }
          CRYPTO_free(data);
        }
      }
      else {
        param_3 = (uchar *)0xfffffffe;
      }
    }
  }
  return param_3;
}

