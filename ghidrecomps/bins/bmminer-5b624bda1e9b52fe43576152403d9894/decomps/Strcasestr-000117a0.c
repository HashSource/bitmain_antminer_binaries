
/* WARNING: Unknown calling convention */

char * Strcasestr(char *haystack,char *needle)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  int hlen;
  size_t sVar4;
  int nlen;
  __int32_t **pp_Var5;
  char *ret;
  __int32_t *p_Var6;
  char *pcVar7;
  char *lowhay;
  char *lowneedle;
  size_t sVar8;
  char acStack_28 [4];
  
  if (haystack == (char *)0x0 || needle == (char *)0x0) {
    pcVar7 = (char *)0x0;
  }
  else {
    pcVar7 = (char *)0x0;
    sVar3 = strlen(haystack);
    sVar4 = strlen(needle);
    if (sVar3 != 0 && sVar4 != 0) {
      sVar8 = 0;
      iVar1 = -(sVar3 + 0xe & 0xfffffff8);
      iVar2 = -(sVar4 + 0xe & 0xfffffff8);
      if (0 < (int)sVar3) {
        pp_Var5 = __ctype_tolower_loc();
        p_Var6 = *pp_Var5;
        do {
          acStack_28[sVar8 + iVar1] = (char)p_Var6[(byte)haystack[sVar8]];
          sVar8 = sVar8 + 1;
        } while (sVar3 != sVar8);
      }
      if (0 < (int)sVar4) {
        pp_Var5 = __ctype_tolower_loc();
        p_Var6 = *pp_Var5;
        sVar3 = 0;
        do {
          acStack_28[sVar3 + iVar2 + iVar1] = (char)p_Var6[(byte)needle[sVar3]];
          sVar3 = sVar3 + 1;
        } while (sVar4 != sVar3);
      }
      pcVar7 = strstr(acStack_28 + iVar1,acStack_28 + iVar2 + iVar1);
      if (pcVar7 != (char *)0x0) {
        pcVar7 = haystack + ((int)pcVar7 - (int)(acStack_28 + iVar1));
      }
    }
  }
  return pcVar7;
}

