
int SSL_select_next_proto
              (uchar **out,uchar *outlen,uchar *in,uint inlen,uchar *client,uint client_len)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint __n;
  uint uVar4;
  
  if (inlen != 0) {
    uVar4 = 0;
    do {
      if (client_len == 0) {
        __n = (uint)in[uVar4];
      }
      else {
        uVar3 = 0;
        __n = (uint)in[uVar4];
        do {
          bVar1 = client[uVar3];
          if ((bVar1 == __n) && (iVar2 = memcmp(in + uVar4 + 1,client + uVar3 + 1,__n), iVar2 == 0))
          {
            iVar2 = 1;
            client = in + uVar4;
            goto LAB_000eb6dc;
          }
          uVar3 = uVar3 + bVar1 + 1;
        } while (uVar3 < client_len);
      }
      uVar4 = uVar4 + __n + 1;
    } while (uVar4 < inlen);
  }
  iVar2 = 2;
LAB_000eb6dc:
  *out = client + 1;
  *outlen = *client;
  return iVar2;
}

