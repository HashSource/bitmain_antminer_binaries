
int Base64decode(char *bufplain,char *bufcoded)

{
  byte bVar1;
  byte *pbVar2;
  uchar *bufin;
  byte *pbVar3;
  uchar *bufout;
  byte *pbVar4;
  int nprbytes;
  byte *pbVar5;
  char *bufcoded_local;
  char *bufplain_local;
  int nbytesdecoded;
  
  pbVar2 = (byte *)bufcoded;
  do {
    pbVar3 = pbVar2 + 1;
    bVar1 = *pbVar2;
    pbVar2 = pbVar3;
  } while ("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@>@@@?456789:;<=@@@@@@@"[bVar1] < 0x40);
  pbVar5 = pbVar3 + (-1 - (int)bufcoded);
  pbVar2 = pbVar3 + (5 - (int)bufcoded);
  if (-1 < (int)(pbVar3 + (2 - (int)bufcoded))) {
    pbVar2 = pbVar3 + (2 - (int)bufcoded);
  }
  for (; 4 < (int)pbVar5; pbVar5 = pbVar5 + -4) {
    *bufplain = "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@>@@@?456789:;<=@@@@@@@"
                [((byte *)bufcoded)[1]] >> 4 |
                "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@>@@@?456789:;<=@@@@@@@"[(byte)*bufcoded]
                << 2;
    pbVar3 = (byte *)bufplain + 2;
    ((byte *)bufplain)[1] =
         "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@>@@@?456789:;<=@@@@@@@"[((byte *)bufcoded)[2]]
         >> 2 | "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@>@@@?456789:;<=@@@@@@@"
                [((byte *)bufcoded)[1]] << 4;
    bufplain = (char *)((byte *)bufplain + 3);
    *pbVar3 = "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@>@@@?456789:;<=@@@@@@@"
              [((byte *)bufcoded)[3]] |
              "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@>@@@?456789:;<=@@@@@@@"
              [((byte *)bufcoded)[2]] << 6;
    bufcoded = (char *)((byte *)bufcoded + 4);
  }
  pbVar3 = (byte *)bufplain;
  if (1 < (int)pbVar5) {
    pbVar3 = (byte *)bufplain + 1;
    *bufplain = "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@>@@@?456789:;<=@@@@@@@"
                [((byte *)bufcoded)[1]] >> 4 |
                "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@>@@@?456789:;<=@@@@@@@"[(byte)*bufcoded]
                << 2;
  }
  pbVar4 = pbVar3;
  if (2 < (int)pbVar5) {
    pbVar4 = pbVar3 + 1;
    *pbVar3 = "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@>@@@?456789:;<=@@@@@@@"
              [((byte *)bufcoded)[2]] >> 2 |
              "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@>@@@?456789:;<=@@@@@@@"
              [((byte *)bufcoded)[1]] << 4;
  }
  pbVar3 = pbVar4;
  if (3 < (int)pbVar5) {
    pbVar3 = pbVar4 + 1;
    *pbVar4 = "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@>@@@?456789:;<=@@@@@@@"
              [((byte *)bufcoded)[3]] |
              "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@>@@@?456789:;<=@@@@@@@"
              [((byte *)bufcoded)[2]] << 6;
  }
  *pbVar3 = 0;
  return ((int)pbVar2 >> 2) * 3 - (-(int)pbVar5 & 3U);
}

