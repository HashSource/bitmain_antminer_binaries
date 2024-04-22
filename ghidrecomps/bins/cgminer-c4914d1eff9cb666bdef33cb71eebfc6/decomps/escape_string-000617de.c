
char * escape_string(char *str,_Bool isjson)

{
  byte bVar1;
  size_t sVar2;
  char *pcVar3;
  char *pcVar4;
  _Bool isjson_local;
  char *str_local;
  char *buf;
  int count;
  char *ptr;
  
  count = 0;
  for (ptr = str; *ptr != '\0'; ptr = ptr + 1) {
    bVar1 = *ptr;
    if (bVar1 == 0x3d) {
LAB_00061812:
      if (!isjson) {
        count = count + 1;
      }
    }
    else if (bVar1 < 0x3e) {
      if (bVar1 == 0x22) {
        if (isjson) {
          count = count + 1;
        }
      }
      else if (bVar1 == 0x2c) goto LAB_00061812;
    }
    else if (bVar1 == 0x5c) {
      count = count + 1;
    }
    else if (bVar1 == 0x7c) goto LAB_00061812;
  }
  if (count != 0) {
    sVar2 = strlen(str);
    pcVar3 = (char *)_cgmalloc(count + sVar2 + 1,"api-btm.c","escape_string",0x34a);
    str_local = str;
    ptr = pcVar3;
    while (*str_local != '\0') {
      bVar1 = *str_local;
      if (bVar1 == 0x3d) {
LAB_000618a6:
        if (!isjson) {
          *ptr = '\\';
          ptr = ptr + 1;
        }
        *ptr = *str_local;
        str_local = str_local + 1;
        ptr = ptr + 1;
      }
      else if (bVar1 < 0x3e) {
        if (bVar1 == 0x22) {
          if (isjson) {
            *ptr = '\\';
            ptr = ptr + 1;
          }
          *ptr = *str_local;
          str_local = str_local + 1;
          ptr = ptr + 1;
        }
        else {
          if (bVar1 == 0x2c) goto LAB_000618a6;
LAB_0006190c:
          *ptr = *str_local;
          str_local = str_local + 1;
          ptr = ptr + 1;
        }
      }
      else {
        if (bVar1 != 0x5c) {
          if (bVar1 != 0x7c) goto LAB_0006190c;
          goto LAB_000618a6;
        }
        pcVar4 = ptr + 1;
        *ptr = '\\';
        ptr = ptr + 2;
        *pcVar4 = *str_local;
        str_local = str_local + 1;
      }
    }
    *ptr = '\0';
    str = pcVar3;
  }
  return str;
}

