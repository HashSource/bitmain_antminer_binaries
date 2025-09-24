
int Base64encode(char *encoded,char *string,int len)

{
  char *pcVar1;
  int len_local;
  char *string_local;
  char *encoded_local;
  char *p;
  int i;
  
  p = encoded;
  for (i = 0; pcVar1 = p, i < len + -2; i = i + 3) {
    *p = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[(byte)string[i] >> 2];
    p[1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
           [(uint)((byte)string[i + 1] >> 4) | ((byte)string[i] & 3) << 4];
    pcVar1 = p + 3;
    p[2] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
           [(uint)((byte)string[i + 2] >> 6) | ((byte)string[i + 1] & 0xf) << 2];
    p = p + 4;
    *pcVar1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
              [(byte)string[i + 2] & 0x3f];
  }
  if (i < len) {
    *p = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[(byte)string[i] >> 2];
    if (len + -1 == i) {
      p[1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
             [((byte)string[i] & 3) * 0x10];
      p[2] = '=';
    }
    else {
      p[1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
             [(uint)((byte)string[i + 1] >> 4) | ((byte)string[i] & 3) << 4];
      p[2] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
             [((byte)string[i + 1] & 0xf) * 4];
    }
    p = p + 3;
    *p = '=';
    p = pcVar1 + 4;
  }
  *p = '\0';
  return (int)(p + (1 - (int)encoded));
}

