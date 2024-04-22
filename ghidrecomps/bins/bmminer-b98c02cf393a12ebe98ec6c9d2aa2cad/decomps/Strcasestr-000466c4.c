
byte * Strcasestr(byte *param_1,byte *param_2)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  size_t sVar4;
  __int32_t **pp_Var5;
  char *pcVar6;
  byte *pbVar7;
  undefined *puVar8;
  byte *pbVar9;
  __int32_t *p_Var10;
  undefined uStack_21;
  
  if (param_2 == (byte *)0x0 || param_1 == (byte *)0x0) {
    return (byte *)0x0;
  }
  sVar3 = strlen((char *)param_1);
  sVar4 = strlen((char *)param_2);
  if (sVar4 != 0 && sVar3 != 0) {
    iVar1 = -(sVar3 + 0xe & 0xfffffff8);
    iVar2 = -(sVar4 + 0xe & 0xfffffff8);
    if (0 < (int)sVar3) {
      pp_Var5 = __ctype_tolower_loc();
      p_Var10 = *pp_Var5;
      puVar8 = &uStack_21 + iVar1;
      pbVar7 = param_1;
      do {
        pbVar9 = pbVar7 + 1;
        puVar8 = puVar8 + 1;
        *puVar8 = (char)p_Var10[*pbVar7];
        pbVar7 = pbVar9;
      } while (pbVar9 != param_1 + sVar3);
    }
    if (0 < (int)sVar4) {
      pp_Var5 = __ctype_tolower_loc();
      p_Var10 = *pp_Var5;
      puVar8 = &uStack_21 + iVar2 + iVar1;
      pbVar7 = param_2;
      do {
        pbVar9 = pbVar7 + 1;
        puVar8 = puVar8 + 1;
        *puVar8 = (char)p_Var10[*pbVar7];
        pbVar7 = pbVar9;
      } while (pbVar9 != param_2 + sVar4);
    }
    pcVar6 = strstr(&stack0xffffffe0 + iVar1,&stack0xffffffe0 + iVar2 + iVar1);
    if (pcVar6 != (char *)0x0) {
      return param_1 + ((int)pcVar6 - (int)(&stack0xffffffe0 + iVar1));
    }
  }
  return (byte *)0x0;
}

