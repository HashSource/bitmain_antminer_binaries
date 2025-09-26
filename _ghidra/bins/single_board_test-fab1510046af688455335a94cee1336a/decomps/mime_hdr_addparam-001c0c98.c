
char * mime_hdr_addparam(int param_1,char *param_2,char *param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  ushort **ppuVar3;
  __int32_t **pp_Var4;
  char *data;
  ushort uVar5;
  
  if (param_2 == (char *)0x0) {
    pbVar2 = (byte *)0x0;
  }
  else {
    pbVar2 = (byte *)BUF_strdup(param_2);
    if (pbVar2 == (byte *)0x0) {
      return (char *)0x0;
    }
    uVar5 = (ushort)*pbVar2;
    if (uVar5 != 0) {
      ppuVar3 = __ctype_b_loc();
      pbVar1 = pbVar2;
      do {
        if ((int)((uint)(*ppuVar3)[(short)uVar5] << 0x17) < 0) {
          pp_Var4 = __ctype_tolower_loc();
          *pbVar1 = (byte)(*pp_Var4)[(short)uVar5];
        }
        uVar5 = (ushort)pbVar1[1];
        pbVar1 = pbVar1 + 1;
      } while (uVar5 != 0);
    }
  }
  if (((param_3 == (char *)0x0) || (data = BUF_strdup(param_3), param_3 = data, data != (char *)0x0)
      ) && (data = (char *)CRYPTO_malloc(8,"asn_mime.c",0x360), data != (char *)0x0)) {
    *(byte **)data = pbVar2;
    *(char **)(data + 4) = param_3;
    sk_push(*(_STACK **)(param_1 + 8),data);
    return (char *)0x1;
  }
  return data;
}

