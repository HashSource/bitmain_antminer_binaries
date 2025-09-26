
int a2i_ipadd(uchar *ipout,char *ipasc)

{
  size_t sVar1;
  size_t sVar2;
  char *pcVar3;
  int iVar4;
  undefined4 local_34 [4];
  size_t local_24;
  size_t local_20;
  int local_1c;
  
  pcVar3 = strchr(ipasc,0x3a);
  if (pcVar3 == (char *)0x0) {
    iVar4 = ipv4_from_asc(ipout,ipasc);
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = 4;
    }
    return iVar4;
  }
  local_24 = 0;
  local_1c = 0;
  local_20 = 0xffffffff;
  iVar4 = CONF_parse_list(ipasc,0x3a,0,(list_cb *)0x1831f9,local_34);
  sVar2 = local_20;
  sVar1 = local_24;
  if (iVar4 == 0) {
    return 0;
  }
  if (local_20 == 0xffffffff) {
    if (local_24 != 0x10) {
      return 0;
    }
  }
  else {
    if (local_24 == 0x10) {
      return 0;
    }
    if (3 < local_1c) {
      return 0;
    }
    if (local_1c == 3) {
      if (0 < (int)local_24) {
        return 0;
      }
    }
    else if (local_1c == 2) {
      if (local_20 != 0 && local_20 != local_24) {
        return 0;
      }
    }
    else if (local_20 == local_24 || local_20 == 0) {
      return 0;
    }
    if (-1 < (int)local_20) {
      memcpy(ipout,local_34,local_20);
      memset(ipout + sVar2,0,0x10 - sVar1);
      if (sVar2 == sVar1) {
        return 0x10;
      }
      memcpy(ipout + ((sVar2 + 0x10) - sVar1),(void *)((int)local_34 + sVar2),sVar1 - sVar2);
      return 0x10;
    }
  }
  *(undefined4 *)ipout = local_34[0];
  *(undefined4 *)(ipout + 4) = local_34[1];
  *(undefined4 *)(ipout + 8) = local_34[2];
  *(undefined4 *)(ipout + 0xc) = local_34[3];
  return 0x10;
}

