
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

int dump_string(char *str,json_dump_callback_t dump,void *data,size_t flags)

{
  int iVar1;
  char *text;
  size_t sVar2;
  uint uVar3;
  char *pos;
  byte *buffer;
  byte *pbVar4;
  int32_t codepoint;
  char seq [13];
  
  iVar1 = (*dump)(DAT_0003d750,1,data);
joined_r0x0003d63e:
  do {
    pbVar4 = (byte *)str;
    if (iVar1 != 0) {
      return -1;
    }
    while (buffer = pbVar4, pbVar4 = buffer, *buffer != 0) {
      if ((flags & 0x800) == 0) {
        pbVar4 = (byte *)utf8_iterate((char *)buffer,&codepoint);
      }
      else {
        pbVar4 = buffer + 1;
        codepoint = (uint)*buffer;
      }
      if (pbVar4 == (byte *)0x0) {
        return -1;
      }
      if ((((codepoint == 0x5c || codepoint == 0x22) || (codepoint < 0x20)) ||
          (((flags & 0x400) != 0 && (codepoint == 0x2f)))) ||
         (((flags & 0x40) != 0 && (0x7f < codepoint)))) break;
    }
    if ((buffer != (byte *)str) && (iVar1 = (*dump)(str,(int)buffer - (int)str,data), iVar1 != 0)) {
      return -1;
    }
    if (pbVar4 == buffer) {
      iVar1 = (*dump)(DAT_0003d750,1,data);
      return iVar1;
    }
    str = (char *)pbVar4;
    if (codepoint == 0xc) {
      sVar2 = 2;
      text = DAT_0003d76c;
    }
    else if (codepoint < 0xd) {
      if (codepoint == 9) {
        sVar2 = 2;
        text = DAT_0003d774;
      }
      else if (codepoint == 10) {
        sVar2 = 2;
        text = DAT_0003d770;
      }
      else {
        if (codepoint != 8) goto LAB_0003d66e;
        sVar2 = 2;
        text = DAT_0003d764;
      }
    }
    else if (codepoint == 0x22) {
      sVar2 = 2;
      text = DAT_0003d768;
    }
    else if (codepoint < 0x23) {
      if (codepoint == 0xd) {
        iVar1 = (*dump)(DAT_0003d758,2,data);
        goto joined_r0x0003d63e;
      }
LAB_0003d66e:
      if (codepoint < 0x10000) {
        sprintf(seq,DAT_0003d754);
        text = seq;
        sVar2 = 6;
      }
      else {
        iVar1 = codepoint + -0x10000;
        uVar3 = codepoint & 0x3ff;
        codepoint = iVar1;
        sprintf(seq,DAT_0003d778,(uint)(iVar1 * 0x1000) >> 0x16 | 0xd800,uVar3 | 0xdc00);
        text = seq;
        sVar2 = 0xc;
      }
    }
    else if (codepoint == 0x2f) {
      sVar2 = 2;
      text = DAT_0003d760;
    }
    else {
      if (codepoint != 0x5c) goto LAB_0003d66e;
      sVar2 = 2;
      text = DAT_0003d75c;
    }
    iVar1 = (*dump)(text,sVar2,data);
  } while( true );
}

