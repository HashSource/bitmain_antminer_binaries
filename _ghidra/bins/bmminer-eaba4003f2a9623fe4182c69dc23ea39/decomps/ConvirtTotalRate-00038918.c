
int ConvirtTotalRate(int totalRate)

{
  int totalRate_local;
  int lowPart;
  
  if (totalRate % 1000 < 0x1f5) {
    lowPart = 0;
  }
  else {
    lowPart = 500;
  }
  return (totalRate / 1000) * 1000 + lowPart;
}

