
char decode_ft_head(uint8_t d)

{
  char cVar1;
  uint8_t d_local;
  
  if (d == '\x01') {
    cVar1 = 'F';
  }
  else if (d == '\x02') {
    cVar1 = 'E';
  }
  else {
    cVar1 = 'A';
  }
  return cVar1;
}

