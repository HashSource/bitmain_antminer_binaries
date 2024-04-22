
int ASN1_STRING_set_default_mask_asc(char *p)

{
  int iVar1;
  ulong uVar2;
  char *local_c;
  
  iVar1 = strncmp(p,DAT_0010a39c,5);
  if (iVar1 == 0) {
    if ((p[5] == '\0') || (uVar2 = strtoul(p + 5,&local_c,0), *local_c != '\0')) {
      return 0;
    }
  }
  else {
    iVar1 = strcmp(p,DAT_0010a3a0);
    if (iVar1 == 0) {
      uVar2 = 0xffffd7ff;
    }
    else {
      iVar1 = strcmp(p,DAT_0010a3a8);
      if (iVar1 == 0) {
        uVar2 = 0xfffffffb;
      }
      else {
        iVar1 = strcmp(p,DAT_0010a3ac);
        if (iVar1 == 0) {
          uVar2 = 0x2000;
        }
        else {
          iVar1 = strcmp(p,DAT_0010a3b0);
          uVar2 = 0xffffffff;
          if (iVar1 != 0) {
            return 0;
          }
        }
      }
    }
  }
  *DAT_0010a3a4 = uVar2;
  return 1;
}

