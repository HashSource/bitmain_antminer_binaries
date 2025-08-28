
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

int dump_string(char *str,json_dump_callback_t dump,void *data,size_t flags)

{
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  uint uVar4;
  byte *buffer;
  uint uVar5;
  byte *pbVar6;
  uint local_34;
  char seq [13];
  
  iVar1 = (*dump)("\"",1,data);
joined_r0x0003d63e:
  do {
    pbVar6 = (byte *)str;
    if (iVar1 != 0) {
      return -1;
    }
    while (buffer = pbVar6, pbVar6 = buffer, *buffer != 0) {
      if ((flags & 0x800) == 0) {
        pbVar6 = (byte *)utf8_iterate((char *)buffer,(int32_t *)&local_34);
      }
      else {
        pbVar6 = buffer + 1;
        local_34 = (uint)*buffer;
      }
      if (pbVar6 == (byte *)0x0) {
        return -1;
      }
      if ((((local_34 == 0x5c || local_34 == 0x22) || ((int)local_34 < 0x20)) ||
          (((flags & 0x400) != 0 && (local_34 == 0x2f)))) ||
         (((flags & 0x40) != 0 && (0x7f < (int)local_34)))) break;
    }
    if ((buffer != (byte *)str) && (iVar1 = (*dump)(str,(int)buffer - (int)str,data), iVar1 != 0)) {
      return -1;
    }
    if (pbVar6 == buffer) {
      iVar1 = (*dump)("\"",1,data);
      return iVar1;
    }
    str = (char *)pbVar6;
    if (local_34 == 0xc) {
      sVar3 = 2;
      pcVar2 = "\\f";
    }
    else if ((int)local_34 < 0xd) {
      if (local_34 == 9) {
        sVar3 = 2;
        pcVar2 = "\\t";
      }
      else if (local_34 == 10) {
        sVar3 = 2;
        pcVar2 = "\\n";
      }
      else {
        if (local_34 != 8) goto LAB_0003d66e;
        sVar3 = 2;
        pcVar2 = "\\b";
      }
    }
    else if (local_34 == 0x22) {
      pcVar2 = "\\\"";
      sVar3 = 2;
    }
    else if ((int)local_34 < 0x23) {
      if (local_34 == 0xd) {
        iVar1 = (*dump)("\\r",2,data);
        goto joined_r0x0003d63e;
      }
LAB_0003d66e:
      if ((int)local_34 < 0x10000) {
        sprintf(seq,"\\u%04x");
        pcVar2 = seq;
        sVar3 = 6;
      }
      else {
        uVar5 = local_34 - 0x10000;
        uVar4 = local_34 & 0x3ff;
        local_34 = uVar5;
        sprintf(seq,"\\u%04x\\u%04x",uVar5 * 0x1000 >> 0x16 | 0xd800,uVar4 | 0xdc00);
        pcVar2 = seq;
        sVar3 = 0xc;
      }
    }
    else if (local_34 == 0x2f) {
      sVar3 = 2;
      pcVar2 = "\\/";
    }
    else {
      if (local_34 != 0x5c) goto LAB_0003d66e;
      sVar3 = 2;
      pcVar2 = "\\\\";
    }
    iVar1 = (*dump)(pcVar2,sVar3,data);
  } while( true );
}

