
int Base64encode_len(int len)

{
  int len_local;
  
  return ((len + 2) / 3) * 4 + 1;
}

