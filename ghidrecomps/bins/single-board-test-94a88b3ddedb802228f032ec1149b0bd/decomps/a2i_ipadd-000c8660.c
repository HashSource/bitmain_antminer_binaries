
int a2i_ipadd(uchar *ipout,char *ipasc)

{
  char *pcVar1;
  int iVar2;
  uint local_30 [2];
  int local_28 [2];
  int local_20 [2];
  int local_18 [3];
  
  pcVar1 = strchr(ipasc,0x3a);
  if (pcVar1 == (char *)0x0) {
    iVar2 = __isoc99_sscanf(ipasc,DAT_000c86d0,local_30,local_28,local_20,local_18);
    if (((((iVar2 == 4) && (local_30[0] < 0x100)) && (-1 < local_28[0])) &&
        ((local_28[0] < 0x100 && (-1 < local_20[0])))) &&
       ((local_20[0] < 0x100 && ((-1 < local_18[0] && (local_18[0] < 0x100)))))) {
      *ipout = (uchar)local_30[0];
      ipout[1] = (uchar)local_28[0];
      ipout[2] = (uchar)local_20[0];
      ipout[3] = (uchar)local_18[0];
      iVar2 = 4;
    }
    else {
      iVar2 = 0;
    }
  }
  else {
    iVar2 = ipv6_from_asc(ipout,ipasc);
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = 0x10;
    }
  }
  return iVar2;
}

