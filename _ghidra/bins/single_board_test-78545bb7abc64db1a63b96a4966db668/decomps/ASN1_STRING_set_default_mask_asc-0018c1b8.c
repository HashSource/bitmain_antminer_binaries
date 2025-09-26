
int ASN1_STRING_set_default_mask_asc(char *p)

{
  int iVar1;
  ulong mask;
  char *local_c;
  
  iVar1 = strncmp(p,"MASK:",5);
  if (iVar1 == 0) {
    if ((p[5] == '\0') || (mask = strtoul(p + 5,&local_c,0), *local_c != '\0')) {
      return 0;
    }
  }
  else {
    iVar1 = strcmp(p,"nombstr");
    if (iVar1 == 0) {
      mask = 0xffffd7ff;
    }
    else {
      iVar1 = strcmp(p,"pkix");
      if (iVar1 == 0) {
        mask = 0xfffffffb;
      }
      else {
        iVar1 = strcmp(p,"utf8only");
        if (iVar1 == 0) {
          mask = 0x2000;
        }
        else {
          iVar1 = strcmp(p,"default");
          if (iVar1 != 0) {
            return 0;
          }
          mask = 0xffffffff;
        }
      }
    }
  }
  ASN1_STRING_set_default_mask(mask);
  return 1;
}

