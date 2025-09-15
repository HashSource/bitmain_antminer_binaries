
int baud2bt8d(uint baud)

{
  uint baud_local;
  uchar bt8d;
  
  if (baud == 0xe1000) {
    bt8d = '\x02';
  }
  else if (baud < 0xe1001) {
    if (baud == 0x1c200) {
      bt8d = '\x1a';
    }
    else {
      if (baud != 0x70800) {
LAB_0001f802:
        printf("%s: the baud is not recommand value, so use 115200 baud\n","baud2bt8d");
        return -1;
      }
      bt8d = '\x06';
    }
  }
  else if (baud == 1500000) {
    bt8d = '\x01';
  }
  else {
    if (baud != 3000000) goto LAB_0001f802;
    bt8d = '\0';
  }
  return (uint)bt8d;
}

