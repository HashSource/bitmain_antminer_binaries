
int Base64decode_len(char *bufcoded)

{
  byte bVar1;
  byte *pbVar2;
  uchar *bufin;
  byte *pbVar3;
  char *bufcoded_local;
  int nbytesdecoded;
  
  pbVar2 = (byte *)bufcoded;
  do {
    pbVar3 = pbVar2 + 1;
    bVar1 = *pbVar2;
    pbVar2 = pbVar3;
  } while ("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@>@@@?456789:;<=@@@@@@@"[bVar1] < 0x40);
  pbVar2 = pbVar3 + (5 - (int)bufcoded);
  if (-1 < (int)(pbVar3 + (2 - (int)bufcoded))) {
    pbVar2 = pbVar3 + (2 - (int)bufcoded);
  }
  return ((int)pbVar2 >> 2) * 3 + 1;
}

