
int SSL_select_next_proto
              (uchar **out,uchar *outlen,uchar *in,uint inlen,uchar *client,uint client_len)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint __n;
  uint uVar4;
  uchar *local_38;
  
  local_38 = client;
  if (inlen != 0) {
    uVar4 = 0;
    do {
      if (client_len == 0) {
        __n = (uint)in[uVar4];
      }
      else {
        __n = (uint)in[uVar4];
        uVar3 = 0;
        do {
          bVar1 = client[uVar3];
          if ((bVar1 == __n) && (iVar2 = memcmp(in + uVar4 + 1,client + uVar3 + 1,__n), iVar2 == 0))
          {
            iVar2 = 1;
            local_38 = in + uVar4;
            goto LAB_0007b2e8;
          }
          uVar3 = uVar3 + bVar1 + 1;
        } while (uVar3 < client_len);
      }
      uVar4 = uVar4 + __n + 1;
    } while (uVar4 < inlen);
  }
  iVar2 = 2;
LAB_0007b2e8:
  *out = local_38 + 1;
  *outlen = *local_38;
  return iVar2;
}

