
short * Curl_ipv6_scope(short *param_1)

{
  char cVar1;
  ushort uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  short *psVar16;
  
  if (*param_1 == 10) {
    cVar1 = *(char *)((int)param_1 + 9);
    uVar2 = CONCAT11((char)param_1[4],cVar1);
    psVar16 = (short *)(uVar2 & 0xffc0);
    if (psVar16 == (short *)0xfe80) {
      return (short *)0x1;
    }
    if (psVar16 == (short *)0xfec0) {
      return (short *)0x2;
    }
    if ((uVar2 & 0xffc0) == 0) {
      bVar3 = (char)param_1[0xb] != '\0';
      bVar15 = (char)param_1[5] != '\0';
      bVar14 = *(char *)((int)param_1 + 0xb) != '\0';
      bVar13 = (char)param_1[6] != '\0';
      bVar12 = *(char *)((int)param_1 + 0xd) != '\0';
      bVar11 = (char)param_1[7] != '\0';
      bVar10 = *(char *)((int)param_1 + 0xf) != '\0';
      bVar9 = (char)param_1[8] != '\0';
      bVar8 = *(char *)((int)param_1 + 0x11) != '\0';
      bVar7 = (char)param_1[9] != '\0';
      bVar6 = *(char *)((int)param_1 + 0x13) != '\0';
      bVar5 = (char)param_1[10] != '\0';
      bVar4 = *(char *)((int)param_1 + 0x15) != '\0';
      if (bVar3 || ((((((((((((bVar15 || cVar1 != '\0') || bVar14) || bVar13) || bVar12) || bVar11)
                         || bVar10) || bVar9) || bVar8) || bVar7) || bVar6) || bVar5) || bVar4)) {
        param_1 = psVar16;
      }
      if (bVar3 || ((((((((((((bVar15 || cVar1 != '\0') || bVar14) || bVar13) || bVar12) || bVar11)
                         || bVar10) || bVar9) || bVar8) || bVar7) || bVar6) || bVar5) || bVar4)) {
        return param_1;
      }
      if (*(char *)((int)param_1 + 0x17) != '\x01') {
        return (short *)0x0;
      }
      return (short *)0x3;
    }
  }
  return (short *)0x0;
}

